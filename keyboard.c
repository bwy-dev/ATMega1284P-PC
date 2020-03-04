#include "main.h"
#include "keyboard.h"
#include "vga.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile char key_to_write = NULL; 

char keyboard_check_input()
{
	if(PIND != 0x00 && PIND != key_to_write)
	{
		PIND = key_to_write;
		return (PIND >> 2);
	}	
	else
	{
		return NULL;
	}
}
