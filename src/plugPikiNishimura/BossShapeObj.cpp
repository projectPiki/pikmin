#include "Boss.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80152684
 * Size:	000110
 */
BossShapeObject::BossShapeObject(Shape*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8023
	  stw       r0, 0x4(r1)
	  subi      r0, r6, 0x7730
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  mr.       r30, r5
	  stw       r29, 0x9C(r1)
	  mr        r29, r4
	  stw       r28, 0x98(r1)
	  addi      r28, r3, 0
	  stw       r0, 0x10(r3)
	  li        r0, 0
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x5788(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x5784(r2)
	  stfs      f0, 0xC(r3)
	  stw       r29, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x24(r3)
	  beq-      .loc_0xB0
	  lis       r3, 0x802D
	  crclr     6, 0x6
	  subi      r4, r3, 0xEA8
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  bl        0xC3EA4
	  li        r3, 0xB8
	  bl        -0x10B6F8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xA0
	  lis       r6, 0x1
	  addi      r4, r29, 0
	  addi      r5, r1, 0x14
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0x101E7C

	.loc_0xA0:
	  stw       r31, 0x14(r28)
	  lwz       r3, 0x14(r28)
	  stw       r30, 0x4(r3)
	  b         .loc_0xDC

	.loc_0xB0:
	  li        r3, 0xB8
	  bl        -0x10B734
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xD8
	  addi      r4, r29, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  bl        -0x101EB4

	.loc_0xD8:
	  stw       r31, 0x14(r28)

	.loc_0xDC:
	  lwz       r3, 0x0(r28)
	  addi      r5, r28, 0x4
	  li        r4, 0
	  bl        -0x11D708
	  mr        r3, r28
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  lwz       r28, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}
