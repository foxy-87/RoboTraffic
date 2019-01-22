#include <Servo.h>
Servo rudder;
Servo motor;

#define SEN1 A3
#define SEN2 A2
#define SEN_STOP A4
int target = 0;
int trigPin = 6;
int echoPin = 5;

bool Flag;

void setup() {
  target = analogRead(SEN1) - analogRead(SEN2);
  rudder.attach(11);
  motor.attach(10);
  Serial.begin(9600);
  Serial1.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  //Flag = false;
  Line_sensor_rudder();
  simafor();
  //if (Serial1.available()) {
  //Flag = true;
  //if (Flag == true) {
  //simafor();
  //delay(20);
  //Serial.println("всё норм");
  //}
  //} else {
  //Flag = false;
  //if (Flag == false) {
  //ultra_cm();
  //Serial.println("всё плохо");
  //}
  //}
  //if (Flag == true) {
  //simafor();
  //} else if (Flag == false) {
  //ultra_cm();
  //}

}
void Line_sensor_rudder() {
  float err = target - (analogRead(SEN1) - analogRead(SEN2));
  //Serial.println(1520 + err);
  int u = 1520 + err / 2;
  rudder.writeMicroseconds(u);
}
void simafor() {
  if (Serial1.available()) {
    int svet = Serial1.read();
    Serial.println(svet);
    if (svet == 0) {
      motor.writeMicroseconds(1520);
    } else if (svet == 2) {
      motor.writeMicroseconds(1700);
    } else if (svet == 1) {
      motor.writeMicroseconds(1520);
    } else if (svet == 3) {
      motor.writeMicroseconds(1520);
    } else if (svet == 4) {
      motor.writeMicroseconds(1520);
    } else if (svet == 5) {
      motor.writeMicroseconds(1520);
    }
  }
}
void ultra_cm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Теперь установим высокий уровень на пине Trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Узнаем длительность высокого сигнала на пине Echo
  int cm = pulseIn(echoPin, HIGH);
  int cm_speed = 1520 + (cm / 58 + 17) * 2;
  if (cm_speed >= 1615) {
    motor.writeMicroseconds(1700);
  } else {
    motor.writeMicroseconds(1520);
  }

}

