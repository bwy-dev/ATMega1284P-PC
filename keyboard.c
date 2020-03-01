#include "main.h"
#include "keyboard.h"
#include <avr/io.h>
#include <avr/interrupt.h>



volatile char key_to_write = NULL; 

char get_key(){return key_to_write;}
void set_key(char c){key_to_write = c;}


ISR(TIMER1_OVF_vect)
{
    if(PORTD == NULL)
    {
        key_to_write = PORTD >> 2; //Keyboard inputs use the last 6 bits of portD, with the first 2 reserved for USART, so shift back 2 bits to adjust for this.
    }
    else if(PORTD == key_to_write){
        key_to_write = NULL;
    }
}
