// Kirjastot
#include <Servo.h>

// Ohjelman tilakone
int state;
#define ST_IDLE 0
#define ST_OPEN 1
#define ST_WAIT 2
#define ST_CLOSE 3

// Mittalaitteen käyttöönotto
#define TRIG_PIN 12
#define ECHO_PIN 13

// Servon käyttöönotto
#define SERVO 2
#define LID_CLOSE 110
#define LID_OPEN 0

// LED
#define LED1 8
#define LED2 9
#define VIRTA 11
Servo myservo;

void setup() {
  state = ST_IDLE;
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myservo.attach(SERVO, 500, 2400);    
  myservo.write(LID_CLOSE);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(VIRTA, OUTPUT);
  // Debuggausta varten 
  Serial.begin(9600);
  alustaMittaus();
}

unsigned long duration; // Globaali muuttuja mittaustietoa varten
unsigned long data[10]; // Globaali muuttuja mittaustiedon keskiarvoistusta varten
int index=0;
void alustaMittaus(){
  Serial.println("Alusta mittaus");
  for(int i=0;i<10;i++){
    digitalWrite(VIRTA, HIGH);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(TRIG_PIN, LOW);
    data[i] = pulseIn(ECHO_PIN, HIGH);
    //Serial.println(data[i]);
  }
}
void mittaus(){
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(TRIG_PIN, LOW);
  data[index++] = pulseIn(ECHO_PIN, HIGH);
  if(index==10){
    index=0;
  }
  unsigned long d=0;
  for(int i=0;i<10;i++){
    d += data[i];
  }
  duration = d/10;
}

#define TIME2OPEN 5000
#define TIME2CLOSE 8000

void loop() {
  mittaus();
  Serial.println(duration);
  delay(100);
  switch(state){
    case ST_IDLE: 
      //Serial.println("ST_IDLE");
      if(duration < TIME2OPEN){
        state=ST_OPEN; 
      }
      break;
    case ST_OPEN:
      Serial.println("ST_OPEN");
      myservo.write(LID_OPEN);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      state=ST_WAIT;
      break;
    case ST_WAIT:
      //Serial.println("ST_WAIT");
      if(duration > TIME2CLOSE){
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        state=ST_CLOSE;
      }
      break;
    case ST_CLOSE:
      Serial.println("ST_CLOSE");
      myservo.write(LID_CLOSE);
      state=ST_IDLE;
      break;
  }

}
