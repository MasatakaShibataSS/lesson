#include "pitches.h"
 
// ブザーを接続するピン 今回は D8 に接続
int buzzerPin = 8;
 
// 帝国のマーチ A メロ
int melody[] = {
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3, NOTE_DS3, NOTE_AS3, NOTE_G3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_AS3, NOTE_FS3, NOTE_DS3, NOTE_AS3, NOTE_G3
};
 
// 音の長さ 2, 4, 8 はそれぞれ 2分音符、4分音符、8分音符
int noteDurations[] = {
  4, 4, 4, 6, 8, 4, 6, 8, 2,
  4, 4, 4, 6, 8, 4, 6, 8, 2
};
 
void setup() {
  for (int thisNote = 0; thisNote < sizeof(noteDurations) / sizeof(noteDurations[0]); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}
 
void loop() {
  // ループはしない
}
