
// Classe de base pour tous les composants 
// pour gérer l'initialision des entrées/sorties
#include "Classe.h"
#include <iostream>
#include <map>

void StartGame(void){
  int nbjoueur;
  int scoremax;
  cout<<"Entrer nombre de joueur : "<<endl;
  cin >> nbjoueur; 
  cout<<"Entrer score fin de partie : "<<endl;
  cin>> scoremax;
  game Game(nbjoueur, scoremax);
}
