
#include "A02YYUW_ESP.h"

unsigned char Frame[4] = {'\0'};

void Read_Frame(uint8_t *Data)
{

    if (SENSOR.available() > 0)
    {
        delay(4);
        if (SENSOR.read() == HEADER)
        {
            Data[0] = HEADER;

            for (int i = 1; i < 4; i++)
            {
                Data[i] = SENSOR.read();
            }
        }
    }
}

uint32_t Get_Distance(uint8_t *Data)
{
    uint32_t Dist =0;
    Dist = ((Data[1]<<8) + Data[2]);
    return Dist;
}

bool Validate_Checksum(uint8_t *Data, uint8_t Checksum)
{
    if(Checksum == Data[3])
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint8_t Calculate_Checksum(uint8_t *cData)
{
    uint8_t CS = 0;
    CS = cData[0] + cData[1] + cData[2];
    return CS;
}
