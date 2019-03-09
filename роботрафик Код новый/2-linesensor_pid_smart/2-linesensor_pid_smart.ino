#include <Wire.h>
#include <Octoliner.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

Servo rudder;
Servo motor;

Octoliner octoliner_left(43);
Octoliner octoliner_right(44);

#define turn_signalR 7
#define turn_signalL 6

int angel = 1300;
int speed = 1520;

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
  
  speed = 1300;

  /*ёint  = -1;
  int  = -1;
  for (int i = 0; i < 8; i++) {
    if (linesensor_right[i] > 3800) {
       = i;
      break;
    }
  }for (int i = 0; i < 8; i++) {
    if (linesensor_left[i] > 3800) {
       = i;
      break;
    }
  }*/
  if(linesensor_left[7] > 600){
    angel = 1300;
    speed = 1615;
    lcd.setCursor(9,1);
    lcd.print("\8");
  }else if(linesensor_right[0] > 950){
    angel = 1300;
    speed = 1615;
    lcd.setCursor(10,1);
    lcd.print("\9");
  }else if(linesensor_left[6] > 600){
    angel = 1065;
    speed = 1615;
    lcd.setCursor(8,1);
    lcd.print("\7");
  }else if(linesensor_right[1] > 950){
    angel = 1487;
    speed = 1615;
    lcd.setCursor(11,1);
    lcd.print("\10");
  }else if(linesensor_left[5] > 600){
    angel = 1065;
    speed = 1615;
    lcd.setCursor(7,1);
    lcd.print("\6");
  }else if(linesensor_right[2] > 950){
    angel = 1487;
    speed = 1615;
    lcd.setCursor(12,1);
    lcd.print("\11");
  }else if(linesensor_left[4] > 600){
    angel = 830; 
    speed = 1615;
    lcd.setCursor(6,1);
    lcd.print("\5");
  }else if(linesensor_right[3] > 950){
    angel = 1689;
    speed = 1615;
    lcd.setCursor(13,1);
    lcd.print("\12");
  }else if ((linesensor_right[0] > 950 or linesensor_right[1] > 950 or linesensor_right[2] > 950 or linesensor_right[3] > 950 or linesensor_right[4] > 950 or linesensor_right[5] > 950 or linesensor_right[6] > 950 or linesensor_right[7] > 950)and(linesensor_left[0] > 600 or linesensor_left[1] > 600 or linesensor_left[2] > 600 or linesensor_left[3] > 600 or linesensor_left[4] > 600)){
    angel = 2094;
    speed = 1615;
    lcd.setCursor(6,1);
    lcd.print("left");
  }else if(linesensor_left[3] > 600){
    angel = 830;
    speed = 1615;
    lcd.setCursor(5,1);
    lcd.print("\4");
  }else if(linesensor_right[4] > 950){
    angel = 1689;
    speed = 1615;
    lcd.setCursor(14,1);
    lcd.print("\13");
  }else if(linesensor_left[2] > 600){
    digitalWrite(turn_signalL, HIGH);
    angel = 595;
    speed = 1615;
    lcd.setCursor(4,1);
    lcd.print("\3");
  }else if(linesensor_right[5] > 950){
    digitalWrite(turn_signalR, HIGH);
    angel = 1892;
    speed = 1615;
    lcd.setCursor(15,1);
    lcd.print("\14");
  }else if(linesensor_left[1] > 600){
    digitalWrite(turn_signalL, HIGH);
    angel = 595;
    speed = 1615;
    lcd.setCursor(3,1);
    lcd.print("\2");
  }else if(linesensor_right[6] > 950){
    digitalWrite(turn_signalR, HIGH);
    angel = 1892;
    speed = 1615;
    lcd.setCursor(16,1);
    lcd.print("\15");
  }else if(linesensor_left[0] > 600){
    digitalWrite(turn_signalL, HIGH);
    angel = 361;
    speed = 1615;
    lcd.setCursor(2,1);
    lcd.print("\1");
  }else if(linesensor_right[7] > 950){
    digitalWrite(turn_signalR, HIGH);
    angel = 2094;
    speed = 1615;
    lcd.setCursor(17,1);
    lcd.print("\16");
  }else{
      angel = 1300;
      speed = 1520;
      speed = 591;
      lcd.setCursor(6,1);
      lcd.print("Go back");
  }
  //delay(100);
}
  
void loop() {
  lineride();
  rudder.writeMicroseconds(angel);
  motor.writeMicroseconds(speed);
}
