#include "main.h"
#include "keyboard.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void timer1_init()
{
    TCCR1A |= 0x00000101 ; // CS02 and CS00 high, running at 1024th base clock speed
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