#include "acquisitionDonnees.h"

float ReverseFloat( const float inFloat )
{
  float retVal;
  char *floatToConvert = ( char* ) & inFloat;
  char *returnFloat = ( char* ) & retVal;

  // swap the bytes into a temporary buffer
  returnFloat[0] = floatToConvert[3];
  returnFloat[1] = floatToConvert[2];
  returnFloat[2] = floatToConvert[1];
  returnFloat[3] = floatToConvert[0];

   return retVal;
}

unsigned floatToBits(float x)
{
    unsigned y;
    memcpy(&y, &x, 4);
    return y;
}


void sendData(float poids, float temp, float hygro)
{  
  /*unsigned */char trame[35];
  
  sprintf(trame, "AT$SF= %x %x %x \r\n", floatToBits(ReverseFloat(poids)), floatToBits(ReverseFloat(temp)), floatToBits(ReverseFloat(hygro)));
  
  HAL_UART_Transmit(&huart4, (uint8_t*)trame, 35, 100);
}