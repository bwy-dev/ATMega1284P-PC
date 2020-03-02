#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#define F_CPU 20000000UL
#define __AVR_ATmega1284P__
#define __asm__ __asm
typedef unsigned char byte;
typedef enum{
    true = 1,
    false = 0,
}bool;
#define LEN(arr) ((int) sizeof(arr)/sizeof(arr)[0])
#endif