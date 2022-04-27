#include <avr/io.h>
#include <Arduino.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

extern "C" {
    #include "morse.h"
    #include "uart.h"
}
#define BAUD 9600
#define LED PORTB5 
Morse MorseConfig;

int main(void){


  Uart_Init(BAUD);
  uint8_t const text_length = 39;
  uint8_t recievedChCts = 0;
  char text[text_length+1]; 

  DDRB |= (1 << LED); 
  MorseConfig=SetupMorse(LED);

  while (1)
  {
    recievedChCts = Uart_RecieveString(text,text_length);

    for (uint8_t i = 0; i < recievedChCts; i++)
    {
      MorseChar(text+i);
    }
    
  }
  



  
  
    //ACHTUNG: Breakcounter zurücksetzen!!!
  
}