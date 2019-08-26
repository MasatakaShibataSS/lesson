#include <Wire.h>                             // I2Cのライブラリ
#include <ACM1602.h>                          // ACM1602NIのライブラリ
 
#define ACM1602_ADDR 0x50                     // ACM1602のI2Cアドレス
#define ACM1602_BL_SOCKET 7                   // バックライトを制御するソケット番号(PD7)
 
ACM1602 lcd(ACM1602_ADDR, ACM1602_BL_SOCKET); // ACM1602クラスのインスタンスlcdを作成
boolean runflag = 0;                          // 繰り返し処理を行わないための変数
int count = 0;                                // 表示カウント用の変数

const int buttonON = LOW;    // ボタンが押されているとピンの値はLOW
const int buttonOFF = HIGH;  // ボタンが押されていないとピンの値はHIGH
 
const int buttonUp = 3;
const int buttonDown = 5;
  
void setup()
{
    Wire.begin();                             // I2C通信初期化
    lcd.begin();                              // ACM1602NIの初期化        
    lcd.set_cursol(0);                        // カーソル非表示
    lcd.backlight(1);                         // バックライトオン
    pinMode(buttonUp, INPUT_PULLUP); 
    pinMode(buttonDown, INPUT_PULLUP);
    Serial.begin(9600) ;    
}
 
void loop()
{
    char count_str[32];                        // ACM1602NIへの出力用文字配列
    if ( runflag == 0 ){
        // 最初に１回だけ行う処理
        runflag = 1;
        lcd.charwrite("Arduino");             // １行目に"Arduino"と表示
        lcd.move(0x00,0x01);                  // ２行目の行頭に表示位置を移動
        lcd.charwrite("Count:");              // ２行目に"Count:"を表示  
        lcd.set_blink(0);  
    }
        lcd.move(0x07,0x01);                      // ２行目７文字目に表示位置を移動
    if( digitalRead(buttonUp)==buttonON){
      count++;
    }else if(digitalRead(buttonDown)==buttonON){
      count--;
    }
    sprintf(count_str,"%4d",count);    // カウント値（整数）を４桁の文字列に変換
    strcat(count_str, "     ");        // 表示桁が変わったときに余白をSPでクリア
    lcd.charwrite( count_str );
    delay(100);
}
 
