
#include <cassert>
#include <codecvt>

#include "window.h"

#include <Windows.h>
#include <ShellAPI.h>

static_assert(_MSC_VER >= 1916);
static_assert(sizeof(void *) == 4);

void window_callback(Fl_Widget *w, void *)
{
    // 按 Esc 不退出, 而是还原默认窗口大小
    if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    {
        if (Fl::screen_scale(((Fl_Double_Window *)w)->screen_num()) != 1.0f)
            Fl::screen_scale(((Fl_Double_Window *)w)->screen_num(), 1.0f);
        return;
    }

    if (((Pt::Window *)w)->window_spawn->shown() == 1)
        ((Pt::Window *)w)->window_spawn->hide();
    ((Pt::Window *)w)->hide();
}

void callback_pvz_check(void *w)
{
    // 定期检查游戏进程状态
    bool on = ((Pt::Window *)w)->pvz->GameOn();
    double t = on ? 0.4 : 0.2;
    Fl::repeat_timeout(t, callback_pvz_check, w);
}

/// main ///

int main(int argc, char **argv)
{
    // 初始化随机数种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

#ifdef _DEBUG
    // 调试输出中文
    // 我也不知道为什么加这些就有用
    // It just works!
    system("chcp 65001");
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
    std::wcout.imbue(loc);
#endif

    // 测试版在 2022-03-29 之后失效
    bool beta_version = false;
    if (beta_version && (std::time(nullptr) > std::time_t(1648569599)))
    {
        if (MessageBoxW(nullptr, L"这是很久以前的测试版哦, 现在去下载新的正式版吗?", //
                        L"提示", MB_OKCANCEL) == IDOK)
            ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", //
                          nullptr, nullptr, SW_SHOWNORMAL);
        return -1;
    }

    // 只运行单个实例
    HANDLE m = CreateMutexW(nullptr, true, L"PvZ Toolkit");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return -1;

    // 第一次调用时启用线程锁机制
    Fl::lock();

    // 主窗口
    Pt::Window window(0, 0, "");
    window.callback(window_callback);
    window.show(argc, argv);
    window.pvz->FindPvZ();

#ifndef _DEBUG // 避免调试的时候频繁输出
    Fl::add_timeout(0.01, callback_pvz_check, &window);
#endif

    int ret = Fl::run();

    // 结束主循环后再释放
    ReleaseMutex(m);
    CloseHandle(m);

    return ret;
}
