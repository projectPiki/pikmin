#include "Dolphin/rand.h"

u32 next = 1;

/*
 * --INFO--
 * Address:	80218068
 * Size:	000008
 */
void srand(u32 seed)
{
	next = seed;
}

/*
 * --INFO--
 * Address:	80218070
 * Size:	000024
 */
int rand(void)
{
	next = next * 1103515245 + 12345;
	return ((u16)((u32)next >> 0x10) & 0x7fff);
}
