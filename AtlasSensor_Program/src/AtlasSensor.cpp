/* Libreria */
#include "AtlasSensor.h"

/* ----- Defines ----- */
char read_cmd[2] = "r";
char find_cmd[5] = "find";

/* ----- Funciones Privadas ----- */
void AtlSensor::writeCommand(char str[])
{

  Wire.beginTransmission(this->address);  /* Open I2C Communication */
  Wire.write(str);                        /* Transmit Command */
  Wire.endTransmission();                 /* End Transmission */
  
}

/* ----- Funciones Publicas ----- */
uint8_t AtlSensor::getAddress(void)
{
  return this->address;
}

AtlasSensor_state_t AtlSensor::getValue(char _value[])
{

  /* Local Variables */
  byte  code;  
  byte  in_char;
  int   i = 0;
  int   delayTime = 0;
  
  writeCommand(read_cmd); // Send read command to pH Sensor 
  
  switch(sensorType)
  {
    case ph_Sensor:
      delayTime = 900;
      break;

    case ORP_Sensor:
      delayTime = 900;
      break;

    case disOxy_Sensor:
      delayTime = 600;
      break;

    case Temp_Sensor:
      delayTime = 600;
      break;

    case Conduct_Sensor:
      delayTime = 600;
      break;
  }

  delay(delayTime);

  Wire.requestFrom(this->address, (uint8_t)20);  // Request from device
  code = Wire.read();                       // Read return code

  while( Wire.available() )
  {
      in_char = Wire.read();
      _value[i] = in_char;
      i++;
      if( in_char == 0)
      {
        break;
      }
  }
  
  return code;

}

void AtlSensor::find(void)
{
  writeCommand(find_cmd); // Send Find command to sensor
  delay(300);             // Delay 300 mS
}