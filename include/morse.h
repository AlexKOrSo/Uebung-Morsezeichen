#ifndef MORSE_H_
#define MORSE_H_

#define DASH 8
#define DOT 3

typedef struct {
  uint8_t pin;
} Morse;
/*
decode function   --> gets a char

	getter Function
	Whole blinkin pattern
		Blinkin Function
*/


const char *letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};
//For Numbers
const char *numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....",
  "-....", "--...", "---..", "----."
};

Morse SetupMorse(uint8_t pin);
uint8_t MorseChar(Morse*morse,char* symbol);
//some function for generating delay
//some function for doing blink with a letter



#endif

