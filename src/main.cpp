
#include <cassert>

#include "window.h"

#include <Windows.h>
#include <ShellAPI.h>

#define IDI_ICON 1001

#if _MSC_VER >= 1910
static_assert(sizeof(void *) == 4);
#endif

void choice_callback(Fl_Widget *w, void *)
{
    HKEY hKey;
    DWORD ret;
    ret = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                        0, KEY_SET_VALUE, &hKey);
    if (ret != ERROR_SUCCESS)
        ret = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                              0, nullptr, 0, KEY_SET_VALUE, nullptr, &hKey, nullptr);
    if (ret == ERROR_SUCCESS)
    {
        TCHAR szLangEnglish[] = L"English";
        TCHAR szLangChinese[] = L"简体中文";
        if (((Pt::Fl_Choice_ *)w)->value() == 1)
            ret = RegSetValueExW(hKey, L"Language", 0, REG_SZ, (LPBYTE)&szLangChinese, sizeof(szLangChinese));
        else
            ret = RegSetValueExW(hKey, L"Language", 0, REG_SZ, (LPBYTE)&szLangEnglish, sizeof(szLangEnglish));
        std::cout << ((Pt::Fl_Choice_ *)w)->value() << " " << ret << std::endl;
        RegCloseKey(hKey);
    }
}

void button_callback(Fl_Widget *, void *data)
{
    ((Fl_Double_Window *)data)->hide();
}

void window_callback(Fl_Widget *w, void *)
{
    HKEY hKey;
    DWORD ret;
    ret = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                        0, KEY_SET_VALUE, &hKey);
    if (ret != ERROR_SUCCESS)
        ret = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                              0, nullptr, 0, KEY_SET_VALUE, nullptr, &hKey, nullptr);
    if (ret == ERROR_SUCCESS)
    {
        float scale = Fl::screen_scale(((Fl_Double_Window *)w)->screen_num());
        if (scale > 0.9f && scale < 1.1f)
            scale = 1.0;
        if (scale > 1.7f && scale < 2.4f)
            scale = 2.0;
        ret = RegSetValueExW(hKey, L"ScaleFactor", 0, REG_DWORD, (LPBYTE)&scale, sizeof(scale));
        RegCloseKey(hKey);
    }

    // 按 Esc 不退出, 而是还原默认窗口大小
    if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    {
        if (Fl::screen_scale(((Fl_Double_Window *)w)->screen_num()) != 1.0f)
            Fl::screen_scale(((Fl_Double_Window *)w)->screen_num(), 1.0f);
        return;
    }
    exit(0);
}

void callback_pvz_check(void *w)
{
    // 定期检查游戏进程状态
    bool on = ((Pt::Window *)w)->pvz->GameOn();
    double t = on ? 2.0 : 0.5;
    Fl::repeat_timeout(t, callback_pvz_check, w);
}

/// main ///

int main(int argc, char **argv)
{
    // 初始化随机数种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 调试输出中文
#ifdef _DEBUG
    std::wcout.imbue(std::locale("chs"));
    system("chcp 65001");
#endif

    // 测试版在 2020-12-31 之后失效
    if (false && (std::time(nullptr) > std::time_t(1609430399)))
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

    Fl_Window launcher(280, 115, "选择界面语言");
    Pt::Fl_Choice_ choice(130, 20, 120, 25, "语言 (Language): ");
    Fl_Button button(130, 75, 120, 25, "启动 (Launch)");
    extern HINSTANCE fl_display;
    launcher.icon((char *)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));
    choice.add("English");
    choice.add("简体中文");
    choice.value(0);
    choice.callback(choice_callback);
    button.callback(button_callback, (void *)&launcher);

    bool first_open;
    HKEY hKey;
    DWORD r = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                            0, KEY_QUERY_VALUE, &hKey);
    if (r == ERROR_SUCCESS)
    {
        first_open = false;
        DWORD dwType = REG_SZ;
        TCHAR szLang[260];
        DWORD dwSize = 260;
        LSTATUS r = RegQueryValueExW(hKey, L"Language", 0, &dwType, (LPBYTE)&szLang, &dwSize);
        if (r == ERROR_SUCCESS && std::wstring(szLang) == L"简体中文")
            choice.value(1);
        else
            choice.value(0);
        RegCloseKey(hKey);
    }
    else // 没有注册表配置就读系统区域
    {
        first_open = true;
        LANGID lang_id = GetUserDefaultLangID();
        // std::cout << lang_id << std::endl;
        if (lang_id == 2052 || lang_id == 1028) // 中文
            choice.value(1);
        else
            choice.value(0);
    }

    if (first_open)
    {
        choice.do_callback();
        launcher.set_modal();
        launcher.show();
        while (launcher.shown())
            Fl::wait();
    }

    std::wcout << choice.value() << std::endl;
    if (choice.value() == 1)
        Pt::LANG = Pt::Language::Chinese;
    else
        Pt::LANG = Pt::Language::English;

    Pt::Window window(0, 0, "");
    window.callback(window_callback);
    window.show(argc, argv);
    window.pvz->FindPvZ();
#ifndef _DEBUG // 调试的时候不要频繁输出
    Fl::add_timeout(0.01, callback_pvz_check, &window);
#endif

    // 读取保存的缩放比例
    {
        HKEY hKey;
        DWORD r = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                                0, KEY_QUERY_VALUE, &hKey);
        if (r == ERROR_SUCCESS)
        {
            DWORD dwType = REG_DWORD;
            DWORD scale;
            DWORD dwSize = sizeof(DWORD);
            LSTATUS r = RegQueryValueExW(hKey, L"ScaleFactor", 0, &dwType, (LPBYTE)&scale, &dwSize);
            RegCloseKey(hKey);
            if (r == ERROR_SUCCESS)
            {
                float factor = *(float *)(&scale);
                std::cout << "ScaleFactor: " << factor << std::endl;
                if (factor != 1.0f)
                    Fl::screen_scale(window.screen_num(), factor);
            }
        }
    }

    int ret = Fl::run();

    // 结束主循环后再释放
    ReleaseMutex(m);
    CloseHandle(m);

    return ret;
}
