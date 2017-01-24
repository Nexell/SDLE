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

#ifndef _MAIN_GAME_INTERFACE_H_
#define _MAIN_GAME_INTERFACE_H_

//-----------------------------------------------------------------------------
//
//  customizing parameters
//
//-----------------------------------------------------------------------------
#define CAPTURE_WIDTH      400
#define CAPTURE_HEIGHT     166
#define CAPTURE_CH         3     // 3:RGB 1:Luminance
#define CAPTURE_FRAMERATE  15.0f
#define VIEW_WINDOW_SCALE  1

//-----------------------------------------------------------------------------
//
//  customizing functions
//
//-----------------------------------------------------------------------------
struct GameInterface {
    float m_steering;  // -1.0(left) ~ +1.0(right)
    bool  m_acclerator;
    bool  m_break;
};
extern void init_capture_server(HWND hWindow);
extern void open_capture_server(HWND hWindow);
extern GameInterface do_capture_server(HWND hWindow, HDC hDC, const unsigned char* pframebuffer, float velocity);
extern void close_capture_server(HWND hWindow, bool save_data);
extern void init_infer_server(HWND hWindow);
extern void open_infer_server(HWND hWindow);
extern GameInterface do_infer_server(HWND hWindow, HDC hDC, const unsigned char* pframebuffer, float velocity);
extern void close_infer_server(HWND hWindow);

#endif  // _MAIN_GAME_INTERFACE_H_

