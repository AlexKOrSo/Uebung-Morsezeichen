#ifndef MORSE_H_
#define MORSE_H_

#include <stdint.h>
#include "avr/delay.h"
#include "avr/io.h"

#define DOT       1
#define DASH      3  //Wikipedia
#define SYMBOLSEP 1
#define LETTERSEP (3)
#define WORDSEP   (7)

#define LETTERCNT 4
#define NUMBERCNT 5
#define ERROR_CHAR_UNKNOWN -1

#define T_BASE 100



typedef struct
{
  uint8_t pin;
} Morse;

/*
decode function   --> gets a char

  getter Function
  Whole blinkin pattern
    Blinkin Function
*/
Morse SetupMorse(uint8_t pin);
int8_t MorseChar(char *symbol);

extern Morse MorseConfig;
// some function for generating delay
// some function for doing blink with a letter

#endif
