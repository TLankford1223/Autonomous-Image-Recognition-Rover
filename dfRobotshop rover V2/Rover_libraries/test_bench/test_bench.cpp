//
// ********************************************
// File: test_bench.cpp
// Author: Tanner Lankford
// Date: 6/23/18
// Desc: Library for implementing numerous tests
//       on robotic or electronic platform. 
//       (In progress).
// ********************************************
//
#include "test_bench.h"



// Function to test motor setting and latency in signal

test_bench::test_bench(){}

void test_bench::motor_control() {
      Serial.println("test run");
      Forward(MOTORSPEED);
      delay(2000);
      reverse(MOTORSPEED);
      delay(2000);
      turn_left(MOTORSPEED);
      delay(2000);
      turn_right(MOTORSPEED);
      delay(2000);
      stop();
      Serial.println("Return to main loop");
      return;
  }
