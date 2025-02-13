/* 
  Name: store-nvs 
  Description: 
  Non Volatile Storage for ESP32. This code is to store the data inside the nvs. 
  Author: Min T. Zan
  Version: 1.1
  Created date: 6/12/2024 
  Revision 1: 14/01/2025 
*/

#include "nvs.hpp"

Storage storage("Storage1");  //Name of the storage space (Any name can be named)
float data[] = { 1.2, 12.9, 23.1, 120.4, 212.98 }; //Data to store

void setup() {
  // put your setup code here, to run once:
  storage.initialise();
  storage.storeArray("Data", data, 5);  //Store the data inside para array in "Data"
}

void loop() {
  //Nothing to do here. 
}
