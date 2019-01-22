#include <QuadDisplay.h>
#define SENSOR_PIN1 A2
#define SENSOR_PIN2 A3
#define SEN_STOP A4
#define SEN_ik A0
#define DISPLAY_PIN1 6
#define DISPLAY_PIN2 5
void setup()
{
    Serial.begin(9600);
}
 
void loop()
{
  Serial.print(analogRead(SENSOR_PIN1));
  Serial.print(" , ");
  Serial.print(analogRead(SENSOR_PIN2));
  Serial.print(", ");
  Serial.print(analogRead(SEN_STOP));
  Serial.print(", ");
  Serial.println(analogRead(SEN_ik));
  delay(100);
    
}
