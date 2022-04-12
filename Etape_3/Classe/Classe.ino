
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
    //diode ir(pinIrEmitter, HIGH);
    pinMode(pinIrEmitter, INPUT);
    Serial.begin(9600);
    

     
}

void loop() {
    
}
