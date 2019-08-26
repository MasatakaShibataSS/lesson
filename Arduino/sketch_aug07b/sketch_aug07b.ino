#define STOP 0
#define CW 1
#define CCW 2
int FAN_SOCKET1 = 5;
int FAN_SOCKET2 = 6;
int fan_out ; // モータのPWM値
int stat    ; // 0:STOP　1:CW　2:CCW
 
void stop_wait(int time){
    analogWrite( FAN_SOCKET1, 0 ); 
    analogWrite( FAN_SOCKET2, 0 );
    delay(time);  
}
void setup() {
    stat=STOP;
    fan_out = 0;
    Serial.begin(9600) ;                    // シリアル通信の初期化
}
 
void loop() {
      String numStr;
      while(Serial.available() ==0);      // シリアルにデータがあるか確認
      numStr=Serial.readStringUntil('\n');
      fan_out = numStr.toInt();            // ASCIIを整数に変換;
      fan_out = constrain(fan_out, -255, 255);
      Serial.println(fan_out);
        if(fan_out == 0){
          if(stat != STOP){
            Serial.println("STOP");
            stop_wait(2000);
          }
          stat = STOP;
        }else if(fan_out > 0){
            if(stat == CCW) {
                // 逆転⇒正転で２秒間停止
                Serial.println("CCW => CW");
                stop_wait(2500);    
            }
            stat = CW;
            // 1～255でモータ正回転駆動
            analogWrite( FAN_SOCKET1, fan_out );
            analogWrite( FAN_SOCKET2, 0 );
            Serial.println("CW: " + String(fan_out));
        }else{
            if(stat == CW) {
                // 正転⇒逆転で２秒間停止
                Serial.println("CW => CCW");
                stop_wait(2500);  
            }
            stat = CCW;
            // 1～255でモータ逆回転駆動
            analogWrite( FAN_SOCKET1, 0 );
            analogWrite( FAN_SOCKET2, -fan_out);
            Serial.println("CCW: " + String(-fan_out)); 
        }
}
 
