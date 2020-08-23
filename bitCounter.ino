const int lsbPin = 13;
const int buttonPin = 3;

void setup() {
  pinMode(buttonPin, INPUT);
 
  for(int i = lsbPin; i >= 6; i--) {
     pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  for(int count = 0; count < 256; count++) {
      int temp = count;
      for(int i = lsbPin; i >= 6; i--) {
        digitalWrite(i, temp & 1 == 1 ? HIGH : LOW);
        temp = temp >> 1;
      }
      delay(200);
      int reading = digitalRead(buttonPin);
      if(reading == 1) break;
  }
  for(int i = lsbPin; i >= 6; i--) {
    digitalWrite(i, LOW);
  }  
}
