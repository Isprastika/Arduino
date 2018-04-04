#include <LiquidCrystal.h>
int led7 = 7;
int led6 = 6;
int led5 = 5;
int led4 = 4;
int led3 = 3;
int led2 = 2;
int led1 = 1;
int led0 = 0;
LiquidCrystal lcd (13,12,11,10,9,8);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(led0,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 int LDR1 = analogRead(A0);
 int temp = map(LDR1,0,1023,0,255);
 lcd.setCursor(0,0);
 lcd.print("ADC VALUE = ");
 lcd.setCursor(0,1);
 lcd.print(temp);
 delay(1000);
 lcd.clear();

 if(LDR1==0){
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
   
  } else if (LDR1>50){
    digitalWrite(led0, LOW);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    
    }
    else{
    digitalWrite(led0, LOW);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    
    }
}
