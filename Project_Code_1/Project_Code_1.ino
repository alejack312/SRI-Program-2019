
// include the Servo library
#include <Servo.h>

Servo myServo;  // create a servo object
Servo myServo1;
Servo myServo2;
Servo myServo3;
int const potPin = A0; // analog pin used to connect the potentiometer
int const potPin1 = A1;
int const potPin2 = A2;
int const potPin3 = A3;
int potVal;  // variable to read the value from the analog pin
int potVal1;
int potVal2;
int potVal3;
int angle;   // variable to hold the angle for the servo motor
int angle1;
int angle2;
int angle3;


void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  myServo1.attach(10);
  myServo2.attach(11);
  myServo3.attach(12);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600); // open a serial connection to your computer
 
}

void loop() {
  potVal = analogRead(potPin); // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);

  potVal1 = analogRead(potPin1);
  // print out the value to the Serial Monitor
  Serial.print("potVal1: ");
  Serial.print(potVal1);

  potVal2 = analogRead(potPin2); // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal2: ");
  Serial.print(potVal2);
  
  potVal3 = analogRead(potPin3); // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal3: ");
  Serial.print(potVal3);

  // scale the numbers from the pot
  angle = map(potVal, 0, 1023, 0, 179);
  angle1 = map(potVal1, 0, 1023, 0, 179);
  angle2 = map(potVal2, 0, 1023, 0, 179);
  angle3 = map(potVal3, 0, 1023, 0, 179);

  // print out the angle for the servo motor
  Serial.print(", angle: ");
  Serial.println(angle);

  Serial.print(", angle1: ");
  Serial.println(angle1);

  Serial.print(", angle2: ");
  Serial.println(angle2);

  Serial.print(", angle3: ");
  Serial.println(angle3);

  // set the servo position
  digitalWrite(9, HIGH);
  myServo.write(angle);
  //digitalWrite(9, LOW);
  
  digitalWrite(10, HIGH);
  myServo1.write(angle1);
  //digitalWrite(10, LOW);
  
  digitalWrite(11, HIGH);
  myServo2.write(angle2);
  //digitalWrite(11, LOW);
   
  digitalWrite(12, HIGH);
  myServo3.write(angle3);
  //digitalWrite(12, LOW);
  // wait for the servo to get there
  
}
