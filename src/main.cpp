
#include <Windows.h>

#include <shellapi.h>
#include <shlwapi.h>

#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
#include <string>

#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/x.H>

#include "../inc/toolkit.h"
#include "../inc/utils.h"

#define IDI_ICON 1001

// 要求编译器支持 C++17
static_assert(_MSC_VER >= 1916);

// 编译器目标平台限制为 x86
// 因为目标应用 (植物大战僵尸1 PC版) 本身是 x86 的
// 修改器也不需要 x64 的任何优势, 反而增加体积
// 以及 Visual Studio 不支持 x64 内联汇编
static_assert(sizeof(void *) == 4);

void window_callback(Fl_Widget *w, void *)
{
    // 按 Esc 不退出, 而是还原默认窗口大小
    if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    {
        if (Fl::screen_scale(((Fl_Window *)w)->screen_num()) != ((Pt::Window *)w)->MinScale())
            Fl::screen_scale(((Fl_Window *)w)->screen_num(), ((Pt::Window *)w)->MinScale());
        return;
    }

    ((Pt::Toolkit *)w)->close_all_sub_window();
    ((Pt::Toolkit *)w)->hide();
}

void callback_pvz_check(void *w)
{
    // 定期检查游戏进程状态
    bool on = ((Pt::Toolkit *)w)->pvz->GameOn();
    double t = on ? 0.4 : 0.2;
    Fl::repeat_timeout(t, callback_pvz_check, w);

    if (IsDebuggerPresent())
        exit(-42);
}

/// main ///

Fl_Font ui_font = FL_FREE_FONT + 1; // 界面中文
Fl_Font ms_font = FL_FREE_FONT + 2; // 等宽英文

