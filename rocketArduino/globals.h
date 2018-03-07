#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFE_BMP180.h>
#include <LSM303.h>
#include <L3G.h>
#include "Arduino.h"

#include <SD.h>

extern int phase;
extern String message;

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


#endif
