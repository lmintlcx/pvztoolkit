
#include <cassert>

#include "window.h"

#include <Windows.h>
#include <ShellAPI.h>

#if _MSC_VER >= 1910
static_assert(sizeof(void *) == 4);
#endif

void window_callback(Fl_Widget *, void *)
{
  if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    return; // 无视 Escape
  exit(0);
}

int main(int argc, char **argv)
{
  // 初始化随机数种子
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  // 输出中文
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

  Pt::Window window(450, 270, "PvZ Toolkit");
  window.callback(window_callback);

  Fl::lock(); // 第一次调用时启用线程锁机制
  window.show(argc, argv);

  int ret = Fl::run();

  // 结束主循环后再释放
  ReleaseMutex(m);
  CloseHandle(m);

  return ret;
}
