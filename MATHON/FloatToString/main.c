#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <math.h>
#include <string.h>

void setPoids(char* trame, float poids)
{
  char* pds[9];
  *pds = ( char* ) & poids;
  trame[7] = pds[0];
  trame[8] = pds[1];
  trame[9] = pds[2];
  trame[10] = pds[3];
  trame[11] = pds[4];
  trame[12] = pds[5];
  trame[13] = pds[6];
  trame[14] = pds[7];
}

void setTemperature(char* trame, float temper)
{
  char* temp[9];
  *temp = ( char* ) & temper;
  trame[16] = temp[0];
  trame[17] = temp[1];
  trame[18] = temp[2];
  trame[19] = temp[3];
  trame[20] = temp[4];
  trame[21] = temp[5];
  trame[22] = temp[6];
  trame[23] = temp[7];
}

void setHygrometrie(char* trame, float hygro)
{
  char* humy[9];
  *humy = ( char* ) & hygro;
  trame[25] = humy[0];
  trame[26] = humy[1];
  trame[27] = humy[2];
  trame[28] = humy[3];
  trame[29] = humy[4];
  trame[30] = humy[5];
  trame[31] = humy[6];
  trame[32] = humy[7];
}

void sendTrame(float poids, float temp, float hygro)
{
  int i = 0;
  char * trame[36];

  trame[0] = 'A';
  trame[1] = 'T';
  trame[2] = '$';
  trame[3] = 'S';
  trame[4] = 'F';
  trame[5] = '=';
  trame[6] = ' ';
  trame[15] = ' ';
  trame[24] = ' ';
  trame[33] = '\n';
  trame[34] = '\r';

  setPoids(&trame, poids);
  setTemperature(&trame, temp);
  setHygrometrie(&trame, hygro);

  while(i<34){
    printf("%s",trame[i]);
    i++;
  }
}


int main()
{
    float test = 114.5;
    float test2 = 28.9;
    float test3 = 12.1;

    printf("float to string\n\n");

    sendTrame(test, test2, test3);

    printf("%f\n\n",test);
    printf("%#08.8X \n\n",( char* ) & test);

    return 0;
}
