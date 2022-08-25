/*
 Title : Sumo Robot v1.0
 Author : MacTheDev
 copyright 8/17/2022
*/
#include <NewPing.h>
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5 
#define ir_one 8
#define ir_two 9
#define FRONT_CHECK A0
#define BACK_CHECK A1
bool is_detect = false;
NewPing distance (10, 11, 100);
void setup()
{
  pinMode(ir_one, INPUT);
  pinMode(ir_two, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{  
  int duration = distance.ping_cm();
  Serial.println(duration);
  while (duration < 100 && duration != 0){
    forwardComand();
    Serial.print("blackorwhite() : ");
    Serial.println(blackorwhite());
    if (blackorwhite() == 0){
       following();
    }
     if (blackorwhite() == 1){
       reverseComand();
       delay(1200);
    }
    if (blackorwhite() == 2){
       forwardComand();
       delay(1200);
    }
    duration = distance.ping_cm();
  }
}
int blackorwhite(){
   int blackorwhite1 = analogRead(FRONT_CHECK);
   int blackorwhite2 = analogRead(BACK_CHECK);
   Serial.print("BACK_CHECK : ");
   Serial.println(blackorwhite2);
   if (blackorwhite1 >= 600 && blackorwhite2 >= 600) { 
    return 0; 
    }
   else if (blackorwhite1 <= 600 && blackorwhite2 >= 600) { 
    return 1; 
    }
   else if (blackorwhite1 >= 600 && blackorwhite2 <= 600) { 
    return 2; 
    }
}
void following(){ // following system
      if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == LOW){
        forwardComand();
       }
      if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == HIGH){
      forwardComand();
       }
     else if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == HIGH){
       leftComand();
    }
    else if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == LOW){
       rightComand();
   }
}
void reset() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
}
void forwardComand() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}

void reverseComand() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void leftComand() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void rightComand() {
 digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
