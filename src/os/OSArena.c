static void* __OSArenaHi = (void*)0x00000000;
static void* __OSArenaLo = (void*)0xffffffff;

/*
 * --INFO--
 * Address:	801F6918
 * Size:	000008
 */
void* OSGetArenaHi(void) { return __OSArenaHi; }

/*
 * --INFO--
 * Address:	801F6920
 * Size:	000008
 */
void* OSGetArenaLo(void) { return __OSArenaLo; }

/*
 * --INFO--
 * Address:	801F6928
 * Size:	000008
 */
void OSSetArenaHi(void* arena_hi)

{
	__OSArenaHi = arena_hi;
	return;
}

/*
 * --INFO--
 * Address:	801F6930
 * Size:	000008
 */
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
