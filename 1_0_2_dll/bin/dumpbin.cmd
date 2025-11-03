::SET PATH=C:\WINDOWS\system32;C:\WINDOWS;

call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86

cd /d "%~dp0"
echo "dp0 =  %~dp0"

echo %PATH%
SET NAME=ssleay32

dumpbin.exe /EXPORTS %NAME%.dll > %NAME%_EXPORT.txt
SET NAME=libeay32
dumpbin.exe /EXPORTS %NAME%.dll > %NAME%_EXPORT.txt

:: > libeay_32_dll_exports.txt
::dumpbin /EXPORTS D:\OpenSSL\1_0_2_dll\bin\libeay32.dll > libeay32_dll_exports.txt
pause

exit

usage: DUMPBIN [options] [files]

   options:

      /ALL
      /ARCHIVEMEMBERS
      /CLRHEADER
      /DEPENDENTS
      /DIRECTIVES
      /DISASM[:{BYTES|NOBYTES}]
      /ERRORREPORT:{NONE|PROMPT|QUEUE|SEND}
      /EXPORTS
      /FPO
      /HEADERS
      /IMPORTS[:filename]
      /LINENUMBERS
      /LINKERMEMBER[:{1|2}]
      /LOADCONFIG
      /OUT:filename
      /PDATA
      /PDBPATH[:VERBOSE]
      /RANGE:vaMin[,vaMax]
      /RAWDATA[:{NONE|1|2|4|8}[,#]]
      /RELOCATIONS
      /SECTION:name
      /SUMMARY
      /SYMBOLS
      /TLS
      /UNWINDINFO
