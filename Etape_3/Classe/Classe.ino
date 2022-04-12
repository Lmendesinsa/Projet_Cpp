#include "Classe.h"
<<<<<<< HEAD
#include <Arduino.h>
=======
#include "Arduino.h"
>>>>>>> 325faa713882d4870f0ca23a0e11086a1abe0569


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
<<<<<<< HEAD
=======
    digital bouton(pinBouton,INPUT);


>>>>>>> 325faa713882d4870f0ca23a0e11086a1abe0569

}

void loop() {
<<<<<<< HEAD
    int a=analogRead(pinIrSensor);
    Serial.println(a);
    delay(50);
=======
    if (bouton.getlevel==1){ir.setDiode(HIGH);}
    else{ir.setDiode(LOW);}
    int a=analogRead(pinIrSensor);
    Serial.println(a);
    delay(100);
>>>>>>> 325faa713882d4870f0ca23a0e11086a1abe0569
}
