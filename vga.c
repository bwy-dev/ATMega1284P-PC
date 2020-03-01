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
struct Coord cursor_location;

void vga_init()
{
    *frame_buffer_start = FRAME_BUFFER[0][0];
    cursor_location.x = 0;
    cursor_location.y = 0;
    //disable watchdog
    WDTCSR = 0;
    //configure VGA out pins
    DDRA = 0xff;
}

void vga_write_buffer_to_screen()
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

void vga_add_char_at_cursor(char c)
{
    char (*new_char_ptr)[6][4];
    switch (c)
    {
    case KEY_A:
        new_char_ptr = CHAR_A_UP;
        break;
    case KEY_B:
        new_char_ptr = CHAR_B_UP;
        break;
    case KEY_C:
        new_char_ptr = CHAR_C_UP;
        break;
    case KEY_D:
        new_char_ptr = CHAR_D_UP;
        break;
    case KEY_E:
        new_char_ptr = CHAR_E_UP;
        break;
    case KEY_F:
        new_char_ptr = CHAR_F_UP;
        break;
    case KEY_G:
        new_char_ptr = CHAR_G_UP;
        break;
    case KEY_H:
        new_char_ptr = CHAR_H_UP;
        break;
    case KEY_I:
        new_char_ptr = CHAR_I_UP;
        break;
    case KEY_J:
        new_char_ptr = CHAR_J_UP;
        break;
    case KEY_K:
        new_char_ptr = CHAR_K_UP;
        break;
    case KEY_L:
        new_char_ptr = CHAR_L_UP;
        break;
    case KEY_M:
        new_char_ptr = CHAR_M_UP;
        break;
    case KEY_N:
        new_char_ptr = CHAR_N_UP;
        break;
    default:
        new_char_ptr = CHAR_SPACE; 
        break;
    }
    SCREEN_CONTENTS[cursor_location.x][cursor_location.y] = c;
    vga_add_char_to_screen_buffer(new_char_ptr);
    vga_move_cursor();
}

void vga_add_char_to_screen_buffer(char arr[6][4])
{

}

void vga_move_cursor()
{
    int x = cursor_location.x;
    int y = cursor_location.y;

    x++;
    if(x > FB_WIDTH/CHAR_WIDTH){
        y++;
        x=0;
    }

    cursor_location.x = x;
    cursor_location.y = y;
}