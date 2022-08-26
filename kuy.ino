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
#define ir_three 12
#define ir_four 13
#define FRONT_CHECK A0
#define BACK_CHECK A1
NewPing distance (10, 11, 50);
bool go = false;
void sayl(char* message){
  Serial.println(message);
}
void say(char* message){
  Serial.print(message);
}
int blackorwhite(){
   int blackorwhite1 = analogRead(FRONT_CHECK);
   say("Detect baw1 = ");
   Serial.println(blackorwhite1);
   int blackorwhite2 = analogRead(BACK_CHECK);
   say("Detect baw2 = ");
   Serial.println(blackorwhite2);
   if (blackorwhite1 >= 600 && blackorwhite2 >= 600) { 
    return 0; 
    }
   else if (blackorwhite1 <= 600 && blackorwhite2 >= 600) { 
     reset();
     reverseComand();

    }
    else if (blackorwhite1 >= 600 && blackorwhite2 <= 600) { 
      reset();
     forwardComand();
    }
}
void following(){ // following system
     reset();
     if (digitalRead(ir_one) == LOW && digitalRead(ir_two) == HIGH){
       leftComand();
    }
    else if (digitalRead(ir_one) == HIGH && digitalRead(ir_two) == LOW){
       rightComand();
   }
   else{
     forwardComand();
    }
}
void reset() {
  sayl("Reset");
  
}
void forwardComand() {
  sayl("Go !!!!!!");
}

void reverseComand() {
  sayl("Reverse !!!");
}

void leftComand() {
  sayl("Left @@@@");
}
void rightComand() {
  sayl("Right %%%%");
}
int checkback(){
     int three = digitalRead(ir_three);
     int four = digitalRead(ir_four);
   
     if (three == LOW && four == HIGH){
        leftComand();
     }
     if (three == HIGH && four == LOW){
        rightComand();
     }
}
void setup()
{
  pinMode(ir_one, INPUT);
  pinMode(ir_two, INPUT);
  pinMode(ir_three, INPUT);
  pinMode(ir_four, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  delay(6000);
  Serial.begin(9600);
}

void loop()
{  
  int duration = distance.ping_cm();
  if (duration < 50 && duration != 0){
    go = true;
  }
  while (go){
    leftComand();
    int detect_white = blackorwhite();
    say("Check detect : ");
    Serial.println(detect_white);
    if (detect_white == 0){
       checkback();
    }
    if (detect_white == 0){
       following();
    }
    duration = distance.ping_cm();
  }
}
