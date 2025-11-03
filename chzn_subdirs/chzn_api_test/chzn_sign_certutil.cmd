::@echo off
cd %~dp0
echo %1
SET PATH=%PATH%;C:\Program Files (x86)\Crypto Pro\CSP;

:: OK csptest.exe -sfsign -sign -in body.txt -out sign_out.txt -my %1 -base64 -add

::certutil.exe sign /debug /sha1 c308ccee0aa8e8b57bbebb8c2d9be4ecb406d01e /v /fd SHA256 222.txt

certutil -v -user -store my "c308ccee0aa8e8b57bbebb8c2d9be4ecb406d01e"

pause
exit

950418e91cf9a5dc56895c905591fbe70c70cc83 мкт

c308ccee0aa8e8b57bbebb8c2d9be4ecb406d01e бит
