/**
* NOM FONCTION: getPoids.c
* Auteur : B.Loiodice
* DATE : 14/06/2017
* PARAMETRES: PAS DE PARAMETRES
* RENVOI: un float qui est la moyenne du poids calcule
* DESCRIPTION: cette fonction renvoie un nombre reel qui est la moyenne d'un tableau de 100 valeurs.
* j'utilise la foncton HAL_ADC_PollForConversion pour lancer la recuperation de l'ADC, l'ADC est active dans STM32Cube
* Je recupere la valeur de L'ADC avec la fonction HAL_ADC_GetValue integré de la HAL sur le STM32
* Je fais une boucle de 100 pour calculer la moyenne du poids
* Les valeurs du tableau sont ranges dans la variable moyenne poids puis une fois la boucle fini le resultats est divise par 100
* Le resultat de la moyenne est donc rangé dans la variable moyennePoids.
* CONTRAINTES D'UTILISATION: Les valeurs de l'ADC  varient tout le temps, car l'ADC n'est pas assez precis.
*/
#include "acquisitionDonnees.h"

float getPoids(){

    uint16_t adcValeur;      // Variable acValeur entier non signe
    float poids;             // Variable qui récupere le poid en kg
    float tabPoids[100];     // Tableau qui recupere la valeur issue du calcul de poids
    float moyennePoids;      // Variable qui contient la moyenne des 100 échantillions
    uint8_t pesage[50];      // Tableau qui stock les chaine de caractere dans l'hyper terminal
    
    int i=0;

    adcValeur=0;       // Initialisation variable adcValeur
    poids=0.0;         // Initialisation variable poids
    moyennePoids=0.0;  // Initialisation variable moyennePoids
     
 /* 
  * Je fais une boucle de 100 pour calculer la moyenne du poids
  */
    
    for(i=0;i<100;i++){ // Debut boucle for
      HAL_ADC_Start(&hadc1);                            // Mise en fonction de L'ADC
      HAL_ADC_PollForConversion(&hadc1,100);            // La foncton HAL_ADC_PollForConversion lance une conversion
      adcValeur= HAL_ADC_GetValue(&hadc1);              // Recupere la valeur d l'ADC
      poids = ((adcValeur/12.733)-(24.182/12.733));     // Calcul du poids
      tabPoids[i] = poids;
      moyennePoids = moyennePoids + tabPoids[i];
    }   // Fin boucle for
    
    HAL_ADC_Stop(&hadc1);                               // Arret de l'ADC
    moyennePoids = (moyennePoids/100);                  // Fait la moyenne du poids de 100 valeurs
	  
    sprintf(pesage,"le poids mesure est : %f kg \n", moyennePoids);  // Affichage du poids dans l'hyper terminal
    HAL_UART_Transmit(&huart2, pesage, strlen(pesage), 100);         // Transmission de l'affichage dans l'hyper terminal par l'huart2
	 
	
      return (moyennePoids);    // Retourne la valeur de la variable moyennePoids 
}
