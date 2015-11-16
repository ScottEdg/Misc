/*
Test code for using SainSmart I2C LCD2004 adapter for HD44780 LCD screen

Created by: Scott Edgerly
Created on 4/26/2014
Written and Tested on Arduino Diecimila 1.0

Pin Assignments:
GND - GND
VCC - 5V
SDA - A4
SCL - A5
*/
#include <Wire.h> //Research what this does.
#include <LiquidCrystal_I2C.h> //This includes the library to control LCDs that have an I2C adapter

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

void setup() {
  lcd.begin (20,4);  //This tells the arduino what size the LCD screen is (Columns, Rows).  Change accordingly to what hardware is avaiable.
  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);//need to research what this does.
  lcd.setBacklight(HIGH);  //Turns on backlight
  lcd.home ();                   //Need to research what this does
  
  lcd.print("SainSmart Test Code"); //prints text inside the quotation marks to screen.
  lcd.setCursor (0,1);  //Sets cursor to write the next line of text on the 2nd row.  Note, position (0,0) is the first position.
  lcd.print("Created by"); //prints text to screen
  lcd.setCursor (0,2); //Sets cursor to write on the 3rd row.
  lcd.print("Scott Edgerly");
  lcd.setCursor(0,3);  //sets cursor to write on the 4th row
  lcd.print("04/26/2014");
}

void loop(){

}
