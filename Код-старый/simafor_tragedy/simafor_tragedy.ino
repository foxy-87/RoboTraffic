#include <Servo.h>
Servo rudder;
Servo motor;

#define SEN1 A3
#define SEN2 A2
#define SEN_STOP A4
int target = 0;

void setup() {
  target = analogRead(SEN1) - analogRead(SEN2);
  rudder.attach(11);
  motor.attach(10);
  Serial.begin(9600);
  Serial1.begin(115200);
}

void loop() {
  float err = target - (analogRead(SEN1) - analogRead(SEN2));
  //Serial.println(1520 + err);
  int u = 1520 + err / 2;
  if (u > 2280) {
    u = 2280;
  }
  rudder.writeMicroseconds(u);
  if (Serial1.available()) {
    int svet = Serial1.read();
    drive(1520);
    delay(10);
  }else{
    drive(1615);
    delay(10);  }
}
void drive(int speed) {
  motor.writeMicroseconds(speed);
}
