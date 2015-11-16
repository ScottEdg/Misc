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
void setup(){
  pinMode(ledb, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  analogWrite(ledb, blight);
  analogWrite(ledg, glight);
  analogWrite(ledr, rlight);
}

void loop(){

  blue();
  delay(1000);

  red();
  delay(1000);
  
  green();
  delay(1000);
  
  purple();
  delay(1000);
  
  yellow();
  delay(1000);
  
  aqua();
  delay(1000);  
}

void blue(){
  char flag = 0;
  while (flag == 0){
    if(blight>bgon){
      blight--;
      analogWrite(ledb, blight);
    }
     if(glight<off){
       glight+=1;
       analogWrite(ledg, glight);
    }
    if(rlight<off){
        rlight+=1;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==bgon && glight == off && rlight == off){
      flag = 1;
    }
  } 
}

void red(){
  char flag = 0;
  while (flag == 0){
    if(blight<off){
      blight++;
      analogWrite(ledb, blight);
    }
     if(glight<off){
       glight++;
       analogWrite(ledg, glight);
    }
    if(rlight>ron){
        rlight--;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==off && glight == off && rlight == ron){
      flag = 1;
    }
  } 
}

void green(){
  while (flag == 0){
    if(blight<off){
      blight++;
      analogWrite(ledb, blight);
    }
     if(glight>bgon){
       glight--;
       analogWrite(ledg, glight);
    }
    if(rlight<off){
        rlight++;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==off && glight == bgon && rlight == off){
      flag = 1;
    }
  }
 flag = 0; 
}

void purple(){
  while (flag == 0){
    if(blight>ron){
      blight--;
      analogWrite(ledb, blight);
    }
     if(glight<off){
       glight++;
       analogWrite(ledg, glight);
    }
    if(rlight>ron){
        rlight--;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==ron && glight == off && rlight == ron){
      flag = 1;
    }
  } 
  flag = 0;
}

void yellow(){
  while (flag == 0){
    if(blight<off){
      blight++;
      analogWrite(ledb, blight);
    }
     if(glight>ron){
       glight--;
       analogWrite(ledg, glight);
    }
    if(rlight>ron){
        rlight--;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==off && glight == ron && rlight == ron){
      flag = 1;
    }
  } 
  flag = 0;
}

void aqua(){
  while (flag == 0){
    if(blight>bgon){
      blight--;
      analogWrite(ledb, blight);
    }
     if(glight>bgon){
       glight--;
       analogWrite(ledg, glight);
    }
    if(rlight<off){
        rlight++;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==bgon && glight == bgon && rlight == off){
      flag = 1;
    }
  } 
  flag = 0;
}

void orange(){ // needs work not implemented yet
  while (flag == 0){
    if(blight<off){
      blight++;
      analogWrite(ledb, blight);
    }
     if(glight>ron-25){
       glight--;
       analogWrite(ledg, glight);
    }
    if(rlight>ron){
        rlight--;
        analogWrite(ledr, rlight);
    }
    delay (10);
    if(blight==off && glight == ron && rlight == ron){
      flag = 1;
    }
  }
 flag = 0; 
}
