#define red 4 //объявляем что 5 пин мы будем называть red
#define yellow 5 //объявляем что 4 пин мы будем называть yellow
#define green 3 //объявляем что 3 пин мы будем называть green

void setup() {
  Serial1.begin(115200); //объявляем что с Serial1(uart1) мы будем общаться на 115200 скорости
  Serial.begin(115200);
  pinMode(red, OUTPUT); //объявляем что пин red теперь работает в режиме выхода
  pinMode(yellow, OUTPUT); //объявляем что пин yellow теперь работает в режиме выхода
  pinMode(green, OUTPUT); //объявляем что пин green теперь работает в режиме выхода
}

void Simafor(){ //создаём функцию Simafor
  int simafor = Serial1.read(); //создаём переменную simafor типа int и считываем в неё всё что приходит с Serial1
  Serial.println(simafor);
  if(Serial1.available()){
   if(simafor == 0){
      digitalWrite(red, HIGH); //в случае если переменная simafor равна 0 то мы отправляем высокий сигнал(+5v) на пин red
     delay(50);
     digitalWrite(red, LOW);
   }else if(simafor == 1){
     digitalWrite(red, HIGH); //в случае если переменная simafor равна 1 то мы отправляем высокий сигнал(+5v) на пин red
     digitalWrite(yellow, HIGH); //в случае если переменная simafor равна 1 то мы отправляем высокий сигнал(+5v) на пин yellow
     delay(50);
     digitalWrite(red, LOW);
     digitalWrite(yellow, LOW);
   }else if(simafor == 4){
     digitalWrite(yellow, HIGH); //в случае если переменная simafor равна 4 то мы отправляем высокий сигнал(+5v) на пин yellow
     delay(50);
      digitalWrite(yellow, LOW);
    }else if(simafor == 2){
      digitalWrite(green, HIGH); //в случае если переменная simafor равна 2 то мы отправляем высокий сигнал(+5v) на пин green
      delay(50);
      digitalWrite(green, LOW);
    }else if(simafor == 3){
      digitalWrite(green, HIGH); //в случае если переменная simafor равна 3 то мы отправляем высокий сигнал(+5v) на пин green
      delay(50);
      digitalWrite(green, LOW); //в случае если переменная simafor равна 3 то мы отправляем низкий сигнал(0v) на пин green
      delay(50);
    }else{
      digitalWrite(green, HIGH); //если не один из вышеперечисленных случаев неподашёл то мы отправляем высокий сигнал(+5v) на пин green
      digitalWrite(yellow, HIGH); //если не один из вышеперечисленных случаев неподашёл то мы отправляем высокий сигнал(+5v) на пин yellow
      digitalWrite(red, HIGH); //если не один из вышеперечисленных случаев неподашёл то мы отправляем высокий сигнал(+5v) на пин red
      delay(50);
      digitalWrite(green, LOW); //мы отправляем низкий(0v) сигнал на пин green 
      digitalWrite(yellow, LOW); //мы отправляем низкий(0v) сигнал на пин green
      digitalWrite(red, LOW); //мы отправляем низкий(0v) сигнал на пин green
      delay(50);
    }
    delay(50);
  }
}

void loop() {
    Simafor(); //если пришёл сигнал с Serial1 то мы запускаем функцию Simafor
}
