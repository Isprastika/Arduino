//dual 7 segment display 
//with button

// Segments that make each number when lit:
// 0 => -FEDCBA
// 1 => ----BC-
// 2 => G-ED-BA
// 3 => G--DCBA
// 4 => GF--CB-
// 5 => GF-DC-A
// 6 => GFEDC-A
// 7 => ----CBA
// 8 => GFEDCBA
// 9 => GF-DCBA
// Arduino digital pins used to light up
// corresponding segments on the LED display
#define A 3
#define B 2
#define C 6
#define D 8
#define E 7
#define F_SEG 4
#define G 5
// Pushbuttons connected to pins 9 and 10
#define BTN1 9
#define BTN2 10
// Pins driving common anodes
#define CA1 13
#define CA2 12
// Pins for A B C D E F G, in sequence
const int segs[7] = { A, B, C, D, E, F_SEG, G };
// Segments that make each number
const byte numbers[10] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0000010, 0b1111000, 0b0000000,0b0010000};
int digit1 = 0;
int digit2 = 0;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F_SEG, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);  
}



void loop() {
// check button1
int val1 = digitalRead(BTN1);
if (val1 == HIGH) {
digit1++;
digit1 %= 10;
delay(10);
} // check button2
int val2 = digitalRead(BTN2);
if (val2 == HIGH) {
digit2++;
digit2 %= 10;
delay(10);
} // display number
unsigned long startTime = millis();
for (unsigned long elapsed=0; elapsed < 600; elapsed = millis() - startTime) {
lightDigit1(numbers[digit1]);
delay(5);
lightDigit2(numbers[digit2]);
delay(5);
}
} 
void lightDigit1(byte number) {
digitalWrite(CA1, LOW);
digitalWrite(CA2, HIGH);
lightSegments(number);
} 

void lightDigit2(byte number) {
digitalWrite(CA1, HIGH);
digitalWrite(CA2, LOW);
lightSegments(number);
} 
void lightSegments(byte number) {
for (int i = 0; i < 7; i++) {
int bit = bitRead(number, i);
digitalWrite(segs[i], bit);
}
}


