#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "avr/io.h"

#ifndef BAUD
#define BAUD 9600
#endif

#ifndef UART_DELIM
#define UART_DELIM ('\n')
#endif

#define BAUD_PRESCALE (((F_CPU / (baudrate * 16UL)))-1)

void Uart_Init(uint32_t baudrate);

uint8_t Uart_RecieveString(char* buffer,uint8_t length);


#endif