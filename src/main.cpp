#include <avr/io.h>
#include <Arduino.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

extern "C" {
    #include "morse.h"
}

#define LED PORTB5 // Bitte hier im Define ändern, da an mehreren Stellen die Pinnummer  genutzt wird.
Morse MorseConfig;

int main(void){

  Serial.begin(9600); //Zur Nutzung fürs Debugging

  DDRB |= (1 << LED); 

  MorseConfig=SetupMorse(LED);

  char string[] = "das ist setlsam"; //Das, was ausgegeben werden soll, hier ändern! Aber nur Kleinbuchstaben und Zahlen, keine Umlaute, kein ß.
  int breakcounter = 0;

  for(int i = 0; i < 100; i++){ //Maximal 1000 Zeichen ausgeben
    
    
    Serial.println("Stelle:");
    Serial.println(i); //Bestätigung dass Auswahlverfahren geglückt ist
  

    int stelle;

    if (string[i] >= 97 && string[i] <= 122) {
      stelle = string[i];
    }/*
    if (string[i] >= 90 && string[i] <= 65){
      stelle = string[i];
    }*/
    else if (string[i] >= 48 && string[i] <= 57){
      stelle = string[i];
    }
    else{
      stelle = 0;
      _delay_ms(200); //Pause zu nächstem Wort, blinken zur definitiven Anzeige
      PORTB |= (1 << DDB5);
      _delay_ms(1000);
      PORTB &= ~(1 << DDB5);
      breakcounter ++;
      if (breakcounter >= 2){
        break;
      }
    }


    char letter = stelle;   
    
      MorseChar(&letter);
      breakcounter = 0;
  
  
    //ACHTUNG: Breakcounter zurücksetzen!!!
  }
}
