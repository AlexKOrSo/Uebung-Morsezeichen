#define F_CPU 16000000UL
#include <Arduino.h>
#include "avr/io.h"



extern "C" {
    #include "morse.h"
}

#define LED PORTB0
Morse MorseConfig;

int main()
{ 
  Serial.begin(9600);

  DDRB |= (1 << LED);

  MorseConfig=SetupMorse(LED);
  char S = 'S';
  char O = 'O';
  while(true)
  {
    Serial.println("HI");
    MorseChar(&S);
    MorseChar(&O);
    MorseChar(&S);
  }
}


void setup(void){

}