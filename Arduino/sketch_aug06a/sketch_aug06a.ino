int red_pin = 11;
int green_pin = 9;
int blue_pin = 10;
 
void setup() {
    pinMode(red_pin, OUTPUT);
    pinMode(green_pin, OUTPUT);
    pinMode(blue_pin, OUTPUT);
}
 
void loop() {
    // Red ON
    light_led(HIGH,LOW,LOW);
 
    // Green ON
    light_led(LOW,HIGH,LOW);
 
    // Blue ON
    light_led(LOW,LOW,HIGH);
 
    // Red, Grenn ON
    light_led(HIGH,HIGH,LOW);
 
    // Green Blue ON
    light_led(LOW,HIGH,HIGH);
 
    // Blue, Red ON
    light_led(HIGH,LOW,HIGH);
 
    // Red, Blue, Green ON
    light_led(HIGH,HIGH,HIGH);
 
    // Red, Blue, Green OFF
    light_led(LOW,LOW,LOW);
}
 
void light_led(boolean r, boolean g, boolean b){
    digitalWrite(red_pin, r);    
    digitalWrite(green_pin, g);
    digitalWrite(blue_pin, b);
    delay(1000);
}
