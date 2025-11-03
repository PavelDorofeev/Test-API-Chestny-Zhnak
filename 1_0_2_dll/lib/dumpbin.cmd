call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86
SET NNN=libeay32
::dumpbin.exe /exports %NNN%.dll >  dumpbin_%NNN%_dll.txt
dumpbin.exe /exports %NNN%.lib >  dumpbin_%NNN%_lib.txt
SET NNN=ssleay32
::dumpbin.exe /exports %NNN%.dll >  dumpbin_%NNN%_dll.txt
dumpbin.exe /exports %NNN%.lib >  dumpbin_%NNN%_lib.txt

pause

exit

