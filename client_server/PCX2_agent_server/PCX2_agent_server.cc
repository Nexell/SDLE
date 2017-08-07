//-----------------------------------------------------------------------------
//
// Self-Driving Learning Environment(SDLE)
// Copyright(C) 2017 Nexell Co., Ltd.
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.
//
// nick@nexell.co.kr
//-----------------------------------------------------------------------------
#pragma warning(disable : 4100)  // unreferenced formal parameter
#pragma warning(disable : 4711)  // selected for automatic inline expansion
#pragma warning(disable : 4710)  // function not inlined
#pragma warning(disable : 4505)  // unreferenced local function has been removed
#pragma warning(push, 3)
#include <windows.h>
#include <tchar.h>
#include <assert.h>
#pragma warning(push, 0)
#include "./tensorflow/core/public/session.h"
#include "./tensorflow/core/platform/env.h"
#pragma warning(pop)
#pragma warning(pop)
#include "./main_game_interface.h"

//-----------------------------------------------------------------------------
#define AGENT_CONNECTION_NAME  _T("\\\\.\\pipe\\ps2_agent_server_pipe")

// velocity by using pre-trained CNN
#define VELOCITY_MODELFILE  ".\\models\\frozen_graph_velocity.pb"
#define VELOCITY_SX         (895.0f/1920.0f)
#define VELOCITY_SY         (892.0f/1080.0f)
#define VELOCITY_SW         (117.0f/1920.0f)
#define VELOCITY_SH         (47.0f/1080.0f)
#define VELOCITY_DW         117
#define VELOCITY_DH          47

//-----------------------------------------------------------------------------
#define DEBUG_PRINT(fmt, ...)    printf(fmt, __VA_ARGS__)

//-----------------------------------------------------------------------------
struct AgentPacket {
    UINT32 Command;
    INT32  Data[8];
};
struct AgentCommand {
    enum {
        OpenCapture = 0xDEADC0DE
        , DoCapture
        , CancelCapture
        , CloseCapture
        , OpenInfer
        , DoInfer
        , CloseInfer
        , PadStatus
    };
};
struct ServerState {
    enum T {
        WaitForClient = 0xDEADBEEF,
        Idle,
        Capture,
        Infer,
        Disconnect,
    };
};
//-----------------------------------------------------------------------------
class FramerateController {  // http://www.gamza.net/
public:
    void Clear() {
        SetFramePerSec(60.0f);
        m_Timer = 0.0f;
        m_LastTick = GetCurrentTick();
    }
    void SetFramePerSec(float fps) { m_SecPerFrame = 1.0f / fps; }
    bool Update(void) {
        float dt;
        unsigned __int64 cur_tick = GetCurrentTick();
        dt = (cur_tick - m_LastTick) / 1000.0f;
        m_LastTick = cur_tick;
        m_Timer += dt;
        if (m_Timer < 0) return false;
        m_Timer -= m_SecPerFrame;
        return true;
    }
    bool IsFrameSkip() { return m_Timer >= 0; }
    FramerateController() { Clear(); }
    virtual ~FramerateController() {}

protected:
    float m_Timer;
    float m_SecPerFrame;
    unsigned __int64 m_LastTick;
    unsigned __int64 GetCurrentTick(void) { return GetTickCount64(); }
};
//-----------------------------------------------------------------------------
struct PlatformPaint {
    HWND m_hWindow;
    RECT m_ClientRect;
    HDC  m_hWindowDC;
    HDC  m_hFramebufferDC;
    HBITMAP m_hFramebufferBitmap;
    HBITMAP m_hOldBitmap;
    void begin_paint(HWND hWindow) {
        m_hWindow = hWindow;
        GetClientRect(hWindow, &m_ClientRect);
        m_hWindowDC = GetDC(hWindow);
        m_hFramebufferDC = CreateCompatibleDC(m_hWindowDC);
        m_hFramebufferBitmap = CreateCompatibleBitmap(m_hWindowDC, m_ClientRect.right - m_ClientRect.left, m_ClientRect.bottom - m_ClientRect.top);
        m_hOldBitmap = (HBITMAP)SelectObject(m_hFramebufferDC, m_hFramebufferBitmap);
    }
    void end_paint(void) {
        BitBlt(m_hWindowDC, 0, 0, m_ClientRect.right - m_ClientRect.left, m_ClientRect.bottom - m_ClientRect.top, m_hFramebufferDC, 0, 0, SRCCOPY);
        SelectObject(m_hFramebufferDC, m_hOldBitmap);
        DeleteObject(m_hFramebufferBitmap);
        DeleteDC(m_hFramebufferDC);
        ReleaseDC(m_hWindow, m_hWindowDC);
    }
};


