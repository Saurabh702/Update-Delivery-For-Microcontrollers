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
AVRDUDE (Link: https://www.nongnu.org/avrdude/)

### Server ###
Server files are located in updates folder.
(Place the updates folder in your server's directory and change the server address in main.c, ex: http://127.0.0.1/updates)
It contains two files: package.hex and index.html
index.html -> Contains version of the packaged update (Hosted version)
package.hex -> pre-compiled hex update (for arduino uno based microcontroller)
The above update is based on sample blink example provided by Arduino IDE with modified delay interval of 5000ms 
Link: https://github.com/arduino/Arduino/blob/master/build/shared/examples/01.Basics/Blink/Blink.ino
(On successful update of the Arduino UNO, expect the LED to blink every 5 seconds)

### Debugging/Testing ###
If microcontroller is not available, use Null-modem emulator(com0com) to test/debug 
Link: https://sourceforge.net/projects/com0com/
Steps to Emulate a Device Connection (for eg: Arduino UNO) (Screenshots added in Report)
* Run the com0com setup
* Add a pair of devices
* Add port class and emulate baud rate
* Change the device description by modifying the registry
Note1: For other microcontrollers, change either device description or friendly name in registry for emulating it
Note2: change device descriptions of the port using regedit, for ex regedit at this location:
    "HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Enum\com0com\port\CNCA0"
* To send the program version, use echo <Version> > <PortNo>
For ex: if emulator is emulating the device connection at COM5 and COM6 port is sending data to COM5, then echo 10.0 > COM6
* To enable or disable the ports, run the command line version of com0com (setupc.exe) in administrator mode
	ex: "enable all" command enables the ports and "disable all" disables the ports

### Assumptions ###
The initial program running in the microcontroller, should output the program version for the utility. In case of an Arduino Uno, the output of the program version can be done in either the setup() or loop() based on convenience. Subsequent update packages should include this functionality too.
For Arduino Uno, the Device Description is given as "Arduino Uno"(according to arduino.inf located in drivers folder of Arduino IDE) however this is true for orginal UNO devices. Fake or clones of Arduino UNO might use different device description names, so make sure to change the device description accordingly.
"avrdude" folder should be in the same folder as that of the program, for ex: if program is built using makefile, then it is located in the bin folder, so the avrdude folder should be in the bin folder.

### Code References ###
	-> Serial-Programming-Win32API-C: https://github.com/xanthium-enterprises/Serial-Programming-Win32API-C
   	   Link to reference used: 
	   https://github.com/Saurabh702/Update-Delivery-For-Microcontrollers/blob/master/source/usb2serial_read_w32.c
	-> Makefile generated using cbp2make tool (https://sourceforge.net/projects/cbp2make/)

Note: For more details refer to the report 
Link: https://github.com/Saurabh702/Update-Delivery-For-Microcontrollers/blob/master/Report.pdf

### TODOS ###
* Compatibility for other devices and Operating systems
