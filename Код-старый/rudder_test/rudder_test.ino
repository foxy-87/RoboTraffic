#include <Servo.h>
#define SENSOR_PIN1 A1
#define SENSOR_PIN2 A2
Servo servo1;
void setup() {
  servo1.attach(11);

}

void loop() {
  if(analogRead(SENSOR_PIN1)<400 and analogRead(SENSOR_PIN2)>400){
    servo1.write(135);
  }else if (analogRead(SENSOR_PIN1)>400 and analogRead(SENSOR_PIN2)<400){
    servo1.write(45);
  }else if (analogRead(SENSOR_PIN1)>400 and analogRead(SENSOR_PIN2)>400){
    servo1.write(90);
  }else if (analogRead(SENSOR_PIN1)<400 and analogRead(SENSOR_PIN2)<400){
    servo1.write(90);
  }
}
