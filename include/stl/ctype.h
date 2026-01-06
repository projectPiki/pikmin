#ifndef _CTYPE_H
#define _CTYPE_H

#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ctype_api.h"
#include "locale.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

int tolower(int c);
int toupper(int c);

inline int isalnum(u8 c)
{
	return (int)(__ctype_map[c] & __alphanumeric);
}
inline int isalpha(u8 c)
{
	return (int)(__ctype_map[c] & __letter);
}
inline int iscntrl(u8 c)
{
	return (int)(__ctype_map[c] & __control);
}
inline int isdigit(u8 c)
{
	return (int)(__ctype_map[c] & __digit);
}
inline int isgraph(u8 c)
{
	return (int)(__ctype_map[c] & __graphic);
}
inline int islower(u8 c)
{
	return (int)(__ctype_map[c] & __lower_case);
}
inline int isprint(u8 c)
{
	return (int)(__ctype_map[c] & __printable);
}
inline int ispunct(u8 c)
{
	return (int)(__ctype_map[c] & __punctuation);
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

END_SCOPE_EXTERN_C
#endif
