#include "main.h"
#include "keyboard.h"
#include "vga.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/* Port Usage:
 * PORTD 0-1: reserved for USART
 * PORTD 2-7: keyboard input
 * PORTA 0-5: vga color out
 * PORTA 6-7: HSYNC & VSYNC
 */

void timer1_init()
{
    TCCR1A |= 0b00000101; //Initializes timer 1. CS02 and CS00 are set high so it will
                          //run at 1024th base clock speed, around 20khz
    TCNT1 = 0;            //then reset value to 0.
}

void port_init()
{
    DDRD = 0x00; //set port d to input
    DDRA = 0xFF; //set port a to ouput
}

int main (void)
{
    port_init();
    timer1_init();
    sei();
    
    while(1) 
    {
        vga_write_buffer_to_screen();
    }
}