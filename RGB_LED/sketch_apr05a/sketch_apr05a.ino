#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 4
#define delayTime 1000

int RED_LED = 6;
int BLUE_LED = 5;
int GREEN_LED = 4;
int led[] = {4, 5, 6};
int delayTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(BLUE_LED, LOW);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  myPwm(RED_LED);
  myPwm(BLUE_LED);
  myPwm(GREEN_LED);
}

void myPwm(int led)
{
  for(int i = 0; i < 255; i += 1)
  {
    analogWrite(led, i);
    delay(delayTime);  
  }

  for(int i = 254; i > 0; i -= 1)
  {
    analogWrite(led, i);
    delay(delayTime);  
  }
}
