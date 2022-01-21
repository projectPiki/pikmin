#include "types.h"

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
 * Address:	8007B564
 * Size:	0000C8
 */
RadarInfo::RadarInfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r26, 0x10(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0x738C
	  lis       r3, 0x8022
	  addi      r28, r3, 0x737C
	  lis       r3, 0x802B
	  subi      r30, r3, 0x33DC
	  li        r29, 0
	  addi      r3, r26, 0
	  stw       r27, 0x0(r26)
	  mr        r4, r30
	  stw       r28, 0x0(r26)
	  stw       r29, 0x10(r26)
	  stw       r29, 0xC(r26)
	  stw       r29, 0x8(r26)
	  bl        -0x566DC
	  lis       r3, 0x802B
	  subi      r31, r3, 0x3398
	  stw       r31, 0x0(r26)
	  mr        r4, r30
	  addi      r3, r26, 0x18
	  stw       r29, 0x14(r26)
	  stw       r27, 0x18(r26)
	  stw       r28, 0x18(r26)
	  stw       r29, 0x28(r26)
	  stw       r29, 0x24(r26)
	  stw       r29, 0x20(r26)
	  bl        -0x5670C
	  stw       r31, 0x18(r26)
	  subi      r4, r13, 0x6430
	  subi      r0, r13, 0x6428
	  stw       r29, 0x2C(r26)
	  mr        r3, r26
	  stw       r29, 0x10(r26)
	  stw       r29, 0xC(r26)
	  stw       r29, 0x8(r26)
	  stw       r4, 0x4(r26)
	  stw       r29, 0x28(r26)
	  stw       r29, 0x24(r26)
	  stw       r29, 0x20(r26)
	  stw       r0, 0x1C(r26)
	  lwz       r0, 0x2C(r1)
	  lmw       r26, 0x10(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B62C
 * Size:	0000E8
 */
void RadarInfo::attachParts(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r4
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x10(r3)
	  b         .loc_0x3C

	.loc_0x2C:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r29
	  beq-      .loc_0xC8
	  lwz       r3, 0xC(r3)

	.loc_0x3C:
	  cmplwi    r3, 0
	  bne+      .loc_0x2C
	  lwz       r0, 0x28(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  mr        r30, r0
	  addi      r3, r30, 0
	  bl        -0x3B074
	  b         .loc_0xB8

	.loc_0x60:
	  li        r3, 0x18
	  bl        -0x3468C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB8
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r30)
	  li        r31, 0
	  lis       r4, 0x802B
	  stw       r31, 0x10(r30)
	  subi      r4, r4, 0x33DC
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0x567FC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3398
	  stw       r0, 0x0(r30)
	  stw       r31, 0x14(r30)

	.loc_0xB8:
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x3B114
	  stw       r29, 0x14(r30)

	.loc_0xC8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B714
 * Size:	000070
 */
void RadarInfo::detachParts(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r31, 0x10(r3)
	  b         .loc_0x50

	.loc_0x20:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r4
	  bne-      .loc_0x4C
	  mr        r3, r31
	  bl        -0x3B134
	  addi      r3, r30, 0x18
	  addi      r4, r31, 0
	  bl        -0x3B178
	  li        r0, 0
	  stw       r0, 0x14(r31)
	  b         .loc_0x58

	.loc_0x4C:
	  lwz       r31, 0xC(r31)

	.loc_0x50:
	  cmplwi    r31, 0
	  bne+      .loc_0x20

	.loc_0x58:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B784
 * Size:	000044
 */
void RadarInfo::PartsInfo::getPos()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x14(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x28
	  lfsu      f0, 0x94(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x8(r3)
	  blr

	.loc_0x28:
	  lfs       f1, -0x641C(r13)
	  lfs       f2, -0x6418(r13)
	  lfs       f0, -0x6420(r13)
	  stfs      f0, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f2, 0x8(r3)
	  blr
	*/
}
