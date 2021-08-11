// --------------------------------------------------
//
// ESP32 Bluetooth App part 3 -> reliable cummunication of id and value
//
// Code for reliable communication between the ESP32 and mobile phone (with MIT inventor app). 
// device used for tests: ESP32-WROOM-32D
// 
// Data is sent in 3 bytes: 
// First byte is the identification byte -> values used 128 - 255
// Second byte is the most significant byte of the data -> values used 0 - 127
// Third byte is the least significant byte of the data -> values used 0 - 127
//
// Written by mo thunderz (last update: 11.8.2021)
//
// --------------------------------------------------

// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h" 

// init Class:
BluetoothSerial ESP_BT; 

// Parameters for Bluetooth interface and timing
int incoming;                           // variable to store byte received from phone 
int id = -1;                            // received identification byte
int val_byte1 = -1;                     // most significant byte of data value
int val_byte2 = -1;                     // least significant byte of data value

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control");        // Name of your Bluetooth interface -> will show up on your phone

}

void loop() {
 
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read();           // Read what we receive and store in "incoming"

    if (incoming > 127) {               // ID bytes are 128 or higher, so check if incoming byte is an ID-byte
      reset_rx_BT();                    // reset id and data to -1
      id = incoming - 128;              // write id value
    }
    else if (val_byte1 == -1) {         // if incoming byte is lower than 128 it is a data byte. Check if first data byte is empty (-1)
      val_byte1 = incoming;             // write first data byte (MSB)
    }
    else if (val_byte2 == -1) {         // check if second data byte is empty (-1)
      val_byte2 = incoming;             // write second data byte (LSB)
      int value = 128*val_byte1 + val_byte2;          // recombine the first and second data byte to the actual value that was sent from the phone
      // here is the location that you can implement the code what you want to do with the controller id and value received from the phone
      
      Serial.print("Id: "); Serial.print(id); Serial.print(", val: "); Serial.println(value);   // for debugging write to the serial interface (check with serial monitor)
      send_BT(id, value);               // for test purposes we just send the data back to the phone
      reset_rx_BT();                    // not strictly needed, but just in case erase all bytes (set to -1)
    }
  }
}

void reset_rx_BT() {                    // function to erase all bytes (set to -1)
  id = -1;
  val_byte1 = -1;
  val_byte2 = -1;
}
void send_BT(int id, int value) {       // function to write id and value to the bluetooth interface (and split value in MSB and LSB
  ESP_BT.write(128 + id);
  ESP_BT.write(floor(value/128));       // MSB
  ESP_BT.write(value%128);              // LSB
}
