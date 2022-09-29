# Esp32BluetoothApp Part3
Part 1 and 2 of this series focused on realization of a bi-directional Bluetooth communication channel between an ESP32 and your phone (using MIT app inventor). However, the length of the communication was limited to a single byte. In part 3 I will show you to send over values larger than 256 values and introduce a simple protocol to send over an ID with an associated value. This is practical for sending over control and/or sensor values. Please make sure that your ESP32 has integrated Bluetooth. Device used for coding: ESP32-WROOM-32D. Youtube explanation is available (see below).

This code is based on part 1 and 2 which covers uni-directional and bi-directional communication from your phone to the ESP32, respectively:
https://github.com/mo-thunderz/Esp32BluetoothApp
https://github.com/mo-thunderz/Esp32BluetoothAppPart2

# Installation
1) Download all files from this repository (Esp32BluetoothAppPart3)
2) Program ESP32 with the "Esp32BluetoothAppPart3.ino", located in the folders \Arduino\Esp32BluetoothAppPart3
3) Open the Bluetooth settings of your phone and scan here for devices (while the ESP32 is programmed and has power). You should find a device called "ESP32_Control". Select this device.
4) navigate to https://appinventor.mit.edu/ and select "create Apps!" on the left top
5) Select "Projects" on the top and then "import project (.aia) from my computer
6) From the ESP32BluetoothAppPart3 repository, select the file "ESP32BluetoothAppPart3.aia" located in the folder "MIT inventor"
7) There are two ways to run the app:
7a) Ideal for debugging: on your phone goto your app store and install MIT AI2 Companion. You can then connect your phone to the computer by running this app and on your computer navigating to "Connect" -> AI Companion. This will give you a QR code on your computer screen that you can scan in the MIT AI2 Companion app on your phone.
7b) You can compile the ESP32BluetoothAppPart3 and install it on your phone by selecting "Build" -> App (provide QR code for .apk). This will give you a link to install the app on your phone.
8) Run the app (with 7a or 7b), this will prompt a list of all Bluetooth devices you have configured in your phone: select "ESP32_Control" -> Please make sure you have done step 3 BEFORE running the app.
9) There are two ways to test if everything works. 
9a) you can open a serial monitor in your Arduino IDE and set the baud rate to 19200
9b) you can connect LEDs to pins 26, 27 and 14 (dont forget to put a resistor of ~100 ohms in series per LED)

# How to use
Part 1:
https://www.youtube.com/watch?v=aM2ktMKAunw

Part 2:
https://www.youtube.com/watch?v=OvWd_xZ12E4

Part 3:
https://www.youtube.com/watch?v=eP35zgZnQY4

# Updates
* 29.09.2022 - MIT App inventor updated the BluetoothClient without backward compatibility. As a result, the .aia file gave an error when loaded into MIT app inventor: "A problem occurred while loading this project. No upgrade strategy exists for BluetoothClient from version 6 to 7". I updated to the new BluetoothClient, but then I got the following error "need android.permission.BLUETOOTH_CONNECT permission". It turned out that the code now needs to ask for permission to use Bluetooth. Both problems are now fixed. 

Have fun ;-)

mo thunderz
