#include <Wire.h>
#include <MQ2.h>
#include <LiquidCrystal_I2C.h>
#define MQ2pin (0)
float values;
LiquidCrystal_I2C output(0x27, 16 , 2);
char* gas_status = "OK";
void setup()
{
  Serial.begin(9600);
  output.begin(16, 2);
  output.init();
  output.backlight();
  output.setCursor(0, 0);
  output.print("GAS SO SUSY 1.0");
  output.setCursor(0, 1);
  output.print("MacTheDev");
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  delay(2500);
}
void volume(){
    digitalWrite(10, HIGH);
  delay(3000);
  digitalWrite(10, LOW);
  digitalWrite(6, HIGH);
  delay(5000);
  digitalWrite(6, LOW);
}
void light(){
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
}
void loop()
{
  output.clear();
  values = analogRead(MQ2pin);
  double  percent = (values-50)/10;
  if (percent >= 35.00 && percent <= 45.00){
          gas_status = "LEAK";  
           light();
  }
  if (percent < 35.00){
          gas_status = "OK";  
  }
  if (percent > 45.00){
          gas_status = "DANGER";  
          volume();
  }
  output.clear();
  output.setCursor(0, 0);
  output.print("Percent : ");
  output.print(percent);
  output.setCursor(0, 1);
  output.print("Status : ");
  output.print(gas_status);
  delay(2000);
}
