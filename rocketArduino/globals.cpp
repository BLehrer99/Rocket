#include "globals.h"

int phase = 0;
/*
   phases
   0: startup, calibration
   1: control surface test
   2: countdown
   3: ignition
   4: accent
   5: peak
   6: decent
   7: landing
   8: shutoff
   9: powered off
*/


String message; //stores important info to write to sd card
int countdownStart;

int tTime;

Telemetry telemetry;
Servos servos;

Servo Thrust;
Servo RYaw;
Servo RPitch;
Servo RollComp;
Servo LaunchPitch;
Servo IgnitionSwitch;
Servo Legs;
