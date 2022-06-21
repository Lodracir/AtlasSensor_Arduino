/* Librerias */
#include "Arduino.h"
#include <Wire.h>

typedef enum
{
  ph_Sensor,
  disOxy_Sensor,
  ORP_Sensor,
  Conduct_Sensor,
  Temp_Sensor
}sensorType_t;

class AtlSensor
{
  
  private:
  /* Variables Privadas */
  sensorType_t  sensorType;
  uint8_t       _address;

  /* Funciones Privadas */
  void writeCommand(char str[]);
  
  public:
  
  /* Funciones Publicas */
  void      init(uint8_t _addr, sensorType_t _sensorType);     // Set device Address for I2C
  uint8_t   getAddress(void);                             // Get device Address 
  byte      getValue(char _value[]);                      // Get pH Value
  void      find(void);
  void      setName(char _name[]);                        // Set device name
  void      getName(void);                                // Get device name 
};
