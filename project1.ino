/*
 * CODING : CoderMan
 * Humidity and Temperature program
 * Temidity 1.0
*/
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 8
#define DHTTYPE DHT11 
DHT dht (DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.begin(16, 2);
   lcd.init(); // เตรียมพร้อมการแสดงผล
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("[Temidity 1.0]");
   lcd.setCursor(0, 1);
   lcd.print("CoderMan");
   delay(4000);
   Serial.begin(9600); //เริ่มต้น output
   dht.begin();  // เริ่มต้น sensor
}
int num = 0;
void loop() {
   float h = dht.readHumidity(); //รับความชื้น
   float t = dht.readTemperature();  //รับค่าอุณหภูมิ
   delay(5);
   Serial.print("['"); 
   Serial.print(h);
   Serial.print("', '"); // ส่งค่าคุยกับคอมหลักรับค่าไปฐานข้อมูล
   Serial.print(t);
   Serial.print("']");
   Serial.print("\n");
   if ((t > 37 || h > 60) || (t > 37 && h > 60)){ // เงื่อนไขถ้าอุณหภูมิมากกว่า 37 หรือ ความชื้นมากกว่า 50 % หรือทั้งสอง
    pinMode (6, OUTPUT); 
    digitalWrite(6,HIGH);
    delay(2000);
    digitalWrite(6,LOW); // เปิดไฟแดงและออด
    delay(500);
    pinMode (10, OUTPUT);
    digitalWrite(10,HIGH);
    delay(2500);
    digitalWrite(10,LOW);
    delay(100);
    }
    else if (t <= 37 && h <= 60){ // เงื่อนไขถ้าอุณหภูมิตํ่ากว่า 37 และความชื้นตํ่ากว่า 47 %
    pinMode (4, OUTPUT);
    digitalWrite(4,HIGH); // เปิดไฟสีเขียว
    delay(250);
    digitalWrite(4,LOW);
    delay(250);
    }
   lcd.setCursor(0,0);
   lcd.print("Humid : "); // แสดงความชื้น
   lcd.print(h);
   lcd.print(" %");
   lcd.setCursor(0,1);
   lcd.print("Temp : "); //แสดงอุณหภูมิ
   lcd.print(t);
   lcd.print(" C");
   
    // จบการทํางาน  
}
