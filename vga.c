/*********************************************************************************
 *                                                                               *
 *              Adapted from Andrew Rossignol's AVR VGA code available at:       *
 *      Available at https://github.com/aarossig/avr-vga/blob/master/src/main.s  *
 *                                                                               *
**********************************************************************************/
/*
 *NOTE: There is currently no timing calculation being done, so this will not work properly at the moment
 *I do not currently have accesses to Atmel Studio, once I do I will calculate timings using Simulator and 
 *make necessary adjustments.
 */
#include "vga.h"
#include "main.h"
#include "keyboard.h"
#include <avr/io.h>


volatile byte SCREEN_CONTENTS[FB_WIDTH/CHAR_WIDTH][FB_HEIGHT/CHAR_HEIGHT]; //Actual characters currently on screen
volatile byte FRAME_BUFFER[FB_WIDTH][FB_HEIGHT];                           //individual pixels on screen

struct Coord cursor_location;


void vga_init()
{
    cursor_location.x = 0;
    cursor_location.y = 0;
    //disable watchdog
    WDTCSR = 0;

    int x,y;
    for(y = 0; y < FB_HEIGHT; y++){
        for(x = 0; x < FB_WIDTH; x++){
            FRAME_BUFFER[x][y] = 0x00;    //fill frame buffer with black pixels
        }
    }
}

int vga_vertical_sync()
{
  PORTA = (1 << VSYNC);
  return 0;
}

void vga_horizontal_sync()
{
  PORTA = (1 << HSYNC);
}


 void vga_add_char_to_frame_buffer(volatile char arr[][CHAR_WIDTH])
{
    uint8_t x = cursor_location.x * CHAR_WIDTH;
    uint8_t y = cursor_location.y * CHAR_HEIGHT;
    uint8_t i,j;

    for(i = 0; i < CHAR_HEIGHT; i++){
	    for(j = 0; j < CHAR_WIDTH; j++){
          FRAME_BUFFER[x + i][y + j/2] = arr[j][i];
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


void vga_add_char_at_cursor(char b)
{
	
    volatile char c;
    switch (b)
    {
      case KEY_A:
          vga_add_char_to_frame_buffer(CHAR_A_UP);
          c = 'A';
          break;
      case KEY_B:
          vga_add_char_to_frame_buffer(CHAR_B_UP);
		  c = 'B';
          break;
      case KEY_C:
          vga_add_char_to_frame_buffer(CHAR_C_UP);
          c = 'C';
          break;
      case KEY_D:
          vga_add_char_to_frame_buffer(CHAR_D_UP);
          c = 'D';
          break;
      case KEY_E:
          vga_add_char_to_frame_buffer(CHAR_E_UP);
          c = 'E';
          break;
      case KEY_F:
          vga_add_char_to_frame_buffer(CHAR_F_UP);
          c = 'F';
          break;
      case KEY_G:
          vga_add_char_to_frame_buffer(CHAR_G_UP);
          c = 'G';
          break;
      case KEY_H:
          vga_add_char_to_frame_buffer(CHAR_H_UP);
          c = 'H';
          break;
      case KEY_I:
          vga_add_char_to_frame_buffer(CHAR_I_UP);
          c = 'I';
          break;
      case KEY_J:
          vga_add_char_to_frame_buffer(CHAR_J_UP);
          c = 'J';
          break;
      case KEY_K:
          vga_add_char_to_frame_buffer(CHAR_K_UP);
          c = 'K';
          break;
      case KEY_L:
          vga_add_char_to_frame_buffer(CHAR_L_UP);
          c = 'L';
          break;
      case KEY_M:
          vga_add_char_to_frame_buffer(CHAR_M_UP);
          c = 'M';
          break;
      case KEY_N:
          vga_add_char_to_frame_buffer(CHAR_N_UP);
          c = 'N';
          break;
      case KEY_O:
          vga_add_char_to_frame_buffer(CHAR_O_UP);
          c = 'O';
          break;
      case KEY_P:
          vga_add_char_to_frame_buffer(CHAR_P_UP);
          c = 'P';
          break;
      case KEY_Q:
          vga_add_char_to_frame_buffer(CHAR_Q_UP);
          c = 'Q';
          break;
      case KEY_R:
          vga_add_char_to_frame_buffer(CHAR_R_UP);
          c = 'R';
          break;
      case KEY_S:
          vga_add_char_to_frame_buffer(CHAR_S_UP);
          c = 'S';
          break;
      case KEY_T:
          vga_add_char_to_frame_buffer(CHAR_T_UP);
          c = 'T';
          break;
      case KEY_U:
          vga_add_char_to_frame_buffer(CHAR_U_UP);
          c = 'U';
          break;
      case KEY_V:
          vga_add_char_to_frame_buffer(CHAR_V_UP);
          c = 'V';
          break;
      case KEY_W:
          vga_add_char_to_frame_buffer(CHAR_W_UP);
          c = 'W';
          break;
      case KEY_X:
          vga_add_char_to_frame_buffer(CHAR_X_UP);
          c = 'X';
          break;
      case KEY_Y:
          vga_add_char_to_frame_buffer(CHAR_Y_UP);
          c = 'Y';
          break;
      case KEY_Z:
          vga_add_char_to_frame_buffer(CHAR_Z_UP);
          c = 'Z';
          break;
      case KEY_SPACE:
          vga_add_char_to_frame_buffer(CHAR_SPACE);
          c = ' ';
          break;
      default:
          vga_add_char_to_frame_buffer(CHAR_SPACE); 
          break;
    }
    SCREEN_CONTENTS[cursor_location.x][cursor_location.y] = c;
    vga_move_cursor();
}

void vga_write_line(volatile int start)
{
    write_line();
}