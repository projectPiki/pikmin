#include "PowerPC_EABI_Support/MSL_C/MSL_Common/wchar.h"
#include "types.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void mblen(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
int mbtowc(wchar_t* pwc, const char* s, size_t n)
{
	if (!s) {
		return 0;
	}

	if (n == 0) {
		return -1;
	}

	if (pwc) {
		*pwc = *s;
	}

	if (*s == 0) {
		return 0;
	}

	return 1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void wctomb(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void mbstowcs(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
size_t wcstombs(char* s, const wchar_t* pwcs, size_t n)
{
	wchar_t next;
	size_t chars_written;
	int i;

	chars_written = 0;
	for (i = 0; i < n; ++i) {
		next = *pwcs++;
		*s++ = (char)next;
		if ((char)next == '\0')
			break;
		++chars_written;
	}
	return chars_written;
}
