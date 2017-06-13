/* Nom fichier : acquisitionDonnees.h
* Auteur : B.Loiodice
* Date : 29/03/2017
* Description : Fichier header du projet RucSTM32.
* Contient les prototypes des fonctions de connexionRecuperation,getTemperature, getHumidite, getPoids et leurs variables globales associées.
* A inclure dans chacun des fichiers sources
* contient le prototype des fonctions 
*/

#ifndef __ACQUISITIONDONNEES_H
#define __ACQUISITIONDONNEES_H

#include "stm32l4xx_hal.h"
#include "string.h"

// Ces variables sont declares dans le main
extern I2C_HandleTypeDef hi2c2;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart2;

// Prototypes de nos fonctions
void connexionRecuperationCapteur();
float getHumidite();
float getTemperature();
void sendData(float poids, float temp, float hygro);
unsigned floatToBits(float x);
float reverseFloat(const float inFloat);
float getPoids();

// variables globales declares dans le main et utilisees par nos fonctions
extern char flag;
extern __IO uint8_t demande[3];
extern __IO uint8_t test[3];
extern __IO uint8_t recevoir[8];
extern float humiditeTOTAL;
extern int humiditeMB;
extern int humiditeLB;
extern float temperature;
extern float temperatureTOTAL;

#endif