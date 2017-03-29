#include "acquisitionDonnees.h"

/** 
* NOM FONCTION: getHumidite
* RENVOI: humidite
* DESCRIPTION: Récupère l'humidité du tableau Recevoir à l'indice 2 et 3
*  puis convertit en décimale l'humidité
* DATE : 29/03/2017
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: Nécessite d'abord d'avoir exécuté la fonction connexionRecuperationCapteur
*/
float getHumidite(){
  
  //conversion en decimal la valeure de l'humidite
    humiditeMB= Recevoir[2]*256;
    humiditeLB= Recevoir[3];
    humidite = (int)(humiditeMB + humiditeLB);
   
    humidite=(float)humidite/10;
    return humidite;
}

/** 
* NOM FONCTION: getTemperature
* RENVOI: tempTOTAL
* DESCRIPTION: Récupère la température du tableau Recevoir à l'indice 5
*  puis convertit en décimale la température
* DATE : 29/03/2017
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: Nécessite d'abord d'avoir exécuté la fonction connexionRecuperationCapteur
*/
float getTemperature(){
    int temp=0;
    float tempTOTAL;
    
    temp=Recevoir[5];
    tempTOTAL=(float)temp/10;
    
    return tempTOTAL;
  
}

/** 
* NOM FONCTION: connexionRecuperationCapteur
* RENVOI: tempTOTAL
* DESCRIPTION: Se connecte au capteur de température et humidité puis transmet les trames pour récupérer la température
* puis met le µc en écoute pour recevoir les données du capteur
* DATE : 29/03/2017
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: Nécessite d'être exécute en premier pour utiliser les fonctions ci-dessus
*/
void connexionRecuperationCapteur(){
  
   HAL_I2C_Master_Transmit(&hi2c2,0xB8,(uint8_t*)Demande,3,2000);//Reveil du capteur par n'importe quelle trame
   HAL_Delay(2);
   HAL_I2C_Master_Transmit(&hi2c2,0xB8,(uint8_t*)Demande,3,2000);//B8 pour la l'écriture

  //Reception des données venant du capteur de temperature et humidité
   HAL_I2C_Master_Receive(&hi2c2,0xB9,(uint8_t*)Recevoir,8,2000); //B9 pour la lecture
   
  
}