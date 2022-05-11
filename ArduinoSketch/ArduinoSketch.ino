#include "gps.h" //gps
//#include "lcd.h" //lcd(opzionale)
void setup() {
  Serial.begin(115200);
    GPSSetup();
    
  #if defined(LCDSetup)
    LCDSetup();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  getGPSInfo();
}
