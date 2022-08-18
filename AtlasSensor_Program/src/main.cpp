#include "main.h"

/* ----- Class Objects ----- */
AtlSensor pHSensor(pHSensor_addr, ph_Sensor);
AtlSensor disOxySensor(disOxySensor_addr, disOxy_Sensor);
AtlSensor ORPSensor(ORPSensor_addr, ORP_Sensor);
AtlSensor ConductSensor(ConducSensor_addr, Conduct_Sensor);
AtlSensor TempSensor(TempSensor_addr, Temp_Sensor);

/* ----- Global Variables ----- */
char pHValue[15];
char disolvedOxygenValue[15];
char ORPValue[15];
char ConductivityValue[15];
char TemperatureValue[15];
char cmd = 'F';

void setup() 
{
   
  Serial.begin(BAUDRATE);     // Init UART com
  MX_AtlSensor_Init();        // Init I2C and assign Atlas Sensor Addresses

}

void loop() 
{
  
  if(Serial.available() > 0)
  {   
      cmd = Serial.read();
  }

  if(cmd == 'T')
  {
      AtlSensor_requestValue();   // Request all sensor to measure (Task 1)
      delay(100);
      AtlSensor_transmitValue();  // Transmit all Sensor values trough UART (Task 2)

      cmd = 'F';
  }
  
}

static void MX_AtlSensor_Init(void)
{
  Wire.begin();                                           // Init I2C
}

static void AtlSensor_requestValue(void)
{
  pHSensor.getValue(pHValue);                   // Request pH Value from sensor (900 mS delay)
  delay(50);                                    
  disOxySensor.getValue(disolvedOxygenValue);   // Request Disolved Oxygen Value from sensor (600 mS delay)
  delay(50);                                    
  ORPSensor.getValue(ORPValue);                 // Request ORP Value from sensor (900 mS delay)
  delay(50);                                    
  ConductSensor.getValue(ConductivityValue);    // Request Conductivity Value from sensor (600 mS delay)
  delay(50);
  TempSensor.getValue(TemperatureValue);        // Request Temperature Value from sensor  (600 mS delay)
  delay(50);

  // Total time to measure all sensors: 3600 mS (3.75 sec or 4 sec) 

}

static void AtlSensor_transmitValue(void)
{

  Serial.print(pHValue);
  Serial.print("\t");
  Serial.print(disolvedOxygenValue);
  Serial.print("\t");
  Serial.print(ORPValue);
  Serial.print("\t");
  Serial.print(ConductivityValue);
  Serial.print("\t");
  Serial.println(TemperatureValue);

}