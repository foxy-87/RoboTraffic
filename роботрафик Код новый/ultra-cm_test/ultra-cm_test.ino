#include <NewPing.h> //подключение библиотеки NewPing
 
#define TRIGGER_PIN  48 //подключение 10 пина к переменной TRIGGER_PIN
#define ECHO_PIN     46 //подключение 11 пина к переменной ECHO_PIN
#define MAX_DISTANCE 400 //кладём в переменную MAX_DISTANCE значение 400 
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //говорим библиотеке NewPing что пин TRIGGER подключен к 10 пину, а пин ECHO подключен к 11 и говорим что максимальное расстояние 400
 
void setup() {
  Serial.begin(9600); // говорим arduino что мы с ней будем общаться на скорости 9600
}
 
void loop() {
  delay(50); // ждём 50 милисекунд
  Serial.print("Ping: "); // выводим в монитор порта надпись Ping: 
  Serial.print(sonar.ping_cm());// выводим в монитор порта расстояние в сантиметрах
  Serial.println("cm"); // выводим в монитор порта надпись cm
}
