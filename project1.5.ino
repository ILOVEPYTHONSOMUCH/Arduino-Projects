/*
 * Hot-Or-Cold 1.0
 * Coding : CoderMan
 * Open-source
 * DHT11, RTC 1.1 censor
*/ 
// ขอโทษนะ ขี้เกียจคอมเม้นต์แล้วอะ มันยาวไป ....................
// อ่านเองละกัน ปล.รู้ว่าอ่านไม่ออก แต่ช่างมันเถอะ
#include "DHT.h"
#include <Wire.h> 
#include <DS3231.h> 
#include <LiquidCrystal_I2C.h> 
DS3231 rtc(SDA, SCL); 
Time t; 
LiquidCrystal_I2C output(0x27, 16 , 2); 
#define DHTPIN 6 
#define DHTTYPE DHT11  
DHT dht (DHTPIN, DHTTYPE); 
void setup() 
{
 pinMode(3, OUTPUT); 
 Serial.begin(9600); 
 output.begin(16, 2); 
 output.init(); 
 output.backlight();
 output.setCursor(0, 0);
 output.print("Hot-Or-Cold 1.0");
 output.setCursor(0, 1);
 output.print("CoderMan");
 delay(4000); 
 output.clear();
 dht.begin(); 
 rtc.begin(); 
}

void loop() 
{
  Serial.print("Starting........");
  char* moment; 
  char* hu;
  char* te;
  t = rtc.getTime();
  float human = dht.readHumidity(); // ค่า
  float tem = dht.readTemperature();
  Serial.print("human = ");
  Serial.print(human);
  Serial.print("\n");
  Serial.print("tem = ");
  Serial.print(tem);
  Serial.print("\n");
  char* day = rtc.getDOWStr();
  char* datetime = rtc.getDateStr();
  char* timeday = rtc.getTimeStr();
  int hours = t.hour;
  Serial.print("hour = ");
  Serial.print(hours);
  Serial.print("\n");
  int minute = t.min;
  Serial.print("minute = ");
  Serial.print(minute);
  Serial.print("\n");
  if (hours < 12){
    moment = (char*)"Morning";
  }
  else if (hours == 12){
    moment = (char*)"Noon";
  }
  else if (hours > 12 && hours <= 16){
    moment = (char*)"Afternoon";
  }
  else if (hours > 16 && hours <= 18){
    moment = (char*)"Evening";
  }
  else if (hours > 18 && hours != 0){
    moment = (char*)"Night";
  }
  else if (hours == 0){
    moment = (char*)"Midnight";
  }
  output.backlight();
  output.setCursor(0, 0);
  output.print(moment);
  output.print(" !!!");
  output.setCursor(0, 1);
  output.print("Now: ");
  output.print(t.hour);
  output.print(":");
  output.print((int)t.min);
  delay(5000);
  output.clear();
  output.backlight();
  output.setCursor(0, 0);
  output.print("Day: ");
  output.print(day);
  output.setCursor(0, 1);
  output.print("Time: ");
  output.print(t.hour);
  output.print(":");
  output.print((int)t.min);
  delay(5000);
  output.clear();
  if (human <= 38){
    hu = (char*)"Dry";
  }
  else if (human > 38 && human <= 47){
    hu = (char*)"Normal";
  }
  else if (human > 47 && human <= 60){
    hu = (char*)"Humidy";
  }
  else if (human > 60){
    hu = (char*)"Very Humidy";
  }
  if (tem <= 25){
  te = (char*)"Cold";
 
  }
  else if (tem > 25 && tem <= 36){
   te = (char*)"Hot";
 
    
  }
  else if (tem > 36 && tem <= 42){
     te = (char*)"Hot";
   
  }
  else if (tem > 42){
   te = (char*)"Very hot";
  
  }
  int n = 0;
  while (n < 60){
  float human = dht.readHumidity();
  float tem = dht.readTemperature();
  if (human <= 38){
    hu = (char*)"Dry";
  }
  else if (human > 38 && human <= 47){
    hu = (char*)"Normal";
  }
  else if (human > 47 && human <= 60){
    hu = (char*)"Humidy";
  }
  else if (human > 60){
    hu = (char*)"Very Humidy";
  }
  if (tem <= 25){
  te = (char*)"Cold";
 
  }
  else if (tem > 25 && tem <= 36){
   te = (char*)"Normal";
 
    
  }
  else if (tem > 36 && tem <= 42){
     te = (char*)"Hot";
   
  }
  else if (tem > 42){
   te = (char*)"Very hot";
  
  }
  output.clear();
  output.backlight();
  output.setCursor(0, 0);
  output.print(hu);
  Serial.print("hu = ");
  Serial.print(hu);
  output.print(" : ");
  output.print(human);
  Serial.print("\n");
  output.setCursor(0, 1);
  output.print(te);
  Serial.print("te = ");
  Serial.print(te);
  output.print(" : ");
  output.print(tem);
  Serial.print("\n");
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  n = n + 1;
  delay(100);
 
  
  }
  output.clear();
}
