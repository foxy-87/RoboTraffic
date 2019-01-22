#include <Wire.h>
#include <Octoliner.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

Servo servo1;

Octoliner octoliner_left(44);
Octoliner octoliner_right(43);
  
//const int blackline_calibration = 9;

byte lcd1[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd2[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd3[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd4[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd5[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd6[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd7[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd8[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd9[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd10[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd11[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd12[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd13[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd14[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd15[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
byte lcd16[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
 
void setup() {
  lcd.init();             
  lcd.backlight();
  //pinMode(blackline_calibration, INPUT);
  Serial.begin(115200);
  Wire.begin();
  servo1.attach(11);
  octoliner_left.begin();
  octoliner_right.begin();
  octoliner_left.setSensitivity(200);
  octoliner_right.setSensitivity(200);
  octoliner_left.setBrightness(255);
  octoliner_right.setBrightness(255);
}
/*void calibration(){
  int black_line = 0;
  int left_black = 0;
  int right_black = 0;
  for (int i = 0; i < 8; i++) {
    left_black = octoliner_left.analogRead(i);
    right_black = octoliner_right.analogRead(i);
    black_line = left_black + right_black;
  }
  black_line = black_line / 8;
  lcd.setCursor(5,1);
  lcd.print("calibration");
  lcd.setCursor(6,2);
  lcd.print("complite");
}

void line_ride(){
  lcd.createChar(1, lcd1);
  lcd.createChar(2, lcd2);
  lcd.createChar(3, lcd3);
  lcd.createChar(4, lcd4);
  lcd.createChar(5, lcd5);
  lcd.createChar(6, lcd6);
  lcd.createChar(7, lcd7);
  lcd.createChar(8, lcd8);
  lcd.createChar(9, lcd9);
  lcd.createChar(10, lcd10);
  lcd.createChar(11, lcd11);
  lcd.createChar(12, lcd12);
  lcd.createChar(13, lcd13);
  lcd.createChar(14, lcd14);
  lcd.createChar(15, lcd15);
  lcd.createChar(16, lcd16);
  
  int black_line = 3800;
  int linesensor_1 = octoliner_left.analogRead(0);
  int linesensor_2 = octoliner_left.analogRead(1);
  int linesensor_3 = octoliner_left.analogRead(2);
  int linesensor_4 = octoliner_left.analogRead(3);
  int linesensor_5 = octoliner_left.analogRead(4);
  int linesensor_6 = octoliner_left.analogRead(5);
  int linesensor_7 = octoliner_left.analogRead(6);
  int linesensor_8 = octoliner_left.analogRead(7);
  int linesensor_9 = octoliner_right.analogRead(0);
  int linesensor_10 = octoliner_right.analogRead(1);
  int linesensor_11 = octoliner_right.analogRead(2);
  int linesensor_12 = octoliner_right.analogRead(3);
  int linesensor_13 = octoliner_right.analogRead(4);
  int linesensor_14 = octoliner_right.analogRead(5);
  int linesensor_15 = octoliner_right.analogRead(6);
  int linesensor_16 = octoliner_right.analogRead(7);
  
  if(linesensor_1 > black_line){
    servo1.write(45);
    lcd.setCursor(2,1);
    lcd.print("\1");
  }else if(linesensor_2 > black_line){
    servo1.write(56);
    lcd.setCursor(3,1);
    lcd.print("\2");
  }else if(linesensor_3 > black_line){
    servo1.write(56);
    lcd.setCursor(4,1);
    lcd.print("\3");
  }else if(linesensor_4 > black_line){
    servo1.write(67);
    lcd.setCursor(5,1);
    lcd.print("\4");
  }else if(linesensor_5 > black_line){
    servo1.write(67);
    lcd.setCursor(6,1);
    lcd.print("\5");
  }else if(linesensor_6 > black_line){
    servo1.write(78);
    lcd.setCursor(7,1);
    lcd.print("\6");
  }else if(linesensor_7 > black_line){
    servo1.write(78);
    lcd.setCursor(8,1);
    lcd.print("\7");
  }else if(linesensor_8 > black_line){
    servo1.write(90);
    lcd.setCursor(9,1);
    lcd.print("\8");
  }else if(linesensor_9 > black_line){
    servo1.write(90);
    lcd.setCursor(10,1);
    lcd.print("\9");
  }else if(linesensor_10 > black_line){
    servo1.write(101);
    lcd.setCursor(11,1);
    lcd.print("\10");
  }else if(linesensor_11 > black_line){
    servo1.write(101);
    lcd.setCursor(12,1);
    lcd.print("\11");
  }else if(linesensor_12 > black_line){
    servo1.write(112);
    lcd.setCursor(13,1);
    lcd.print("\12");
  }else if(linesensor_13 > black_line){
    servo1.write(112);
    lcd.setCursor(14,1);
    lcd.print("\13");
  }else if(linesensor_14 > black_line){
    servo1.write(123);
    lcd.setCursor(15,1);
    lcd.print("\14");
  }else if(linesensor_15 > black_line){
    servo1.write(123);
    lcd.setCursor(16,1);
    lcd.print("\15");
  }else if(linesensor_16 > black_line){
    servo1.write(135);
    lcd.setCursor(17,1);
    lcd.print("\16");
  }
}*/
 
void loop() {
  lcd.createChar(1, lcd1);
  lcd.createChar(2, lcd2);
  lcd.createChar(3, lcd3);
  lcd.createChar(4, lcd4);
  lcd.createChar(5, lcd5);
  lcd.createChar(6, lcd6);
  lcd.createChar(7, lcd7);
  lcd.createChar(8, lcd8);
  lcd.createChar(9, lcd9);
  lcd.createChar(10, lcd10);
  lcd.createChar(11, lcd11);
  lcd.createChar(12, lcd12);
  lcd.createChar(13, lcd13);
  lcd.createChar(14, lcd14);
  lcd.createChar(15, lcd15);
  lcd.createChar(16, lcd16);
  
  int black_line = 3800;
  int linesensor_1 = octoliner_left.analogRead(0);
  int linesensor_2 = octoliner_left.analogRead(1);
  int linesensor_3 = octoliner_left.analogRead(2);
  int linesensor_4 = octoliner_left.analogRead(3);
  int linesensor_5 = octoliner_left.analogRead(4);
  int linesensor_6 = octoliner_left.analogRead(5);
  int linesensor_7 = octoliner_left.analogRead(6);
  int linesensor_8 = octoliner_left.analogRead(7);
  int linesensor_9 = octoliner_right.analogRead(0);
  int linesensor_10 = octoliner_right.analogRead(1);
  int linesensor_11 = octoliner_right.analogRead(2);
  int linesensor_12 = octoliner_right.analogRead(3);
  int linesensor_13 = octoliner_right.analogRead(4);
  int linesensor_14 = octoliner_right.analogRead(5);
  int linesensor_15 = octoliner_right.analogRead(6);
  int linesensor_16 = octoliner_right.analogRead(7);

  lcd.clear();
  
  if(linesensor_1 > black_line){
    servo1.write(45);
    lcd.setCursor(2,1);
    lcd.print("\1");
  }else if(linesensor_2 > black_line){
    servo1.write(56);
    lcd.setCursor(3,1);
    lcd.print("\2");
  }else if(linesensor_3 > black_line){
    servo1.write(56);
    lcd.setCursor(4,1);
    lcd.print("\3");
  }else if(linesensor_4 > black_line){
    servo1.write(67);
    lcd.setCursor(5,1);
    lcd.print("\4");
  }else if(linesensor_5 > black_line){
    servo1.write(67);
    lcd.setCursor(6,1);
    lcd.print("\5");
  }else if(linesensor_6 > black_line){
    servo1.write(78);
    lcd.setCursor(7,1);
    lcd.print("\6");
  }else if(linesensor_7 > black_line){
    servo1.write(78);
    lcd.setCursor(8,1);
    lcd.print("\7");
  }else if(linesensor_8 > black_line){
    servo1.write(90);
    lcd.setCursor(9,1);
    lcd.print("\8");
  }else if(linesensor_9 > black_line){
    servo1.write(90);
    lcd.setCursor(10,1);
    lcd.print("\9");
  }else if(linesensor_10 > black_line){
    servo1.write(101);
    lcd.setCursor(11,1);
    lcd.print("\10");
  }else if(linesensor_11 > black_line){
    servo1.write(101);
    lcd.setCursor(12,1);
    lcd.print("\11");
  }else if(linesensor_12 > black_line){
    servo1.write(112);
    lcd.setCursor(13,1);
    lcd.print("\12");
  }else if(linesensor_13 > black_line){
    servo1.write(112);
    lcd.setCursor(14,1);
    lcd.print("\13");
  }else if(linesensor_14 > black_line){
    servo1.write(123);
    lcd.setCursor(15,1);
    lcd.print("\14");
  }else if(linesensor_15 > black_line){
    servo1.write(123);
    lcd.setCursor(16,1);
    lcd.print("\15");
  }else if(linesensor_16 > black_line){
    servo1.write(135);
    lcd.setCursor(17,1);
    lcd.print("\16");
  }
  /*bool blackline_calibration = digitalRead(blackline_calibration);
  if(blackline_calibration == 1){
    calibration();
    //black_line = calibration();  
  }else if(blackline_calibration == 0){
    line_ride();
  }*/
} 
