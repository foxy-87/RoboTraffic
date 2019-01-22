void setup() {
  Serial.begin(9600); // говорим arduino что мы общаемся с ней на скорости 9600

}

void loop() {
  Serial.println(digitalRead(5)); // выводим в монитор порта значения с 5 пина arduino
    delay(10); // ждём 1 секунду

}
