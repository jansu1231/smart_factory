#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
}

void loop() {
  servo1.write(0);
  delay(1000);
  servo1.write(180);
  delay(1000);

   
}
