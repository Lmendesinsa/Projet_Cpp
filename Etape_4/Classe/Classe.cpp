
// Classe de base pour tous les composants 
// pour gérer l'initialision des entrées/sorties
#include "Classe.h"
#include <iostream>
#include <Arduino.h>

using namespace std;

void InitGame(void){
  int nbjoueur;
  int scoremax;
  string nom;
  cout<<"Entrer nombre de joueur : "<<endl;
  //cin >> nbjoueur; 
  cout<<"Entrer score fin de partie : "<<endl;
  //cin>> scoremax;
  game Game(nbjoueur, scoremax);
  joueur ListeJoueur [Game.getNbJoueur()]; // Création de la liste des joueur
  for (int i = 0; i < nbjoueur; i++){
     cout<<"Entrer le nom d'un joueur : "<<endl;
     //cin >> nom;
     ListeJoueur[i].setNom(nom);
  }
}

void StartGame(void){

 
  
//Mettre ce qu'il y a dans le ino
//+comptage score{
//    try...
//}
//catch(game::fin...


}
