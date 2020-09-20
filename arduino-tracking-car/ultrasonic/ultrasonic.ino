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
// Store the high pulse's duration.
const long duration = pulseIn(echoPin, HIGH);
// Calculate and print the distance to the target.
const double distance = microsecondsToDistance(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
}
/**
 * @param microseconds a number of microseconds
 * @return the conversion of the provided microseconds into a distance
*/
const double microsecondsToDistance(const long microseconds) {
// Initialize m and b to their respective values in the formula, y = mx + b.
// y = distance, x = time (in microseconds).
const double m = 0.01723722479;
const double b = -0.2604487142;
return m * microseconds + b;
}
