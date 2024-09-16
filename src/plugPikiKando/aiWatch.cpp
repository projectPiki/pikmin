#include "PikiAI.h"

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
 * Address:	800C2C54
 * Size:	000004
 */
void ActWatch::AnimListener::animationKeyUpdated(PaniAnimKeyEvent&) { }

/*
 * --INFO--
 * Address:	800C2C58
 * Size:	0000C4
 */
ActWatch::ActWatch(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r4
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        0x1150
	  lis       r3, 0x802B
	  lwz       r30, 0x8(r1)
	  addi      r0, r3, 0x7C8C
	  stw       r0, 0x0(r30)
	  li        r31, 0
	  stw       r31, 0x14(r30)
	  lfs       f0, -0x6AD8(r2)
	  stfs      f0, 0x28(r30)
	  stfs      f0, 0x24(r30)
	  stfs      f0, 0x20(r30)
	  lwz       r3, 0x14(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  bl        0x216B4
	  stw       r31, 0x14(r30)

	.loc_0x68:
	  li        r3, 0xC
	  bl        -0x7BCC0
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  lis       r4, 0x802B
	  subi      r0, r4, 0x246C
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x7D78
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x8(r1)
	  stw       r0, 0x4(r3)
	  stw       r29, 0x8(r3)

	.loc_0x9C:
	  lwz       r4, 0x8(r1)
	  stw       r3, 0x1C(r4)
	  mr        r3, r4
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C2D1C
 * Size:	000004
 */
void ActWatch::Initialiser::initialise(Action*) { }

/*
 * --INFO--
 * Address:	800C2D20
 * Size:	000148
 */
void ActWatch::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  mr.       r30, r4
	  stw       r29, 0x44(r1)
	  addi      r29, r3, 0
	  beq-      .loc_0x12C
	  bl        0x15532C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6AC0(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6AD0(r2)
	  stw       r0, 0x38(r1)
	  lfs       f1, -0x6AD4(r2)
	  lfd       f3, 0x38(r1)
	  lfs       f0, -0x6ACC(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r3, 0x34(r1)
	  addi      r0, r3, 0x32
	  stw       r0, 0x18(r29)
	  lwz       r3, 0x14(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  beq-      .loc_0x8C
	  bl        0x215CC
	  li        r0, 0
	  stw       r0, 0x14(r29)

	.loc_0x8C:
	  stw       r30, 0x14(r29)
	  lwz       r3, 0x14(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  bl        0x215A0

	.loc_0xA0:
	  addi      r3, r1, 0x20
	  li        r4, 0x3
	  bl        0x5C190
	  addi      r31, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x3
	  bl        0x5C180
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x7BF0
	  lwz       r3, 0xC(r29)
	  bl        0x7E1C
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x14
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x14(r1)
	  mr        r3, r30
	  lwz       r0, 0x18(r1)
	  stw       r4, 0x20(r29)
	  stw       r0, 0x24(r29)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x28(r29)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, -0x6AC8(r2)
	  lfs       f0, 0x24(r29)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0x24(r29)

	.loc_0x12C:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C2E68
 * Size:	000048
 */
void ActWatch::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x14(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  bl        0x214E4
	  li        r0, 0
	  stw       r0, 0x14(r31)

	.loc_0x2C:
	  lwz       r3, 0xC(r31)
	  bl        0x1682C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C2EB0
 * Size:	000038
 */
void ActWatch::getInfo(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x7C44
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x18(r3)
	  addi      r3, r4, 0
	  mr        r4, r0
	  bl        0x1536C4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C2EE8
 * Size:	00015C
 */
int ActWatch::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  mr        r30, r3
	  lwz       r31, 0x14(r3)
	  cmplwi    r31, 0
	  addi      r3, r31, 0
	  beq-      .loc_0x48
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x50

	.loc_0x48:
	  li        r3, 0x1
	  b         .loc_0x13C

	.loc_0x50:
	  lwz       r3, 0x18(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x18(r30)
	  bge-      .loc_0x68
	  li        r3, 0x2
	  b         .loc_0x13C

	.loc_0x68:
	  lwz       r3, 0xC(r30)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x9C(r31)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x4C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  lfs       f1, -0x6AD8(r2)
	  lfs       f30, 0x4C(r1)
	  lfs       f31, 0x54(r1)
	  fmr       f2, f1
	  fmr       f3, f30
	  fmr       f4, f31
	  bl        -0x8A974
	  lwz       r3, 0xC(r30)
	  fmr       f1, f30
	  lfs       f0, -0x4478(r13)
	  fmr       f2, f31
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4474(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4470(r13)
	  stfs      f0, 0x8(r3)
	  bl        0x158A34
	  lwz       r3, 0xC(r30)
	  lfs       f2, 0xA0(r3)
	  bl        -0x8AA1C
	  lfs       f0, -0x6AB8(r2)
	  lwz       r3, 0xC(r30)
	  fmuls     f1, f0, f1
	  lfs       f0, 0xA0(r3)
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r3)
	  lwz       r3, 0xC(r30)
	  lfs       f1, 0xA0(r3)
	  bl        -0x8AA6C
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  stfs      f1, 0xA0(r4)
	  lwz       r5, 0xC(r30)
	  lfs       f0, -0x446C(r13)
	  addi      r4, r5, 0x88
	  stfs      f0, 0x88(r5)
	  lfs       f0, 0xA0(r5)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4468(r13)
	  stfs      f0, 0x8(r4)

	.loc_0x13C:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3044
 * Size:	000064
 */
ActWatch::~ActWatch()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x48
	  lis       r3, 0x802B
	  addi      r0, r3, 0x7C8C
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0xD90
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x7BEDC

	.loc_0x48:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
