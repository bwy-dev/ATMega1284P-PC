#include "main.h"
#include "keyboard.h"
#include "vga.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile char key_to_write = NULL; 

ISR(TIMER1_OVF_vect)
{
    if(PORTD != 0x00)
    {
        key_to_write = PORTD >> 2; //Keyboard inputs use the last 6 bits of portD, with the first 2 reserved for USART, so shift back 2 bits to adjust for this.
        vga_add_char_at_cursor(key_to_write);
    }
    else if(PORTD == key_to_write || PORTD == 0x00){
        key_to_write = NULL;
    }
}
