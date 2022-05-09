#include <ArduinoSTL.h>

#include "Classe.h"
#include <Arduino.h>


const int pinIrSensor = A0; 
const int pinIrEmitter= D3; 
const int pinBouton= D5;
const int pinLEDVerte= D6;
const int pinLEDRouge= D8;

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

diode ir(pinIrEmitter, LOW);
digital bouton(pinBouton,INPUT);
diode vert(pinLEDVerte, LOW);
diode rouge(pinLEDRouge, LOW);

int a=0;

void setup() {
    
    Serial.begin(9600);
}

void loop() {


    if (bouton.getlevel()==HIGH){ir.setDiode(HIGH);}
    else{ir.setDiode(LOW);}
    a=analogRead(pinIrSensor);
    if (a<=850){
      vert.setDiode(HIGH);
      rouge.setDiode(LOW);
      delay(1000);
    }
    else{
      vert.setDiode(LOW);
      rouge.setDiode(HIGH);
      delay(1000);
    }
    
    Serial.println(a);
}
