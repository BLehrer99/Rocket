#include "globals.h"

void writeSD() {
  File myFile = SD.open("log.txt", FILE_WRITE);
  char str[400];
  snprintf(str, sizeof(str),
           "T%07d, mag: %03d, agl: %03d, accentRate: %03d, pitch: %03d, yaw: %03d, roll: %03d, thrustPos: %03d, mYawPos: %03d, mPitchPos: %03d, rollCompPos: %03d, launchPitchPos: %03d, ignitionSwitchPos: %03d, message: %s"
           , tTime, telemetry.mag, telemetry.agl, telemetry.accentRate, telemetry.pitch, telemetry.yaw, telemetry.roll, servos.thrust, servos.rYaw - (SERVORANGE / 2), servos.rPitch - (SERVORANGE / 2), servos.rollComp - (SERVORANGE / 2), servos.launchPitch - (SERVORANGE / 2), servos.ignitionSwitch, message.c_str());
  myFile.println(str);
  myFile.close();
}
