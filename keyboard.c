#include "main.h"
#include "keyboard.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/* Port Usage:
 * PORTD 0-1: reserved for USART
 * PORTD 2-7: keyboard input
 * PORTA 0-7: currently used for testing input detection
 */


volatile char keyToWrite = NULL; 

char get_key(){return keyToWrite;}
void set_key(char c){keyToWrite = c;}


ISR(TIMER1_OVF_vect)
{
    if(PORTD == NULL)
    {
        keyToWrite = PORTD >> 2; //Keyboard inputs use the last 6 bits of portD, with the first 2 reserved for USART, so shift back 2 bits to adjust for this.
    }
    else if(PORTD == keyToWrite){
        keyToWrite = NULL;
    }
}
