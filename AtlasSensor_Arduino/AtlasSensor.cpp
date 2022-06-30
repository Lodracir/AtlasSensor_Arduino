/* Libreria */
#include "AtlasSensor.h"

/* ----- Defines ----- */
char *read_cmd = "r";
char *find_cmd = "find";

/* ----- Funciones Privadas ----- */
void AtlSensor::writeCommand(char str[])
{

  Wire.beginTransmission(_address); /* Open I2C Communication */
  Wire.write(str);                  /* Transmit Command */
  Wire.endTransmission();           /* End Transmission */
  
}

/* ----- Funciones Publicas ----- */
void AtlSensor::init(uint8_t _addr, sensorType_t _sensorType)
{
  _address    = _addr;        //Set Device address
  sensorType  = _sensorType;  //Set Sensor Type
}

uint8_t AtlSensor::getAddress(void)
{
  return _address;
}

byte AtlSensor::getValue(char _value[])
{

  /* Local Variables */
  byte  code;  
  byte  in_char;
  int   i = 0;
  
  writeCommand(read_cmd); // Send read command to pH Sensor 
  
   if( (sensorType == ph_Sensor) || (sensorType == ORP_Sensor) )
   {
     delay(900); // Delay 900 mS
   }
   else if ( (sensorType == disOxy_Sensor) || (sensorType == Temp_Sensor ) || (sensorType == Conduct_Sensor) )
   { 
     delay(600); // Delay 600 mS
   }

  //delay(1000);
                         
  Wire.requestFrom(_address, 20);       // Request from device
  code = Wire.read();                   // Read return code

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