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
//
// The original source code of xpad is a part of PCSX2
// (https://github.com/PCSX2/pcsx2/tree/master/plugins/xpad)
//
//-----------------------------------------------------------------------------
#pragma warning(disable:4100)  // unreferenced formal parameter
#pragma warning(disable:4710)  // function not inlined
#pragma warning(disable:4711)  // selected for automatic inline expansion
#pragma warning(push, 3)
#include <windows.h>
#include <tchar.h>
#include <VersionHelpers.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <list>
#pragma warning(pop)

//-----------------------------------------------------------------------------
#define EXPORT_C extern "C" void __stdcall
#define EXPORT_C_(type) extern "C" type __stdcall
#define countof(a) (sizeof(a) / sizeof(a[0]))
//-----------------------------------------------------------------------------
#define PLUGIN_REVISION  1
#define PLUGIN_BUILD     0
#define PLUGIN_MINOR     0
#define PLUGIN_NAME      "XPad - modified by Nexell for SDLE"
//-----------------------------------------------------------------------------
#define AGENT_CONNECTION_NAME  _T("\\\\.\\pipe\\ps2_agent_server_pipe")
//-----------------------------------------------------------------------------
#define PLUGIN_1P_SELECT     'B'
#define PLUGIN_1P_START      'N'
#define PLUGIN_1P_L3         '1'
#define PLUGIN_1P_R3         '3'
#define PLUGIN_1P_L2         'Q'
#define PLUGIN_1P_R2         'E'
#define PLUGIN_1P_L1         'A'
#define PLUGIN_1P_R1         'D'
#define PLUGIN_1P_TRIANGLE   'S'
#define PLUGIN_1P_SQUARE     'Z'
#define PLUGIN_1P_CIRCLE     'C'
#define PLUGIN_1P_CROSS      'X'
#define PLUGIN_1P_UP         VK_UP
#define PLUGIN_1P_RIGHT      VK_RIGHT
#define PLUGIN_1P_DOWN       VK_DOWN
#define PLUGIN_1P_LEFT       VK_LEFT
//-----------------------------------------------------------------------------
#define PSE_LT_PAD       8
#define PS2E_LT_PAD      0x02
#define PS2E_PAD_VERSION 0x0002
//-----------------------------------------------------------------------------
// #define PSE_PAD_TYPE_MOUSE        1  // MOUSE SCPH-1030
// #define PSE_PAD_TYPE_NEGCON       2  // NEGCON - 16 button analog controller SLPH-00001
// #define PSE_PAD_TYPE_GUN          3  // GUN CONTROLLER - gun controller SLPH-00014 from Konami
// #define PSE_PAD_TYPE_STANDARD     4  // STANDARD PAD SCPH-1080, SCPH-1150
// #define PSE_PAD_TYPE_ANALOGJOY    5  // ANALOG JOYSTICK SCPH-1110
// #define PSE_PAD_TYPE_GUNCON       6  // GUNCON - gun controller SLPH-00034 from Namco
#define PSE_PAD_TYPE_ANALOGPAD      7  // ANALOG CONTROLLER SCPH-1150
//-----------------------------------------------------------------------------
struct PadDataS {
    BYTE type;       // controler type - fill it withe predefined values above
    BYTE padding;
    WORD status;     // status of buttons - every controller fills this field
    BYTE rightJoyX;  // for analog pad values are analog in range 0-255 where 128 is center position
    BYTE rightJoyY;
    BYTE leftJoyX;
    BYTE leftJoyY;
    BYTE moveX;      // for mouse values are in range -128 - 127
    BYTE moveY;
    BYTE reserved[90];
};
struct XPadButton {
    enum {
        Select = 0x0001,
        L3 = 0x0002,
        R3 = 0x0004,
        Start = 0x0008,
        Up = 0x0010,
        Right = 0x0020,
        Down = 0x0040,
        Left = 0x0080,
        L2 = 0x0100,
        R2 = 0x0200,
        L1 = 0x0400,
        R1 = 0x0800,
        Triangle = 0x1000,
        Circle = 0x2000,
        Cross = 0x4000,
        Square = 0x8000,
    };
};
struct KeyEvent {
    UINT32 key;
    UINT32 event;
};
#define KEYPRESS    1
#define KEYRELEASE  2
class CCritSec {
private:
    CCritSec(const CCritSec &refCritSec);
    CCritSec &operator=(const CCritSec &refCritSec) = delete;
    CRITICAL_SECTION m_CritSec;
public:
    CCritSec() { InitializeCriticalSection(&m_CritSec); }
    ~CCritSec() { DeleteCriticalSection(&m_CritSec); }
    void Lock() { EnterCriticalSection(&m_CritSec); }
    void Unlock() { LeaveCriticalSection(&m_CritSec); }
};
class CAutoLock {
    CAutoLock(const CAutoLock &refAutoLock);
    CAutoLock &operator=(const CAutoLock &refAutoLock) = delete;
protected:
    CCritSec * m_pLock;
public:
    explicit CAutoLock(CCritSec * plock) { m_pLock = plock; m_pLock->Lock(); }
    ~CAutoLock() { m_pLock->Unlock(); }
};
//-----------------------------------------------------------------------------
static volatile bool is_server_activated = false;
static volatile WORD server_buttons = 0;
static volatile BYTE server_left_x = 128;
static volatile BYTE server_left_y = 128;
//-----------------------------------------------------------------------------
class XPad {
public:
    int m_pad;
    bool m_connected;
    bool m_ds2native;
    bool m_analog;
    bool m_locked;
    bool m_vibration;
    BYTE m_padding[3];
    BYTE m_small;
    BYTE m_large;
    WORD m_buttons;
    struct { BYTE x, y; } m_left;
    struct { BYTE x, y; } m_right;
    void SetButton(int windows_key, int flag) {
        if (0 != (GetAsyncKeyState(windows_key) & 0x8000)) {
            m_buttons &= ~flag;
        } else {
            m_buttons |= flag;
        }
    }

public:
    XPad(void)
        : m_ds2native(false)
        , m_analog(false)  // defaults to analog off for ps2
        , m_locked(false)
        , m_vibration(true)
        , m_small(0)
        , m_large(0)
        , m_buttons(0xffff) {}
    virtual ~XPad() {}
    BYTE GetId() {
        return (BYTE)(m_analog ? (m_ds2native ? 0x79 : 0x73) : 0x41);
    }
    BYTE ReadData(int index) {
        if (is_server_activated) {
            m_buttons = (WORD)(~server_buttons);  // 0: pushed  1: released
            m_left.x = server_left_x;
            m_left.y = server_left_y;
            m_right.x = 128;
            m_right.y = 128;
        } else {
            m_buttons = 0xffff;
            SetButton(PLUGIN_1P_SELECT, XPadButton::Select);
            SetButton(PLUGIN_1P_START, XPadButton::Start);
            SetButton(PLUGIN_1P_L3, XPadButton::L3);
            SetButton(PLUGIN_1P_R3, XPadButton::R3);
            SetButton(PLUGIN_1P_L2, XPadButton::L2);
            SetButton(PLUGIN_1P_R2, XPadButton::R2);
            SetButton(PLUGIN_1P_L1, XPadButton::L1);
            SetButton(PLUGIN_1P_R1, XPadButton::R1);
            SetButton(PLUGIN_1P_TRIANGLE, XPadButton::Triangle);
            SetButton(PLUGIN_1P_SQUARE, XPadButton::Square);
            SetButton(PLUGIN_1P_CIRCLE, XPadButton::Circle);
            SetButton(PLUGIN_1P_CROSS, XPadButton::Cross);
            SetButton(PLUGIN_1P_UP, XPadButton::Up);
            SetButton(PLUGIN_1P_RIGHT, XPadButton::Right);
            SetButton(PLUGIN_1P_DOWN, XPadButton::Down);
            SetButton(PLUGIN_1P_LEFT, XPadButton::Left);
            m_left.x = 128;
            m_left.y = 128;
            m_right.x = 128;
            m_right.y = 128;
        }

        switch (index) {
        case 0:
            return (BYTE)(m_buttons & 0xff);
        case 1:
            return (BYTE)(m_buttons >> 8);
        case 2:
            return m_right.x;
        case 3:
            return m_right.y;
        case 4:
            return m_left.x;
        case 5:
            return m_left.y;
        }

        return 0xff;
    }
};

