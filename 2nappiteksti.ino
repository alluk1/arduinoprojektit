#define LED1 6
#define LEDON LOW
#define LEDOFF HIGH
#define TOGGLE 5
#define PRESS LOW
#define NAPPI 3

int Led1State = LEDON;
int butOldState;
int tOldState;
int newState;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(TOGGLE, INPUT);
  pinMode(NAPPI, INPUT_PULLUP);
  digitalWrite(LED1, Led1State);
  Serial.begin(9600);
  butOldState = digitalRead(NAPPI);
  tOldState = digitalRead(TOGGLE);
}

void loop() {

int x = digitalRead(TOGGLE);
    if(x == PRESS){
      if(Led1State == LEDON){
        Led1State = LEDOFF;
      }else{
        Led1State = LEDON;
      }
      digitalWrite(LED1, Led1State);
      delay(50);
    }
   
    int butNewState = digitalRead(NAPPI);
    if(butNewState != butOldState){
      if(butNewState == PRESS){
      Serial.println("o/");
    }
    }
  tOldState=newState;
  newState = digitalRead(TOGGLE);
  if(newState != tOldState){
    if(newState == PRESS){
      Serial.println("\\o/");
      if(Led1State==LEDON){
        Led1State=LEDOFF;
      }else{
        Led1State=LEDON;
      }
      digitalWrite(LED1, Led1State);
    }
  }
   delay(35);
  butOldState=butNewState;
}
