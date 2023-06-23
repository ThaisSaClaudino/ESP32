#define POT A0

void setup() {
  pinMode(POT, INPUT);

  Serial.begin(115200);
}

void loop() {
  int valor = analogRead(POT);

  Serial.println(valor);
  delay(500);
}
