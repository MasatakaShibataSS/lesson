/*
 * 
 * Arduino Clock
 * ■機能概要
 * 時刻　カレンダー表示
 * Wake up alarm 機能
 * 　　Wake up 時間になるとLCDにアラームメロディーを鳴らす。
 * Timer alarm 機能
 * 　タイムカウント終了までの時間（分:秒）をLCDの2行目11桁～に表示
 *   タイムカウント終了でメロディーを鳴らす。
 * メッセージスクロール表示機能
 * メロディー機能（アラーム時）
 */
#include <Wire.h>
#include <RTC8564.h>
#include <ACM1602.h>
#include <DHT.h>

#define ACM1602_ADDR 0x50
#define ACM1602_BL_SOCKET 7
#define DHTPIN 4
#define DHTTYPE DHT11
#define DELAY_TIME 100

//extern void almMelody();
//extern void cmdParse();
String rightJustify(String str, String zero="00", int n=2); 

RTC8564 RTC;
RTC_TIME rtc_time;
ALARM_TIME alarm;

volatile bool fTimeUp;
const char* dayofweek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
bool fTimerAlarm = false;
int timerAlarm;

int tmCount300ms = 0;
int tmCurrent = 0;
extern String msg;
extern bool fScroll;

float t,h;              // DHT11 Temp. Hummidity

DHT dht(DHTPIN, DHTTYPE);
ACM1602 lcd(ACM1602_ADDR, ACM1602_BL_SOCKET);

void int0Hndl() {
  fTimeUp = true;
}

void setup()
{
    Wire.begin();
    lcd.begin();            //LCD開始
    lcd.set_cursol(0);      //LCDカーソル表示OFF
    lcd.backlight(LOW);    //LCDバックライト点灯
    lcd.set_blink(0);       // cursor blink off
    lcd.clear();            //LCD表示クリア
    Serial.begin(9600);    //シリアル通信開始 9600bps
    RTC.begin();            //RTC開始
    dht.begin();            //DHT11開始
    Serial.println("ArduinoClock Beta1");
    Serial.println("a,yyyy,mm,dd,hh,min,ss");

  // 割り込みフラグ初期化する
    fTimeUp = false;

  // 温度、湿度の初期値を取得する
    h = dht.readHumidity();
    t = dht.readTemperature();
    almMelody();
  // RTCタイマーを１秒周期、繰り返しでスタート
    RTC.setTimer( RTC.TIMING_1_SEC, 1, true, true );
    attachInterrupt(digitalPinToInterrupt(2), int0Hndl, FALLING);
}

void loop()
{
  // シリアルモニタからのコマンド受信、パース
  cmdParse();
  tmCurrent = millis();
  if(tmCurrent - tmCount300ms > 300) {
    tmCount300ms = tmCurrent;
    if(msg.length() !=0) lcdScroll(msg);
  }

  //int0割り込み処理
  if(fTimeUp){
    fTimeUp=false;

    //タイマー割り込み処理
    if(RTC.checkTimerFlag()){
      RTC.clearTimer();
      if(RTC.now(&rtc_time))
      {
        String strLcd0, strLcd1;
        //LCD上段出力 時,分,秒,気温
        strLcd0 = rightJustify(String(rtc_time.hour))+ ":";
        strLcd0 += rightJustify(String(rtc_time.min)) + ":";
        strLcd0 += rightJustify(String(rtc_time.sec)) + " ";
        strLcd0 += "TMP:" + rightJustify(String(t, 0)) + "C";
    
        //LCD下段出力　月,日,曜日,湿度
        strLcd1 = rightJustify(String(rtc_time.month)) + "/";
        strLcd1 += rightJustify(String(rtc_time.day));
        strLcd1 += dayofweek[rtc_time.wday];
        if(!fTimerAlarm){
         strLcd1 += "  RH:" + rightJustify(String(h, 0)) + "%";
        }else{
          strLcd1 += "  " + rightJustify(String(timerAlarm/60)) +":" + rightJustify(String(timerAlarm%60)) + " ";
        if(timerAlarm == 0){
          fTimerAlarm = false;
          lcd.move(0,1);
          lcd.charwrite(strLcd1.c_str());
          almMelody();
        }else{
          timerAlarm--;
          }
        }

        lcd.move(0x00,0x00);
        lcd.charwrite(strLcd0.c_str());
        if(fScroll == false){
        lcd.move(0x00,0x01);
        lcd.charwrite(strLcd1.c_str());
      }  
      }
      readDHT11( &h, &t);
    }
    // アラーム割り込み処理
    if(RTC.checkAlarmFlag()){
      RTC.stopAlarm();
      almMelody();
    }
  }
}
/* void readDHT11(float *h, float *t)
 * ３秒間隔で温度、湿度を読み取る
 */
void readDHT11(float *h, float *t){
  static unsigned int count;
  count +=1;
  if(count >= 3) {
    count = 0;
    *h = dht.readHumidity();
    *t = dht.readTemperature();
  }
}

/*
 * String rightJusty(String str, int n) 
 * 第１引数の文字列"str"を０埋め右揃で第３引数"n"の桁数に変換する。 
 */
 String rightJustify(String str, String zero="00", int n=2) {
  String workStr = zero + str;
  return workStr.substring(workStr.length()-n, workStr.length());
}
