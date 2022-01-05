//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the Licens++++e at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "manless-parking-system-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "RUPOf0UK32oHYoKFaAnxgjAVH6b6iqACCUuBrbPW"
#define WIFI_SSID "keylogger"
#define WIFI_PASSWORD "keylogger"

void setup()
{
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
     }

    // connect to wifi.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop()
{
    char slot;
    if (Serial.available()) {
      slot =(Serial.read());
    Serial.println(slot);
    switch(slot){
      case 'a':
        Firebase.setInt("parkingslot/A1",0);
        break;
     case 'A':
        Firebase.setInt("parkingslot/A1",1);
        break;
     case 'b':
        Firebase.setInt("parkingslot/A2",0);
        break;
     case 'B':
        Firebase.setInt("parkingslot/A2",1);
        break;
     case 'c':
        Firebase.setInt("parkingslot/A3",0);
        break;
     case 'C':
        Firebase.setInt("parkingslot/A3",1);
        break;
     case 'd':
        Firebase.setInt("parkingslot/A4",0);
        break;
     case 'D':
        Firebase.setInt("parkingslot/A4",1);
        break;
     case 'e':
        Firebase.setInt("parkingslot/A5",0);
        break;
     case 'E':
        Firebase.setInt("parkingslot/A5",1);
        break;
     case 'f':
        Firebase.setInt("parkingslot/B1",1);
        break;
     case 'F':
        Firebase.setInt("parkingslot/B1",1);
        break;
     case 'g':
        Firebase.setInt("parkingslot/B2",0);
        break;
     case 'G':
        Firebase.setInt("parkingslot/B2",1);
        break;
     case 'h':
        Firebase.setInt("parkingslot/B3",0);
        break;
     case 'H':
        Firebase.setInt("parkingslot/B3",1);
        break;
     case 'i':
        Firebase.setInt("parkingslot/B4",0);
        break;
     case 'I':
        Firebase.setInt("parkingslot/B4",1);
        break;
     case 'j':
        Firebase.setInt("parkingslot/B5",0);
        break;
     case 'J':
        Firebase.setInt("parkingslot/B5",1);
        break;
    default:
        break;
        }   
}
}
