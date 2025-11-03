@echo off
cd %~dp0
echo %1
SET PATH=%PATH%;C:\Program Files (x86)\Crypto Pro\CSP;
SET PATH=%PATH%;C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x86;


echo  signtool.exe is part of Windows SDK. If you don’t already have it, you should first download install Windows SDK on your system.


::signtool.exe sign /fd sha256 /tr http://ts.ssl.com /td sha256 /v "D:\DEVELOPMENT\QT4\_MY__\driver_KKT_BIT\chzn\chzn_wgt_test\body2.txt"
signtool.exe sign /csp "Aktiv ruToken CSP v1.0" "c308ccee0aa8e8b57bbebb8c2d9be4ecb406d01e" /tr http://rfc3161timestamp.globalsign.com/advanced /td SHA256 "body2.txt"
::certificate thumbprint
pause
exit

950418e91cf9a5dc56895c905591fbe70c70cc83 мкт

c308ccee0aa8e8b57bbebb8c2d9be4ecb406d01e бит


/td – “td” here stands time server digest algorithm.
/fd – “fd” here stands for File Digest Algorithm.