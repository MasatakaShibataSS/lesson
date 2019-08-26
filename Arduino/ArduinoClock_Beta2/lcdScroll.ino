#include <Wire.h>
#include <ACM1602.h>
String msgLCD;
String msgSpace = "               ";
bool fScroll=false;
int cntScroll;

void lcdScroll(String str){
  if(fScroll==false){
    fScroll = true;
    cntScroll = 0;
    msgLCD = msgSpace + str + msgSpace;
  }
  lcd.move(0x0,0x01);
  lcd.charwrite(msgLCD.substring(cntScroll,cntScroll+16).c_str());
  if(cntScroll++ >= (str.length()+msgSpace.length())){
    fScroll = false;
    msg="";
  }   
}
