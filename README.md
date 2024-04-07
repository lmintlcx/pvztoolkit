#Plants vs. Zombies Toolkit

PvZ Toolkit is an auxiliary tool for the PC version of Plants vs. Zombies.

## Preview animation

### English

![PvZ Toolkit](https://github.com/shortydoggg/pvztoolkit/raw/master/img/pvztoolkit_en.gif)

## Original download link

PvZ Toolkit official website: [https://pvz.lmintlcx.com/toolkit/](https://pvz.lmintlcx.com/toolkit/)

## Update log

Latest version: 1.20.5 (2024-04-07)

[Click to view CHANGELOG.md](https://github.com/shortydoggg/pvztoolkit/blob/master/CHANGELOG.md)

## Operating platform

PvZ Toolkit is compatible with all major versions of Microsoft Windows.

| Operating system | Version number | Architecture |
| -------------- | --------------- | ----------- |
| Windows Vista | RTM / SP1 / SP2 | x86 / WoW64 |
| **Windows 7** | RTM / SP1 | x86 / WoW64 |
| Windows 8 | RTM | x86 / WoW64 |
| Windows 8.1 | RTM | x86 / WoW64 |
| **Windows 10** | 1507 / ... | x86 / WoW64 |
| Windows 11 | 21H2 / ... | WoW64 |

> On Windows 8 and above, some button texts will be embellished with Emoji emoticons.

## game version

PvZ Toolkit supports [all known official versions of Plants vs. Zombies](https://pvz.lmintlcx.com/download/) on the PC platform.

- English Beta 0.1.1.1014 (en) \*
- English Beta 0.9.9.1029 (en) \*
- English Original 1.0.0.1051 (en)
- English fix 1.2.0.1065 (en)
- Spanish version 1.0.4.7924 (es)
- Spanish version 1.0.7.3556 (es)
- Russian version 1.0.7.3467 (ru)
- Origin English Annual Edition 1.2.0.1073 GOTY (en)
- Origin German Annual Edition 1.2.0.1093 GOTY (de)
- Origin Spanish Year of the Year 1.2.0.1093 GOTY (es)
- Origin French Annual Edition 1.2.0.1093 GOTY (fr)
- Origin Italian Annual Edition 1.2.0.1093 GOTY (it)
- Steam English Version of the Year 1.2.0.1096 GOTY (en)
- Zoo Japanese Annual Edition 1.1.0.1056 GOTY (ja)
- Renren 2010 Viscosity sweat version 1.1.0.1056 GOTY (en)
- Renren Enhanced Version 2012 1.1.0.1056 GOTY (en)
- Renren Enhanced Version 2012 1.1.0.1056 GOTY (en)

> There is only limited functional support for the test version, and the serial number and name of the object in 0.1.1.1014 are not completely corresponding.

> If you find other **official original** that is not supported by PvZ Toolkit, you can contact the author to request to add adaptation.

## Project build

PvZ Toolkit is developed with Visual Studio and depends on FLTK interface library and zlib compression library.

> Compiler for Visual Studio 2019 16.11, install the "Desktop Development with C++" workload.

> Dependencies FLTK 1.4 and zlib 1.2.12 required to build the complete project are already included in the code repository.


### For the English version:

The following operations are performed in the command prompt, and the finished file `pvztoolkit_(English).exe` is located in the `pvztoolkit` directory inside the `eng\out` folder.

```bat
REM clone project

git clone https://github.com/shortydoggg/pvztoolkit.git

REM switch to the project folder

cd pvztoolkit
cd eng

REM starts the Visual Studio 2019 compilation environment

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86

REM adds paths to dependent libraries to environment variables

set INCLUDE=.\fltk\include;%INCLUDE%
set LIB=.\fltk\lib;%LIB%

set INCLUDE=.\zlib\include;%INCLUDE%
set LIB=.\zlib\lib;%LIB%

REM build project

nmake -f makefile.release

REM embed manifest file

mt.exe -nologo -manifest ".\res\ptk.manifest" -outputresource:".\out\pvztoolkit_(English).exe;#1"
```

## Development route

(Based on PvZ Tools) PvZ Toolkit design goals:

- Runs on all major Windows operating systems.
- Support for modifying all known Plants vs. Zombies PC versions.
- The finished product is released as a single-file green version, which is small in size and quick to start.
- The functions are streamlined and practical, filtering out the most commonly used and most useful function sets.
- Manually plan the layout, make full use of the space, and arrange the position of the controls reasonably.
- Support interface zooming under high resolution screen, and can automatically save and restore the zoom ratio.
- The statistics function of the number of monsters, you can check the specific types and numbers of monsters in each wave.
- Optimized the functions of the quick layout mode, supporting the planting of front plant flower pots and water lilies in columns.
- A more accurate game search method, which can update the running status of the game process in time.
- A newly designed formation code format, abandoning the lengthy string format of the web layout tool.
- Simultaneously supports Simplified Chinese for the main interface and English for the bubble box.
- A more comprehensive search method for archive locations, able to open all possible archive folders.

> PvZ Toolkit is the sequel to PvZ Tools, which was born to solve some obvious shortcomings of the previous one.

## Open Source License

The source code of PvZ Toolkit is released under the GPL-3.0 agreement. If you use it, you need to continue to open source and free under the same agreement.

## Acknowledgments list

PvZ Toolkit was originally developed based on the well-known [zhumxiang/PVZ_Helper](https://github.com/zhumxiang/PVZ_Helper) project.

[Lazuplis-Mei](https://github.com/Lazuplis-Mei) / [63enjoy](https://github.com/63enjoy) / [infdust](https://github.com /infdust) et al.
