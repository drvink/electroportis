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

namespace saver { namespace timeutil {
inline void
spin_until_deadline(const long long deadline)
{
    LARGE_INTEGER cur;

    do
        QueryPerformanceCounter(&cur);
    while (cur.QuadPart < deadline);
}

inline long long
qpc_units_of_usec(const LARGE_INTEGER * const freq, const long long us)
{
    return (freq->QuadPart * us) / 1000000;
}

inline long long
usec_of_qpc_units(const long long qpc, const long long freq)
{
    return (qpc * 1000000) / freq;
}

inline long long
qpc_diff(const LARGE_INTEGER * const x, const LARGE_INTEGER * const y)
{
    return x->QuadPart - y->QuadPart;
}

inline DWORD
calc_timeout(const long long freq, const long long framecalc_qpc,
             const long long target_period_qpc)
{
    long long duration_us;
    DWORD duration_ms;

    if (framecalc_qpc < 0 || framecalc_qpc > target_period_qpc)
        return 0;
    duration_us = usec_of_qpc_units(target_period_qpc - framecalc_qpc, freq);
    duration_ms = (DWORD)(duration_us / 1000);
    return duration_ms;
}
}
}