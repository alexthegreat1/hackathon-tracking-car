//L293D
//enable 
const int enableA = 4;
const int enableB = 5;
const int enableC = 10;
const int enableD = 11;

//Motor A
const int motorPin1  = 6;  // Pin 14 of L293
const int motorPin2  = 7;  // Pin 10 of L293
//Motor B
const int motorPin3  = 8; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293
//Motor C
const int motorPin5 = 12;
const int motorPin6 = 13;
//Motor D
const int motorPin7 = 22;
const int motorPin8 = 23;

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(enableA, OUTPUT);
    pinMode(enableB, OUTPUT);
    pinMode(enableC, OUTPUT);
    pinMode(enableD, OUTPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    pinMode(motorPin6, OUTPUT);
    pinMode(motorPin7, OUTPUT);
    pinMode(motorPin8, OUTPUT);
    
    //enable
//this should change the speeds of the wheels
//note: setting a speed of 200 on 1 wheel may not be the same as 200 on another wheel
    analogWrite(enableA, 200);
    analogWrite(enableB, 200);
    analogWrite(enableC, 200);
    analogWrite(enableD, 200);
  
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(2000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(2000);
    
    //This code will turn Motor B clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(2000); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(2000);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, HIGH);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(2000);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, HIGH);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
    delay(2000);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, HIGH);
    digitalWrite(motorPin8, LOW);
    delay(2000);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, HIGH);
    delay(2000);
    
    //And this code will stop motors
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, LOW);
  
}

void loop(){
  

}
