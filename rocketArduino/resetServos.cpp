#include "globals.h"

void resetServos() {
  servos.setThrust(0);
  servos.setRPitch(SERVORANGE / 2);
  servos.setRYaw(SERVORANGE / 2);
  servos.setRollComp(SERVORANGE / 2);
  servos.setLaunchPitch(SERVORANGE / 2);
  servos.setIgnitionSwitch(0);
  if (phase < 7)
    servos.setLegs(0);
  message += "reseting servos, ";
}
