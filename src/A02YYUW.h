#ifndef A02YYUW_H
#define A02YYUW_H


#include <Arduino.h>

#define HEADER 0xFF
#define SENSOR  Serial2

void Read_Frame(uint8_t *Data);
uint32_t Get_Distance(uint8_t *Data);
bool Validate_Checksum(uint8_t* Data, uint8_t Checksum);
uint8_t Calculate_Checksum(uint8_t *cData);

#endif
