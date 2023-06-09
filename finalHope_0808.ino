/*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
//#define TURN_TIME 2000

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

int switch1 = 3;
//int label1 = 0
//int label2 = 1;

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
  average = total / numReadings;// send it to the computer as ASCII digits

  if (average < 110) {
    average = 80;
  }

  mapVal = map(average, 80, 132, 0, 180);
  Serial.print(", average: ");
  Serial.print(average);

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
  if (average2 < 110) {
    average2 = 80;
  }

  mapVal2 = map(average2, 80, 180, 0, 180);
  Serial.print(",   average2: ");
  Serial.print(average2);

  myServo2.write(mapVal2);
  delay(1);

  total3 = total3 - readings3[readIndex3];
  readings3[readIndex3] = analogRead(potPin3);
  total3 = total3 + readings3[readIndex3];
  readIndex3 = readIndex3 + 1;

  if (readIndex3 >= numReadings3) {
    readIndex3 = 0;
  }

  average3 = total3 / numReadings3;
  if (average3 < 110) {
    average3 = 80;
  }

  mapVal3 = map(average3, 80, 190, 0, 180);
  Serial.print(",  average3: ");
  Serial.print(average3);

  myServo3.write(mapVal3);
  delay(1);

  total4 = total4 - readings4[readIndex4];
  readings4[readIndex4] = analogRead(potPin4);
  total4 = total4 + readings4[readIndex4];
  readIndex4 = readIndex4 + 1;

  if (readIndex4 >= numReadings4) {   //this is for capping high values for the servo so it doesn't go crazy
    readIndex4 = 0;
  }

  average4 = total4 / numReadings4;
  if (average4 <= 110) {
    myServo4.write(0);
  }

  if (average4 >= 120) {
    myServo4.write(180);
  }
  
  if (average4 > 111 && (average4 < 119)) {
    myServo4.write(90);
  }
  Serial.print(",   average4: ");
  Serial.println(average4);
  //Serial.println;
  /*mapVal4 = map(average4, 80, 120, 0, 172);
  Serial.print(",   average4: ");
  Serial.print(average4);
  Serial.print(", angle4: ");
  Serial.println(mapVal4);

  myServo4.write(average4);
  delay(1);
*/
  /* switch (switch1) {
    case 1:
    if (switch1 != 1) {
      if (average4 = 120) {
        myServo4.write(180);
        delay(TURN_TIME);
        myServo4.write(90);
        switch1 = 1;
      }
    }
      break;
    case 2:
    if (switch1 != 0) {
      if (average4 = 80) {
        myServo4.write(0);
        delay(TURN_TIME);
        myServo4.write(90);
        switch1 = 0;
      }
    }
      break;
    default:
      myServo4.write(90);
      break;
    }
    }

    if (switch1 != 1) {
    if (average4 = 120) {
      myServo4.write(180);
      delay(TURN_TIME);
      myServo4.write(90);
      switch1 = 1;
    }
    }
    else if (switch1 != 0) {
    if (average4 = 80) {
      myServo4.write(0);
      delay(TURN_TIME);
      myServo4.write(90);
      switch1 = 0;
    }
    }
  */
}
