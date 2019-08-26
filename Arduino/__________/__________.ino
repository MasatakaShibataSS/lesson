// File: rtcAdjustDate
#include <Wire.h>
#include <RTC8564.h>
int split(String *dst, size_t arraySize, String src, char delimiter);
String strArray[10] = {"\0"}; // 分割された文字列を格納する配列 
String rxString;
RTC8564 RTC;
RTC_TIME rtc_time;
const char* dayofweek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
 
void setup()
{
  Serial.begin(9600);
  RTC.begin();
  Serial.println("w,hh,mm + Enter");
  while(true){
    if (Serial.available() > 0) {
      rxString = Serial.readStringUntil('n');
      break;
    }
  }
  size_t arraySize = (sizeof(strArray)/sizeof((strArray)[0]));
  int index = split(strArray, arraySize, rxString, ',');
  for(int i = 0; i < index; i++){
    Serial.println(strArray[i]);
  }
 
  /* 2013年4月27日 0時0分0秒に時刻合わせ */
  rtc_time.year = strArray[1].toInt();
  rtc_time.month = strArray[2].toInt();
  rtc_time.day = strArray[3].toInt();
  rtc_time.hour = strArray[4].toInt();
  rtc_time.min = strArray[5].toInt();
  rtc_time.sec = strArray[6].toInt();
  RTC.adjust( rtc_time );
}
//  これでも可能です。
//  RTC.adjust( 2017, 10, 02, 16, 48, 0 );
//}
 
void loop()
{
  char buf[32];
  if(RTC.now(&rtc_time))
  {
    snprintf(buf,32,"%04u-%02u-%02u(%s) %02u:%02u:%02u\n",
    rtc_time.year,
    rtc_time.month,
    rtc_time.day,
    dayofweek[rtc_time.wday],
    rtc_time.hour,
    rtc_time.min,
    rtc_time.sec   );
 
    Serial.print(buf);
  }
  delay(1000);
}
 
int split(String *dst, size_t arraySize, String src, char delimiter){
    int index = 0;
    int srclength = src.length();
    for (int i = 0; i < srclength; i++) {
        char tmp = src.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
