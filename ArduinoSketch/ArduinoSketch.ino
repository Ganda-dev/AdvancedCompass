#include "gps.h" //gps
#include "steppermotor.h"
#include "lcd.h" //lcd(opzionale)
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1000);
  GPSSetup();
  stepMotorSetup();    
  LCDSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  getGPSInfo();
  getAngle();
}
