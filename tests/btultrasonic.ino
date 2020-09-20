const int trigPin = 2;
const int echoPin = 3;
long duration;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  if(Serial.available() > 0) {
    char cmd = Serial.read();
    if(cmd == 'd') {
      Serial.println(getDist());
    }
    
    if(cmd == 's') {
      float val = 30.00;
      Serial.println(val);
      delay(100);
    }
  }
  delayMicroseconds(2);
}

long getDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long cm = pulseIn(echoPin, HIGH) * 345 / 2 / 10000;
  delay(100);
  return cm;
}