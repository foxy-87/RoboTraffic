// библиотека для работы с модулями I²C
#include <Wire.h>
// библиотека для работы cо сборкой датчиков линии
#include <Octoliner.h>
 
// создаём объект для работы с датчиками линии
Octoliner octoliner_left(44);
Octoliner octoliner_right(43);
 
void setup() {
  // открываем Serial-порт
  Serial.begin(115200);
  // начало работы с модулями I²C
  Wire.begin();
  // начало работы с датчиками линии
  octoliner_left.begin();
  octoliner_right.begin();
  // выставляем чувствительность фотоприёмников в диапазоне от 0 до 255
  octoliner_left.setSensitivity(200);
  octoliner_right.setSensitivity(200);
  // выставляем яркость свечения ИК-светодиодов в диапазоне от 0 до 255
  octoliner_left.setBrightness(255);
  octoliner_right.setBrightness(255);
}
 
void loop() {
  // массив для хранения показателей с датчиков линии
  int dataSensors_left[8];
  int dataSensors_right[8];
  // считываем значение с датчиков линии
  for (int i = 0; i < 8; i++) {
    // выводим значения в Serial-порт
    dataSensors_left[i] = octoliner_left.analogRead(i);
    Serial.print(octoliner_left.analogRead(i));
    Serial.print("\t");
  }
  int Left_sensor = octoliner_left.mapLine(dataSensors_left)*1000;
  //Left_sensor = map(Left_sensor, -1000, 1000, -1000, 0);
  //Left_sensor = Left_sensor/1000;
  Serial.println(Left_sensor);
  for (int i = 0; i < 8; i++) {
    // выводим значения в Serial-порт
    dataSensors_right[i] = octoliner_right.analogRead(i);
    Serial.print(octoliner_right.analogRead(i));
    Serial.print("\t");
  }
  int Right_sensor = octoliner_left.mapLine(dataSensors_left)*1000;
  Serial.println(Right_sensor);
  Serial.println();
  // ждём пол секунды
  delay(50);
} 
