#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void TRKWaitForACK(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021E6B0
 * Size:	0000D8
 */
void TRKDoNotifyStopped(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r4, r1, 0xC
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x8
	  bl        -0x2184
	  mr.       r31, r3
	  bne-      .loc_0xBC
	  lwz       r5, 0xC(r1)
	  lwz       r3, 0xC(r5)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x44
	  li        r4, 0x301
	  b         .loc_0x64

	.loc_0x44:
	  addi      r0, r3, 0x1
	  add       r3, r5, r3
	  stw       r0, 0xC(r5)
	  li        r4, 0
	  stb       r30, 0x10(r3)
	  lwz       r3, 0x8(r5)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r5)

	.loc_0x64:
	  cmpwi     r4, 0
	  bne-      .loc_0x8C
	  rlwinm    r0,r30,0,24,31
	  cmplwi    r0, 0x90
	  bne-      .loc_0x84
	  lwz       r3, 0xC(r1)
	  bl        0xF54
	  b         .loc_0x8C

	.loc_0x84:
	  lwz       r3, 0xC(r1)
	  bl        0xFD8

	.loc_0x8C:
	  lwz       r3, 0xC(r1)
	  addi      r4, r1, 0x10
	  li        r5, 0x2
	  li        r6, 0x3
	  li        r7, 0x1
	  bl        -0x25C
	  mr.       r31, r3
	  bne-      .loc_0xB4
	  lwz       r3, 0x10(r1)
	  bl        -0x214C

	.loc_0xB4:
	  lwz       r3, 0x8(r1)
	  bl        -0x2154

	.loc_0xBC:
	  mr        r3, r31
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
