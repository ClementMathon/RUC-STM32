#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <math.h>
#include <string.h>

void setPoids(unsigned char* trame, float* ptPoids)
{
  int i = 7;
  float poids = *ptPoids;

  //char* pds[9];
  unsigned char *pds = ( unsigned char* ) & poids;
  trame[7] = pds[0];
  trame[8] = pds[1];
  trame[9] = pds[2];
  trame[10] = pds[3];
  trame[11] = pds[4];
  trame[12] = pds[5];
  trame[13] = pds[6];
  trame[14] = pds[7];

  printf("poids       = ");
  while(i<11){
    printf("%2.2X ",trame[i]);
    i++;
  }
  printf("\n\n");
}

void setTemperature(unsigned char* trame, float * ptTemper)
{
  float temperature = *ptTemper;
  int i = 16;
  //char* temp[9];
  unsigned char *temp = ( unsigned char* ) & temperature;
  trame[16] = temp[0];
  trame[17] = temp[1];
  trame[18] = temp[2];
  trame[19] = temp[3];
  trame[20] = temp[4];
  trame[21] = temp[5];
  trame[22] = temp[6];
  trame[23] = temp[7];

  printf("temperature = ");
  while(i<20){
    printf("%2.2X ",trame[i]);
    i++;
  }printf("\n\n");
}

void setHygrometrie(unsigned char* trame, float * ptHygro)
{
  int i = 25;
  float hygrometrie = *ptHygro;
  //char* humy[9];
  unsigned char *humy = ( unsigned char* ) & hygrometrie;
  trame[25] = humy[0];
  trame[26] = humy[1];
  trame[27] = humy[2];
  trame[28] = humy[3];
  trame[29] = humy[4];
  trame[30] = humy[5];
  trame[31] = humy[6];
  trame[32] = humy[7];

  printf("hygrometrie = ");
  while(i<29){
    printf("%2.2X ",trame[i]);
    i++;
  }printf("\n\n");
}

void sendTrame(float* ptTest, float* ptTest2, float* ptTest3)
{
  int i = 0;
  unsigned char trame[36];

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

  setPoids(trame, ptTest);
  setTemperature(trame, ptTest2);
  setHygrometrie(trame, ptTest3);
  i = 0;
  while(i<34){
        if((i<=6)||(i==15)||(i==24)||(i>=33))
        {
            printf("%c",trame[i]);
        }if(((i>=7)&&(i<11))||((i>=16)&&(i<20))||((i>=25)&&(i<29)))
        {
            printf("%2.2X",trame[i]);
        }

    i++;
  }
}


int main()
{
    float test = 114.5;
    float test2 = 28.9;
    float test3 = 12.1;

    float * ptTest = &test;
    float * ptTest2 = &test2;
    float * ptTest3 = &test3;

    printf("float to string + AT command :\n\n");
    sendTrame(ptTest, ptTest2, ptTest3);
    //printf("%f\n\n",test);

    return 0;
}
