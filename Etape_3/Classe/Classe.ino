#include "Classe.h"
#include "Arduino.h"


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

void setup() {
    diode ir(pinIrEmitter, HIGH);
    Serial.begin(9600);
    digital bouton(pinBouton,INPUT);



}

void loop() {
    if (bouton.getlevel==1){ir.setDiode(HIGH);}
    else{ir.setDiode(LOW);}
    int a=analogRead(pinIrSensor);
    Serial.println(a);
    delay(100);
}
