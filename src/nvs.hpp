/*

Copyright (c) 2025 Baruch Enterprised Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
  
  Name: nvs.hpp 
  Description: 
  Non Volatile Storage for ESP32. Primarily to store float arrays in the 
  permanent memory of the ESP32 family. 
  Author: Min T. Zan
  Version: 1.1
  Created date: 6/12/2024 
  Revision 1: 14/01/2025 

 */

#ifndef NVS_HPP
#define NVS_HPP

#include <Preferences.h>
#include <climits>

class Storage : public Preferences {

public:
  const char* storageName = "";

  Storage(const char* _storageName) {
    storageName = _storageName;
  }

  esp_err_t initialise() {
    if (!begin(storageName, false)) {
      return -1;
    } else {
      return ESP_OK;
    }
  }
  void storeArray(String arrName, float* data) {
    String indexWithArrayName = "";
    for (int index = 0; index <= sizeof(data); index++) {
      indexWithArrayName = arrName + String(index);
      putFloat(indexWithArrayName.c_str(), data[index]);
    }
  }


  void readArray(String arrName, float result[9999]) {
    String indexWithArrayName = "";
    int index = 0;
    while (true) {
      indexWithArrayName = arrName + String(index);
      if (isKey(indexWithArrayName.c_str())) {
        result[index] = getFloat(indexWithArrayName.c_str(), 0);
      } else {
        break;
      }
      index++;
    }
  }

  int getArraySize(String arrName) {
    String indexWithArrayName = "";
    int index = 0;
    while (true) {
      indexWithArrayName = arrName + String(index);
      if (isKey(indexWithArrayName.c_str())) {
        index++;
      } else {
        break;
      }
    }
    return index;
  }
};

#endif
