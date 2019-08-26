#include <Wire.h>
#include <RTC8564.h>

RTC8564 RTC;
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

  // タイマー設定:10分後 繰り返しなし、/INTロー割り込みあり
  RTC.setTimer( RTC.TIMING_1_MIN, 10, false, true );

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
    Serial.println("WakeUp Timer!!");

    // 繰り返しなしなら /INTはローになりっぱなし
    // 場合によってはタイマーを停止させる
    RTC.stopTimer();
  }

  delay(1000);
}