const int pin_7502 = A0;
long r_lux = 10000;
int sensorValue_lux = 0;    //value read from pin_lux
float vref = 5.0;           //参照電圧5V
float lux = 0.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  sensorValue_lux = analogRead(pin_7502);
  float v_lux = sensorValue_lux * vref / 1023;
  lux = 2 * ( v_lux / r_lux ) * 1000000;        //データシートより lx = 2 x 光電流[μA]
  Serial.print("7502L = " );
  Serial.print(sensorValue_lux);
  Serial.print("\t Volt = " );
  Serial.print(v_lux,4);
  Serial.print("\t lux = ");
  Serial.println(lux);
  delay(1000);
}
 
