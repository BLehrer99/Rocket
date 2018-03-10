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

File myFile;

Servo Thrust;
Servo RYaw;
Servo RPitch;
Servo RollComp0;
Servo RollComp1;
Servo RollComp2;
Servo RollComp3;
Servo LegFin0;
Servo LegFin1;
Servo LegFin2;
Servo LegFin3;

LSM303 compass;
L3G gyro;
SFE_BMP180 pressure;
