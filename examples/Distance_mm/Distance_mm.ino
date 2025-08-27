#include "A02YYUW_ESP.h"

#define WATER_LEVEL_MIN 20 // In Percent
#define WATER_LEVEL_MAX 80 // In Percent

#define SOLENOID_PIN
#define PUPM_PIN


#define DEBUG Serial

uint8_t Buff[4] = {'\0'};
uint8_t CheckSum = 0;
uint32_t Distance =0;

void setup()
{
  SENSOR.begin(9600); // Initialize the sensor
}

void loop()
{
  Read_Frame(Buff); //Read the RAW frame from the sensor
  CheckSum = Calculate_Checksum(Buff); //Calculate the checksum

  if(Validate_Checksum(Buff, CheckSum)) //Validate the checksum
  {
    Distance = Get_Distance(Buff);//Get the distance from the Sensor
    DEBUG.print("Distance: ");
    DEBUG.print(Distance);
    DEBUG.println(" mm");
  }
  else
  {
    DEBUG.println("Invalid Checksum");
  }
  delay(1000);
}
