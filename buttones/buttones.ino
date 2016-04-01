#include "pitches.h"



// los tonos 
int notes[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4 };

// los pin numbers EL TAMANO TIENE QUE SER IQUAL QUE LO DE notes
int buttonPins[] = { 2, 3, 4, 5, 6, 7, 8 };
// los estados de los bottones (indeces corresponden a los de buttonPins)
int buttonStates[] = { 0, 0, 0, 0, 0, 0, 0 };

//el pin del altavoz
const int altavozPin = 9;

void setup() {
  for (int i = 0; i < 7; i++) { // el tamano de buttonPins
    pinMode(buttonPins[i], INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 7; i++) { // el tamano de notes
    buttonStates[i] = digitalRead(buttonPins[i]);

    if (buttonStates[i] == HIGH) {
      tone(altavozPin, notes[i],50);
    } else {
      //noTone(altavozPin);  // messes things up
    }
    
  }
  
}
