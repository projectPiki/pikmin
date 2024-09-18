#include "PaniAnimator.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B148
 * Size:	000148
 */
PaniMotionTable* PaniPlantAnimator::createMotionTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x8
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  bl        -0xD415C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x30
	  li        r4, 0x7
	  bl        0x3E94

	.loc_0x30:
	  li        r3, 0x8
	  bl        -0xD4178
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4C
	  li        r4, 0
	  bl        0x3E38

	.loc_0x4C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x0(r4)
	  bl        -0xD419C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x70
	  li        r4, 0x1
	  bl        0x3E14

	.loc_0x70:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x4(r4)
	  bl        -0xD41C0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x94
	  li        r4, 0x2
	  bl        0x3DF0

	.loc_0x94:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x8(r4)
	  bl        -0xD41E4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB8
	  li        r4, 0x3
	  bl        0x3DCC

	.loc_0xB8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xC(r4)
	  bl        -0xD4208
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xDC
	  li        r4, 0x4
	  bl        0x3DA8

	.loc_0xDC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x10(r4)
	  bl        -0xD422C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x100
	  li        r4, 0x5
	  bl        0x3D84

	.loc_0x100:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x14(r4)
	  bl        -0xD4250
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x124
	  li        r4, 0x6
	  bl        0x3D60

	.loc_0x124:
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  stw       r30, 0x18(r4)
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
 * Address:	8011B290
 * Size:	00003C
 */
PaniPlantAnimator::PaniPlantAnimator()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x3E3C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x4068
	  stw       r0, 0x30(r31)
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
