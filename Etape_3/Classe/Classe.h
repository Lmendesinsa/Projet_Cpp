#include "Classe.cpp"
#include "Arduino.h"


namespace Classe{
class composant{ 
    public:
    void setPin(int p);
};

class digital: public composant{
    public:
    void setPin(int p); 
    void setMode(int m);         
};

class diode : public digital{  
};

}
