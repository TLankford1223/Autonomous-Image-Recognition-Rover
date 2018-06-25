
//
// ********************************************
// File: tracked_rover_control_v1.ino
// Author: Tanner Lankford
// Date: 6/22/18
// Desc: Program controls tracked rover using Arduino Uno board 
//       dfrobotshop rover v2 platform via android controller
//       application. 
// ********************************************
//
#include "tracked_rover_control_v1.h"

test_bench test;

void setup() {
  for(int i=5;i<=9;i++){
    pinMode(i,OUTPUT); // Sets motor control and trigger pins for output 
  }
  pinMode(ECHOPIN,INPUT);
  pinMode(LEDPIN,OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup for dfrobotshop rover v2 done");
}

void loop() {
 
  while (Serial.available() < 1) {} // Waits for control input
  char val = Serial.read(); 
  

    switch(val) {
      case 'x': // user control
      case 'X':
        user_control();
        break;
      case 'y': // autonomous mode
      case 'Y':
       auto_object_avoid();
        break;
      case 'z': // test run
      case 'Z':    
        test.motor_control();
        break;
      default:
        stop();
        break;
    }
  }


/**
 * Function: void user_control();
 * Desc: Allows user to control rover via bluetooth android app.
 *       user_control() calls the the motor control functions.
 */
void user_control(){
  
  Serial.println("User control");

   
  while(1){
    while (Serial.available() < 1) {}
   char val = Serial.read();
  switch(val){
    case 'w':
    case 'W':
      forward(MOTORSPEED);
      break;
    case 's':
    case 'S':
      reverse(MOTORSPEED);
      break;
    case 'a':
    case 'A':
      turn_left(MOTORSPEED);
      break;
    case 'd':
    case 'D':
      turn_right(MOTORSPEED);
      break;
    case 'q':
    case 'Q':
      Serial.println("Return to main loop");
      return;
      break;
    default:
      stop();
      break;
  }
 }
}



/**
 * Desc: Functions below control motor directions and speeds 
 * 
 * @param spd refers to motor speed
 * 
 */
void stop(void) //Stop
{
  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);
  Serial.println("stop");
}

void forward(char spd)
{
  analogWrite (E1,spd);
  digitalWrite(M1,HIGH);
  analogWrite (E2,spd);
  digitalWrite(M2,HIGH);
  Serial.println("forward");
}

void reverse (char spd)
{
  analogWrite (E1,spd);
  digitalWrite(M1,LOW);
  analogWrite (E2,spd);
  digitalWrite(M2,LOW);
  Serial.println("reverse");
}

void turn_left (char spd)
{
  analogWrite (E1,spd);
  digitalWrite(M1,HIGH);
  analogWrite (E2,spd);
  digitalWrite(M2,LOW);
  Serial.println("left");
}

void turn_right (char spd)
{
  analogWrite (E1,spd);
  digitalWrite(M1,LOW);
  analogWrite (E2,spd);
  digitalWrite(M2,HIGH);
  Serial.println("right");
}




