#include <Servo.h>
Servo motor;

void setup() {

  Serial.begin(9600);
  Serial1.begin(115200);
  motor.attach(10);
}

void loop() {
  if (Serial1.available()) {
    int svet = Serial1.read();
    Serial.println(svet);

    if (svet == 2) {
      drive(1800);
      delay(10);
    } else if (svet == 0) {
      drive(0);
      delay(10);
    }
  }
}

void drive(int speed) {
  motor.writeMicroseconds(speed);

}

