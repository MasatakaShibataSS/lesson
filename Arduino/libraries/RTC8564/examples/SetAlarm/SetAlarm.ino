#include <Wire.h>
#include <RTC8564.h>

RTC8564 RTC;
ALARM_TIME alarm;
RTC_TIME rtc_time;
bool fWakeUp;
const char* dayofweek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void walkeup()
{
  fWakeUp = true;
}

void setup()
{
  fWakeUp = false;

  Serial.begin(9600);
  RTC.begin();

  // アラーム設定:23時15分、/INTロー割り込みあり
  alarm.min = 15;
  alarm.hour = 23;
  alarm.day = 0xFF;                 // 使用しないのなら0xFFに設定
  alarm.wday = 0xFF;                //           〃
  RTC.setAlarm( alarm, true );

  // /INT端子をD2に接続する
  attachInterrupt(0, walkeup, FALLING);
}

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

  if (fWakeUp)
  {
    fWakeUp = false;
    Serial.println("WakeUp Alarm!!");

    // /INTはローになりっぱなし
    // 次回のアラームのためにアラームをクリア
    RTC.clearAlarm();
  }
  delay(1000);
}