#include <Wire.h>                             // I2Cのライブラリ
#include <ACM1602.h>                          // ACM1602NIのライブラリ
 
#define ACM1602_ADDR 0x50                     // ACM1602のI2Cアドレス
#define ACM1602_BL_SOCKET 7                   // バックライトを制御するソケット番号(PD7)
 
ACM1602 lcd(ACM1602_ADDR, ACM1602_BL_SOCKET); // ACM1602クラスのインスタンスlcdを作成
boolean runflag = 0;                          // 繰り返し処理を行わないための変数

int count = 0;
String msgRead; 
String space = "                ";
String msg;

void setup()
{
    Wire.begin();                             // I2C通信初期化
    lcd.begin();                              // ACM1602NIの初期化        
    lcd.set_cursol(0);                        // カーソル非表示
    lcd.backlight(1);                         // バックライトオン
    Serial.begin(9600) ;    
}
 
void loop()
{
    char lcd_disp[17];
    // １回だけArduinoをLCDに表示する
    if ( runflag == 0 ){
        runflag = 1;
        lcd.move(0x00,0x00);
        lcd.charwrite("Arduino");
        lcd.set_blink(0);     
    }

 
    if(Serial.available() > 0) {
      Serial.println("available");
      msgRead = Serial.readStringUntil('\n');
      Serial.println(msgRead.length());     // 受信した文字数をシリアルモニタに出力
      // 受信した文字列の前後にスペースを付加する
      msg = space + msgRead.substring(0,msgRead.length()) + space;
      count=0;
    }
    if(msgRead.length() != 0){
      lcd.move(0x0,0x01);
      lcd.charwrite( msg.substring(count,count+16).c_str() );
      count++;
      if(count > (space.length()+msgRead.length()))
        count=0;
    }  
    delay(300);
}
