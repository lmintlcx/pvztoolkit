
echo off
chcp 65001

REM 本文件仅用于作者开发和打包 pvztoolkit
REM 内部使用, 不要在不明白代码作用的情况下随便运行

set PZTK=D:\repo\pvztoolkit
set FLTK=C:\Dev\fltk_1.4.0\msvc2017_x86\static

set JOM=C:\Tools\jom_1_1_4\jom.exe

if not exist %PZTK% exit
if not exist %FLTK% exit

cd /d %PZTK%

call "C:\VisualStudio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x86

set INCLUDE=%FLTK%\include;%INCLUDE%
set LIB=%FLTK%\lib;%LIB%

if exist .\build\pvztoolkitd.exe del .\build\pvztoolkitd.exe

if exist %JOM% (
    %JOM% -f tools/debug.makefile
) else (
    nmake -f tools/debug.makefile
)

if not exist .\build\pvztoolkitd.exe goto :end

mt.exe -nologo ^
-manifest ".\res\pvztoolkit.manifest" ^
-outputresource:".\build\pvztoolkitd.exe;#1"

signtool.exe sign /v ^
/fd sha1 ^
/f "D:\notes\cert\lmintlcx_r4.pfx" ^
/p "Rm9yIFppb24h" ^
.\build\pvztoolkitd.exe

goto :end rem release

nmake -f tools/release.makefile clean
nmake -f tools/release.makefile

REM nmake -f tools/release.nt5.makefile
REM Set-ExecutionPolicy -ExecutionPolicy RemoteSigned
REM start powershell .\nt5\patch_exe.ps1 .\build\pvztoolkit.exe

if not exist .\build\pvztoolkit.exe goto :end

mt.exe -nologo ^
-manifest ".\res\pvztoolkit.manifest" ^
-outputresource:".\build\pvztoolkit.exe;#1"

signtool.exe sign /v ^
/fd sha1 ^
/f "D:\notes\cert\lmintlcx_r4.pfx" ^
/p "Rm9yIFppb24h" ^
.\build\pvztoolkit.exe

signtool.exe sign /v ^
/as /fd sha256 ^
/f "D:\notes\cert\lmintlcx_r4.pfx" ^
/p "Rm9yIFppb24h" ^
.\build\pvztoolkit.exe

goto :end

file="PvZ_Toolkit_v1.xx.x.exe"
rm -f $file.hash
echo $file >> $file.hash
echo "MD5" >> $file.hash
md5sum $file | cut -d" " -f1 | tr [a-z] [A-Z] >> $file.hash
echo "SHA-1" >> $file.hash
sha1sum $file | cut -d" " -f1 | tr [a-z] [A-Z] >> $file.hash
echo "SHA-256" >> $file.hash
sha256sum $file | cut -d" " -f1 | tr [a-z] [A-Z] >> $file.hash
echo "SHA-512" >> $file.hash
sha512sum $file | cut -d" " -f1 | tr [a-z] [A-Z] >> $file.hash

gpg --armor --detach-sign $file
gpg --verify $file.asc $file

:end

if not exist .\build\splash.png copy misc\splash.png .\build
if not exist .\build\setups.yml copy misc\setups.yml .\build

exit

set WinRAR="C:\Program Files\WinRAR\WinRAR.exe"
%WinRAR% a -afrar -m5 -ma4 -r -rr1% -s XXXX.rar "XXXX"
%WinRAR% a -afzip -m5      -r          XXXX.zip "XXXX"
