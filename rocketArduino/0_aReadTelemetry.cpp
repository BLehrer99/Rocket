#include "globals.h"

void readTelemetry() {
  telemetry.magRead();
  telemetry.aglRead();
  float prevAccentRate = telemetry.accentRate;
  telemetry.accentRateRead();
  telemetry.accelerationRead(prevAccentRate);
  telemetry.gyroRead();
}

void Telemetry::magRead() {
  compass.read();
  mag = compass.heading();
}

void Telemetry::aglRead() {
  double P = getPressure();
  if (P == -9999)
    P = 0;
  agl = pressure.altitude(P, qfe);
}

void Telemetry::accentRateRead() {
  accentSamplesPerSecond = 1.0 / (micros() - prevAltMicros);
  prevAltMicros = micros();
  accentRate = (agl - prevAgl) * accentSamplesPerSecond;
}

void Telemetry::accelerationRead(float prevAccentRate) {
  acceleration = (accentRate - prevAccentRate) / accentSamplesPerSecond;
}

void Telemetry::gyroRead() {
  gyro.read();
  float samplesPerSecond = 1.0 / (micros() - prevGyroMicros);
  prevGyroMicros = micros();

  pitchRate = (float)gyro.g.x;
  yawRate = (float)gyro.g.y;
  rollRate = (float)gyro.g.z;

  float deltaPitch = pitchRate * samplesPerSecond;
  float deltaYaw = yawRate * samplesPerSecond;
  float deltaRoll = rollRate * samplesPerSecond;

  pitch = (int)(pitch + deltaPitch) % 360;
  yaw = (int)(yaw + deltaYaw) % 360;
  roll = (int)(roll + deltaRoll) % 360;
}

double Telemetry::getPressure() {
  char status;
  double T, P;
  status = pressure.startTemperature();
  if (status != 0) {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0) {
      status = pressure.startPressure(3);
      if (status != 0) {
        delay(status);
        status = pressure.getPressure(P, T);
        if (status != 0) {
          return (P);
        } else {
          message += "error: retrieving pressure measurement, ";
          return -9999;
        }
      } else {
        message += "error: starting pressure measurement, ";
        return -9999;
      }
    } else {
      message += "error: retrieving temperature measurement, ";
      return -9999;
    }
  } else {
    message += "error: starting temperature measurement, ";
    return -9999;
  }
  message += "error: reached end of getPressure, ";
  return -9999;
}
