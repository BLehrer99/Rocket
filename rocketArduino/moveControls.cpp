#include "globals.h"

void Servos::setThrust(int val) {
  thrust = val;
  Thrust.write(thrust);
}

void Servos::setRYaw(int val) {
  rYaw = val;
  Thrust.write(rYaw);
}

void Servos::setRPitch(int val) {
  rPitch = val;
  RPitch.write(rPitch);
}

void Servos::setRollComp(int val) {
  rollComp = val;
  RollComp.write(rollComp);
}

void Servos::setIgnitionSwitch(int val) {
  ignitionSwitch = val;
  IgnitionSwitch.write(ignitionSwitch);
}
void Servos::setLegFin(int number, int val) {
  legs[number] = val;
  switch (number) {
    case 0:
      LegFin0.write(legs[0]);
    case 1:
      LegFin1.write(legs[1]);
    case 2:
      LegFin2.write(legs[2]);
    case 3:
      LegFin3.write(legs[3]);
  }
}
