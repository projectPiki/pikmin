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
 * Address:	800B92C0
 * Size:	000080
 */
ActMine::ActMine(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh.    r0, r4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x30
	  addi      r0, r31, 0x28
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x28(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  li        r5, 0x1
	  bl        0xAAD4
	  lis       r3, 0x802B
	  addi      r3, r3, 0x6850
	  stw       r3, 0x0(r31)
	  addi      r5, r3, 0x68
	  addi      r0, r31, 0x28
	  lwz       r4, 0x14(r31)
	  mr        r3, r31
	  stw       r5, 0x0(r4)
	  lwz       r4, 0x14(r31)
	  sub       r0, r0, r4
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B9340
 * Size:	000064
 */
void ActMine::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)
	  lwz       r3, 0x6C(r4)
	  cmpwi     r3, 0xD
	  beq-      .loc_0x38
	  bl        -0x2493C

	.loc_0x38:
	  stw       r31, 0x18(r30)
	  mr        r3, r30
	  bl        .loc_0x64
	  li        r0, 0x2
	  sth       r0, 0x1C(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x64:
	*/
}

/*
 * --INFO--
 * Address:	800B93A4
 * Size:	000090
 */
void ActMine::initWatch()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r3
	  addi      r30, r29, 0
	  beq-      .loc_0x28
	  lwz       r30, 0x14(r29)

	.loc_0x28:
	  addi      r3, r1, 0xC
	  li        r4, 0x41
	  bl        0x65B84
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x41
	  bl        0x65BA4
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x115E0
	  lwz       r3, 0xC(r29)
	  lfs       f0, -0x4960(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x495C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4958(r13)
	  stfs      f0, 0x8(r3)
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
 * Address:	........
 * Size:	000008
 */
void ActMine::exeWatch()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void ActMine::exeGo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void ActMine::initMine()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void ActMine::initGo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800B9434
 * Size:	00014C
 */
void ActMine::exeMine()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  lfs       f0, -0x4954(r13)
	  lwz       r3, 0xC(r3)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4950(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x494C(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x24(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x134

	.loc_0x48:
	  lwz       r3, 0x18(r30)
	  bl        0x3E5D4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x60
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x60:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0xE
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x124
	  mr        r3, r31
	  lwz       r4, 0xC(r30)
	  lwz       r12, 0x0(r31)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r30)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x14(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2E2C
	  stw       r5, 0x18(r1)
	  addi      r4, r1, 0x14
	  addi      r3, r31, 0
	  stw       r0, 0x14(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x110
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x110:
	  lwz       r4, 0xC(r30)
	  li        r0, 0x6
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0x134

	.loc_0x124:
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)

	.loc_0x134:
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
 * Address:	800B9580
 * Size:	000200
 */
int ActMine::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x30
	  li        r3, 0x1
	  b         .loc_0x1E4

	.loc_0x30:
	  bl        0x3E474
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x50
	  lwz       r4, 0xC(r31)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1E4

	.loc_0x50:
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x2AC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  li        r0, 0x6
	  stb       r0, 0x400(r4)
	  li        r3, 0x2
	  b         .loc_0x1E4

	.loc_0x70:
	  lhz       r0, 0x1C(r31)
	  li        r3, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1DC
	  bge-      .loc_0x90
	  cmpwi     r0, 0
	  bge-      .loc_0xA0
	  b         .loc_0x1E4

	.loc_0x90:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x1E4
	  li        r3, 0
	  b         .loc_0x1E4

	.loc_0xA0:
	  lwz       r3, 0x18(r31)
	  addi      r8, r4, 0x94
	  lfs       f0, 0x9C(r4)
	  addi      r6, r1, 0x1C
	  lfs       f1, 0x9C(r3)
	  addi      r7, r3, 0x94
	  fsubs     f0, f1, f0
	  addi      r5, r1, 0x18
	  addi      r4, r1, 0x14
	  addi      r3, r1, 0x48
	  stfs      f0, 0x1C(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r1)
	  bl        -0x82550
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x40(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xABA68
	  lfs       f0, -0x6D78(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x15C
	  lfs       f0, 0x38(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x40(r1)

	.loc_0x15C:
	  lfs       f0, -0x6D74(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C4
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x178
	  lwz       r29, 0x14(r31)

	.loc_0x178:
	  addi      r3, r1, 0x28
	  li        r4, 0x4
	  bl        0x65858
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x4
	  bl        0x65878
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x112B4
	  lwz       r3, 0xC(r31)
	  bl        0x114E0
	  li        r0, 0
	  stb       r0, 0x24(r31)
	  li        r0, 0x1
	  sth       r0, 0x1C(r31)
	  b         .loc_0x1D4

	.loc_0x1C4:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x38
	  lfs       f1, -0x6D70(r2)
	  bl        0x12688

	.loc_0x1D4:
	  li        r3, 0
	  b         .loc_0x1E4

	.loc_0x1DC:
	  mr        r3, r31
	  bl        -0x32C

	.loc_0x1E4:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B9780
 * Size:	000004
 */
void ActMine::cleanup()
{
}

/*
 * --INFO--
 * Address:	800B9784
 * Size:	0000C0
 */
void ActMine::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x90
	  bge-      .loc_0xA4
	  cmpwi     r0, 0
	  bge-      .loc_0x38
	  b         .loc_0xA4

	.loc_0x38:
	  lhz       r0, 0x1C(r29)
	  cmplwi    r0, 0x2
	  bne-      .loc_0xA4
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x54
	  lwz       r30, 0x14(r29)

	.loc_0x54:
	  addi      r3, r1, 0x18
	  li        r4, 0x2
	  bl        0x65778
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x10
	  li        r4, 0x2
	  bl        0x65798
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x111D4
	  li        r0, 0
	  sth       r0, 0x1C(r29)
	  b         .loc_0xA4

	.loc_0x90:
	  lhz       r0, 0x1C(r29)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xA4
	  li        r0, 0x1
	  stb       r0, 0x24(r29)

	.loc_0xA4:
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
 * Address:	800B9844
 * Size:	000080
 */
ActMine::~ActMine()
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
	  beq-      .loc_0x64
	  lis       r3, 0x802B
	  addi      r3, r3, 0x6850
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x28
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0xA574
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x726F8

	.loc_0x64:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
