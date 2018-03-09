#include "globals.h"

bool fairingSep = false;

void apogee() {
  if (digitalRead(FAIRINGPIN) == HIGH) {
    message += "error: fairing not jettisoned, ";
  } else {
    fairingSep = true;
    message += "fairing jettison confirmed, ";
  }
  for (int i = 0; i < 4; ++i) {
    message += "legFins stowed";
    servos.setLegFin(0, 0);
  }
  //stow accent pitch fin
  ++phase;
}

