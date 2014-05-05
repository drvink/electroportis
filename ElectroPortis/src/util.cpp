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