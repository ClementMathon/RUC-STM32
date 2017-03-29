/**
* NOM FONCTION: getPoids.c
* Auteur : B.Loiodice
* Date : 29/03/2017
* **PARAMETRES: PAS DE PARAMETRES
* RENVOI: un float qui est la moyenne du poids calculer
* DESCRIPTION: cette fonction renvoie un nombre réel qui est la moyenne d'un tableau de 10 valeurs.
* j'utilise la foncton HAL_ADC_PollForConversion pour récuperer la valeur de l'ADC sur l'ADC activer dans STMCube
* Je recupère la valeur de l'ADC avec la méthode HAL_ADC_GetValue
* Récupere la valeur de L'ADC avec la fonction HAL_ADC_GetValue integré au STM32
* Je fais une boucle de 10 pour calculer la moyenne du poids
* Je créée un tableau de 10 float tabADC[10] pour faire une moyenne du poids car non fixe a chaque fois que nous recuperons la valeur de L'ADC
* Dans la boucle Je calcule la tension (adcValeur*quantum) par une multiplication par la valeur de L'ADC fois le quantum (5/2^12) car 5 volt et 12 bits convertisable part l'ADC
* Dans la boucle je calcule le poids = ((tension*100)/1.450191968) la valeur 1,45 est la valeur en sortie de l'amplification en volt pour 100kg
* Les valeurs du tableau sont rangés dans la variable moyenne poids puis une fois la boucle fini le résulatats est divisé par 10
* Le résultat de la moyenne est donc rangé dans la variable moyennePoids.
* CONTRAINTES D’UTILISATION: les valeurs de l'ADC  varient tout le temps, car l'ADC n'est pas assez précis.
*/
  
#include "acquisitionDonnees.h"


float getPoids(){
  
    ADC_HandleTypeDef hadc1;
    uint16_t adcValeur; // variable acValeur entier non signé
    float tension; //mesure de la tension convertie de l'ADC
    float poids; //variable qui récupere le poid en kg
    float tabPoids[10];
    int tabADC[10];
    float MoyennePoids;
    int i=0;
   
    // Initialisation des variables à zéro
    adcValeur=0;     
    tension=0; 
    poids=0.0;
    MoyennePoids =0.0;
       
    for(i=0;i<10;i++){
      HAL_ADC_Start(&hadc1);// fonction qui démarre  L'ADC
      HAL_ADC_PollForConversion(&hadc1,100);//la foncton HAL_ADC_PollForConversion pour récuperer la valeur de l'ADC avec l'adresse de l'ADC en paramètre
      adcValeur= HAL_ADC_GetValue(&hadc1); // Fonction inclu qui récupère la valeur de l'ADC
      tabADC[i] = adcValeur;// récupère dans un tableau la valeur de l'ADC
      //tension=(adcValeur*2265)/3308;// calcule pour recuperer la tension 3.3v
      tension=(tabADC[i]*0.0012207031);// calcule le plus precis pour recuperer la tension
      // poids = ((0.1186*tension)+3.079);
      poids = ((tension*100)/1.450191968);
      tabPoids[i] = poids;
      HAL_Delay(100);
      MoyennePoids = MoyennePoids + tabPoids[i];
    }
      MoyennePoids = (MoyennePoids/10);
    
      
      return (MoyennePoids);
}