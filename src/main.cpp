#include <avr/io.h>
#include <Arduino.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

extern "C" {
    #include "morse.h"
    #include "uart.h"
}

#define LED PORTB5 
Morse MorseConfig;

int main(void){

  Serial.begin(9600); //Zur Nutzung fürs Debugging

  DDRB |= (1 << LED); 
  MorseConfig=SetupMorse(LED);

  char string[] = "das ist setlsam"; //Das, was ausgegeben werden soll, hier ändern! Aber nur Kleinbuchstaben und Zahlen, keine Umlaute, kein ß.
  int breakcounter = 0;
    



  
  
    //ACHTUNG: Breakcounter zurücksetzen!!!
  
}
