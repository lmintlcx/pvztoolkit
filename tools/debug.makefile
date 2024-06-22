
OUTDIR = .\build
TARGET = pvztoolkitd

CXX = cl
CXX_FLAGS_BARE = /c /nologo \
                /Zc:wchar_t /Zc:__cplusplus \
                /std:c++17 \
                /MP \
                /utf-8 \
                /W3 /GR- \
                /Od /MTd /Zi /FS
DEFINES = -D_HAS_EXCEPTIONS=0 \
          -DUNICODE -D_UNICODE \
          -DWIN32_LEAN_AND_MEAN -DNOMINMAX \
          -DWIN32 -D_WIN32_WINNT=0x0600 \
          -D_REGEX_MAX_STACK_COUNT=0 \
          -D_PVZ_BETA_LEAK_SUPPORT \
          -D_PTK_CHINESE_UI \
          -D_PTK_SIGNATURE_CHECK
INCPATH = -I.
INCS = .\inc\utils.h \
       .\inc\pak.h \
       .\inc\process.h \
       .\inc\code.h \
       .\inc\data.h \
       .\inc\lineup.h \
       .\inc\pvz.h \
       .\inc\window.h \
       .\inc\toolkit.h
CXX_FLAGS = /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\$(TARGET).pdb" $(CXX_FLAGS_BARE) $(DEFINES) $(INCPATH)

ASM = ml
ASM_FLAGS = /c /nologo /W3

RC = rc
RC_FLAGS = /n $(DEFINES)

LINKER = link
LIBS_FLTK = fltkd.lib fltk_imagesd.lib fltk_jpegd.lib fltk_pngd.lib fltk_zd.lib
LIBS_ZLIB = 
LIBS_WIN32 = user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib comdlg32.lib ws2_32.lib comctl32.lib gdiplus.lib \
             crypt32.lib advapi32.lib wintrust.lib shlwapi.lib
LIBS = /LIBPATH:$(OUTDIR) $(LIBS_FLTK) $(LIBS_ZLIB) $(LIBS_WIN32)
OBJS = $(OUTDIR)\utils.obj \
       $(OUTDIR)\pak.obj \
       $(OUTDIR)\process.obj \
       $(OUTDIR)\code.obj \
       $(OUTDIR)\data.obj \
       $(OUTDIR)\lineup.obj \
       $(OUTDIR)\pvz.obj \
       $(OUTDIR)\window.obj \
       $(OUTDIR)\toolkit.obj \
       $(OUTDIR)\main.obj
RES = $(OUTDIR)\version.res
LINK_FLAGS = /NOLOGO /DYNAMICBASE:NO /INCREMENTAL:NO /SUBSYSTEM:CONSOLE \
         $(LIBS) $(OBJS) $(RES) /DEBUG /STACK:0x00400000


all:$(OUTDIR) $(OUTDIR)\$(TARGET).exe

$(OUTDIR):
    if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"

$(OUTDIR)\$(TARGET).exe: $(OBJS) $(OUTDIR)\version.res
    $(LINKER) $(LINK_FLAGS) /out:$(OUTDIR)\$(TARGET).exe

$(OUTDIR)\version.res: .\res\version.rc
    $(RC) $(RC_FLAGS) /fo $(OUTDIR)\version.res .\res\version.rc

$(OUTDIR)\utils.obj: .\src\utils.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\utils.obj" .\src\utils.cpp

$(OUTDIR)\pak.obj: .\src\pak.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\pak.obj" .\src\pak.cpp

$(OUTDIR)\process.obj: .\src\process.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\process.obj" .\src\process.cpp

$(OUTDIR)\code.obj: .\src\code.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\code.obj" .\src\code.cpp

$(OUTDIR)\data.obj: .\src\data.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\data.obj" .\src\data.cpp

$(OUTDIR)\lineup.obj: .\src\lineup.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\lineup.obj" .\src\lineup.cpp

$(OUTDIR)\pvz.obj: .\src\pvz.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\pvz.obj" .\src\pvz.cpp

$(OUTDIR)\window.obj: .\src\window.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\window.obj" .\src\window.cpp

$(OUTDIR)\toolkit.obj: .\src\toolkit.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\toolkit.obj" .\src\toolkit.cpp

$(OUTDIR)\main.obj: .\src\main.cpp $(INCS)
    $(CXX) $(CXX_FLAGS) /Fe"$(OUTDIR)\main.obj" .\src\main.cpp

clean:
    if exist "$(OUTDIR)" rmdir /s /q "$(OUTDIR)"
