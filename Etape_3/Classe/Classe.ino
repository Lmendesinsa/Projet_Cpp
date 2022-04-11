#include "Classe.h"

const int pinIrSensor = A0; 
const int pinIrEmitter= D3; 


#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

void setup() {
    infra diode(pinIrEmitter, LOW);
    Serial.begin(9600);
    

     
}

void loop() {
    
}
