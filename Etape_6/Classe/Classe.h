#ifndef _CLASSE_H_
#define _CLASSE_H_


#include <Arduino.h>


#define INPUT 0x0
#define OUTPUT 0x1

#define LOW 0x0
#define HIGH 0x1

class composant{ 
  protected:
    int pin;


  public:
    composant(){ this->pin = 0;} // constructeur sans argument
    composant(int p) { // constructeur avec arguments
      this->pin = p;;
    }

    void setPin(int p){
      this->pin = p;
    }

  
         
};



class digital: public composant{
  protected :   
    int mode;
    
  public:
    digital() : composant(){this->mode = INPUT;} // constructeur sans argument
    digital(int p, int m) : composant(p){
       this->mode = m;
       pinMode(this->pin, this->mode);
    } // constructeur avec arguments
      
  
    void setPin(int p) {
      composant :: setPin(p);
      pinMode(this->pin, this->mode);
    }
     void setMode(char m){
      this->mode = m;
      pinMode(this->pin, this->mode);
    }
    int getlevel(){
      int result=-1;
      if (this->mode == INPUT){result=digitalRead(this->pin);}
      return result;
    }
         
};

class diode : public digital{
  protected : 
    int level;
    
  public :
    diode() : digital(){this->level = 0; this->mode = OUTPUT;} // constructeur sans argument
    diode(int p, int l) : digital(p, OUTPUT){this->level = l; digitalWrite(this->pin, this->level);} // constructeur avec arguments
    void setDiode(int l){
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

    game(){ this->score_max = 0; this->nb_tentatives = 0;}

    game(String j, int s, int t){
      this->nom_joueur = j;
      this->score_max = s;
      this->nb_tentatives = t;
    }

    void setScoreMax(int score){
      this->score_max = score;
    }

    void setNomJoeur(String nom){
      this->nom_joueur = nom;
    }

    void setNomJoeur(int tentatives){
      this->nb_tentatives = tentatives;
    }
};

/* Classe créée à chaque tentatives */
class score{ 
  private:
    int nb_fail;
    int nb_success;

  public:
    score(){ this->nb_fail = 0; this->nb_success = 0;}

    int getScore(){
      return this->nb_success;
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



//Fonctions
boolean Touche(int pin);



#endif
