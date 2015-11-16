/*
Test Code for using Phantom YoYo wRobot Light Sensor

Created by: Scott Edgerly 
Created on 04/12/2104
Written and Tested on Arduino Diecimila 1.0

Pin Assignments:
GND - GND
VCC - 5V
OUT - A0
*/

int sensorPin = A0;
int sensorVal = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("void setup() complete");
}

void loop(){
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);
  delay(500);
}
