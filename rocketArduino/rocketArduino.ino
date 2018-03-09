#include "globals.h"

void setup() {
  Wire.begin();

  pinMode(ABORTPIN, INPUT);

  Thrust.attach(THRUSTPIN);
  RYaw.attach(RYAWPIN);
  RPitch.attach(RPITCHPIN);
  RollComp.attach(ROLLCOMPPIN);
  IgnitionSwitch.attach(IGNITIONSWITCHPIN);
  LegFin0.attach(LEGS0PIN);
  LegFin1.attach(LEGS1PIN);
  LegFin2.attach(LEGS2PIN);
  LegFin3.attach(LEGS3PIN);
}

long prevMillis;
void loop() {
  if (millis() - prevMillis >= 1000 * DELTAT) {
    prevMillis = millis();
    message = "";
    tTime = phase >= 2 ? (millis() - countdownStart) - (1000 * COUNTLENGTH) : -1000000;
    readTelemetry();
    checkCase();
    writeSD();
  }
}

