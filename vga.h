#ifndef VGA_H
#define VGA_H

void vga_init();
void vga_write_buffer_to_screen();
void vga_move_cursor();
void vga_add_char_at_cursor(char b);
void vga_add_char_to_screen_buffer(char arr[6][4]);

//frame buffer constants
#define FB_WIDTH        80        //frane buffer width
#define FB_HEIGHT       120        //frame buffer height
#define PIXELS_PER_BYTE 2         // actual generated pixels is (FB_WIDTH * PIXELS_PER_BYTE) * FB_HEIGHT
//vga constants
#define TOTAL_LINES   524         //total number of lines (vertical) including downtime
#define TOTAL_CYCLES  800         //total number of cycles (horizontal) including downtime
//actual pixel sizes
#define RES_WIDTH  640
#define RES_HEIGHT 480
//video pins
#define HSYNC 6
#define VSYNC 7
//font size definitions
#define CHAR_HEIGHT 6
#define CHAR_WIDTH  4

/* Color definitions, pins for color are as follows: 
 * |0|1|2|3|4|5|6|7|
 * |R|G|B|S|x|x|x|x|
 * "S" combines with the color pins to give a different shade
 * for a total of 16 different colors. */

#define RED      0b1000
#define GREEN    0b0100
#define BLUE     0b0010
#define YELLOW   0b1100
#define MAGENTA  0b1010
#define CYAN     0b0110
#define LRED     0b1001
#define LGREEN   0b0101
#define LBLUE    0b0011
#define LYELLOW  0b1101
#define LMAGENTA 0b1011
#define LCYAN    0b0111
#define BLACK    0b0000
#define WHITE    0b1111
#define LGREY    0b1110
#define DGREY    0b0001

//mask to isolate each half of color byte
#define BYTEMASKL 0b00001111
#define BYTEMASKH 0b11110000
#endif

#ifndef COORD_STRUCT
#define COORD_STRUCT
struct Coord
{
    int x,y;
};
#endif

#ifndef DEFINE_GLOBALS
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN  char CHAR_A_UP[6][4];
EXTERN  char CHAR_B_UP[6][4];
EXTERN  char CHAR_C_UP[6][4];
EXTERN  char CHAR_D_UP[6][4];
EXTERN  char CHAR_E_UP[6][4];
EXTERN  char CHAR_F_UP[6][4];
EXTERN  char CHAR_G_UP[6][4];
EXTERN  char CHAR_H_UP[6][4];
EXTERN  char CHAR_I_UP[6][4];
EXTERN  char CHAR_J_UP[6][4];
EXTERN  char CHAR_K_UP[6][4];
EXTERN  char CHAR_L_UP[6][4];
EXTERN  char CHAR_M_UP[6][4];
EXTERN  char CHAR_N_UP[6][4];
EXTERN  char CHAR_O_UP[6][4];
EXTERN  char CHAR_P_UP[6][4];
EXTERN  char CHAR_Q_UP[6][4];
EXTERN  char CHAR_R_UP[6][4];
EXTERN  char CHAR_S_UP[6][4];
EXTERN  char CHAR_T_UP[6][4];
EXTERN  char CHAR_U_UP[6][4];
EXTERN  char CHAR_V_UP[6][4];
EXTERN  char CHAR_W_UP[6][4];
EXTERN  char CHAR_X_UP[6][4];
EXTERN  char CHAR_Y_UP[6][4];
EXTERN  char CHAR_Z_UP[6][4];
EXTERN  char CHAR_SPACE[6][4];