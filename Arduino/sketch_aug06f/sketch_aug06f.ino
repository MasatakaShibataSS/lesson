int red_pin = 11;
int blue_pin = 10;
int green_pin = 9;
 
int r, g, b;
 
void setup() {
    Serial.begin(9600);
    pinMode(red_pin, OUTPUT);       //　赤の出力ピンをOUTPUTに設定
    pinMode(green_pin, OUTPUT);     //　緑の出力ピンをOUTPUTに設定
    pinMode(blue_pin, OUTPUT);      //　青の出力ピンをOUTPUTに設定
 
    r = 0; 
    g = 0;
    b = 0;
}
 
void loop() {
    // LED：青⇒紫⇒赤
    for(r = 0, b = 255; r < 255; b--, r++){
      light_led();
    }
    // LED：赤⇒黄⇒緑
    for(g = 0, r = 255; g < 255; r--, g++){
      light_led();
    }
    // LED：緑⇒青
    for(b = 0, g = 255; b < 255; g--, b++){
      light_led();
    }
}
 
void light_led(){
    analogWrite(red_pin, r);    
    analogWrite(green_pin, g);
    analogWrite(blue_pin, b);
    delay(10);
}
 
