// библиотека для работы с модулями I²C
#include <Wire.h>
#include <Servo.h>
// библиотека для работы cо сборкой датчиков линии
#include <Octoliner.h>
 
// создаём объект для работы с датчиками линии
Octoliner octoliner(42);
Servo servo1; 
void setup() {
  // открываем Serial-порт
  Serial.begin(115200);
  // начало работы с модулями I²C
  Wire.begin();
  servo1.attach(11);
  // начало работы с датчиками линии
  octoliner.begin();
  // выставляем чувствительность фотоприёмников в диапазоне от 0 до 255
  octoliner.setSensitivity(200);
  // выставляем яркость свечения ИК-светодиодов в диапазоне от 0 до 255
  octoliner.setBrightness(255);
 
}
 
void loop() {
  int black_line = 3800;
  int linesensor_1 = octoliner.analogRead(0);
  int linesensor_2 = octoliner.analogRead(1);
  int linesensor_3 = octoliner.analogRead(2);
  int linesensor_4 = octoliner.analogRead(3);
  int linesensor_5 = octoliner.analogRead(4);
  int linesensor_6 = octoliner.analogRead(5);
  int linesensor_7 = octoliner.analogRead(6);
  int linesensor_8 = octoliner.analogRead(7);

  if(linesensor_1 > black_line){
    servo1.write(45);
  }else if(linesensor_2 > black_line){
    servo1.write(67);
  }else if(linesensor_3 > black_line){
    servo1.write(67);
  }else if(linesensor_4 > black_line){
    servo1.write(90);
  }else if(linesensor_5 > black_line){
    servo1.write(90);
  }else if(linesensor_6 > black_line){
    servo1.write(112);
  }else if(linesensor_7 > black_line){
    servo1.write(112);
  }else if(linesensor_8 > black_line){
    servo1.write(135);
  }
}
