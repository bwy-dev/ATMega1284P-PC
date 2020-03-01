#ifndef VGA_H
#define VGA_H

//frame buffer constants
#define FB_WIDTH 128        //frane buffer width
#define FB_HEIGHT 96        //frame buffer height
//vga constants
#define TOTAL_LINES   524
#define TOTAL_CYCLES  800
//actual pixel sizes
#define RES_WIDTH 640
#define RES_HEIGHT 480
//video pins
#define HSYNC 6
#define VSYNC 7

//font size definitions
#define CHAR_HEIGHT 6
#define CHAR_WIDTH 4

/* Color definitions, pins for color are as follows: 
 * |0|1|2|3|4|5|6|7|
 * |R|R|G|G|B|B|x|x|
 * the second of each color is a darker shade */

#define RED     0x11000000
#define GREEN   0x00110000
#define BLUE    0x00001100
#define BLACK   0x00000000
#define WHILE   0x11111100
#define YELLOW  0x11110000
#define PURPLE  0x11001100
#define CYAN    0x00111100

#endif