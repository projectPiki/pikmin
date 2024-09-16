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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AC30C
 * Size:	000054
 */
ActBoMake::ActBoMake(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x17AAC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  addi      r3, r3, 0x5A50
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x64
	  addi      r3, r31, 0
	  stw       r0, 0x14(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC360
 * Size:	000040
 */
void ActBoMake::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x1C(r3)
	  beq-      .loc_0x2C
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x23
	  bne-      .loc_0x2C
	  stw       r4, 0x1C(r3)

	.loc_0x2C:
	  bl        0xB4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC3A0
 * Size:	0000A0
 */
int ActBoMake::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x1C(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x28
	  li        r3, 0x1
	  b         .loc_0x8C

	.loc_0x28:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x54
	  lwz       r4, 0xC(r31)
	  li        r0, 0
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0x8C

	.loc_0x54:
	  lhz       r0, 0x18(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x7C
	  bge-      .loc_0x88
	  cmpwi     r0, 0
	  bge-      .loc_0x70
	  b         .loc_0x88

	.loc_0x70:
	  mr        r3, r31
	  bl        0x90
	  b         .loc_0x8C

	.loc_0x7C:
	  mr        r3, r31
	  bl        0x264
	  b         .loc_0x8C

	.loc_0x88:
	  li        r3, 0

	.loc_0x8C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC440
 * Size:	000064
 */
void ActBoMake::initApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  sth       r0, 0x18(r3)
	  addi      r3, r1, 0xC
	  bl        0x72AF0
	  addi      r31, r3, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x72AE0
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1E550
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC4A4
 * Size:	00012C
 */
int ActBoMake::exeApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  lwz       r4, 0xC(r3)
	  lwz       r3, 0x1C(r3)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x34(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  lfs       f2, 0x3C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9E8D8
	  fmr       f30, f1
	  lfs       f0, -0x70D0(r2)
	  fcmpu     cr0, f0, f30
	  beq-      .loc_0xAC
	  lfs       f0, 0x34(r1)
	  fdivs     f0, f0, f30
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fdivs     f0, f0, f30
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fdivs     f0, f0, f30
	  stfs      f0, 0x3C(r1)

	.loc_0xAC:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1C(r31)
	  fmr       f31, f1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fsubs     f1, f30, f1
	  lfs       f0, -0x70CC(r2)
	  fsubs     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xFC
	  mr        r3, r31
	  bl        .loc_0x12C
	  li        r3, 0
	  b         .loc_0x110

	.loc_0xFC:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x34
	  lfs       f1, -0x70C8(r2)
	  bl        0x1F82C
	  li        r3, 0

	.loc_0x110:
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x12C:
	*/
}

/*
 * --INFO--
 * Address:	800AC5D0
 * Size:	0000B4
 */
void ActBoMake::initWork()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r3
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lwz       r5, 0x1C(r29)
	  lis       r3, 0x6365
	  addi      r4, r3, 0x6E74
	  lwz       r3, 0x220(r5)
	  bl        -0x22EFC
	  mr        r5, r3
	  lwz       r3, 0xC(r29)
	  lwz       r4, 0x1C(r29)
	  li        r6, -0x1
	  lfs       f1, -0x70D0(r2)
	  bl        -0x1BF6C
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x68
	  addi      r30, r30, 0x14

	.loc_0x68:
	  addi      r3, r1, 0x10
	  li        r4, 0x30
	  bl        0x72918
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x30
	  bl        0x72938
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1E374

	.loc_0x98:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC684
 * Size:	000008
 */
int ActBoMake::exeWork() { return 0; }

/*
 * --INFO--
 * Address:	800AC68C
 * Size:	000024
 */
void ActBoMake::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0xC(r3)
	  bl        -0x1BE24
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC6B0
 * Size:	000078
 */
void ActBoMake::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x20
	  bge-      .loc_0x68
	  b         .loc_0x68

	.loc_0x20:
	  lis       r4, 0x802B
	  lwz       r6, 0xC(r3)
	  subi      r0, r4, 0x3064
	  lfs       f0, -0x70C8(r2)
	  stw       r0, 0x10(r1)
	  lis       r4, 0x802B
	  addi      r5, r4, 0x10D8
	  stw       r6, 0x14(r1)
	  li        r0, 0
	  addi      r4, r1, 0x10
	  stw       r5, 0x10(r1)
	  stw       r0, 0x18(r1)
	  stfs      f0, 0x1C(r1)
	  lwz       r3, 0x1C(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC728
 * Size:	00006C
 */
ActBoMake::~ActBoMake()
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
	  beq-      .loc_0x50
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5A50
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x64
	  addi      r3, r30, 0
	  stw       r0, 0x14(r30)
	  li        r4, 0
	  bl        0x176A4
	  extsh.    r0, r31
	  ble-      .loc_0x50
	  mr        r3, r30
	  bl        -0x655C8

	.loc_0x50:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
