const int frontTrigPin = 2;
const int frontEchoPin = 3;
const int rightTrigPin = 4;
const int rightEchoPin = 5;
long duration;

void setup() {
  pinMode(frontTrigPin, OUTPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available() > 0) {
    char cmd = Serial.read();
    if(cmd == 'f') {
      Serial.println(getFrontDist());
    }

    if(cmd == 'r') {
      Serial.println(getRightDist());
    }
    
    if(cmd == 's') {
      float val = 30.00;
      Serial.println(val);
      delay(100);
    }
  }
  delayMicroseconds(2);
}

double getFrontDist() {
  return getDist(frontTrigPin, frontEchoPin);
//  delayMicroseconds(2);
}

double getRightDist() {
  return getDist(rightTrigPin, rightEchoPin);
//  delayMicroseconds(2);
}

double getDist(const int trigPin, const int echoPin) {
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
  return distance;
}

const double microsecondsToDistance(const long microseconds) {
// Initialize m and b to their respective values in the formula, y = mx + b.
// y = distance, x = time (in microseconds).
const double m = 0.01723722479;
const double b = -0.2604487142;
return m * microseconds + b;
}
