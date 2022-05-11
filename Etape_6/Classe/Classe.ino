#include "Classe.h"
#include <Arduino.h>
#include <stdexcept>
#include <exception>
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

/* INITIALISATION DE LA CONFIGURATION DU JEU */////////////////////////////////////////////////////
// Initilisation des pin pour configuration du jeu
const int pinIrSensor = A0; 
const int pinIrEmitter= D3; 
const int pinBouton= D5;
const int pinLEDVerte= D6;
const int pinLEDRouge= D8;


/* CHOIX DES PARAMETRES DE LA PARTIE */////////////////////////////////////////////////////
// Paramètre à changer avant de lancer une partie
const String nom_joueur= "Lucas";             // Le nom du joueur en question
const int score_max= 5;                       // Le score max à atteindre pour finir la gamme
const int nb_tentatives = 2;                  // Le nombre de tentatives pour le joueur d'améliorer son score

/* VARIABLES ET OBJETS *//////////////////////////////////////////////////////////////////
game game(nom_joueur,score_max,nb_tentatives);// Construction d'une game
score score[nb_tentatives];                   // Structure qui contient le score de chaque partie
diode ir(pinIrEmitter, LOW);
digital bouton(pinBouton,INPUT);
diode vert(pinLEDVerte, LOW);
diode rouge(pinLEDRouge, LOW);
int fin_game ;
int num_tentative; 

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Lancement de la partie");
}

void loop() {
  fin_game = 0;
  num_tentative = 0;


  while(num_tentative < nb_tentatives){ // Tant que il reste des tentatives au joueur
    Serial.println("LANCEMENT D'UNE TENTATIVE");
    while(fin_game==0){ // Tant que la game n'est pas finie
      //try{  
        // Le joueur appui sur un bouton
        if (bouton.getlevel()==HIGH){
          ir.setDiode(HIGH);
          Serial.println("Pew pew");
          // Il touche la cible 
          if(Touche(pinIrSensor)==true){
            vert.setDiode(HIGH);
            rouge.setDiode(LOW);
            delay(1000);
            Serial.println("Success");
            ++score[num_tentative];
            Serial.println(score[num_tentative].getScore());
          }
          // Il ne touche pas la cible
          else{
            vert.setDiode(LOW);
            rouge.setDiode(HIGH);
            delay(1000);
            Serial.println("Fail");
            --score[num_tentative];
            Serial.println(score[num_tentative].getScore());
          }
        }
        else{
          ir.setDiode(LOW);
          Serial.println(" ");
        }
      //}
    
      /*catch(const exception& e) {
        Serial.print("exception caught: ");
        Serial.prinln(e.what());
      }*/

      // Vérifier si le score max a été atteint
      if (score[num_tentative].getScore()==score_max){
        fin_game = 1;
        num_tentative++;
        Serial.print("Fin de la tentative numero ");
        Serial.println(num_tentative);
        delay(10000);  
      }
    }
    fin_game = 0;
  }
  num_tentative = 0;
  Serial.println("Fin de la game ------------------------------- ");
  Serial.print("Affichage des scores du joueur ");
  Serial.println(nom_joueur);

  // Parcours du tableau de scores du joueur
  for (int i = 0; i<nb_tentatives; i++){
    Serial.print("Tentative numero ");
    Serial.println(i);
    Serial.print("Score final : ");
    Serial.println(score[i].getScore()-score[i].getFail());
    delay(100);
  }
  Serial.println("Changer les parametres et relancer pour nouvelles partie !");
  delay(10000);

}
 

