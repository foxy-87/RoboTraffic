#include <Servo.h> //подключаем библиотеку Servo
#include <NewPing.h> //подключаем библиотеку NewPing
#include <Wire.h> //подключаем библиотеку Wire
#include <Octoliner.h> //подключаем библиотеку Octoliner

Octoliner octoliner(42);

NewPing SONAR_REAR(TRIG_REAR, ECHO_REAR, MAXDISTANCE_REAR); //
NewPing SONAR_FRONT(TRIG_FRONT, ECHO_FRONT, MAXDISTANCE_FRONT); //
NewPing SONAR_LEFT(TRIG_LEFT, ECHO_LEFT, MAXDISTANCE_LEFT); //
NewPing SONAR_RIGHT(TRIG_RIGHT, ECHO_RIGHT, MAXDISTANCE_RIGHT); //


Servo motor; //подключаем драйвер двигателя
Servo rudder; //подключаем сервопривод поворота колёс

#define STOP_LINESENSOR 22 //
#define CENTRAL_LINESENSOR 23 //
#define LOWLEFT_LINESENSOR 24 //
#define LOWRIGHT_LINESENSOR 25 //
#define LEFT_LINESENSOR 26 //
#define RIGHT_LINESENSOR 27 //
#define HIGHLEFT_LINESENSOR 28 //
#define HIGHRIGHT_LINESENSOR 29 //
#define TRIG_REAR 5 //
#define ECHO_REAR 6 //
#define MAXDISTANCE_REAR 400 //
#define TRIG_FRONT 7 //
#define ECHO_FRONT 8 //
#define MAXDISTANCE_FRONT 400 //
#define TRIG_LEFT 9 //
#define ECHO_LEFT 26 //
#define MAXDISTANCE_LEFT 400 //
#define TRIG_RIGHT 12 //
#define ECHO_RIGHT 13 //
#define MAXDISTANCE_RIGHT 400 //

void setup() { //
  motor.attach(11); //
  rudder.attach(10); //
  Serial1.begin(115200); //
  Wire.begin();
  octoliner.begin();
  ocloliner.
  octoliner.
}
void LINE_RIDE(){ //
  if(LOWRIGHT_LINESENSOR == 1){ //
    rudder.writeMicroseconds(1688); //
  }else if(LOWLEFT_LINESENSOR == 1){ //
    rudder.writeMicroseconds(1351); //
  }else if(RIGHT_LINESENSOR == 1){ //
    rudder.writeMicroseconds(1984); //
  }else if(LEFT_LINESENSOR == 1){ //
    rudder.writeMicroseconds(1055.5); //
  }else if(HIGHRIGHT_LINESENSOR == 1){ //
    rudder.writeMicroseconds(2280); //
  }else if(HIGHLEFT_LINESENSOR == 1){ //
    rudder.writeMicroseconds(760); //
  }
}
void SIMAFOR(){ //
   if(Serial1.read() == 2){ //
    motor.writeMicroseconds(2280); //
   }else if(Serial1.read() == 3){ //
    motor.writeMicroseconds(2100); //
   }else if(Serial1.read() == 0){ //
    if(STOP_LINESENSOR == 1 or SONAR_FRONT.ping_cm() <= 40){ //
      motor.writeMicroseconds(1520); //
    }
   }else if(Serial1.read() == 1){ //
    motor.writeMicroseconds(1700); //
   }else if(Serial1.read() == 6){ //
    motor.writeMicroseconds(1520); //
    delay(500); //
    motor.writeMicroseconds(2280); //
   }
}
void LINE_RETURN(){ //
  if(LOWRIGHT_LINESENSOR == 0 and LOWLEFT_LINESENSOR == 0 and RIGHT_LINESENSOR == 0 and LEFT_LINESENSOR == 0 and HIGHRIGHT_LINESENSOR == 0 and HIGHLEFT_LINESENSOR == 0) { //
    if(SONAR_REAR.ping_cm() <= 40){ //
      motor.writeMicroseconds(1520); //
      delay(100); //
    }else{ //
      motor.writeMicroseconds(1000); //
    }
  }else{ //
    motor.writeMicroseconds(2100); //
  }
}
void PEDASTRIAN_CROSSING(){ //
  if(SONAR_FRONT.ping_cm() <= 40){ //
    motor.writeMicroseconds(1520); //
  }else{ //
    motor.writeMicroseconds(2280); //
  }
}
void loop() { //
  if (Serial1.available()){ //
    SIMAFOR; //
  }
  LINE_RIDE; //
  LINE_RETURN; //
  PEDASTRIAN_CROSSING; //
}
