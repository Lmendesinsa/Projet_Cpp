
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
    pinMode(pinIrEmitter, 0);
    Serial.begin(9600);
    

     
}

void loop() {
     pinMode(pinIrSensor, 1);
     println(
     

    
}
