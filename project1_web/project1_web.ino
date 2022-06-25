#include "DHT.h"

DHT dnt(4, DHT11);

#include <WiFi.h>
#include <HTTPClient.h>
#include <string>
String host = "http://ไอพีของ server/ที่อยู่ของไฟล์ที่รับข้อมูล";
String file_to_access = "ไฟล์ที่รับข้อมูล";
String URL = host + file_to_access;

void setup()
{
Serial.begin(9600);
dnt.begin();
pinMode(2, OUTPUT);
WiFi.begin("ชื่อ wifi", "รหัสผ่าน wifi"); //Connect to WiFi
 while (WiFi.status() != WL_CONNECTED){
    Serial.println("<------!>");
    delay(1000);
  }
   Serial.println("Connected !!!!!!");  
   Serial.print("IP: ");
   Serial.print(WiFi.localIP());
   Serial.print("\n");
}

void loop()
{
digitalWrite(2, HIGH);
float h = dnt.readHumidity(); // ดึงค่าความชื้น
float t = dnt.readTemperature();
float f = dnt.readTemperature(true);
Serial.print("Humidity : ");
Serial.print(h);
Serial.print("\n");
Serial.print("Temperature : ");
Serial.print(t);
Serial.print("\n");
HTTPClient http;
bool http_begin = http.begin(URL);
String message_name = "data"; // ชื่อของพารามิเตอร์ ที่ต้องการส่งข้อมูล
String hum_str = ""; // แปลง float to str
hum_str.concat(h);
String tem_str = "";
tem_str.concat(t);
String message_value = hum_str + "/" + tem_str; // ลงในรูปแบบ h/t
Serial.println(message_value);
String payload_request = message_name + "=" + message_value;  //Combine the name and value
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
int httpResponseCode = http.sendRequest("POST", payload_request);
String payload_response = http.getString();
delay(30000); // ดีเลบ์ในการส่ง
}
