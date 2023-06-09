
#include <Servo.h>

Servo myServo;

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int const inputPin = A0;
int pot1 = 0;
int potVal = 0;
int angle;


void setup() {
  myServo.attach(2);
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
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
  angle = map(average, 0, 1023, 0, 179);
  Serial.print(", average: ");
  Serial.println(average);


  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);

  delay(1);        // delay in between reads for stability

}
