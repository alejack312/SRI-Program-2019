/*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myServo;  // create servo object to control a servo
Servo myServo2;
Servo myServo3;
Servo myServo4;

int potPin = A5;  // analog pin used to connect the potentiometer
int potPin2 = A4;
int potPin3 = A3;
int potPin4 = A2;
int mapVal;
int mapVal2;
int mapVal3;
int mapVal4;
//int val; // variable to read the value from the analog pin
//int val2;
//int val3;
//int val4;

const int numReadings = 10;
const int numReadings2 = 10;
const int numReadings3 = 10;
const int numReadings4 = 10;

int readings[numReadings];      // the readings from the analog input
int readings2[numReadings2];
int readings3[numReadings3];
int readings4[numReadings4];

int readIndex = 0;              // the index of the current reading
int readIndex2 = 0;
int readIndex3 = 0;
int readIndex4 = 0;

int total = 0;                  // the running total
int total2 = 0;
int total3 = 0;
int total4 = 0;

int average = 0;                // the average
int average2 = 0;
int average3 = 0;
int average4 = 0;  

void setup() {
  myServo.attach(2);  // attaches the servo on pin 9 to the servo object
  myServo2.attach(3);
  myServo3.attach(4);
  myServo4.attach(5);
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  for (int thisReading2 = 0; thisReading2 < numReadings2; thisReading2++) {
    readings2[thisReading2] = 0;
  }
  for (int thisReading3 = 0; thisReading3 < numReadings3; thisReading3++) {
    readings3[thisReading3] = 0;
  }
  for (int thisReading4 = 0; thisReading4 < numReadings4; thisReading4++) {
    readings4[thisReading4] = 0;
  }
}
void loop() {
  /*
    val = analogRead(potPin);            // reads the value of the potentiometer (value between 0 and 1023)
    mapVal = map(val, 79, 132, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myServo.write(mapVal);                  // sets the servo position according to the scaled value 
    val2 = analogRead(potPin2);            // reads the value of the potentiometer (value between 0 and 1023)
    mapVal2 = map(val2, 79, 167, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myServo2.write(mapVal2);                  // sets the servo position according to the scaled value
    val3 = analogRead(potPin3);            // reads the value of the potentiometer (value between 0 and 1023)
    mapVal3 = map(val3, 71, 210, 0, 180 );    // scale it to use it with the servo (value between 0 and 180)
    myServo3.write(mapVal3);                  // sets the servo position according to the scaled value
    val4 = analogRead(potPin4);            // reads the value of the potentiometer (value between 0 and 1023)
    mapVal4 = map(val4, 79, 180 , 0, 180 );    // scale it to use it with the servo (value between 0 and 180)
    myServo4.write(mapVal4);                   // sets the servo position according to the scaled value

    Serial.print("   angle thumb:");                // print value name
    Serial.print(mapVal);                    // print value
    Serial.print("   serial thumb:");         // print serial name
    Serial.println(val);

    //Serial.print("   angle index:");
    //Serial.print(mapVal2);
    //Serial.print("   serial index:");
    //Serial.print(val2);
    //Serial.print("   angle middle:");
    //Serial.print(mapVal3);
    //Serial.print("   serial middle:");
    //Serial.print(val3);
    //Serial.print("   angle ring:");
    //Serial.print(mapVal4);
    //Serial.print("   serial ring:");
    //Serial.println(val4);


    delay(15);
  */

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(potPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  mapVal = map(average, 79, 132, 0, 180);
  Serial.print(", average: ");
  Serial.println(average);

  myServo.write(mapVal);
  delay(1);        // delay in between reads for stability

  total2 = total2 - readings2[readIndex2];
  readings2[readIndex2] = analogRead(potPin2);
  total2 = total2 + readings2[readIndex2];
  readIndex2 = readIndex2 + 1;

  if (readIndex2 >= numReadings2) {
    readIndex2 = 0;
  }

  average2 = total2 / numReadings2;
  mapVal2 = map(average2, 79, 132, 0, 180);
  Serial.print(", average2: ");
  Serial.println(average2);

  myServo.write(mapVal2);
  delay(1);

  total3 = total3 - readings3[readIndex3];
  readings3[readIndex3] = analogRead(potPin3);
  total3 = total3 + readings3[readIndex3];
  readIndex3 = readIndex3 + 1;

  if (readIndex3 >= numReadings3) {
    readIndex3 = 0;
  }

  average3 = total3 / numReadings3;
  mapVal3 = map(average3, 79, 132, 0, 180);
  Serial.print(", average3: ");
  Serial.println(average3);

  myServo.write(mapVal3);
  delay(1);

  total4 = total4 - readings4[readIndex4];
  readings4[readIndex4] = analogRead(potPin4);
  total4 = total4 + readings4[readIndex4];
  readIndex4 = readIndex4 + 1;

  if (readIndex4 >= numReadings4) {
    readIndex4 = 0;
  }

  average4 = total4 / numReadings4;
  mapVal4 = map(average4, 79, 132, 0, 180);
  Serial.print(", average4: ");
  Serial.println(average4);

  myServo.write(mapVal4);
  delay(1);
}
