#include "zen/ogMap.h"
#include "std/Math.h"

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
 * Address:	80182DE0
 * Size:	0000D4
 */
void zen::ogScrMapMgr::start(s16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  sth       r4, 0x14(r3)
	  stw       r0, 0x0(r3)
	  lha       r0, 0x14(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xAC
	  lwz       r0, 0xC(r31)
	  lis       r3, 0x7069
	  addi      r4, r3, 0x6331
	  stw       r0, 0x4(r31)
	  li        r5, 0x1
	  lwz       r3, 0x4(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1C(r31)
	  lis       r4, 0x4330
	  lwz       r3, 0x1C(r31)
	  lfd       f1, -0x5080(r2)
	  lha       r0, 0x18(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x34(r1)
	  stw       r4, 0x30(r1)
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x24(r31)
	  lwz       r3, 0x1C(r31)
	  lha       r0, 0x1A(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x2C(r1)
	  stw       r4, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x28(r31)
	  lwz       r3, 0x10(r31)
	  bl        -0x2A64
	  b         .loc_0xB4

	.loc_0xAC:
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x4(r31)

	.loc_0xB4:
	  li        r0, 0
	  sth       r0, 0x2C(r31)
	  sth       r0, 0x2E(r31)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80182EB4
 * Size:	0001CC
 */
zen::ogScrMapMgr::ogScrMapMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  li        r3, 0xF8
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  bl        -0x13BED0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x88
	  addi      r29, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x3072C
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x14
	  addi      r3, r29, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2DAB0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r0, 0xEC(r30)
	  stw       r0, 0xF0(r30)
	  stw       r0, 0xF4(r30)

	.loc_0x88:
	  stw       r30, 0x8(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x4058
	  lwz       r3, 0x8(r31)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x2FCA8
	  li        r3, 0xF8
	  bl        -0x13BF5C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x114
	  addi      r29, r30, 0
	  addi      r3, r1, 0xC
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x306A0
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0xC
	  addi      r3, r29, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2DA24
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r0, 0xEC(r30)
	  stw       r0, 0xF0(r30)
	  stw       r0, 0xF4(r30)

	.loc_0x114:
	  stw       r30, 0xC(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x406C
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x2FC1C
	  lwz       r3, 0xC(r31)
	  lis       r4, 0x7478
	  addi      r4, r4, 0x3030
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x418
	  bl        -0x13C00C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x174
	  mr        r4, r29
	  bl        -0x2C94

	.loc_0x174:
	  stw       r30, 0x10(r31)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x7273
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r31)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  lfs       f0, -0x5078(r2)
	  stfs      f0, 0x18(r31)
	  stw       r0, 0x0(r31)
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
 * Address:	80183080
 * Size:	00029C
 */
void zen::ogScrMapMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x80(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x284

	.loc_0x2C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  bl        0x2FA8C
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x64
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x284

	.loc_0x64:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x7C
	  li        r0, 0x4
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x284

	.loc_0x7C:
	  cmpwi     r0, 0x4
	  bne-      .loc_0x94
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x284

	.loc_0x94:
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0xA8
	  li        r0, 0x2
	  stw       r0, 0x0(r30)

	.loc_0xA8:
	  lha       r0, 0x14(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x204
	  lwz       r3, 0x10(r30)
	  bl        -0x279C
	  lwz       r4, 0x10(r30)
	  lwz       r3, 0x20(r30)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lfs       f1, 0x18(r30)
	  lfs       f2, -0x5074(r2)
	  bl        .loc_0x29C
	  lfs       f0, -0x5070(r2)
	  fmuls     f1, f0, f1
	  bl        0x98B60
	  lfs       f0, -0x5074(r2)
	  lwz       r6, 0x1C(r30)
	  fadds     f0, f0, f1
	  lha       r5, 0x18(r6)
	  lha       r3, 0x1C(r6)
	  lha       r4, 0x1A(r6)
	  lha       r0, 0x1E(r6)
	  sub       r3, r3, r5
	  srawi     r3, r3, 0x1
	  stfs      f0, 0xC0(r6)
	  addze     r3, r3
	  sub       r0, r0, r4
	  stfs      f0, 0xC4(r6)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stfs      f0, 0xC8(r6)
	  extsh     r3, r3
	  extsh     r0, r0
	  lwz       r4, 0x1C(r30)
	  sth       r3, 0xB8(r4)
	  sth       r0, 0xBA(r4)
	  lfs       f1, 0x24(r30)
	  lfs       f0, 0x28(r30)
	  lwz       r3, 0x1C(r30)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x78(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x70(r1)
	  mtlr      r12
	  lwz       r4, 0x7C(r1)
	  lwz       r5, 0x74(r1)
	  blrl
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x1B0
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x506C(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r30)

	.loc_0x1B0:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x1CC
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x506C(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r30)

	.loc_0x1CC:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x1E8
	  lfs       f1, 0x28(r30)
	  lfs       f0, -0x506C(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r30)

	.loc_0x1E8:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x204
	  lfs       f1, 0x28(r30)
	  lfs       f0, -0x506C(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r30)

	.loc_0x204:
	  lwz       r3, 0x4(r30)
	  lha       r4, 0x2C(r30)
	  lwz       r12, 0x0(r3)
	  lha       r5, 0x2E(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x238
	  lha       r3, 0x2C(r30)
	  subi      r0, r3, 0x4
	  sth       r0, 0x2C(r30)

	.loc_0x238:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x250
	  lha       r3, 0x2C(r30)
	  addi      r0, r3, 0x4
	  sth       r0, 0x2C(r30)

	.loc_0x250:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x268
	  lha       r3, 0x2E(r30)
	  subi      r0, r3, 0x4
	  sth       r0, 0x2E(r30)

	.loc_0x268:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x280
	  lha       r3, 0x2E(r30)
	  addi      r0, r3, 0x4
	  sth       r0, 0x2E(r30)

	.loc_0x280:
	  lwz       r3, 0x0(r30)

	.loc_0x284:
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr

	.loc_0x29C:
	*/
}

/*
 * --INFO--
 * Address:	8018331C
 * Size:	000060
 */
void std::fmodf(f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  fmr       f31, f2
	  stfd      f30, 0x18(r1)
	  fmr       f30, f1
	  fabs      f1, f31
	  fabs      f0, f30
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x34
	  fmr       f1, f30
	  b         .loc_0x48

	.loc_0x34:
	  fdivs     f1, f30, f31
	  bl        0x920A0
	  bl        0x91FE8
	  fmuls     f0, f31, f1
	  fsubs     f1, f30, f0

	.loc_0x48:
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lfd       f30, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018337C
 * Size:	00008C
 */
void zen::ogScrMapMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  mr        r31, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x78
	  lfs       f1, -0x5068(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x5074(r2)
	  li        r4, 0
	  lfs       f3, -0x5064(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x2CDD4
	  addi      r3, r1, 0x10
	  bl        0x2CEDC
	  lwz       r3, 0x4(r31)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x2FAFC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0x78:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}
