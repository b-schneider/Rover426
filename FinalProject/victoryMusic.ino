#define victoryMusicPin 11 //can be set to any pin
#include "pitches.h"
#include "NewTone.h"  //must use this instead of default tone library to avoid
                      //timer usage conflict with IR detection library
void setupVictoryMusic(){
  pinMode(victoryMusicPin, OUTPUT);
}

void playVictoryMusic(){
  uint8_t numNotes = 9;  //total number of notes to play
  uint8_t BPM = 140;  //speed of song, in beats/ minute
  
  //notes to be played, in order
  int melody[] = {
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_F4, NOTE_G4, NOTE_A5, NOTE_G4, 
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    12, 12, 12, 4, 4, 4, 16/3, 16, 2
  };
  
  //loop through and play each note
  Serial.println("PLaying");
  for (int thisNote = 0; thisNote < numNotes; thisNote++) {
    int noteDuration = 60000. / (noteDurations[thisNote]*BPM);
    Serial.println(noteDurations[thisNote]);
    NewTone(victoryMusicPin, melody[thisNote], noteDuration);
  
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noNewTone(victoryMusicPin);
  }
}

