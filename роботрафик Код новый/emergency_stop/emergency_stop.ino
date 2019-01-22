#define stop_signal 2
#define left_turn_signal 3
#define right_turn_signal 4

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(stop_signal, OUTPUT);
  pinMode(left_turn_signal, OUTPUT);
  pinMode(right_turn_signal, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(stop_signal, HIGH);
  digitalWrite(left_turn_signal, HIGH);
  digitalWrite(right_turn_signal, HIGH);// turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(left_turn_signal, LOW); 
  digitalWrite(right_turn_signal, LOW);// turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
