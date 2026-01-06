#ifndef _MSL_MBSTRING_H
#define _MSL_MBSTRING_H

#include "PowerPC_EABI_Support/MSL_C/MSL_Common/wchar.h"
#include "types.h"
#include <stddef.h>

BEGIN_SCOPE_EXTERN_C

int __mbtowc_noconv(wchar_t*, const char*, size_t);
int __wctomb_noconv(char*, wchar_t);
size_t wcstombs(char* s, const wchar_t* pwcs, size_t n);
int mbstowcs(wchar_t* pwc, const char* s, size_t n);
int wctomb(char* s, wchar_t wchar);
static int unicode_to_UTF8(char* s, wchar_t wchar);
int mbtowc(wchar_t* pwc, const char* s, size_t n);
static int is_utf8_complete(const char* s, size_t n);

END_SCOPE_EXTERN_C
#endif
