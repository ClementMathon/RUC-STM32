/*
* filename : acquisitionDonnees.h
* author : MATHON Clement
* description : These fonctions deal with the back-end part of this project.
*               It incorporates with the Sigox modem breakout TD1208. But could
*               be able to fit with others modems.
*/

#include "acquisitionDonnees.h"
/*
* function name : ReverseFloat
* author : MATHON Clement
* description : this function switchs a float between big and little endian 
*               and vice versa
* parameters : 
*   float inFloat : it's your float you want to transform.
* 
* retruns : 
*   float : inFloat transformed in big or little endian.
*/
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

/*
* function name : floatToBits
* author : MATHON Clement
* description : this function transforms a float into a string of hexadecimal
*               symbols. 
* parameters : 
*   float x : it's your float you want to transform.
* 
* retruns : 
*   unsigned int y : it's a pointer to the string corresponding to the float.
*/

unsigned floatToBits(float x)
{
    unsigned y;
    memcpy(&y, &x, 4);
    return y;
}

/*
* function name : sendData
* author : MATHON Clement
* description : this function creates and sends a frame to the back-end device.
* parameters : 
*   float poids : it's the real weight in kg
*   float temp : it's the real temperature in °C
*   float hygro : it's the real humidity level in %
* 
* retruns : 
*   nothing
*/

void sendData(float poids, float temp, float hygro)
{  
  char trame[35];
  
  sprintf(trame, "AT$SF= %x %x %x \r\n", floatToBits(ReverseFloat(poids)), floatToBits(ReverseFloat(temp)), floatToBits(ReverseFloat(hygro)));
  
  HAL_UART_Transmit(&huart4, (uint8_t*)trame, 35, 100);
}
