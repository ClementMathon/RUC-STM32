/** 
* NOM FONCTION: connexionRecuperationCapteur
* RENVOI: tempTOTAL
* DESCRIPTION: Se connecte au capteur de température et humidité puis transmet les trames pour récupérer la température
* puis met le µc en écoute pour recevoir les données du capteur
* DATE : 29/03/2017
* AUTEUR : J.MONNIER
* CONTRAINTES D’UTILISATION: Nécessite d'être exécute en premier pour utiliser les fonctions ci-dessus
*/

#include "acquisitionDonnees.h"

void connexionRecuperationCapteur(){
  
   HAL_I2C_Master_Transmit(&hi2c2,0xB8,(uint8_t*)demande,3,2000);//Reveil du capteur par n'importe quelle trame
   HAL_Delay(2);
   HAL_I2C_Master_Transmit(&hi2c2,0xB8,(uint8_t*)demande,3,2000);//B8 pour la l'écriture

  //Reception des données venant du capteur de temperature et humidité
   HAL_I2C_Master_Receive(&hi2c2,0xB9,(uint8_t*)recevoir,8,2000); //B9 pour la lecture
   
  
}