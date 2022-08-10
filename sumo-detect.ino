#include <NewPing.h>
#include <Servo.h>
 NewPing see(3, 8 , 400);
 Servo m;
 bool on = false;
void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  delay(50);
  m.attach(5);
  m.write(0);
  }

void loop() {
 int x  = see.ping_cm();
  Serial.println(x);
  if (x <= 14 && x != 0){
     digitalWrite(10, HIGH);
     on = true;
     m.write(90);
     delay(250);
     m.write(180);
     delay(250);
     return;
    }
  if (on){
    digitalWrite(10, LOW);
    }
}
