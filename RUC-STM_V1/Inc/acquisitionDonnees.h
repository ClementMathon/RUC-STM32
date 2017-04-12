/* Nom fichier : acquisitionDonnees.h
* Auteur : B.Loiodice
* Date : 29/03/2017
* Description : Fichier header du projet RucSTM32 Contient les prototypes des fonctions de connexionRecuperation,
*	getTemperature, getHumidite, getPoids et leurs vbaraibles globales associées.
* A inclure dans chacun des fichiers sources
* contient le prototype des fonctions 
*/

#ifndef __ACQUISITIONDONNEES_H
#define __ACQUISITIONDONNEES_H

#include "stm32l4xx_hal.h"
#include "string.h"

extern __IO uint8_t Demande[3];
extern __IO uint8_t Test[3];
extern __IO uint8_t Recevoir[8];
extern float humidite;
extern float humiditeTOTAL;
extern int humiditeMB;
extern int humiditeLB;
extern float temperature;
extern float temperatureTOTAL;
extern int Thumidite;
extern char flag;

extern ADC_HandleTypeDef hadc1;

extern I2C_HandleTypeDef hi2c2;

extern UART_HandleTypeDef huart4;
extern float poids;
float getHumidite();
float getTemperature();
void connexionRecuperationCapteur();
float getPoids();

void sendData(float poids, float temp, float hygro);
unsigned floatToBits(float x);
float ReverseFloat(const float inFloat);
#endif