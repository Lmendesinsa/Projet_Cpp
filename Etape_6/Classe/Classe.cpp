
// Classe de base pour tous les composants 
// pour gérer l'initialision des entrées/sorties
#include "Classe.h"
#include <Arduino.h>

boolean Touche(int pin){
  boolean result=false;
  int a;
  a=analogRead(pin);
  if (a<=850){
    result =true;
  }
  return result;
}



