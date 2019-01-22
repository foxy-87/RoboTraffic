// Моторы подключаются к клеммам M1+, M1-, M2+, M2-
// Motor shield использует четыре контакта 4, 5, 6, 7 для управления моторами 
// 4 и 7 — для направления, 5 и 6 — для скорости
#define SPEED_2      6
#define DIR_2        7
#define SPEED_1      4
#define DIR_1        5
 
void setup() 
{
    // Настраивает выводы платы 4, 5, 6, 7 на вывод сигналов 
    for(int i = 4; i < 8; i++)     
        pinMode(i, OUTPUT);  
} 
 
void loop() 
{ 
  // Для коллекторного мотора можно выбрать значение скорости от 0 до 255.
  // Покрутим в течении секунды M1 на средней скорости сначала в одну сторону...
  analogWrite(SPEED_2, 255);
  digitalWrite(DIR_2, LOW);
  analogWrite(SPEED_1, 255);
  digitalWrite(DIR_1, LOW);
  delay(10);
  }
