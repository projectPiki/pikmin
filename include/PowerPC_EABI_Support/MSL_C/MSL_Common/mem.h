#ifndef _MSL_MEM_H
#define _MSL_MEM_H

#include "types.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

int memcmp(const void*, const void*, size_t);
void* memchr(u8*, int, size_t);
void* memmove(void*, const void*, size_t);
void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* dest, int val, size_t count);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
