#include "types.h"
#include <stddef.h>

extern "C" {

/**
 * @todo Documentation
 * @note UNUSED Size: 000074
 */
void __dc_arr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00007C
 */
void __del_arr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000088
 */
void __new_arr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000078
 */
void __init_arr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo Documentation
 */
void* __copy(char* dest, char* src, size_t size)
{
	char* p;

	if (dest && size) {
		p = dest;
		do {
			*p++ = *src++;
		} while (--size);
	}

	return (dest);
}
}
