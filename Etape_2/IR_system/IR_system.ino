#include <math.h>

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

     Serial.begin(9600);
     pinMode(pinIrEmitter, OUTPUT);
     digitalWrite(pinIrEmitter, HIGH);

     

}

void loop() {

    int a = analogRead(pinIrSensor);
 
    Serial.print("a = ");
    Serial.println(a);
}
