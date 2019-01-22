#include <Servo.h>
#define SENSOR_PIN1 A1
#define SENSOR_PIN2 A2
Servo servo1;

#define SPEED_2      6
#define DIR_2        7
#define SPEED_1      4
#define DIR_1        5
void setup() {
for(int i = 4; i < 8; i++)     
        pinMode(i, OUTPUT);
  servo1.attach(11);
}

void loop() {
  if(analogRead(SENSOR_PIN1)>900 and analogRead(SENSOR_PIN2)<500){
    servo1.write(135);
    analogWrite(SPEED_2, 130);
    digitalWrite(DIR_2, LOW);
    analogWrite(SPEED_1, 130);
    digitalWrite(DIR_1, LOW);
  }else if (analogRead(SENSOR_PIN1)<900 and analogRead(SENSOR_PIN1)>500){
    servo1.write(45);
    analogWrite(SPEED_2, 130);
    digitalWrite(DIR_2, LOW);
    analogWrite(SPEED_1, 130);
    digitalWrite(DIR_1, LOW);
  }else if (analogRead(SENSOR_PIN1)<900 and analogRead(SENSOR_PIN2)<500){
    servo1.write(90);
    analogWrite(SPEED_2, 200);
    digitalWrite(DIR_2, LOW);
    analogWrite(SPEED_1, 200);
    digitalWrite(DIR_1, LOW);
  }else if (analogRead(SENSOR_PIN1)>900 and analogRead(SENSOR_PIN2)>500){
    servo1.write(90);
    analogWrite(SPEED_2, 200);
    digitalWrite(DIR_2, LOW);
    analogWrite(SPEED_1, 200);
    digitalWrite(DIR_1, LOW);

}
}
