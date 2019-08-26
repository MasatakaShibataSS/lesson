void setup() {
 
  // シリアル通信の初期化
  Serial.begin(9600);
 
}
 
void loop() {
 
  //文字列をArduinoIDEに送る
  Serial.println("From Arduino Message.");
 
  //１秒間ウェイト
  delay(1000);
 
}
