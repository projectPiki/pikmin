#ifndef _STDIO_H
#define _STDIO_H

#include "types.h"
#include "stl/stdarg.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct {
	u8 filler0[4];
	u16 unk4b0 : 7;
	u16 unk4b7 : 3;
	u16 unk4b10 : 2;
} FILE;

int puts(const char* s);
int printf(const char*, ...);
int sprintf(char* s, const char* format, ...);
int vprintf(const char* format, va_list arg);
int vsprintf(char* s, const char* format, va_list arg);
int sscanf(const char* s, const char* format, ...);

// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/FILE_POS.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/direct_io.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/file_io.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/printf.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/scanf.h"

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
