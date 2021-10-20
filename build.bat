
@echo off
chcp 65001

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 -vcvars_ver=14.16

set PATH=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%
set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%

cd /d D:\repo\pvztoolkit

set INCLUDE=.\fltk\include;.\zlib\include;%INCLUDE%
set LIB=.\fltk\lib;.\zlib\lib;%LIB%

set PATH=.\jom;%PATH%
set MAKE_TOOL=jom

%MAKE_TOOL% -f makefile.debug clean
%MAKE_TOOL% -f makefile.debug

signtool.exe sign /v ^
/f "D:\notes\cert\pvztoolkit.pfx" ^
/p "Rm9yIFppb24h" ^
.\out\pvztoolkitd.exe



goto :end

%MAKE_TOOL% -f makefile.release clean
%MAKE_TOOL% -f makefile.release
.\upx\upx.exe --lzma --ultra-brute .\out\pvztoolkit.exe

signtool.exe sign /v ^
/f "D:\notes\cert\pvztoolkit.pfx" ^
/p "Rm9yIFppb24h" ^
/t "http://timestamp.digicert.com" ^
.\out\pvztoolkit.exe

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
