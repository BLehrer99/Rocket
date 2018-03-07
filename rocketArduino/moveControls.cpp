#include "globals.h"

void Servos::setThrust(int val){
  thrust = val;
  Thrust.write(thrust);
}

void Servos::setRYaw(int val){
  rYaw = val;
  Thrust.write(rYaw);
}

void Servos::setRPitch(int val){
  rPitch = val;
  RPitch.write(rPitch);
}

void Servos::setRollComp(int val){
  rollComp = val;
  RollComp.write(rollComp);
}

void Servos::setLaunchPitch(int val){
  launchPitch = val;
  LaunchPitch.write(launchPitch);
}

void Servos::setIgnitionSwitch(int val){
  ignitionSwitch = val;
  IgnitionSwitch.write(ignitionSwitch);
}
void Servos::setLegs(int val){
  legs = val;
  Legs.write(legs);
}
