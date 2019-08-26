/*
 * DC MotorのCW/CCW駆動
 * BUTTON1 ON: CWでPWM駆動
 * BUTTON2 ON: CCWでPWM駆動
 */
int FAN_SOCKET1 = 5;
int FAN_SOCKET2 = 6;
int BUTTON1_SOCKET = 2;
int BUTTON2_SOCKET = 3;
int fan_out = 0;
//char buf[8];
 
void setup() {
    pinMode(FAN_SOCKET1, OUTPUT);
    pinMode(FAN_SOCKET2, OUTPUT);
    pinMode(BUTTON1_SOCKET, INPUT);
    pinMode(BUTTON2_SOCKET, INPUT);
    Serial.begin(9600) ;                    // シリアル通信の初期化
}
 
void loop() {
    if ( digitalRead(BUTTON1_SOCKET) == HIGH ){
        // fan_outを255まで増加する
        if ( fan_out < 255 ) {
            fan_out = fan_out + 5;
        }
        while ( digitalRead(BUTTON1_SOCKET) == HIGH ){
            delay ( 100 );
        }
    } else if ( digitalRead(BUTTON2_SOCKET) == HIGH ){
        // fan_outを-255まで減少する
        if ( fan_out > -255){
            fan_out = fan_out - 5;
        }
        while ( digitalRead(BUTTON2_SOCKET) == HIGH ){
            delay ( 100 );
        }
    }
    if(fan_out >= 0){
      // DC-Motor をCWでPWM駆動する
      analogWrite( FAN_SOCKET2, 0 );
      analogWrite( FAN_SOCKET1, fan_out );
    }else{
      // DC-MotorをCCWでPWM駆動する
      analogWrite( FAN_SOCKET1, 0 );
      analogWrite( FAN_SOCKET2, -fan_out );      
    }
    Serial.println(String(fan_out));
    delay (100);
}
 
