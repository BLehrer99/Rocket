#include "globals.h"

void writeSD() {
  File myFile = SD.open("log.txt", FILE_WRITE);
  char str[400];
  snprintf(str, sizeof(str),
           "T%07d, mag: %03d, agl: %03d, accentRate: %03d, pitch: %03d, yaw: %03d, roll: %03d, thrust: %03d, rYaw: %03d, rPitch: %03d, rollComp: %03d, launchPitch: %03d, ignitionSwitch: %03d, legs: %03d, message: %s"
           , tTime, telemetry.mag, telemetry.agl, telemetry.accentRate, telemetry.pitch, telemetry.yaw, telemetry.roll, servos.thrust, servos.rYaw - (SERVORANGE / 2), servos.rPitch - (SERVORANGE / 2), servos.rollComp - (SERVORANGE / 2), servos.launchPitch - (SERVORANGE / 2), servos.ignitionSwitch, servos.legs, message.c_str());
  myFile.println(str);
  myFile.close();
}
