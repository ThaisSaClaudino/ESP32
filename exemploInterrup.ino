#include "TimerOne.h"

#define BOTAO 2

#define L1 3
#define L2 4

int i;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(BOTAO), funcao, FALLING);

  i=0;
}

void loop() {
  if(i == 1){
    digitalWrite(L1, !digitalRead(L1));
  }else if(i == 2){
    digitalWrite(L2, !digitalRead(L2));
    i=0;
  }
  

}

void funcao(){
  i++;
  Serial.println(i);
  //delay(600);
}
