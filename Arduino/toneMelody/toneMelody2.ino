#include "pitches.h"
void  toneMelody(int melody[], int noteDurations[], int arySize){
  for (int thisNote = 0; thisNote < arySize; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void setup() {

}

void loop() {
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

  toneMelody(melody, noteDurations, sizeof(melody)/sizeof(melody[0]));
  delay(5000);

}
