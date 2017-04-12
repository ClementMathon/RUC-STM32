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
  
  //conversion en decimal la valeure de l'humidite
    humiditeMB= Recevoir[2]*256;
    humiditeLB= Recevoir[3];
    humidite = (int)(humiditeMB + humiditeLB);
   
    humidite=(float)humidite/10;
    return humidite;
}