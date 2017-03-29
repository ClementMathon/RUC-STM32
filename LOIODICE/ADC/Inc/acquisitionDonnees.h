/* Nom fichier : acquisitionDonnees.h
* Auteur : B.Loiodice
* Date : 29/03/2017
* Description : Fichier header du projet RucSTM32 Contient les prototypes des fonctions de connexionRecuperation,
*	getTemperature, getHumidite, getPoids et leurs vbaraibles globales associées.
* A inclure dans chacun des fichiers sources
* contient le prototype des fonctions 
*/

#include "stm32l4xx_hal.h"
#include "string.h"

__IO uint8_t Demande[3]={0x03,0x00,0x04};
__IO uint8_t Test[3]={0x00,0x00,0x00};
__IO uint8_t Recevoir[8];

uint8_t rec[3] = "OK\n";

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
float getPoids();