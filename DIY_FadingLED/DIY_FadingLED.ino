const int buttonPin = 2;//nomor pin buttonPin 2
const int ledPin = 9; //nomor pin LED 9
const int fadingDelay = 50;//kecepatan fading LED, makin besar nilainya makin lelet fadingnya

//variables will change
int buttonState = 0;
boolean fadingState = false;

void setup() {
  // put your setup code here, to run once:
  // Initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  //Initialize LED pin as asn input
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin); //baca nilai buttonPin

  //cek apakah button udah ditekan?
  if(buttonState == HIGH) {
    //cek status LED on/off?
    if(fadingState == false){
        //matikan LED
        for(int i = 0; i <= 255; i += 5){
            analogWrite(ledPin, i);
            delay(fadingDelay);
          }
      } else {
        //matikan LED
        for(int i = 255; i >= 0; i -= 5){
            analogWrite(ledPin, i);
            delay(fadingDelay);
          }
        }
        fadingState = !fadingState//menyimpan status LED (ON/OFF)
        
    }

}
