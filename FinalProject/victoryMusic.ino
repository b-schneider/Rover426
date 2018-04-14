#define victoryMusicPin 7 //can be set to any pin
#include "pitches.h"
#include "NewTone.h"  //must use this instead of default tone library to avoid
                      //timer usage conflict with IR detection library
void setupVictoryMusic(){
  pinMode(victoryMusicPin, OUTPUT);
}

void playVictoryMusic(){
  uint8_t numNotes = 8;  //total number of notes to play
  uint8_t BPM = 60;  //speed of song, in beats/ minute
  
  //notes to be played, in order
  int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };
  
  //loop through and play each note
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {
    int noteDuration = 60000 / (noteDurations[thisNote]*BPM);
    NewTone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noNewTone(8);
  }
}

