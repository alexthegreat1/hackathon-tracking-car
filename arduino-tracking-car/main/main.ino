const int trigPin = 2;
const int echoPin = 3;
long duration;

void setup() {
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

double getDist() {
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//  double distance = (double)duration * 100 * 345 / 2 / 1000000;
//  delayMicroseconds(2);
//  return distance;
// Send a short low pulse to ensure a clean high one.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Send a ten-second high pulse.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Store the high pulse's duration.
  const long duration = pulseIn(echoPin, HIGH);
  // Calculate and print the distance to the target.
  const double distance = microsecondsToDistance(duration);
//  Serial.print("Distance: ");
//  Serial.println(distance);
  return distance;
}

const double microsecondsToDistance(const long microseconds) {
// Initialize m and b to their respective values in the formula, y = mx + b.
// y = distance, x = time (in microseconds).
const double m = 0.01723722479;
const double b = -0.2604487142;
return m * microseconds + b;
}
