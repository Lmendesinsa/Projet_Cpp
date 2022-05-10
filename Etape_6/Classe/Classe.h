#ifndef _CLASSE_H_
#define _CLASSE_H_


#include <Arduino.h>


#define INPUT 0x0
#define OUTPUT 0x1

#define LOW 0x0
#define HIGH 0x1

/* Classe permettant de gérer composant quelconque :
 @attribut pin : associer un composant à une pin
 */
class composant{ 
  protected:
    int pin;
  public:
    composant(){ this->pin = 0;} // constructeur sans argument
    composant(int p) { // constructeur avec arguments
      this->pin = p;;
    }
    void setPin(int p){ // Régler la Pin d'un composant
      this->pin = p;
    }        
};


/* Classe permettant de régler un composant digital :
 @attribut mode : permet de régler en INPUT ou OUTPUT le fonctionnement du composant
 */
class digital: public composant{
  protected :   
    int mode;
    
  public:
    digital() : composant(){this->mode = INPUT;} // constructeur sans argument
    digital(int p, int m) : composant(p){
       this->mode = m;
       pinMode(this->pin, this->mode);
    } // constructeur avec arguments
      
  
    void setPin(int p) { // Initialiser un composant sur la bonne Pin
      composant :: setPin(p);
      pinMode(this->pin, this->mode);
    }
     void setMode(char m){ // Changer le mode d'un composant
      this->mode = m;
      pinMode(this->pin, this->mode);
    }
    int getlevel(){ // Récupérer la valeur d'une entrée numérique
      int result=-1;
      if (this->mode == INPUT){result=digitalRead(this->pin);}
      return result;
    }
         
};

/* Classe permettant de régler une diode RGB ou IR:
 @attribut level : permet de d'allumer ou éteindre une diode
 */
class diode : public digital{
  protected : 
    int level; 
  public :
    diode() : digital(){this->level = 0; this->mode = OUTPUT;} // constructeur sans argument
    diode(int p, int l) : digital(p, OUTPUT){this->level = l; digitalWrite(this->pin, this->level);} // constructeur avec arguments
    
    void setDiode(int l){ // Régler le niveau et le Pin d'un composant digital
      digitalWrite(this->pin,l);
      this->level=l;
    } 
};


/* Classe créée dès qu'une partie est créée :
 @attribut nom_joueur : le nom du joueur qui lance la game
 @attribut score_max : le score a réalisé pour gagner la game
 @attribut nb_tentatives : le nombre de tentatives dans la game
 */
class game{ 
  protected:
    String nom_joueur;
    int score_max;
    int nb_tentatives;

    
  public:
    game(){ this->score_max = 0; this->nb_tentatives = 0;} // constructeur sans arguments

    game(String j, int s, int t){ // constructeur avec arguments
      this->nom_joueur = j;
      this->score_max = s;
      this->nb_tentatives = t;
    }

    void setScoreMax(int score){ // Changer la valeur du score à atteindre
      this->score_max = score;
    }

    void setNomJoeur(String nom){ // Changer le nom du joueur
      this->nom_joueur = nom;
    }

    void setNomJoeur(int tentatives){ // Changer le nombre de tentatives disponibles
      this->nb_tentatives = tentatives;
    }
};

/* Classe créée à chaque tentatives pour conserver les performances du joueur :
 @attribut nb_fail : augmente quand le joueur tir à côté de la cible
 @attribut nb_success : augmente quand le joueur tir sur la cible
 */ 
class score{ 
  private:
    int nb_fail;
    int nb_success;

  public:
    score(){ this->nb_fail = 0; this->nb_success = 0;} // Constructeur sans argument initilise à 0 les valeurs des parties

    int getScore(){ // accès au nombre de succès
      return this->nb_success;
    }
    int getFail(){ // accès au nombre d'échec
      return this->nb_fail;
    }
    // Opérateur ++ augmente le nombre de success
    void operator ++() { 
      nb_success = nb_success +1; 
    }
    // Opérateur -- augmente le nombre de fail 
    void operator --() {   
      nb_fail = nb_fail +1;    
    } 
};



/* Fonction permettant de vérifier que la cible a été touchée :
@arg : numéro de pin à tester
@return : true si touché, false sinon 
*/
boolean Touche(int pin);



#endif
