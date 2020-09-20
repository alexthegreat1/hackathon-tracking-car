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

//This will run only one time.
void setup(){
 
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
    analogWrite(enableFrontLeft, 255);
    analogWrite(enableFrontRight, 255);
    analogWrite(enableBackLeft, 255);
    analogWrite(enableBackRight, 255);
  
}

void loop(){
  
  if(Serial.available() > 0) {
    
    char cmd = Serial.read();

    switch (cmd) {
      case 'w':
        startMoving();
        break;
      case 'd': // turn right in place
        turnRightUntilAligned();
        break;
      case 's':
        stopMoving();
        break;
      default:
        break;
    }
    
    if(cmd == 'g') {
      digitalWrite(frontLeftForward, HIGH);
      digitalWrite(frontLeftBackward, LOW);
      digitalWrite(frontRightForward, HIGH);
      digitalWrite(frontRightBackward, LOW);
      digitalWrite(backLeftForward, HIGH);
      digitalWrite(backLeftBackward, LOW);
      digitalWrite(backRightForward, HIGH);
      digitalWrite(backRightBackward, LOW);
      delay(5000);

      digitalWrite(frontLeftForward, HIGH);
      digitalWrite(frontLeftBackward, LOW);
      digitalWrite(frontRightForward, LOW);
      digitalWrite(frontRightBackward, HIGH);
      digitalWrite(backLeftForward, HIGH);
      digitalWrite(backLeftBackward, LOW);
      digitalWrite(backRightForward, LOW);
      digitalWrite(backRightBackward, HIGH);
      delay(5000);

      digitalWrite(frontLeftForward, LOW);
      digitalWrite(frontLeftBackward, LOW);
      digitalWrite(frontRightForward, LOW);
      digitalWrite(frontRightBackward, LOW);
      digitalWrite(backLeftForward, LOW);
      digitalWrite(backLeftBackward, LOW);
      digitalWrite(backRightForward, LOW);
      digitalWrite(backRightBackward, LOW);
    }
  }
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
  delay(3000);
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
