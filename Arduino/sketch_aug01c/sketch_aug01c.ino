void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //シリアル通信の初期化
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int a, b, ans;
  a = 10;
  b = 3;
  ans = a + b;
  Serial.println("a = 10, b = 3");
  Serial.print("a + b = ");
  Serial.println(ans);
 
  delay(3000);  //３秒間待機
}
 
