#ifndef _STL_STRING_H
#define _STL_STRING_H

#include "extras.h"
#include "mem.h"
#include "types.h"
#ifdef __cplusplus
extern "C" {
#endif

char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, size_t n);

char* strcat(char* dst, const char* src);
char* strncat(char* dst, const char* src, size_t n);

int strcmp(const char* lhs, const char* rhs);
int strncmp(const char* lhs, const char* rhs, size_t n);
char* strchr(const char* str, int ch);
char* strstr(const char* str, const char* substr);
char* strrchr(const char* str, int chr);
size_t strlen(const char* str);

#ifdef __cplusplus
}
#endif
#endif
