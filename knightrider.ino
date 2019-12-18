#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10
#define LED5 9

void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

int v = 50;

void loop(){
  
   digitalWrite(LED1, LOW);
   delay(v);
   digitalWrite(LED1, HIGH);
   delay(v);
   digitalWrite(LED2, LOW);
   delay(v);
   digitalWrite(LED2, HIGH);
   delay(v);
   digitalWrite(LED3, LOW);
   delay(v);
   digitalWrite(LED3, HIGH);
   delay(v);
   digitalWrite(LED4, LOW);
   delay(v);
   digitalWrite(LED4, HIGH);
   delay(v);
   digitalWrite(LED5, LOW);
   delay(v);
   digitalWrite(LED5, HIGH);
   delay(v);
   digitalWrite(LED4, LOW);
   delay(v);
   digitalWrite(LED4, HIGH);
   delay(v);
   digitalWrite(LED3, LOW);
   delay(v);
   digitalWrite(LED3, HIGH);
   delay(v);
   digitalWrite(LED2, LOW);
   delay(v);   
   digitalWrite(LED2, HIGH);
   delay(v);
     
}
