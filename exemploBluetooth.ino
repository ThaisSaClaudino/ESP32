#include <SoftwareSerial.h>

SoftwareSerial bl(2,3);

#define L1 10
#define L2 11

void setup() {
  bl.begin(9600);
  Serial.begin(9600);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
}

void loop() {
  char dado;
  if(bl.available()){
    dado = bl.read();
    Serial.println(dado);  
  }

  switch(dado){
    case 'A':
      digitalWrite(L1, !digitalRead(L1));
    break;
    case 'B':
      digitalWrite(L2, !digitalRead(L2));
    break;
    case 'T':
      digitalWrite(L1, !digitalRead(L1));
      digitalWrite(L2, !digitalRead(L2));
    break;
  }
  
  delay(500);
}
