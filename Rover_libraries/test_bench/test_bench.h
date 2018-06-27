//
// ********************************************
// File: test_bench.h
// Author: Tanner Lankford
// Date: 6/23/18
// Desc: Header file for test_bench.cpp 
// ********************************************
//
#ifndef TEST_BENCH
#define TEST_BENCH

#include "tracked_rover_control_v1.h"
#include "tracked_rover_v1_autonomous.h"
#include <Arduino.h>

// Test function declarations
class test_bench {
     public:
          test_bench();
     void motor_control();
   // void buffer_filler();
   // void img_rec();
   // void voice_control();
};
#endif
