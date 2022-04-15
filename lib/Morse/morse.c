
#include "morse.h"

const char *letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};
// For Numbers
const char *numbers[] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."};


Morse SetupMorse(uint8_t pin)
{
    Morse configuration =
        {
            pin = pin
        };
    // Todo anything else here
    return configuration;
}

uint8_t MorseChar(Morse *morse, char *symbol)
{

    return 0;
}
