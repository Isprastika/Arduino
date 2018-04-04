int pinLed = 5;
int pushBtn1 = 8;
int pushBtn2 = 9;

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(pushBtn1, INPUT_PULLUP);
  pinMode(pushBtn2, INPUT_PULLUP);  
}

void loop()
{
  if(digitalRead(pushBtn1) == LOW)
  {
    digitalWrite(pinLed, HIGH);  
  } 
  if(digitalRead(pushBtn2) == LOW)
  {
    digitalWrite(pinLed, LOW);  
  }
}
