static void* __OSArenaHi = (void*)0x00000000;
static void* __OSArenaLo = (void*)0xffffffff;

void* OSGetArenaHi(void)
{
	return __OSArenaHi;
}

void* OSGetArenaLo(void)
{
	return __OSArenaLo;
}

void OSSetArenaHi(void* arena_hi)

{
	__OSArenaHi = arena_hi;
	return;
}

void OSSetArenaLo(void* arena_lo)

{
	__OSArenaLo = arena_lo;
	return;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void OSAllocFromArenaLo(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void OSAllocFromArenaHi(void)
{
	// UNUSED FUNCTION
}
