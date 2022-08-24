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
NewPing distance (10, 11, 80);
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
   int distance2 = distance.ping_cm();
   Serial.println(distance2);
   if (distance2 < 200 && distance2 != 0){
     while (distance2 <= 200){
     int check = blackorwhite();
     if (check == 0){
      if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == LOW){
      forwardComand();
       }
      if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == HIGH){
      forwardComand();
       }
     else if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == HIGH){
     Serial.print("left");
       leftComand();
    }
    else if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == LOW){
     Serial.print("right");
       rightComand();
   }
     }
     if (check==1){
        reverseComand();
        delay(1000);
     }}
    }
}
int blackorwhite(){
   int blackorwhite = analogRead(FRONT_CHECK);
     if (blackorwhite > 600) { 
    return 0; 
    }
  else {
   return 1;
  }
}
void following(){ // following system
  if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == LOW){
      forwardComand();
   }
  else if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == HIGH){
    Serial.print("left");
      leftComand();
   }
  else if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == LOW){
    Serial.print("right");
       rightComand();
   }
    else{
         reset();
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
