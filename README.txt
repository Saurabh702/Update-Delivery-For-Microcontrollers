Prerequisite to build source code on Windows -> mingw32 (with win32api)
					     -> curl for Windows (mingw32)

Links: To build curl for mingw32 compiler in Windows
       -> https://fatchoco.wordpress.com/2009/03/01/using-curl-in-mingw/
       -> https://toster.ru/q/29031	
      
Make utility for Windows - > mingw32-make

Use -e argument in mingw32-make to use enviroment variables in makefiles
Ex:
If include directory is to be specified, then
SET INC=-I\\path\\to\\include\\directory
mingw32-make -e 

Alternative: Run the command below
mingw32-make INC=-I\\path\\to\\include\\directory
-----------------------------------
makefile works when the current directory has the contents of headers and source directories
