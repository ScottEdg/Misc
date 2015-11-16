/*
Test code for printing data from DHT11 and DHT 22 Temperature Sensors to a 
SainSmart I2C LCD2004 20x4 LCD screen.

Created by: Scott Edgerly
Created on: 4/27/2014
Written and Tested on Arduino Deicimila 1.0

Pin Assingments:
SainSmart LCD
GND - GND
VCC - 5V
SDA - A4
SCL - A5

DHT22 Sensor(sensor facing user)
from left to right
VCC - 5V
Data - pin 2
2nd pin from right most is unused
GND - GND
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h> 
#include "DHT.h"

DHT dht;

#define I2C_ADDR    0x27 //This is the address of the I2C adapter.  Use the I2C Address Finder code that can be found on the Arduino website.
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); //Need to research what this does.

int n=1;
float t1=0;
float t2=0;
void setup() {
  lcd.begin (20,4);  //This tells the arduino what size the LCD screen is (Columns, Rows).  Change accordingly to what hardware is avaiable.
  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);//need to research what this does.
  lcd.setBacklight(HIGH);  //Turns on backlight
  lcd.home ();                   //sets cursor to (0,0)
  dht.setup(2); // data pin 2
  //dht.setup(1); //data pin 1
  
}

void loop(){
  dht.setup(n);
  delay(dht.getMinimumSamplingPeriod());
   float temperature = dht.getTemperature();
  //lcd.on();
  if(n==1){
  lcd.print("DHT11: "); //prints text inside the quotation marks to screen.
  lcd.print(dht.toFahrenheit(temperature));
  t1=dht.toFahrenheit(temperature);
  lcd.print(" F");
  //lcd.setCursor (0,1);  //Sets cursor to write the next line of text on the 2nd row.  Note, position (0,0) is the first position.
  //lcd.print("Which is also"); //prints text to screen
  }
  if(n==2){
  lcd.setCursor (0,2); //Sets cursor to write on the 3rd row.
  lcd.print("DHT22: ");
  lcd.print(dht.toFahrenheit(temperature));
  t2=dht.toFahrenheit(temperature);
  lcd.print(" F");
  lcd.setCursor(0,3);  //sets cursor to write on the 4th row
  lcd.print("");
  
  }
 // delay(1500);
  float average =(t1+t2)/2;
  lcd.setCursor (0,1);
  lcd.print("average: ");
  lcd.print(average);
  lcd.print(" F");
  lcd.home();
  //lcd.off();
  n==2?n=1:n=2;
  //delay(1500);
}
