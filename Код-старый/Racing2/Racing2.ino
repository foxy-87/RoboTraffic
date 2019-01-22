#include <Servo.h>
Servo rudder;
Servo motor;

#define SEN1 A3
#define SEN2 A2

float target = 0;

void setup() {
  target = analogRead(SEN1) * 1.38 - analogRead(SEN2);
  rudder.attach(11);
  motor.attach(10);
}

void loop() {
  float err = target - (analogRead(SEN1) * 1.38 - analogRead(SEN2));

  //Serial.println(1520 + err);
  float u = 1520 + err / 3.5;
  rudder.writeMicroseconds(u);
  motor.writeMicroseconds(1630);
  delay(10);
}
