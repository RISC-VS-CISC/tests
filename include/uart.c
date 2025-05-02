#include <stdio.h>
#include <stdarg.h>
#include "uart.h"


void setup_uart(int baud)
{
    // sets up the uart register and sets the baud rate
    int baud_rate = (int)((CLOCK_FREQUENCY) / (baud * 8 + 7)); // UART calulation
	volatile int* UART = (volatile int*)(UART_BASE_ADDR);
	UART[3] = baud_rate; 
    UART[2] = UART[2] | (0x02); // 0x02 is the register to enable UART
}

int _print_char(char cha)
{
    // prints one character to the UART returns 1 if fail, returns 0 if prints character
    volatile int* UART = (volatile int*)(UART_BASE_ADDR);
    int status_register = UART[1];
    if((status_register & BUFF_FULL) == 0) // checks if buffer is full
    {
        UART[0] = (char)(cha); 
        return 0;
    }
    return 1;
}

/* int _read_char(char *cha)
// {
//
 } */
void _print_word(char* word)
{
    // prints a full string
    char *str_ptr = word;
    while(*str_ptr != 0)
    {
        int fail = _print_char(*str_ptr);
        if (!fail)
        {
            str_ptr++;
        }
    }
}

int printf(const char* format, ...)
{
    // printf implementation with vprintf
    va_list args;
    va_start(args, format);
    char char_arr[512];
    vsprintf(char_arr, format, args);
    _print_word(char_arr);
    va_end(args);
    return 0;

}
