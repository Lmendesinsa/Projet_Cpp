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

int detection(void){
    int result = 0;
    int a = analogRead(pinIrSensor);
    if (a <= 924){
       result = 1;
    }
    return result;
}

void tirer(bool tir){
  if (tir == true){
    digitalWrite(pinIrEmitter, HIGH);
  }
  else{
    digitalWrite(pinIrEmitter, LOW);
  }

}



void setup() {

     Serial.begin(9600);
     pinMode(pinIrEmitter, OUTPUT);

     
}

void loop() {
    Serial.println(analogRead(pinIrSensor));
    delay(100);
 ;

    
}
