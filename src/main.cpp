#include <Arduino.h>
#include "avr/io.h"

extern "C" {
    #include "morse.h"
}

#define LED PORTB0


int main()
{ 
  DDRB |= (1 << LED);

  Morse configartion=SetupMorse(LED);


  while(true)
  {
    _NOP();
  }
}

