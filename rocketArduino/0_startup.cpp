#include "globals.h"

void setupCompass() {
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>) {
    -32767, -32767, -32767
  };
  compass.m_max = (LSM303::vector<int16_t>) {
    +32767, +32767, +32767
  };
}

int setupGyro() {
  if (!gyro.init()) {
    message += "aborted: failed to detect gyro, ";
    phase = 9;
    return 0;
  }

  gyro.enableDefault();
  telemetry.pitch = 0;
  telemetry.yaw = 0;
  telemetry.roll = 0;
  return 1;
}

int setupPressure() {
  if (!pressure.begin()) {
    message += "aborted: failed to setup pressure, ";
    phase = 9;
    return 0;
  }
  telemetry.qfe = telemetry.getPressure();
  if (telemetry.qfe == -9999) {
    message += "aborted: failed to setup get pressure, ";
    phase = 9;
    return 0;
  }
  return 1;
}

void startup() {
  if (digitalRead(ABORTPIN) == HIGH) {
    message += "aborted: abort switch, ";
    phase = 9;
    return;
  }
  
  myFile = SD.open("log.txt", FILE_WRITE);
  
  resetServos();

  setupCompass();

  if (!setupGyro())
    return;

  if (!setupPressure())
    return;

  message += "startup initiated: calibrating, ";
  ++phase;
}
