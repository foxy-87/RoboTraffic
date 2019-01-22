#include <Servo.h>
Servo servo1;
#define SEN1 A1
#define SEN2 A3
#define SPEED_2      6
#define DIR_2        7
#define SPEED_1      4
#define DIR_1        5
void setup() {
  servo1.attach(11);
  for(int i = 4; i < 8; i++)     
        pinMode(i, OUTPUT); 
}

void loop() {
  int grey = 150 ;
  int err = -grey + analogRead(SEN2);
  servo1.write(90-err/5);
  drive(150);
  delay(10);

}
void drive(int speed) {
  analogWrite(SPEED_2, speed);
  digitalWrite(DIR_2, LOW);
  analogWrite(SPEED_1, speed);
  digitalWrite(DIR_1, LOW);
}
