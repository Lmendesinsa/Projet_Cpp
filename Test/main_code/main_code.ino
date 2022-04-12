
#include "my_library.h"

void setup() 
{
  Serial.begin(9600);
  int result = addTwoInts(4,3);
  Serial.println(result);
}

void loop() {}
