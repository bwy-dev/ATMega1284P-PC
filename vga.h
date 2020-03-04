#ifndef VGA_H
#define VGA_H

void vga_init();
void vga_move_cursor();
void vga_add_char_at_cursor(char b);
void vga_add_char_to_frame_buffer(volatile char arr[6][4]);
extern void write_line(void);


//frame buffer constants
#define FB_WIDTH      128    //frame buffer width
#define FB_HEIGHT     94     //frame buffer height
//VGA constants
#define TOTAL_LINES   524    //total number of lines (vertical) including downtime
#define TOTAL_CYCLES  800    //total number of cycles (horizontal) including downtime
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
 * |R|R|G|G|B|B|S|S|
 */

#define RED      0b11000000
#define GREEN    0b00110000
#define BLUE     0b00001100
#define YELLOW   0b11110000
#define MAGENTA  0b11001100
#define CYAN     0b00111100
#define BLACK    0b00000000
#define WHITE    0b11111111
#define LGREY    0b10101000
#define DGREY    0b01010100

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

EXTERN  volatile char CHAR_A_UP[6][4];
EXTERN  volatile char CHAR_B_UP[6][4];
EXTERN  volatile char CHAR_C_UP[6][4];
EXTERN  volatile char CHAR_D_UP[6][4];
EXTERN  volatile char CHAR_E_UP[6][4];
EXTERN  volatile char CHAR_F_UP[6][4];
EXTERN  volatile char CHAR_G_UP[6][4];
EXTERN  volatile char CHAR_H_UP[6][4];
EXTERN  volatile char CHAR_I_UP[6][4];
EXTERN  volatile char CHAR_J_UP[6][4];
EXTERN  volatile char CHAR_K_UP[6][4];
EXTERN  volatile char CHAR_L_UP[6][4];
EXTERN  volatile char CHAR_M_UP[6][4];
EXTERN  volatile char CHAR_N_UP[6][4];
EXTERN  volatile char CHAR_O_UP[6][4];
EXTERN  volatile char CHAR_P_UP[6][4];
EXTERN  volatile char CHAR_Q_UP[6][4];
EXTERN  volatile char CHAR_R_UP[6][4];
EXTERN  volatile char CHAR_S_UP[6][4];
EXTERN  volatile char CHAR_T_UP[6][4];
EXTERN  volatile char CHAR_U_UP[6][4];
EXTERN  volatile char CHAR_V_UP[6][4];
EXTERN  volatile char CHAR_W_UP[6][4];
EXTERN  volatile char CHAR_X_UP[6][4];
EXTERN  volatile char CHAR_Y_UP[6][4];
EXTERN  volatile char CHAR_Z_UP[6][4];
EXTERN  volatile char CHAR_SPACE[6][4];