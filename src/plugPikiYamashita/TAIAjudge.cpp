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
 * Address:	801AD094
 * Size:	000004
 */
void TAIAsearchWorkObject::start(Teki&) { }

/*
 * --INFO--
 * Address:	801AD098
 * Size:	000200
 */
void TAIAsearchWorkObject::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stmw      r25, 0x8C(r1)
	  mr        r29, r4
	  li        r30, 0
	  lwz       r4, 0x2C4(r4)
	  lwz       r31, 0x3020(r13)
	  lwz       r4, 0x84(r4)
	  addi      r3, r31, 0
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f31, 0x3C(r4)
	  stw       r0, 0x4BC(r29)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f30, -0x49E0(r2)
	  addi      r27, r3, 0
	  addi      r28, r29, 0x94
	  b         .loc_0x180

	.loc_0x68:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA4

	.loc_0x8C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xA4:
	  stfs      f30, 0x70(r1)
	  mr        r26, r3
	  stfs      f30, 0x6C(r1)
	  stfs      f30, 0x68(r1)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x0(r28)
	  lfs       f4, 0x9C(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r28)
	  lfs       f2, 0x98(r3)
	  lfs       f1, 0x4(r28)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x54(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f3, 0x70(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f0, 0x6C(r1)
	  lfs       f2, 0x70(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19F564
	  fmr       f29, f1
	  fcmpo     cr0, f29, f31
	  bge-      .loc_0x164
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r25, 0
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x150
	  mr        r3, r26
	  bl        -0x10EF34
	  cmpwi     r3, 0
	  blt-      .loc_0x150
	  li        r25, 0x1

	.loc_0x150:
	  rlwinm.   r0,r25,0,24,31
	  beq-      .loc_0x164
	  fmr       f31, f29
	  stw       r26, 0x4BC(r29)
	  li        r30, 0x1

	.loc_0x164:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x180:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1A8
	  li        r0, 0x1
	  b         .loc_0x1D4

	.loc_0x1A8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1D0
	  li        r0, 0x1
	  b         .loc_0x1D4

	.loc_0x1D0:
	  li        r0, 0

	.loc_0x1D4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x68
	  mr        r3, r30
	  lmw       r25, 0x8C(r1)
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD298
 * Size:	000084
 */
void TAIAlessLife::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x2C4(r4)
	  li        r4, 0
	  lwz       r3, 0x84(r5)
	  lwz       r3, 0x4(r3)
	  bl        -0x8ADF4
	  lfs       f0, 0x58(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  fdivs     f31, f0, f1
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0x64
	  li        r3, 0x1
	  b         .loc_0x68

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD31C
 * Size:	000084
 */
void TAIAmoreLife::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x2C4(r4)
	  li        r4, 0
	  lwz       r3, 0x84(r5)
	  lwz       r3, 0x4(r3)
	  bl        -0x8AE78
	  lfs       f0, 0x58(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  fdivs     f31, f0, f1
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x64
	  li        r3, 0x1
	  b         .loc_0x68

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD3A0
 * Size:	00006C
 */
void TAIAjudgeOptionalRange::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x54

	.loc_0x50:
	  li        r3, 0x1

	.loc_0x54:
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
 * Address:	801AD40C
 * Size:	000068
 */
void TAIAjudgeOptionalRange::setTargetPositionCreature(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r3, 0x418(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  addi      r4, r3, 0x94
	  addi      r3, r1, 0x10
	  bl        -0x905B4
	  lwz       r4, 0x0(r3)
	  li        r5, 0x1
	  lwz       r0, 0x4(r3)
	  stw       r4, 0x388(r31)
	  stw       r0, 0x38C(r31)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x390(r31)
	  b         .loc_0x50

	.loc_0x4C:
	  li        r5, 0

	.loc_0x50:
	  lwz       r0, 0x2C(r1)
	  mr        r3, r5
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD474
 * Size:	0000D0
 */
void TAIAinsideOptionalRange::judgement(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x94(r4)
	  lfs       f0, 0x388(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x38C(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19F8BC
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  mfcr      r0
	  rlwinm    r3,r0,1,31,31
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD544
 * Size:	0000D0
 */
void TAIAoutsideOptionalRange::judgement(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x94(r4)
	  lfs       f0, 0x388(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x38C(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19F98C
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  mfcr      r0
	  rlwinm    r3,r0,2,31,31
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD614
 * Size:	0001D8
 */
void TAIAcheckInsideRangePiki::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stmw      r25, 0x64(r1)
	  addi      r25, r3, 0
	  addi      r26, r4, 0
	  li        r28, 0
	  li        r27, 0
	  lwz       r30, 0x3068(r13)
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f30, -0x49E0(r2)
	  addi      r29, r3, 0
	  addi      r31, r26, 0x94
	  b         .loc_0x138

	.loc_0x50:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x74
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x8C

	.loc_0x74:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
	  stfs      f30, 0x48(r1)
	  stfs      f30, 0x44(r1)
	  stfs      f30, 0x40(r1)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x0(r31)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x4(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x30(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x30(r1)
	  stfs      f0, 0x40(r1)
	  stfs      f1, 0x44(r1)
	  stfs      f3, 0x48(r1)
	  lfs       f1, 0x40(r1)
	  lfs       f0, 0x44(r1)
	  lfs       f2, 0x48(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19FAC4
	  mr        r3, r25
	  fmr       f31, f1
	  lwz       r12, 0x4(r25)
	  mr        r4, r26
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0x11C
	  addi      r27, r27, 0x1

	.loc_0x11C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x138:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x160
	  li        r0, 0x1
	  b         .loc_0x18C

	.loc_0x160:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x188
	  li        r0, 0x1
	  b         .loc_0x18C

	.loc_0x188:
	  li        r0, 0

	.loc_0x18C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x50
	  mr        r3, r25
	  lwz       r12, 0x4(r25)
	  mr        r4, r26
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  cmpw      r27, r3
	  blt-      .loc_0x1B8
	  li        r28, 0x1

	.loc_0x1B8:
	  mr        r3, r28
	  lmw       r25, 0x64(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD7EC
 * Size:	000008
 */
void TAIAcheckInsideRangePiki::getPikiMax(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD7F4
 * Size:	000008
 */
void TAIAcheckInsideRangePiki::getRange(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD7FC
 * Size:	000134
 */
void TAIAinsideTerritoryRangeNavi::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  li        r30, 0
	  stw       r29, 0x74(r1)
	  addi      r29, r4, 0
	  lwz       r3, 0x3120(r13)
	  bl        -0x9645C
	  mr.       r31, r3
	  beq-      .loc_0x114
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x60
	  bl        -0x909B4
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  stw       r4, 0x388(r29)
	  stw       r0, 0x38C(r29)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x390(r29)
	  lwz       r3, 0x2C8(r29)
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  lfsu      f1, 0x10(r3)
	  lfs       f0, 0x388(r29)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r29)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x38C(r29)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x50(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f1, 0x58(r1)
	  stfs      f3, 0x5C(r1)
	  lfs       f1, 0x54(r1)
	  lfs       f0, 0x58(r1)
	  lfs       f2, 0x5C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19FC7C
	  lwz       r3, 0x2C4(r29)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x114
	  lwz       r3, 0x418(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  beq-      .loc_0xFC
	  bl        -0xC9580
	  li        r0, 0
	  stw       r0, 0x418(r29)

	.loc_0xFC:
	  stw       r31, 0x418(r29)
	  lwz       r3, 0x418(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x110
	  bl        -0xC95AC

	.loc_0x110:
	  li        r30, 0x1

	.loc_0x114:
	  mr        r3, r30
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD930
 * Size:	0000FC
 */
void TAIAoutsideTerritoryRangeNavi::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  li        r31, 0
	  stw       r30, 0x70(r1)
	  addi      r30, r4, 0
	  lwz       r3, 0x3120(r13)
	  bl        -0x9658C
	  cmplwi    r3, 0
	  beq-      .loc_0xE0
	  addi      r4, r3, 0x94
	  addi      r3, r1, 0x60
	  bl        -0x90AE4
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  stw       r4, 0x388(r30)
	  stw       r0, 0x38C(r30)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x390(r30)
	  lwz       r3, 0x2C8(r30)
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  lfsu      f1, 0x10(r3)
	  lfs       f0, 0x388(r30)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r30)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x38C(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x50(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f1, 0x58(r1)
	  stfs      f3, 0x5C(r1)
	  lfs       f1, 0x54(r1)
	  lfs       f0, 0x58(r1)
	  lfs       f2, 0x5C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19FDAC
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE0
	  li        r31, 0x1

	.loc_0xE0:
	  mr        r3, r31
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ADA2C
 * Size:	00008C
 */
void TAIAvisibleNavi::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r3, 0x3120(r13)
	  bl        -0x96684
	  addi      r31, r3, 0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x66D44
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  beq-      .loc_0x54
	  bl        -0xC9708
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x54:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  bl        -0xC9734

	.loc_0x68:
	  li        r3, 0x1
	  b         .loc_0x74

	.loc_0x70:
	  li        r3, 0

	.loc_0x74:
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
 * Address:	801ADAB8
 * Size:	000164
 */
void TAIAvisiblePiki::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  addi      r27, r4, 0
	  li        r28, 0
	  lwz       r30, 0x3068(r13)
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0xF0

	.loc_0x38:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x60
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x7C

	.loc_0x60:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x7C:
	  addi      r4, r31, 0
	  addi      r3, r27, 0
	  bl        -0x66E28
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD4
	  lwz       r0, 0x184(r31)
	  cmplw     r0, r27
	  beq-      .loc_0xD4
	  lwz       r3, 0x418(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  beq-      .loc_0xB8
	  bl        -0xC97F8
	  li        r0, 0
	  stw       r0, 0x418(r27)

	.loc_0xB8:
	  stw       r31, 0x418(r27)
	  lwz       r3, 0x418(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  bl        -0xC9824

	.loc_0xCC:
	  li        r28, 0x1
	  b         .loc_0x14C

	.loc_0xD4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0xF0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x118
	  li        r0, 0x1
	  b         .loc_0x144

	.loc_0x118:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x140
	  li        r0, 0x1
	  b         .loc_0x144

	.loc_0x140:
	  li        r0, 0

	.loc_0x144:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38

	.loc_0x14C:
	  mr        r3, r28
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void TAIAattackableTarget::checkDist(Teki&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801ADC1C
 * Size:	000080
 */
void TAIAattackableTarget::checkAngle(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  addi      r3, r31, 0
	  lwz       r4, 0x418(r4)
	  addi      r4, r4, 0x94
	  bl        -0x6693C
	  lwz       r3, 0x2C4(r31)
	  lfs       f2, -0x1CA8(r13)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x49DC(r2)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x24(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x58
	  li        r0, 0x1
	  b         .loc_0x5C

	.loc_0x58:
	  li        r0, 0

	.loc_0x5C:
	  neg       r3, r0
	  lwz       r31, 0x54(r1)
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r0,0,24,31
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ADC9C
 * Size:	00014C
 */
void TAIAattackableTarget::judge(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  addi      r6, r1, 0x60
	  addi      r5, r1, 0x5C
	  stw       r31, 0x8C(r1)
	  addi      r3, r1, 0x70
	  li        r31, 0
	  stw       r30, 0x88(r1)
	  stw       r29, 0x84(r1)
	  addi      r29, r4, 0
	  addi      r4, r1, 0x58
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x78(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x9C(r29)
	  lfs       f0, 0x390(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x98(r29)
	  lfs       f0, 0x38C(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x5C(r1)
	  lfs       f1, 0x94(r29)
	  lfs       f0, 0x388(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r1)
	  bl        -0x150684
	  lfs       f1, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A00F4
	  lwz       r3, 0x2C4(r29)
	  fmr       f31, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x8B878
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0xC4
	  li        r0, 0x1
	  b         .loc_0xC8

	.loc_0xC4:
	  mr        r0, r31

	.loc_0xC8:
	  cmpwi     r0, 0
	  beq-      .loc_0x128
	  lwz       r3, 0x2C4(r29)
	  li        r4, 0x9
	  lwz       r30, 0x418(r29)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x8B8AC
	  fmr       f31, f1
	  addi      r4, r30, 0x94
	  addi      r3, r29, 0
	  bl        -0x66A90
	  lfs       f2, -0x1CA8(r13)
	  lfs       f0, -0x49DC(r2)
	  fmuls     f2, f31, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x118
	  li        r0, 0x1
	  b         .loc_0x11C

	.loc_0x118:
	  li        r0, 0

	.loc_0x11C:
	  cmpwi     r0, 0
	  beq-      .loc_0x128
	  li        r31, 0x1

	.loc_0x128:
	  mr        r3, r31
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ADDE8
 * Size:	000098
 */
void TAIAattackableTarget::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  li        r31, 0x1
	  stw       r30, 0x28(r1)
	  mr        r30, r4
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  lwz       r4, 0x418(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x78
	  addi      r4, r4, 0x94
	  addi      r3, r1, 0x10
	  bl        -0x90FA0
	  lwz       r5, 0x0(r3)
	  mr        r4, r30
	  lwz       r0, 0x4(r3)
	  stw       r5, 0x388(r30)
	  stw       r0, 0x38C(r30)
	  lwz       r0, 0x8(r3)
	  mr        r3, r29
	  stw       r0, 0x390(r30)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x78
	  li        r31, 0

	.loc_0x78:
	  mr        r3, r31
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
 * Address:	801ADE80
 * Size:	00004C
 */
void TAIAunvisibleTarget::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x418(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x38
	  addi      r3, r4, 0
	  mr        r4, r0
	  bl        -0x6718C
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,5,31
	  mr        r3, r0
	  b         .loc_0x3C

	.loc_0x38:
	  li        r3, 0x1

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ADECC
 * Size:	0000A0
 */
void TAIAstickingPiki::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  addi      r4, r1, 0x18
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  stw       r0, 0x18(r1)
	  addi      r0, r5, 0x6964
	  lis       r5, 0x802D
	  stw       r0, 0x18(r1)
	  subi      r0, r5, 0x2A4C
	  stw       r0, 0x18(r1)
	  stw       r30, 0x1C(r1)
	  bl        -0x65ABC
	  addi      r31, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  cmpw      r31, r3
	  blt-      .loc_0x80
	  li        r3, 0x1
	  b         .loc_0x84

	.loc_0x80:
	  li        r3, 0

	.loc_0x84:
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
 * Address:	801ADF6C
 * Size:	000008
 */
void TAIAstickingPiki::getPikiNum(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ADF74
 * Size:	000058
 */
void TAIAdistanceTarget::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lfs       f1, 0x8(r3)
	  bl        0x6DB3C
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC(r30)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ADFCC
 * Size:	0000E8
 */
void TAIAdistanceTarget::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x418(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0xCC
	  addi      r4, r4, 0x94
	  addi      r3, r1, 0x3C
	  bl        -0x9117C
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  stw       r4, 0x388(r31)
	  stw       r0, 0x38C(r31)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x390(r31)
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x388(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x38C(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A0440
	  lfs       f0, 0xC(r30)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm    r3,r0,2,31,31
	  b         .loc_0xD0

	.loc_0xCC:
	  li        r3, 0x1

	.loc_0xD0:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE0B4
 * Size:	000014
 */
void TAIAcheckTurnAngle::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0xA0(r4)
	  stfs      f0, 0x494(r4)
	  lfs       f0, -0x49E0(r2)
	  stfs      f0, 0x478(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE0C8
 * Size:	0000D4
 */
void TAIAcheckTurnAngle::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f2, 0xA0(r4)
	  li        r5, 0
	  lfs       f1, 0x494(r4)
	  lfs       f0, -0x49E0(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  fmr       f2, f1
	  bge-      .loc_0x28
	  fneg      f1, f2
	  b         .loc_0x2C

	.loc_0x28:
	  fmr       f1, f2

	.loc_0x2C:
	  lfs       f0, -0x49D8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x58
	  lfs       f0, -0x49E0(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x50
	  lfs       f0, -0x49D4(r2)
	  fsubs     f2, f2, f0
	  b         .loc_0x58

	.loc_0x50:
	  lfs       f0, -0x49D4(r2)
	  fadds     f2, f0, f2

	.loc_0x58:
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x94
	  lfs       f1, -0x49E0(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x84
	  lfs       f0, 0x478(r4)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x94
	  stfs      f1, 0x478(r4)
	  b         .loc_0x94

	.loc_0x84:
	  lfs       f0, 0x478(r4)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x94
	  stfs      f1, 0x478(r4)

	.loc_0x94:
	  lfs       f0, 0x478(r4)
	  fadds     f0, f0, f2
	  stfs      f0, 0x478(r4)
	  lfs       f0, 0xA0(r4)
	  stfs      f0, 0x494(r4)
	  lfs       f1, 0x478(r4)
	  lfs       f0, -0x49E0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xBC
	  fneg      f1, f1

	.loc_0xBC:
	  lfs       f0, 0x8(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xCC
	  li        r5, 0x1

	.loc_0xCC:
	  mr        r3, r5
	  blr
	*/
}
