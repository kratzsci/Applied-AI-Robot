#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("ESP32");
}

void loop() {
  SerialBT.println("Hellow World");
  delay(10000);
}