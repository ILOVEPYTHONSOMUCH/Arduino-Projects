#include <NewPing.h>
void setup() {
  NewPing see (3, 8 , 400);
  Serial.begin(9600);
  delay(50);
  }

void loop() {
  long x  = see.ping_cm();
  Serial.println(x);
}