class XPadPlugin {
private:
    std::vector<XPad*> m_pads;
    XPad* m_pad;
    int m_index;
    bool m_cfgreaddata;
    BYTE m_unknown1;
    BYTE m_unknown3;
    BYTE m_cmd;
    typedef BYTE(XPadPlugin::*CommandHandler)(int, BYTE);

    CommandHandler m_handlers[256];
    CommandHandler m_handler;

    BYTE DS2Enabler(int index, BYTE) {
        switch (index) {
        case 2:
            return 0x02;
        case 5:
            return 'Z';
        }
        return 0;
    }

    BYTE QueryDS2AnalogMode(int index, BYTE) {
        if (m_pad->m_ds2native) {
            switch (index) {
            case 0:
                return 0xff;
            case 1:
                return 0xff;
            case 2:
                return 3;
            case 3:
                return 0;
            case 4:
                return 0;
            case 5:
                return 'Z';
            }
        }
        return 0;
    }

    BYTE ReadDataAndVibrate(int index, BYTE value) {
        switch (index) {
        case 0:
            m_pad->m_small = (BYTE)((value & 1) * 128);
            break;
        case 1:
            m_pad->m_large = value;
            break;
        }
        return m_pad->ReadData(index);
    }

    BYTE ConfigMode(int index, BYTE value) {
        switch (index) {
        case 0:
            switch (value) {
            case 0:
                m_cfgreaddata = false;
                break;
            case 1:
                m_cfgreaddata = true;
                break;
            }
            break;
        }
        if (m_cfgreaddata) {
            return m_pad->ReadData(index);
        }
        return 0;
    }

