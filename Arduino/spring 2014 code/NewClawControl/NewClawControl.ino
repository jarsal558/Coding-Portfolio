#include <Servo.h>
Servo claw;
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  claw.attach(11);
  // initialize the servo output
  
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn the servo or motor:
    if (incomingByte == 'H') {
      claw.write(180);
    } 
    // if it's an L (ASCII 76) turn the servo or motor back
    if (incomingByte == 'L') {
      claw.write(0);
    }
  }
}
