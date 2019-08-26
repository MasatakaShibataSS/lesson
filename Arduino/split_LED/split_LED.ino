String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int outputValueR = 0;        // value output to the PWM (analog out)
int outputValueG = 0;        // value output to the PWM (analog out)
int outputValueB = 0;        // value output to the PWM (analog out)
const int analogOutPinR = 11; // Analog output pin that the LED is attached to
const int analogOutPinG = 9;
const int analogOutPinB = 10;
 
#define ARYSIZE 10
String dst_str[ARYSIZE] = {"\0"}; // 分割された文字列を格納する配列 
 
int split(String *dst, size_t arraySize, String src, char delimiter){
    int index = 0;
    int srclength = src.length();
    dst[index] = "";
    for (int i = 0; i < srclength; i++) {
        char tmp = src.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
            dst[index] = "";
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
 
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
    analogWrite(analogOutPinR, 0);
  
}
 
void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    int index = split(dst_str, ARYSIZE, inputString, ',');
    outputValueR = dst_str[0].toInt();
    outputValueG = dst_str[1].toInt();
    outputValueB = dst_str[2].toInt();
    // clear the string:
    analogWrite(analogOutPinR, outputValueR);
    analogWrite(analogOutPinG, outputValueG);
    analogWrite(analogOutPinB, outputValueB);
    inputString = "";
    stringComplete = false;
  }
}
 
/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
