//bron: http://www.instructables.com/id/Arduino-Photoresistor-LED-onoff/

int resistor = 0; //analoog 0
int resistorValue = 0;  //output value
int resistor_Input = 80; //value when light is on. Light will now only turn on if a vinger or hand is put on top of the resistor

int buzzpin = 9;



void setup() {
resistorValue = analogRead(resistor);
pinMode(resistor,INPUT);
pinMode(buzzpin,OUTPUT);

 Serial.begin(9600); //start serial monitor
 

}

void loop() {
resistorValue = analogRead(resistor);
Serial.println(resistorValue); // print value photoresistor
delay(100); // value updated every 0.1 second

if (resistorValue < resistor_Input) //if sensor value is less than 8, make noise
{
  buzz(50); //waarde staat voor de delay
  }
}

void buzz(unsigned char time){
  analogWrite(buzzpin, 500);
 delay(time);
  analogWrite(buzzpin, 0);
  delay(time);
}

