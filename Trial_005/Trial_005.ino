//bron: http://www.instructables.com/id/Arduino-Photoresistor-LED-onoff/
//bron: https://www.arduino.cc/en/Tutorial/toneKeyboard

#include "pitches.h"   //laad pitches in

int notes[]={NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4};  // tonen die gespeeld worden door de buzzer, afkomstig uit pitches.h

int resistor_Input = 5; //value for the resistor. buzzer will now only turn on if a vinger or hand is put on top of the resistor

int ledPin = 5;  // pin 5 == lampje
int brightness = 0;
int fadeAmount = 5;


void setup() {

 Serial.begin(9600); //start serial monitor
 pinMode (ledPin, OUTPUT); // digitale pin als output

}

void loop() {

for (int thisSensor = 0; thisSensor < 4; thisSensor++){ //gaat alle sensors af
int resistorValue = analogRead(thisSensor); //leest de sensor uit
  Serial.println(resistorValue); //print de waarde van de sensor


   
  if (resistorValue < resistor_Input){  //als het donker genoeg is oftewel: als een hand op de sensor ligt
  tone(8, notes[thisSensor],20);  // speel een toon af 
  digitalWrite(ledPin, brightness); // zet het lampje aan
  brightness = brightness + fadeAmount;
  
    }else {
    digitalWrite(ledPin, LOW);
    
    }
    }
  }





