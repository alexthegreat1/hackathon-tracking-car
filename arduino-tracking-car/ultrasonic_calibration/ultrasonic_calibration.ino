/**
 * The digital pin that receives input from the ultrasonic sensor.
*/
const int trigPin = 2;
/**
 * The digital pin that sends output to the ultrasonic sensor.
*/
const int echoPin = 3;
void setup() {
  pinMode(echoPin, INPUT);  // Register echoPin for receiving input
  pinMode(trigPin, OUTPUT);  // Register trigPin for sending output
  Serial.begin(9600);  // Begin serial communication to receive data from the ultrasonic sensor
}
void loop() {
  // Send a short low pulse to ensure a clean high one.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Send a ten-second high pulse.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the high pulse and print out its duration.
  const long duration = pulseIn(echoPin, HIGH);
  Serial.print("Period (microseconds): ");
  Serial.println(duration);
}
