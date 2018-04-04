#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Minggu","Senin","Selasa","Rabu","Kamis","Jum'at","Sabtu"};

void setup() {
  // put your setup code here, to run once:
#ifndef ESP8266
  while(!Serial);
#endif
    Serial.begin(9600);
    delay(3000);
    if(!rtc.begin()){
      Serial.println("Tidak dapat mencari RTC");  
      while(1);
    }
    if(rtc.lostPower()){
      Serial.println("RTC kehilangan power, ayo pasang waktu!");
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}
