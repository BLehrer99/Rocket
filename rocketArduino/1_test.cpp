#include "globals.h"

void test() {
  if (digitalRead(ABORTPIN) == HIGH) {
    message = "aborted";
    phase = 9;
    return;
  }
  message = "testing systems";
  countdownStart = millis();
}

