#include <Wire.h>
#include <Octoliner.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

Servo servo1;
Servo servo2;

Octoliner octoliner_left(44);
Octoliner octoliner_right(43);

#define realy_pin 36;
#define turn_signalR 37;
#define turn_signalL 38;

void setup() {
  lcd.init();             
  lcd.backlight();
  Serial.begin(115200);
  Wire.begin();
  servo1.attach(11);
  servo2.attach(10);
  octoliner_left.begin();
  octoliner_right.begin();
  octoliner_left.setSensitivity(200);
  octoliner_right.setSensitivity(200);
  octoliner_left.setBrightness(255);
  octoliner_right.setBrightness(255);
  pinMode(realy_pin, OUTPUT);
  pinMode(turn_signalL, OUTPUT);
  pinMode(turn_signalR, OUTPUT);
}

void loop() {
  digitalWrite(realy_pin, HIGH);
  digitalWrite(turn_signalL, LOW);
  digitalWrite(turn_signalR, LOW);
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
  
  if(linesensor_1 > 3800){
    digitalWrite(turn_signalL, HIGH);
    servo1.write(35);
    servo2.write(105);
    lcd.setCursor(2,1);
    lcd.print("\1");
  }else if(linesensor_2 > 3800){
    servo1.write(48);
    servo2.write(105);
    lcd.setCursor(3,1);
    lcd.print("\2");
  }else if(linesensor_3 > 3800){
    servo1.write(48);
    servo2.write(105);
    lcd.setCursor(4,1);
    lcd.print("\3");
  }else if(linesensor_4 > 3800){
    servo1.write(62);
    servo2.write(105);
    lcd.setCursor(5,1);
    lcd.print("\4");
  }else if(linesensor_5 > 3800){
    servo1.write(62);
    servo2.write(105);
    lcd.setCursor(6,1);
    lcd.print("\5");
  }else if(linesensor_6 > 3800){
    servo1.write(76);
    servo2.write(105);
    lcd.setCursor(7,1);
    lcd.print("\6");
  }else if(linesensor_7 > 3800){
    servo1.write(76);
    servo2.write(105);
    lcd.setCursor(8,1);
    lcd.print("\7");
  }else if(linesensor_8 > 3800){
    servo1.write(90);
    servo2.write(105);
    lcd.setCursor(9,1);
    lcd.print("\8");
  }else if(linesensor_9 > 3800){
    servo1.write(90);
    servo2.write(105);
    lcd.setCursor(10,1);
    lcd.print("\9");
  }else if(linesensor_10 > 3800){
    servo1.write(103);
    servo2.write(105);
    lcd.setCursor(11,1);
    lcd.print("\10");
  }else if(linesensor_11 > 3800){
    servo1.write(103);
    servo2.write(105);
    lcd.setCursor(12,1);
    lcd.print("\11");
  }else if(linesensor_12 > 3800){
    servo1.write(117);
    servo2.write(105);
    lcd.setCursor(13,1);
    lcd.print("\12");
  }else if(linesensor_13 > 3800){
    servo1.write(117);
    servo2.write(105);
    lcd.setCursor(14,1);
    lcd.print("\13");
  }else if(linesensor_14 > 3800){
    servo1.write(131);
    servo2.write(105);
    lcd.setCursor(15,1);
    lcd.print("\14");
  }else if(linesensor_15 > 3800){
    servo1.write(131);
    servo2.write(105);
    lcd.setCursor(16,1);
    lcd.print("\15");
  }else if(linesensor_16 > 3800){
    digitalWrite(turn_signalR, HIGH);
    servo1.write(145);
    servo2.write(105);
    lcd.setCursor(17,1);
    lcd.print("\16");
  }else{
    digitalWrite(realy_pin, LOW);
    delay(50);
    digitalWrite(realy_pin, HIGH);
    servo1.write(90);
    servo2.write(105);
    lcd.setCursor(6,1);
    lcd.print("Go back");
  }
}
