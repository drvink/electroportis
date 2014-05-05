#include "stdafx.hpp"
#include "ep.h"
#include "util.hpp"
#include "saver.hpp"
#include "render.hpp"

namespace saver {
saver::util::event_t g_active(TRUE, FALSE);
HWND g_hParent; /* for control panel mini-preview */
HINSTANCE g_hInstance; /* instance of the program */
int g_nCmdShow; /* SW_SHOW mode */
const LPCTSTR CLASSNAME = TEXT("ElectroPaint");
fs_mode g_fullscreen = FULLSCREEN_NONE;
saver_mode g_sm;

static const LPCTSTR MASTER_TITLE = TEXT("ElectroPaint (master)");
static const LPCTSTR CLONE_TITLE = TEXT("ElectroPaint (clone)");
static std::atomic<wincount_t> g_wincount;
static bool g_first_mouse_move = false;
static int g_cursor_vis;
static POINT g_mouse_point;
static saver::util::critsec_t g_workers_lock;
static std::list<saver_t> g_workers;
static bool g_userexit = false; /* asked to exit or got input during saver */

typedef std::lock_guard<saver::util::critsec_t> scoped_lock;

static inline saver_t *
get_ctx(const HWND hWnd)
{
    return (saver_t *)GetWindowLongPtr(hWnd, GWLP_USERDATA);
}

static void
kill_window(const saver_t& ctx)
{
    g_wincount--;
    SignalObjectAndWait(ctx.thr.quitting.ev.get(), ctx.thr.thr.get(), INFINITE,
        FALSE);
    DestroyWindow(ctx.hWnd);
}

static void
handle_mouse_move(const HWND hWnd)
{
    POINT move_point, check_point;

    /*
    * according to rswin32saver, some gfx drivers will kill the
    * screensaver by spuriously sending WM_MOUSEMOVE, so drop the first
    * mouse movement
    */
    if (!g_first_mouse_move)
        g_first_mouse_move = true;
    else if (!CPL_PREVIEW())
        g_userexit = true;

    /* check for real movements */
    GetCursorPos(&check_point);
    move_point.x = g_mouse_point.x - check_point.x;
    if (0 > move_point.x)
        move_point.x *= -1;
    move_point.y = g_mouse_point.y - check_point.y;
    if (0 > move_point.y)
        move_point.y *= -1;
    if ((move_point.x + move_point.y) > WAKE_THRESHOLD && SAVER_SAVER == g_sm)
        PostMessage(hWnd, WM_CLOSE, 0, 0);
    else
        g_mouse_point = check_point;
}

static void
notify_wincount_change(void)
{
    for (const auto &x : g_workers)
        PostThreadMessage(x.thr.tid, SAVER_WINCOUNT_CHANGE, g_wincount, 0);
}

static LRESULT CALLBACK
main_wndproc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_NCCREATE: {
        auto winarg = (saver_t *)((LPCREATESTRUCT)lParam)->lpCreateParams;

        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)winarg);
        break;
    }

    case WM_NCDESTROY:
        if (0 == g_wincount && FULLSCREEN_CLONE != g_fullscreen)
            PostQuitMessage(0);
        break;

    case WM_CREATE:
        if (SAVER_SAVER == g_sm && !CPL_PREVIEW())
            /* get initial mouse position */
            GetCursorPos(&g_mouse_point);
        g_workers_lock.lock();
        notify_wincount_change();
        g_workers_lock.unlock();
        break;

        /* for control panel preview */
    case WM_SHOWWINDOW:
        if (wParam)
            g_active.set();
        break;

    case WM_CLOSE:
        /*
         * in screensaver mode, the OS will send spurious WM_CLOSE messages, so
         * we need some logic to ensure the screensaver is only terminated if
         * the user did something to end it (keyboard/mouse activity)
         */
        if (SAVER_SAVER == g_sm && !g_userexit) {
            return 0; /* don't close window */
        } else {
            auto ctx = get_ctx(hWnd);

            g_active.set();
            scoped_lock lock(g_workers_lock);
            if (ctx->master) {
                for (auto it = g_workers.begin(); g_workers.end() != it;) {
                    kill_window(*it);
                    auto prev = it;
                    it = std::next(prev);
                    g_workers.erase(prev);
                }
            } else {
                kill_window(*ctx);
                g_workers.remove(*ctx);
                for (const auto &win : g_workers)
                    PostThreadMessage(win.thr.tid, SAVER_WINCOUNT_CHANGE,
                        g_wincount, 0);
            }
        }
        return 0;

        /* run when shown, suspend when minimized */
    case WM_ACTIVATE:
        if (!HIWORD(wParam))
            g_active.set();
        else
            g_active.reset();
        break;

    case WM_MOVE: {
        auto ctx = get_ctx(hWnd);

        if (FULLSCREEN_NONE == g_fullscreen && nullptr != ctx) {
            RECT rect;

            /* save window position */
            GetWindowRect(hWnd, &rect);
            ctx->winleft = rect.left;
            ctx->wintop = rect.top;
        }
        break;
    }

    /* send WM_SIZE to GL thread if it's running; otherwise, we handle it */
    case WM_SIZE: {
        auto ctx = get_ctx(hWnd);

        if (nullptr != ctx &&
            WAIT_OBJECT_0 == ctx->thr.msgq_ready.wait(0)) {
            /*
             * don't bother checking for failure of posting WM_SIZE; if it
             * does, all that happens is the window behaves oddly (the GL
             * viewport won't get changed)
             */
            PostThreadMessage(ctx->thr.tid, WM_SIZE, wParam, lParam);
            return 0;
        }
        break;
    }

    case WM_MOUSEMOVE:
        if (SAVER_STANDALONE == g_sm)
            break;
        handle_mouse_move(hWnd);
        return 0;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        if (SAVER_SAVER == g_sm && !CPL_PREVIEW()) {
            g_userexit = true;
            PostMessage(hWnd, WM_CLOSE, 0, 0);
            return 0;
        }
        break; /* handle normally in non-saver mode */

    case WM_SYSCOMMAND:
        if (!CPL_PREVIEW() || SAVER_STANDALONE == g_sm) {
            switch (wParam) {
            case SC_SCREENSAVE: /* prevent other screensavers */
                if (FULLSCREEN_NONE != g_fullscreen || SAVER_SAVER == g_sm)
                    return 0;
                break;

            case SC_MONITORPOWER:
                if (SAVER_STANDALONE == g_sm && FULLSCREEN_NONE != g_fullscreen)
                    return 0; /* prevent power-off */
                else if (SAVER_SAVER == g_sm && (1 == lParam || 2 == lParam))
                    g_active.reset(); /* don't run while in DPMS/off */
                else if (-1 == lParam)
                    g_active.set(); /* reactivate when powering on */
                break;

            default:
                break;
            }
        }
        break;

    default:
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

