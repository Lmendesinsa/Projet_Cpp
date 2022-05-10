#include "Classe.h"
#include <Arduino.h>
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

// Création des objets sur les bons Pin et initialisation de leurs configurations
diode ir(pinIrEmitter, LOW);
digital bouton(pinBouton,INPUT);
diode vert(pinLEDVerte, LOW);
diode rouge(pinLEDRouge, LOW);

/* CHOIX DES PARAMETRES DE LA PARTIE */////////////////////////////////////////////////////
// Paramètre à changer avant de lancer une partie
const String nom_joueur= "Laura";             // Le nom du joueur en question
const int score_max= 20;                      // Le score max à atteindre pour finir la gamme
const int nb_tentatives = 5;                  // Le nombre de tentatives pour le joueur d'améliorer son score
game game(nom_joueur,score_max,nb_tentatives);// Construction d'une game
score score[nb_tentatives];                   // Structure qui contient le score de chaque partie

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
    while(fin_game==0){ // Tant que la game n'est pas finie
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
      
      
     
      // Vérifier si le score max a été atteint
      if (score[num_tentative].getScore()==score_max){
        fin_game = 1;
        num_tentative++;
        Serial.println(num_tentative);
      }
    }
    fin_game = 0;
  }
  num_tentative = 0;

  delay(10000);

  
}
 

