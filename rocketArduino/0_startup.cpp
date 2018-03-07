#include "globals.h"

void startup() {
  if (digitalRead(ABORTPIN) == HIGH){
    message = "aborted";
    phase = 9;
    return;
  }
  resetServos();
  message = "startup initiated: calibrating";
  ++phase;
}

