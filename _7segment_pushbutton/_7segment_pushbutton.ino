const int switchPin = 9;

int ledPin = (2,3,4,5,6,7,8);

// the debounce time; increase if the output flick
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

void setup() { pinMode(switchPin, INPUT); pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);

}boolean debounce(boolean last)

{
boolean current = digitalRead(switchPin);
if (last != current)
{
delay(5);
current = digitalRead(switchPin);
}
return current;
}

void loop() { currentButton = debounce(lastButton);
if (lastButton == LOW && currentButton == HIGH)
{
ledOn = !ledOn;
}
lastButton = currentButton;
digitalWrite(ledPin, ledOn); if(currentButton == HIGH){ // write 'show nothing'
digitalWrite(2, 1);
digitalWrite(3, 1);
digitalWrite(4, 1);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 1);
digitalWrite(8, 1);
delay(250); } else if(currentButton == LOW) { // write '9'
digitalWrite(2, 0);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 0);
digitalWrite(8, 0);
delay(1000);
// write '8'
digitalWrite(2, 0);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 0);
digitalWrite(8, 0);
delay(1000);
// write '7'
digitalWrite(2, 0);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 1);
digitalWrite(8, 1);
delay(1000);
// write '6'
digitalWrite(2, 0);
digitalWrite(3, 1);
digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 0);
digitalWrite(8, 0);
delay(1000);
// write '5'
digitalWrite(2, 0);
digitalWrite(3, 1);
digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 1);
digitalWrite(7, 0);
digitalWrite(8, 0);
delay(1000);
// write '4'
digitalWrite(2, 1);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 0);
digitalWrite(8, 0);
delay(1000);
// write '3'
digitalWrite(2, 0);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 1);
digitalWrite(7, 1);
digitalWrite(8, 0);
delay(1000);
// write '2'
digitalWrite(2, 0);
digitalWrite(3, 0);
digitalWrite(4, 1);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 1);
digitalWrite(8, 0);
delay(1000);
// write '1'
digitalWrite(2, 1);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 1);
digitalWrite(6, 1);
digitalWrite(7, 1);
digitalWrite(8, 1);
delay(1000);
// write '0'
digitalWrite(2, 0);
digitalWrite(3, 0);
digitalWrite(4, 0);
digitalWrite(5, 0);
digitalWrite(6, 0);
digitalWrite(7, 0);
digitalWrite(8, 1);
delay(2000);

}
}