static LPCTSTR
get_style_bits(DWORD * const style, DWORD * const exstyle)
{
    LPCTSTR wintitle;

    if (SAVER_STANDALONE == g_sm) {
        *exstyle = WS_EX_APPWINDOW;
        wintitle = CLASSNAME;
        *style = FULLSCREEN_NONE != g_fullscreen
            ? WS_POPUP
            : WS_OVERLAPPEDWINDOW;
    } else if (CPL_PREVIEW()) { /* preview */
        /*
         * according to rswin32saver, the preview window title and full-screen
         * saver title must differ from each other
         */
        wintitle = TEXT("Screensaver Preview");
        *style = WS_CHILD;
    } else { /* saver */
        wintitle = TEXT("Screensaver");
        *style = WS_POPUP;
        *exstyle = WS_EX_TOPMOST;
    }
    *style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    return wintitle;
}

static HWND
create_window(void * const ctx, const int x, const int y,
              const int width, const int height, const LPCTSTR title)
{
    assert(nullptr != ctx);

    DWORD exstyle = 0, style = 0;
    RECT rect = { 0, 0, width, height };
    const LPCTSTR wintitle = get_style_bits(&style, &exstyle);

    if (SAVER_SAVER == g_sm && !CPL_PREVIEW()) {
        const HWND hOther = FindWindow(CLASSNAME, wintitle);

        if (nullptr != hOther && nullptr != GetParent(hOther)) {
            SetForegroundWindow(hOther);
            return nullptr; /* already have a window */
        }
    }

    /* clamp rect to client area */
    AdjustWindowRectEx(&rect, style, FALSE, exstyle);

    const HWND hWnd = CreateWindowEx(
        exstyle,
        CLASSNAME,
        title,
        style,
        x, y,
        rect.right - rect.left,
        rect.bottom - rect.top,
        nullptr != g_hParent ? g_hParent : nullptr,
        nullptr,
        g_hInstance,
        ctx);

    if ((SAVER_STANDALONE == g_sm || !CPL_PREVIEW()) && nullptr == hWnd)
        /* couldn't create window in standalone or non-preview saver mode */
        EP_DIE("Unable to create window.");
    return hWnd;
}

