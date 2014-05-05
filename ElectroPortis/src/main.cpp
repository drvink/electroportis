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
