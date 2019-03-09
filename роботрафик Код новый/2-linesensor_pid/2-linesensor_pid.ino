#include <Wire.h>
#include <Octoliner.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

Servo rudder;
Servo motor;

Octoliner octoliner_left(43);
Octoliner octoliner_right(44);

#define turn_signalR 6
#define turn_signalL 5

int angel = 90;
int speed = 90;
int turnL = 600;
int turnR = 950;

void setup() {
  lcd.init();             
  lcd.backlight();
  Serial.begin(115200);
  Wire.begin();
  rudder.attach(11);
  motor.attach(10);
  octoliner_left.begin();
  octoliner_right.begin();
  octoliner_left.setSensitivity(200);
  octoliner_right.setSensitivity(200);
  octoliner_left.setBrightness(255);
  octoliner_right.setBrightness(255);
  pinMode(turn_signalL, OUTPUT);
  pinMode(turn_signalR, OUTPUT);
}

int lineride(){
  digitalWrite(turn_signalL, LOW);
  digitalWrite(turn_signalR, LOW);
  
  int linesensor_left[8];
  int linesensor_right[8];
  for (int i = 0; i < 8; i++) {
      linesensor_left[i] = octoliner_left.analogRead(i);
  }for (int i = 0; i < 8; i++) {
      linesensor_right[i] = octoliner_right.analogRead(i);
  }

  lcd.clear();
  if(linesensor_left[7] > turnL){
    angel = 90;
    speed = 105;
    lcd.setCursor(9,1);
    lcd.print("\8");
  }else if(linesensor_right[0] > turnR){
    angel = 90;
    speed = 105;
    lcd.setCursor(10,1);
    lcd.print("\9");
  }else if(linesensor_left[1] > turnL){
    angel = 48;
    speed = 105;
    lcd.setCursor(3,1);
    lcd.print("\2");
  }else if(linesensor_left[2] > turnL){
    angel = 48;
    speed = 105;
    lcd.setCursor(4,1);
    lcd.print("\3");
  }else if(linesensor_left[3] > turnL){
    angel = 62;
    speed = 105;
    lcd.setCursor(5,1);
    lcd.print("\4");
  }else if(linesensor_left[4] > turnL){
    angel = 62;
    speed = 105;
    lcd.setCursor(6,1);
    lcd.print("\5");
  }else if(linesensor_left[5] > turnL){
    angel = 76;
    speed = 105;
    lcd.setCursor(7,1);
    lcd.print("\6");
  }else if(linesensor_left[6] > turnL){
    angel = 76;
    speed = 105;
    lcd.setCursor(8,1);
    lcd.print("\7");
  }else if(linesensor_right[1] > turnR){
    angel = 103;
    speed = 105;
    lcd.setCursor(11,1);
    lcd.print("\10");
  }else if(linesensor_right[2] > turnR){
    angel = 103;
    speed = 105;
    lcd.setCursor(12,1);
    lcd.print("\11");
  }else if(linesensor_right[3] > turnR){
    angel = 117;
    speed = 105;
    lcd.setCursor(13,1);
    lcd.print("\12");
  }else if(linesensor_right[4] > turnR){
    angel = 117;
    speed = 105;
    lcd.setCursor(14,1);
    lcd.print("\13");
  }else if(linesensor_right[5] > turnR){
    angel = 131;
    speed = 105;
    lcd.setCursor(15,1);
    lcd.print("\14");
  }else if(linesensor_right[6] > turnR){
    angel = 131;
    speed = 105;
    lcd.setCursor(16,1);
    lcd.print("\15");
  }else if(linesensor_left[0] > turnL){
    digitalWrite(turn_signalL, HIGH);
    angel = 35;
    speed = 105;
    lcd.setCursor(2,1);
    lcd.print("\1");
  }else if(linesensor_right[7] > turnR){
    digitalWrite(turn_signalR, HIGH);
    angel = 145;
    speed = 105;
    lcd.setCursor(17,1);
    lcd.print("\16");
  }else{
    angel = 90;
    speed = 0;
    delay(100);
    speed = 90;
    delay(100);
    speed = 35;
    lcd.setCursor(6,1);
    lcd.print("Go back");
  }
}

void loop() {
  lineride();
  rudder.write(angel);
  motor.write(speed);
}
