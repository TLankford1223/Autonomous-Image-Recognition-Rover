// 
// ***************************************
// File: tracked_rover_control_v1.h
// Author: Tanner Lankford
// Date: 6/22/18
// Desc: Header file for tracked_rover_control_v1.h
// ***************************************
//

#ifndef HEADER_FILE
#define HEADER_FILE


 #include "tracked_rover_v1_autonomous.h"
 #include <test_bench.h>



// Pin assignments
#define E2 6 // Left Motor Speed (analogWrite 0-255) 
#define E1 5 // Right Motor Speed (analogWrite 0-255)
#define M2 8 // M1 Direction (HIGH = Forward, LOW = Backward)
#define M1 7 // M2 Direction (HIGH = Forward, LOW = Backward)


// Constant declarations
#define MOTORSPEED 150 // Max motor speed is 255


// Function declarations
void user_control();
void forward(char spd);
void reverse(char spd);
void turn_left(char spd);
void turn_right(char spd);
void stop();


#endif
