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
#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef __cplusplus
#include "util.hpp"
#endif

#define CPL_PREVIEW() (nullptr != saver::g_hParent)

typedef enum saver_mode {
    SAVER_STANDALONE = 0, /* running via /w option */
    SAVER_SAVER = 1 /* running as preview or actual screensaver */
} saver_mode;

typedef enum fs_mode {
    FULLSCREEN_NONE = 0,
    FULLSCREEN_SINGLE = 1,
    FULLSCREEN_SPAN = 2,
    FULLSCREEN_CLONE = 3
    /* FULLSCREEN_UNIQUE = 4 */
} fs_mode;

typedef enum saver_msg {
    SAVER_FSMODE_CHANGE = WM_USER + 0,
    SAVER_WINCOUNT_CHANGE = WM_USER + 1
} saver_msg;

typedef enum saver_constant {
    WAKE_THRESHOLD = 4 /* in pixels */
} saver_constant;

typedef unsigned long wincount_t;

#ifdef __cplusplus
namespace saver {
struct saver_t {
    explicit saver_t(const fs_mode fs, const wincount_t wc)
        : winleft(0), wintop(0)
        , bounds({ 0, 0, 0, 0 })
        , hWnd(nullptr), hDC(nullptr), master(false)
        , fullscreen(fs)
        , wincount(wc)
    {}

    bool operator==(const saver_t& other) { return &other == this; }

    int winleft, wintop;
    RECT bounds;
    saver::util::thread_t thr;
    HWND hWnd;
    HDC hDC;
    bool master;
    fs_mode fullscreen;
    wincount_t wincount;
};

extern saver::util::event_t g_active;

extern const LPCTSTR CLASSNAME;
extern HWND g_hParent; /* for control panel mini-preview */
extern HINSTANCE g_hInstance; /* instance of the program */
extern int g_nCmdShow; /* SW_SHOW mode */
extern fs_mode g_fullscreen;
extern saver_mode g_sm;

int run(void);
}
#endif