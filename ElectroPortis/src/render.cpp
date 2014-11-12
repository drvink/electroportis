/*
 * Copyright (C) 2014 Mark Laws
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "stdafx.hpp"
#include "ep.h"
#include "timeutil.hpp"
#include "replay_draw.hpp"
#include "util.hpp"
#include "saver.hpp"

namespace saver { namespace render {
static HDC
set_pixel_format(const HWND hWnd)
{
    PIXELFORMATDESCRIPTOR pfd;
    const HDC hDC = GetDC(hWnd);

    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

    const int format = ChoosePixelFormat(hDC, &pfd);
    if (!format)
        EP_DIE("Cannot find a suitable pixel format.");
    if (!SetPixelFormat(hDC, format, &pfd))
        EP_DIE("SetPixelFormat failed:  cannot set format specified.");

    return hDC;
}

static void
render_loop(saver_t * const ctx)
{
    using namespace saver::timeutil;

    EPANOS_ARGS ARGS;
    MSG msg;
    LARGE_INTEGER freq, drawstart, drawend;
    long long error = 0;
    long long deadline;
    DWORD waitres, timeout = 0;

    QueryPerformanceFrequency(&freq);
    const long long sixteen_ms = qpc_units_of_usec(&freq, 16666);
    const long long one_ms = qpc_units_of_usec(&freq, 1000);

    do {
        DWORD tmres;

        g_active.wait(INFINITE);
        if (ctx->master) {
            g_replay_list_lock.acquireLockExclusive();
            if (1 < ctx->wincount)
                clear_replay_list();
            QueryPerformanceCounter(&drawstart);
            display__Gv(&ARGS, ctx->wincount);
            QueryPerformanceCounter(&drawend);
            g_replay_list_lock.releaseLockExclusive();
        } else {
            g_replay_list_lock.acquireLockShared();
            QueryPerformanceCounter(&drawstart);
            replay_draw();
            QueryPerformanceCounter(&drawend);
            g_replay_list_lock.releaseLockShared();
        }
        deadline = drawstart.QuadPart + sixteen_ms;
        timeout = calc_timeout(freq.QuadPart,
            qpc_diff(&drawend, &drawstart),
            sixteen_ms);
        tmres = (timeout
            ? MsgWaitForMultipleObjects(0, 0, TRUE, timeout, QS_ALLEVENTS)
            : WAIT_TIMEOUT);
        if (WAIT_TIMEOUT == tmres) {
            spin_until_deadline(deadline);
            SwapBuffers(ctx->hDC);
        }

        if (PeekMessage(&msg, (HWND)-1, 0, 0, PM_REMOVE)) {
            switch (msg.message) {
            case WM_SIZE: {
                const auto width = LOWORD(msg.lParam);
                const auto height = HIWORD(msg.lParam);

                reshape__GiT1((GLuint)width, (GLuint)height);
                UpdateWindow(ctx->hWnd);
                break;
            }

            case SAVER_FSMODE_CHANGE:
                if (ctx->master)
                    ctx->fullscreen = (fs_mode)msg.wParam;
                break;

            case SAVER_WINCOUNT_CHANGE:
                ctx->wincount = (wincount_t)msg.wParam;
                break;

            default:
                break;
            }
        }

        waitres = ctx->thr.quitting.wait(0);
    } while (WAIT_OBJECT_0 != waitres && WAIT_FAILED != waitres);
}

DWORD WINAPI
render(LPVOID param)
{
    MSG msg;
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
    saver_t *ctx = (saver_t *)param;
    ctx->hDC = set_pixel_format(ctx->hWnd);

    /*
     * vmware's GL driver can crash if a context is created while another
     * context is drawing, so block other threads from drawing while we're
     * making a context
     */
    g_replay_list_lock.acquireLockExclusive();
    const HGLRC hRC = wglCreateContext(ctx->hDC);

    wglMakeCurrent(ctx->hDC, hRC);
    g_replay_list_lock.releaseLockExclusive();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_FLAT);
    glClear(GL_COLOR_BUFFER_BIT);

    /* enable vsync */
    wglSwapIntervalEXT =
        (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    if (wglSwapIntervalEXT)
        wglSwapIntervalEXT(1);

    /* tell main/message loop thread we're ready */
    PeekMessage(&msg, nullptr, WM_USER, WM_USER, PM_NOREMOVE);
    ctx->thr.msgq_ready.set();

    ShowWindow(ctx->hWnd, g_nCmdShow);
    if (!CPL_PREVIEW())
        SetForegroundWindow(ctx->hWnd);
    SetFocus(ctx->hWnd);
    reshape__GiT1((GLuint)ctx->bounds.right, (GLuint)ctx->bounds.bottom);

    render_loop(ctx);

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hRC);
    ReleaseDC(ctx->hWnd, ctx->hDC);
    return 1;
}
}
}