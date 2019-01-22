#include <Servo.h>
Servo motor;
#define STOP_SENSOR A4
//int lol = 0;
void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  motor.attach(10);
  //lol = analogRead(STOP_SENSOR);
}

void loop() {
  if (Serial1.available()) {
    int svet = Serial1.read();
    Serial.print(svet);
    Serial.print(", ");
    Serial.println(analogRead(STOP_SENSOR));
    if (svet == 4 or svet == 3 or svet == 0 and analogRead(STOP_SENSOR) < 255) {
      drive(0);
      delay(10);
    } else if (svet == 4 or svet == 3 and analogRead(STOP_SENSOR) > 255) {
      drive(1800);
      delay(10);
    } 
  }
}

void drive(int speed) {
  motor.writeMicroseconds(speed);
}