    BYTE SetModeAndLock(int index, BYTE value) {
        switch (index) {
        case 0:
            m_pad->m_analog = value == 1;
            break;
        case 1:
            m_pad->m_locked = value == 3;
            break;
        }
        return 0;
    }

    BYTE QueryModelAndMode(int index, BYTE) {
        switch (index) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return (BYTE)(m_pad->m_analog ? 1 : 0);
        case 3:
            return (BYTE)(m_pad->m_ds2native ? 1 : 2);
        case 4:
            return 1;
        }
        return 0;
    }

    BYTE QueryUnknown1(int index, BYTE value) {
        switch (index) {
        case 0:
            m_unknown1 = value;
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return (BYTE)(m_unknown1 ? 0x01 : 0x02);
        case 4:
            return (BYTE)(m_unknown1 ? 0x01 : 0x00);
        case 5:
            return (BYTE)(m_unknown1 ? 0x14 : 0x0a);
        }
        return 0;
    }

    BYTE QueryUnknown2(int index, BYTE) {
        switch (index) {
        case 2:
            return 2;
        case 4:
            return 1;
        }
        return 0;
    }

    BYTE QueryUnknown3(int index, BYTE value) {
        switch (index) {
        case 0:
            m_unknown3 = value;
            return 0;
        case 3:
            return (BYTE)(m_unknown3 ? 0x07 : 0x04);
        }
        return 0;
    }

    BYTE ConfigVibration(int index, BYTE value) {
        switch (index) {
        case 0:
            return value;
        case 1:
            m_pad->m_vibration = value == 1;
            return value;
        }
        return 0xff;
    }

    BYTE SetDS2NativeMode(int index, BYTE) {
        switch (index) {
        case 5:
            m_pad->m_ds2native = true;
            return 'Z';
        }
        return 0;
    }

    BYTE UnknownCommand(int, BYTE) {
        // printf("Unknown command %02x (%d, %02x)\n", m_cmd, index, value);
        return 0;
    }

