
OUTDIR = .\out
TARGET = pvztoolkit

CXX = cl
CXXFLAGS_BARE = -c -nologo \
                -Zc:wchar_t \
                /MP \
                /utf-8 \
                /Zc:__cplusplus /std:c++20 \
                /W3 /EHsc \
                /O1 /MT
DEFINES = -DUNICODE -D_UNICODE \
          -DWIN32 -D_WIN32_WINNT=0x0600 \
          -D_REGEX_MAX_STACK_COUNT=0
INCPATH = -I.
INCS = .\src\pak.h \
       .\src\process.h \
       .\src\code.h \
       .\src\data.h \
       .\src\lineup.h \
       .\src\pvz.h \
       .\src\window.h \
       .\src\toolkit.h
CXXFLAGS = /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\$(TARGET).pdb" $(CXXFLAGS_BARE) $(DEFINES) $(INCPATH)

RC = rc
RC_FLAGS = /n $(DEFINES)

LINKER = link
LIBS_FLTK = fltk.lib fltk_z.lib fltk_images.lib fltk_jpeg.lib fltk_png.lib
LIBS_ZLIB = zlib.lib
LIBS_WIN32 = user32.lib shell32.lib advapi32.lib comctl32.lib comdlg32.lib ole32.lib \
             psapi.lib version.lib wsock32.lib crypt32.lib gdi32.lib gdiplus.lib wintrust.lib
LIBS = /LIBPATH:$(OUTDIR) $(LIBS_FLTK) $(LIBS_ZLIB) $(LIBS_WIN32)
OBJS = $(OUTDIR)\pak.obj \
       $(OUTDIR)\process.obj \
       $(OUTDIR)\code.obj \
       $(OUTDIR)\data.obj \
       $(OUTDIR)\lineup.obj \
       $(OUTDIR)\pvz.obj \
       $(OUTDIR)\window.obj \
       $(OUTDIR)\toolkit.obj \
       $(OUTDIR)\main.obj
RES = $(OUTDIR)\version.res
LFLAGS = /NOLOGO /DYNAMICBASE /NXCOMPAT /INCREMENTAL:NO /SUBSYSTEM:WINDOWS \
         $(LIBS) $(OBJS) $(RES) /STACK:0x00400000


all:$(OUTDIR) $(OUTDIR)\$(TARGET).exe

$(OUTDIR):
    if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"

$(OUTDIR)\$(TARGET).exe: $(OBJS) $(OUTDIR)\version.res
    $(LINKER) $(LFLAGS) /out:$(OUTDIR)\$(TARGET).exe

$(OUTDIR)\version.res: .\res\version.rc
    $(RC) $(RC_FLAGS) /fo $(OUTDIR)\version.res .\res\version.rc

$(OUTDIR)\pak.obj: .\src\pak.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\pak.obj" .\src\pak.cpp

$(OUTDIR)\process.obj: .\src\process.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\process.obj" .\src\process.cpp

$(OUTDIR)\code.obj: .\src\code.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\code.obj" .\src\code.cpp

$(OUTDIR)\data.obj: .\src\data.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\data.obj" .\src\data.cpp

$(OUTDIR)\lineup.obj: .\src\lineup.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\lineup.obj" .\src\lineup.cpp

$(OUTDIR)\pvz.obj: .\src\pvz.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\pvz.obj" .\src\pvz.cpp

$(OUTDIR)\window.obj: .\src\window.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\window.obj" .\src\window.cpp

$(OUTDIR)\toolkit.obj: .\src\toolkit.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\toolkit.obj" .\src\toolkit.cpp

$(OUTDIR)\main.obj: .\src\main.cpp $(INCS)
    $(CXX) $(CXXFLAGS) /Fe"$(OUTDIR)\main.obj" .\src\main.cpp

clean:
    if exist "$(OUTDIR)" rmdir /s /q "$(OUTDIR)"
