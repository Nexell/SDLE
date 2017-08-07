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
#pragma warning(push, 3)
#include <windows.h>
#include <assert.h>
#pragma warning(push, 0)
#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"
#pragma warning(pop)
#pragma warning(pop)
#include "./main_game_interface.h"

#define INFER_MODELFILE  ".\\models\\frozen_graph.pb"
#define INFER_VELOCITY    60

void init_infer_server(HWND hWindow) {
}

void open_infer_server(HWND hWindow) {
}

static float get_steering_control(const unsigned char* pframebuffer, float velocity);
extern void get_cruise_control(float velocity, float target_velocity, bool* p_acc, bool* p_break);
GameInterface do_infer_server(HWND hWindow, HDC hDC, const unsigned char* pframebuffer, float velocity) {
    GameInterface result;
    result.m_steering = get_steering_control(pframebuffer, velocity);
    get_cruise_control(velocity, INFER_VELOCITY, &result.m_acclerator, &result.m_break);

    printf("Velocity : %4.1f  Steering : %5.2f  acc : %s, break: %s\r",
        velocity,
        result.m_steering,
        result.m_acclerator ? "ON " : "OFF",
        result.m_break ? "ON " : "OFF");

    return result;
}

void close_infer_server(HWND hWindow) {
}




//-----------------------------------------------------------------------------
namespace {
    tensorflow::Session* tf_session = 0;
    tensorflow::Tensor infer_i(tensorflow::DT_UINT8, tensorflow::TensorShape({1, CAPTURE_HEIGHT, CAPTURE_WIDTH, CAPTURE_CH }));
    std::vector<std::pair<std::string, tensorflow::Tensor>> tf_inputs = { { "infer_i", infer_i } };
    std::vector<tensorflow::Tensor> tf_outputs;
    void close_tf_session(void);
    bool open_tf_session(void) {
        tensorflow::GraphDef graph_def;
        tensorflow::Status status;
        status = tensorflow::NewSession(tensorflow::SessionOptions(), &tf_session);
        if (!status.ok()) {
            std::cout << status.ToString() << "\n";
            close_tf_session();
            return false;
        }
        status = tensorflow::ReadBinaryProto(tensorflow::Env::Default(), INFER_MODELFILE, &graph_def);
        if (!status.ok()) {
            std::cout << status.ToString() << "\n";
            close_tf_session();
            return false;
        }
        status = tf_session->Create(graph_def);
        if (!status.ok()) {
            std::cout << status.ToString() << "\n";
            close_tf_session();
            return false;
        }
        return true;
    }
    void close_tf_session(void) {
        tensorflow::Session* cur_session;
        cur_session = tf_session;
        tf_session = NULL;
        if (cur_session) { cur_session->Close(); }
    }
}  // namespace

static float get_steering_control(const unsigned char* pframebuffer, float velocity) {
    if (!tf_session) {
        if (!open_tf_session()) {
            return -1;
        }
    }
    auto in = infer_i.flat<unsigned char>();
    for (int i = 0; i < in.size(); i++) {
        in(i) = *pframebuffer++;
    }
    tensorflow::Status status = tf_session->Run(tf_inputs, { "infer_o" }, {}, &tf_outputs);
    if (!status.ok()) {
        std::cout << status.ToString() << "\n";
        return -1;
    }
    return tf_outputs[0].flat<float>()(0);
}




