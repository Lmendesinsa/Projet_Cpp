#include "Classe.h"
#include <Arduino.h>


const int pinIrSensor = A0; 
const int pinIrEmitter= D3; 
const int pinBouton= D5;
const int pinLEDVerte= D6;
const int pinLEDRouge= D8;
const int nb_joueur= 1;
const int score_max= 20;

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

diode ir(pinIrEmitter, LOW);
digital bouton(pinBouton,INPUT);
diode vert(pinLEDVerte, LOW);
diode rouge(pinLEDRouge, LOW);

//Config partie et liste joueur
game partie(nb_joueur,score_max);
joueur liste[nb_joueur];

int fin = 0;


void setup() {

    Serial.begin(9600);

    for(int i=0;i<nb_joueur;i++){
      liste[i]=joueur();
      liste[i].setScore(2);
    }
/*Association des joueurs à leur PIN
Nous n'avons ici que deux joueurs : un qui tire et un qui reçoit
On peut ici facilement rajouter des joueurs.
Dans la classe on a aussi prévu l'association de deux pin par jouer(réception et émission)
*/
    liste[0].setPin(pinIrEmitter);
    liste[1].setPin(pinIrSensor);      
}

void loop() {
  while(fin==0){
    delay(1000);
    if (bouton.getlevel()==HIGH){ir.setDiode(HIGH);}
    else{ir.setDiode(LOW);}

    if(Touche(liste[0].getPin())==true){
        vert.setDiode(HIGH);
        rouge.setDiode(LOW);
        liste[1].incScore(10);
        Serial.println(liste[1].getScore());

    }
      else{
        vert.setDiode(LOW);
        rouge.setDiode(HIGH);
        
    }
    
    if(liste[1].getScore()>=score_max){fin=1;}
  }
  Serial.println("La partie est finie");
  
  //Serial.println((liste[1].getScore()+liste[0].getScore()));

  delay(20000);
  
  Serial.println("Remise a zero");
  liste[1].setScore(0);
  fin=0;


    /*
    catch(int erreur){
      switch (erreur){
        case 1:Serial.println("Pas de joueur");break;
        case 2:Serial.println("Problème récepteur");break;
      }
    }
    */
  
}
