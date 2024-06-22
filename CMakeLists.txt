
cmake_minimum_required(VERSION 3.15)

project(pvztoolkit)

# set(CMAKE_BUILD_TYPE MinSizeRel)
# set(FLTK_DIR "C:/Dev/fltk_1.4.0/msvc2017_x86/static/CMake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(FLTK CONFIG REQUIRED)

aux_source_directory(./src PZTK_SRCS)
add_executable(pvztoolkit WIN32 ${PZTK_SRCS})

# target_include_directories(
#     pvztoolkit PRIVATE
#     ./inc
# )

target_sources(
    pvztoolkit PRIVATE
    ./res/version.rc
    ./res/pvztoolkit.manifest
)

target_compile_definitions(
    pvztoolkit PRIVATE
    UNICODE _UNICODE
    WIN32_LEAN_AND_MEAN NOMINMAX
    _WIN32_WINNT=0x0600
    _REGEX_MAX_STACK_COUNT=0
    _PVZ_BETA_LEAK_SUPPORT
)

target_compile_options(
    pvztoolkit PRIVATE
    /Zc:wchar_t /Zc:__cplusplus
    /utf-8
)

target_link_libraries(
    pvztoolkit PRIVATE
    fltk::fltk fltk::images fltk::jpeg fltk::png fltk::z
    crypt32.lib advapi32.lib wintrust.lib shlwapi.lib
)
