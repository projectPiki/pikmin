#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void fmax(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void fmin(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021B1E8
 * Size:	000080
 */
void __fpclassifyd(f64)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  lis       r0, 0x7FF0
	  stfd      f1, 0x8(r1)
	  lwz       r4, 0x8(r1)
	  rlwinm    r3,r4,0,1,11
	  cmpw      r3, r0
	  beq-      .loc_0x2C
	  bge-      .loc_0x74
	  cmpwi     r3, 0
	  beq-      .loc_0x50
	  b         .loc_0x74

	.loc_0x2C:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0x40
	  lwz       r0, 0xC(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x48

	.loc_0x40:
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x48:
	  li        r3, 0x2
	  b         .loc_0x78

	.loc_0x50:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0x64
	  lwz       r0, 0xC(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x6C

	.loc_0x64:
	  li        r3, 0x5
	  b         .loc_0x78

	.loc_0x6C:
	  li        r3, 0x3
	  b         .loc_0x78

	.loc_0x74:
	  li        r3, 0x4

	.loc_0x78:
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void fdim(void)
{
	// UNUSED FUNCTION
}
