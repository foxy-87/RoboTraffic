

void setup() {
  Serial.begin(9600);
  Serial2.begin(115200);

}

void loop() {
  if (Serial2.available()) {

    Serial.println(Serial2.read());

  } else {
    Serial.println("no");
  }

}
