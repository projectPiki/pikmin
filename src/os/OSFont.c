#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void GetFontCode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000174
 */
void Decode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GetFontSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F8F24
 * Size:	000058
 */
void OSGetFontEncode(void)
{
	/*
	.loc_0x0:
	  lhz       r3, 0x29F0(r13)
	  cmplwi    r3, 0x1
	  blelr-
	  lis       r3, 0x8000
	  lwz       r0, 0xCC(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x24
	  blt-      .loc_0x48
	  b         .loc_0x48

	.loc_0x24:
	  lis       r3, 0xCC00
	  lhz       r0, 0x206E(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x3C
	  li        r0, 0x1
	  b         .loc_0x40

	.loc_0x3C:
	  li        r0, 0

	.loc_0x40:
	  sth       r0, 0x29F0(r13)
	  b         .loc_0x50

	.loc_0x48:
	  li        r0, 0
	  sth       r0, 0x29F0(r13)

	.loc_0x50:
	  lhz       r3, 0x29F0(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void ReadROM(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void ReadFont(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void OSLoadFont(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002CC
 */
void OSGetFontTexel(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003B0
 */
void ExpandFontSheet(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void OSInitFont(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000178
 */
void OSGetFontTexture(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void OSGetFontWidth(void)
{
	// UNUSED FUNCTION
}
