#include "globals.h"

void decent() {
  message += "retro burn, ";
  //decent sequece***************************

  if (telemetry.agl <= 5) {
    message += "landing, ";
    ++phase;
  }
}