static void
get_fullscreen_metrics(const HWND hWnd, RECT * const rect)
{
    assert(FULLSCREEN_NONE != g_fullscreen);

    switch (g_fullscreen) {
    case FULLSCREEN_SINGLE:
    case FULLSCREEN_CLONE: {
        assert(nullptr != hWnd);

        auto mon = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
        if (nullptr == mon)
            EP_DIE("Monitor disappeared!");

        MONITORINFO moninfo;
        moninfo.cbSize = sizeof(MONITORINFO);
        if (FALSE == GetMonitorInfo(mon, &moninfo))
            EP_DIE("Error getting monitor info.");

        *rect = moninfo.rcMonitor;
        break;
    }

    case FULLSCREEN_SPAN:
        rect->left = GetSystemMetrics(SM_XVIRTUALSCREEN);
        rect->top = GetSystemMetrics(SM_YVIRTUALSCREEN);
        rect->right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
        rect->bottom = GetSystemMetrics(SM_CYVIRTUALSCREEN);
        break;

    default:
        assert(0);
    }
}
static void
get_window_metrics(RECT * const rect)
{
    rect->left = 0;
    rect->top = 0;

    if (SAVER_STANDALONE == g_sm && FULLSCREEN_NONE == g_fullscreen) {
        rect->right = 640;
        rect->bottom = 480;
    } else if (SAVER_SAVER == g_sm && CPL_PREVIEW()) { /* preview */
        RECT parentrect;

        GetClientRect(g_hParent, &parentrect);
        rect->right = parentrect.right;
        rect->bottom = parentrect.bottom;
    } else {
        assert(0);
    }
}

static void
set_cursor_visibility(void)
{
    assert(SAVER_STANDALONE == g_sm);

    if (FULLSCREEN_NONE == g_fullscreen)
        g_cursor_vis = ShowCursor(TRUE);
    else if (-1 < g_cursor_vis)
        g_cursor_vis = ShowCursor(FALSE);
}

static void
cycle_maybe_multimonitor(void)
{
    assert(SAVER_STANDALONE == g_sm);
    assert(FULLSCREEN_NONE != g_fullscreen);

    const int mc = GetSystemMetrics(SM_CMONITORS);
    if (1 == mc) {
        g_fullscreen = FULLSCREEN_NONE;
        return;
    }

    switch (g_fullscreen) {
    case FULLSCREEN_SINGLE:
        g_fullscreen = FULLSCREEN_SPAN;
        break;

    case FULLSCREEN_SPAN:
        g_fullscreen = FULLSCREEN_CLONE;
        break;

    case FULLSCREEN_CLONE:
        g_fullscreen = FULLSCREEN_NONE;
        break;

    default:
        assert(0);
    }
}