public:
    XPadPlugin()
        : m_pad(NULL)
        , m_index(-1)
        , m_cfgreaddata(false)
        , m_handler(NULL) {
        m_pads.push_back(new XPad());
        m_pads.push_back(new XPad());
        for (int i = 0; i < countof(m_handlers); i++) {
            m_handlers[i] = &XPadPlugin::UnknownCommand;
        }
        m_handlers['@'] = &XPadPlugin::DS2Enabler;
        m_handlers['A'] = &XPadPlugin::QueryDS2AnalogMode;
        m_handlers['B'] = &XPadPlugin::ReadDataAndVibrate;
        m_handlers['C'] = &XPadPlugin::ConfigMode;
        m_handlers['D'] = &XPadPlugin::SetModeAndLock;
        m_handlers['E'] = &XPadPlugin::QueryModelAndMode;
        m_handlers['F'] = &XPadPlugin::QueryUnknown1;
        m_handlers['G'] = &XPadPlugin::QueryUnknown2;
        m_handlers['L'] = &XPadPlugin::QueryUnknown3;
        m_handlers['M'] = &XPadPlugin::ConfigVibration;
        m_handlers['O'] = &XPadPlugin::SetDS2NativeMode;
    }

    virtual ~XPadPlugin() {
        for (std::vector<XPad*>::iterator i = m_pads.begin(); i != m_pads.end(); i++) {
            delete *i;
        }
        m_pads.clear();
    }

    void StartPoll(int pad) {
        m_pad = m_pads[(unsigned int)(pad) & 1];
        m_index = 0;
    }

    BYTE Poll(BYTE value) {
        BYTE ret = 0;
        switch (++m_index) {
        case 1:
            m_cmd = value;
            m_handler = m_handlers[value];
            ret = (value == 'B' || value == 'C') ? m_pad->GetId() : (BYTE)0xf3;
            break;
        case 2:
            assert(value == 0);
            ret = 'Z';
            break;
        default:
            ret = (this->*m_handler)(m_index - 3, value);
            break;
        }
        return ret;
    }
};

class CKeyEventList : protected CCritSec {
    std::list<KeyEvent> m_list;
    CKeyEventList(const CKeyEventList &);
    CKeyEventList &operator=(const CKeyEventList &) = delete;
public:
    CKeyEventList(void) {}
    void Push(UINT32 event, UINT32 key) {
        CAutoLock cAutoLock(this);
        KeyEvent e;
        e.event = event;
        e.key = key;
        m_list.push_back(e);
    }
    bool Pop(KeyEvent* e) {
        CAutoLock cAutoLock(this);
        if (m_list.empty()) return false;
        (*e) = m_list.front();
        m_list.pop_front();
        return true;
    }
};

//-----------------------------------------------------------------------------
static bool          s_ps2 = false;
static XPadPlugin    s_padplugin;
static CKeyEventList s_event;

static int s_nRefs = 0;
static HWND s_hWnd = NULL;
static WNDPROC s_GSWndProc = NULL;
//-----------------------------------------------------------------------------
static int my_wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI PADwndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (my_wnd_proc(hWnd, msg, wParam, lParam)) { return TRUE; }

    switch (msg) {
    case WM_KEYDOWN:
        if (lParam & 0x40000000) return TRUE;
        s_event.Push(KEYPRESS, wParam);
        return TRUE;
    case WM_KEYUP:
        s_event.Push(KEYRELEASE, wParam);
        return TRUE;
    case WM_DESTROY:
    case WM_QUIT:
        s_event.Push(KEYPRESS, VK_ESCAPE);
        break;
    }
    return CallWindowProc(s_GSWndProc, hWnd, msg, wParam, lParam);
}


//-----------------------------------------------------------------------------
BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID) {
    return TRUE;
}
//-----------------------------------------------------------------------------
EXPORT_C_(UINT32) PSEgetLibType() {
    return PSE_LT_PAD;
}

EXPORT_C_(char*) PSEgetLibName() {
    return PLUGIN_NAME;
}

EXPORT_C_(UINT32) PSEgetLibVersion() {
    return (PLUGIN_MINOR << 16) | (PLUGIN_REVISION << 8) | PLUGIN_BUILD;
}

EXPORT_C_(UINT32) PS2EgetLibType() {
    return PS2E_LT_PAD;
}

EXPORT_C_(char*) PS2EgetLibName() {
    return PLUGIN_NAME;
}

EXPORT_C_(UINT32) PS2EgetLibVersion2(UINT32) {
    s_ps2 = true;

    return (PLUGIN_BUILD << 0) | (PLUGIN_REVISION << 8) | (PS2E_PAD_VERSION << 16) | (PLUGIN_MINOR << 24);
}

EXPORT_C_(UINT32) PADinit(UINT32) {
    return 0;
}

EXPORT_C PADshutdown() {}

EXPORT_C_(UINT32) PADopen(void* pDsp) {
    if (s_nRefs == 0) {
        if (s_ps2) {
            s_hWnd = *(reinterpret_cast<HWND*>(pDsp));
            s_GSWndProc = (WNDPROC)SetWindowLongPtr(s_hWnd, GWLP_WNDPROC, (LPARAM)PADwndProc);
        }
    }
    s_nRefs++;
    return 0;
}

