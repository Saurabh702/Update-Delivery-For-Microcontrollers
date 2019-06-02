Update-Delivery-For-Microcontrollers
====================================

## Project Description ##

Microcontrollers are devices that take input as analog signals and deliver output as digital signals. Assuming the user has no technical background, and the end user product is included in the microcontroller. This project assumes that user is simply using the product. Product must update or configure itself by abstracting unneeded details from the user. The problem of updates and upload is addressed in this implementation. This project will check for updates by the consent of the user, check whether the device is connected or not, then if connected, upload the program to the controller.

### Pre-requisite to build the source code (Windows) ###
	-> mingw32 compiler (with win32api)
	   Make utility for Windows : mingw32-make.exe
	   Link: http://wiki.codeblocks.org/index.php/MinGW_installation
	-> curl for Windows
	   Links (to build curl for mingw32 compiler):
			 * https://fatchoco.wordpress.com/2009/03/01/using-curl-in-mingw/
			 * https://toster.ru/q/29031	

### IDE used ###  
Codeblocks
		
### Microcontroller ### 
Arduino UNO
	
### Utility used to upload code to the Microcontroller ### 
AVRDUDE

### Code References ###
	-> Serial-Programming-Win32API-C: https://github.com/xanthium-enterprises/Serial-Programming-Win32API-C
   	   Link to reference used: 
	   https://github.com/Saurabh702/Update-Delivery-For-Microcontrollers/blob/develop/source/usb2serial_read_w32.c

Note: For more details refer to the report 
Link: https://github.com/Saurabh702/Update-Delivery-For-Microcontrollers/blob/master/Report.pdf
