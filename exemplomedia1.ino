#include <Adafruit_LiquidCrystal.h>

#define L1 4
#define L2 5
#define L3 6
#define L4 7

Adafruit_LiquidCrystal lcd_1(0);

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  
  lcd_1.begin(16, 2);
  lcd_1.print("IFSC SE");
  
  Serial.begin(115200);
}

void loop() {
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Informe Valor:");
  while(Serial.available() == 0){}
  int valor = Serial.parseInt();
  lcd_1.setCursor(0,1);
  lcd_1.print(valor);
  
  if(valor <= 10){
    digitalWrite(L1, HIGH);
  }else if(valor > 10 && valor <= 20){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
  }else if(valor > 20 && valor <= 30){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
  }
  
  delay(2000);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);  
}