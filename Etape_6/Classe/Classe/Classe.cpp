
// Classe de base pour tous les composants 
// pour gérer l'initialision des entrées/sorties
#include "Classe.h"
#include <Arduino.h>
#include <stdexcept>
#include <exception>

boolean Touche(int pin){
  boolean result=false;
  int a;
  a=analogRead(pin);
  if (a<=850){
    result =true;
  }
  /*if ( (a < 800) || (a> 1000)) {
    throw std::invalid_argument( "Valeur détectée par IR invalide" );
  }*/
  return result;
}



