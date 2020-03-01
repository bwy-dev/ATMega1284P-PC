#ifndef KEYBOARD_H
#define KEYBOARD_H

char get_key();
void set_key(char c);
void timer1_init();

#define NULL -0x01

//KeyCodes
#define KEY_1       0x00
#define KEY_2       0x01
#define KEY_3       0x02
#define KEY_4       0x03
#define KEY_5       0x04
#define KEY_6       0x05
#define KEY_7       0x06
#define KEY_8       0x07
#define KEY_9       0x08
#define KEY_0       0x09
#define KEY_MINUS   0x0A
#define KEY_PLUS    0x0B
#define KEY_Q       0x0C
#define KEY_W       0x0D
#define KEY_E       0x0E
#define KEY_R       0x0F
#define KEY_T       0x10
#define KEY_Y       0x11
#define KEY_U       0x12
#define KEY_I       0x13
#define KEY_O       0x14
#define KEY_P       0x15
#define KEY_A       0x16
#define KEY_S       0x17
#define KEY_D       0x18
#define KEY_F       0x19
#define KEY_G       0x1A
#define KEY_H       0x1B
#define KEY_J       0x1C
#define KEY_K       0x1D
#define KEY_L       0x1E
#define KEY_Z       0x1F
#define KEY_X       0x20
#define KEY_C       0x21
#define KEY_V       0x22
#define KEY_B       0x23
#define KEY_N       0x24
#define KEY_M       0x25
#define KEY_TAB     0x26
#define KEY_CAPS    0x27
#define KEY_SHIFT   0x28
#define KEY_CTRL    0x29
#define KEY_SQRB_L  0x2A
#define KEY_SQRB_R  0x2B
#define KEY_COLON   0x2C
#define KEY_AT      0x2D
#define KEY_ANGB_L  0x2E
#define KEY_ANGB_R  0x2F
#define KEY_QMARK   0x30
#define KEY_ENTER   0x31
#define KEY_TILDE   0x32
#define KEY_SPACE   0x33
#define KEY_UP      0x34
#define KEY_DOWN    0x35
#define KEY_LEFT    0x36
#define KEY_RIGHT   0x37
#define KEY_ALT     0x38
#define KEY_BKSPC   0x39

#endif