EXPORT_C PADclose() {
    s_nRefs--;
    if (s_nRefs == 0) {
        if (s_ps2) {
            SetWindowLongPtr(s_hWnd, GWLP_WNDPROC, (LPARAM)s_GSWndProc);
        }
    }
}

EXPORT_C_(UINT32) PADquery() {
    return 3;
}

EXPORT_C_(BYTE) PADstartPoll(int pad) {
    s_padplugin.StartPoll(pad - 1);

    return 0xff;
}

EXPORT_C_(BYTE) PADpoll(BYTE value) {
    return s_padplugin.Poll(value);
}

EXPORT_C_(UINT32) PADreadPort(int port, PadDataS* data) {
    PADstartPoll(port + 1);

    data->type = (BYTE)(PADpoll('B') >> 4);
    PADpoll(0);
    data->status = (WORD)(PADpoll(0) | (PADpoll(0) << 8));
    data->rightJoyX = data->moveX = PADpoll(0);
    data->rightJoyY = data->moveY = PADpoll(0);
    data->leftJoyX = PADpoll(0);
    data->leftJoyY = PADpoll(0);

    return 0;
}

EXPORT_C_(UINT32) PADreadPort1(PadDataS* ppds) {
    return PADreadPort(0, ppds);
}

EXPORT_C_(UINT32) PADreadPort2(PadDataS* ppds) {
    return PADreadPort(1, ppds);
}

EXPORT_C_(KeyEvent*) PADkeyEvent() {
    static KeyEvent e;

    return s_event.Pop(&e) ? &e : NULL;
}

EXPORT_C PADconfigure() {}

EXPORT_C PADabout() {}

EXPORT_C_(UINT32) PADtest() {
    return 0;
}
//-----------------------------------------------------------------------------

static void open_infer_client(HWND hWnd);
static void close_infer_client(HWND hWnd);

static void open_capture_client(HWND hWnd);
static void close_capture_client(HWND hWnd);
static void cancel_capture_client(HWND hWnd);

//-----------------------------------------------------------------------------
static int my_wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM) {
    switch (msg) {
    case WM_KEYUP:
        switch (wParam) {
        case VK_INSERT: open_infer_client(hWnd);  return 1;
        case VK_HOME  : close_infer_client(hWnd);  return 1;
        case VK_PRIOR : close_infer_client(hWnd);  return 1;

        case VK_DELETE: open_capture_client(hWnd);  return 1;
        case VK_END   : close_capture_client(hWnd);  return 1;
        case VK_NEXT  : cancel_capture_client(hWnd);  return 1;
        }
        break;
    case WM_DESTROY:
    case WM_QUIT:
        close_capture_client(hWnd);
        close_infer_client(hWnd);
        break;
    }
    return 0;
}


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

//-----------------------------------------------------------------------------
static volatile bool infer_client_connected = false;
static volatile bool infer_client_alive = false;
static HANDLE infer_client_pipe = NULL;

