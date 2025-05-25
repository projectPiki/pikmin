#ifndef _CTYPE_H
#define _CTYPE_H

#include "types.h"
#include "locale.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ctype_api.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __zero_fill(c) ((int)(u8)(c))

int tolower(int __c);

inline int isalpha(char c)
{
	return (int)(__ctype_map[__zero_fill(c)] & __letter);
}
inline int isdigit(char c)
{
	return (int)(__ctype_map[__zero_fill(c)] & __digit);
}
inline int isspace(char c)
{
	return (int)(__ctype_map[__zero_fill(c)] & __whitespace);
}
inline int isupper(char c)
{
	return (int)(__ctype_map[__zero_fill(c)] & __upper_case);
}
inline int isxdigit(char c)
{
	return (int)(__ctype_map[__zero_fill(c)] & __hex_digit);
}
// added underscore to avoid naming conflicts
inline int _tolower(char c)
{
	return (c == -1 ? -1 : (int)__lower_map[__zero_fill(c)]);
}
inline int _toupper(char c)
{
	return (c == -1 ? -1 : (int)__upper_map[__zero_fill(c)]);
}

#ifdef __cplusplus
}
#endif
#endif
