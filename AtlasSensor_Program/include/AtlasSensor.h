/* Librerias */
#include "Arduino.h"
#include <Wire.h>

typedef byte AtlasSensor_state_t;

/**/
typedef enum
{
  ph_Sensor,
  disOxy_Sensor,
  ORP_Sensor,
  Conduct_Sensor,
  Temp_Sensor
}sensorType_t;

/**/
class AtlSensor
{
  
  private:
  /* Variables Privadas */
  sensorType_t  sensorType;
  uint8_t       address;

  /* Funciones Privadas */
  void writeCommand(char str[]);
  
  public:
  
  /* Constructor para inicializar el sensor */
  AtlSensor(uint8_t address, sensorType_t sensorType)
  {
    this->address    = address;
    this->sensorType = sensorType;

  }

  /* Funciones Publicas */
  uint8_t   getAddress(void);                                 // Get device Address 
  byte      getValue(char _value[]);                          // Get pH Value
  void      find(void);
  void      setName(char _name[]);                            // Set device name
  void      getName(void);                                    // Get device name 
};
