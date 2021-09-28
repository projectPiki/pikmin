

/*
 * --INFO--
 * Address:	801F6918
 * Size:	000008
 */
void OSGetArenaHi(void)
{
/*
.loc_0x0:
  lwz       r3, 0x31F0(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6920
 * Size:	000008
 */
void OSGetArenaLo(void)
{
/*
.loc_0x0:
  lwz       r3, 0x29E0(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6928
 * Size:	000008
 */
void OSSetArenaHi(void)
{
/*
.loc_0x0:
  stw       r3, 0x31F0(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6930
 * Size:	000008
 */
void OSSetArenaLo(void)
{
/*
.loc_0x0:
  stw       r3, 0x29E0(r13)
  blr
*/
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