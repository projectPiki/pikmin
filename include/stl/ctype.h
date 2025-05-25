#ifndef _CTYPE_H
#define _CTYPE_H

#include "types.h"
#include "locale.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ctype_api.h"

#ifdef __cplusplus
extern "C" {
#endif

int tolower(int __c);

inline int isalpha(u8 c)
{
	return (int)(__ctype_map[c] & __letter);
}
inline int isdigit(u8 c)
{
	return (int)(__ctype_map[c] & __digit);
}
inline int isspace(u8 c)
{
	return (int)(__ctype_map[c] & __whitespace);
}
inline int isupper(u8 c)
{
	return (int)(__ctype_map[c] & __upper_case);
}
inline int isxdigit(u8 c)
{
	return (int)(__ctype_map[c] & __hex_digit);
}
// added underscore to avoid naming conflicts
inline int _tolower(u8 c)
{
	return (c == -1 ? -1 : (int)__lower_map[c]);
}
inline int _toupper(u8 c)
{
	return (c == -1 ? -1 : (int)__upper_map[c]);
}

#ifdef __cplusplus
}
#endif
#endif
