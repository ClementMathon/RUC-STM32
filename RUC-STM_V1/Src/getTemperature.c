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
    int temp=0;
    float tempTOTAL;
    
    temp=Recevoir[5];
    tempTOTAL=(float)temp/10;
    
    return tempTOTAL;
  
}