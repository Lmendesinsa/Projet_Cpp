
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
    int setDiode(int l){
      digitalWrite(this->pin,l);
      this->level=l;
      }


    
};



#endif
