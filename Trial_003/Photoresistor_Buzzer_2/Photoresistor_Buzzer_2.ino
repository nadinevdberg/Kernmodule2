//bron: http://www.instructables.com/id/Arduino-Photoresistor-LED-onoff/
//bron: https://www.arduino.cc/en/Tutorial/toneKeyboard

#include "pitches.h"

int notes[]={NOTE_A4, NOTE_B4};

int resistor1 = A0; //analoog 0
int resistor2 = A1;
int resistorValue1 = 0;  //output value resistor 1
int resistorValue2 = 0;  //output value resistor 2
int resistor_Input = 300; //value for the resistor. buzzer will now only turn on if a vinger or hand is put on top of the resistor

int buzzpin = 9;



void setup() {
resistorValue1 = analogRead(resistor1);
resistorValue2 = analogRead(resistor2);
pinMode(resistor1,INPUT);
pinMode (resistor2, INPUT);
pinMode(buzzpin,OUTPUT);

 Serial.begin(9600); //start serial monitor
 

}

void loop() {

for (int thisSensor = 0; thisSensor < 2; thisSensor++){
int resistorValue = analogRead(thisSensor); //read the sensor
  Serial.println(resistorValue);
if (resistorValue < resistor_Input){
  tone(8, notes[thisSensor],20);
}
}

}
  /*
resistorValue1 = analogRead(resistor1);
resistorValue2 = analogRead(resistor2);
Serial.print("sensor 1 = ") 
Serial.println(resistorValue1); // print value photoresistor 1
delay(100); // value updated every 0.1 second

Serial.print("sensor 2 = ") 
Serial.println(resistorValue1); // print value photoresistor 2
delay(100); // value updated every 0.1 second

if (resistorValue1 < resistor_Input) //if sensor value is less than 8, make noise
{
  tone(buzzpin, notes[thisSensor], 20);
  }
}
else if (resistorValue2 < resistor_Input) //if sensor value is less than 8, make noise
{
  buzz(20); //waarde staat voor de delay
  }
  */



