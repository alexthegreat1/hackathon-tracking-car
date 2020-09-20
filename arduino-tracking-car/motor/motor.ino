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
  
    //Motor Control - Motor A: frontLeftForward,frontLeftBackward & Motor B: frontRightForward,frontRightBackward

    //This code  will turn Motor A clockwise for 2 sec.
//    digitalWrite(frontLeftForward, HIGH);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000); 
//    //This code will turn Motor A counter-clockwise for 2 sec.
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, HIGH);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000);
//    
//    //This code will turn Motor B clockwise for 2 sec.
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, HIGH);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000); 
//    //This code will turn Motor B counter-clockwise for 2 sec.
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, HIGH);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000);
//
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, HIGH);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000);
//
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, HIGH);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000);
//
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, HIGH);
//    digitalWrite(backRightBackward, LOW);
//    delay(2000);
//
//    digitalWrite(frontLeftForward, LOW);
//    digitalWrite(frontLeftBackward, LOW);
//    digitalWrite(frontRightForward, LOW);
//    digitalWrite(frontRightBackward, LOW);
//    digitalWrite(backLeftForward, LOW);
//    digitalWrite(backLeftBackward, LOW);
//    digitalWrite(backRightForward, LOW);
//    digitalWrite(backRightBackward, HIGH);
//    delay(2000);
    
    //And this code will stop motors
    digitalWrite(frontLeftForward, LOW);
    digitalWrite(frontLeftBackward, LOW);
    digitalWrite(frontRightForward, LOW);
    digitalWrite(frontRightBackward, LOW);
    digitalWrite(backLeftForward, LOW);
    digitalWrite(backLeftBackward, LOW);
    digitalWrite(backRightForward, LOW);
    digitalWrite(backRightBackward, LOW);
  
}

void loop(){
  
  if(Serial.available() > 0) {
    char cmd = Serial.read();
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
