
#include "morse.h"

const char *letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

const uint8_t LetterSymbols[] = {
    2,4,4,3,1,4,3,4,2,
    4,3,4,2,2,3,4,4,3,
    3,1,3,4,3,4,4,4
};

// For Numbers
const char *numbers[] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};

const uint8_t NumberSymbol = 5;


static inline void delayDot()
{
    _delay_ms(T_BASE*DOT);
}

//Switching LED on for ton BASE TIME CICCLYES * DOT
void SwitchLED(uint8_t ton)
{
    PINB = (1 << MorseConfig.pin);
    for (uint8_t i = 0; i < ton; i++)
    {
        delayDot();
    }
    PINB = (1 << MorseConfig.pin);
    delayDot();
}

// Setting up pin struct
Morse SetupMorse(uint8_t pin)
{
    Morse configuration =
        {
            pin = pin
        };
    // Todo anything else here
    
    return configuration;
}


//Morsing a char
void sendChar(const char* symbols, uint8_t const* count)
{
    for (uint8_t i = 0; i < *count; i++)
    {
        if (*(symbols+i)=='-')
        {
            SwitchLED(DASH);
        } else if (*(symbols+i)=='.')
        {
            SwitchLED(DOT);
        }  
    }
         
}

//no clue why seperate function
void sendNumber(uint8_t number)
{
    sendChar(numbers[number],&NumberSymbol);
}

void sendLetter(uint8_t letter)
{
    sendChar(letters[letter],LetterSymbols+letter);
}


//API-FCT, handling lower upper case and number selection
int8_t MorseChar(char *symbol)
{
    uint8_t temp = (int) *symbol; //TODO not sure if needed
    if ((temp>='a')&&temp<='z')
    {
        temp -= 'a';
        sendLetter(temp);
    } else if ((temp>='0')&&(temp<='9'))
    {
        temp -= '0';
        sendNumber(temp);
    } else if ((temp>='A')&&(temp<='Z'))
    {
        temp -= 'A';
        sendLetter(temp);
    } else if(temp==' ')
    {
        //Leerzeichen
    } else 
    {
        return ERROR_CHAR_UNKNOWN;
    }
    return 0;
}
