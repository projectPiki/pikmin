#include "Dolphin/rand.h"

u32 next = 1;

/**
 * @TODO: Documentation
 */
int rand(void)
{
	next = next * 1103515245 + 12345;
	return ((u16)((u32)next >> 0x10) & 0x7fff);
}

/**
 * @TODO: Documentation
 */
void srand(u32 seed)
{
	next = seed;
}
