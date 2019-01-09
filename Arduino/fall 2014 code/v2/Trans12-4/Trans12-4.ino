void setup() {
  Serial.begin(9600);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
}

void loop() {
  
  delay(800); // prevents confused information 
  
  // fwd/rev
    
        if (digitalRead(12) == HIGH) {
        Serial.print('F');
      }
      if (digitalRead(11) == HIGH) {
        Serial.print('R');
      }
      if(digitalRead(11) == LOW && digitalRead(12) == LOW){
        Serial.print('S'); 
      }
            
   // servo 
   
    if (digitalRead(8) == HIGH) {
        Serial.print('H');
      }
      else if (digitalRead(8) == LOW) {
        Serial.print('L');
      }  
}
