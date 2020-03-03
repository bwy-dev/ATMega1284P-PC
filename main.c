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
volatile int line;

//void timer1_init()
//{    
//     TCCR1B |= 0x09;      //Timer Clock = System Clock.
//     TIMSK1 |= 0x02;
//     OCR1A = 800; //set timer to trigger every 800 cycles
//     TCNT1 = 0;
//	 sei();
//}

void port_init()
{
    DDRD = 0x00; //set port d (Keyboard In) to input
    DDRA = 0xFF; //set port a (VGA Out) to output
}

/*Drawing to Screen via VGA happens in an interrupt the we can hopefully make happen every full clock cycle of the VGA*/
 /*ISR(TIMER1_COMPA_vect)
 {
	if(line > RES_HEIGHT)
	{
		if (line > TOTAL_LINES)
		{
			line = 0;
		}
		else
		{
			line ++;
		}
		return;
	}
    write_line();
	line++;
	return;
 }*/

ISR(TIMER1_COMPA_vect){write_line();}

int main (void)
{
	port_init();
	vga_init();
	start_up();

	while(1)
	{
		char c = keyboard_check_input();
		if(c != NULL)
		{
			vga_add_char_at_cursor(c);
		}
	}
}
