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

//-----------------------------------------------------------------------------
#pragma warning(disable : 4100)  // unreferenced formal parameter
#pragma warning(disable : 4711)  // selected for automatic inline expansion
#pragma warning(disable : 4710)  // function not inlined
#pragma warning(disable : 4505)  // unreferenced local function has been removed
#pragma warning(push, 3)
#include <windows.h>
#include "Shlwapi.h"
#include <assert.h>
#include <stdio.h>
#include <io.h>
#include <string>
#include "./zlib.h"
#pragma warning(pop)
#include "./main_game_interface.h"

//-----------------------------------------------------------------------------
#define CURSOR_SIZE 40
#define CAPTURE_DATA_FOLDER ".\\captured"
#define CAPTURE_FRAME_SKIP  4
#define CAPTURE_VELOCITY    70

namespace {
    gzFile       fp_vector_framebuffer = NULL;
    gzFile       fp_vector_velocity = NULL;
    gzFile       fp_vector_steering = NULL;
    char         last_captured_file_base[256];
    char         last_captured_file_f[256];
    char         last_captured_file_v[256];
    char         last_captured_file_s[256];
    unsigned int last_vector_count;
    unsigned int captured_tick;
}  // namespace

//-----------------------------------------------------------------------------
void init_capture_server(HWND hWindow) {
    if ( !PathFileExists(TEXT(CAPTURE_DATA_FOLDER)) ) {
        CreateDirectory(TEXT(CAPTURE_DATA_FOLDER), NULL);
    }
}

//-----------------------------------------------------------------------------
void open_capture_server(HWND hWindow) {
    int screen_width = GetSystemMetrics(SM_CXFULLSCREEN);
    int screen_height = GetSystemMetrics(SM_CYFULLSCREEN);
    SetCursorPos(screen_width / 2, screen_height - CURSOR_SIZE);

    SYSTEMTIME system_time;
    GetLocalTime(&system_time);
    snprintf(last_captured_file_base, sizeof(last_captured_file_base)-1,
            "%s\\%04d%02d%02d_%02d%02d", CAPTURE_DATA_FOLDER,
            system_time.wYear, system_time.wMonth, system_time.wDay,
            system_time.wHour, system_time.wSecond);

    snprintf(last_captured_file_f, sizeof(last_captured_file_f) - 1, "%s_f.gz", last_captured_file_base);
    fp_vector_framebuffer = gzopen(last_captured_file_f, "wb");

    snprintf(last_captured_file_v, sizeof(last_captured_file_v) - 1, "%s_v.gz", last_captured_file_base);
    fp_vector_velocity = gzopen(last_captured_file_v, "wb");

    snprintf(last_captured_file_s, sizeof(last_captured_file_s) - 1, "%s_s.gz", last_captured_file_base);
    fp_vector_steering = gzopen(last_captured_file_s, "wb");


    last_vector_count = 0;
    captured_tick = 0;
}

//-----------------------------------------------------------------------------
static bool is_key_pushed(int key);
static float get_steering_control(void);
extern void get_cruise_control(float velocity, float target_velocity, bool* p_acc, bool* p_break);
static void save_capture_data(const unsigned char* pframebuffer, float velocity, const GameInterface& user_control);
//-----------------------------------------------------------------------------
GameInterface do_capture_server(HWND hWindow, HDC hDC, const unsigned char* pframebuffer, float velocity) {
    GameInterface result;
    result.m_steering = get_steering_control();
    get_cruise_control(velocity, CAPTURE_VELOCITY, &result.m_acclerator, &result.m_break);
    // result.m_acclerator = is_key_pushed('X');
    // result.m_break = is_key_pushed('Z');

    if (0 == (captured_tick%CAPTURE_FRAME_SKIP)) {
        save_capture_data(pframebuffer, velocity, result);
    }

    captured_tick++;

    printf("Velocity : %4.1f  Steering : %5.2f  acc : %s, break: %s\r",
        velocity,
        result.m_steering,
        result.m_acclerator ? "ON " : "OFF",
        result.m_break ? "ON " : "OFF");
    return result;
}
//-----------------------------------------------------------------------------
static bool is_key_pushed(int key) {
    return (0 != (GetAsyncKeyState(key) & 0x8000));
}

