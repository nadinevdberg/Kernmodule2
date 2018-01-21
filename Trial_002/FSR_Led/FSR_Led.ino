//bron : https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

int fsrAnalogPin = 0; // Force Sensitive Resistor (FSR) pin 0
int LEDpin = 8;  // led pin 8
int fsrReading; // value read from fsr
int LEDbrightness;

void setup() {
 Serial.begin(9600); // start serial monitor
 pinMode(LEDpin, OUTPUT);

}

void loop() {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog readin = ");
  Serial.println(fsrReading);

  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
  
  delay(100);
}
