char Incoming_value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    float val = 30.00;
    char cmd = Serial.read();
    if(cmd == 's') {
      Serial.println(val);
      delay(100);
    }
  }
}