static float get_steering_control(void) {
    int screen_width = GetSystemMetrics(SM_CXFULLSCREEN);
    int screen_height = GetSystemMetrics(SM_CYFULLSCREEN);
    POINT mpos;
    GetCursorPos(&mpos);
    float x = (mpos.x - (screen_width / 2.0f)) / (screen_width / 4.0f);
    if (x < -1.0) x = -1.0f;
    if (x > 1.0) x = 1.0f;

    if (mpos.x < CURSOR_SIZE) { mpos.x = CURSOR_SIZE; }
    if (mpos.x >= screen_width - CURSOR_SIZE) { mpos.x = screen_width - CURSOR_SIZE; }
    mpos.y = screen_height - CURSOR_SIZE;
    SetCursorPos(mpos.x, mpos.y);
    return x;

    // static float steering_state;
    // bool right = is_key_pushed(VK_RIGHT);
    // bool left  = is_key_pushed(VK_LEFT);
    // if (right) { steering_state+=1.0f; }
    // else if (left) { steering_state -= 1.0f; }
    // else           { steering_state /= 2.0f; }
    // if (steering_state > CAPTURE_FRAMERATE) { steering_state = CAPTURE_FRAMERATE; }
    // if (steering_state < -CAPTURE_FRAMERATE) { steering_state = -CAPTURE_FRAMERATE; }
    // return steering_state / CAPTURE_FRAMERATE;
}

//-----------------------------------------------------------------------------
extern void get_cruise_control(float velocity, float target_velocity, bool* p_acc, bool* p_break) {
    float local_diff_velocity = target_velocity - velocity;
    float cruise_acc;
    float cruise_break;
    if (local_diff_velocity > 2.0f) {
        cruise_acc = 1.0f;
        cruise_break = 0.0f;
    } else if (local_diff_velocity >= 0.0f) {
        cruise_acc = ((local_diff_velocity - 0.0f) * 0.8f / (2.0f - 0.0f)) + 0.2f;
        cruise_break = 0.0f;
    } else if (local_diff_velocity < -15.0f) {
        cruise_acc = 0.0f;
        cruise_break = 0.3f;
    } else {  // if (local_diff_velocity < 0.0f)
        cruise_acc = 0.0f;
        cruise_break = (((-local_diff_velocity) - 0.0f) * 0.3f / (15.0f - 0.0f)) + 0.0f;
    }
    (*p_acc)   = ((cruise_acc   * RAND_MAX) > static_cast<float>(rand()));
    (*p_break) = ((cruise_break * RAND_MAX) > static_cast<float>(rand()));
}

//-----------------------------------------------------------------------------
static void save_capture_data(const unsigned char* pframebuffer, float velocity, const GameInterface& user_control) {
    gzwrite(fp_vector_framebuffer, pframebuffer, CAPTURE_WIDTH * CAPTURE_HEIGHT * CAPTURE_CH);
    gzwrite(fp_vector_velocity, &velocity, sizeof(velocity));
    gzwrite(fp_vector_steering, &user_control.m_steering, sizeof(user_control.m_steering));
    last_vector_count++;
}
//-----------------------------------------------------------------------------
std::wstring convert_mbs_to_wcs(const std::string& mbs) {
    std::wstring wcs;
    wcs.assign(mbs.begin(), mbs.end());
    return wcs;
}
//-----------------------------------------------------------------------------
void close_capture_server(HWND hWindow, bool save_data) {
    if (fp_vector_framebuffer) { gzclose(fp_vector_framebuffer); }
    if (fp_vector_velocity) { gzclose(fp_vector_velocity); }
    if (fp_vector_steering) { gzclose(fp_vector_steering); }
    fp_vector_framebuffer = NULL;
    fp_vector_velocity = NULL;
    fp_vector_steering = NULL;
    if (save_data && (last_vector_count > 0)) {
        size_t ins_pos = strlen(last_captured_file_base);
        snprintf(last_captured_file_base + ins_pos, sizeof(last_captured_file_base)- ins_pos-1, "_f_%04d.gz", last_vector_count);
        MoveFile(convert_mbs_to_wcs(last_captured_file_f).c_str(), convert_mbs_to_wcs(last_captured_file_base).c_str());
        snprintf(last_captured_file_base + ins_pos, sizeof(last_captured_file_base) - ins_pos - 1, "_v_%04d.gz", last_vector_count);
        MoveFile(convert_mbs_to_wcs(last_captured_file_v).c_str(), convert_mbs_to_wcs(last_captured_file_base).c_str());
        snprintf(last_captured_file_base + ins_pos, sizeof(last_captured_file_base) - ins_pos - 1, "_s_%04d.gz", last_vector_count);
        MoveFile(convert_mbs_to_wcs(last_captured_file_s).c_str(), convert_mbs_to_wcs(last_captured_file_base).c_str());
    } else {
        DeleteFile(convert_mbs_to_wcs(last_captured_file_f).c_str());
        DeleteFile(convert_mbs_to_wcs(last_captured_file_v).c_str());
        DeleteFile(convert_mbs_to_wcs(last_captured_file_s).c_str());
    }
}



