#include <Arduino.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>

float lat = 0.0000;
float lon = 0.0000;
SoftwareSerial gpsSerial(2,3); //RX, TX
TinyGPS gps; //Creo l'oggetto GPS

void GPSSetup(){
  gpsSerial.begin(9600);
}

void getInfo(){
    while(gpsSerial.available()){
      if(gps.encode(gpsSerial.read())){
        gps.f_get_position(&lat,&lon);  
      }
    }
}

void printGPS(){
  while(gpsSerial.available()){
    if(gps.encode(gpsSerial.read())){
          Serial.println("lat:"+String(lat,5)+";");
          Serial.println("lon:"+String(lon,5)+";");
          Serial.println("----");
          delay(50); 
      }
  }
}