DWORD WINAPI  infer_client_thread(LPVOID lpParam) {
    HWND hWnd = (HWND)lpParam;
    AgentPacket packet;
    DWORD temp;

    {
        RECT rt;
        GetWindowRect(hWnd, &rt);
        packet.Command = (UINT32)AgentCommand::OpenInfer;
        packet.Data[0] = rt.left;
        packet.Data[1] = rt.top;
        packet.Data[2] = rt.right;
        packet.Data[3] = rt.bottom;
        if (!WriteFile(infer_client_pipe, &packet, sizeof(packet), &temp, NULL)) {
            goto do_disconnect;
        }
        FlushFileBuffers(infer_client_pipe);
    }

    while (infer_client_alive) {
        packet.Command = (UINT32)AgentCommand::DoInfer;
        if (!WriteFile(infer_client_pipe, &packet, sizeof(packet), &temp, NULL)) {
            goto do_disconnect;
        }
        FlushFileBuffers(infer_client_pipe);

        if (!ReadFile(infer_client_pipe, &packet, sizeof(packet), &temp, NULL)) {
            goto do_disconnect;
        }
        FlushFileBuffers(infer_client_pipe);

        switch (packet.Command) {
        case AgentCommand::PadStatus:
            is_server_activated = true;
            server_buttons = (WORD)packet.Data[0];
            server_left_x = (BYTE)packet.Data[1];
            server_left_y = (BYTE)packet.Data[2];
            break;
        default:
            goto do_disconnect;
        }
    }
do_disconnect:
    packet.Command = (UINT32)AgentCommand::CloseInfer;
    WriteFile(infer_client_pipe, &packet, sizeof(packet), &temp, NULL);
    FlushFileBuffers(infer_client_pipe);
    CloseHandle(infer_client_pipe);
    infer_client_alive = false;
    is_server_activated = false;
    infer_client_pipe = NULL;
    infer_client_connected = false;
    return 0;
}
//-----------------------------------------------------------------------------
static void open_infer_client(HWND hWnd) {
    if (!infer_client_connected) {
        close_capture_client(hWnd);
        infer_client_pipe = CreateFile(AGENT_CONNECTION_NAME, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (infer_client_pipe == INVALID_HANDLE_VALUE) { return; }
        infer_client_connected = true;
        infer_client_alive = true;
        CreateThread(NULL, 0, infer_client_thread, (LPVOID)hWnd, 0, 0);
        Sleep(100);
    }
}
//-----------------------------------------------------------------------------
static void close_infer_client(HWND) {
    infer_client_alive = false;
    do {
        Sleep(100);
    } while (infer_client_connected);
}

//-----------------------------------------------------------------------------
namespace {
    volatile bool capture_client_connected = false;
    volatile bool capture_client_alive = false;
    HANDLE capture_client_pipe = NULL;
    UINT32 capture_done_command = (UINT32)AgentCommand::CloseCapture;
}
DWORD WINAPI  capture_client_thread(LPVOID lpParam) {
    HWND hWnd = (HWND)lpParam;
    AgentPacket packet;
    DWORD temp;

    {
        RECT rt;
        GetWindowRect(hWnd, &rt);
        packet.Command = (UINT32)AgentCommand::OpenCapture;
        packet.Data[0] = rt.left;
        packet.Data[1] = rt.top;
        packet.Data[2] = rt.right;
        packet.Data[3] = rt.bottom;
        if (!WriteFile(capture_client_pipe, &packet, sizeof(packet), &temp, NULL)) {
            goto do_disconnect;
        }
        FlushFileBuffers(capture_client_pipe);
    }

    while (capture_client_alive) {
        packet.Command = (UINT32)AgentCommand::DoCapture;
        if (!WriteFile(capture_client_pipe, &packet, sizeof(packet), &temp, NULL)) {
            goto do_disconnect;
        }
        FlushFileBuffers(capture_client_pipe);
        if (!ReadFile(capture_client_pipe, &packet, sizeof(packet), &temp, NULL)) {
            goto do_disconnect;
        }
        FlushFileBuffers(capture_client_pipe);

        switch (packet.Command) {
        case AgentCommand::PadStatus:
            is_server_activated = true;
            server_buttons = (WORD)packet.Data[0];
            server_left_x = (BYTE)packet.Data[1];
            server_left_y = (BYTE)packet.Data[2];
            break;
        default:
            goto do_disconnect;
        }
    }
do_disconnect:
    packet.Command = capture_done_command;
    WriteFile(capture_client_pipe, &packet, sizeof(packet), &temp, NULL);
    FlushFileBuffers(capture_client_pipe);
    CloseHandle(capture_client_pipe);
    capture_client_alive = false;
    is_server_activated = false;
    capture_client_pipe = NULL;
    capture_client_connected = false;
    return 0;
}
//-----------------------------------------------------------------------------
static void open_capture_client(HWND hWnd) {
    if (!capture_client_connected) {
        close_infer_client(hWnd);
        capture_client_pipe = CreateFile(AGENT_CONNECTION_NAME, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (capture_client_pipe == INVALID_HANDLE_VALUE) { return; }
        capture_client_connected = true;
        capture_client_alive = true;
        CreateThread(NULL, 0, capture_client_thread, (LPVOID)hWnd, 0, 0);
        Sleep(100);
    }
}
//-----------------------------------------------------------------------------
static void close_capture_client(HWND) {
    capture_done_command = (UINT32)AgentCommand::CloseCapture;
    capture_client_alive = false;
    do {
        Sleep(100);
    } while (capture_client_connected);
}

//-----------------------------------------------------------------------------
static void cancel_capture_client(HWND) {
    capture_done_command = (UINT32)AgentCommand::CancelCapture;
    capture_client_alive = false;
    do {
        Sleep(100);
    } while (capture_client_connected);
}
