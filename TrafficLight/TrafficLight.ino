//Traffic Light

//Jumlah LED 3
const int Led = 3;
const int pinLed[Led] = {8, 9, 10};//3 variabel LED dijadikan 1 variabel
int Delay = 1000;//1 detik
const int pushButton = A0;//pasang ldr di pin 13
int Pencetan;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton, INPUT);
  digitalWrite(Pencetan, HIGH);
    for(int i = 0; i < 3; i++)
    {
        pinMode(pinLed[i], OUTPUT);
        delay(Delay);
    }
}

void loop() 
{
  
  if(digitalRead(Pencetan) == LOW)
  {
      for(int j = 0; j < 3; j++)
        {
          digitalWrite(pinLed[j], HIGH);
          delay(Delay);  
        }
  } else {
      for(int k = 0; k < 3; k++)
        {
          digitalWrite(pinLed[k], LOW);
          delay(Delay);
        }
     }
}


