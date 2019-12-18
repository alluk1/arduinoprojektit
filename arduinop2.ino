#include "fikkari.h"

fikkari T1(5, 6);//Luodaan ilmentymä meidän luokasta
fikkari T2(9, 10);
fikkari T3(3, 11);
void setup(){
}
void loop(){
  T1.handle();
  T2.handle();
  T3.handle();
}
