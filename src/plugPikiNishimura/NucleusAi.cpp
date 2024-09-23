#include "Nucleus.h"

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
 * Address:	8017A544
 * Size:	000020
 */
NucleusAi::NucleusAi(Nucleus*)
{
	/*
	.loc_0x0:
	  lis       r5, 0x802B
	  subi      r0, r5, 0x246C
	  lis       r5, 0x802D
	  stw       r0, 0x0(r3)
	  addi      r0, r5, 0x1314
	  stw       r0, 0x0(r3)
	  stw       r4, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A564
 * Size:	000074
 */
void NucleusAi::initAI(Nucleus*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  addi      r5, r31, 0
	  stw       r4, 0x8(r3)
	  li        r4, 0x2
	  lwz       r6, 0x8(r3)
	  addi      r3, r1, 0x1C
	  stw       r0, 0x2E4(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2E8(r6)
	  bl        -0x5B610
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B3EC
	  lfs       f0, -0x51A0(r2)
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  stfs      f0, 0x2D8(r3)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A5D8
 * Size:	00007C
 */
void NucleusAi::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4C
	  bge-      .loc_0x2C
	  cmpwi     r0, 0
	  beq-      .loc_0x5C
	  bge-      .loc_0x44
	  b         .loc_0x6C

	.loc_0x2C:
	  cmpwi     r0, 0x7
	  beq-      .loc_0x64
	  bge-      .loc_0x6C
	  cmpwi     r0, 0x6
	  bge-      .loc_0x54
	  b         .loc_0x6C

	.loc_0x44:
	  bl        .loc_0x7C
	  b         .loc_0x6C

	.loc_0x4C:
	  bl        0x34
	  b         .loc_0x6C

	.loc_0x54:
	  bl        0x30
	  b         .loc_0x6C

	.loc_0x5C:
	  bl        0x3C
	  b         .loc_0x6C

	.loc_0x64:
	  lwz       r4, 0x4(r4)
	  bl        0x40

	.loc_0x6C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x7C:
	*/
}

/*
 * --INFO--
 * Address:	8017A654
 * Size:	000004
 */
void NucleusAi::keyAction0() { }

/*
 * --INFO--
 * Address:	8017A658
 * Size:	000004
 */
void NucleusAi::keyAction1() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017A65C
 * Size:	000014
 */
void NucleusAi::keyLoopEnd()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x8(r3)
	  lwz       r3, 0x2EC(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2EC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A670
 * Size:	000010
 */
void NucleusAi::keyFinished()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x8(r3)
	  li        r0, 0x1
	  stb       r0, 0x2BD(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A680
 * Size:	000004
 */
void NucleusAi::playSound(int) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NucleusAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::setBossPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NucleusAi::setSlimeDamagePoint()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NucleusAi::afterProcessing()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void NucleusAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::damageTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void NucleusAi::initDie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initDamage(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initFollow(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::dieState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::damageState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::followState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017A684
 * Size:	0002D0
 */
void NucleusAi::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  bl        -0x2B650
	  stw       r3, 0x4(r31)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x3B8(r4)
	  lfs       f0, 0x3DC(r3)
	  stfs      f0, 0x94(r4)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x3B8(r4)
	  lfs       f0, 0x3E4(r3)
	  stfs      f0, 0x9C(r4)
	  lwz       r3, 0x8(r31)
	  lfs       f1, 0x2C0(r3)
	  lwz       r3, 0x3B8(r3)
	  lwz       r3, 0x400(r3)
	  bl        -0x15AA4
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x78
	  bge-      .loc_0x6C
	  b         .loc_0x2B0

	.loc_0x6C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x2B0
	  b         .loc_0x18C

	.loc_0x78:
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x519C(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x140
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x84
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B7AC
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B588
	  lfs       f0, -0x519C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x223C8
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x223AC
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x22390
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2B0

	.loc_0x140:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B0
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0x7C
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B86C
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B648
	  b         .loc_0x2B0

	.loc_0x18C:
	  lfs       f0, 0x2C4(r3)
	  lfs       f1, -0x519C(r2)
	  fcmpo     cr0, f0, f1
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x254
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x74
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B8C0
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B69C
	  lfs       f0, -0x519C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x222B4
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x22298
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2227C
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2B0

	.loc_0x254:
	  lfs       f0, 0x2C0(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x268:
	  li        r0, 0

	.loc_0x26C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2B0
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0x6C
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B994
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B770

	.loc_0x2B0:
	  lfs       f0, -0x519C(r2)
	  lwz       r3, 0x8(r31)
	  stfs      f0, 0x2C0(r3)
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}
