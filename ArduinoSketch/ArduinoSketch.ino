#include "gps.h" //gps
//#include "lcd.h" //lcd(opzionale)
void setup() {
  Serial.begin(115200);
  GPSSetup();
  //LCDSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  getInfo();
  
  
  
  printGPS(); //per stampare i valori nel monitor seriale(115200)
}
