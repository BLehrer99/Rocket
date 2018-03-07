#include "globals.h"

void setup() {
  Wire.begin();

  pinMode(ABORTPIN, INPUT);

  Thrust.attach(THRUSTPIN);
  RYaw.attach(RYAWPIN);
  RPitch.attach(RPITCHPIN);
  RollComp.attach(ROLLCOMPPIN);
  LaunchPitch.attach(LAUNCHPITCHPIN);
  IgnitionSwitch.attach(IGNITIONSWITCHPIN);
  Legs.attach(LEGSPIN);
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

