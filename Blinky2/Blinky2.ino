/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

double x;
int i;

int incomingByte;



#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken



void setup()
  {
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(9600);
  }


void loop() 
  {
   x++;
   Serial.print(x);
   Serial.print("\r\n");

   // step forward 
   for(i=0; i<200; i++)
     {
      myStepper.step(5);
      delay(5);    
     }
   digitalWrite(LED_BUILTIN, HIGH);   // on
   delay(1000);
   digitalWrite(LED_BUILTIN, LOW);    // off

   // step backward
   for(i=0; i<200; i++)
     {
      myStepper.step(-5);
      delay(5);    
     }
   digitalWrite(LED_BUILTIN, HIGH);   // on
   delay(1000);
   digitalWrite(LED_BUILTIN, LOW);    // off



   // Any received data?
   if (Serial.available() > 0) 
     {
      // read the incoming byte:
      incomingByte = Serial.read();
      // say what you got:
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);
      
      // make a step for alignment
      myStepper.step(1);
      delay(5);    

     }
  
  }


