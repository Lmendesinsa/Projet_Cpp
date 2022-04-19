#include "Classe.h"
#include <Arduino.h>


const int pinIrSensor = A0; 
const int pinIrEmitter= D3; 
const int pinBouton= D5;


#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

diode ir(pinIrEmitter, HIGH);
digital bouton(pinBouton,INPUT);

int a=0;

void setup() {
    
    Serial.begin(9600);
}

void loop() {


    if (bouton.getlevel()==HIGH){ir.setDiode(HIGH);}
    else{ir.setDiode(LOW);}
    a=analogRead(pinIrSensor);
    Serial.println(a);
    delay(100);
}
