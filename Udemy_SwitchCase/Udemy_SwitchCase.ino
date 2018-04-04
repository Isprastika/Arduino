//definisi pin pemutar resistansi pot
int potPin = A0;

//tentukan variabel global
int lastPotValue;

void setup() {
  // set pin Mode
  pinMode(potPin, INPUT);
  //memulai Serial port
  Serial.begin(9600);
}

void loop() {
  // baca potPin dan bagi dengan 255 untuk beri keungkinan dibaca
  int potValue = analogRead(potPin) / 255;//karena 1024 dibagi 255, dapet 5 kemungkinan

  //jika sesuatu berubah sejak nilai terakhir
  if(potValue != lastPotValue)
  {
    //masukkan swich case
    switch(potValue){
    case 0:
      Serial.println("Sangat rendah"); 
      break;
    case 1:
      Serial.println("Rendah");
      break; 
    case 2:
      Serial.println("Biasa");
      break;
    case 3:
      Serial.println("Tinggi");
      break;
    case 4:
      Serial.println("Sangat tinggi");
      break;
    default:
      Serial.println("ERROR");
      break;
    }
  }
  lastPotValue = potValue;
}
