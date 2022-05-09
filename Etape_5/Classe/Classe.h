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

class joueur{
  private:
  int score;
  char nom;  
  int pin;
  int pin_tir;
  int pin_capt;

  public:
  
  joueur() {
    score=0;
    pin=0;
    pin_tir = 0;
    pin_capt = 0;}  

  joueur(int pin) {
    score=0;
    this->pin=pin;
    pin_tir = 0;
    pin_capt = 0;
    } 

  joueur(int pin_tir, int pin_capt) {
    score=0;
    this->pin=0;
    this->pin_tir = pin_tir;
    this->pin_capt = pin_capt;
    } 

  void setNom(char in){
    nom = in;
  }

  void setScore(int in){
    score = in;
  }

  void incScore(int in){
    score += in;
  }

   void setPin(int in){
    pin = in;
  }

  int getScore(void){return score;}

  int getPin(void){return pin;}

};

//Retourne l'addition de scores de joueurs

joueur operator+(joueur& j1, joueur& j2) {
  int s;
  s=j1.getScore();
  s += j2.getScore();
  return s;
};





class game{ 
  protected:
    int nb_joueur;
    int score_max;
    
  public:

    class finGame{ //Permet de récuperer données erreur
      public:
      String gagnant;
    };

    game(){this->nb_joueur = 0; this->score_max = 0;}

    game(int j, int s){
      this->nb_joueur = j;
      this->score_max = s;}

    int getNbJoueur(){
      return nb_joueur;
    }
};

//Fonctions
boolean Touche(int pin);



#endif