static void
cycle_fullscreen_mode(void)
{
    assert(SAVER_STANDALONE == g_sm);

    if (FULLSCREEN_NONE == g_fullscreen)
        g_fullscreen = FULLSCREEN_SINGLE;
    else
        cycle_maybe_multimonitor();

    set_cursor_visibility();
}

static void
switch_to_window_or_non_cloned_fs(const DWORD style, const DWORD exstyle)
{
    int left, top;
    RECT rect;
    auto master = &g_workers.front();

    ShowWindow(master->hWnd, SW_HIDE);
    SetWindowLongPtr(master->hWnd, GWL_STYLE, style);
    SetWindowLongPtr(master->hWnd, GWL_EXSTYLE, exstyle);

    switch (g_fullscreen) {
    case FULLSCREEN_NONE: /* windowed */
        get_window_metrics(&rect);
        /* these will be CW_USEDEFAULT; zero them */
        rect.left = 0;
        rect.top = 0;
        AdjustWindowRectEx(&rect, style, FALSE, exstyle);
        /* restore to saved window position */
        left = master->winleft;
        top = master->wintop;
        break;

    case FULLSCREEN_SINGLE:
    case FULLSCREEN_SPAN:
    case FULLSCREEN_CLONE:
        get_fullscreen_metrics(master->hWnd, &rect);
        AdjustWindowRectEx(&rect, style, FALSE, exstyle);
        left = rect.left;
        top = rect.top;
        break;

    default:
        assert(0);
    }

    int width, height;
    if (FULLSCREEN_SPAN == g_fullscreen) {
        width = rect.right;
        height = rect.bottom;
    } else {
        width = rect.right - rect.left;
        height = rect.bottom - rect.top;
    }
    SetWindowPos(master->hWnd, HWND_TOP, left, top, width, height,
        SWP_FRAMECHANGED);
    MoveWindow(master->hWnd, left, top, width, height, TRUE);
    PostThreadMessage(master->thr.tid, SAVER_FSMODE_CHANGE, g_fullscreen, 0);
    ShowWindow(master->hWnd, SW_SHOW);
}

static void
init_window(saver_t * const ctx, const RECT * const dims,
            const bool make_window, const bool defpos, const LPCTSTR title)
{
    if (defpos) {
        ctx->bounds.left = CW_USEDEFAULT;
        ctx->bounds.top = CW_USEDEFAULT;
    } else {
        ctx->bounds.left = dims->left;
        ctx->bounds.top = dims->top;
    }
    ctx->bounds.right = dims->right - dims->left;
    ctx->bounds.bottom = dims->bottom - dims->top;

    if (make_window) {
        ctx->hWnd = create_window(ctx, ctx->bounds.left, ctx->bounds.top,
            ctx->bounds.right, ctx->bounds.bottom, title);
        ctx->thr.init(saver::render::render, ctx);
        ctx->thr.run();
    }
}

static BOOL CALLBACK
set_up_clones(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor,
              LPARAM dwData)
{
    auto is_master = (bool *)dwData;
    saver_t *w;

    if (!*is_master) {
        scoped_lock lock(g_workers_lock);
        g_workers.emplace_back(g_fullscreen, ++g_wincount);
        w = &g_workers.back();
    } else {
        w = &g_workers.front();
        PostThreadMessage(w->thr.tid, SAVER_FSMODE_CHANGE, g_fullscreen, 0);
    }

    if (*is_master)
        init_window(w, lprcMonitor, false, false, MASTER_TITLE);
    else
        init_window(w, lprcMonitor, true, false, CLONE_TITLE);

    MoveWindow(w->hWnd, w->bounds.left, w->bounds.top,
        w->bounds.right, w->bounds.bottom, TRUE);

    *is_master = false;
    return TRUE;
}

