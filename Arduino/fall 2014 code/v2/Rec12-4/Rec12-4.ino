 #include <Servo.h>
Servo claw;
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  claw.attach(9);
  // initialize the servo output
  
  pinMode(12, OUTPUT); //Initiates Motor Channel Direction
  pinMode(11, OUTPUT); // Speed
  
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn the servo or motor:
    if (incomingByte == 'H') {
      claw.write(0);
    } 
    // if it's an L (ASCII 76) turn the servo or motor back
    if (incomingByte == 'L') {
      claw.write(90);
    }
    if (incomingByte == 'F') {
      
       digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  
  analogWrite(11, 1023);   //Spins the motor on Channel A at full speed
  
      
      
    }
    if (incomingByte == 'R') {
      
      
        digitalWrite(12, LOW); //Establishes backward direction of Channel A
  analogWrite(11, 1023);   //Spins the motor on Channel A at half speed
      
    }
    
      if (incomingByte == 'S') {
      
        digitalWrite(12, LOW); //Establishes backward direction of Channel A
  analogWrite(11, 0);   //Spins the motor on Channel A at half speed
      
    }
  }
}
