#include <Servo.h> // подключаем библиотеку для работы с сервоприводом
 
Servo servo1; // объявляем переменную servo1 типа servo

void setup(){
servo1.attach(11); // объявляем что servo1 привязанна к пину 11
}

void loop(){

servo1.writeMicroseconds(1300); // ставим угол поворота под 90 градусов
}
