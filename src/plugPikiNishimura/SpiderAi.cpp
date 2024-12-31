#include "Spider.h"
#include "DebugLog.h"

static u32 spiderSE[] = { 0x29, 0x2A, 0x2B, 0x2C, 0x2D };

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("SpiderAi");

/*
 * --INFO--
 * Address:	80153840
 * Size:	000020
 */
SpiderAi::SpiderAi(Spider* spider) { mSpider = spider; }

/*
 * --INFO--
 * Address:	80153860
 * Size:	0000A8
 */
void SpiderAi::initAI(Spider*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x7
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  addi      r5, r31, 0
	  stw       r4, 0x4(r3)
	  li        r4, 0x3
	  lwz       r6, 0x4(r3)
	  addi      r3, r1, 0x34
	  stw       r0, 0x2E4(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2E8(r6)
	  bl        -0x3490C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x346E8
	  li        r4, 0
	  stb       r4, 0x8(r31)
	  lwz       r5, 0x4(r31)
	  lwz       r3, 0x224(r5)
	  lwz       r0, 0x540(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x70
	  stb       r4, 0x3C8(r5)
	  b         .loc_0x94

	.loc_0x70:
	  li        r0, 0x1
	  stb       r0, 0x3C8(r5)
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x460(r3)
	  stfs      f0, 0x2D8(r4)
	  lfs       f0, -0x56E0(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x368(r3)

	.loc_0x94:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80153908
 * Size:	00007C
 */
void SpiderAi::animationKeyUpdated(PaniAnimKeyEvent&)
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
	  bl        0xD8
	  b         .loc_0x6C

	.loc_0x54:
	  bl        0xF0
	  b         .loc_0x6C

	.loc_0x5C:
	  bl        0xFC
	  b         .loc_0x6C

	.loc_0x64:
	  lwz       r4, 0x4(r4)
	  bl        0x100

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
 * Address:	80153984
 * Size:	0000A8
 */
void SpiderAi::keyAction0()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r4, 0x4(r3)
	  lwz       r0, 0x2E4(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x64
	  li        r0, 0
	  stb       r0, 0x2B8(r4)
	  lis       r3, 0x7461
	  addi      r4, r3, 0x6D61
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x220(r3)
	  bl        -0xCA2B0
	  lfs       f0, -0x56DC(r2)
	  addi      r4, r3, 0x4
	  lwz       r6, 0x58(r3)
	  li        r5, 0x1
	  stfs      f0, 0x40(r6)
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x56D8(r2)
	  bl        -0x58D0
	  b         .loc_0x94

	.loc_0x64:
	  cmpwi     r0, 0x8
	  bne-      .loc_0x94
	  lwz       r3, 0x3178(r13)
	  addi      r6, r4, 0x94
	  li        r4, 0x5
	  li        r5, 0
	  bl        0x293D4
	  lwz       r5, 0x4(r31)
	  li        r4, 0x2
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x2FA3C

	.loc_0x94:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80153A2C
 * Size:	000020
 */
void SpiderAi::keyAction1()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x8
	  bnelr-
	  lwz       r3, 0x3C4(r3)
	  li        r0, 0
	  stb       r0, 0x5(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SpiderAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SpiderAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80153A4C
 * Size:	000014
 */
void SpiderAi::keyLoopEnd()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x4(r3)
	  lwz       r3, 0x2EC(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2EC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80153A60
 * Size:	000010
 */
void SpiderAi::keyFinished()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  li        r0, 0x1
	  stb       r0, 0x2BD(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80153A70
 * Size:	000044
 */
void SpiderAi::playSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lis       r5, 0x802D
	  rlwinm    r4,r4,2,0,29
	  subi      r0, r5, 0xB68
	  add       r4, r0, r4
	  lwz       r4, 0x0(r4)
	  bl        -0xAFCD0

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void SpiderAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void SpiderAi::checkFlickPiki()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void SpiderAi::checkHalfDead()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SpiderAi::resultFlagOn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void SpiderAi::resultFlagSeen()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void SpiderAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::outSideChaseRangeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::inSideWaitRangeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::chaseNaviTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::chasePikiTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void SpiderAi::shakeOffTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::targetLostTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80153AB4
 * Size:	0002FC
 */
void SpiderAi::appearTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stmw      r26, 0xA0(r1)
	  mr        r28, r3
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x3C8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2A0
	  lwz       r31, 0x3120(r13)
	  addi      r29, r3, 0x300
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x244

	.loc_0x48:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x84

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x228
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x228
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x228
	  lfs       f1, 0x0(r29)
	  lfs       f2, 0x8(r29)
	  lfs       f3, 0x94(r26)
	  lfs       f4, 0x9C(r26)
	  bl        -0x11B574
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x450(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x228
	  li        r0, 0x1
	  stb       r0, 0x3C8(r4)
	  lwz       r3, 0x4(r28)
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x30AC(r13)
	  lwz       r27, 0x64(r3)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x1C8

	.loc_0x134:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x158
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x170

	.loc_0x158:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x170:
	  cmplwi    r3, 0
	  beq-      .loc_0x1AC
	  lfs       f1, 0x0(r29)
	  lfs       f2, 0x8(r29)
	  lfs       f3, 0x94(r3)
	  lfs       f4, 0x9C(r3)
	  bl        -0x11B614
	  lwz       r3, 0x4(r28)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x450(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1AC
	  lfs       f0, -0x56D0(r2)
	  stfs      f0, 0x460(r3)
	  b         .loc_0x2A0

	.loc_0x1AC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x1C8:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F0
	  li        r0, 0x1
	  b         .loc_0x21C

	.loc_0x1F0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x218
	  li        r0, 0x1
	  b         .loc_0x21C

	.loc_0x218:
	  li        r0, 0

	.loc_0x21C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x134
	  b         .loc_0x2A0

	.loc_0x228:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x244:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x26C
	  li        r0, 0x1
	  b         .loc_0x298

	.loc_0x26C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x294
	  li        r0, 0x1
	  b         .loc_0x298

	.loc_0x294:
	  li        r0, 0

	.loc_0x298:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x48

	.loc_0x2A0:
	  lwz       r4, 0x4(r28)
	  lbz       r0, 0x3C8(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x2E4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D8(r4)
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x460(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2E4
	  li        r3, 0x1
	  b         .loc_0x2E8

	.loc_0x2E4:
	  li        r3, 0

	.loc_0x2E8:
	  lmw       r26, 0xA0(r1)
	  lwz       r0, 0xBC(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SpiderAi::initDie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void SpiderAi::initWalk(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void SpiderAi::initShakeOff(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void SpiderAi::initAppear(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void SpiderAi::initWait(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80153DB0
 * Size:	000260
 */
void SpiderAi::dieState()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r1, 0x78
	  stw       r30, 0x98(r1)
	  mr        r30, r3
	  stw       r29, 0x94(r1)
	  lwz       r3, 0x4(r3)
	  lfs       f1, -0x56DC(r2)
	  lwz       r4, 0x224(r3)
	  lfs       f31, 0x2D4(r3)
	  lfs       f0, 0x490(r4)
	  lfs       f2, 0x480(r4)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x78(r1)
	  lwz       r3, 0x4(r30)
	  lfs       f3, -0x56CC(r2)
	  lwz       r3, 0x224(r3)
	  lfs       f2, -0x56A8(r2)
	  lfs       f0, 0x490(r3)
	  lfs       f4, 0x480(r3)
	  fmuls     f0, f3, f0
	  lfs       f1, -0x56A4(r2)
	  fadds     f0, f4, f0
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x490(r3)
	  lfs       f3, 0x480(r3)
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x80(r1)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x490(r3)
	  lfs       f2, 0x480(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x84(r1)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x108
	  bl        0xC420C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x56C0(r2)
	  stw       r0, 0x8C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x56C8(r2)
	  stw       r0, 0x88(r1)
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x88(r1)
	  lfs       f1, -0x56C4(r2)
	  fsubs     f4, f0, f4
	  lfs       f0, -0x56A0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x108
	  lwz       r3, 0x4(r30)
	  li        r4, 0x1
	  lwz       r3, 0x3C4(r3)
	  bl        0x219C

	.loc_0x108:
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x470(r3)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x13C
	  lbz       r0, 0x3BB(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x13C
	  lwz       r3, 0x3C4(r4)
	  bl        0x20B4
	  lwz       r3, 0x4(r30)
	  li        r0, 0
	  stb       r0, 0x3BB(r3)

	.loc_0x13C:
	  lfs       f0, 0x78(r1)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1A0
	  lwz       r3, 0x4(r30)
	  lbz       r0, 0x3B9(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x174
	  lwz       r3, 0x3C4(r3)
	  bl        0x24C8
	  lwz       r3, 0x4(r30)
	  li        r0, 0
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r30)
	  stb       r0, 0x2B9(r3)

	.loc_0x174:
	  lwz       r4, 0x4(r30)
	  lfs       f1, 0x84(r1)
	  lwz       r3, 0x224(r4)
	  lfs       f2, -0x569C(r2)
	  lfs       f0, 0x4A0(r3)
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1A0
	  li        r0, 0
	  stb       r0, 0x2BD(r4)

	.loc_0x1A0:
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x224(r3)
	  lwz       r0, 0x550(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x228
	  li        r29, 0

	.loc_0x1B8:
	  lfs       f0, 0x0(r31)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1D4
	  lwz       r3, 0x4(r30)
	  mr        r4, r29
	  lwz       r3, 0x3C4(r3)
	  bl        0x2938

	.loc_0x1D4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r31, r31, 0x4
	  blt+      .loc_0x1B8
	  lwz       r3, 0x4(r30)
	  lfs       f1, 0x84(r1)
	  lwz       r3, 0x224(r3)
	  lfs       f2, -0x5698(r2)
	  lfs       f0, 0x4A0(r3)
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x228
	  lwz       r3, 0x30F8(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x30F8(r13)
	  lwz       r3, 0x4(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl

	.loc_0x228:
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r4)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void SpiderAi::walkRandomState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void SpiderAi::walkGoHomeState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::chaseNaviState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::chasePikiState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::shakeOffState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void SpiderAi::waitState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void SpiderAi::appearState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80154010
 * Size:	0019F8
 */
void SpiderAi::update()
{
	setEveryFrame();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x6E8(r1)
	  stw       r31, 0x6E4(r1)
	  mr        r31, r3
	  stw       r30, 0x6E0(r1)
	  lwz       r3, 0x4(r3)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x30
	  bl        -0x5AF4

	.loc_0x30:
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x58
	  bl        -0x50CC
	  stb       r3, 0x8(r31)

	.loc_0x58:
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x2EC(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2EC(r4)

	.loc_0x74:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56D4(r2)
	  lfs       f2, 0x2C8(r3)
	  lfs       f1, 0x2C4(r3)
	  fmuls     f0, f0, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB4
	  lbzu      r0, 0x3BA(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xBC
	  li        r0, 0x1
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1CAC
	  b         .loc_0xBC

	.loc_0xB4:
	  li        r0, 0
	  stb       r0, 0x3BA(r3)

	.loc_0xBC:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmplwi    r0, 0x8
	  bgt-      .loc_0x19E0
	  lis       r4, 0x802D
	  subi      r4, r4, 0xB38
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  mr        r3, r31
	  bl        -0x348
	  b         .loc_0x19E0
	  lfs       f1, -0x56B4(r2)
	  bl        -0x5B3C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x17C
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x6B8
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x351C0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x34F9C
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD0734
	  b         .loc_0x19E0

	.loc_0x17C:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x19C
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  li        r4, 0x1

	.loc_0x19C:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x240
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC3EA0
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6DC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6D8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6D8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x2C08
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x4E70
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD0848
	  b         .loc_0x19E0

	.loc_0x240:
	  cmplwi    r5, 0
	  beq-      .loc_0x330
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x270
	  b         .loc_0x274

	.loc_0x270:
	  neg       r30, r30

	.loc_0x274:
	  bl        0xC3DEC
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6D4(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6D0(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6D0(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6DC(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D8(r1)
	  addi      r3, r1, 0x6B0
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D8(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6C8(r1)
	  lwz       r6, 0x6CC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x3539C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x35178
	  b         .loc_0x19E0

	.loc_0x330:
	  bl        -0x5C34
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x424
	  lwz       r3, 0x4(r31)
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x388
	  b         .loc_0x38C

	.loc_0x388:
	  neg       r30, r30

	.loc_0x38C:
	  bl        0xC3CD4
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x2A08
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0x424:
	  lwz       r3, 0x4(r31)
	  bl        -0x5A5C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x480
	  b         .loc_0x484

	.loc_0x480:
	  neg       r30, r30

	.loc_0x484:
	  bl        0xC3BDC
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x2910
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  bl        -0x5F94
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x5A4
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x6A8
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x355E8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x353C4
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD0B5C
	  b         .loc_0x19E0

	.loc_0x5A4:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x5C4
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C4
	  li        r4, 0x1

	.loc_0x5C4:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x668
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC3A78
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x27E0
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x5298
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD0C70
	  b         .loc_0x19E0

	.loc_0x668:
	  cmplwi    r5, 0
	  beq-      .loc_0x758
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x698
	  b         .loc_0x69C

	.loc_0x698:
	  neg       r30, r30

	.loc_0x69C:
	  bl        0xC39C4
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6C8(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6D4(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D0(r1)
	  addi      r3, r1, 0x6A0
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r6, 0x6DC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x357C4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x355A0
	  b         .loc_0x19E0

	.loc_0x758:
	  bl        -0x58F8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84C
	  lwz       r3, 0x4(r31)
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x7B0
	  b         .loc_0x7B4

	.loc_0x7B0:
	  neg       r30, r30

	.loc_0x7B4:
	  bl        0xC38AC
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x25E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0x84C:
	  lwz       r3, 0x4(r31)
	  bl        -0x5BA8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x944
	  lwz       r3, 0x4(r31)
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x8A8
	  b         .loc_0x8AC

	.loc_0x8A8:
	  neg       r30, r30

	.loc_0x8AC:
	  bl        0xC37B4
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x24E8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0x944:
	  lwz       r3, 0x4(r31)
	  bl        -0x5F7C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x9A0
	  b         .loc_0x9A4

	.loc_0x9A0:
	  neg       r30, r30

	.loc_0x9A4:
	  bl        0xC36BC
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x23F0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  bl        -0x64B4
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xAC4
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x698
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x35B08
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x358E4
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD107C
	  b         .loc_0x19E0

	.loc_0xAC4:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0xAE4
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xAE4
	  li        r4, 0x1

	.loc_0xAE4:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xB88
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC3558
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x22C0
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x57B8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD1190
	  b         .loc_0x19E0

	.loc_0xB88:
	  cmplwi    r5, 0
	  beq-      .loc_0xC78
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xBB8
	  b         .loc_0xBBC

	.loc_0xBB8:
	  neg       r30, r30

	.loc_0xBBC:
	  bl        0xC34A4
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6C8(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6D4(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D0(r1)
	  addi      r3, r1, 0x690
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r6, 0x6DC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x35CE4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x35AC0
	  b         .loc_0x19E0

	.loc_0xC78:
	  bl        -0x5E18
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD6C
	  lwz       r3, 0x4(r31)
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xCD0
	  b         .loc_0xCD4

	.loc_0xCD0:
	  neg       r30, r30

	.loc_0xCD4:
	  bl        0xC338C
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x20C0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0xD6C:
	  lwz       r3, 0x4(r31)
	  bl        -0x60C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE64
	  lwz       r3, 0x4(r31)
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xDC8
	  b         .loc_0xDCC

	.loc_0xDC8:
	  neg       r30, r30

	.loc_0xDCC:
	  bl        0xC3294
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1FC8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0xE64:
	  lwz       r3, 0x4(r31)
	  bl        -0x676C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF5C
	  lwz       r3, 0x4(r31)
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xEC0
	  b         .loc_0xEC4

	.loc_0xEC0:
	  neg       r30, r30

	.loc_0xEC4:
	  bl        0xC319C
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1ED0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0xF5C:
	  lwz       r3, 0x4(r31)
	  bl        -0x6594
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xFB8
	  b         .loc_0xFBC

	.loc_0xFB8:
	  neg       r30, r30

	.loc_0xFBC:
	  bl        0xC30A4
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1DD8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  lwz       r4, 0x300(r3)
	  lwz       r0, 0x304(r3)
	  stw       r4, 0x30C(r3)
	  stw       r0, 0x310(r3)
	  lwz       r0, 0x308(r3)
	  stw       r0, 0x314(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x10F0
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x688
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36134
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x35F10
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD16A8
	  b         .loc_0x19E0

	.loc_0x10F0:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x1110
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1110
	  li        r4, 0x1

	.loc_0x1110:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x11B4
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC2F2C
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x1C94
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x5DE4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD17BC
	  b         .loc_0x19E0

	.loc_0x11B4:
	  cmplwi    r5, 0
	  beq-      .loc_0x12A4
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x11E4
	  b         .loc_0x11E8

	.loc_0x11E4:
	  neg       r30, r30

	.loc_0x11E8:
	  bl        0xC2E78
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6C8(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6D4(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D0(r1)
	  addi      r3, r1, 0x680
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r6, 0x6DC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36310
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x360EC
	  b         .loc_0x19E0

	.loc_0x12A4:
	  bl        -0x64A4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x12FC
	  b         .loc_0x1300

	.loc_0x12FC:
	  neg       r30, r30

	.loc_0x1300:
	  bl        0xC2D60
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1A94
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  bl        -0x6E10
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x56DC(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x142C
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x678
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36470
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3624C
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD19E4
	  b         .loc_0x19E0

	.loc_0x142C:
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x1474
	  b         .loc_0x1478

	.loc_0x1474:
	  neg       r30, r30

	.loc_0x1478:
	  bl        0xC2BE8
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x191C
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  mr        r3, r31
	  bl        -0x1A70
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x8
	  li        r4, 0
	  stw       r0, 0x2E8(r3)
	  li        r0, 0x1
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x2BC(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x56B4(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)
	  bl        0xC2B00
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f1, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f4, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f3, -0x56CC(r2)
	  fsubs     f5, f0, f1
	  lfs       f1, -0x56B0(r2)
	  lfs       f0, -0x56AC(r2)
	  lfs       f2, 0x8C(r3)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fmuls     f1, f1, f3
	  fsubs     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x8C(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0x8C(r3)
	  stfs      f0, 0xA0(r3)
	  b         .loc_0x19E0
	  lbz       r0, 0x3C9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x160C
	  lwz       r3, 0x220(r3)
	  bl        -0xCBED8
	  lwz       r4, 0x4(r31)
	  lfs       f1, -0x5694(r2)
	  lfs       f0, 0x98(r4)
	  lfs       f2, 0x8(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x160C
	  li        r0, 0x1
	  stb       r0, 0x3C9(r4)
	  lwz       r3, 0x2F00(r13)
	  lwz       r4, 0x4(r31)
	  addi      r3, r3, 0x114
	  addi      r4, r4, 0x3CC
	  bl        -0x115040

	.loc_0x160C:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1690
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x670
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x366D4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x364B0
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD1C48
	  b         .loc_0x19E0

	.loc_0x1690:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x16E4
	  b         .loc_0x16E8

	.loc_0x16E4:
	  neg       r30, r30

	.loc_0x16E8:
	  bl        0xC2978
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x16AC
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  lwz       r4, 0x2EC(r3)
	  lwz       r0, 0x3BC(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x17B0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x668
	  li        r4, -0x1
	  bl        -0x36820
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3658C

	.loc_0x17B0:
	  lwz       r4, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r4)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1834
	  li        r0, 0
	  stw       r0, 0x2E8(r4)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x660
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36878
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x36654
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD1DEC
	  b         .loc_0x19E0

	.loc_0x1834:
	  lbz       r5, 0x2BD(r4)
	  li        r3, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x1854
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1854
	  li        r3, 0x1

	.loc_0x1854:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x18F8
	  li        r0, 0x5
	  stw       r0, 0x2E8(r4)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC27E8
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x1550
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x6528
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD1F00
	  b         .loc_0x19E0

	.loc_0x18F8:
	  cmplwi    r5, 0
	  beq-      .loc_0x19E0
	  li        r0, 0x1
	  stw       r0, 0x2E8(r4)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x1948
	  b         .loc_0x194C

	.loc_0x1948:
	  neg       r30, r30

	.loc_0x194C:
	  bl        0xC2714
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1448
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)

	.loc_0x19E0:
	  lwz       r0, 0x6EC(r1)
	  lwz       r31, 0x6E4(r1)
	  lwz       r30, 0x6E0(r1)
	  addi      r1, r1, 0x6E8
	  mtlr      r0
	  blr
	*/
}
