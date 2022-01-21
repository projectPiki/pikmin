#ifndef _TYPES_H
#define _TYPES_H

typedef signed char         s8;
typedef signed short        s16;
typedef signed long         s32;
typedef signed long long    s64;
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;

typedef volatile u8         vu8;
typedef volatile u16        vu16;
typedef volatile u32        vu32;
typedef volatile u64        vu64;
typedef volatile s8         vs8;
typedef volatile s16        vs16;
typedef volatile s32        vs32;
typedef volatile s64        vs64;

typedef float               f32;
typedef double              f64;
typedef volatile f32        vf32;
typedef volatile f64        vf64;

typedef int                 BOOL;

/* int<x>_t */
typedef signed char         int8_t;
typedef short               int16_t;
typedef int                 int32_t;

/* uint<x>_t */
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;

typedef int                 intptr_t;
typedef unsigned int        uintptr_t;

typedef unsigned long size_t;

#define TRUE 1
#define FALSE 0

#define NULL ((void*)0)
#define nullptr 0

#define BUMP_REGISTER(reg) { asm { mr reg, reg } }

#define ATTRIBUTE_ALIGN(num) __attribute__ ((aligned (num)))

#endif
