
#include <cassert>

#include "window.zh.h"
#include "window.en.h"

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
    TCHAR szLangChinese[] = L"简体中文";
    TCHAR szLangEnglish[] = L"English";
    if (((Pt::zh::Fl_Choice_ *)w)->value() == 1)
      ret = RegSetValueExW(hKey, L"Language", 0, REG_SZ, (LPBYTE)&szLangEnglish, sizeof(szLangEnglish));
    else
      ret = RegSetValueExW(hKey, L"Language", 0, REG_SZ, (LPBYTE)&szLangChinese, sizeof(szLangChinese));
    std::cout << ((Pt::zh::Fl_Choice_ *)w)->value() << " " << ret << std::endl;
    RegCloseKey(hKey);
  }
}

void button_callback(Fl_Widget *w, void *data)
{
  ((Fl_Double_Window *)data)->hide();
}

void window_callback(Fl_Widget *, void *)
{
  if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    return; // 无视 Escape
  exit(0);
}

/// main ///

int main(int argc, char **argv)
{
  // 初始化随机数种子
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  // 调试输出中文
#ifdef _DEBUG
  std::wcout.imbue(std::locale("chs"));
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
  Pt::zh::Fl_Choice_ choice(130, 20, 120, 25, "语言(Language): ");
  Fl_Button button(130, 75, 120, 25, "启动(Launch)");
  extern HINSTANCE fl_display;
  launcher.icon((char *)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));
  choice.add("简体中文");
  choice.add("English");
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
    DWORD r = RegQueryValueExW(hKey, L"Language", 0, &dwType, (LPBYTE)&szLang, &dwSize);
    if (r == ERROR_SUCCESS && std::wstring(szLang) == L"English")
      choice.value(1);
    RegCloseKey(hKey);
  }
  else // 没有注册表配置就读系统区域
  {
    first_open = true;
    LANGID lang_id = GetUserDefaultLangID();
    // std::cout << lang_id << std::endl;
    if (lang_id != 2052 && lang_id != 1028) // 非中文
      choice.value(1);
  }

  if (first_open)
  {
    choice.do_callback();
    launcher.set_modal();
    launcher.show();
    while (launcher.shown())
      Fl::wait();
  }

  Pt::en::Window window_en(450 + 50 * 4, 270, "PvZ Toolkit");
  Pt::zh::Window window_zh(450, 270, "植物大战僵尸辅助工具");
  window_en.callback(window_callback);
  window_zh.callback(window_callback);
  std::wcout << choice.value() << std::endl;
  if (choice.value() == 1)
  {
    window_en.show(argc, argv);
    window_en.pvz->FindPvZ();
  }
  else
  {
    window_zh.show(argc, argv);
    window_zh.pvz->FindPvZ();
  }

  int ret = Fl::run();

  // 结束主循环后再释放
  ReleaseMutex(m);
  CloseHandle(m);

  return ret;
}
