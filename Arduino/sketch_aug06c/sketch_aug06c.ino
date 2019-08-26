int sensorPin = A0;    // select the input pin for the Cds
int sensorValue = 0;  // variable to store the value coming from the sensor
float volts;
String message;
 
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
}
 
void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // アナログ入力を電圧に変換
  volts = float(sensorValue) * 5.0/1023.0;
  if(volts > 1.0) {
    message = "Lighted : ";
  } else {
    message = "Dark : ";
  }
  // メッセージとA0で読み取った電圧を出力
  Serial.print(message);
  Serial.print(volts);
  Serial.println("V");
  // ２秒間ウェイト
  delay(2000);
}
