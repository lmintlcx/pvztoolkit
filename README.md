
# Plants vs. Zombies Toolkit

PvZ Toolkit 是一个适用于植物大战僵尸一代电脑版的辅助工具.

## 预览动图

![PvZ Toolkit](https://github.com/lmintlcx/pvztoolkit/raw/master/img/pvztoolkit.gif)

> 对于非中文用户, 鼠标悬停在控件上的时候会显示英文提示信息.

## 下载链接

[PvZ Toolkit 官方网站](https://pvz.lmintlcx.com/toolkit/)

最近更新: 1.12.0 (2021-10-20)

## 运行平台

PvZ Toolkit 能在所有主流 Windows 系统上正常运行.

| 操作系统       | 版本号          | 架构      |
| -------------- | --------------- | --------- |
| Windows XP \*  | SP3             | x86       |
| Windows Vista  | RTM / SP1 / SP2 | x86 / x64 |
| Windows 7      | RTM / SP1       | x86 / x64 |
| **Windows 8**  | RTM / 8.1       | x86 / x64 |
| **Windows 10** | 1507 / ...      | x86 / x64 |
| **Windows 11** | 21H2 / ...      | x64       |

> 对于 XP 系统建议安装微软雅黑字体以获得完整的视觉体验.

## 游戏版本

PvZ Toolkit 支持 [PC 平台上所有已知的游戏版本](https://pvz.lmintlcx.com/download/).

- 英语测试版 0.1.1.1014 (en)
- 英语测试版 0.9.9.1029 (en)
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
- 人人网 2010 粘度汗化版 1.1.0.1056 GOTY (zh)
- 人人网 2012 年度加强版 1.1.0.1056 GOTY (zh)
- 人人网 2012 年度加强版 1.1.0.1056 GOTY (zh)

> 如果你发现有不能使用的其他**官方版本**, 可以联系作者要求添加支持.

## 项目构建

PvZ Toolkit 使用 Visual Studio 编译, 依赖于 FLTK 界面库和 zlib 压缩库.

> 为了支持 XP 系统最高只能使用 Visual Studio 2017 和 Windows 7.1A SDK.

> 构建完整项目需要的依赖库 FLTK 1.4 和 zlib 1.2.11 已包含在代码仓库中.

## 更新日志

[点击查看 CHANGELOG.md](https://github.com/lmintlcx/pvztoolkit/blob/master/CHANGELOG.md)

> 目前暂时没有 2.0 大版本的开发计划.

## 开发路线

(在 PvZ Tools 的基础上) PvZ Toolkit 的设计目标:

- 支持在所有主流的 Windows 操作系统上运行.
- 支持修改所有已知的植物大战僵尸一代电脑版.
- 成品发布为单文件绿色版, 体积小巧, 启动快速.
- 功能精简实用, 筛选出最常用的和最有用的功能集.
- 手动布局充分利用空间, 合理规划排布控件的位置.
- 支持高分屏下的 DPI 缩放, 可自动保存恢复缩放比例.
- 更加准确的游戏查找方法, 能够及时更新游戏进程的运行状态.
- 同时支持 "简体中文" 和冒泡框显示的 "English" 两种界面语言.
- 出怪数量统计功能, 可以查看具体每波的出怪种类和数量.
- 快捷布阵模式功能优化, 支持按列种植前置植物花盆和睡莲.
- 全新设计的阵型代码格式, 抛弃网页布阵器的冗长的字符串格式.
- 更加全面的存档位置查找方法, 能够打开所有可能存在的存档文件夹.

> PvZ Toolkit 是 PvZ Tools 的续作, 是为了解决前作的一些明显的缺点而诞生的.

## 开源许可

PvZ Toolkit 的代码采用 GPL-3.0 协议发布, 如若使用需要以相同的协议继续开源免费.

## 鸣谢名单

PvZ Toolkit 基于 [zhumxiang/PVZ_Helper](https://github.com/zhumxiang/PVZ_Helper) 开发, 得到了 [Lazuplis-Mei](https://github.com/Lazuplis-Mei) / [63enjoy](https://github.com/63enjoy) / [infdust](https://github.com/infdust) 等人的帮助.
