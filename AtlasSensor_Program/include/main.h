/* ----- Headers ----- */
#include <Arduino.h>
#include "AtlasSensor.h"

/* ----- Defines ----- */
#define BAUDRATE            9600
#define disOxySensor_addr   0x61
#define ORPSensor_addr      0x62
#define pHSensor_addr       0x63
#define ConducSensor_addr   0x64
#define TempSensor_addr     0x66

/* ----- Local Functions ----- */
static void MX_AtlSensor_Init(void);        // Sensor Init
static void AtlSensor_requestValue(void);   // Task 1
static void AtlSensor_transmitValue(void);  // Task 2