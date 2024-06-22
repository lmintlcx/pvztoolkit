**简体中文 | [English](./README.English.md)**

# PvZ Toolkit

植物大战僵尸一代电脑版辅助工具

## 界面截图

![PvZ Toolkit](https://github.com/lmintlcx/pvztoolkit/raw/master/docs/pvztoolkit_zh.gif)

> For non-Chinese users, English tooltips will be displayed with mouse hovers.

## 下载链接

官方网站: [https://pvz.lmintlcx.com/toolkit/](https://pvz.lmintlcx.com/toolkit/)

GitHub Releases: [https://github.com/lmintlcx/pvztoolkit/releases](https://github.com/lmintlcx/pvztoolkit/releases)

## 更新日志

最新版本: 1.22.0 (2024-06-22)

[点击查看 CHANGELOG.md](https://github.com/lmintlcx/pvztoolkit/blob/master/CHANGELOG.md)

## 运行平台

PvZ Toolkit 兼容微软 Windows 系统的所有主流版本.

| 操作系统       | 版本号            | 架构        |
| -------------- | ----------------- | ----------- |
| Windows 2000   | RTM / ... / SP4   | x86         |
| Windows XP     | RTM / ... / SP3   | x86         |
| Windows Vista  | RTM / SP1 / SP2   | x86 / WoW64 |
| **Windows 7**  | RTM / SP1         | x86 / WoW64 |
| Windows 8      | RTM               | x86 / WoW64 |
| Windows 8.1    | RTM               | x86 / WoW64 |
| **Windows 10** | 1507 / ... / 22H2 | x86 / WoW64 |
| **Windows 11** | 21H2 / ...        | WoW64       |

> 在 Windows 8 以及更高版本的系统上, 部分按钮文字会使用 Emoji 表情符号点缀.

## 游戏版本

PvZ Toolkit 支持 PC 平台上的 [植物大战僵尸一代所有已知官方版本](https://pvz.lmintlcx.com/download/).

- 英语测试版 0.1.1.1014 (en) \*
- 英语测试版 0.9.9.1029 (en) \*
- 英语原始版 1.0.0.1051 (en)
- 英语修复版 1.2.0.1065 (en)
- 西班牙语版 1.0.4.7924 (es)
- 西班牙语版 1.0.7.3556 (es)
- 俄罗斯语版 1.0.7.3467 (ru)
- Origin 英语年度版 1.2.0.1073 GOTY (en)
- Origin 德语年度版 1.2.0.1093 GOTY (de)
- Origin 西班牙语年度版 1.2.0.1093 GOTY (es)
- Origin 法语年度版 1.2.0.1093 GOTY (fr)
- Origin 意大利语年度版 1.2.0.1093 GOTY (it)
- Steam 英语年度版 1.2.0.1096 GOTY (en)
- Zoo 日语年度版 1.1.0.1056 GOTY (ja)
- 人人网 2010 粘度汗化版 1.1.0.1056 GOTY (zh) (2010/08/02)
- 人人网 2012 年度加强版 1.1.0.1056 GOTY (zh) (2012/06/05)
- 人人网 2012 年度加强版 1.1.0.1056 GOTY (zh) (2012/07/17)

> 泄露的测试版本内存布局与正式版本差别较大, PvZ Toolkit 对其仅提供有限功能支持.

> 如果有新发现的 PvZ Toolkit 不支持的其他 **官方原版**, 可以要求作者添加适配.

## 代码结构

| 文件/目录名    | 用途说明         |
| -------------- | ---------------- |
| deps           | 项目依赖的开发库 |
| docs           | 文档图片和教程   |
| inc            | 项目头文件       |
| misc           | 发行附带的文件   |
| nt5            | 旧版系统兼容组件 |
| res            | 程序内嵌的资源   |
| src            | 项目源代码文件   |
| tools          | 调试发布用的脚本 |
| CHANGELOG.md   | 更新日志         |
| CMakeLists.txt | 项目文件         |
| LICENSE        | 开源许可协议     |
| README.md      | 自述说明文件     |

## 项目构建

PvZ Toolkit 使用 Visual C++ 开发, 依赖于 FLTK 界面库和 zlib 压缩库.

> 需求的语言标准 >= C++17, Visual Studio >= 2017 15.9, CMake >= 3.15.

> 依赖库 FLTK + zlib 编译步骤参考: [build_fltk_zlib.md](https://github.com/lmintlcx/pvztoolkit/blob/master/deps/build_fltk_zlib.md)

```bat

REM 获取项目源代码

git clone https://github.com/lmintlcx/pvztoolkit

REM 切换到项目文件夹

cd pvztoolkit

REM 创建并切换到临时文件夹

mkdir build && cd build

REM 启动编译环境 (请按实际情况修改编译器安装目录)

call "C:\VisualStudio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x86

REM 配置项目 (请按实际情况修改构建类型和依赖库路径)

cmake ^
-G "NMake Makefiles" ^
-D CMAKE_BUILD_TYPE=MinSizeRel ^
-D FLTK_DIR="C:\Dev\fltk_1.4.0\msvc2017_x86\static\CMake" ^
-S ..

REM 编译项目

cmake --build .

REM 成品文件 pvztoolkit.exe 位于 build 文件夹内

```

条件编译开关:
`_PVZ_BETA_LEAK_SUPPORT` 支持泄露的测试版
`_PTK_CHINESE_UI` 中文语言界面

## 开发路线

> PvZ Toolkit 是 PvZ Tools 的续作, 是为了解决前作的一些明显的缺点而诞生的.

旧作 PvZ Tools 存在的问题:

- 界面库 Qt 更新激进, 仅支持较新的系统.
- 发布文件过于臃肿, 启动速度非常地慢.
- 网格布局在英文下拉长后显得非常丑陋.
- 控件之间空隙过大, 空间利用率低.
- 界面逻辑和对象通信代码占比太高.
- 业务代码不方便拓展成多版本支持.
- 盲目选取堆砌没有实用价值的功能.
- 网页布阵器的字符串真的是太长了.

新作 PvZ Toolkit 的设计目标:

- 能在所有主流的 Windows 操作系统上运行.
- 支持修改所有已知的植物大战僵尸一代电脑版.
- 成品发布为单文件绿色版, 体积小巧, 启动快速.
- 功能精简实用, 筛选出最常用的和最有用的功能集.
- 手动规划布局, 充分利用空间, 合理排布控件的位置.
- 支持高分屏下的界面缩放, 可以自动保存恢复缩放比例.
- 出怪数量统计功能, 可以查看具体每波的出怪种类和数量.
- 快捷布阵模式功能优化, 支持按列种植前置植物花盆和睡莲.
- 更加准确的游戏查找方法, 能够及时更新游戏进程的运行状态.
- 全新设计的阵型代码格式, 抛弃网页布阵器的冗长的字符串格式.
- 同时支持显示主界面的 简体中文 和冒泡框的 English 两种语言.
- 更加全面的存档位置查找方法, 能够打开所有可能存在的存档文件夹.

> 阵型代码编码格式开发者文档: [rfc1437.txt](https://github.com/lmintlcx/pvztoolkit/blob/master/docs/rfc1437.txt)

## 已知问题

PvZ Toolkit 目前仍然存在的问题:

- 界面库 FLTK 样式丑陋, 没有针对视障人群的可访问性支持.
- 修改功能的实现照搬已有的旧修改器, 留有一些 bug 未修复.

## 许可协议

PvZ Toolkit 的源代码采用 GPL-3.0 协议发布, 如若使用需要以相同的协议继续开源免费.

## 鸣谢名单

PvZ Toolkit 最初基于知名的 [zhumxiang/PVZ_Helper](https://github.com/zhumxiang/PVZ_Helper) 项目而开发.

编写过程中得到了 [Lazuplis-Mei](https://github.com/Lazuplis-Mei) / [63enjoy](https://github.com/63enjoy) / [infdust](https://github.com/infdust) 等人的帮助.
