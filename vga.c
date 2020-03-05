#include "vga.h"
#include "main.h"
#include "keyboard.h"
#include <avr/io.h>

//individual pixels on screen. it has a constant address so we know where to find it in assembly code
volatile byte FRAME_BUFFER[FB_WIDTH][FB_HEIGHT] __attribute__((address(0x0570))); 

struct Coord cursor_location;


void vga_init()
{
    cursor_location.x = 0;
    cursor_location.y = 0;

    int x,y;
    for(y = 0; y < FB_WIDTH; y++)
	{
        for(x = 0; x < FB_HEIGHT; x++)
		{
			byte color = x % 2 == 0 ? BLUE : RED ;
            FRAME_BUFFER[y][x] = color;    //fill frame buffer with alternating blue and red pixels for testing
        }
    }
}


 void vga_add_char_to_frame_buffer(volatile char arr[][CHAR_WIDTH])
{
    uint8_t x = cursor_location.x * CHAR_WIDTH;
    uint8_t y = cursor_location.y * CHAR_HEIGHT;
    uint8_t i,j;

    for(i = 0; i < CHAR_HEIGHT; i++)
	{
	    for(j = 0; j < CHAR_WIDTH; j++)
		{
          FRAME_BUFFER[x + i][y + j/2] = arr[j][i];
        }
    }
}

void vga_move_cursor()
{
    int x = cursor_location.x;
    int y = cursor_location.y;
    x += CHAR_WIDTH;

    if(x > FB_WIDTH/CHAR_WIDTH)
	{
        y += CHAR_HEIGHT;
        x=0;
    }

    cursor_location.x = x;
    cursor_location.y = y;
}

void vga_add_char_at_cursor(char b)
{
    switch (b)
    {
      case KEY_A:
          vga_add_char_to_frame_buffer(CHAR_A_UP);
          break;
      case KEY_B:
          vga_add_char_to_frame_buffer(CHAR_B_UP);
          break;
      case KEY_C:
          vga_add_char_to_frame_buffer(CHAR_C_UP);
          break;
      case KEY_D:
          vga_add_char_to_frame_buffer(CHAR_D_UP);
          break;
      case KEY_E:
          vga_add_char_to_frame_buffer(CHAR_E_UP);
          break;
      case KEY_F:
          vga_add_char_to_frame_buffer(CHAR_F_UP);
          break;
      case KEY_G:
          vga_add_char_to_frame_buffer(CHAR_G_UP);
          break;
      case KEY_H:
          vga_add_char_to_frame_buffer(CHAR_H_UP);
          break;
      case KEY_I:
          vga_add_char_to_frame_buffer(CHAR_I_UP);
          break;
      case KEY_J:
          vga_add_char_to_frame_buffer(CHAR_J_UP);
          break;
      case KEY_K:
          vga_add_char_to_frame_buffer(CHAR_K_UP);
          break;
      case KEY_L:
          vga_add_char_to_frame_buffer(CHAR_L_UP);
          break;
      case KEY_M:
          vga_add_char_to_frame_buffer(CHAR_M_UP);
          break;
      case KEY_N:
          vga_add_char_to_frame_buffer(CHAR_N_UP);
          break;
      case KEY_O:
          vga_add_char_to_frame_buffer(CHAR_O_UP);
          break;
      case KEY_P:
          vga_add_char_to_frame_buffer(CHAR_P_UP);
          break;
      case KEY_Q:
          vga_add_char_to_frame_buffer(CHAR_Q_UP);
          break;
      case KEY_R:
          vga_add_char_to_frame_buffer(CHAR_R_UP);
          break;
      case KEY_S:
          vga_add_char_to_frame_buffer(CHAR_S_UP);
          break;
      case KEY_T:
          vga_add_char_to_frame_buffer(CHAR_T_UP);
          break;
      case KEY_U:
          vga_add_char_to_frame_buffer(CHAR_U_UP);
          break;
      case KEY_V:
          vga_add_char_to_frame_buffer(CHAR_V_UP);
          break;
      case KEY_W:
          vga_add_char_to_frame_buffer(CHAR_W_UP);
          break;
      case KEY_X:
          vga_add_char_to_frame_buffer(CHAR_X_UP);
          break;
      case KEY_Y:
          vga_add_char_to_frame_buffer(CHAR_Y_UP);
          break;
      case KEY_Z:
          vga_add_char_to_frame_buffer(CHAR_Z_UP);
          break;
      case KEY_SPACE:
          vga_add_char_to_frame_buffer(CHAR_SPACE);
          break;
      default:
          vga_add_char_to_frame_buffer(CHAR_SPACE); 
          break;
    }
    vga_move_cursor();
}