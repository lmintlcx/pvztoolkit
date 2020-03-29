@echo off
setlocal enabledelayedexpansion
if "%IBJOM_NUMBEROFJOBS%" == "" set IBJOM_NUMBEROFJOBS=60
set NINJAFLAGS=-j60
xgConsole /profile="%~dp0\xgejom.xml" /command="jom -j%IBJOM_NUMBEROFJOBS% %*" || exit /b !ERRORLEVEL!
endlocal
