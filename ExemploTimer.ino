#include "TimerOne.h"

#define L1 3
#define L2 4

int i;

void setup() {
  pinMode(L1, OUTPUT); 
  pinMode(L2, OUTPUT);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(executaTimer);
  i=0;
}

void loop() {
  // put your main code here, to run repeatedly:

}

void executaTimer(){
  /*switch(i){
    case 0:
      digitalWrite(L1, HIGH);
    break;
    case 1: 
      digitalWrite(L1, LOW);
    break;
    case 2:
      digitalWrite(L2, HIGH);
    break;
    case 3:
      digitalWrite(L2, LOW);
      i=-1;
    break;
  }*/
  if(i<2){
    digitalWrite(L1, !digitalRead(L1));
  }else{
    digitalWrite(L2, !digitalRead(L2));
  }
  if(i == 3)
    i = -1;
  
  i++;
}
