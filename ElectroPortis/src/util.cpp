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

#define SET_FP_TO_HANDLE(file, handle) \
    *(file) = *(handle); \
    setvbuf((file), NULL, _IONBF, 0);

namespace saver { namespace util {
static FILE *
get_stream(const DWORD which, const char *mode)
{
    int hConHandle;
    long lStdHandle;

    lStdHandle = (long)GetStdHandle(which);
    hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    return _fdopen(hConHandle, mode);
}

void
open_console(void)
{
    FILE *fp;
    /* allocate a console for this app */
    AllocConsole();

    fp = get_stream(STD_OUTPUT_HANDLE, "w");
    SET_FP_TO_HANDLE(stdout, fp);
    fp = get_stream(STD_ERROR_HANDLE, "w");
    SET_FP_TO_HANDLE(stderr, fp);
    fp = get_stream(STD_INPUT_HANDLE, "r");
    SET_FP_TO_HANDLE(stdin, fp);
}
}}