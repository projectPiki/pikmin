#ifndef _DOLPHIN_STL_H
#define _DOLPHIN_STL_H

#include "types.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

DECL_SECT(".init") void* memcpy(void*, const void*, size_t);
DECL_SECT(".init") void __fill_mem(void*, int, size_t);
DECL_SECT(".init") void* memset(void*, int, size_t);

#ifdef __MWERKS__
typedef struct {
	char gpr;
	char fpr;
	char reserved[2];
	char* input_arg_area;
	char* reg_save_area;
} __va_list[1];
typedef __va_list va_list;

#ifndef __MWERKS__
extern void __builtin_va_info(va_list*);
#endif

void* __va_arg(va_list v_list, u8 type);

#define va_start(ap, fmt) ((void)fmt, __builtin_va_info(&ap))
#define va_arg(ap, t)     (*((t*)__va_arg(ap, _var_arg_typeof(t))))
#define va_end(ap)        (void)0

#elif defined(__GNUC__)
typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_end(v)      __builtin_va_end(v)
#define va_arg(v, l)   __builtin_va_arg(v, l)
#else
typedef char* va_list;
#define _INTSIZEOF(n)   ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list) & v + _INTSIZEOF(v))
#define va_arg(ap, t)   (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap)      (ap = (va_list)0)
#endif

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
