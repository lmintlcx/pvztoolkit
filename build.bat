
@echo off
chcp 65001

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" ^
x86 10.0.10240.0

set PATH=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%
set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%

cd /d %~dp0

set INCLUDE=.\fltk\include;%INCLUDE%
set LIB=.\fltk\lib;%LIB%

set PATH=.\jom;%PATH%

if exist .\out\pvztoolkit.exe del .\out\pvztoolkit.exe
REM if exist .\out rmdir /s /q .\out

REM set MAKE_TOOL=nmake
set MAKE_TOOL=jom

REM REM debug
%MAKE_TOOL% -f makefile.debug

REM REM release
REM %MAKE_TOOL% -f makefile.release
REM mt.exe -manifest ".\src\dpi.manifest" -outputresource:".\out\pvztoolkit.exe;1"
REM .\upx\upx.exe --lzma --ultra-brute .\out\pvztoolkit.exe
