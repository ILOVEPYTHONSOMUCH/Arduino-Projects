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
#define ir_one 6 
#define ir_two 7 
bool check_in_front_of = false;
NewPing distance (10, 11, 400);
void setup()
{
  pinMode(ir_one, INPUT);
  pinMode(ir_two, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //pinMode(speedA,OUTPUT);
  //pinMode(speedB,OUTPUT);
}

void loop()
{
   if (digitalRead(ir_one) == LOW){
      forwardComand();
    }
    else{
         reset();
    }
}
void checkdistance(){ //Ultra Sonic Sensor
 distance = distance.ping_cm();
 if (distance < 25){
     // to do
     bool check_in_front_of = true;
  }
}
void following(){ // following system
  if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == LOW){
      forwardComand();
   }
  else if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == HIGH){
      leftComand();
   }
  else if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == LOW){
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
