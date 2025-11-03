@echo off
set CURDIR=%~dp0
echo %CURDIR%

echo ---------------------------------------------------------------------------------------------------------------------------
mklink /j %CURDIR%\qp D:\DEVELOPMENT\QT4\_MY__\qp
mklink /j %CURDIR%\chzn_subdirs D:\DEVELOPMENT\QT4\_MY__\chzn_subdirs
mklink /j %CURDIR%\marking D:\DEVELOPMENT\QT4\_MY__\marking
mklink /j %CURDIR%\kb_scanner D:\DEVELOPMENT\QT4\_MY__\kb_scanner


echo ---------------------------------------------------------------------------------------------------------------------------
pause
