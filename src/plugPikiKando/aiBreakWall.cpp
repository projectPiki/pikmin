#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AE13C
 * Size:	000070
 */
ActBreakWall::ActBreakWall(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x15C7C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  addi      r3, r3, 0x5E04
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x64
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  addi      r0, r3, 0x5D64
	  addi      r3, r31, 0
	  lfs       f0, -0x7050(r2)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x20(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE1AC
 * Size:	000154
 */
void ActBreakWall::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x1
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r0, 0x2
	  stwu      r1, -0x48(r1)
	  addi      r7, r6, 0
	  addi      r8, r6, 0
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  stb       r5, 0x31(r3)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)
	  lwz       r3, 0xC(r31)
	  stb       r5, 0x400(r3)
	  lwz       r3, 0x6C(r4)
	  cmpwi     r3, 0x16
	  beq-      .loc_0x5C
	  cmpwi     r3, 0x17
	  beq-      .loc_0x5C
	  mr        r8, r5

	.loc_0x5C:
	  rlwinm.   r0,r8,0,24,31
	  bne-      .loc_0x70
	  cmpwi     r3, 0x18
	  beq-      .loc_0x70
	  li        r7, 0

	.loc_0x70:
	  rlwinm.   r0,r7,0,24,31
	  bne-      .loc_0x84
	  cmpwi     r3, 0x19
	  beq-      .loc_0x84
	  li        r6, 0

	.loc_0x84:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x94
	  stw       r4, 0x18(r31)
	  b         .loc_0x9C

	.loc_0x94:
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x9C:
	  li        r0, 0
	  sth       r0, 0x1C(r31)
	  stb       r0, 0x32(r31)
	  lwz       r3, 0xC(r31)
	  stb       r0, 0x470(r3)
	  bl        0x169E14
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7040(r2)
	  stw       r0, 0x34(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7048(r2)
	  cmplwi    r31, 0
	  stw       r0, 0x30(r1)
	  lfs       f1, -0x704C(r2)
	  mr        r29, r31
	  lfd       f3, 0x30(r1)
	  lfs       f0, -0x7044(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stb       r0, 0x30(r31)
	  beq-      .loc_0x108
	  addi      r29, r29, 0x14

	.loc_0x108:
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x70C9C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  bl        0x70CBC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1C6F8
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE300
 * Size:	0000C4
 */
void ActBreakWall::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  bl        0x1A228
	  cmpwi     r3, 0x1A
	  beq-      .loc_0xA4
	  lwz       r31, 0x4(r30)
	  lwz       r0, 0x18(r28)
	  cmplw     r31, r0
	  bne-      .loc_0xA4
	  lhz       r0, 0x1C(r28)
	  cmplwi    r0, 0x1
	  beq-      .loc_0xA4
	  addi      r3, r1, 0x14
	  lwz       r4, 0x8(r30)
	  bl        -0x264BC
	  lis       r4, 0x6761
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x7465
	  bl        -0x6A38C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xA4
	  lwz       r4, 0x94(r29)
	  mr        r3, r28
	  lwz       r0, 0x98(r29)
	  stw       r4, 0x20(r28)
	  stw       r0, 0x24(r28)
	  lwz       r0, 0x9C(r29)
	  stw       r0, 0x28(r28)
	  bl        0x3E4

	.loc_0xA4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE3C4
 * Size:	000190
 */
void ActBreakWall::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4C
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  bge-      .loc_0x40
	  b         .loc_0x17C

	.loc_0x34:
	  cmpwi     r0, 0x8
	  beq-      .loc_0xB4
	  b         .loc_0x17C

	.loc_0x40:
	  li        r0, 0x1
	  stb       r0, 0x32(r31)
	  b         .loc_0x17C

	.loc_0x4C:
	  li        r0, 0
	  stb       r0, 0x32(r31)
	  b         .loc_0x17C

	.loc_0x58:
	  bl        0x169C54
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7040(r2)
	  stw       r0, 0x64(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7048(r2)
	  mr        r3, r31
	  stw       r0, 0x60(r1)
	  lfs       f1, -0x704C(r2)
	  lfd       f3, 0x60(r1)
	  lfs       f0, -0x7044(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stb       r0, 0x30(r31)
	  bl        0x3AC
	  li        r0, 0
	  stb       r0, 0x32(r31)
	  b         .loc_0x17C

	.loc_0xB4:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x17C
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0
	  ble-      .loc_0xE0
	  addi      r3, r3, 0x174
	  bl        -0x9040
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x17C

	.loc_0xE0:
	  lwz       r3, 0xC(r31)
	  lfsu      f2, 0x464(r3)
	  lfs       f1, -0x7050(r2)
	  stfs      f2, 0x48(r1)
	  lfs       f0, -0x704C(r2)
	  lfs       f2, 0x4(r3)
	  stfs      f2, 0x4C(r1)
	  lfs       f2, 0x8(r3)
	  stfs      f1, 0x24(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f1, 0x1C(r1)
	  stfs      f1, 0x30(r1)
	  stfs      f2, 0x50(r1)
	  stfs      f1, 0x2C(r1)
	  lwz       r0, 0x48(r1)
	  stfs      f1, 0x28(r1)
	  lwz       r3, 0x4C(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r3, 0x20(r1)
	  stw       r0, 0x24(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x18(r31)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x16
	  bne-      .loc_0x158
	  li        r3, 0xB
	  addi      r4, r1, 0x1C
	  bl        0x65DCC
	  b         .loc_0x17C

	.loc_0x158:
	  cmpwi     r0, 0x17
	  bne-      .loc_0x170
	  li        r3, 0xD
	  addi      r4, r1, 0x1C
	  bl        0x65DB4
	  b         .loc_0x17C

	.loc_0x170:
	  li        r3, 0xE
	  addi      r4, r1, 0x1C
	  bl        0x65DA4

	.loc_0x17C:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE554
 * Size:	000148
 */
void ActBreakWall::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x40

	.loc_0x38:
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x40:
	  lhz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x68
	  bge-      .loc_0x130
	  cmpwi     r0, 0
	  bge-      .loc_0x5C
	  b         .loc_0x130

	.loc_0x5C:
	  mr        r3, r31
	  bl        0x108
	  b         .loc_0x134

	.loc_0x68:
	  lwz       r3, 0xC(r31)
	  lfs       f3, 0x24(r31)
	  addi      r3, r3, 0x94
	  lfs       f1, 0x20(r31)
	  lfs       f2, 0x4(r3)
	  lfs       f0, 0x0(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x28(r31)
	  fsubs     f5, f1, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x7050(r2)
	  fsubs     f3, f2, f1
	  fmuls     f2, f5, f5
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x10C
	  fsqrte    f1, f4
	  lfd       f3, -0x7038(r2)
	  lfd       f2, -0x7030(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f4, 0x28(r1)

	.loc_0x10C:
	  lfs       f0, -0x7028(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x124
	  li        r0, 0
	  sth       r0, 0x1C(r31)
	  b         .loc_0x130

	.loc_0x124:
	  mr        r3, r31
	  bl        0x28C
	  b         .loc_0x134

	.loc_0x130:
	  li        r3, 0

	.loc_0x134:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE69C
 * Size:	000020
 */
void BuildingItem::isAlive()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x440(r3)
	  lwz       r3, 0x444(r3)
	  eqv       r0, r4, r3
	  subc      r3, r3, r4
	  rlwinm    r0,r0,1,31,31
	  addze     r3, r0
	  rlwinm    r3,r3,0,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE6BC
 * Size:	0000C8
 */
void ActBreakWall::gotoWall()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  lwz       r4, 0xC(r3)
	  lwz       r3, 0x18(r3)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x30(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA0AE8
	  lfs       f0, -0x7050(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xA0
	  lfs       f0, 0x30(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x38(r1)

	.loc_0xA0:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x30
	  lfs       f1, -0x704C(r2)
	  bl        0x1D670
	  lwz       r0, 0x4C(r1)
	  li        r3, 0
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE784
 * Size:	000090
 */
void ActBreakWall::initBreakWall()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  bl        0x1698D8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7040(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7048(r2)
	  mr        r3, r31
	  stw       r0, 0x18(r1)
	  lfs       f1, -0x704C(r2)
	  lfd       f3, 0x18(r1)
	  lfs       f0, -0x7044(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stb       r0, 0x30(r31)
	  bl        .loc_0x90
	  li        r0, 0x1
	  lis       r3, 0x803A
	  sth       r0, 0x1C(r31)
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x300(r3)
	  stw       r0, 0x2C(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x90:
	*/
}

/*
 * --INFO--
 * Address:	800AE814
 * Size:	0000F4
 */
void ActBreakWall::startWorkMotion()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  mr        r29, r3
	  lbz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xD8
	  lwz       r3, 0xC(r29)
	  bl        -0x245F8
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  addi      r3, r1, 0x38
	  lwz       r4, 0xC(r29)
	  bl        -0x245F0
	  lfs       f1, 0x3C(r1)
	  lfs       f0, -0x7024(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x98
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x64
	  addi      r30, r30, 0x14

	.loc_0x64:
	  addi      r3, r1, 0x28
	  li        r4, 0x13
	  bl        0x706D8
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x13
	  bl        0x706F8
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1C134
	  b         .loc_0xD8

	.loc_0x98:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0xA8
	  addi      r30, r30, 0x14

	.loc_0xA8:
	  addi      r3, r1, 0x18
	  li        r4, 0x30
	  bl        0x70694
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x30
	  bl        0x706B4
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1C0F0

	.loc_0xD8:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE908
 * Size:	0002E4
 */
void ActBreakWall::breakWall()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r30, 0x80(r1)
	  mr        r30, r3
	  stw       r29, 0x7C(r1)
	  stw       r28, 0x78(r1)
	  lbz       r3, 0x30(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  subi      r0, r3, 0x1
	  stb       r0, 0x30(r30)
	  lbz       r0, 0x30(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xF4
	  bne-      .loc_0xF4
	  lwz       r3, 0xC(r30)
	  bl        -0x24708
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  addi      r3, r1, 0x28
	  lwz       r4, 0xC(r30)
	  bl        -0x24700
	  lfs       f1, 0x2C(r1)
	  lfs       f0, -0x7024(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0x80
	  addi      r29, r29, 0x14

	.loc_0x80:
	  addi      r3, r1, 0x3C
	  li        r4, 0x13
	  bl        0x705C8
	  addi      r28, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x13
	  bl        0x705E8
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r28
	  bl        0x1C024
	  b         .loc_0xF4

	.loc_0xB4:
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0xC4
	  addi      r29, r29, 0x14

	.loc_0xC4:
	  addi      r3, r1, 0x4C
	  li        r4, 0x30
	  bl        0x70584
	  addi      r28, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x44
	  li        r4, 0x30
	  bl        0x705A4
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r28
	  bl        0x1BFE0

	.loc_0xF4:
	  li        r3, 0
	  b         .loc_0x2C4

	.loc_0xFC:
	  lis       r3, 0x803A
	  lwz       r5, 0x2C(r30)
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x300
	  lwz       r0, 0x300(r3)
	  lis       r4, 0x8889
	  lis       r3, 0x803A
	  sub       r5, r0, r5
	  addi      r5, r5, 0x3C
	  subi      r0, r4, 0x7777
	  mulhw     r0, r0, r5
	  add       r0, r0, r5
	  subi      r3, r3, 0x24E0
	  srawi     r0, r0, 0x5
	  lwz       r3, 0xA8(r3)
	  rlwinm    r4,r0,1,31,31
	  add       r4, r0, r4
	  lhz       r0, 0x26(r3)
	  mulli     r3, r4, 0x3C
	  cmplwi    r0, 0
	  sub       r3, r5, r3
	  bne-      .loc_0x158
	  li        r3, 0x1

	.loc_0x158:
	  cmpwi     r3, 0
	  ble-      .loc_0x288
	  lbz       r0, 0x32(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x288
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x7040(r2)
	  stw       r0, 0x74(r1)
	  lis       r28, 0x4330
	  lis       r4, 0x802B
	  lfs       f0, -0x7020(r2)
	  stw       r28, 0x70(r1)
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r30)
	  lfd       f1, 0x70(r1)
	  subi      r0, r4, 0x3064
	  stw       r0, 0x54(r1)
	  subi      r0, r3, 0x31FC
	  fsubs     f1, f1, f2
	  stw       r5, 0x58(r1)
	  li        r29, 0
	  addi      r4, r1, 0x54
	  fdivs     f0, f1, f0
	  stw       r0, 0x54(r1)
	  stfs      f0, 0x5C(r1)
	  stw       r29, 0x60(r1)
	  stb       r29, 0x64(r1)
	  stb       r29, 0x32(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x280
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x208
	  li        r3, 0x2
	  b         .loc_0x2C4

	.loc_0x208:
	  lbz       r3, 0x31(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x31(r30)
	  bl        0x169554
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7040(r2)
	  stw       r0, 0x74(r1)
	  lfs       f2, -0x7048(r2)
	  stw       r28, 0x70(r1)
	  lfs       f1, -0x704C(r2)
	  lfd       f3, 0x70(r1)
	  lfs       f0, -0x701C(r2)
	  fsubs     f3, f3, f4
	  lbz       r4, 0x31(r30)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r3, 0x6C(r1)
	  addi      r0, r3, 0x3
	  cmpw      r4, r0
	  blt-      .loc_0x280
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  lwz       r4, 0xC(r30)
	  stb       r29, 0x408(r4)
	  b         .loc_0x2C4

	.loc_0x280:
	  lwz       r0, 0x0(r31)
	  stw       r0, 0x2C(r30)

	.loc_0x288:
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lfs       f0, -0x4E28(r13)
	  stfsu     f0, 0x70(r4)
	  lfs       f0, -0x4E24(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4E20(r13)
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0xC(r30)
	  lfs       f0, -0x4E1C(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x4E18(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4E14(r13)
	  stfs      f0, 0x8(r4)

	.loc_0x2C4:
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  lwz       r28, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AEBEC
 * Size:	00001C
 */
void BuildingItem::isCompleted()
{
	/*
	.loc_0x0:
	  lwz       r5, 0x444(r3)
	  lwz       r0, 0x440(r3)
	  srawi     r3, r5, 0x1F
	  rlwinm    r4,r0,1,31,31
	  subc      r0, r5, r0
	  adde      r3, r3, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AEC08
 * Size:	000004
 */
void ActBreakWall::cleanup() { }

/*
 * --INFO--
 * Address:	800AEC0C
 * Size:	00006C
 */
ActBreakWall::~ActBreakWall()
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
	  addi      r3, r3, 0x5E04
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x64
	  addi      r3, r30, 0
	  stw       r0, 0x14(r30)
	  li        r4, 0
	  bl        0x151C0
	  extsh.    r0, r31
	  ble-      .loc_0x50
	  mr        r3, r30
	  bl        -0x67AAC

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

/*
 * --INFO--
 * Address:	800AEC78
 * Size:	000008
 */
void ActBreakWall::@20 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x14
	  b         -0x8B8
	*/
}
