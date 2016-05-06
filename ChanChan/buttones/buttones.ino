#include <Servo.h>

#include "pitches.h"

//-- Servo
Servo myservo;
int pulsador=LOW;  
int lastPulsador=LOW;  

// los tonos 
int notes[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 };

// los pin numbers EL TAMANO TIENE QUE SER IQUAL QUE LO DE notes
int buttonPins[] = { 2, 3, 4, 5, 6, 7, 8 , 9};
// los estados de los bottones (indeces corresponden a los de buttonPins)
int buttonState = 0;

// el pin del altavoz
int altavozPins[] = { 10 };

bool toggle;

void setup() {
  myservo.attach(11);
  pinMode(13, OUTPUT);        
  pinMode(12, INPUT);
  for (int i = 0; i < 8; i++) { // el tamano de buttonPins
    pinMode(buttonPins[i], INPUT);
  }
  toggle = true;
     myservo.write(40); 
}

void loop() {

  bool altavozUno = true;
  
  for (int i = 0; i < 8; i++) { // el tamano de notes
    buttonState = digitalRead(buttonPins[i]);

    if (buttonState == HIGH) {
      if (altavozUno) {
        tone(altavozPins[0], notes[i],20);
        altavozUno = false;
      }
      else {
        // do nothing
      }    
    }    
  }
  pulsador = digitalRead(12);
  if((pulsador==HIGH)&&(lastPulsador==LOW)) { 
    myservo.write(0);           
    delay(100);  
    myservo.write(40);                      
    delay(100);  
  }
  lastPulsador=pulsador;
}



