
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "manless-parking-system-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "RUPOf0UK32oHYoKFaAnxgjAVH6b6iqACCUuBrbPW"
#define WIFI_SSID "keylogger"
#define WIFI_PASSWORD "keylogger"

String slot[10]={"A1","A2","A3","A4","A5","B1","B2","B3","B4","B5"};

void setup()
{
    Serial.begin(9600);
    pinMode(4,OUTPUT);

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
  for(int i=0;i<10;i++){
    int dt = Firebase.getInt("parkingslot/"+slot[i]);
    Serial.println(slot[i]+" : " +dt);
    if(dt == 0){
      n++;
    }
    }
  if (n>0){
    Serial.println('O');
    digitalWrite(4,HIGH);
    }
   else{
   digitalWrite(4,LOW);
   }
    
}
