//Тестировалось на Arduino IDE 1.0.5
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);   /* Задаем адрес и размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */

byte smile[8] =
{
  B00010,
  B00001,
  B11001,
  B00001,
  B11001,
  B00001,
  B00010,
};     

void setup()
{
  lcd.init();                            // Инициализация lcd             
  lcd.backlight();                       // Включаем подсветку
  // Курсор находится в начале 1 строки
  lcd.setCursor(0, 0);
  lcd.print("Hello world");            // Выводим текст
  lcd.createChar(1, smile);
  lcd.setCursor(0, 1);
  lcd.print("\1");
  lcd.setCursor(4, 2);                   // Устанавливаем курсор в начало 2 строки
  lcd.print("robotraffic test");              // Выводим текст
  delay(1000);
  /*while(true){
    lcd.print("\1");
  }*/
}

void loop()
{
}
