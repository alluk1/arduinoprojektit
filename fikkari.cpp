#include <Arduino.h>
#include "fikkari.h"

/*
 * Konstruktori
 * P - parametri painikkeen liitäntää varten
 * L - parametri ledin liitäntä varten
 */
 fikkari::fikkari(int P, int L){
  _P=P;
  _L=L;  
  pinMode(_L, OUTPUT);
  pinMode(_P, INPUT_PULLUP);
  _oldState = digitalRead(_P);//Alustetaan "muistijälki"
  analogWrite(_L, _valaistusTaso);
 }

bool fikkari::buttonPressed(){
  bool retVal = false;
  int x = digitalRead(_P);
  if(x == LOW && _oldState == HIGH){//Etsitään painikkeen painallus
    retVal = true;
  }
  _oldState = x;
  delay(FILTER);
  return retVal;
}

void fikkari::changeState(){
      switch(_valaistusTaso){
      case LEDOFF:_valaistusTaso=LEDON;break;
      case LEDON:_valaistusTaso=TASO1;break;
      case TASO1:_valaistusTaso=TASO2;break;
      case TASO2:_valaistusTaso=LEDOFF;break;
        }
  analogWrite(_L, _valaistusTaso);
}

void fikkari::handle(){
    if(buttonPressed()){
    changeState();
  }
}
