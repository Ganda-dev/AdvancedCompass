#include <Stepper.h>
#include <Arduino.h>
#include "lcd.h"
#define STEPS 200
int angle = 0;
Stepper stepper(STEPS, 8, 10, 9, 11);

void stepMotorSetup(){
  stepper.setSpeed(30);
}
void getAngle(){
    angle = Serial.readStringUntil('/').toInt();
    printDistance(angle);
    int val = map(angle, 0,360,0,2048);
    stepper.step(val);

}
