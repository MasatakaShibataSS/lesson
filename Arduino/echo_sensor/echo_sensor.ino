#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
 
double Duration = 0; //受信した間隔
double Distance = 0; //距離
    void setup() {
  Serial.begin( 9600 );
  pinMode( echoPin, INPUT );
  pinMode( trigPin, OUTPUT );
} 
void loop() {
  digitalWrite(trigPin, LOW);    //(1)トリガをLOWにする
  delayMicroseconds(10); 
  digitalWrite( trigPin, HIGH ); //(2)トリガをLOW⇒HIGH
  delayMicroseconds( 1000 ); 
  digitalWrite( trigPin, LOW );  //(3)トリガをHIGH⇒LOW
 
  Duration = pulseIn( echoPin, HIGH ); //(4)から(5)の時間を計測
  if (Duration > 0) {
    Duration = Duration/2; //往復距離を半分にする
    Distance = Duration*340*100/1000000; // 音速を340m/sに設定
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");

  if 
  }
  delay(500);
}
