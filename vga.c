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
#include "main.h"
#include "keyboard.h"
#include <avr/io.h>

volatile char SCREEN_CONTENTS[FB_WIDTH/CHAR_WIDTH][FB_HEIGHT/CHAR_HEIGHT]; //Actual characters currently on screen
volatile char FRAME_BUFFER[FB_WIDTH][FB_HEIGHT];                           //individual pixels on screen
struct Coord cursor_location;

void vga_init()
{
    cursor_location.x = 0;
    cursor_location.y = 0;
    //disable watchdog
    WDTCSR = 0;
    //configure VGA out pins
    DDRA = 0xff;
}

void vga_write_buffer_to_screen()
{
    uint8_t x,y;
    for(y = 0; y< FB_HEIGHT; y++){
        uint8_t i;
        //print same row RES_HEIGHT/FB_HEIGHT times, to reduce resolution and make up for limited storage.
        for(i = 0; i< RES_HEIGHT/FB_HEIGHT; i++ ) 
        {
            for(x = 0; x<FB_WIDTH; x++){
                uint8_t j;
                //print same pixel RES_WIDTH/FB_WIDTH times, to reduce resolution and make up for limited storage.
                for(j = 0; j < RES_WIDTH/FB_WIDTH; j++){
                    PORTA = FRAME_BUFFER[x][y];
                }
            }
            //Some Code here for waiting out front/rear porch and sync pulse timings
            PORTA = (1 << HSYNC); //send HSYNC signal to move on to next line
        }
    }
    PORTA = (1 << VSYNC); //send VSYNC signal to return to top left of screen
}

void vga_add_char_to_screen_buffer(char arr[6][4])
{
    uint8_t x = cursor_location.x * CHAR_WIDTH;
    uint8_t y = cursor_location.y * CHAR_HEIGHT;
    uint8_t i,j;

    for(i = 0; i < LEN(arr); i++){
        for(j = 0; j < LEN(arr[0]); j++){
            FRAME_BUFFER[x + j][y + i] = arr[j][i];
        }
    }
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


void vga_add_char_at_cursor(char c)
{
    switch (c)
    {
    case KEY_A:
         vga_add_char_to_screen_buffer(CHAR_A_UP);
        break;
    case KEY_B:
          vga_add_char_to_screen_buffer(CHAR_B_UP);
        break;
    case KEY_C:
          vga_add_char_to_screen_buffer(CHAR_C_UP);
        break;
    case KEY_D:
          vga_add_char_to_screen_buffer(CHAR_D_UP);
        break;
    case KEY_E:
          vga_add_char_to_screen_buffer(CHAR_E_UP);
        break;
    case KEY_F:
          vga_add_char_to_screen_buffer(CHAR_F_UP);
        break;
    case KEY_G:
          vga_add_char_to_screen_buffer(CHAR_G_UP);
        break;
    case KEY_H:
          vga_add_char_to_screen_buffer(CHAR_H_UP);
        break;
    case KEY_I:
          vga_add_char_to_screen_buffer(CHAR_I_UP);
        break;
    case KEY_J:
          vga_add_char_to_screen_buffer(CHAR_J_UP);
        break;
    case KEY_K:
          vga_add_char_to_screen_buffer(CHAR_K_UP);
        break;
    case KEY_L:
          vga_add_char_to_screen_buffer(CHAR_L_UP);
        break;
    case KEY_M:
          vga_add_char_to_screen_buffer(CHAR_M_UP);
        break;
    case KEY_N:
          vga_add_char_to_screen_buffer(CHAR_N_UP);
        break;
    default:
          vga_add_char_to_screen_buffer(CHAR_SPACE); 
        break;
    }
    SCREEN_CONTENTS[cursor_location.x][cursor_location.y] = c;
    vga_move_cursor();
}

