//FineName: _LcdSetAlarmBuzz
#include <Wire.h>
#include <RTC8564.h>
#include <ACM1602.h>
#define ARYSIZE 10
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
extern void almMelody();
int split(String *dst, size_t arraySize, String src, char delimiter);
String rightJustify(String str, int n);

String strArray[10] = {"\0"}; // 分割された文字列を格納する配列 
String rxString;
String strLcd0;
String strLcd1;

RTC8564 RTC;
RTC_TIME rtc_time;
ALARM_TIME alarm;
volatile bool fTimeUp;
const char* dayofweek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

#define ACM1602_ADDR 0x50
#define ACM1602_BL_SOCKET 7

ACM1602 lcd(ACM1602_ADDR, ACM1602_BL_SOCKET);
void int0Hndl() {
  fTimeUp = true;
}
void setup()
{
    Wire.begin();
    lcd.begin();
    lcd.set_cursol(0);
    lcd.backlight(HIGH);
    lcd.set_blink(LOW);
    Serial.begin(9600);
    RTC.begin();             //RTC-8564NB
  // RTCタイマーを１秒周期、繰り返しでスタート
    RTC.setTimer( RTC.TIMING_1_SEC, 1, true, true );
    attachInterrupt(digitalPinToInterrupt(2), int0Hndl, FALLING);
    almMelody();
    Serial.println("a,yyyy,mm,dd,hh,mm,ss + Enter");
}

void loop()
{
  if (Serial.available() > 0) {
    rxString = Serial.readStringUntil('\n');
    Serial.println(rxString);                           // 受信データ確認
    int index = split(strArray, ARYSIZE, rxString, ',');
    // コマンドのエラーチェック
    if(index <= 0){
      strArray[0] = "";
      Serial.println("Command Error!!");
    }
  } 

  if(strArray[0] == "a") {
    // 時刻設定処理
    rtc_time.year = strArray[1].toInt();
    rtc_time.month = strArray[2].toInt();
    rtc_time.day = strArray[3].toInt();
    rtc_time.hour = strArray[4].toInt();
    rtc_time.min = strArray[5].toInt();
    rtc_time.sec = strArray[6].toInt();
    RTC.adjust( rtc_time );
    strArray[0] = "";

  }else if(strArray[0] == "w"){
    Serial.println("Set Alarm");
    // アラーム設定処理
    alarm.hour = strArray[1].toInt();
    alarm.min = strArray[2].toInt();
    alarm.day = 0xFF;                 // 使用しないのなら0xFFに設定
    alarm.wday = 0xFF;                //
    RTC.setAlarm( alarm, true );
    strArray[0] = "";
  }
  if(fTimeUp) {
    fTimeUp=false;
    if(RTC.checkTimerFlag()) {
      // Timer割り込み処理
      RTC.clearTimer();
      // RTCからカレンダー、時刻を読み取り、LCD表示文字列作成
      if(RTC.now(&rtc_time)) {
        // LCD １行目の表示データ
//        strLcd0 = String(rtc_time.year)+ "/";
        strLcd0 += String(rtc_time.month)+"/";
        strLcd0 += String(rtc_time.day);
        strLcd0 += "(" + String(dayofweek[rtc_time.wday]) +")";
        // LCD ２行目の表示データ
        strLcd1 = rightJustify(String(rtc_time.hour), 2) + ":";
        strLcd1 += rightJustify(String(rtc_time.min), 2) + ":";
        strLcd1 += rightJustify(String(rtc_time.sec), 2);
    
    //  LCDのカレンダー、時刻表示更新
        lcd.move(0,0);
        lcd.charwrite(strLcd0.c_str());
        lcd.move(0x00,01);
        lcd.charwrite(strLcd1.c_str());
      }
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    lcd.move(9,00);
    lcd.charwrite("TMP:");
    lcd.charwrite(String(t,0).c_str());;
    lcd.charwrite("C");
    lcd.move(9,01);
    lcd.charwrite("RH:");
    lcd.charwrite(String(h,0).c_str());
    lcd.charwrite("%");
    }
    if(RTC.checkAlarmFlag()){
        // Alarm割り込み処理
//        RTC.clearAlarm();
        RTC.stopAlarm();
        almMelody();
    }
  }
}
/*
 * int split(String *dst, size_t arraySize, String src, char delimiter);
 *  String *dst: 分割された文字列を格納する配列のポインタ
 *  size_t arraySize: 格納先配列のサイズ
 *  String src: 区切り文字を含む分割元文字列(ソース文字列）
 *  delimiter: 区切り文字
 */ 
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
/*
 * String rightJusty(String str, int n) 
 * 第１引数の文字列"str"を０埋め右揃で第２引数"n"の桁数に変換する。 
 */
 String rightJustify(String str, int n) {
  String workStr = "00" + str;
  return workStr.substring(workStr.length()-n, workStr.length());
}