//-----------------------------------------------------------------------------
static RECT s_capture_rect;
static HWND create_window(void);
static HDC  begin_paint(HWND hWnd);
static HDC  end_paint(void);
static bool check_exitkey(void);
static void capture_game_state(HDC hDC, unsigned char* framebuffer, float* velocity);
static void convert_gameinterface_packet(const GameInterface& gi, AgentPacket* packet);
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    static float         s_velocity;
    static unsigned char s_framebuffer[CAPTURE_WIDTH * CAPTURE_HEIGHT * CAPTURE_CH];
    HWND hWindow;
    PlatformPaint paint;
    ServerState::T cur_state = ServerState::WaitForClient;
    HANDLE  connection_pipe = INVALID_HANDLE_VALUE;
    AgentPacket packet;
    FramerateController framerate_controller;
    DWORD temp;

    hWindow = create_window();

    framerate_controller.SetFramePerSec(CAPTURE_FRAMERATE);

    init_capture_server(hWindow);
    init_infer_server(hWindow);

begin_server_loop:
    while ( !check_exitkey() ) {
        switch (cur_state) {
        case ServerState::WaitForClient:
            assert(INVALID_HANDLE_VALUE == connection_pipe);
            connection_pipe = CreateNamedPipe(AGENT_CONNECTION_NAME, PIPE_ACCESS_DUPLEX,
                PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                PIPE_UNLIMITED_INSTANCES, sizeof(packet) * 20, sizeof(packet) * 20, 0, NULL);
            if (connection_pipe == INVALID_HANDLE_VALUE) {
                WaitNamedPipe(AGENT_CONNECTION_NAME, 100);
            } else {
                BOOL isSuccess = ConnectNamedPipe(connection_pipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
                if (isSuccess) {
                    cur_state = ServerState::Idle;
                    printf("Client Connected\n");
                } else {
                    CloseHandle(connection_pipe);
                    connection_pipe = INVALID_HANDLE_VALUE;
                }
            }
            break;

        case ServerState::Idle:
            assert(INVALID_HANDLE_VALUE != connection_pipe);
            if (!ReadFile(connection_pipe, &packet, sizeof(packet), &temp, NULL)) {
                cur_state = ServerState::Disconnect;
                goto begin_server_loop;
            }
            FlushFileBuffers(connection_pipe);
            switch (packet.Command) {
            case AgentCommand::OpenCapture:
                framerate_controller.Clear();
                s_capture_rect.left = packet.Data[0];
                s_capture_rect.top = packet.Data[1];
                s_capture_rect.right = packet.Data[2];
                s_capture_rect.bottom = packet.Data[3];
                cur_state = ServerState::Capture;
                open_capture_server(hWindow);
                printf("OpenCapture: (%d, %d) %d x %d\n", s_capture_rect.left, s_capture_rect.top,
                        s_capture_rect.right - s_capture_rect.left, s_capture_rect.bottom - s_capture_rect.top);
                break;
            case AgentCommand::OpenInfer:
                framerate_controller.Clear();
                s_capture_rect.left = packet.Data[0];
                s_capture_rect.top = packet.Data[1];
                s_capture_rect.right = packet.Data[2];
                s_capture_rect.bottom = packet.Data[3];
                cur_state = ServerState::Infer;
                open_infer_server(hWindow);
                printf("OpenInfer: (%d, %d) %d x %d\n", s_capture_rect.left, s_capture_rect.top,
                        s_capture_rect.right - s_capture_rect.left, s_capture_rect.bottom - s_capture_rect.top);
                break;
            default:
                cur_state = ServerState::Disconnect;
                printf("unknown command : %08X\n", packet.Command);
                assert(false);
                break;
            }
            break;

        case ServerState::Capture:
            assert(INVALID_HANDLE_VALUE != connection_pipe);
            if (!framerate_controller.Update()) {
                Sleep(1);
                goto begin_server_loop;
            }
            if (!ReadFile(connection_pipe, &packet, sizeof(packet), &temp, NULL)) {
                cur_state = ServerState::Disconnect;
                close_capture_server(hWindow, false);
                goto begin_server_loop;
            }
            FlushFileBuffers(connection_pipe);
            switch (packet.Command) {
            case AgentCommand::DoCapture:
                paint.begin_paint(hWindow);
                capture_game_state(paint.m_hFramebufferDC, s_framebuffer, &s_velocity);
                convert_gameinterface_packet(do_capture_server(hWindow, paint.m_hFramebufferDC, s_framebuffer, s_velocity), &packet);
                paint.end_paint();
                if (!WriteFile(connection_pipe, &packet, sizeof(packet), &temp, NULL)) {
                    cur_state = ServerState::Disconnect;
                    close_capture_server(hWindow, false);
                    goto begin_server_loop;
                }
                FlushFileBuffers(connection_pipe);
                break;
            default:
                cur_state = ServerState::Disconnect;
                close_capture_server(hWindow, packet.Command == AgentCommand::CloseCapture);
                if (packet.Command == AgentCommand::CloseCapture) {
                    printf("\nSave Capture\n");
                } else {
                    printf("\nCencel Capture\n");
                }
                printf("Disconnect Capture\n");
                break;
            }
            break;

        case ServerState::Infer:
            assert(INVALID_HANDLE_VALUE != connection_pipe);
            if (!framerate_controller.Update()) {
                Sleep(1);
                goto begin_server_loop;
            }
            if (!ReadFile(connection_pipe, &packet, sizeof(packet), &temp, NULL)) {
                cur_state = ServerState::Disconnect;
                close_infer_server(hWindow);
                goto begin_server_loop;
            }
            FlushFileBuffers(connection_pipe);
            switch (packet.Command) {
            case AgentCommand::DoInfer:
                paint.begin_paint(hWindow);
                capture_game_state(paint.m_hFramebufferDC, s_framebuffer, &s_velocity);
                convert_gameinterface_packet(do_infer_server(hWindow, paint.m_hFramebufferDC, s_framebuffer, s_velocity), &packet);
                paint.end_paint();
                if (!WriteFile(connection_pipe, &packet, sizeof(packet), &temp, NULL)) {
                    cur_state = ServerState::Disconnect;
                    close_infer_server(hWindow);
                    goto begin_server_loop;
                }
                FlushFileBuffers(connection_pipe);
                break;
            default:
                cur_state = ServerState::Disconnect;
                close_infer_server(hWindow);
                printf("\nDisconnect Infer\n");
                break;
            }
            break;

        case ServerState::Disconnect:
            assert(INVALID_HANDLE_VALUE != connection_pipe);
            if (connection_pipe) { CloseHandle(connection_pipe); }
            connection_pipe = INVALID_HANDLE_VALUE;
            cur_state = ServerState::WaitForClient;
            break;

        default:
            cur_state = ServerState::Disconnect;
            assert(false);
            break;
        }
    }

    DestroyWindow(hWindow);
    if (connection_pipe) { CloseHandle(connection_pipe); }
    return 0;
}

