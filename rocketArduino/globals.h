#ifndef GLOBALS_H
#define GLOBALS_H

#include "Arduino.h"

#include <Wire.h>

#include <SFE_BMP180.h>
#include <LSM303.h>
#include <L3G.h>

#include <SPI.h>

#include <SD.h>

#include <Servo.h>

#define DELTAT 0.01
#define COUNTLENGTH 3

#define ABORTPIN 48
#define FAIRINGPIN 49

#define THRUSTPIN 2
#define RYAWPIN 3
#define RPITCHPIN 5
//skip 4, sd
#define ROLLCOMPPIN 6
#define IGNITIONSWITCHPIN 7
#define LEGS0PIN 8
#define LEGS1PIN 9
#define LEGS2PIN 10
#define LEGS3PIN 11

#define SERVORANGE 180

#define ENGINEDELAY 4000 //ms

extern LSM303 compass;
extern L3G gyro;
extern SFE_BMP180 pressure;

extern File myFile;

extern int phase; //phase of flight
extern String message; //important message to be written to sd card

extern int countdownStart; //records start time of countdown
extern int tTime;

class Telemetry {
  public:
    void magRead();
    double getPressure();
    void aglRead();
    void accentRateRead();
    void accelerationRead(float prevAccentRate);
    void gyroRead();

    float mag;
    float agl;
    float prevAgl;
    float accentRate;
    float pitch;
    float yaw;
    float roll;
    float pitchRate;
    float yawRate;
    float rollRate;
    float acceleration;

    double qfe;

  private:
    unsigned long prevAltMicros = 0;
    unsigned long prevGyroMicros = 0;
    int accentSamplesPerSecond;
};

extern Telemetry telemetry;

class Servos {
  public:
    void setThrust(int);
    void setRYaw(int);
    void setRPitch(int);
    void setRollComp(int);
    void setIgnitionSwitch(int);
    void setLegFin(int, int);

    int thrust;
    int rYaw;
    int rPitch;
    int rollComp;
    int launchPitch;
    int ignitionSwitch;
    int legs[4];
};

extern Servos servos;

void readTelemetry();
void checkCase();
void updateControls();
void writeSD();
void startup();
void test();
void countdown();
void ignition();
void accent();
void apogee();
void decent();
void landing();
void shutoff();
void resetServos();

extern Servo Thrust;
extern Servo RYaw;
extern Servo RPitch;
extern Servo RollComp;
extern Servo IgnitionSwitch;
extern Servo LegFin0;
extern Servo LegFin1;
extern Servo LegFin2;
extern Servo LegFin3;

#endif
