#ifndef _STRING_H
#define _STRING_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

size_t strlen(char*);
char* strrchr(const char* str, int chr);
char* strchr(const char* str, int chr);
int strncmp(const char* str1, const char* str2, size_t n);
int strcmp(const char* str1, const char* str2);
int stricmp(char*, char*);
char* strcpy(char*, const char*);
char* strcat(char* dst, const char* src);
char* strncpy(char* dst, const char* src, size_t n);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

struct String
{
  u32 m_length; // _00
  u8 *m_str;    // _04

  int getLength();
};

#endif
