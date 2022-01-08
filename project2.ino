/*
 * โปรเจคโปรแกรมที่ 2
 * นาฬิกาไทยประดิษฐ์
 * Coding : CoderMan
 * เซนเซอร์ คือ RTC 1.1
*/
#include <DS3231.h> // เรียกใช้ module เวลาจริง
#include <LiquidCrystal_I2C.h> // เรือกใช้ module หน้าจอ
#include <Wire.h> // เรียกใช้ module ระบุชื่อสาย
LiquidCrystal_I2C output(0x27, 16, 2); // เตรียมแสดงผลหน้าจอ
DS3231 rtc(SDA, SCL); // 
void setup(){
  output.begin(16, 2); // เตรียมแสดงผลหน้าจอ
  output.init(); // เตรียมแสดงผลหน้าจอ
  output.backlight(); // เตรียมแสดงผลหน้าจอ
  output.setCursor(0, 0); // จัดการลักษณะแสดงผล
  rtc.begin(); // เริ่ม sensor ทํางาน
}

void loop(){
  char *day = rtc.getDOWStr(); // เอาวัน ปล. ส่วนนี้ไม่ได้แสดงผล เขียนไว้เพื่อพัฒนาต่อในอนาคต
  char *date = rtc.getDateStr(); // เอาวันที่
  char *daytime = rtc.getTimeStr(); // เอาเวลา
  output.setCursor(0, 0); // แสดงผลเวลาตรงบรรทัดแรก
  output.print("Date: "); // แสดงผลเวลาตรงบรรทัดแรก
  output.print(date); // แสดงผลเวลาตรงบรรทัดแรก
  output.setCursor(0, 1); // แสดงผลเวลาตรงบรรทัดที่สอง
  output.print("Time: "); // แสดงผลเวลาตรงบรรทัดที่สอง
  output.print(daytime); // แสดงผลเวลาตรงบรรทัดที่สอง
  delay(1000); // รอ 1 วินาที
}
