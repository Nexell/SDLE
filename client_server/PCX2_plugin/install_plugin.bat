@echo off
set SRCPATH=%~dp0\Win32Release\nexell_xpad.dll
set DSTPATH="C:\Program Files (x86)\PCSX2 1.4.0\Plugins"

>nul 2>&1 "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"
if '%errorlevel%' NEQ '0' (
    echo "This script needs Supervisor authority"
    goto UACPrompt
) else ( goto gotAdmin )
:UACPrompt
    echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
    set params = %*:"=""
    echo UAC.ShellExecute "cmd.exe", "/c %~s0 %params%", "", "runas", 1 >> "%temp%\getadmin.vbs"
    "%temp%\getadmin.vbs"
    rem del "%temp%\getadmin.vbs"
    exit /B
    pushd "%CD%"
    CD /D "%~dp0"


:gotAdmin
    echo copy /y %SRCPATH% %DSTPATH%
    copy /y %SRCPATH% %DSTPATH%
    pause





