void setup()
{
  /*initializes pins*/
  Serial.begin(9600);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
}

void loop()
{
  /*button commands*/
  if(digitalRead(4))
  {
    Serial.print('H');
  }
  if(digitalRead(5))
  {
    Serial.print('L');
  }
}
