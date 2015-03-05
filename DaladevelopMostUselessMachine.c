/*
  Karl-Henrik Nilsson - Daladevelop hackaton 2015
  This code is inteded to be used to control the "off switch arm" of the "Usless machine" design that were lasercut at the Hackatons arranged by Soltorgsgymnasiet and Daladevelop.
  This code is inteded to be used with the Arduino UNO.
  
  The switch needs to be connected to PIN12 and PIN13. The switch should have a pulldown (connection to GND) of 10K Ohm on the side that is connected to PIN12.
  The servo signal is on PIN 9.
*/

#include <Servo.h> 


//Make changes to pin selections here.
#define switchPin 13
#define vPin 12 // +5V for the switch due to lack of +5v outputs.
#define servoSignalPin 9

Servo myservo;  // The servo object - this allows us to control the servo.
int pos = 0;    // The variable that holds the servo position 

void setup() 
{
  pinMode(switchPin,INPUT);
  pinMode(vPin,OUTPUT);

  myservo.attach(servoSignalPin);  // attaches the servo on pin 9 to the servo object 
  myservo.write(pos);

  delay(15);
  digitalWrite(vPin,1);
} 
 
void loop() 
{ 
    
    if(digitalRead(switchPin) == 1)
    {
      while(pos <= 130)
      {
        if(digitalRead(switchPin) == 0)
        {
          break;
        }  
        myservo.write(pos += 10);
        delay(50);  
      }
    }
    if(digitalRead(switchPin) == 0)
    {
      while(pos > 0)
      {
        if(digitalRead(switchPin) == 1)
        {
          break;
        }        
        myservo.write(pos -= 10);
        delay(50);  
      }
    }
    
} 
