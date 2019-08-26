#define ARYSIZE 10

String msg = "";
int split(String *dst, size_t arraySize, String src, char delimiter);

void cmdParse(){
  String strArray[10] = {"\0"}; // 分割された文字列を格納する配列 
  String rxString;

  if(Serial.available()==0){
    return;
  }
  rxString = Serial.readStringUntil('\n');
//  size_t arraySize = (sizeof(strArray)/sizeof((strArray)[0]));
  split(strArray, ARYSIZE, rxString, ',');
/* Debug
  for(int i = 0; i < index; i++){
    Serial.println(strArray[i]);
  }
*/

  if(strArray[0] == "a") {
    Serial.println("Adjust");
    // 時刻設定処理
    rtc_time.year = strArray[1].toInt();
    rtc_time.month = strArray[2].toInt();
    rtc_time.day = strArray[3].toInt();
    rtc_time.hour = strArray[4].toInt();
    rtc_time.min = strArray[5].toInt();
    rtc_time.sec = strArray[6].toInt();
    RTC.adjust( rtc_time );

  }else if(strArray[0] == "w"){
    Serial.println("Wakeup");
    // アラーム設定処理
    alarm.hour = strArray[1].toInt();
    alarm.min = strArray[2].toInt();
    alarm.day = 0xFF;                 // 使用しないのなら0xFFに設定
    alarm.wday = 0xFF;                //
    RTC.setAlarm( alarm, true );
 
  }else if(strArray[0] == "t"){
    int min = strArray[1].toInt();
    int ss = strArray[2].toInt();
    if((min*60+ss)==0) return;
    RTC.clearAlarm();
    timerAlarm = min*60+ss;
    fTimerAlarm = true;
    
  }else if(strArray[0] == "m"){
    msg = strArray[1];

  }
}
/*
 * int split(String *dst, size_t arraySize, String src, char delimiter);
 *  String *dst: 分割された文字列を格納する配列のポインタ
 *  size_t arraySize: 格納先配列のサイズ
 *  String src: 区切り文字を含む分割元文字列(ソース文字列）
 *  delimiter: 区切り文字
 */ 
int split(String *dst, size_t arraySize, String src, char delimiter){
    int index = 0;
    int srclength = src.length();
    for (int i = 0; i < srclength; i++) {
        char tmp = src.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
