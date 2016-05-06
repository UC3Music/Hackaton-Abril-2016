#include <Servo.h>

Servo myservo;
int pulsador=LOW;  
int lastPulsador=LOW;  
int pos = 0;  

void setup() {
  myservo.attach(11);
  pinMode(12, INPUT);
  myservo.write(45);                      
           
}


void loop() {
 
  pulsador = digitalRead(12);
  if((pulsador==HIGH)&&(lastPulsador==LOW)) { 
    myservo.write(5);           
    delay(100);  
    myservo.write(45);                      
  }
  lastPulsador=pulsador;

}
