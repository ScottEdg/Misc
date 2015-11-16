/*
LED test code

Created by: Scott Edgerly
Created on: 05/10/2014

Pins Assingnments
V+ - 5V
LED - pin 3

note that 190 is a PWM output of 3.3 volts and
85 is an output of 3.22 volts for Blue and Green and
145 is an output of 2.04 volts for red
*/
#include <TrueRandom.h>

int LsensorPin = A1;
int LsensorVal = 0;

unsigned char ledb = 3;
unsigned char ledg = 5;
unsigned char ledr = 6;

unsigned char bgon = 85;
unsigned char ron = 145;
unsigned char off = 255;

unsigned char blight = off;
unsigned char glight = off;
unsigned char rlight = off;
unsigned char flag = 0;

unsigned char red[7] =   {ron, off, off, ron, off, ron};  //the colors are indexed as follows 0 = red, 1 = green, 2 = blue, 3 = yellow, 4 = aqua, 5 = purple
unsigned char green[7] = {off, bgon, off, bgon, bgon, off};
unsigned char blue[7] =  {off, off, bgon, off, bgon, bgon};

unsigned char colorChange[6] = {6, 15, 29, 44, 58};  //This array changes how long it takes to transition between colors. 0 = 1 sec, 1 = 2.5 sec, 2 = 5 sec, 3 = 7.5sec, 4 = 10sec.
unsigned int duration[7] = {10000, 20000, 30000, 40000, 50000, 60000};  //This array changes how long each color is on.

unsigned char i = TrueRandom.random(6);
unsigned char j = TrueRandom.random(5);
unsigned char k = TrueRandom.random(6);

unsigned long lastTimeC = 0;
unsigned long lastTimeD = 0;

void setup(){
  pinMode(ledb, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  analogWrite(ledb, blight);
  analogWrite(ledg, glight);
  analogWrite(ledr, rlight);
}

void loop(){
  analogWrite(ledb, blight);
  analogWrite(ledg, glight);
  analogWrite(ledr, rlight);
  while(LsensorVal>50){
    analogWrite(ledr, off);
    analogWrite(ledg, off);
    analogWrite(ledb, off);
    LsensorVal = analogRead(LsensorPin);
  }
  if((millis() - lastTimeD) > duration[k]){
    i = TrueRandom.random(6);
    j = TrueRandom.random(5);
    k = TrueRandom.random(6);
    flag = 1;
    lastTimeD = millis();
    LsensorVal = analogRead(LsensorPin);
  }
    if(((millis() - lastTimeC) > colorChange[j]) && flag == 1){
      if(red[i] != off){
        if(rlight>red[i]){
          rlight--;
        }
      }
      if(red[i] == off){
        if(rlight<red[i]){
          rlight++;
        }
      }   
      analogWrite(ledr, rlight);
    
      if(green[i] != off){
        if(glight>green[i]){
          glight--;
        }
      }
      if(green[i] == off){
        if(glight<green[i]){
          glight++;
        }
      }   
      analogWrite(ledg, glight);
    
      if(blue[i] != off){
        if(blight>blue[i]){
          blight--;
        }
      }
    
      if(blue[i] == off){
        if(blight<blue[i]){
          blight++;
        }
      }   
      analogWrite(ledb, blight);
      
      if(blight == blue[i] && glight == green[i] && rlight == red[i]){
        flag = 0;
      }
      lastTimeC = millis();
      LsensorVal = analogRead(LsensorPin);
  }
  LsensorVal = analogRead(LsensorPin);
}
