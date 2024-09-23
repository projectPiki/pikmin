#include "Snake.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015B1F0
 * Size:	0000D0
 */
SnakeAi::SnakeAi(Snake*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x246C
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x5A0
	  li        r3, 0x14
	  stw       r0, 0x0(r31)
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0x3C(r31)
	  stfs      f0, 0x38(r31)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x48(r31)
	  stfs      f0, 0x44(r31)
	  stfs      f0, 0x40(r31)
	  stw       r4, 0x4C(r31)
	  bl        -0x11423C
	  stw       r3, 0x18(r31)
	  li        r3, 0x14
	  bl        -0x114248
	  stw       r3, 0x1C(r31)
	  li        r3, 0x14
	  bl        -0x114254
	  stw       r3, 0x20(r31)
	  li        r3, 0x14
	  bl        -0x114260
	  stw       r3, 0x24(r31)
	  li        r3, 0x14
	  bl        -0x11426C
	  stw       r3, 0x28(r31)
	  li        r3, 0x14
	  bl        -0x114278
	  stw       r3, 0x2C(r31)
	  li        r3, 0x44
	  bl        -0x114284
	  lis       r4, 0x8003
	  addi      r4, r4, 0x5B24
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x5
	  bl        0xB9988
	  stw       r3, 0x30(r31)
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B2C0
 * Size:	00009C
 */
void SnakeAi::initAI(Snake*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x8
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  addi      r5, r31, 0
	  stw       r4, 0x4C(r3)
	  li        r4, 0x6
	  lwz       r6, 0x4C(r3)
	  addi      r3, r1, 0x18
	  stw       r0, 0x2E4(r6)
	  lwz       r6, 0x4C(r31)
	  stw       r0, 0x2E8(r6)
	  bl        -0x3C36C
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3C148
	  li        r5, 0x1
	  stb       r5, 0x6(r31)
	  li        r0, 0
	  lis       r3, 0x736C
	  stb       r0, 0x4(r31)
	  addi      r4, r3, 0x6F74
	  stb       r5, 0x5(r31)
	  stw       r0, 0x14(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x220(r3)
	  bl        -0xD1C2C
	  bl        -0xD35B0
	  stw       r3, 0x10(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B35C
 * Size:	00007C
 */
void SnakeAi::animationKeyUpdated(PaniAnimKeyEvent&)
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
	  bl        0x138
	  b         .loc_0x6C

	.loc_0x54:
	  bl        0x1A8
	  b         .loc_0x6C

	.loc_0x5C:
	  bl        0x24C
	  b         .loc_0x6C

	.loc_0x64:
	  lwz       r4, 0x4(r4)
	  bl        0x250

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
 * Address:	8015B3D8
 * Size:	000108
 */
void SnakeAi::keyAction0()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r4, 0x4C(r3)
	  lwz       r0, 0x2E4(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x74
	  lwz       r3, 0x3CC(r4)
	  li        r4, 0x1
	  lfsu      f0, 0xB0(r3)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x1C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x14(r1)
	  lfs       f2, 0x1C(r1)
	  bl        -0xF3524
	  stfs      f1, 0x18(r1)
	  addi      r5, r1, 0x14
	  li        r4, 0x79
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0x416F4
	  b         .loc_0xF4

	.loc_0x74:
	  cmpwi     r0, 0x4
	  bne-      .loc_0x88
	  mr        r3, r31
	  bl        0xB8C
	  b         .loc_0xF4

	.loc_0x88:
	  cmpwi     r0, 0x7
	  bne-      .loc_0xA4
	  mr        r3, r4
	  bl        -0xD3F4
	  lwz       r3, 0x4C(r31)
	  bl        -0xD1160
	  b         .loc_0xF4

	.loc_0xA4:
	  cmpwi     r0, 0x5
	  bne-      .loc_0xB8
	  mr        r3, r31
	  bl        0xE60
	  b         .loc_0xF4

	.loc_0xB8:
	  cmpwi     r0, 0x9
	  bne-      .loc_0xF4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x94
	  li        r4, 0x7E
	  li        r6, 0
	  li        r7, 0
	  bl        0x4168C
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x41670

	.loc_0xF4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B4E0
 * Size:	000078
 */
void SnakeAi::keyAction1()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  lwz       r3, 0x4C(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x68
	  lwz       r3, 0x3CC(r3)
	  li        r4, 0x1
	  lfsu      f0, 0xB0(r3)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x1C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x14(r1)
	  lfs       f2, 0x1C(r1)
	  bl        -0xF3624
	  stfs      f1, 0x18(r1)
	  addi      r5, r1, 0x14
	  li        r4, 0x78
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0x415F4

	.loc_0x68:
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SnakeAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SnakeAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015B558
 * Size:	0000AC
 */
void SnakeAi::keyLoopEnd()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r4, 0x4C(r3)
	  lwz       r3, 0x2EC(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2EC(r4)
	  lwz       r3, 0x4C(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x98
	  lbz       r0, 0x5(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  lis       r3, 0x8022
	  addi      r6, r3, 0x26F0
	  lwz       r5, 0x0(r6)
	  mr        r3, r31
	  lwz       r0, 0x4(r6)
	  li        r4, 0x5
	  stw       r5, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r0, 0x10(r6)
	  stw       r0, 0x2C(r1)
	  bl        0x2924
	  lwz       r0, 0x14(r31)
	  addi      r4, r1, 0x1C
	  addi      r3, r31, 0
	  rlwinm    r0,r0,2,0,29
	  lfsx      f1, r4, r0
	  li        r4, 0x4
	  bl        0x2974

	.loc_0x98:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B604
 * Size:	000010
 */
void SnakeAi::keyFinished()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4C(r3)
	  li        r0, 0x1
	  stb       r0, 0x2BD(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B614
 * Size:	000044
 */
void SnakeAi::playSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4C(r3)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lis       r5, 0x802D
	  rlwinm    r4,r4,2,0,29
	  subi      r0, r5, 0x650
	  add       r4, r0, r4
	  lwz       r4, 0x0(r4)
	  bl        -0xB7874

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
 * Size:	000054
 */
void SnakeAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void SnakeAi::setInitPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SnakeAi::setUnderPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00012C
 */
void SnakeAi::setAppearPosition01()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002A0
 */
void SnakeAi::setAppearPosition02()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015B658
 * Size:	000104
 */
void SnakeAi::traceTargetPosition()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x4(r3)
	  lwz       r3, 0x4C(r3)
	  bl        -0xD0E0
	  lwz       r3, 0x4C(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x78
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x78
	  lwz       r4, 0x3CC(r3)
	  lfs       f1, -0x5590(r2)
	  lfs       f0, 0xC(r4)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x64
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x410(r4)
	  bl        -0xD300
	  stb       r3, 0x4(r31)
	  b         .loc_0xF0

	.loc_0x64:
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x400(r4)
	  bl        -0xD314
	  stb       r3, 0x4(r31)
	  b         .loc_0xF0

	.loc_0x78:
	  cmpwi     r0, 0x4
	  bne-      .loc_0xF0
	  lbz       r0, 0x5(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  lwz       r0, 0x14(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xAC
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x400(r4)
	  bl        -0xD348
	  stb       r3, 0x4(r31)
	  b         .loc_0xF0

	.loc_0xAC:
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD0
	  lwz       r4, 0x224(r3)
	  lfs       f0, -0x5578(r2)
	  lfs       f1, 0x400(r4)
	  fdivs     f1, f1, f0
	  bl        -0xD36C
	  stb       r3, 0x4(r31)
	  b         .loc_0xF0

	.loc_0xD0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0xF0
	  lwz       r4, 0x224(r3)
	  lfs       f0, -0x5574(r2)
	  lfs       f1, 0x400(r4)
	  fdivs     f1, f1, f0
	  bl        -0xD390
	  stb       r3, 0x4(r31)

	.loc_0xF0:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B75C
 * Size:	000888
 */
void SnakeAi::setAttackPosition()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x460(r1)
	  stfd      f31, 0x458(r1)
	  stw       r31, 0x454(r1)
	  mr        r31, r3
	  lwz       r3, 0x4C(r3)
	  lfs       f1, 0x8C(r3)
	  bl        0xC03D8
	  lwz       r3, 0x4C(r31)
	  fmr       f31, f1
	  lfs       f1, 0x8C(r3)
	  bl        0xC055C
	  stfs      f1, 0x34(r31)
	  lfs       f0, -0x6C(r13)
	  stfs      f0, 0x38(r31)
	  stfs      f31, 0x3C(r31)
	  lfs       f3, -0x64(r13)
	  lfs       f0, 0x3C(r31)
	  lfs       f4, -0x60(r13)
	  lfs       f1, 0x38(r31)
	  fmuls     f0, f0, f3
	  lfs       f2, -0x68(r13)
	  fmuls     f1, f1, f4
	  fsubs     f0, f1, f0
	  stfs      f0, 0x40(r31)
	  lfs       f1, 0x3C(r31)
	  lfs       f0, 0x34(r31)
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f4
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44(r31)
	  lfs       f1, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  fmuls     f1, f1, f3
	  fmuls     f0, f0, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48(r31)
	  lfs       f1, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  lfs       f2, 0x3C(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14DBD4
	  lfs       f0, -0x5590(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xEC
	  lfs       f0, 0x34(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x3C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3C(r31)

	.loc_0xEC:
	  lfs       f1, 0x40(r31)
	  lfs       f0, 0x44(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14DC28
	  lfs       f0, -0x5590(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x140
	  lfs       f0, 0x40(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x40(r31)
	  lfs       f0, 0x44(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x44(r31)
	  lfs       f0, 0x48(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x48(r31)

	.loc_0x140:
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r5, 0x224(r4)
	  li        r4, 0x1
	  lfs       f0, 0x270(r5)
	  stfs      f0, 0x0(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x1C(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x280(r5)
	  stfs      f0, 0x0(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x20(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x290(r5)
	  stfs      f0, 0x0(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x24(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x2A0(r5)
	  stfs      f0, 0x0(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x28(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x2B0(r5)
	  stfs      f0, 0x0(r3)
	  lwz       r5, 0x20(r31)
	  lwz       r3, 0x24(r31)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x0(r3)
	  lwz       r5, 0x18(r31)
	  fadds     f1, f1, f0
	  lfs       f3, -0x5570(r2)
	  lwz       r3, 0x1C(r31)
	  lfs       f0, 0x40(r31)
	  fmuls     f7, f1, f3
	  lfs       f5, 0x0(r5)
	  lfs       f4, 0x0(r3)
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f0, f7
	  lfs       f1, 0x44(r31)
	  fadds     f4, f5, f4
	  fmuls     f6, f2, f7
	  stfs      f0, 0x288(r1)
	  fmuls     f8, f4, f3
	  lfs       f0, 0x34(r31)
	  fmuls     f7, f1, f7
	  fmuls     f0, f0, f8
	  stfs      f0, 0x27C(r1)
	  lwz       r3, 0x4C(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x27C(r1)
	  lfs       f2, 0x3C(r31)
	  fadds     f0, f1, f0
	  lfs       f5, 0x8(r3)
	  fmuls     f4, f2, f8
	  lfs       f2, 0x38(r31)
	  lfs       f3, 0x4(r3)
	  fmuls     f1, f2, f8
	  stfs      f0, 0x330(r1)
	  fadds     f2, f5, f4
	  lfs       f0, 0x330(r1)
	  fadds     f1, f3, f1
	  stfs      f0, 0x428(r1)
	  stfs      f1, 0x42C(r1)
	  stfs      f2, 0x430(r1)
	  lfs       f1, 0x428(r1)
	  lfs       f0, 0x288(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x324(r1)
	  lfs       f0, 0x324(r1)
	  stfs      f0, 0x434(r1)
	  lfs       f0, 0x42C(r1)
	  fadds     f0, f0, f7
	  stfs      f0, 0x438(r1)
	  lfs       f0, 0x430(r1)
	  fadds     f0, f0, f6
	  stfs      f0, 0x43C(r1)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x434(r1)
	  lwz       r0, 0x438(r1)
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x43C(r1)
	  stw       r0, 0x8(r5)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r5)
	  lfs       f2, 0x8(r5)
	  bl        -0xF3AFC
	  lwz       r3, 0x30(r31)
	  li        r4, 0x1
	  stfs      f1, 0x4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x2C0(r5)
	  stfs      f0, 0x4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x1C(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x2D0(r5)
	  stfs      f0, 0x4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x20(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x2E0(r5)
	  stfs      f0, 0x4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x24(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x2F0(r5)
	  stfs      f0, 0x4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x28(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x300(r5)
	  stfs      f0, 0x4(r3)
	  lwz       r5, 0x20(r31)
	  lwz       r3, 0x24(r31)
	  lfs       f1, 0x4(r5)
	  lfs       f0, 0x4(r3)
	  lwz       r5, 0x18(r31)
	  fadds     f1, f1, f0
	  lfs       f3, -0x5570(r2)
	  lwz       r3, 0x1C(r31)
	  lfs       f0, 0x40(r31)
	  fmuls     f7, f1, f3
	  lfs       f5, 0x4(r5)
	  lfs       f4, 0x4(r3)
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f0, f7
	  lfs       f1, 0x44(r31)
	  fadds     f4, f5, f4
	  fmuls     f6, f2, f7
	  stfs      f0, 0x278(r1)
	  fmuls     f8, f4, f3
	  lfs       f0, 0x34(r31)
	  fmuls     f7, f1, f7
	  fmuls     f0, f0, f8
	  stfs      f0, 0x26C(r1)
	  lwz       r3, 0x4C(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x26C(r1)
	  lfs       f2, 0x3C(r31)
	  fadds     f0, f1, f0
	  lfs       f5, 0x8(r3)
	  fmuls     f4, f2, f8
	  lfs       f2, 0x38(r31)
	  lfs       f3, 0x4(r3)
	  fmuls     f1, f2, f8
	  stfs      f0, 0x30C(r1)
	  fadds     f2, f5, f4
	  lfs       f0, 0x30C(r1)
	  fadds     f1, f3, f1
	  stfs      f0, 0x3F8(r1)
	  stfs      f1, 0x3FC(r1)
	  stfs      f2, 0x400(r1)
	  lfs       f1, 0x3F8(r1)
	  lfs       f0, 0x278(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x300(r1)
	  lfs       f0, 0x300(r1)
	  stfs      f0, 0x404(r1)
	  lfs       f0, 0x3FC(r1)
	  fadds     f0, f0, f7
	  stfs      f0, 0x408(r1)
	  lfs       f0, 0x400(r1)
	  fadds     f0, f0, f6
	  stfs      f0, 0x40C(r1)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x404(r1)
	  lwz       r0, 0x408(r1)
	  stw       r3, 0xC(r5)
	  stw       r0, 0x10(r5)
	  lwz       r0, 0x40C(r1)
	  stw       r0, 0x14(r5)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0xC(r5)
	  lfs       f2, 0x14(r5)
	  bl        -0xF3C6C
	  lwz       r3, 0x30(r31)
	  li        r4, 0x1
	  stfs      f1, 0x10(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x310(r5)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x1C(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x320(r5)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x20(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x330(r5)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x24(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x340(r5)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x28(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x350(r5)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x20(r31)
	  lwz       r3, 0x24(r31)
	  lfs       f1, 0x8(r5)
	  lfs       f0, 0x8(r3)
	  lwz       r5, 0x18(r31)
	  fadds     f1, f1, f0
	  lfs       f3, -0x5570(r2)
	  lwz       r3, 0x1C(r31)
	  lfs       f0, 0x40(r31)
	  fmuls     f7, f1, f3
	  lfs       f5, 0x8(r5)
	  lfs       f4, 0x8(r3)
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f0, f7
	  lfs       f1, 0x44(r31)
	  fadds     f4, f5, f4
	  fmuls     f6, f2, f7
	  stfs      f0, 0x268(r1)
	  fmuls     f8, f4, f3
	  lfs       f0, 0x34(r31)
	  fmuls     f7, f1, f7
	  fmuls     f0, f0, f8
	  stfs      f0, 0x25C(r1)
	  lwz       r3, 0x4C(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x25C(r1)
	  lfs       f2, 0x3C(r31)
	  fadds     f0, f1, f0
	  lfs       f5, 0x8(r3)
	  fmuls     f4, f2, f8
	  lfs       f2, 0x38(r31)
	  lfs       f3, 0x4(r3)
	  fmuls     f1, f2, f8
	  stfs      f0, 0x2E8(r1)
	  fadds     f2, f5, f4
	  lfs       f0, 0x2E8(r1)
	  fadds     f1, f3, f1
	  stfs      f0, 0x3C8(r1)
	  stfs      f1, 0x3CC(r1)
	  stfs      f2, 0x3D0(r1)
	  lfs       f1, 0x3C8(r1)
	  lfs       f0, 0x268(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2DC(r1)
	  lfs       f0, 0x2DC(r1)
	  stfs      f0, 0x3D4(r1)
	  lfs       f0, 0x3CC(r1)
	  fadds     f0, f0, f7
	  stfs      f0, 0x3D8(r1)
	  lfs       f0, 0x3D0(r1)
	  fadds     f0, f0, f6
	  stfs      f0, 0x3DC(r1)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x3D4(r1)
	  lwz       r0, 0x3D8(r1)
	  stw       r3, 0x18(r5)
	  stw       r0, 0x1C(r5)
	  lwz       r0, 0x3DC(r1)
	  stw       r0, 0x20(r5)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x18(r5)
	  lfs       f2, 0x20(r5)
	  bl        -0xF3DDC
	  lwz       r3, 0x30(r31)
	  li        r4, 0x1
	  stfs      f1, 0x1C(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x360(r5)
	  stfs      f0, 0xC(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x1C(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x370(r5)
	  stfs      f0, 0xC(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x20(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x380(r5)
	  stfs      f0, 0xC(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x24(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x390(r5)
	  stfs      f0, 0xC(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x28(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3A0(r5)
	  stfs      f0, 0xC(r3)
	  lwz       r5, 0x20(r31)
	  lwz       r3, 0x24(r31)
	  lfs       f1, 0xC(r5)
	  lfs       f0, 0xC(r3)
	  lwz       r5, 0x18(r31)
	  fadds     f1, f1, f0
	  lfs       f3, -0x5570(r2)
	  lwz       r3, 0x1C(r31)
	  lfs       f0, 0x40(r31)
	  fmuls     f7, f1, f3
	  lfs       f5, 0xC(r5)
	  lfs       f4, 0xC(r3)
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f0, f7
	  lfs       f1, 0x44(r31)
	  fadds     f4, f5, f4
	  fmuls     f6, f2, f7
	  stfs      f0, 0x258(r1)
	  fmuls     f8, f4, f3
	  lfs       f0, 0x34(r31)
	  fmuls     f7, f1, f7
	  fmuls     f0, f0, f8
	  stfs      f0, 0x24C(r1)
	  lwz       r3, 0x4C(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x24C(r1)
	  lfs       f2, 0x3C(r31)
	  fadds     f0, f1, f0
	  lfs       f5, 0x8(r3)
	  fmuls     f4, f2, f8
	  lfs       f2, 0x38(r31)
	  lfs       f3, 0x4(r3)
	  fmuls     f1, f2, f8
	  stfs      f0, 0x2C4(r1)
	  fadds     f2, f5, f4
	  lfs       f0, 0x2C4(r1)
	  fadds     f1, f3, f1
	  stfs      f0, 0x398(r1)
	  stfs      f1, 0x39C(r1)
	  stfs      f2, 0x3A0(r1)
	  lfs       f1, 0x398(r1)
	  lfs       f0, 0x258(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2B8(r1)
	  lfs       f0, 0x2B8(r1)
	  stfs      f0, 0x3A4(r1)
	  lfs       f0, 0x39C(r1)
	  fadds     f0, f0, f7
	  stfs      f0, 0x3A8(r1)
	  lfs       f0, 0x3A0(r1)
	  fadds     f0, f0, f6
	  stfs      f0, 0x3AC(r1)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x3A4(r1)
	  lwz       r0, 0x3A8(r1)
	  stw       r3, 0x24(r5)
	  stw       r0, 0x28(r5)
	  lwz       r0, 0x3AC(r1)
	  stw       r0, 0x2C(r5)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x24(r5)
	  lfs       f2, 0x2C(r5)
	  bl        -0xF3F4C
	  lwz       r3, 0x30(r31)
	  li        r4, 0x1
	  stfs      f1, 0x28(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3B0(r5)
	  stfs      f0, 0x10(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x1C(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3C0(r5)
	  stfs      f0, 0x10(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x20(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3D0(r5)
	  stfs      f0, 0x10(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x24(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3E0(r5)
	  stfs      f0, 0x10(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x28(r31)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3F0(r5)
	  stfs      f0, 0x10(r3)
	  lwz       r5, 0x20(r31)
	  lwz       r3, 0x24(r31)
	  lfs       f1, 0x10(r5)
	  lfs       f0, 0x10(r3)
	  lwz       r5, 0x18(r31)
	  fadds     f1, f1, f0
	  lfs       f3, -0x5570(r2)
	  lwz       r3, 0x1C(r31)
	  lfs       f0, 0x40(r31)
	  fmuls     f7, f1, f3
	  lfs       f5, 0x10(r5)
	  lfs       f4, 0x10(r3)
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f0, f7
	  lfs       f1, 0x44(r31)
	  fadds     f4, f5, f4
	  fmuls     f6, f2, f7
	  stfs      f0, 0x248(r1)
	  fmuls     f8, f4, f3
	  lfs       f0, 0x34(r31)
	  fmuls     f7, f1, f7
	  fmuls     f0, f0, f8
	  stfs      f0, 0x23C(r1)
	  lwz       r3, 0x4C(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x23C(r1)
	  lfs       f2, 0x3C(r31)
	  fadds     f0, f1, f0
	  lfs       f5, 0x8(r3)
	  fmuls     f4, f2, f8
	  lfs       f2, 0x38(r31)
	  lfs       f3, 0x4(r3)
	  fmuls     f1, f2, f8
	  stfs      f0, 0x2A0(r1)
	  fadds     f2, f5, f4
	  lfs       f0, 0x2A0(r1)
	  fadds     f1, f3, f1
	  stfs      f0, 0x368(r1)
	  stfs      f1, 0x36C(r1)
	  stfs      f2, 0x370(r1)
	  lfs       f1, 0x368(r1)
	  lfs       f0, 0x248(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x294(r1)
	  lfs       f0, 0x294(r1)
	  stfs      f0, 0x374(r1)
	  lfs       f0, 0x36C(r1)
	  fadds     f0, f0, f7
	  stfs      f0, 0x378(r1)
	  lfs       f0, 0x370(r1)
	  fadds     f0, f0, f6
	  stfs      f0, 0x37C(r1)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x374(r1)
	  lwz       r0, 0x378(r1)
	  stw       r3, 0x30(r5)
	  stw       r0, 0x34(r5)
	  lwz       r0, 0x37C(r1)
	  stw       r0, 0x38(r5)
	  lwz       r5, 0x30(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x30(r5)
	  lfs       f2, 0x38(r5)
	  bl        -0xF40BC
	  lwz       r3, 0x30(r31)
	  stfs      f1, 0x34(r3)
	  lwz       r0, 0x464(r1)
	  lfd       f31, 0x458(r1)
	  lwz       r31, 0x454(r1)
	  addi      r1, r1, 0x460
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015BFE4
 * Size:	000130
 */
void SnakeAi::checkAttackTarget()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  addi      r4, r1, 0x2C
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  addi      r5, r1, 0x28
	  lfs       f0, -0x556C(r2)
	  stw       r31, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  lwz       r6, 0x14(r30)
	  bl        0x300
	  lwz       r6, 0x14(r30)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x2C
	  addi      r5, r1, 0x28
	  bl        0x584
	  lwz       r0, 0x2C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  lwz       r3, 0x4C(r30)
	  li        r31, 0
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x84
	  mr        r3, r30
	  bl        .loc_0x130
	  li        r31, 0x1
	  b         .loc_0x94

	.loc_0x84:
	  cmpwi     r0, 0
	  bne-      .loc_0x94
	  mr        r3, r30
	  bl        0x110

	.loc_0x94:
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0xC0
	  mr        r3, r30
	  bl        0x1EBC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC0
	  addi      r3, r30, 0
	  li        r4, 0x5
	  bl        0xA0C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x118

	.loc_0xC0:
	  addi      r5, r30, 0
	  addi      r3, r1, 0x20
	  li        r4, -0x1
	  bl        -0x3D124
	  lwz       r5, 0x4C(r30)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3CE90
	  li        r0, 0
	  stb       r0, 0x5(r30)
	  b         .loc_0x118

	.loc_0xEC:
	  lwz       r4, 0x4C(r30)
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  stw       r31, 0x318(r4)
	  li        r4, -0x1
	  bl        -0x3D158
	  lwz       r5, 0x4C(r30)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3CEC4
	  stb       r31, 0x5(r30)

	.loc_0x118:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x130:
	*/
}

/*
 * --INFO--
 * Address:	8015C114
 * Size:	000070
 */
void SnakeAi::naviNudge()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r6, r5, 0x3064
	  lis       r4, 0x802B
	  stwu      r1, -0x38(r1)
	  subi      r5, r4, 0x31FC
	  li        r0, 0
	  lwz       r8, 0x4C(r3)
	  addi      r4, r1, 0x20
	  lwz       r7, 0x224(r8)
	  lfs       f0, 0x260(r7)
	  stw       r6, 0x20(r1)
	  stw       r8, 0x24(r1)
	  stw       r5, 0x20(r1)
	  stfs      f0, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  stb       r0, 0x30(r1)
	  lwz       r3, 0x4C(r3)
	  lwz       r3, 0x318(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SnakeAi::setMouthCollPart(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void SnakeAi::getMouthCollPart(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015C184
 * Size:	000164
 */
void SnakeAi::pikiStickMouth()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  lwz       r5, 0x4C(r3)
	  lis       r3, 0x736C
	  addi      r4, r3, 0x6F74
	  lwz       r3, 0x220(r5)
	  bl        -0xD2AA4
	  lwz       r30, 0x10(r31)
	  mr        r29, r3
	  bl        0xBBEB0
	  xoris     r0, r3, 0x8000
	  lwz       r4, 0x10(r31)
	  stw       r0, 0x44(r1)
	  lis       r3, 0x4330
	  xoris     r0, r30, 0x8000
	  lfd       f4, -0x5580(r2)
	  stw       r3, 0x40(r1)
	  lfs       f0, -0x5588(r2)
	  cmpwi     r4, 0
	  lfd       f1, 0x40(r1)
	  mtctr     r4
	  stw       r0, 0x3C(r1)
	  fsubs     f3, f1, f4
	  lfs       f2, -0x558C(r2)
	  stw       r3, 0x38(r1)
	  lfs       f1, -0x5568(r2)
	  fdivs     f3, f3, f0
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r5, 0x34(r1)
	  ble-      .loc_0xF0

	.loc_0xA8:
	  cmpw      r5, r4
	  blt-      .loc_0xB4
	  li        r5, 0

	.loc_0xB4:
	  lwz       r3, 0x8(r31)
	  sraw      r0, r3, r5
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0xE8
	  li        r0, 0x1
	  slw       r0, r0, r5
	  or        r0, r3, r0
	  stw       r0, 0x8(r31)
	  mr        r28, r5
	  lwz       r3, 0xC(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0xC(r31)
	  b         .loc_0xF0

	.loc_0xE8:
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0xA8

	.loc_0xF0:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xD4490
	  lis       r4, 0x802B
	  lwz       r6, 0x4C(r31)
	  subi      r0, r4, 0x3064
	  stw       r0, 0x20(r1)
	  lis       r4, 0x802B
	  subi      r5, r4, 0x3244
	  stw       r6, 0x24(r1)
	  li        r0, 0
	  addi      r4, r1, 0x20
	  stw       r5, 0x20(r1)
	  stw       r0, 0x28(r1)
	  stw       r3, 0x2C(r1)
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x318(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015C2E8
 * Size:	000030
 */
void SnakeAi::eatStickToMouthPiki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x4C(r3)
	  bl        -0xCFDC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015C318
 * Size:	000298
 */
void SnakeAi::nearNaviInAttackArea(Creature**, f32*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stmw      r24, 0x38(r1)
	  mr        r25, r3
	  rlwinm    r28,r6,2,0,29
	  mr        r24, r6
	  mr        r26, r4
	  mr        r27, r5
	  lwz       r9, 0x18(r3)
	  lwz       r8, 0x1C(r3)
	  lwz       r7, 0x20(r3)
	  lwz       r6, 0x24(r25)
	  lwz       r31, 0x3120(r13)
	  lfsx      f2, r9, r28
	  lfsx      f0, r8, r28
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  fadds     f3, f2, f0
	  lfs       f2, -0x5570(r2)
	  lwz       r12, 0xC(r12)
	  lfsx      f1, r7, r28
	  lfsx      f0, r6, r28
	  fmuls     f31, f3, f2
	  mtlr      r12
	  fadds     f0, f1, f0
	  fmuls     f30, f0, f2
	  blrl
	  mulli     r29, r24, 0xC
	  lfs       f29, -0x5590(r2)
	  mr        r30, r3
	  b         .loc_0x21C

	.loc_0x8C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xB4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0xD0

	.loc_0xB4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0xD0:
	  lwz       r12, 0x0(r24)
	  mr        r3, r24
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x200
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x200
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x200
	  lwz       r3, 0x4C(r25)
	  lwz       r0, 0x18(r25)
	  lfs       f3, 0x94(r24)
	  lfs       f0, 0x94(r3)
	  lfs       f2, 0x9C(r24)
	  lfs       f1, 0x9C(r3)
	  fsubs     f3, f3, f0
	  lfs       f0, 0x34(r25)
	  fsubs     f5, f2, f1
	  lfs       f1, 0x3C(r25)
	  fmuls     f4, f0, f3
	  lfs       f0, 0x40(r25)
	  fmuls     f2, f1, f5
	  lfs       f1, 0x48(r25)
	  fmuls     f3, f0, f3
	  lfsx      f0, r28, r0
	  fadds     f4, f4, f2
	  fmuls     f2, f1, f5
	  fcmpo     cr0, f4, f0
	  fmr       f1, f4
	  fadds     f2, f3, f2
	  ble-      .loc_0x200
	  lwz       r0, 0x1C(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x200
	  lwz       r0, 0x20(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x200
	  lwz       r0, 0x24(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x200
	  lwz       r3, 0x30(r25)
	  lfs       f0, 0x98(r24)
	  addi      r0, r3, 0x4
	  lfsx      f3, r29, r0
	  fsubs     f3, f3, f0
	  fcmpo     cr0, f3, f29
	  ble-      .loc_0x1CC
	  b         .loc_0x1D0

	.loc_0x1CC:
	  fneg      f3, f3

	.loc_0x1D0:
	  lwz       r0, 0x28(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x200
	  fmr       f3, f31
	  fmr       f4, f30
	  bl        -0x123ED8
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x200
	  stfs      f1, 0x0(r27)
	  stw       r24, 0x0(r26)

	.loc_0x200:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x21C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x244
	  li        r0, 0x1
	  b         .loc_0x270

	.loc_0x244:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x26C
	  li        r0, 0x1
	  b         .loc_0x270

	.loc_0x26C:
	  li        r0, 0

	.loc_0x270:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x8C
	  lmw       r24, 0x38(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015C5B0
 * Size:	000298
 */
void SnakeAi::nearPikiInAttackArea(Creature**, f32*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stmw      r24, 0x38(r1)
	  mr        r25, r3
	  rlwinm    r28,r6,2,0,29
	  mr        r24, r6
	  mr        r26, r4
	  mr        r27, r5
	  lwz       r9, 0x18(r3)
	  lwz       r8, 0x1C(r3)
	  lwz       r7, 0x20(r3)
	  lwz       r6, 0x24(r25)
	  lwz       r31, 0x3068(r13)
	  lfsx      f2, r9, r28
	  lfsx      f0, r8, r28
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  fadds     f3, f2, f0
	  lfs       f2, -0x5570(r2)
	  lwz       r12, 0xC(r12)
	  lfsx      f1, r7, r28
	  lfsx      f0, r6, r28
	  fmuls     f31, f3, f2
	  mtlr      r12
	  fadds     f0, f1, f0
	  fmuls     f30, f0, f2
	  blrl
	  mulli     r29, r24, 0xC
	  lfs       f29, -0x5590(r2)
	  mr        r30, r3
	  b         .loc_0x21C

	.loc_0x8C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xB4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0xD0

	.loc_0xB4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0xD0:
	  lwz       r12, 0x0(r24)
	  mr        r3, r24
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x200
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x200
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x200
	  lwz       r3, 0x4C(r25)
	  lwz       r0, 0x18(r25)
	  lfs       f3, 0x94(r24)
	  lfs       f0, 0x94(r3)
	  lfs       f2, 0x9C(r24)
	  lfs       f1, 0x9C(r3)
	  fsubs     f3, f3, f0
	  lfs       f0, 0x34(r25)
	  fsubs     f5, f2, f1
	  lfs       f1, 0x3C(r25)
	  fmuls     f4, f0, f3
	  lfs       f0, 0x40(r25)
	  fmuls     f2, f1, f5
	  lfs       f1, 0x48(r25)
	  fmuls     f3, f0, f3
	  lfsx      f0, r28, r0
	  fadds     f4, f4, f2
	  fmuls     f2, f1, f5
	  fcmpo     cr0, f4, f0
	  fmr       f1, f4
	  fadds     f2, f3, f2
	  ble-      .loc_0x200
	  lwz       r0, 0x1C(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x200
	  lwz       r0, 0x20(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x200
	  lwz       r0, 0x24(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x200
	  lwz       r3, 0x30(r25)
	  lfs       f0, 0x98(r24)
	  addi      r0, r3, 0x4
	  lfsx      f3, r29, r0
	  fsubs     f3, f3, f0
	  fcmpo     cr0, f3, f29
	  ble-      .loc_0x1CC
	  b         .loc_0x1D0

	.loc_0x1CC:
	  fneg      f3, f3

	.loc_0x1D0:
	  lwz       r0, 0x28(r25)
	  lfsx      f0, r28, r0
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x200
	  fmr       f3, f31
	  fmr       f4, f30
	  bl        -0x124170
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x200
	  stfs      f1, 0x0(r27)
	  stw       r24, 0x0(r26)

	.loc_0x200:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x21C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x244
	  li        r0, 0x1
	  b         .loc_0x270

	.loc_0x244:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x26C
	  li        r0, 0x1
	  b         .loc_0x270

	.loc_0x26C:
	  li        r0, 0

	.loc_0x270:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x8C
	  lmw       r24, 0x38(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015C848
 * Size:	00025C
 */
void SnakeAi::naviInAttackArea(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stmw      r27, 0x3C(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  lwz       r31, 0x3120(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5590(r2)
	  mr        r30, r3
	  b         .loc_0x1E4

	.loc_0x40:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x68
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x84

	.loc_0x68:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x84:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1C8
	  lwz       r6, 0x4C(r28)
	  li        r4, 0
	  lfs       f3, 0x94(r27)
	  cmpwi     r29, 0
	  lfs       f1, 0x94(r6)
	  lfs       f2, 0x9C(r27)
	  mtctr     r29
	  lfs       f0, 0x9C(r6)
	  fsubs     f4, f3, f1
	  lfs       f3, 0x34(r28)
	  lfs       f1, 0x40(r28)
	  fsubs     f5, f2, f0
	  lfs       f2, 0x3C(r28)
	  lfs       f0, 0x48(r28)
	  fmuls     f3, f3, f4
	  fmuls     f2, f2, f5
	  fmuls     f1, f1, f4
	  mr        r5, r4
	  fmuls     f0, f0, f5
	  fadds     f2, f3, f2
	  li        r7, 0
	  fadds     f3, f1, f0
	  ble-      .loc_0x1C8

	.loc_0x134:
	  lwz       r3, 0x18(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x1B8
	  lwz       r3, 0x1C(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x1B8
	  lwz       r3, 0x20(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x1B8
	  lwz       r3, 0x24(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x1B8
	  lwz       r3, 0x30(r28)
	  addi      r0, r5, 0x4
	  lfs       f0, 0x98(r27)
	  lfsx      f1, r3, r0
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x194
	  b         .loc_0x198

	.loc_0x194:
	  fneg      f1, f1

	.loc_0x198:
	  lwz       r3, 0x28(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B8
	  stw       r27, 0x318(r6)
	  li        r3, 0x1
	  stw       r7, 0x14(r28)
	  b         .loc_0x244

	.loc_0x1B8:
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0xC
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x134

	.loc_0x1C8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1E4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x20C
	  li        r0, 0x1
	  b         .loc_0x238

	.loc_0x20C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x234
	  li        r0, 0x1
	  b         .loc_0x238

	.loc_0x234:
	  li        r0, 0

	.loc_0x238:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40
	  li        r3, 0

	.loc_0x244:
	  lmw       r27, 0x3C(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015CAA4
 * Size:	00025C
 */
void SnakeAi::pikiInAttackArea(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stmw      r27, 0x3C(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5590(r2)
	  mr        r30, r3
	  b         .loc_0x1E4

	.loc_0x40:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x68
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x84

	.loc_0x68:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x84:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1C8
	  lwz       r6, 0x4C(r28)
	  li        r4, 0
	  lfs       f3, 0x94(r27)
	  cmpwi     r29, 0
	  lfs       f1, 0x94(r6)
	  lfs       f2, 0x9C(r27)
	  mtctr     r29
	  lfs       f0, 0x9C(r6)
	  fsubs     f4, f3, f1
	  lfs       f3, 0x34(r28)
	  lfs       f1, 0x40(r28)
	  fsubs     f5, f2, f0
	  lfs       f2, 0x3C(r28)
	  lfs       f0, 0x48(r28)
	  fmuls     f3, f3, f4
	  fmuls     f2, f2, f5
	  fmuls     f1, f1, f4
	  mr        r5, r4
	  fmuls     f0, f0, f5
	  fadds     f2, f3, f2
	  li        r7, 0
	  fadds     f3, f1, f0
	  ble-      .loc_0x1C8

	.loc_0x134:
	  lwz       r3, 0x18(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x1B8
	  lwz       r3, 0x1C(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x1B8
	  lwz       r3, 0x20(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x1B8
	  lwz       r3, 0x24(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x1B8
	  lwz       r3, 0x30(r28)
	  addi      r0, r5, 0x4
	  lfs       f0, 0x98(r27)
	  lfsx      f1, r3, r0
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x194
	  b         .loc_0x198

	.loc_0x194:
	  fneg      f1, f1

	.loc_0x198:
	  lwz       r3, 0x28(r28)
	  lfsx      f0, r3, r4
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B8
	  stw       r27, 0x318(r6)
	  li        r3, 0x1
	  stw       r7, 0x14(r28)
	  b         .loc_0x244

	.loc_0x1B8:
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0xC
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x134

	.loc_0x1C8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1E4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x20C
	  li        r0, 0x1
	  b         .loc_0x238

	.loc_0x20C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x234
	  li        r0, 0x1
	  b         .loc_0x238

	.loc_0x234:
	  li        r0, 0

	.loc_0x238:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40
	  li        r3, 0

	.loc_0x244:
	  lmw       r27, 0x3C(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015CD00
 * Size:	000414
 */
void SnakeAi::appearType01()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stmw      r27, 0xBC(r1)
	  addi      r29, r3, 0
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5590(r2)
	  mr        r30, r3
	  b         .loc_0x1AC

	.loc_0x3C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x64
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x80

	.loc_0x64:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x80:
	  addi      r27, r28, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x190
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x190
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x190
	  lwz       r4, 0x4C(r29)
	  lfs       f1, 0x94(r27)
	  lwz       r3, 0x224(r4)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x3D0(r4)
	  addi      r27, r3, 0x210
	  lfs       f4, 0x3D8(r4)
	  bl        -0x1247CC
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x190
	  lwz       r3, 0x4C(r29)
	  stfs      f31, 0x94(r1)
	  stfs      f31, 0x90(r1)
	  stfs      f31, 0x8C(r1)
	  lfsu      f0, 0x3D0(r3)
	  lfs       f1, 0x94(r28)
	  lfs       f4, 0x9C(r28)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r28)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x60(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f1, 0x90(r1)
	  stfs      f3, 0x94(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x90(r1)
	  lfs       f2, 0x94(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14F22C
	  lwz       r4, 0x4C(r29)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x210(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x190
	  stw       r28, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x3FC

	.loc_0x190:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1AC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D4
	  li        r0, 0x1
	  b         .loc_0x200

	.loc_0x1D4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1FC
	  li        r0, 0x1
	  b         .loc_0x200

	.loc_0x1FC:
	  li        r0, 0

	.loc_0x200:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x3C
	  lwz       r30, 0x3120(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5590(r2)
	  mr        r31, r3
	  b         .loc_0x39C

	.loc_0x22C:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x254
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x270

	.loc_0x254:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x270:
	  addi      r27, r28, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x380
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x380
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x380
	  lwz       r4, 0x4C(r29)
	  lfs       f1, 0x94(r27)
	  lwz       r3, 0x224(r4)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x3D0(r4)
	  addi      r27, r3, 0x210
	  lfs       f4, 0x3D8(r4)
	  bl        -0x1249BC
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x380
	  lwz       r3, 0x4C(r29)
	  stfs      f31, 0x78(r1)
	  stfs      f31, 0x74(r1)
	  stfs      f31, 0x70(r1)
	  lfsu      f0, 0x3D0(r3)
	  lfs       f1, 0x94(r28)
	  lfs       f4, 0x9C(r28)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r28)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x58(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f3, 0x78(r1)
	  lfs       f1, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  lfs       f2, 0x78(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14F41C
	  lwz       r4, 0x4C(r29)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x210(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x380
	  stw       r28, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x3FC

	.loc_0x380:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x39C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C4
	  li        r0, 0x1
	  b         .loc_0x3F0

	.loc_0x3C4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3EC
	  li        r0, 0x1
	  b         .loc_0x3F0

	.loc_0x3EC:
	  li        r0, 0

	.loc_0x3F0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x22C
	  li        r3, 0

	.loc_0x3FC:
	  lmw       r27, 0xBC(r1)
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015D114
 * Size:	0004D8
 */
void SnakeAi::appearType02()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x118(r1)
	  stfd      f31, 0x110(r1)
	  stfd      f30, 0x108(r1)
	  stfd      f29, 0x100(r1)
	  stfd      f28, 0xF8(r1)
	  stfd      f27, 0xF0(r1)
	  stfd      f26, 0xE8(r1)
	  stw       r31, 0xE4(r1)
	  mr        r31, r3
	  stw       r30, 0xE0(r1)
	  stw       r29, 0xDC(r1)
	  stw       r28, 0xD8(r1)
	  lwz       r3, 0x4C(r3)
	  lfs       f3, -0x5564(r2)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x3C0(r3)
	  lfs       f2, 0x230(r4)
	  lfs       f0, 0x240(r4)
	  fadds     f26, f3, f1
	  fadds     f27, f2, f0
	  bl        0xBE9E8
	  lwz       r3, 0x4C(r31)
	  fmr       f28, f1
	  lfs       f1, 0x3C0(r3)
	  bl        0xBEB6C
	  fmr       f29, f1
	  fmr       f1, f26
	  bl        0xBE9CC
	  fmr       f30, f1
	  fmr       f1, f26
	  bl        0xBEB54
	  lwz       r29, 0x3068(r13)
	  fmr       f31, f1
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f26, -0x5590(r2)
	  mr        r28, r3
	  b         .loc_0x23C

	.loc_0xAC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xD4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xF0

	.loc_0xD4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xF0:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x220
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x220
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x220
	  lwz       r3, 0x4C(r31)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f3, 0x3D0(r3)
	  lfs       f4, 0x3D8(r3)
	  bl        -0x124C44
	  fcmpo     cr0, f1, f27
	  bge-      .loc_0x220
	  lwz       r4, 0x4C(r31)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x3D4(r4)
	  lwz       r5, 0x224(r4)
	  fsubs     f1, f1, f0
	  addi      r3, r5, 0x250
	  fcmpo     cr0, f1, f26
	  ble-      .loc_0x188
	  b         .loc_0x18C

	.loc_0x188:
	  fneg      f1, f1

	.loc_0x18C:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x220
	  lfs       f2, 0x94(r30)
	  addi      r3, r5, 0x230
	  lfs       f0, 0x3D0(r4)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x3D8(r4)
	  fsubs     f0, f1, f0
	  fmuls     f3, f29, f2
	  fmuls     f1, f31, f2
	  fmuls     f2, f28, f0
	  fmuls     f0, f30, f0
	  fadds     f2, f3, f2
	  fadds     f3, f1, f0
	  fcmpo     cr0, f2, f26
	  fmr       f0, f2
	  ble-      .loc_0x1E0
	  fmr       f1, f0
	  b         .loc_0x1E4

	.loc_0x1E0:
	  fneg      f1, f0

	.loc_0x1E4:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x220
	  fcmpo     cr0, f3, f26
	  addi      r3, r5, 0x240
	  ble-      .loc_0x204
	  fmr       f1, f3
	  b         .loc_0x208

	.loc_0x204:
	  fneg      f1, f3

	.loc_0x208:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x220
	  stw       r30, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x4A0

	.loc_0x220:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x23C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x264
	  li        r0, 0x1
	  b         .loc_0x290

	.loc_0x264:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x28C
	  li        r0, 0x1
	  b         .loc_0x290

	.loc_0x28C:
	  li        r0, 0

	.loc_0x290:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xAC
	  lwz       r28, 0x3120(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f26, -0x5590(r2)
	  mr        r29, r3
	  b         .loc_0x440

	.loc_0x2BC:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x2E4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x300

	.loc_0x2E4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x300:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x424
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x424
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x424
	  lwz       r3, 0x4C(r31)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f3, 0x3D0(r3)
	  lfs       f4, 0x3D8(r3)
	  bl        -0x124E54
	  fcmpo     cr0, f1, f27
	  bge-      .loc_0x424
	  lwz       r4, 0x4C(r31)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x3D4(r4)
	  lwz       r5, 0x224(r4)
	  fsubs     f1, f1, f0
	  addi      r3, r5, 0x250
	  fcmpo     cr0, f1, f26
	  ble-      .loc_0x398
	  b         .loc_0x39C

	.loc_0x398:
	  fneg      f1, f1

	.loc_0x39C:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x424
	  lfs       f2, 0x94(r30)
	  addi      r3, r5, 0x230
	  lfs       f0, 0x3D0(r4)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x3D8(r4)
	  fsubs     f0, f1, f0
	  fmuls     f3, f29, f2
	  fmuls     f1, f31, f2
	  fmuls     f2, f28, f0
	  fmuls     f0, f30, f0
	  fadds     f2, f3, f2
	  fadds     f1, f1, f0
	  fcmpo     cr0, f2, f26
	  ble-      .loc_0x3E8
	  b         .loc_0x3EC

	.loc_0x3E8:
	  fneg      f2, f2

	.loc_0x3EC:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x424
	  fcmpo     cr0, f1, f26
	  addi      r3, r5, 0x240
	  ble-      .loc_0x408
	  b         .loc_0x40C

	.loc_0x408:
	  fneg      f1, f1

	.loc_0x40C:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x424
	  stw       r30, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x4A0

	.loc_0x424:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x440:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x468
	  li        r0, 0x1
	  b         .loc_0x494

	.loc_0x468:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x490
	  li        r0, 0x1
	  b         .loc_0x494

	.loc_0x490:
	  li        r0, 0

	.loc_0x494:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2BC
	  li        r3, 0

	.loc_0x4A0:
	  lwz       r0, 0x11C(r1)
	  lfd       f31, 0x110(r1)
	  lfd       f30, 0x108(r1)
	  lfd       f29, 0x100(r1)
	  lfd       f28, 0xF8(r1)
	  lfd       f27, 0xF0(r1)
	  lfd       f26, 0xE8(r1)
	  lwz       r31, 0xE4(r1)
	  lwz       r30, 0xE0(r1)
	  lwz       r29, 0xDC(r1)
	  lwz       r28, 0xD8(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SnakeAi::resultFlagOn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void SnakeAi::resultFlagSeen()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SnakeAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SnakeAi::struggleTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015D5EC
 * Size:	000378
 */
void SnakeAi::chaseNaviTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stfd      f28, 0x110(r1)
	  stfd      f27, 0x108(r1)
	  stfd      f26, 0x100(r1)
	  stmw      r26, 0xE8(r1)
	  mr        r27, r3
	  li        r28, 0
	  lwz       r4, 0x4C(r3)
	  lfs       f26, -0x556C(r2)
	  lwz       r3, 0x3CC(r4)
	  addi      r31, r4, 0x300
	  lfsu      f29, 0x50(r3)
	  lwz       r4, 0x318(r4)
	  lfs       f28, 0x4(r3)
	  cmplwi    r4, 0
	  lfs       f27, 0x8(r3)
	  beq-      .loc_0xBC
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0x94(r4)
	  lfs       f2, 0x9C(r4)
	  fsubs     f0, f0, f29
	  lfs       f1, 0x98(r4)
	  fsubs     f2, f2, f27
	  fsubs     f1, f1, f28
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f1, 0xB4(r1)
	  stfs      f2, 0xB8(r1)
	  lfs       f1, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xB8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14FA60
	  fmr       f26, f1

	.loc_0xBC:
	  lwz       r30, 0x3120(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5590(r2)
	  mr        r29, r3
	  b         .loc_0x2D4

	.loc_0xE0:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x108
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x124

	.loc_0x108:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x124:
	  lwz       r12, 0x0(r26)
	  mr        r3, r26
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B8
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B8
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2B8
	  fmr       f1, f29
	  lfs       f3, 0x94(r26)
	  fmr       f2, f27
	  lfs       f4, 0x9C(r26)
	  bl        -0x12514C
	  lwz       r3, 0x4C(r27)
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x88(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2B8
	  fcmpo     cr0, f1, f26
	  bge-      .loc_0x2B8
	  mr        r4, r26
	  bl        -0xE8C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B8
	  stfs      f31, 0xA4(r1)
	  stfs      f31, 0xA0(r1)
	  stfs      f31, 0x9C(r1)
	  lfs       f0, 0x94(r26)
	  lfs       f2, 0x9C(r26)
	  fsubs     f0, f0, f29
	  lfs       f1, 0x98(r26)
	  fsubs     f2, f2, f27
	  fsubs     f1, f1, f28
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x9C(r1)
	  stfs      f1, 0xA0(r1)
	  stfs      f2, 0xA4(r1)
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14FBBC
	  lwz       r3, 0x4C(r27)
	  fmr       f30, f1
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x88(r3)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x2B8
	  fcmpo     cr0, f30, f26
	  bge-      .loc_0x2B8
	  stfs      f31, 0x94(r1)
	  stfs      f31, 0x90(r1)
	  stfs      f31, 0x8C(r1)
	  lfs       f1, 0x94(r26)
	  lfs       f0, 0x0(r31)
	  lfs       f4, 0x9C(r26)
	  lfs       f3, 0x8(r31)
	  fsubs     f0, f1, f0
	  lfs       f2, 0x98(r26)
	  lfs       f1, 0x4(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x74(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f1, 0x90(r1)
	  stfs      f3, 0x94(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x90(r1)
	  lfs       f2, 0x94(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14FC44
	  lwz       r3, 0x4C(r27)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x68(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2B8
	  fmr       f26, f30
	  mr        r28, r26

	.loc_0x2B8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x2D4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2FC
	  li        r0, 0x1
	  b         .loc_0x328

	.loc_0x2FC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x324
	  li        r0, 0x1
	  b         .loc_0x328

	.loc_0x324:
	  li        r0, 0

	.loc_0x328:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xE0
	  cmplwi    r28, 0
	  beq-      .loc_0x348
	  lwz       r4, 0x4C(r27)
	  li        r3, 0x1
	  stw       r28, 0x318(r4)
	  b         .loc_0x34C

	.loc_0x348:
	  li        r3, 0

	.loc_0x34C:
	  lmw       r26, 0xE8(r1)
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lfd       f27, 0x108(r1)
	  lfd       f26, 0x100(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015D964
 * Size:	000388
 */
void SnakeAi::chasePikiTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x138(r1)
	  stfd      f31, 0x130(r1)
	  stfd      f30, 0x128(r1)
	  stfd      f29, 0x120(r1)
	  stfd      f28, 0x118(r1)
	  stfd      f27, 0x110(r1)
	  stfd      f26, 0x108(r1)
	  stmw      r26, 0xF0(r1)
	  mr        r26, r3
	  li        r27, 0
	  lwz       r4, 0x4C(r3)
	  lfs       f26, -0x556C(r2)
	  lwz       r3, 0x3CC(r4)
	  addi      r30, r4, 0x300
	  lfsu      f29, 0x50(r3)
	  lwz       r4, 0x318(r4)
	  lfs       f28, 0x4(r3)
	  cmplwi    r4, 0
	  lfs       f27, 0x8(r3)
	  beq-      .loc_0xBC
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0x94(r4)
	  lfs       f2, 0x9C(r4)
	  fsubs     f0, f0, f29
	  lfs       f1, 0x98(r4)
	  fsubs     f2, f2, f27
	  fsubs     f1, f1, f28
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x84(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f2, 0xBC(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f0, 0xB8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xBC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14FDD8
	  fmr       f26, f1

	.loc_0xBC:
	  lwz       r29, 0x3068(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5590(r2)
	  mr        r28, r3
	  b         .loc_0x2E4

	.loc_0xE0:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x108
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x124

	.loc_0x108:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x124:
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2C8
	  lwz       r3, 0x184(r31)
	  lwz       r0, 0x4C(r26)
	  cmplw     r3, r0
	  beq-      .loc_0x2C8
	  fmr       f1, f29
	  lfs       f3, 0x94(r31)
	  fmr       f2, f27
	  lfs       f4, 0x9C(r31)
	  bl        -0x1254D4
	  lwz       r3, 0x4C(r26)
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x88(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2C8
	  fcmpo     cr0, f1, f26
	  bge-      .loc_0x2C8
	  mr        r4, r31
	  bl        -0xEC50
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C8
	  stfs      f31, 0xA8(r1)
	  stfs      f31, 0xA4(r1)
	  stfs      f31, 0xA0(r1)
	  lfs       f0, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  fsubs     f0, f0, f29
	  lfs       f1, 0x98(r31)
	  fsubs     f2, f2, f27
	  fsubs     f1, f1, f28
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f1, 0xA4(r1)
	  stfs      f2, 0xA8(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14FF44
	  lwz       r3, 0x4C(r26)
	  fmr       f30, f1
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x88(r3)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x2C8
	  fcmpo     cr0, f30, f26
	  bge-      .loc_0x2C8
	  stfs      f31, 0x98(r1)
	  stfs      f31, 0x94(r1)
	  stfs      f31, 0x90(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x0(r30)
	  lfs       f4, 0x9C(r31)
	  lfs       f3, 0x8(r30)
	  fsubs     f0, f1, f0
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x4(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x78(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f3, 0x98(r1)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  lfs       f2, 0x98(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14FFCC
	  lwz       r3, 0x4C(r26)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x68(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2C8
	  fmr       f26, f30
	  mr        r27, r31

	.loc_0x2C8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x2E4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x30C
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x30C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xE0
	  cmplwi    r27, 0
	  beq-      .loc_0x358
	  lwz       r4, 0x4C(r26)
	  li        r3, 0x1
	  stw       r27, 0x318(r4)
	  b         .loc_0x35C

	.loc_0x358:
	  li        r3, 0

	.loc_0x35C:
	  lmw       r26, 0xF0(r1)
	  lwz       r0, 0x13C(r1)
	  lfd       f31, 0x130(r1)
	  lfd       f30, 0x128(r1)
	  lfd       f29, 0x120(r1)
	  lfd       f28, 0x118(r1)
	  lfd       f27, 0x110(r1)
	  lfd       f26, 0x108(r1)
	  addi      r1, r1, 0x138
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015DCEC
 * Size:	000208
 */
void SnakeAi::targetLostTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  stw       r30, 0x98(r1)
	  mr        r30, r3
	  lwz       r3, 0x4C(r3)
	  lwz       r31, 0x318(r3)
	  cmplwi    r31, 0
	  beq-      .loc_0x1EC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  lwz       r0, 0x184(r31)
	  lwz       r3, 0x4C(r30)
	  cmplw     r0, r3
	  bne-      .loc_0xA0

	.loc_0x8C:
	  lwz       r4, 0x4C(r30)
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x318(r4)
	  b         .loc_0x1F0

	.loc_0xA0:
	  mr        r4, r31
	  bl        -0xEEC0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC4
	  lwz       r4, 0x4C(r30)
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x318(r4)
	  b         .loc_0x1F0

	.loc_0xC4:
	  lwz       r3, 0x4C(r30)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x3CC(r3)
	  stfs      f0, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  lfsu      f0, 0x50(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x54(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f1, 0x80(r1)
	  stfs      f3, 0x84(r1)
	  lfs       f1, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  lfs       f2, 0x84(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1501E0
	  lwz       r4, 0x4C(r30)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x88(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x15C
	  li        r0, 0
	  stw       r0, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x1F0

	.loc_0x15C:
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0x6C(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x300(r4)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x308(r4)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x304(r4)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x50(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f1, 0x68(r1)
	  stfs      f3, 0x6C(r1)
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  lfs       f2, 0x6C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x150270
	  lwz       r4, 0x4C(r30)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x68(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1EC
	  li        r0, 0
	  stw       r0, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x1F0

	.loc_0x1EC:
	  li        r3, 0

	.loc_0x1F0:
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015DEF4
 * Size:	00004C
 */
void SnakeAi::attackTransit(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x146C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x34
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x16DC

	.loc_0x34:
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
 * Address:	8015DF40
 * Size:	000020
 */
void SnakeAi::collPartMaxTransit()
{
	/*
	.loc_0x0:
	  lwz       r4, 0xC(r3)
	  lwz       r0, 0x10(r3)
	  cmpw      r4, r0
	  bge-      .loc_0x18
	  li        r3, 0
	  blr

	.loc_0x18:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void SnakeAi::eatPikiTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SnakeAi::intoGroundTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void SnakeAi::diveTimerTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void SnakeAi::underTimerTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void SnakeAi::appearTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void SnakeAi::initDie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void SnakeAi::initStruggle(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void SnakeAi::initChase(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015DF60
 * Size:	00018C
 */
void SnakeAi::initAttack(int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  fmr       f31, f1
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lwz       r3, 0x4C(r3)
	  stw       r4, 0x2E8(r3)
	  lfs       f0, -0x555C(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D8(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r5, 0x2BD(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  stb       r0, 0x5(r31)
	  lwz       r0, 0x14(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x80
	  addi      r5, r31, 0
	  addi      r3, r1, 0x48
	  li        r4, 0xA
	  bl        -0x3F03C
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EE18
	  b         .loc_0x12C

	.loc_0x80:
	  cmpwi     r0, 0x1
	  bne-      .loc_0xAC
	  addi      r5, r31, 0
	  addi      r3, r1, 0x40
	  li        r4, 0xB
	  bl        -0x3F068
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EE44
	  b         .loc_0x12C

	.loc_0xAC:
	  cmpwi     r0, 0x2
	  bne-      .loc_0xD8
	  addi      r5, r31, 0
	  addi      r3, r1, 0x38
	  li        r4, 0xC
	  bl        -0x3F094
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EE70
	  b         .loc_0x12C

	.loc_0xD8:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x104
	  addi      r5, r31, 0
	  addi      r3, r1, 0x30
	  li        r4, 0xD
	  bl        -0x3F0C0
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EE9C
	  b         .loc_0x12C

	.loc_0x104:
	  cmpwi     r0, 0x4
	  bne-      .loc_0x12C
	  addi      r5, r31, 0
	  addi      r3, r1, 0x28
	  li        r4, 0xE
	  bl        -0x3F0EC
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EEC8

	.loc_0x12C:
	  lfs       f0, -0x5590(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x14C
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5578(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x2080
	  b         .loc_0x154

	.loc_0x14C:
	  lwz       r3, 0x4C(r31)
	  stfs      f31, 0x368(r3)

	.loc_0x154:
	  lwz       r3, 0x4C(r31)
	  bl        -0xECF8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x174
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDA6D0

	.loc_0x174:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void SnakeAi::initEat(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void SnakeAi::initWait(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void SnakeAi::initGointo(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void SnakeAi::initUnder(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015E0EC
 * Size:	0005C8
 */
void SnakeAi::initAppear(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x208(r1)
	  stfd      f31, 0x200(r1)
	  stfd      f30, 0x1F8(r1)
	  stfd      f29, 0x1F0(r1)
	  stfd      f28, 0x1E8(r1)
	  stfd      f27, 0x1E0(r1)
	  stfd      f26, 0x1D8(r1)
	  stfd      f25, 0x1D0(r1)
	  stfd      f24, 0x1C8(r1)
	  stfd      f23, 0x1C0(r1)
	  stfd      f22, 0x1B8(r1)
	  stw       r31, 0x1B4(r1)
	  mr        r31, r3
	  stw       r30, 0x1B0(r1)
	  li        r30, 0
	  stw       r29, 0x1AC(r1)
	  lwz       r3, 0x4C(r3)
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r30, 0x2BD(r3)
	  lfs       f0, -0x555C(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D8(r3)
	  lbz       r0, 0x6(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  addi      r5, r31, 0
	  addi      r3, r1, 0x194
	  li        r4, 0x6
	  bl        -0x3F1DC
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EFB8
	  stb       r30, 0x6(r31)
	  b         .loc_0x12C

	.loc_0x98:
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x224(r3)
	  addi      r30, r3, 0x4A0
	  bl        0xB9EE0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5580(r2)
	  stw       r0, 0x1A4(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x5588(r2)
	  stw       r0, 0x1A0(r1)
	  lfs       f2, -0x558C(r2)
	  lfd       f0, 0x1A0(r1)
	  lfs       f1, -0x5568(r2)
	  fsubs     f4, f0, f4
	  lfs       f0, 0x0(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x10C
	  addi      r5, r31, 0
	  addi      r3, r1, 0x18C
	  li        r4, 0x6
	  bl        -0x3F254
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F030
	  b         .loc_0x12C

	.loc_0x10C:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x184
	  li        r4, 0x7
	  bl        -0x3F278
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F054

	.loc_0x12C:
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x556C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1F00
	  lwz       r4, 0x4C(r31)
	  lbz       r0, 0x3BC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x23C
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0x16C(r1)
	  stfs      f0, 0x168(r1)
	  stfs      f0, 0x164(r1)
	  bl        0xB9E28
	  xoris     r0, r3, 0x8000
	  lwz       r4, 0x4C(r31)
	  stw       r0, 0x1A4(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x224(r4)
	  stw       r0, 0x1A0(r1)
	  lfd       f1, -0x5580(r2)
	  addi      r29, r3, 0x220
	  lfd       f0, 0x1A0(r1)
	  lfs       f2, -0x5588(r2)
	  fsubs     f3, f0, f1
	  lfs       f1, -0x558C(r2)
	  lfs       f0, -0x5584(r2)
	  lwz       r30, 0x318(r4)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f26, f0, f1
	  fmr       f1, f26
	  bl        0xBD8C0
	  lfs       f2, 0x0(r29)
	  lfs       f0, 0x94(r30)
	  fmuls     f2, f2, f1
	  fmr       f1, f26
	  fadds     f0, f0, f2
	  stfs      f0, 0x164(r1)
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x224(r3)
	  addi      r29, r3, 0x220
	  bl        0xBDA2C
	  lfs       f2, 0x0(r29)
	  li        r4, 0x1
	  lfs       f0, 0x9C(r30)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0x16C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x164(r1)
	  lfs       f2, 0x16C(r1)
	  bl        -0xF63E0
	  stfs      f1, 0x168(r1)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x300(r4)
	  stw       r0, 0x304(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x308(r4)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x9C(r4)
	  b         .loc_0x4B0

	.loc_0x23C:
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  lwz       r3, 0x318(r4)
	  lfsu      f31, 0x94(r3)
	  lfs       f1, 0x3C0(r4)
	  lfs       f30, 0x4(r3)
	  lfs       f29, 0x8(r3)
	  bl        0xBD808
	  lwz       r3, 0x4C(r31)
	  fmr       f26, f1
	  lfs       f1, 0x3C0(r3)
	  bl        0xBD98C
	  stfs      f1, 0xC4(r1)
	  lfs       f0, -0x70(r13)
	  stfs      f0, 0xC8(r1)
	  stfs      f26, 0xCC(r1)
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x224(r3)
	  addi      r3, r3, 0x224
	  bl        .loc_0x5C8
	  addi      r5, r3, 0
	  addi      r3, r1, 0x104
	  addi      r4, r1, 0xC4
	  bl        -0xBEEB8
	  lwz       r3, 0x4C(r31)
	  addi      r6, r1, 0x78
	  lfs       f0, 0x10C(r1)
	  addi      r5, r1, 0x74
	  lfs       f2, 0x3D8(r3)
	  addi      r7, r3, 0x3D0
	  lfs       f1, 0x108(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x104(r1)
	  addi      r4, r1, 0x70
	  addi      r3, r1, 0xF8
	  stfs      f2, 0x78(r1)
	  lfs       f2, 0x4(r7)
	  fadds     f1, f2, f1
	  stfs      f1, 0x74(r1)
	  lfs       f1, 0x0(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  bl        -0x1272BC
	  lwz       r3, 0x4C(r31)
	  lfs       f28, 0xF8(r1)
	  lwz       r3, 0x224(r3)
	  lfs       f27, 0xFC(r1)
	  lfs       f26, 0x100(r1)
	  addi      r3, r3, 0x224
	  bl        .loc_0x5C8
	  addi      r5, r3, 0
	  addi      r3, r1, 0x11C
	  addi      r4, r1, 0xC4
	  bl        -0xBEF30
	  lwz       r3, 0x4C(r31)
	  addi      r6, r1, 0x6C
	  lfs       f0, 0x124(r1)
	  addi      r5, r1, 0x68
	  lfs       f2, 0x3D8(r3)
	  addi      r7, r3, 0x3D0
	  lfs       f1, 0x120(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x11C(r1)
	  addi      r4, r1, 0x64
	  addi      r3, r1, 0x110
	  stfs      f2, 0x6C(r1)
	  lfs       f2, 0x4(r7)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x68(r1)
	  lfs       f1, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  bl        -0x127334
	  lfs       f22, 0x110(r1)
	  addi      r6, r1, 0x60
	  lfs       f25, 0x114(r1)
	  addi      r5, r1, 0x5C
	  lfs       f24, 0x118(r1)
	  fsubs     f1, f25, f27
	  addi      r4, r1, 0x58
	  fsubs     f2, f24, f26
	  addi      r3, r1, 0x128
	  fsubs     f0, f22, f28
	  stfs      f2, 0x60(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  bl        -0x12736C
	  stfs      f22, 0x14C(r1)
	  addi      r5, r1, 0x14C
	  lfs       f23, 0x128(r1)
	  addi      r4, r1, 0x140
	  stfs      f31, 0x134(r1)
	  lfs       f22, 0x12C(r1)
	  addi      r3, r1, 0x134
	  stfs      f28, 0x140(r1)
	  addi      r6, r1, 0xF4
	  lfs       f31, 0x130(r1)
	  stfs      f25, 0x150(r1)
	  stfs      f27, 0x144(r1)
	  stfs      f30, 0x138(r1)
	  stfs      f24, 0x154(r1)
	  stfs      f26, 0x148(r1)
	  stfs      f29, 0x13C(r1)
	  bl        0x3D454
	  lfs       f0, 0xF4(r1)
	  lfs       f3, -0x5590(r2)
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x3F8
	  b         .loc_0x40C

	.loc_0x3F8:
	  lfs       f3, -0x558C(r2)
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x408
	  b         .loc_0x40C

	.loc_0x408:
	  fmr       f3, f0

	.loc_0x40C:
	  fmuls     f2, f31, f3
	  stfs      f3, 0xF4(r1)
	  fmuls     f1, f22, f3
	  addi      r6, r1, 0x54
	  fmuls     f0, f23, f3
	  stfs      f2, 0x54(r1)
	  addi      r5, r1, 0x50
	  addi      r4, r1, 0x4C
	  stfs      f1, 0x50(r1)
	  addi      r3, r1, 0x158
	  stfs      f0, 0x4C(r1)
	  bl        -0x127408
	  lfs       f1, 0x158(r1)
	  li        r4, 0x1
	  lfs       f0, 0x15C(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f27, f0
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0x160(r1)
	  fadds     f0, f26, f0
	  stfs      f0, 0xB4(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0xAC(r1)
	  lfs       f2, 0xB4(r1)
	  bl        -0xF6658
	  stfs      f1, 0xB0(r1)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0x300(r4)
	  stw       r0, 0x304(r4)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x308(r4)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x9C(r4)

	.loc_0x4B0:
	  lwz       r3, 0x4C(r31)
	  bl        -0x10008
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x556C(r2)
	  bl        -0x101FC
	  lwz       r3, 0x4C(r31)
	  bl        -0xD42E8
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x1
	  li        r4, 0x7E
	  stb       r0, 0x2B8(r3)
	  li        r6, 0
	  li        r7, 0
	  lwz       r3, 0x4C(r31)
	  stb       r0, 0x2B9(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r0, 0x2BE(r3)
	  lfs       f0, -0x558C(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x3C4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x3E540
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3E524
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1688
	  lwz       r6, 0x4C(r31)
	  li        r4, 0xB
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1E79C
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3A674
	  lwz       r3, 0x4C(r31)
	  bl        -0xF294
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x584
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDAC6C

	.loc_0x584:
	  lwz       r0, 0x20C(r1)
	  lfd       f31, 0x200(r1)
	  lfd       f30, 0x1F8(r1)
	  lfd       f29, 0x1F0(r1)
	  lfd       f28, 0x1E8(r1)
	  lfd       f27, 0x1E0(r1)
	  lfd       f26, 0x1D8(r1)
	  lfd       f25, 0x1D0(r1)
	  lfd       f24, 0x1C8(r1)
	  lfd       f23, 0x1C0(r1)
	  lfd       f22, 0x1B8(r1)
	  lwz       r31, 0x1B4(r1)
	  lwz       r30, 0x1B0(r1)
	  lwz       r29, 0x1AC(r1)
	  addi      r1, r1, 0x208
	  mtlr      r0
	  blr

	.loc_0x5C8:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void SnakeAi::dieState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015E6BC
 * Size:	0001B0
 */
void SnakeAi::struggleState()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stw       r31, 0x104(r1)
	  mr        r31, r3
	  lwz       r3, 0x4C(r3)
	  lwz       r5, 0x224(r3)
	  lwz       r4, 0x2EC(r3)
	  lwz       r0, 0x4E0(r5)
	  cmpw      r4, r0
	  bge-      .loc_0x17C
	  bl        -0xF518
	  lwz       r8, 0x4C(r31)
	  li        r9, 0
	  lwz       r7, 0x224(r8)
	  lwz       r6, 0x4C0(r7)
	  cmpw      r3, r6
	  blt-      .loc_0x50
	  lwz       r9, 0x4E0(r7)
	  b         .loc_0x140

	.loc_0x50:
	  lwz       r5, 0x4B0(r7)
	  cmpw      r3, r5
	  ble-      .loc_0x140
	  sub       r4, r3, r5
	  lwz       r0, 0x4D0(r7)
	  sub       r3, r6, r5
	  lfd       f6, -0x5580(r2)
	  xoris     r4, r4, 0x8000
	  lwz       r5, 0x4E0(r7)
	  xoris     r3, r3, 0x8000
	  stw       r4, 0xFC(r1)
	  lis       r4, 0x4330
	  lfs       f7, -0x5560(r2)
	  stw       r3, 0xF4(r1)
	  xoris     r0, r0, 0x8000
	  xoris     r3, r5, 0x8000
	  lfs       f3, -0x558C(r2)
	  stw       r4, 0xF8(r1)
	  lfs       f5, -0x5570(r2)
	  stw       r4, 0xF0(r1)
	  lfd       f1, 0xF8(r1)
	  lfd       f0, 0xF0(r1)
	  fsubs     f2, f1, f6
	  stw       r3, 0xEC(r1)
	  fsubs     f0, f0, f6
	  lfs       f1, -0x5590(r2)
	  stw       r0, 0xE4(r1)
	  fdivs     f4, f2, f0
	  stw       r4, 0xE8(r1)
	  stw       r4, 0xE0(r1)
	  lfd       f2, 0xE8(r1)
	  lfd       f0, 0xE0(r1)
	  fmuls     f8, f7, f4
	  fsubs     f0, f0, f6
	  fsubs     f2, f2, f6
	  fsubs     f4, f8, f3
	  fmuls     f0, f0, f8
	  fmuls     f3, f5, f2
	  fsubs     f2, f8, f7
	  fmuls     f1, f1, f4
	  fmuls     f3, f3, f8
	  fmuls     f0, f2, f0
	  fmuls     f1, f2, f1
	  fmuls     f2, f4, f3
	  fsubs     f0, f1, f0
	  fadds     f0, f2, f0
	  fadds     f0, f5, f0
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stfd      f0, 0xD8(r1)
	  cmpwi     r0, 0
	  lwz       r0, 0xDC(r1)
	  bge-      .loc_0x12C
	  b         .loc_0x140

	.loc_0x12C:
	  cmpw      r0, r5
	  ble-      .loc_0x138
	  b         .loc_0x13C

	.loc_0x138:
	  mr        r5, r0

	.loc_0x13C:
	  mr        r9, r5

	.loc_0x140:
	  addi      r4, r8, 0x2EC
	  lwz       r0, 0x2EC(r8)
	  cmpw      r0, r9
	  blt-      .loc_0x19C
	  lwz       r0, 0x4E0(r7)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xBC
	  stw       r0, 0x0(r4)
	  li        r4, -0x1
	  bl        -0x3F894
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F600
	  b         .loc_0x19C

	.loc_0x17C:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xB4
	  li        r4, -0x1
	  bl        -0x3F8B8
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F624

	.loc_0x19C:
	  lwz       r0, 0x10C(r1)
	  lwz       r31, 0x104(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SnakeAi::chaseState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SnakeAi::attackState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SnakeAi::eatState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void SnakeAi::waitState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SnakeAi::gointoState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void SnakeAi::underState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015E86C
 * Size:	00143C
 */
void SnakeAi::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x3A8(r1)
	  stw       r31, 0x3A4(r1)
	  mr        r31, r3
	  stw       r30, 0x3A0(r1)
	  lwz       r4, 0x4C(r3)
	  lfs       f0, 0x300(r4)
	  addi      r5, r4, 0x300
	  stfs      f0, 0x94(r4)
	  lfs       f0, 0x304(r4)
	  lwz       r4, 0x4C(r31)
	  stfs      f0, 0x98(r4)
	  lfs       f0, 0x8(r5)
	  lwz       r4, 0x4C(r31)
	  stfs      f0, 0x9C(r4)
	  bl        -0x3254
	  mr        r3, r31
	  bl        -0x3158
	  lwz       r3, 0x4C(r31)
	  lfs       f0, -0x5590(r2)
	  lfs       f1, 0x2C0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x64
	  bl        -0x10384

	.loc_0x64:
	  lwz       r3, 0x4C(r31)
	  lwz       r0, 0x2E4(r3)
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x1424
	  lis       r4, 0x802D
	  subi      r4, r4, 0x620
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1424
	  li        r30, 0
	  stb       r30, 0x2B8(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r30, 0x2B9(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r30, 0x2BE(r3)
	  lwz       r4, 0x4C(r31)
	  lfs       f1, -0x5590(r2)
	  lwz       r3, 0x3CC(r4)
	  lfs       f0, 0x30(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x1424
	  lfs       f0, 0x94(r4)
	  addi      r3, r4, 0x94
	  li        r4, 0x1
	  stfs      f0, 0x390(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x394(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x398(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x390(r1)
	  lfs       f2, 0x398(r1)
	  bl        -0xF6A5C
	  stfs      f1, 0x394(r1)
	  addi      r5, r1, 0x390
	  li        r4, 0x3C
	  lwz       r3, 0x4C(r31)
	  li        r6, 0
	  li        r7, 0
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x3E1B4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x390
	  li        r4, 0x3B
	  li        r6, 0
	  li        r7, 0
	  bl        0x3E19C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x390
	  li        r4, 0x3A
	  li        r6, 0
	  li        r7, 0
	  bl        0x3E184
	  lwz       r3, 0x4C(r31)
	  addi      r4, r1, 0x390
	  lfs       f1, -0x5558(r2)
	  li        r5, 0x1
	  bl        -0x108B8
	  lwz       r3, 0x30F8(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x30F8(r13)
	  lwz       r3, 0x4C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1424
	  mr        r3, r31
	  bl        -0x338
	  lwz       r3, 0x4C(r31)
	  lfs       f0, -0x5590(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x204
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x388
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x3FAAC
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F888
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x16CC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB018
	  b         .loc_0x1424

	.loc_0x204:
	  bl        -0xFADC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C8
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x380
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x3FB1C
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F8F8
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x165C
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3E054
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3E038
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1E2BC
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3AB54
	  b         .loc_0x1424

	.loc_0x2C8:
	  lwz       r3, 0x4C(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1424
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        -0x20A8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F8
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        -0x2318

	.loc_0x2F8:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x314
	  lfs       f1, -0x5590(r2)
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xC18
	  b         .loc_0x1424

	.loc_0x314:
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x6
	  li        r30, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x374
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x3FC18
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F9F4
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x318(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x558C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x154C
	  b         .loc_0x1424
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x5590(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x3E8
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x36C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x3FC90
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FA6C
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x14E8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB1FC
	  b         .loc_0x1424

	.loc_0x3E8:
	  bl        -0xFCC0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4AC
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x364
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x3FD00
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FADC
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1478
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3DE70
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3DE54
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1E0D8
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3AD38
	  b         .loc_0x1424

	.loc_0x4AC:
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        -0x227C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4CC
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        -0x24EC

	.loc_0x4CC:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x56C
	  lwz       r3, 0x4C(r31)
	  bl        -0xFB74
	  cmpwi     r3, 0
	  ble-      .loc_0x558
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x1
	  li        r30, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x35C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x5
	  stb       r30, 0x2BD(r6)
	  bl        -0x3FDE8
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FBC4
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5578(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1388
	  lwz       r3, 0x4C(r31)
	  bl        -0xF9E4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB3BC
	  b         .loc_0x1424

	.loc_0x558:
	  lfs       f1, -0x5590(r2)
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xE70
	  b         .loc_0x1424

	.loc_0x56C:
	  mr        r3, r31
	  bl        -0x1478
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5EC
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x354
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  bl        -0x3FE80
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FC5C
	  lwz       r3, 0x4C(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3CC(r3)
	  lfs       f1, 0x420(r4)
	  bl        0x12F4
	  lwz       r3, 0x4C(r31)
	  bl        -0xFA78
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB450
	  b         .loc_0x1424

	.loc_0x5EC:
	  mr        r3, r31
	  bl        -0x1870
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x66C
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x2
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x34C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  bl        -0x3FF00
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FCDC
	  lwz       r3, 0x4C(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3CC(r3)
	  lfs       f1, 0x420(r4)
	  bl        0x1274
	  lwz       r3, 0x4C(r31)
	  bl        -0xFAF8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB4D0
	  b         .loc_0x1424

	.loc_0x66C:
	  mr        r3, r31
	  bl        -0x11F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x6
	  li        r30, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x344
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x3FF80
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FD5C
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x318(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x558C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x11E4
	  b         .loc_0x1424
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x5590(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x750
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x33C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x3FFF8
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FDD4
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1180
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB564
	  b         .loc_0x1424

	.loc_0x750:
	  bl        -0x10028
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x814
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x334
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x40068
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FE44
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1110
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3DB08
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3DAEC
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1DD70
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3B0A0
	  b         .loc_0x1424

	.loc_0x814:
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        -0x25E4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x834
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        -0x2854

	.loc_0x834:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8D4
	  lwz       r3, 0x4C(r31)
	  bl        -0xFEDC
	  cmpwi     r3, 0
	  ble-      .loc_0x8C0
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x1
	  li        r30, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x32C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x5
	  stb       r30, 0x2BD(r6)
	  bl        -0x40150
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FF2C
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5578(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1020
	  lwz       r3, 0x4C(r31)
	  bl        -0xFD4C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB724
	  b         .loc_0x1424

	.loc_0x8C0:
	  lfs       f1, -0x5590(r2)
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0x11D8
	  b         .loc_0x1424

	.loc_0x8D4:
	  mr        r3, r31
	  bl        -0x17E0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x954
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x324
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  bl        -0x401E8
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3FFC4
	  lwz       r3, 0x4C(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3CC(r3)
	  lfs       f1, 0x420(r4)
	  bl        0xF8C
	  lwz       r3, 0x4C(r31)
	  bl        -0xFDE0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB7B8
	  b         .loc_0x1424

	.loc_0x954:
	  mr        r3, r31
	  bl        -0x1BD8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9D4
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x2
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x31C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  bl        -0x40268
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40044
	  lwz       r3, 0x4C(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3CC(r3)
	  lfs       f1, 0x420(r4)
	  bl        0xF0C
	  lwz       r3, 0x4C(r31)
	  bl        -0xFE60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB838
	  b         .loc_0x1424

	.loc_0x9D4:
	  mr        r3, r31
	  bl        -0x1558
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x6
	  li        r30, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x314
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x402E8
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x400C4
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x318(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x558C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xE7C
	  b         .loc_0x1424
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x5590(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xAB8
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x30C
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x40360
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x4013C
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xE18
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDB8CC
	  b         .loc_0x1424

	.loc_0xAB8:
	  bl        -0x10390
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB7C
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x304
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x403D0
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x401AC
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xDA8
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D7A0
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D784
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1DA08
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3B408
	  b         .loc_0x1424

	.loc_0xB7C:
	  lwz       r3, 0x4C(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1424
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4C(r31)
	  addi      r3, r1, 0x2F8
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x4048C
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40268
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x318(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x558C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xCD8
	  b         .loc_0x1424
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x5590(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xC5C
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2F0
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x40504
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x402E0
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xC74
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDBA70
	  b         .loc_0x1424

	.loc_0xC5C:
	  bl        -0x10534
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD20
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2E8
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x40574
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40350
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xC04
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D5FC
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D5E0
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1D864
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3B5AC
	  b         .loc_0x1424

	.loc_0xD20:
	  lwz       r3, 0x4C(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1424
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4C(r31)
	  addi      r3, r1, 0x2DC
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x40630
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x4040C
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x318(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x558C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xB34
	  b         .loc_0x1424
	  bl        -0x10428
	  cmpwi     r3, 0
	  ble-      .loc_0xDBC
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4C(r31)
	  lfs       f1, -0x5574(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x2D0(r4)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2D0(r4)
	  b         .loc_0xDD4

	.loc_0xDBC:
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D0(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D0(r4)

	.loc_0xDD4:
	  lwz       r3, 0x4C(r31)
	  lfs       f0, -0x5590(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xE4C
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2D4
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x406F4
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x404D0
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xA84
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDBC60
	  b         .loc_0x1424

	.loc_0xE4C:
	  bl        -0x10724
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF10
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2CC
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x40764
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40540
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0xA14
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D40C
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D3F0
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1D674
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3B79C
	  b         .loc_0x1424

	.loc_0xF10:
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0xF24
	  li        r0, 0x1
	  b         .loc_0xF28

	.loc_0xF24:
	  li        r0, 0

	.loc_0xF28:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xF9C
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x5
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2C4
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x4
	  stb       r0, 0x2BD(r6)
	  bl        -0x40834
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40610
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5578(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x944
	  lwz       r3, 0x4C(r31)
	  bl        -0x10428
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDBE00
	  b         .loc_0x1424

	.loc_0xF9C:
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0x2D0(r4)
	  lfs       f0, 0x430(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xFBC
	  li        r0, 0x1
	  b         .loc_0xFC0

	.loc_0xFBC:
	  li        r0, 0

	.loc_0xFC0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x107C
	  li        r0, 0x7
	  stw       r0, 0x2E8(r4)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4C(r31)
	  addi      r3, r1, 0x2BC
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stb       r0, 0x2BE(r6)
	  bl        -0x408D0
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x406AC
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x8A8
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D2A0
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D284
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x6
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1D508
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3B908
	  b         .loc_0x1424

	.loc_0x107C:
	  mr        r3, r31
	  bl        -0x1F88
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10FC
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2B4
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  bl        -0x40990
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x4076C
	  lwz       r3, 0x4C(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3CC(r3)
	  lfs       f1, 0x420(r4)
	  bl        0x7E4
	  lwz       r3, 0x4C(r31)
	  bl        -0x10588
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDBF60
	  b         .loc_0x1424

	.loc_0x10FC:
	  mr        r3, r31
	  bl        -0x2380
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x4C(r31)
	  li        r4, 0x2
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2AC
	  lwz       r6, 0x4C(r31)
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  bl        -0x40A10
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x407EC
	  lwz       r3, 0x4C(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3CC(r3)
	  lfs       f1, 0x420(r4)
	  bl        0x764
	  lwz       r3, 0x4C(r31)
	  bl        -0x10608
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDBFE0
	  b         .loc_0x1424
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x5590(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x11F0
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x2A4
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x40A98
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40874
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x6E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDC004
	  b         .loc_0x1424

	.loc_0x11F0:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1424
	  li        r0, 0x8
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4C(r31)
	  addi      r3, r1, 0x298
	  li        r4, 0x6
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D8(r6)
	  bl        -0x40B04
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x408E0
	  lwz       r5, 0x4C(r31)
	  li        r4, 0xE0
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3D07C
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x556C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x658
	  stw       r30, 0xC(r31)
	  stw       r30, 0x8(r31)
	  lwz       r3, 0x4C(r31)
	  bl        -0x107B4
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r30, 0x2B8(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r30, 0x2B9(r3)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x3C4(r3)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x3D0(r4)
	  lwz       r0, 0x3D4(r4)
	  stw       r3, 0x300(r4)
	  stw       r0, 0x304(r4)
	  lwz       r0, 0x3D8(r4)
	  stw       r0, 0x308(r4)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x3D0(r4)
	  lwz       r0, 0x3D4(r4)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x3D8(r4)
	  stw       r0, 0x9C(r4)
	  b         .loc_0x1424
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x2D0(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D0(r3)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0x2D0(r4)
	  lfs       f0, 0x440(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1308
	  li        r0, 0x1
	  b         .loc_0x130C

	.loc_0x1308:
	  li        r0, 0

	.loc_0x130C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1424
	  lbz       r0, 0x3BC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x132C
	  mr        r3, r31
	  bl        -0x2E90
	  b         .loc_0x1334

	.loc_0x132C:
	  mr        r3, r31
	  bl        -0x2A88

	.loc_0x1334:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1424
	  addi      r3, r31, 0
	  li        r4, 0x9
	  bl        -0x1AC4
	  b         .loc_0x1424
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x5590(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x13C0
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x290
	  lwz       r6, 0x4C(r31)
	  li        r4, 0
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4C(r31)
	  stfs      f0, 0x2D0(r6)
	  bl        -0x40C68
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40A44
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x5560(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x510
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDC1D4
	  b         .loc_0x1424

	.loc_0x13C0:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1424
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4C(r31)
	  addi      r3, r1, 0x284
	  li        r4, 0x2
	  stb       r30, 0x2BD(r6)
	  bl        -0x40CCC
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x40AA8
	  lwz       r3, 0x4C(r31)
	  stw       r30, 0x318(r3)
	  lfs       f0, -0x5590(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D0(r3)
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x558C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x498

	.loc_0x1424:
	  lwz       r0, 0x3AC(r1)
	  lwz       r31, 0x3A4(r1)
	  lwz       r30, 0x3A0(r1)
	  addi      r1, r1, 0x3A8
	  mtlr      r0
	  blr
	*/
}
