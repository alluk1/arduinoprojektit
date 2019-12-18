#define LED1 6
#define LEDON LOW
#define LEDOFF HIGH
#define TOGGLE 5
#define PRESS LOW
int Led1State = LEDON;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(TOGGLE, INPUT);
  digitalWrite(LED1, Led1State);
  
  Serial.begin(9600);
}

void loop() {
  
int t = digitalRead(TOGGLE);
    if(t == PRESS){
      if(Led1State == LEDON){
        Led1State = LEDOFF;
      }else{
        Led1State = LEDON;
      }
      digitalWrite(LED1, Led1State);
    }
    delay(300);
}
