#ifndef _STDIO_H
#define _STDIO_H
#include "types.h"
#include "stdarg.h"

typedef struct
{
    unsigned char filler0[4];
    unsigned short unk4b0:7;
    unsigned short unk4b7:3;
    unsigned short unk4b10:2;
} FILE;

int puts(const char *s);
int printf(const char *, ...);
int sprintf(char *s, const char *format, ...);
int vprintf(const char *format, va_list arg);
int vsprintf(char *s, const char *format, va_list arg);

#endif
