#define SEGA 5
#define SEGB 4
#define SEGC 9
#define SEGD 10
#define SEGE 11
#define SEGF 6
#define SEGG 7
#define SEGDP 8

#define B_UP 3
#define B_DOWN 2

#define SEGON LOW
#define SEGOFF HIGH
#define B_PRESSED LOW

void setup() {
  pinMode (B_UP, INPUT_PULLUP);
  pinMode (B_DOWN, INPUT_PULLUP);
  pinMode (SEGA, OUTPUT);
  pinMode (SEGB, OUTPUT);
  pinMode (SEGC, OUTPUT);
  pinMode (SEGD, OUTPUT);
  pinMode (SEGE, OUTPUT);
  pinMode (SEGF, OUTPUT);
  pinMode (SEGG, OUTPUT);
  pinMode (SEGDP, OUTPUT);
  init();
}

int nimi(){
  
}
void zero(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGON);
  digitalWrite(SEGE, SEGON);
  digitalWrite(SEGF, SEGON);
  digitalWrite(SEGG, SEGOFF);
  digitalWrite(SEGDP, SEGON);
}
void one(){
  digitalWrite(SEGA, SEGOFF);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGOFF);
  digitalWrite(SEGE, SEGOFF);
  digitalWrite(SEGF, SEGOFF);
  digitalWrite(SEGG, SEGOFF);
  digitalWrite(SEGDP, SEGON);
}
void two(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGOFF);
  digitalWrite(SEGD, SEGON);
  digitalWrite(SEGE, SEGON);
  digitalWrite(SEGF, SEGOFF);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void three(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGON);
  digitalWrite(SEGE, SEGOFF);
  digitalWrite(SEGF, SEGOFF);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void four(){
  digitalWrite(SEGA, SEGOFF);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGOFF);
  digitalWrite(SEGE, SEGOFF);
  digitalWrite(SEGF, SEGON);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void five(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGOFF);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGON);
  digitalWrite(SEGE, SEGOFF);
  digitalWrite(SEGF, SEGON);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void six(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGOFF);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGON);
  digitalWrite(SEGE, SEGON);
  digitalWrite(SEGF, SEGON);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void seven(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGOFF);
  digitalWrite(SEGE, SEGOFF);
  digitalWrite(SEGF, SEGOFF);
  digitalWrite(SEGG, SEGOFF);
  digitalWrite(SEGDP, SEGON);
}
void eight(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGON);
  digitalWrite(SEGE, SEGON);
  digitalWrite(SEGF, SEGON);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void nine(){
  digitalWrite(SEGA, SEGON);
  digitalWrite(SEGB, SEGON);
  digitalWrite(SEGC, SEGON);
  digitalWrite(SEGD, SEGOFF);
  digitalWrite(SEGE, SEGOFF);
  digitalWrite(SEGF, SEGON);
  digitalWrite(SEGG, SEGON);
  digitalWrite(SEGDP, SEGON);
}
void showNum(int x){
  switch(x){
    case 0:zero();break;
    case 1:one();break;
    case 2:two();break;
    case 3:three();break;
    case 4:four();break;
    case 5:five();break;
    case 6:six();break;
    case 7:seven();break;
    case 8:eight();break;
    case 9:nine();break;
  }
}

int count=0;
int  oldUp=-1, oldDown=-1;
#define FILTER 20

void loop() {
int in=digitalRead(B_UP);
if(in !=oldUp){
  if(in==B_PRESSED){
    count++;
  }
}
oldUp=in;
in=digitalRead(B_DOWN);
if(in !=oldDown){
  if(in==B_PRESSED){
    count--;
  }
}
oldDown=in;
delay(FILTER);
showNum(count);
}
