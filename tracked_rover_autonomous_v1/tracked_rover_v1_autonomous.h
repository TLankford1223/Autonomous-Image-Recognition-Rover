//
// ********************************************
// File: tracked_rover_v1_autonomous.h
// Author: Tanner Lankford
// Date: 6/22/18
// Desc: Header file for tracked_rover_v1_autonomous_cpp
// ********************************************
//
#ifndef AUTO_HEADER_FILE
#define AUTO_HEADER_FILE


#include <Arduino.h>
#include "tracked_rover_control_v1.h"
#include <test_bench.h>

// Pin assignments
#define TRIGPIN 9 // Ultrasound Trigger
#define ECHOPIN 12 // Ultrasound Echo
#define LEDPIN 13 //Onboard LED


// Constant declarations
#define MAXRANGE 200
#define MINRANGE 0
#define MIN_DIST 20

// Function declarations
extern void auto_object_avoid();
extern float distance_US();

#endif
