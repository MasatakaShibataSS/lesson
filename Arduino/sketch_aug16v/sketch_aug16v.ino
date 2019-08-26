#include <Wire.h>
#include <DHT.h>
#include <ACM1602.h>
 
#define ACM1602_ADDR 0x50
#define ACM1602_BL_SOCKET 7
#define DHTPIN 2
#define DHTTYPE DHT11
 
ACM1602 lcd(ACM1602_ADDR, ACM1602_BL_SOCKET);
DHT dht(DHTPIN, DHTTYPE);
boolean runflag = 0;
 
void setup()
{
    Wire.begin();
    lcd.begin();
    lcd.set_cursol(0);
    lcd.backlight(HIGH);
    lcd.set_blink(0);   // cursor blink off
    dht.begin(); 
    Serial.begin(9600);
}
 
void loop()
{
    String str;
    if ( runflag == 0 ){
        runflag = 1;
        lcd.move(0x00,0x00);
        lcd.charwrite("Humidity: ");
        lcd.move(0x00,0x01);
        lcd.charwrite("Temperature: ");        
    }
    float h = dht.readHumidity();
    float t = dht.readTemperature();
 
    // ここにLCDに温度・湿度を表示するコードを入れてください。
 str=String(h,0);
  str += "%";
  lcd.move(13,0);
  lcd.charwrite(str.c_str());

  str=String(t,0);
  char degree = 0xd0;
  str += degree;
  str += "C";
  lcd.move(12,1);
  lcd.charwrite(str.c_str());
  
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" C ");     
    delay(3000);
}
