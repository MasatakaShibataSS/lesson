int _max(int x, int y);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a=3, b=2, ans;
  ans = _max(a, b);
  Serial.print("Max : ");
  Serial.println(ans);
  delay(500);
}
 
int _max(int x, int y) {
  if(x > y)
    return x;
  else
    return y;
}
