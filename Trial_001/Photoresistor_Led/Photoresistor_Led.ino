//bron: http://www.instructables.com/id/Arduino-Photoresistor-LED-onoff/

int Resistor = 0; //analoog 0
int ResistorValue = 0;  //output value
int Resistor_Input = 8; //value when light is on. Light will now only turn on if a vinger or hand is put on top of the resistor



void setup() {
 ResistorValue = analogRead(Resistor);

 Serial.begin(9600); //start serial monitor
 
 pinMode(8, OUTPUT); // pin 8 output light

}

void loop() {
ResistorValue = analogRead(Resistor);
Serial.println(ResistorValue); // print value photoresistor
delay(100); // value updated every 0.1 second

if (ResistorValue < Resistor_Input) //if sensor value is less than 8, turn light on
{digitalWrite(8,HIGH);} else { digitalWrite(8, LOW); }
}
