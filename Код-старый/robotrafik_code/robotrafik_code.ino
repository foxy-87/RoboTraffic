#include<Servo.h> //подключаем библиотеку servo
Servo rudder; //объявляем что переменная rudder отвечает за работу с сервоприводом
Servo motor; //объявляем что переменная motor отвечает за работу с сервоприводом

//#define Programm1 100 //объявляем что переменная Program1 равна значению 100
//#define Programm2 200 //объявляем что переменная Program2 равна значению 200
#define SEN_1 A3 //подключаем  переменную SEN_1 к 3 аналоговому порту
#define SEN_2 A2 //подключаем  переменную SEN_2 к 2 аналоговому порту
#define SEN_STOP A4 //подключаем  переменную SEN_STOP к 4 аналоговому порту

int calibrate_line_sensor = 0; //объявляем что переменная Program1 равна значению 0
int calibrate_stop_sensor = 0;//объявляем что переменная  равна значению 0
int trigPin = 6; //подключаем  переменную SEN_STOP к 4 аналоговому порту
int echoPin = 5; //подключаем  переменную SEN_STOP к 4 аналоговому порту

boolean calibrate_line_sensor_button_flag = 0;
boolean calibrate_line_sensor_button;
boolean calibrate_stop_sensor_button_flag = 0;
boolean calibrate_stop_sensor_button;

unsigned long last_press;
//unsigned long timer1, timer2, timer3, timer4;

void setup() {
  rudder.attach(11);
  motor.attach(10);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial1.begin(115200);
}


void loop() {
  calibrate_line_sensor_button = !digitalRead(3);
  calibrate_stop_sensor_button = !digitalRead(4);



  if (calibrate_line_sensor_button == 1 && calibrate_line_sensor_button_flag == 0 && millis() - last_press > 100) {
    calibrate_line_sensor_button_flag = 1;
    //Serial.println("Датчик линии калибруется");
    calibrate_line_sensor = analogRead(SEN_2) - analogRead(SEN_1);
    last_press = millis();
    digitalWrite(8, HIGH);
  }
  if (calibrate_line_sensor_button == 0 && calibrate_line_sensor_button_flag == 1) {
    calibrate_line_sensor_button_flag = 0;
    digitalWrite(8, LOW);
    //Serial.println("Датчики линии откалиброван");
  }
  if (calibrate_stop_sensor_button == 1 && calibrate_stop_sensor_button_flag == 0 && millis() - last_press > 100) {
    calibrate_stop_sensor_button_flag = 1;
    //Serial.println("Датчик стоплинии калибруется");
    calibrate_stop_sensor = analogRead(SEN_STOP);
    digitalWrite(9, HIGH);
    last_press = millis();
  }
  if (calibrate_stop_sensor_button == 0 && calibrate_stop_sensor_button_flag == 1) {
    calibrate_stop_sensor_button_flag = 0;
    digitalWrite(9, LOW);
    //Serial.println("Датчик стоплинии откалиброван");
  }
  //if {
  //if (millis() - timer1 > Programm1) {
  if (Serial1.available()) {
    int svet = Serial1.read();
    //Serial.println(svet);

    if (svet == 2) {
      drive(1800);
      delay(10);
    } else if (svet == 0) {
      drive(0);
      delay(10);

    }
  }
  // для большей точности установим значение LOW на пине Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Теперь установим высокий уровень на пине Trig
  digitalWrite(trigPin, HIGH);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(9, LOW);
  // Узнаем длительность высокого сигнала на пине Echo
  int cm = pulseIn(echoPin, HIGH);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  int cm_speed = 1520 + (cm / 58 - 7) * 2;
  drive(cm_speed);
  if (cm_speed > 1650) {
    drive(1650);
  }
  //timer1 = millis();
  //}
  //if (millis() - timer2 > Programm2) {
  int err = calibrate_line_sensor + (analogRead(SEN_1) - analogRead(SEN_2));
  //Serial.println(1520 - err);
  int u = 1520 + err;
  if (u > 2280) {
    u = 2280;
  }
  rudder.writeMicroseconds(u);
  delay(10);
  //timer2 = millis();
  //}
  //}
}

void drive(int speed) {
  motor.writeMicroseconds(speed);
}

