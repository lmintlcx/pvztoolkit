
@echo off
chcp 65001

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86

set PATH=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%
set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%

REM cd /d %~dp0
cd /d D:\work\pvz\pvztoolkit

set INCLUDE=.\fltk\include;.\zlib\include;%INCLUDE%
set LIB=.\fltk\lib;.\zlib\lib;%LIB%

REM set MAKE_TOOL=nmake
set PATH=.\jom;%PATH%
set MAKE_TOOL=jom

REM %MAKE_TOOL% -f makefile.debug clean
%MAKE_TOOL% -f makefile.debug

REM %MAKE_TOOL% -f makefile.release clean
REM %MAKE_TOOL% -f makefile.release
REM .\upx\upx.exe --lzma --ultra-brute .\out\pvztoolkit.exe