int main(int argc, char **argv)
{
#ifdef _DEBUG
    system("chcp 65001"); // 调试输出中文
#endif

#ifdef _DEBUG
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
#endif

    if (argc == 0)
        return -0;

    if (argc == 4)
    {
        std::string m = argv[1];
        std::string file = argv[2];
        std::string dir = argv[3];

        Pt::PAK pak;
        if (m == "/U")
            return pak.Unpack(file, dir);
        else if (m == "/P")
            return pak.Pack(dir, file);
        else
            return 0xF7;
    }

    // 界面背景颜色
    Fl::background(243, 243, 243);

    // 界面字体
#if _WIN32_WINNT >= _WIN32_WINNT_VISTA
    Fl::set_font(ui_font, "Microsoft YaHei");
    Fl::set_font(ms_font, "Consolas");
#else
    TCHAR fontsPath[MAX_PATH];
    SHGetSpecialFolderPathW(NULL, fontsPath, CSIDL_FONTS, FALSE);
    std::wstring fonts_path = fontsPath;
    if (PathFileExistsW((fonts_path + L"\\msyh.ttc").c_str()) == TRUE || //
        PathFileExistsW((fonts_path + L"\\msyh.ttf").c_str()) == TRUE)
        Fl::set_font(ui_font, "Microsoft YaHei");
    else
        Fl::set_font(ui_font, "SimSun");
    if (PathFileExistsW((fonts_path + L"\\consola.ttf").c_str()) == TRUE)
        Fl::set_font(ms_font, "Consolas");
    else
        Fl::set_font(ms_font, "Courier New");
#endif

    // 设置对话框属性
#ifdef _PTK_CHINESE_UI
    fl_message_font(ui_font, 13);
#else
    fl_message_font(ms_font, 13);
#endif
    fl_message_hotspot(1);

#ifdef _PTK_CHINESE_UI
    fl_cancel = "取消";
    fl_close = "关闭";
    fl_no = "否";
    fl_ok = "好的";
    fl_yes = "是";
    Fl_Input::copy_menu_text = "复制";
    Fl_Input::cut_menu_text = "剪切";
    Fl_Input::paste_menu_text = "粘贴";
#endif

    // 设置工具提示的样式
    Fl_Tooltip::delay(0.1f);
    Fl_Tooltip::hoverdelay(0.1f);
    Fl_Tooltip::hidedelay(5.0f);
    Fl_Tooltip::color(FL_WHITE);
    Fl_Tooltip::textcolor(FL_BLACK);
    Fl_Tooltip::font(ui_font);
    Fl_Tooltip::size(12);
    Fl_Tooltip::margin_width(5);
    Fl_Tooltip::margin_height(5);
    Fl_Tooltip::wrap_width(400);

    // 初始化随机数种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 第一次调用时启用线程锁机制
    Fl::lock();

    // 启动画面

    bool show_splash = true;
    double dt = 1.2f; // 最短显示时间

    Fl_Window splash(400 + 2, 225 + 2, "");
    splash.begin();
    Fl_Box box(1, 1, 400, 225, nullptr);
    splash.end();

    splash.color(FL_GREEN);
    splash.border(false);
    splash.set_non_modal();

    Fl_JPEG_Image img_jpeg("splash.jpg");
    Fl_PNG_Image img_png("splash.png");
    Fl_BMP_Image img_bmp("splash.bmp");

    if (img_jpeg.fail() == 0)
        box.image(img_jpeg);
    else if (img_png.fail() == 0)
    {
        box.image(img_png);
        if (Pt::VerifyFileHash(L"splash.png", "8dd46f92e0fa175513278ff208147fbf"))
            dt = 0.3f;
    }
    else if (img_bmp.fail() == 0)
        box.image(img_bmp);
    else
        show_splash = false;

    if (box.image())
    {
        int w = box.image()->w();
        int h = box.image()->h();
        box.size(w, h);
        splash.size(w + 2, h + 2);
    }

    if (show_splash)
    {
        splash.position((Fl::w() - splash.w()) / 2, (Fl::h() - splash.h()) / 2);
        splash.show();
        splash.wait_for_expose();
    }

    clock_t start = clock(); // 开始计时

    // 系统需求
    // 针对 Windows 2000 和 XP 的编译版本做了一些特殊改动
    // 在高版本系统上为了避免可能存在的问题, 直接拒绝运行
#if _WIN32_WINNT < _WIN32_WINNT_VISTA
    if (IsWindowsVistaOrGreater())
    {
        fl_message_title("PvZ Toolkit");
#ifdef _PTK_CHINESE_UI
        fl_alert("正在使用的操作系统不受支持！\n"
                 "需要 Windows 2000 或者 XP 才能运行。");
#else
        fl_alert("This operating system is not supported!\n"
                 "Windows 2000 or XP is required to run.");
#endif
        return -10;
    }
#endif

    // 防篡改检测
    // This feature is designed for the original author lmintlcx.
    // If you want to make a customized version, delete this code.
#ifdef _PTK_SIGNATURE_CHECK
    wchar_t exePath[MAX_PATH] = {0};
    GetModuleFileNameW(NULL, exePath, MAX_PATH);
    if (!Pt::VerifySignature(exePath, "\x21\x13\x67\x0f\x3b\x6c\x60\xaf\x42\x50\x7f\x07\xd3\x97\xbc\xd6"))
    {
#ifdef _PTK_CHINESE_UI
        fl_message_title("PvZ Toolkit 防篡改检测");
        if (fl_choice("本程序可能已经感染病毒，请在官方渠道重新下载！", //
#else
        fl_message_title("PvZ Toolkit Tamper-proof Detection");
        if (fl_choice("This program may have been infected with a virus, \n"
                      "please download it again from the official website!", //
#endif
                      "No", "Yes", 0) == 1)
            ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", //
                          nullptr, nullptr, SW_SHOWNORMAL);
        return -1;
    }
#endif

    // 只运行单个实例
    HANDLE m = CreateMutexW(nullptr, true, L"PvZ Toolkit");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return -2;

#ifdef _DEBUG
    std::wcout << L"启动用时(毫秒): " << (clock() - start) << std::endl;
#endif

    // 隐藏启动画面
    if (show_splash)
    {
        while ((clock() - start) / (double)CLOCKS_PER_SEC < dt)
            Fl::check();
        splash.hide();
        Fl::check();
    }

    // 显示主窗口

    Pt::Toolkit pvztoolkit(0, 0, "");
    pvztoolkit.callback(window_callback);

    pvztoolkit.show(1, argv); // argc -> 1
    pvztoolkit.wait_for_expose();
    pvztoolkit.pvz->FindPvZ();
    SetForegroundWindow(fl_xid(&pvztoolkit));

    // 标题栏图标
    HICON hIcon = LoadIconW(fl_display, MAKEINTRESOURCEW(IDI_ICON));
    SendMessageW(fl_xid(&pvztoolkit), WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SendMessageW(fl_xid(&pvztoolkit), WM_SETICON, ICON_BIG, (LPARAM)hIcon);

#ifdef _DEBUG
    // 避免调试的时候频繁输出
#else
    Fl::add_timeout(0.01, callback_pvz_check, &pvztoolkit);
#endif

    int ret = Fl::run();

    // 结束主循环后再释放
    ReleaseMutex(m);
    CloseHandle(m);

    return ret;
}
