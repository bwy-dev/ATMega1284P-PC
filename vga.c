/*********************************************************************************
 *                                                                               *
 *              Adapted from Andrew Rossignol's AVR VGA code available at:       *
 *      Available at https://github.com/aarossig/avr-vga/blob/master/src/main.s  *
 *                                                                               *
**********************************************************************************/
/*
 *NOTE: There is currently no timing calculation being done, so this will not work properly at the moment
 *I do not currently have accesses to Atmel Studio, once I do I will calculate timings using Simulator and 
 *make neccessary adjustments.
 */
#include "vga.h"
#include "keyboard.h"
#include "main.h"
#include <avr/io.h>

volatile char SCREEN_CONTENTS[FB_WIDTH/CHAR_WIDTH][FB_HEIGHT/CHAR_HEIGHT]; //Actual characters currently on screen
volatile char FRAME_BUFFER[FB_WIDTH][FB_HEIGHT];                           //individual pixels on screen
char *frame_buffer_start;
unsigned int cursor_location[2];

vga_init()
{
    *frame_buffer_start = FRAME_BUFFER[0][0];
    cursor_location[0] = 0;
    cursor_location[1] = 0;
    //disable watchdog
    WDTCSR = 0;
    //configure VGA out pins
    DDRA = 0xff;
}

vga_write_buffer_to_screen()
{
    int x;
    int y;
    for(y = 0; y< FB_HEIGHT; y++){
        int i;
        //print same row RES_HEIGHT/FB_HEIGHT times, to reduce resolution and make up for limited storage.
        for(i = 0; i< RES_HEIGHT/FB_HEIGHT; i++ ) 
        {
            for(x = 0; x<FB_WIDTH; x++){
                int j;
                //print same pixel RES_WIDTH/FB_WIDTH times, to reduce resolution and make up for limited storage.
                for(j = 0; j < RES_WIDTH/FB_WIDTH; j++){
                    PORTA = FRAME_BUFFER[x,y];
                }
            }
            //Some Code here for waiting out front/rear porch and sync pulse timings
            PORTA = (1 << HSYNC); //send HSYNC signal to move on to next line
        }
    }
    PORTA = (1 << VSYNC);
}