#include "pitches.h"
#include "pwm.h"

// los tonos 
int notes[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4 };

// los pin numbers EL TAMANO TIENE QUE SER IQUAL QUE LO DE notes
int buttonPins[] = { 2, 3, 4, 5, 6, 7, 8 };
// los estados de los bottones (indeces corresponden a los de buttonPins)
int buttonState = 0;

// el pin del altavoz
int altavozPin = 11;


void setup() {
  for (int i = 0; i < 7; i++) { // el tamano de buttonPins
    pinMode(buttonPins[i], INPUT);
  }

}

void loop() {

  bool altavozUno = true;
  //devisores para setPwmFrequency
  int devs[] = { 1, 8, 32, 64, 128, 256, 1024 };
  
  for (int i = 0; i < 7; i++) { // el tamano de notes
    buttonState = digitalRead(buttonPins[i]);

    if (buttonState == HIGH) {
      if (altavozUno) {
        setPwmFrequency(altavozPin, devs[i]);
        analogWrite(altavozPin, 10);
        altavozUno = false;
      }
      else {
        //analogWrite(altavozPin, 0);
      }    
    }
    
  }

}



