
// include the Servo library
#include <Servo.h>

Servo myServo;  // create a servo object
Servo myServo1;
int const potPin = A0; // analog pin used to connect the potentiometer
int const potPin1 = A1;
int potVal;  // variable to read the value from the analog pin
int potVal1;
int angle;   // variable to hold the angle for the servo motor
int angle1;

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  myServo.attach(10);
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {
  potVal = analogRead(potPin); // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);
  
  // scale the numbers from the pot
  angle = map(potVal, 0, 1023, 0, 179);
  
  // print out the angle for the servo motor
  Serial.print(", angle: ");
  Serial.println(angle);
  
  // set the servo position
  myServo.write(angle);

  // wait for the servo to get there
  delay(15);
  
  potVal1 = analogRead(potPin1);
  // print out the value to the Serial Monitor
  Serial.print("potVal1: ");
  Serial.print(potVal1);

  angle1 = map(potVal1, 0, 1023, 0, 179);

  Serial.print(", angle1: ");
  Serial.println(angle1);

  myServo1.write(angle1);
  // wait for the servo to get there
  delay(15);
}
