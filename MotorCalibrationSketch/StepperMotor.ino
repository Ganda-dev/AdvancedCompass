#include <Stepper.h>

#define STEPS 200
Stepper stepper(STEPS, 8, 10, 9, 11);
int previous = 0;

void setup() {
  stepper.setSpeed(30);
}

void loop() {
  int val = analogRead(0);
  stepper.step(val - previous);
  previous = val;

}
