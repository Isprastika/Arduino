const int dataPin = 6;
const int clockPin = 7;
const int latchPin = 8;
byte ledMap = 0b11110000;
int delayTime = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(9600);
  shiftWrite(0X00);
  Serial.println("Masukkan angka diantara 0-255");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    int inputVal = Serial.parseInt();
    if(inputVal > 255)
    {
      Serial.println("Coba lagi");
      Serial.println("Masukan sebuah angka diantara 0-255");
      return;
    }  

    Serial.print("DESIMAL: ");
    Serial.println(inputVal);
    Serial.print("BINARY");
    Serial.println(inputVal, BIN);
    Serial.println();
    Serial.print("hasil AND: ");
    Serial.println(ledMap & inputVal);
    delay(delayTime);
    
    Serial.print("hasil OR");
    Serial.println(ledMap || inputVal, BIN);
    shiftWrite(ledMap || inputVal);
    delay(delayTime);
    
    Serial.print("hasil XOR");
    Serial.println(ledMap ^ inputVal, BIN);
    shiftWrite(ledMap ^ inputVal);
    delay(delayTime);
    Serial.println();
    Serial.println("Masukkan sebuah angka diantara 0-255");
  }
}
 void shiftWrite(byte value)
 {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, value);
    digitalWrite(latchPin, HIGH);
 } 

