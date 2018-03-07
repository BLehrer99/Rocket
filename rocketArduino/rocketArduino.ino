#include "globals.h"

void setup() {  
  pinMode(ABORTPIN, INPUT);
  Thrust.attach(THRUSTPIN);
  RYaw.attach(RYAWPIN);
  RPitch.attach(RPITCHPIN);
  RollComp.attach(ROLLCOMPPIN);
  LaunchPitch.attach(LAUNCHPITCHPIN);
  IgnitionSwitch.attach(IGNITIONSWITCHPIN);
  Legs.attach(LEGSPIN);
}

int mPrevMillis = 0;
void loop() {
  if (millis() - mPrevMillis >= 1000 * DELTAT) {
    mPrevMillis = millis();
    message = "";
    tTime = phase >= 2 ? (millis() - countdownStart) - (1000 * COUNTLENGTH) : -1000000;
    readTelemetry();
    checkCase();
    writeSD();
  }
}