static void
switch_to_cloned_fs(const DWORD style, const DWORD exstyle)
{
    bool first = true;
    EnumDisplayMonitors(NULL, NULL, set_up_clones, (LPARAM)&first);
}

static void
toggle_fullscreen(void)
{
    DWORD exstyle = 0, style = 0;

    assert(SAVER_STANDALONE == g_sm);

    cycle_fullscreen_mode();
    get_style_bits(&style, &exstyle);

    switch (g_fullscreen) {
    case FULLSCREEN_NONE:
    case FULLSCREEN_SINGLE:
    case FULLSCREEN_SPAN:
        /* go back to single-window: kill all but main worker */
        if (2 <= g_wincount) {
            scoped_lock lock(g_workers_lock);
            for (auto it = g_workers.rbegin();
                it != std::prev(g_workers.rend());
                ++it) {
                it->thr.quitting.set();
                PostMessage(it->hWnd, WM_CLOSE, 0, 0);
            }
        }
        switch_to_window_or_non_cloned_fs(style, exstyle);
        break;

    case FULLSCREEN_CLONE:
        switch_to_cloned_fs(style, exstyle);
        break;

    default:
        assert(0);
    }
}

static void
add_window(const bool initial)
{
    RECT dims;

    std::unique_lock<saver::util::critsec_t> lock(g_workers_lock);
    g_workers.emplace_back(g_fullscreen, ++g_wincount);
    auto worker = &g_workers.back();
    lock.unlock();
    LPCTSTR title;

    if (initial) {
        worker->master = true;
        title = MASTER_TITLE;

        if ((SAVER_STANDALONE == g_sm && FULLSCREEN_NONE != g_fullscreen) ||
            (SAVER_SAVER == g_sm && !CPL_PREVIEW())) {
            worker->master = true;
            get_fullscreen_metrics(worker->hWnd, &dims);
            g_cursor_vis = ShowCursor(FALSE);
        } else {
            get_window_metrics(&dims);
        }
    } else {
        title = CLONE_TITLE;
        get_window_metrics(&dims);
    }

    init_window(worker, &dims, true, true, title);
}

static int
master_loop(void)
{
    MSG msg;
    BOOL ret;

    while (ret = GetMessage(&msg, nullptr, 0, 0)) {
        if (-1 == ret) {
            saver::util::err_msg(TEXT("Internal Windows error."));
            g_userexit = true;
            break;
        }
        if (SAVER_STANDALONE == g_sm && WM_KEYDOWN == msg.message) {
            switch (msg.wParam) {
            case 'F':
                toggle_fullscreen();
                continue;

            case 'N':
                if (FULLSCREEN_NONE == g_fullscreen)
                    add_window(false);
                continue;

            default:
                break;
            }
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

int
run(void)
{
    WNDCLASS wc;

    /* would also want CS_VREDRAW and CS_HREDRAW for GDI */
    wc.style = CS_OWNDC; /* is this actually a good idea? */
    wc.lpfnWndProc = main_wndproc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = sizeof(saver_t *);
    wc.hInstance = g_hInstance;
    /* could use LoadIcon(nullptr, IDI_APPLICATION) for a generic icon */
    wc.hIcon = LoadIcon(g_hInstance, MAKEINTATOM(ID_APP));
    /* use cursor only in non-saver mode */
    wc.hCursor = SAVER_STANDALONE == g_sm
        ? LoadCursor(nullptr, IDC_ARROW)
        : nullptr;
    /* unnecessary for GL, but prevents empty rectangle when resizing */
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = CLASSNAME;

    if (!RegisterClass(&wc))
        EP_DIE("RegisterClass failed.");

    if (SAVER_STANDALONE == g_sm && (oflag || !bflag))
        saver::util::open_console();

    init_ep();
    add_window(true);
    return master_loop();
}
}