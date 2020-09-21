const int frontTrigPin = 2;
const int frontEchoPin = 3;
const int rightTrigPin = 4;
const int rightEchoPin = 5;
const int leftTrigPin = 6;
const int leftEchoPin = 7;
long duration;

//L293D
//enable 
const int enableFrontLeft = 10;
const int enableFrontRight = 11;
const int enableBackLeft = 12;
const int enableBackRight = 13;

//Motor A
const int frontLeftForward  = 22;  // Pin 14 of L293
const int frontLeftBackward  = 23;  // Pin 10 of L293
//Motor B
const int frontRightForward  = 24; // Pin  7 of L293
const int frontRightBackward  = 25;  // Pin  2 of L293
//Motor C
const int backLeftForward = 26;
const int backLeftBackward = 27;
//Motor D
const int backRightForward = 28;
const int backRightBackward = 29;

void setup() {
  pinMode(frontTrigPin, OUTPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  pinMode(leftTrigPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  Serial.begin(9600);

  //Set pins as outputs
  pinMode(enableFrontLeft, OUTPUT);
  pinMode(enableFrontRight, OUTPUT);
  pinMode(enableBackLeft, OUTPUT);
  pinMode(enableBackRight, OUTPUT);
  pinMode(frontLeftForward, OUTPUT);
  pinMode(frontLeftBackward, OUTPUT);
  pinMode(frontRightForward, OUTPUT);
  pinMode(frontRightBackward, OUTPUT);
  pinMode(backLeftForward, OUTPUT);
  pinMode(backLeftBackward, OUTPUT);
  pinMode(backRightForward, OUTPUT);
  pinMode(backRightBackward, OUTPUT);
    
  //enable
  //this should change the speeds of the wheels
  //note: setting a speed of 200 on 1 wheel may not be the same as 200 on another wheel
  analogWrite(enableFrontLeft, 200);
  analogWrite(enableFrontRight, 200);
  analogWrite(enableBackLeft, 200);
  analogWrite(enableBackRight, 200);
}

void loop() {
  
  if(Serial.available() > 0) {
    
    char cmd = Serial.read();
    
    switch (cmd) {
      case 'f':
        Serial.println(getFrontDist());
        break;
      case 'r':
        Serial.println(getRightDist());
        break;
      case 'l':
        Serial.println(getLeftDist());
        break;
      case 'w':
        startMoving();
        break;
      case 'd': // turn right in place
        turnRightUntilAligned();
        break;
      case 's':
        stopMoving();
        break;
      case 't':
        Serial.println(isGoingStraight());
        break;
      default:
        break;
    }
  }
  delayMicroseconds(2);

//  Serial.print("F: ");
//  Serial.println(getFrontDist());
//  Serial.print("R: ");
//  Serial.println(getRightDist());
//  delay(1000);
}

void startMoving() {
  digitalWrite(frontLeftForward, HIGH);
  digitalWrite(frontLeftBackward, LOW);
  digitalWrite(frontRightForward, HIGH);
  digitalWrite(frontRightBackward, LOW);
  digitalWrite(backLeftForward, HIGH);
  digitalWrite(backLeftBackward, LOW);
  digitalWrite(backRightForward, HIGH);
  digitalWrite(backRightBackward, LOW);
}

void stopMoving() {
  digitalWrite(frontLeftForward, LOW);
  digitalWrite(frontLeftBackward, LOW);
  digitalWrite(frontRightForward, LOW);
  digitalWrite(frontRightBackward, LOW);
  digitalWrite(backLeftForward, LOW);
  digitalWrite(backLeftBackward, LOW);
  digitalWrite(backRightForward, LOW);
  digitalWrite(backRightBackward, LOW);
}

// complete this. gyro, ultrasonic, etc.
void turnRightUntilAligned() {
  turnRightInPlace();
  // 2000 might be good for 255 motors, 4000 is untested for 200 motors
  delay(2700);
//  delay(3000);
  stopMoving();
}

void turnRightInPlace() {
  digitalWrite(frontLeftForward, HIGH);
  digitalWrite(frontLeftBackward, LOW);
  digitalWrite(frontRightForward, LOW);
  digitalWrite(frontRightBackward, HIGH);
  digitalWrite(backLeftForward, HIGH);
  digitalWrite(backLeftBackward, LOW);
  digitalWrite(backRightForward, LOW);
  digitalWrite(backRightBackward, HIGH);
}

double getFrontDist() {
  return getDist(frontTrigPin, frontEchoPin);
//  delayMicroseconds(2);
}

double getRightDist() {
  return getDist(rightTrigPin, rightEchoPin);
//  delayMicroseconds(2);
}

double getLeftDist() {
  return getDist(leftTrigPin, leftEchoPin);
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

bool isGoingStraight() {
  if (digitalRead(frontLeftForward) == HIGH
    && digitalRead(frontLeftBackward) == LOW
    && digitalRead(frontRightForward) == HIGH
    && digitalRead(frontRightBackward) == LOW
    && digitalRead(backLeftForward) == HIGH
    && digitalRead(backLeftBackward) == LOW
    && digitalRead(backRightForward) == HIGH
    && digitalRead(backRightBackward) == LOW) {
      return true;
    }
  else return false;
}

const double microsecondsToDistance(const long microseconds) {
  // Initialize m and b to their respective values in the formula, y = mx + b.
  // y = distance, x = time (in microseconds).
  const double m = 0.01723722479;
  const double b = -0.2604487142;
  return m * microseconds + b;
}
