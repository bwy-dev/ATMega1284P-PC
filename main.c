#include "main.h"
#include "keyboard.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/* Port Usage:
 * PORTD 0-1: reserved for USART
 * PORTD 2-7: keyboard input
 * PORTA 0-5: vga color out
 * PORTA 6-7: HSYNC & VSYNC
 */


/* 
 * Initializes timer 1. CS02 and CS00 are set high
 * running at 1024th base clock speed, around 20khz
 */
void timer1_init()
{
    TCCR1A |= 0x00000101 ; 
    TCNT1 = 0;
}

int main (void)
{
    DDRD = 0x00;
    DDRA = 0xFF;

    timer1_init();
    sei();
    
    while(1) 
    {
        if(get_key() < 0x00)
        {
            set_key(PORTA);
        }
        else
        {
            PORTA = 0x00;
        }
        
    }
}