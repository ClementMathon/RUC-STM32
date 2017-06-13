/** 
* NOM FONCTION: getTemperature
* RENVOI: tempTOTAL
* DESCRIPTION: Récupère la température du tableau Recevoir à l'indice 5
*  puis convertit en décimale la température
* DATE : 29/03/2017
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: Nécessite d'abord d'avoir exécuté la fonction connexionRecuperationCapteur
*/

#include "acquisitionDonnees.h"

float getTemperature(){
    
    float tempTOTAL;
    char message[25];
    
    int tempMSB=0;
    int tempLSB=0;
    //on recupere l octet de poids fort en enlevant le bit de signe
    tempMSB=recevoir[4]& 0x7F;
    //formule indique dans la documentation de l AM2315 (doc AMD2315 page 11)
    tempMSB = tempMSB*256;
    //recuperation de l octet de poids faible
    tempLSB=recevoir[5];
    
    tempTOTAL=(float)((tempMSB+tempLSB)/10.0); //(doc AMD2315 page 11)
    //si la temperature est negative, inversion du signe (doc AMD2315 page 11)
    if (recevoir[4] >> 7) 
      tempTOTAL = -tempTOTAL;
    
    sprintf(message,"La temperature est : %.2f Celsius \n", tempTOTAL); 
    HAL_UART_Transmit(&huart2, message, strlen(message), 100);
      
    return tempTOTAL;
  
}