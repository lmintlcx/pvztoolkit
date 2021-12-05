
@echo off
chcp 65001

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 -vcvars_ver=14.16

set PATH=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%
set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%

cd /d D:\repo\pvztoolkit

set INCLUDE=.\fltk\include;.\zlib\include;%INCLUDE%
set LIB=.\fltk\lib;.\zlib\lib;%LIB%

set INCLUDE=.\json;%INCLUDE%

set PATH=.\jom;%PATH%
set MAKE_TOOL=jom

%MAKE_TOOL% -f makefile.debug clean
%MAKE_TOOL% -f makefile.debug

mt.exe -nologo ^
-manifest ".\pvztoolkit.exe.manifest" ^
-outputresource:".\out\pvztoolkitd.exe;#1"

signtool.exe sign /v ^
/fd sha1 ^
/f "D:\notes\cert\lmintlcx_r4.pfx" ^
/p "Rm9yIFppb24h" ^
.\out\pvztoolkitd.exe

goto :end

set MAKE_TOOL=nmake

%MAKE_TOOL% -f makefile.release clean
%MAKE_TOOL% -f makefile.release

mt.exe -nologo ^
-manifest ".\pvztoolkit.exe.manifest" ^
-outputresource:".\out\pvztoolkit.exe;#1"

.\upx\upx.exe --lzma --ultra-brute .\out\pvztoolkit.exe

set PATH=C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x86\;%PATH%

signtool.exe sign /v ^
/fd sha1 ^
/f "D:\notes\cert\lmintlcx_r4.pfx" ^
/p "Rm9yIFppb24h" ^
/t "http://timestamp.digicert.com" ^
.\out\pvztoolkit.exe

signtool.exe sign /v ^
/as /fd sha256 ^
/f "D:\notes\cert\lmintlcx_r4.pfx" ^
/p "Rm9yIFppb24h" ^
/tr "http://timestamp.digicert.com" ^
.\out\pvztoolkit.exe

goto :end

file="PvZ_Toolkit_v1.xx.x.exe"
rm $file.hash
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

copy bin\splash.png .\out
copy bin\lineup.yml .\out
copy bin\build.yml .\out
