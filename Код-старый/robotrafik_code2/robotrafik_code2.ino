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
  line_drive();
  stop_line();
  drive(1615);
}
void drive(int speed) {
  motor.writeMicroseconds(speed);
}
void line_drive() {
  float err = target - (analogRead(SEN1) - analogRead(SEN2));
  //Serial.println(1520 + err);
  int u = 1520 + err / 2;
  if (u > 2280) {
    u = 2280;
  }
  rudder.writeMicroseconds(u);
}

void stop_line() {
  if (analogRead(SEN_STOP) > 400) {
    drive(1520);
    delay(10);
    if (Serial1.available()) {
      int svet = Serial1.read();
    } else {
      drive(1600);
      delay(10);
    }
  }
}
//void simafor_signal() {
//  if(svet == 0 or 1 or 3 or 4 or 5){
    //drive(1520);
    //delay(10);
  //}else if(svet == 2){
    //drive
  //}
//}

