//
// ********************************************
// File: tracked_rover_v1_autonomous.cpp
// Author: Tanner Lankford
// Date: 6/23/18
// Desc: Program controls the atonoumous object
//       avoidance function of the rover 
// ********************************************
//
#include "tracked_rover_v1_autonomous.h"

 /**
  * Function:void auto_object_avoid();
  * Desc: Rover will move forward until min_dist
  *       is reached. It will then reverse and 
  *       turn left and repeat. Function calls
  *       float distance_US(). 
  */
 void auto_object_avoid(){
    int min_dist= MIN_DIST;
    float distance;
    
      distance = distance_US();
      Serial.print(distance);
      Serial.print("\t");
      
      
      Serial.println("Autonomous");
      char val = Serial.read();
      while(1){
        //char val = Serial.read();
        if(val == 'q' || val == 'Q') {
            Serial.println("Return to loop");
            return;
        }   
          while (distance > min_dist) {
            forward(MOTORSPEED);
            distance = distance_US();  
          }
          if (distance <= min_dist){
            reverse(MOTORSPEED);
            delay(1200);
            turn_left(MOTORSPEED);
            delay(1500);
            distance = distance_US();
          }
          else {
            if (distance > MAXRANGE){
            forward(MOTORSPEED);
            delay(2000);
            distance = distance_US();
            }
            else{
              return;
            }
          }
    }   
   }

  /**
    * Function:float distance_US();
    * Desc: Cycles the trigger and echo pins
    *       to determine distance of object
    *       via ultrasound. Return a distance 
    *       value of type float.
    */
   
  float distance_US(){
      float distance, duration;
      
      digitalWrite(TRIGPIN,LOW); 
      delayMicroseconds(2);

      digitalWrite(TRIGPIN,HIGH);
      delayMicroseconds(10);

      digitalWrite(TRIGPIN,LOW);
      duration = pulseIn(ECHOPIN,HIGH,1000000);

      
      distance = duration/58.2; // calculation based on speed of sound

      if (distance >= MAXRANGE || distance <= MINRANGE){
        Serial.println(-1);
        digitalWrite(LEDPIN,HIGH); // Toggles onboard LED to ON if object is out of range of ultrasound.
      }
      else {
        digitalWrite(LEDPIN,LOW); // Toggles onboard LED to OFF if object is in range of ultrasound.
      }
      return distance;
}

   
   
   
   
    
