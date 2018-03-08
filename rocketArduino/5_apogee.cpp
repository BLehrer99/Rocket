#include "globals.h"

bool fairingSep = false;

void apogee() {
  if (digitalRead(FAIRINGPIN) == HIGH) {
    message += "error: fairing not jettisoned, ";
  } else {
    fairingSep = true;
    message += "fairing jettison confirmed, ";
  }
  //stow accent pitch fin
  ++phase;
}

