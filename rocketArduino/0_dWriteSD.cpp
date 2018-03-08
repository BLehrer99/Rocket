#include "globals.h"

void writeSD() {
  char str[300];
  String plus = tTime >= 0 ? "+" : "";
  snprintf(str, sizeof(str),
           "T%s%07d, mag: %03d, agl: %03d, accentRate: %03d, acceleration: %02d, pitch: %03d, yaw: %03d, roll: %03d, thrust: %03d, rYaw: %03d, rPitch: %03d, rollComp: %03d, launchPitch: %03d, ignitionSwitch: %03d, legs: %03d, message: "
           , plus.c_str(), tTime, (int)telemetry.mag, (int)telemetry.agl, (int)telemetry.accentRate, (int)telemetry.acceleration, (int)telemetry.pitch, (int)telemetry.yaw, (int)telemetry.roll, servos.thrust, servos.rYaw - (SERVORANGE / 2), servos.rPitch - (SERVORANGE / 2), servos.rollComp - (SERVORANGE / 2), servos.launchPitch - (SERVORANGE / 2), servos.ignitionSwitch, servos.legs);
  myFile.print(str);
  myFile.println(message);
}
