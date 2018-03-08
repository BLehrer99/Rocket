#include "globals.h"

void ignition() {
  //servos.setIgnition(ignition degrees);
  if(telemetry.agl >= 1){
    message += "liftoff, ";
    ++phase;
  }
}

