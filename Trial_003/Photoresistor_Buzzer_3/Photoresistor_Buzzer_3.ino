//bron: http://www.instructables.com/id/Arduino-Photoresistor-LED-onoff/
//bron: https://www.arduino.cc/en/Tutorial/toneKeyboard

#include "pitches.h"

int notes[]={NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4};

int resistor_Input = 5; //value for the resistor. buzzer will now only turn on if a vinger or hand is put on top of the resistor





void setup() {

 Serial.begin(9600); //start serial monitor
 

}

void loop() {

for (int thisSensor = 0; thisSensor < 4; thisSensor++){
int resistorValue = analogRead(thisSensor); //read the sensor
  Serial.println(resistorValue);
  
if (resistorValue < resistor_Input){  //als het donker genoeg is oftewel als een hand op de sensor ligt
  tone(8, notes[thisSensor],20);
}
}

}


