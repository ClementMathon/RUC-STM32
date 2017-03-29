/**
*	NOM FICHIER:  acquisitionDonnees.h
* 	DESCRIPTION : Contient les prototypes des fonctions de connexionRecuperation,
*	getTemperature, getHumidite et leurs vbaraibles globales associées.
*
*	Auteur : 	J.Monnier

*	Date:		29/03/2017
*/

#include "stm32l4xx_hal.h"

__IO uint8_t Demande[3]={0x03,0x00,0x04};
__IO uint8_t Test[3]={0x00,0x00,0x00};
__IO uint8_t Recevoir[8];

float humidite=0;
float humiditeTOTAL=0;
int humiditeMB=0;
int humiditeLB=0;
float temperature=0;
float temperatureTOTAL=0;
int Thumidite=0;
char flag=0;

float getHumidite();
float getTemperature();
void connexionRecuperationCapteur();
