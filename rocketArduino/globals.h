#ifndef GLOBALS_H
#define GLOBALS_H

#include "Arduino.h"

#include <SFE_BMP180.h>
#include <LSM303.h>
#include <L3G.h>

#include <SD.h>

#include <Servo.h>

#define DELTAT 0.01
#define COUNTLENGTH 3

#define ABORTPIN 22
#define THRUSTPIN 2
#define RYAWPIN 3
#define RPITCHPIN 5
#define ROLLCOMPPIN 6
#define LAUNCHPITCHPIN 7
#define IGNITIONSWITCHPIN 8
#define LEGSPIN 8

#define SERVORANGE 180

extern int phase; //phase of flight
extern String message; //important message to be written to sd card

extern int countdownStart; //records start time of countdown
extern int tTime;

class Telemetry {
  public:
    void magRead();
    void aglRead();
    void accentRateRead();
    void pitchRead();
    void yawRead();
    void rollRead();

    int mag;
    int agl;
    int prevAgl[3];
    int accentRate;
    int pitch;
    int yaw;
    int roll;
};

extern Telemetry telemetry;

class Servos {
  public:
    void setThrust(int);
    void setRYaw(int);
    void setRPitch(int);
    void setRollComp(int);
    void setLaunchPitch(int);
    void setIgnitionSwitch(int);
    void setLegs(int);

    int thrust;
    int rYaw;
    int rPitch;
    int rollComp;
    int launchPitch;
    int ignitionSwitch;
    int legs;
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
void peak();
void decent();
void landing();
void shutoff();
void resetServos();

extern Servo Thrust;
extern Servo RYaw;
extern Servo RPitch;
extern Servo RollComp;
extern Servo LaunchPitch;
extern Servo IgnitionSwitch;
extern Servo Legs;

#endif
