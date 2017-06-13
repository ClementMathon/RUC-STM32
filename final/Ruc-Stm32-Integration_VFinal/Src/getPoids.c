/**
* NOM FONCTION: getPoids.c
* Auteur : B.Loiodice
* **PARAMETRES: PAS DE PARAMETRES
* RENVOI: un float qui est la moyenne du poids calcule
* DESCRIPTION: cette fonction renvoie un nombre reel qui est la moyenne d'un tableau de 100 valeurs.
* j'utilise la foncton HAL_ADC_PollForConversion pour recuperer la valeur de l'ADC, l'ADC est active dans STMCube
* Je recupere la valeur de L'ADC avec la fonction HAL_ADC_GetValue integré au STM32
* Je fais une boucle de 100 pour calculer la moyenne du poids
* Je cree un tableau de 100 float tabADC[100] pour faire une moyenne du poids car non fixe a chaque fois que nous recuperons la valeur de L'ADC
* Les valeurs du tableau sont ranges dans la variable moyenne poids puis une fois la boucle fini le resulatats est divise par 100
* Le resultat de la moyenne est donc rangé dans la variable moyennePoids.
* CONTRAINTES D'UTILISATION: les valeurs de l'ADC  varient tout le temps, car l'ADC n'est pas assez precis.
*/
#include "acquisitionDonnees.h"

float getPoids(){

    //ADC_HandleTypeDef hadc1;
    uint16_t adcValeur; // variable acValeur entier non signe
    //UART_HandleTypeDef huart2;
   //float tension; //mesure de la tension convertie de l'ADC
    float poids; //variable qui récupere le poid en kg
    float tabPoids[100]; // recupere 
    //int tabADC[100];
    float moyennePoids;
    uint8_t pesage[50];
    //uint8_t volt[50];
    int i=0;
   // float moyenneTension;

    adcValeur=0;
    //tension=0;
    poids=0.0;
    moyennePoids =0.0;
    
    
    
    for(i=0;i<100;i++){
      HAL_ADC_Start(&hadc1);// Mise en fonction de L'ADC
      HAL_ADC_PollForConversion(&hadc1,100);// la foncton HAL_ADC_PollForConversion lance une conversion
      adcValeur= HAL_ADC_GetValue(&hadc1); // Recupere la valeur d l'ADC
      //tabADC[i] = adcValeur;// recupere dans un tableau la valeur de l'ADC
      //tension =((tabADC[i]/1128.2)-3.5445/1128.2);// calcul pour recuperer la tension utile dans les tests unitaire
      poids = ((adcValeur/12.733)-(24.182/12.733));
      tabPoids[i] = poids;
      moyennePoids = moyennePoids + tabPoids[i];
      //moyenneTension = moyenneTension + tension; // calcul la tension utile dans les tests unitaires
    }
    HAL_ADC_Stop(&hadc1);
    moyennePoids = (moyennePoids/100); // fait la moyenne du poids de 100 valeurs
     //moyenneTension = (moyenneTension/100); //fait la moyenne de la tension de 100 valeurs
	  
    sprintf(pesage,"le poids mesure est : %f kg \n", moyennePoids); 
    HAL_UART_Transmit(&huart2, pesage, strlen(pesage), 100);
      /*
       sprintf(volt,"la tension mesure est : %f volt \n", moyenneTension); 
      HAL_UART_Transmit(&huart4, volt, strlen(volt), 100);
      */
	  // utile dans le cadre de la mise en oeuvre de l'ADC
	
      return (moyennePoids);
}
