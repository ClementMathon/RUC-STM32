/** 
* NOM FONCTION: getHumidite
* RENVOI: humidite
* DESCRIPTION: Récupère l'humidité du tableau Recevoir à l'indice 2 et 3
*  puis convertit en décimale l'humidité
* DATE : 29/03/2017
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: Nécessite d'abord d'avoir exécuté la fonction connexionRecuperationCapteur
*/

#include "acquisitionDonnees.h"

float getHumidite(){
    char message[40];  //conversion en decimal la valeure de l'humidite
    int  humiditeMB, humiditeLB;
    float humide;
    
    humiditeMB= recevoir[2]*256;
    humiditeLB= recevoir[3];
    humide = (float)((humiditeMB + humiditeLB)/10.0);
    
    sprintf(message,"L'hygrometrie est : %.2f % \n", humide); 
    HAL_UART_Transmit(&huart2, message, strlen(message), 100);
    return humide;
}