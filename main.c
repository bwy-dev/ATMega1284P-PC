#include "main.h"
#include "keyboard.h"
#include "vga.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/* Port Usage:
 * PORTD 0-1: reserved for USART
 * PORTD 2-7: keyboard input
 * PORTA 0-3: VGA color out
 * PORTA 6-7: HSYNC & VSYNC
 */
volatile int line = 0;
volatile byte *NEXT_LINE;
volatile long start = 0;

void timer2_init()
{
    TCCR2A |= 0x01; //Timer Clock = System Clock.
                    //NOTE: need to find way to make this trigger
                    //after number of cycles in a horizontal line for VGA.
    TCNT2 = 0;
}

void port_init()
{
    DDRD = 0x00; //set port d (Keyboard In) to input
    DDRA = 0xFF; //set port a (VGA Out) to output
}

/*Drawing to Screen via VGA happens in an interrupt the we can hopefully make happen every full clock cycle of the VGA*/
ISR(TIMER2_OVF_vect)
{
    if(line < RES_HEIGHT){
        vga_write_line(start);
        //Do something during front porch time
        vga_horizontal_sync(); //run horizontal sync during HSP
        //Do something during rear porch time
    }
}


int main (void)
{
    
    port_init();
    vga_init();
    sei();
    while(1) 
    {
        //everything that can happen while Screen Interrupt isn't happening happens here
        //grabbing stuff from memory
        //checking keyboard inputs
    }
}