//-----------------------------------------------------------------------------
static DWORD WINAPI window_thread(LPVOID lpParam) {
    static int classid = 0;
    const wchar_t classbasename[] = L"SDLE agent view";
    wchar_t classname[64];
    {
        wsprintf(classname, L"%s[%d]", classbasename, classid);
        classid++;
    }
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_CLASSDC;
    wc.lpfnWndProc = DefWindowProc;
    wc.cbClsExtra = 0L;
    wc.cbWndExtra = 0L;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName = NULL;
    wc.lpszClassName = classname;
    wc.hIconSm = NULL;
    RegisterClassEx(&wc);

    const DWORD WindowStyle = WS_OVERLAPPEDWINDOW;
    const int Xpos = CW_USEDEFAULT;
    const int Ypos = CW_USEDEFAULT;
    RECT    windowrect = { 0, 0, CAPTURE_WIDTH*VIEW_WINDOW_SCALE, CAPTURE_HEIGHT*VIEW_WINDOW_SCALE };

    int w, h;
    AdjustWindowRect(&windowrect, WindowStyle, FALSE);
    w = windowrect.right - windowrect.left;
    h = windowrect.bottom - windowrect.top;
    HWND hWindow = CreateWindow(classname,
                                L"SDLE agent view - by Nexell",
                                WindowStyle, Xpos, Ypos, w, h, GetDesktopWindow(),
                                NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hWindow, SW_SHOWDEFAULT);

    *(reinterpret_cast<HWND*>(lpParam)) = hWindow;

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT) {
        if (GetMessage(&msg, NULL, 0U, 0U)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}

static HWND create_window(void) {
    HWND hWindow = NULL;
    CreateThread(NULL, 0, window_thread, (LPVOID)&hWindow, 0, 0);
    while (!hWindow) {
        Sleep(10);
    }
    return hWindow;
}
//-----------------------------------------------------------------------------
static bool check_exitkey(void) {
    if (0 != (GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------------
static float remap_linear_steering_value_into_non_linear_space_for_granturismo4(float a);
static void convert_gameinterface_packet(const GameInterface& gi, AgentPacket* packet) {
    WORD server_buttons = 0;
    BYTE server_left_x = 128;
    BYTE server_left_y = 128;
    float steering = remap_linear_steering_value_into_non_linear_space_for_granturismo4(gi.m_steering);
    if (gi.m_acclerator) { server_buttons |= 0x4000; }  // Cross button
    if (gi.m_break) { server_buttons |= 0x8000; }  // Square button
    if (steering < -1.0) {
        server_left_x = 0;
    } else if (steering > 1.0) {
        server_left_x = 255;
    } else {
        server_left_x = (BYTE)((steering + 1.0f) * 255.0f / 2.0f);
    }
    packet->Command = (UINT32)AgentCommand::PadStatus;
    packet->Data[0] = server_buttons;
    packet->Data[1] = server_left_x;
    packet->Data[2] = server_left_y;
}
//-----------------------------------------------------------------------------
// The granturismo's steering value is not in linear space.
// Tiny little error can makes significant error at non-linear point(0.3~0.4).
// So we need to remap the steering value, to make that the linear value
// (output of CNN) cause linear action in the game world.
// We made the following fucntion experimentally.
// It's not perfect, but it pretty works.
static float remap_linear_steering_value_into_non_linear_space_for_granturismo4(float a) {
    const float THRESHOLD0_0 = 0.025f;
    const float THRESHOLD0_1 = 0.70f;
    const float THRESHOLD0_2 = 0.90f;
    const float THRESHOLD0_3 = 1.00f;

    const float THRESHOLD1_0 = 0.29f;
    const float THRESHOLD1_1 = 0.40f;
    const float THRESHOLD1_2 = 0.55f;
    const float THRESHOLD1_3 = 0.80f;
    const float UPPER_LIMIT = 1.0f;
    float sign = (a >= 0) ? 1.0f : -1.0f;
    a = a * sign;
    if (a <= THRESHOLD0_0) {
        a *= (THRESHOLD1_0 / THRESHOLD0_0);
    } else if (a <= THRESHOLD0_1) {
        a = ((a - THRESHOLD0_0) * (THRESHOLD1_1 - THRESHOLD1_0) / (THRESHOLD0_1 - THRESHOLD0_0)) + THRESHOLD1_0;
    } else if (a <= THRESHOLD0_2) {
        a = ((a - THRESHOLD0_1) * (THRESHOLD1_2 - THRESHOLD1_1) / (THRESHOLD0_2 - THRESHOLD0_1)) + THRESHOLD1_1;
    } else {  // if (a <= THRESHOLD0_3)
        a = ((a - THRESHOLD0_2) * (THRESHOLD1_3 - THRESHOLD1_2) / (THRESHOLD0_3 - THRESHOLD0_2)) + THRESHOLD1_2;
    }
    a = a * sign;
    if (a < -1) a = -1;
    if (a > 1) a = 1;
    return a;
}

//-----------------------------------------------------------------------------
static HBITMAP get_screen_bitmap(float src_x, float src_y, float src_w, float src_h, int dst_w, int dst_h);
static void draw_bitmap(HDC hDC, int x, int y, int w, int h, HBITMAP hBitmap, int sx, int sy, int sw, int sh);
static BITMAPINFO* create_bitmapinfo(HBITMAP hbit);
static int infer_tf_velocity_digit(const unsigned char* pdata);
//-----------------------------------------------------------------------------
static unsigned char RGBtoY(unsigned char rr, unsigned char gg, unsigned char bb) {
    return (unsigned char)((static_cast<int>(rr) * 299 +
                            static_cast<int>(gg) * 587 +
                            static_cast<int>(bb) * 114) / 1000);
}
static void SaveBitmap(BITMAPINFO* bmpinfo, char* Path);
//-----------------------------------------------------------------------------
static void capture_game_state(HDC hDC, unsigned char* const framebuffer, float* const velocity)     {
    HBITMAP      hbmp = NULL;
    BITMAPINFO*  bmpi = NULL;

    // frame buffer
    hbmp = get_screen_bitmap(0.0f, 0.0f, 1.0f, 1.0f, CAPTURE_WIDTH, CAPTURE_HEIGHT);
    bmpi = create_bitmapinfo(hbmp);
    if ((!hbmp) || (!bmpi)) { goto done; }
    if (24 != bmpi->bmiHeader.biBitCount) { goto done; }
    if (CAPTURE_WIDTH != bmpi->bmiHeader.biWidth) { goto done; }
    if (CAPTURE_HEIGHT != bmpi->bmiHeader.biHeight) { goto done; }
    {
        const unsigned char* ptr;
        unsigned int i = 0;
        int bytes_per_line = CAPTURE_WIDTH * 3;
        bytes_per_line = (bytes_per_line + 3) & (~3);
        for (int yy = 0; yy < CAPTURE_HEIGHT; yy++) {
            ptr = ((const unsigned char*)bmpi->bmiColors) + (bytes_per_line*yy);//(bytes_per_line*(CAPTURE_HEIGHT-1-yy));
            for (int xx = 0; xx < CAPTURE_WIDTH; xx++) {
            #if (1 == CAPTURE_CH)
                framebuffer[i] = RGBtoY(ptr[2], ptr[1], ptr[0]);
            #elif(3 == CAPTURE_CH)
                for (int ch = 0; ch < CAPTURE_CH; ch++) {
                    framebuffer[i * CAPTURE_CH + ch] = ptr[2 - ch];  // BGR to RGB
                }
            #else
                CASSERT("CAPTURE_CH should be 1(Y) or 3(RGB)")
            #endif
                ptr += 3;
                i++;
            }
        }
    }
    draw_bitmap(hDC, 0, 0, CAPTURE_WIDTH*VIEW_WINDOW_SCALE, CAPTURE_HEIGHT*VIEW_WINDOW_SCALE, hbmp, 0, 0, CAPTURE_WIDTH, CAPTURE_HEIGHT);
    DeleteObject(hbmp);
    hbmp = NULL;
    free(bmpi);
    bmpi = NULL;

    // velocity by using pre-trained CNN
    hbmp = get_screen_bitmap(VELOCITY_SX, VELOCITY_SY, VELOCITY_SW, VELOCITY_SH, VELOCITY_DW, VELOCITY_DH);
    bmpi = create_bitmapinfo(hbmp);
    draw_bitmap(hDC, 0, 0, CAPTURE_WIDTH*VIEW_WINDOW_SCALE /8, VELOCITY_DH * CAPTURE_WIDTH*VIEW_WINDOW_SCALE / (VELOCITY_DW * 8),
                hbmp, 0, 0, VELOCITY_DW, VELOCITY_DH);
    // SaveBitmap(bmpi, "vel.bmp");
    if ((!hbmp) || (!bmpi)) { goto done; }
    if (24 != bmpi->bmiHeader.biBitCount) { goto done; }
    if (VELOCITY_DW != bmpi->bmiHeader.biWidth) { goto done; }
    if (VELOCITY_DH != bmpi->bmiHeader.biHeight) { goto done; }

    {
        static unsigned char byte_val0[38 * 47];
        static unsigned char byte_val1[38 * 47];
        static unsigned char byte_val2[38 * 47];
        const unsigned char* ptr;
        unsigned int i = 0;
        int bytes_per_line = VELOCITY_DW * 3;
        bytes_per_line = (bytes_per_line + 3) & (~3);
        for (int yy = 0; yy < 47; yy++) {
            ptr = (const unsigned char*)bmpi->bmiColors + (bytes_per_line*(VELOCITY_DH - 1 - yy));
            for (int xx = 0; xx < 38; xx++) {
                byte_val0[i] = RGBtoY(ptr[(39 * 0) * 3 + 2],
                                      ptr[(39 * 0) * 3 + 1],
                                      ptr[(39 * 0) * 3 + 0]);
                byte_val1[i] = RGBtoY(ptr[(39 * 1) * 3 + 2],
                                      ptr[(39 * 1) * 3 + 1],
                                      ptr[(39 * 1) * 3 + 0]);
                byte_val2[i] = RGBtoY(ptr[(39 * 2) * 3 + 2],
                                      ptr[(39 * 2) * 3 + 1],
                                      ptr[(39 * 2) * 3 + 0]);
                ptr += 3;
                i++;
            }
        }

        (*velocity) = infer_tf_velocity_digit(byte_val0) * 100.0f + infer_tf_velocity_digit(byte_val1) * 10.0f + infer_tf_velocity_digit(byte_val2) * 1.0f;
    }

done:
    if (hbmp) {
        DeleteObject(hbmp);
        hbmp = NULL;
    }
    if (bmpi) {
        free(bmpi);
        bmpi = NULL;
    }
}

//-----------------------------------------------------------------------------
static void SaveBitmap(BITMAPINFO* bmpinfo, char* Path) {
    BITMAPFILEHEADER bFile;
    BITMAPINFOHEADER bInfo;
    int PalSize;
    DWORD Size;
    bInfo = bmpinfo->bmiHeader;
    PalSize = (bInfo.biBitCount == 24 ? 0 : 1 << bInfo.biBitCount) * sizeof(RGBQUAD);
    Size = bInfo.biSize + PalSize + bInfo.biSizeImage;
    bFile.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + PalSize;
    bFile.bfReserved1 = 0;
    bFile.bfReserved2 = 0;
    bFile.bfSize = Size + sizeof(BITMAPFILEHEADER);
    bFile.bfType = 0x4d42;
    FILE* fp = fopen(Path, "wb");
    if (fp) {
        fwrite(&bFile, 1, sizeof(bFile), fp);
        fwrite(bmpinfo, 1, Size, fp);
        fclose(fp);
    }
}

//-----------------------------------------------------------------------------
static HBITMAP get_screen_bitmap(float src_x, float src_y, float src_w, float src_h, int dst_w, int dst_h) {
    HDC hScrDC, hMemDC;
    HBITMAP hBitmap;
    RECT rt;
    rt.left   = s_capture_rect.left + (LONG)((s_capture_rect.right - s_capture_rect.left) * src_x);
    rt.top    = s_capture_rect.top  + (LONG)((s_capture_rect.bottom - s_capture_rect.top) * src_y);
    rt.right  = rt.left + (LONG)((s_capture_rect.right - s_capture_rect.left) * src_w);
    rt.bottom = rt.top  + (LONG)((s_capture_rect.bottom - s_capture_rect.top) * src_h);

    hScrDC = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
    hMemDC = CreateCompatibleDC(hScrDC);
    hBitmap = CreateCompatibleBitmap(hScrDC, dst_w, dst_h);
    SelectObject(hMemDC, hBitmap);

    SetStretchBltMode(hMemDC, COLORONCOLOR);
    int src_width  = (rt.bottom - rt.top) * dst_w / dst_h;
    int src_height = (rt.right - rt.left) * dst_h / dst_w;
    int xx = ((rt.right - rt.left) - src_width) / 2;
    int yy = ((rt.bottom - rt.top) - src_height) / 2;
    if (xx < yy) {
        StretchBlt(hMemDC, 0, 0, dst_w, dst_h, hScrDC, rt.left, rt.top + yy, rt.right - rt.left, src_height, SRCCOPY);
    } else {
        StretchBlt(hMemDC, 0, 0, dst_w, dst_h, hScrDC, rt.left + xx, rt.top, src_width, rt.bottom - rt.top, SRCCOPY);
    }
    DeleteDC(hMemDC);
    DeleteDC(hScrDC);
    return hBitmap;
}
//-----------------------------------------------------------------------------
static void draw_bitmap(HDC hDC, int x, int y, int w, int h,
                        HBITMAP hBitmap, int sx, int sy, int sw, int sh ) {
    HDC memdc = CreateCompatibleDC(hDC);
    HANDLE OldBitmap = (HBITMAP)SelectObject(memdc, hBitmap);
    StretchBlt(hDC, x, y, w, h, memdc, sx, sy, sw, sh, SRCCOPY);
    SelectObject(memdc, OldBitmap);
    DeleteDC(memdc);
}
//-----------------------------------------------------------------------------
static BITMAPINFO* create_bitmapinfo(HBITMAP hbit) {
    BITMAPINFOHEADER bInfo;
    BITMAP bit;
    BITMAPINFO *pih;
    int PalSize;
    DWORD Size;
    HDC hdc;
    if (!hbit) { return NULL;  }
    hdc = GetDC(NULL);
    GetObject(hbit, sizeof(BITMAP), &bit);
    bInfo.biSize = sizeof(BITMAPINFOHEADER);
    bInfo.biWidth = bit.bmWidth;
    bInfo.biHeight = bit.bmHeight;
    bInfo.biPlanes = 1;
    bInfo.biBitCount = bit.bmPlanes*bit.bmBitsPixel;
    if (bInfo.biBitCount > 8) bInfo.biBitCount = 24;
    bInfo.biCompression = BI_RGB;
    bInfo.biSizeImage = 0;
    bInfo.biXPelsPerMeter = 0;
    bInfo.biYPelsPerMeter = 0;
    bInfo.biClrUsed = 0;
    bInfo.biClrImportant = 0;
    PalSize = (bInfo.biBitCount == 24 ? 0 : 1 << bInfo.biBitCount) * sizeof(RGBQUAD);
    pih = reinterpret_cast<BITMAPINFO *>(malloc(bInfo.biSize + PalSize));
    pih->bmiHeader = bInfo;
    GetDIBits(hdc, hbit, 0, bit.bmHeight, NULL, pih, DIB_RGB_COLORS);
    bInfo = pih->bmiHeader;
    if (bInfo.biSizeImage == 0) {
        bInfo.biSizeImage = ((((bInfo.biWidth*bInfo.biBitCount) + 31) & ~31) >> 3) * bInfo.biHeight;
    }
    Size = bInfo.biSize + PalSize + bInfo.biSizeImage;
    pih = reinterpret_cast<BITMAPINFO *>(realloc(pih, Size));
    GetDIBits(hdc, hbit, 0, bit.bmHeight, (PBYTE)pih + bInfo.biSize + PalSize, pih, DIB_RGB_COLORS);
    ReleaseDC(NULL, hdc);
    return pih;
}



//-----------------------------------------------------------------------------
namespace {
    tensorflow::Session* tf_session_velocity = 0;
    tensorflow::Tensor infer_i_velocity(tensorflow::DT_UINT8, tensorflow::TensorShape({ 1, 47, 38, 1 }));
    std::vector<std::pair<std::string, tensorflow::Tensor>> tf_inputs_velocity = { { "velocity_i", infer_i_velocity } };
    std::vector<tensorflow::Tensor> tf_outputs;
    void close_tf_session(void);
    bool open_tf_session(void) {
        tensorflow::GraphDef graph_def;
        tensorflow::Status status;
        status = tensorflow::NewSession(tensorflow::SessionOptions(), &tf_session_velocity);
        if (!status.ok()) {
            std::cout << status.ToString() << "\n";
            close_tf_session();
            return false;
        }
        status = tensorflow::ReadBinaryProto(tensorflow::Env::Default(), VELOCITY_MODELFILE, &graph_def);
        if (!status.ok()) {
            std::cout << status.ToString() << "\n";
            close_tf_session();
            return false;
        }
        status = tf_session_velocity->Create(graph_def);
        if (!status.ok()) {
            std::cout << status.ToString() << "\n";
            close_tf_session();
            return false;
        }
        return true;
    }
    void close_tf_session(void) {
        tensorflow::Session* cur_session;
        cur_session = tf_session_velocity;
        tf_session_velocity = NULL;
        if (cur_session) { cur_session->Close(); }
    }
}  // namespace

static int infer_tf_velocity_digit(const unsigned char* pdata) {
    if (!tf_session_velocity)  {
        if (!open_tf_session()) {
            return -1;
        }
    }
    auto in = infer_i_velocity.flat<unsigned char>();
    for (int i = 0; i < in.size(); i++) {
        in(i) = *pdata++;
    }
    tensorflow::Status status = tf_session_velocity->Run(tf_inputs_velocity, { "velocity_o" }, {}, &tf_outputs);
    if (!status.ok()) {
        std::cout << status.ToString() << "\n";
        return -1;
    }
    int   max_index = 0;
    float max_value = tf_outputs[0].flat<float>()(0);
    if (max_value < tf_outputs[0].flat<float>()(1)) { max_value = tf_outputs[0].flat<float>()(1); max_index = 1; }
    if (max_value < tf_outputs[0].flat<float>()(2)) { max_value = tf_outputs[0].flat<float>()(2); max_index = 2; }
    if (max_value < tf_outputs[0].flat<float>()(3)) { max_value = tf_outputs[0].flat<float>()(3); max_index = 3; }
    if (max_value < tf_outputs[0].flat<float>()(4)) { max_value = tf_outputs[0].flat<float>()(4); max_index = 4; }
    if (max_value < tf_outputs[0].flat<float>()(5)) { max_value = tf_outputs[0].flat<float>()(5); max_index = 5; }
    if (max_value < tf_outputs[0].flat<float>()(6)) { max_value = tf_outputs[0].flat<float>()(6); max_index = 6; }
    if (max_value < tf_outputs[0].flat<float>()(7)) { max_value = tf_outputs[0].flat<float>()(7); max_index = 7; }
    if (max_value < tf_outputs[0].flat<float>()(8)) { max_value = tf_outputs[0].flat<float>()(8); max_index = 8; }
    if (max_value < tf_outputs[0].flat<float>()(9)) { max_value = tf_outputs[0].flat<float>()(9); max_index = 9; }
    if (max_value < tf_outputs[0].flat<float>()(10)) { max_value = tf_outputs[0].flat<float>()(10); max_index = 0; }
    return max_index;
}












