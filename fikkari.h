#ifndef FIKKARI_H
#define FIKKARI_H

#include <Arduino.h>


#define LEDON 255
#define LEDOFF 0
#define TASO1 150
#define TASO2 60
#define FILTER 20

class fikkari{
  public:
  fikkari(int P, int L); //Konstruktori
  void handle();
  private:
  bool buttonPressed();
  void changeState();  
  int _oldState;//Painikkeen tilojen seurantaa varten
  int _valaistusTaso = LEDOFF;
  int _P, _L;//Liitännät
};


#endif FIKKARI_H
