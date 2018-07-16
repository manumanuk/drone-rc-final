#include <VirtualWire.h>

const int potPin = 0;
const int xPin = 1;
const int yPin = 2;
const int transmit_pin = 7;

struct package {
  unsigned char potVal;
  unsigned char xVal;
  unsigned char yVal;
};

typedef struct package Package;
Package data;

void setup() {
    vw_set_tx_pin (transmit_pin);
    vw_setup (2000);
    
    pinMode (potPin, INPUT);
    pinMode (xPin, INPUT);
    pinMode (yPin, INPUT);
}

void loop() {
  
  data.potVal = map (analogRead (potPin), 0, 1023, 0, 255);
  data.xVal = map (analogRead (xPin), 0, 1023, 0, 255);
  data.yVal = map (analogRead (yPin), 0, 1023, 0, 255);
 
  
  //send an 8-bit unsigned integer inside a char array
  vw_send((uint8_t *)&data, sizeof(data));
  vw_wait_tx();
  delay(200);
  
}
