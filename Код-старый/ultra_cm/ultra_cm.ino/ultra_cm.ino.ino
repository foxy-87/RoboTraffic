#include <Servo.h>
Servo motor;


int trigPin = 6; 
int echoPin = 5;  
 
void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  motor.attach(10);
} 
 
void loop() { 
  int duration, distance;
  // для большей точности установим значение LOW на пине Trig
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  // Теперь установим высокий уровень на пине Trig
  digitalWrite(trigPin, HIGH);
  // Подождем 10 μs 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  // Узнаем длительность высокого сигнала на пине Echo
  duration = pulseIn(echoPin, HIGH); 
  // Рассчитаем расстояние
  motor.writeMicroseconds(1520+(duration/58-10)*2);
  Serial.println(1600+(duration/58-10)*2);
}
