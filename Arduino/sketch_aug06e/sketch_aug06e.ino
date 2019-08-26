void setup() {
  Serial.begin(9600);
}
void loop() {
  String msgRead;

  if(Serial.available() > 0) {
  
   Serial.println("available");
  
   msgRead = Serial.readStringUntil('\n'); // '\n'まで文字列を読み込む

   Serial.println(msgRead);
  
   Serial.println(msgRead.length()); 
 
 }
}
