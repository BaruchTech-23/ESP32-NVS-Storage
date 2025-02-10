/* 
  Name: read-nvs 
  Description: 
  Non Volatile Storage for ESP32. This code is to read the data from the nvs. 
  Author: Min T. Zan
  Version: 1.1
  Created date: 6/12/2024 
  Revision 1: 14/01/2025 
*/
#include <iostream>
#include "nvs.hpp"

Storage storage("jsonParameters");  //Name of the storage that holds data

float result[5] = {}; // Array to hold the data

void setup() {
  // put your setup code here, to run once:
  storage.initialise();
}

void loop() {
  // put your main code here, to run repeatedly:
  storage.readArray("Data", result);  //Read the data inside "Data" from nvs
  int arrsize = storage.getArraySize("Data"); // Get the array size
  for (int i = 0; i < arrsize; i++) {
    std::cout << "Index " << i << " : " << result[i] << std::endl;
    delay(1000);
  }
}
