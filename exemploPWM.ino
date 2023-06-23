#define L1 10
#define L2 11

#define POT A0

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  pinMode(POT, INPUT);

  Serial.begin(115200);
}

void loop() {
  int valor = analogRead(POT);
  Serial.print("Pot: ");
  Serial.println(valor);

  int refPWM = map(valor, 0, 1023, 0, 255);

  Serial.print("PWM: ");
  Serial.println(refPWM);
  
  analogWrite(L1, refPWM);
  analogWrite(L2, refPWM);
  
  delay(500);
}
