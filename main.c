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

volatile int line = 1;

void port_init()
{
    DDRD = 0x00; //set port d (Keyboard In) to input
    DDRA = 0xFF; //set port a (VGA Out) to output
}

ISR(TIMER1_COMPA_vect)
{
	if(line == 1)
	{
		write_line();
		line = 480;
	}
	else if(line == 492)
	{
		PORTC &= 0b11111101;
		line++;
	}
	else if (line == 494)
	{
		PORTC |= 0b00000010;
		line++;
	}
	else if (line == 524)
	{
		line = 1;
	}
	else
	{
		line++;
	}
}

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
