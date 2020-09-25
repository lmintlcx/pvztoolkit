
@echo off
chcp 65001

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" ^
x86 10.0.10240.0

set PATH=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%
set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%

cd /d %~dp0

set INCLUDE=.\fltk\include;.\zlib\include;%INCLUDE%
set LIB=.\fltk\lib;.\zlib\lib;%LIB%

REM set MAKE_TOOL=nmake
set PATH=.\jom;%PATH%
set MAKE_TOOL=jom

if exist .\out\pvztoolkitd.exe del .\out\pvztoolkitd.exe
if exist .\out\pvztoolkit.exe del .\out\pvztoolkit.exe
REM if exist .\out rmdir /s /q .\out

%MAKE_TOOL% -f makefile.debug

REM %MAKE_TOOL% -f makefile.release
REM .\upx\upx.exe --lzma --ultra-brute .\out\pvztoolkit.exe
