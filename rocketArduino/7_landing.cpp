#include "globals.h"

bool landingStarted = false;

void landing() {
  message += "landing, ";
  if (!landingStarted) {
    landingStarted = true;
    message += "landing legs deploy, ";
    //servos.setLegs(leg down angle);
  }
  //landing routine************************
  if (telemetry.agl <= 1) {
    message += "landed, shutoff, ";
    ++phase;
  }
}

