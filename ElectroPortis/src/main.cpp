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
#include "saver.hpp"

void
exit_handler(void)
{
    timeEndPeriod(1);
//#ifndef NDEBUG
//    _CrtDumpMemoryLeaks();
//#endif
}

int APIENTRY
_tWinMain(_In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPTSTR    lpCmdLine,
  _In_ int       nCmdShow) try
{
    using namespace saver;

    LPCTSTR cmdline = lpCmdLine;
    g_hInstance = hInstance;
    g_nCmdShow = nCmdShow;

    timeBeginPeriod(1);
    std::atexit(exit_handler);
    std::terminate_handler(exit_handler);

    for (;;) {
        switch (*cmdline) {
        case TEXT(' '):
        case TEXT('-'):
        case TEXT('/'):
            cmdline++;
            break;

        case TEXT('p'):
        case TEXT('P'):
            do /* advance to parent handle */
                cmdline++;
            while (TEXT(' ') == *cmdline);

            g_hParent = (HWND)(_tcstoul(cmdline, nullptr, 10));
            g_sm = SAVER_SAVER;
            return (g_hParent && nullptr != GetParent(g_hParent))
                ? run()
                : EXIT_FAILURE;

        case TEXT('s'):
        case TEXT('S'):
            g_sm = SAVER_SAVER;
            g_fullscreen = FULLSCREEN_SPAN;
            return run();

        case TEXT('c'): /* ep has no settings */
        case TEXT('C'):
            MessageBox(nullptr, TEXT("ElectroPaint has no options."),
                CLASSNAME, MB_OK | MB_ICONINFORMATION);
            return EXIT_SUCCESS;

        case TEXT('w'): /* run in window */
        case TEXT('W'):
        default:
            g_sm = SAVER_STANDALONE;
            return run();
        }
    }
} catch (saver::util::failure_t &e) {
    saver::util::err_msg(e.msg);
    return EXIT_FAILURE;
}
