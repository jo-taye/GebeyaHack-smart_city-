/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int servo1_trigPin = 9;
const int servo1_echoPin = 10;

const int servo2_trigPin = 12; 
const int servo2_echoPin = 11;



// defines variables
long servo1_duration;
int servo1_distance;

long servo2_duration; 
int servo2_distance; 



void setup() {
  pinMode(servo1_trigPin, OUTPUT); // Sets the servo1_trigPin as an Output
  pinMode(servo1_echoPin, INPUT); // Sets the servo1_echoPin as an Input

  pinMode(servo2_trigPin, OUTPUT); // Sets the servo1_trigPin as an Output
  pinMode(servo2_echoPin, INPUT); // Sets the servo1_echoPin as an Input
  
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the servo1_trigPin
  digitalWrite(servo1_trigPin, LOW);
  digitalWrite(servo2_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the servo1_trigPin on HIGH state for 10 micro seconds
  digitalWrite(servo1_trigPin, HIGH);
  digitalWrite(servo2_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(servo1_trigPin, LOW);
  digitalWrite(servo2_trigPin, LOW);
  // Reads the servo1_echoPin, returns the sound wave travel time in microseconds
  servo1_duration = pulseIn(servo1_echoPin, HIGH);
  servo2_duration = pulseIn(servo2_echoPin, HIGH);
  
  // Calculating the servo1_distance
  servo1_distance= servo1_duration*0.034/2;
  servo2_distance= servo2_duration*0.034/2;
  
  // Prints the servo1_distance on the Serial Monitor
  Serial.print("servo1_distance: ");
  Serial.println(servo1_distance);

  Serial.print("servo2_distance: ");
  Serial.println(servo2_distance);
}
