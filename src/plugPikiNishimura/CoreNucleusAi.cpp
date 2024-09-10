#include "types.h"

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
 * Address:	8017AD44
 * Size:	000020
 */
CoreNucleusAi::CoreNucleusAi(CoreNucleus*)
{
	/*
	.loc_0x0:
	  lis       r5, 0x802B
	  subi      r0, r5, 0x246C
	  lis       r5, 0x802D
	  stw       r0, 0x0(r3)
	  addi      r0, r5, 0x15DC
	  stw       r0, 0x0(r3)
	  stw       r4, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017AD64
 * Size:	000074
 */
void CoreNucleusAi::initAI(CoreNucleus*)
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
	  bl        -0x5BE10
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5BBEC
	  lfs       f0, -0x5180(r2)
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  stfs      f0, 0x2D8(r3)
	  stb       r0, 0x4(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017ADD8
 * Size:	00007C
 */
void CoreNucleusAi::animationKeyUpdated(PaniAnimKeyEvent&)
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
 * Address:	8017AE54
 * Size:	000004
 */
void CoreNucleusAi::keyAction0() { }

/*
 * --INFO--
 * Address:	8017AE58
 * Size:	000004
 */
void CoreNucleusAi::keyAction1() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017AE5C
 * Size:	000014
 */
void CoreNucleusAi::keyLoopEnd()
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
 * Address:	8017AE70
 * Size:	000010
 */
void CoreNucleusAi::keyFinished()
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
 * Address:	8017AE80
 * Size:	000004
 */
void CoreNucleusAi::playSound(int) { }

/*
 * --INFO--
 * Address:	8017AE84
 * Size:	00000C
 */
void CoreNucleusAi::setHitMotionStart()
{
	// Generated from stb r0, 0x4(r3)
	_04 = 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void CoreNucleusAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CoreNucleusAi::setBossPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void CoreNucleusAi::setSlimeDamagePoint()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void CoreNucleusAi::afterProcessing()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CoreNucleusAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void CoreNucleusAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CoreNucleusAi::damageTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void CoreNucleusAi::hitMotionStartTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void CoreNucleusAi::initDie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void CoreNucleusAi::initDamage(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void CoreNucleusAi::initFollow(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void CoreNucleusAi::initHit(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::dieState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::damageState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::followState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::hitState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017AE90
 * Size:	000544
 */
void CoreNucleusAi::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stw       r31, 0x104(r1)
	  mr        r31, r3
	  stw       r30, 0x100(r1)
	  lwz       r4, 0x8(r3)
	  lwz       r3, 0x3BC(r4)
	  lfs       f0, 0x3E8(r3)
	  stfs      f0, 0x94(r4)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x3BC(r4)
	  lfs       f0, 0x3F0(r3)
	  stfs      f0, 0x9C(r4)
	  lwz       r3, 0x8(r31)
	  lfs       f1, 0x2C0(r3)
	  lwz       r3, 0x3BC(r3)
	  lwz       r3, 0x400(r3)
	  bl        -0x162AC
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x23C
	  bge-      .loc_0x74
	  cmpwi     r0, 0
	  beq-      .loc_0x51C
	  bge-      .loc_0x80
	  b         .loc_0x51C

	.loc_0x74:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x51C
	  b         .loc_0x410

	.loc_0x80:
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x517C(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x148
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xF4
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5BFC0
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5BD9C
	  lfs       f0, -0x517C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x21BB4
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x21B98
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x21B7C
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x51C

	.loc_0x148:
	  lbz       r0, 0x4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F4
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0xEC
	  li        r4, 0xA
	  stb       r0, 0x2BD(r6)
	  bl        -0x5C078
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5BE54
	  lwz       r3, 0x8(r31)
	  lfs       f1, 0xA0(r3)
	  bl        0xA0B34
	  lwz       r3, 0x8(r31)
	  fmr       f31, f1
	  lfs       f1, 0xA0(r3)
	  bl        0xA0CB8
	  stfs      f1, 0xE0(r1)
	  li        r4, 0x59
	  lfs       f0, 0x7D8(r13)
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0xE4(r1)
	  li        r7, 0
	  stfs      f31, 0xE8(r1)
	  lwz       r5, 0x8(r31)
	  addi      r5, r5, 0x94
	  bl        0x21ADC
	  cmplwi    r3, 0
	  beq-      .loc_0x51C
	  lwz       r4, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0xE8(r1)
	  stw       r0, 0xA8(r3)
	  b         .loc_0x51C

	.loc_0x1F4:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x51C
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0xD8
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x5C124
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5BF00
	  stb       r30, 0x4(r31)
	  b         .loc_0x51C

	.loc_0x23C:
	  lfs       f0, 0x2C4(r3)
	  lfs       f1, -0x517C(r2)
	  fcmpo     cr0, f0, f1
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x304
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xD0
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5C17C
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5BF58
	  lfs       f0, -0x517C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x219F8
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x219DC
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x219C0
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x51C

	.loc_0x304:
	  lbz       r0, 0x4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3B0
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0xC8
	  li        r4, 0xA
	  stb       r0, 0x2BD(r6)
	  bl        -0x5C234
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C010
	  lwz       r3, 0x8(r31)
	  lfs       f1, 0xA0(r3)
	  bl        0xA0978
	  lwz       r3, 0x8(r31)
	  fmr       f31, f1
	  lfs       f1, 0xA0(r3)
	  bl        0xA0AFC
	  stfs      f1, 0xBC(r1)
	  li        r4, 0x59
	  lfs       f0, 0x7D8(r13)
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0xC0(r1)
	  li        r7, 0
	  stfs      f31, 0xC4(r1)
	  lwz       r5, 0x8(r31)
	  addi      r5, r5, 0x94
	  bl        0x21920
	  cmplwi    r3, 0
	  beq-      .loc_0x51C
	  lwz       r4, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0xA8(r3)
	  b         .loc_0x51C

	.loc_0x3B0:
	  lfs       f0, 0x2C0(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x3C4
	  li        r0, 0x1
	  b         .loc_0x3C8

	.loc_0x3C4:
	  li        r0, 0

	.loc_0x3C8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x51C
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0xB4
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5C2FC
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C0D8
	  b         .loc_0x51C

	.loc_0x410:
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x517C(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x4D8
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xAC
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5C350
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C12C
	  lfs       f0, -0x517C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x21824
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x21808
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x217EC
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x51C

	.loc_0x4D8:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x51C
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0xA4
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x5C408
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C1E4
	  stb       r30, 0x4(r31)

	.loc_0x51C:
	  lfs       f0, -0x517C(r2)
	  lwz       r3, 0x8(r31)
	  stfs      f0, 0x2C0(r3)
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lwz       r31, 0x104(r1)
	  lwz       r30, 0x100(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}
