//FileName: _018_LcdRtcSnprintf.ino
#include <Wire.h>
#include <RTC8564.h>
#include <ACM1602.h>
#define ARYSIZE 10
int split(String *dst, size_t arraySize, String src, char delimiter);
String strArray[ARYSIZE] = {"\0"}; // 分割された文字列を格納する配列 
String rxString;
RTC8564 RTC;
RTC_TIME rtc_time;
const char* dayofweek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
 
#define ACM1602_ADDR 0x50
#define ACM1602_BL_SOCKET 7
 
ACM1602 lcd(ACM1602_ADDR, ACM1602_BL_SOCKET);
 
char lcd_buf0[17] ;    //ACM1602
char lcd_buf1[17] ;    //ACM1602
 
void setup()
{
    Wire.begin();
    lcd.begin();
    lcd.set_cursol(0);
    lcd.backlight(HIGH);
    lcd.set_blink(LOW);
    Serial.begin(9600);     //RTC-8564NB
    RTC.begin();
      Serial.begin(9600);
    RTC.begin();
    Serial.println("a,yyyy,mm,dd,hh,mm,ss + Enter");
 
}
 
void loop()
{
  char buf[32];
  if (Serial.available() > 0) {
    rxString = Serial.readStringUntil('n');
    Serial.println(rxString);
    int index = split(strArray, ARYSIZE, rxString, ',');
  } 
 
  if(strArray[0] == "a") {
    Serial.println("Adjust");
    // 時刻設定処理
    rtc_time.year = strArray[1].toInt();
    rtc_time.month = strArray[2].toInt();
    rtc_time.day = strArray[3].toInt();
    rtc_time.hour = strArray[4].toInt();
    rtc_time.min = strArray[5].toInt();
    rtc_time.sec = strArray[6].toInt();
    RTC.adjust( rtc_time );
    strArray[0] = "";
  }
  if(RTC.now(&rtc_time))
  {
   // ここに、年/月/日/曜日と時刻をLCD表示する処理を入れます。
    snprintf(lcd_buf0,16,"%04u-%02u-%02u(%s)",
    rtc_time.year,
    rtc_time.month,
    rtc_time.day,
    dayofweek[rtc_time.wday] );
    lcd.move(0,0);
    lcd.charwrite(lcd_buf0);


    snprintf(lcd_buf0,16,"%02u:%02u:%02u",

    rtc_time.hour,
    rtc_time.min,
    rtc_time.sec   );

    lcd.move(0,1);
    lcd.charwrite(lcd_buf0);
  }
  delay(300);
}
int split(String *dst, size_t arraySize, String src, char delimiter){
    int index = 0;
    int srclength = src.length();
    dst[index] = "";
    for (int i = 0; i < srclength; i++) {
        char tmp = src.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
            dst[index] = "";
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
 
