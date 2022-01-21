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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800B7F64
 * Size:	000060
 */
ActEnter::ActEnter(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0xBE54
	  lis       r3, 0x802B
	  addi      r0, r3, 0x6558
	  stw       r0, 0x0(r31)
	  subi      r4, r13, 0x4A78
	  li        r0, -0x1
	  lfs       f0, -0x6E48(r2)
	  mr        r3, r31
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x20(r31)
	  stw       r4, 0x10(r31)
	  sth       r0, 0x8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B7FC4
 * Size:	0001F0
 */
void ActEnter::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x60(r1)
	  stb       r0, 0x2C(r3)
	  beq-      .loc_0x38
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x38
	  stw       r4, 0x18(r31)

	.loc_0x38:
	  mr        r3, r31
	  bl        .loc_0x1F0
	  lwz       r4, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  addi      r4, r4, 0x94
	  lfs       f0, -0x6E48(r2)
	  addi      r3, r3, 0x94
	  lfs       f4, 0x4(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x0(r3)
	  fsubs     f4, f4, f3
	  lfs       f3, 0x8(r4)
	  fsubs     f5, f2, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f1, f4, f4
	  fsubs     f3, f3, f2
	  fmuls     f2, f5, f5
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xEC
	  fsqrte    f1, f4
	  lfd       f3, -0x6E40(r2)
	  lfd       f2, -0x6E38(r2)
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
	  stfs      f0, 0x2C(r1)
	  lfs       f4, 0x2C(r1)

	.loc_0xEC:
	  lfs       f0, -0x6E30(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x13C
	  li        r0, 0
	  sth       r0, 0x14(r31)
	  li        r5, 0
	  lwz       r4, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  addi      r4, r4, 0x94
	  bl        0xEF54
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x158
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6E2C(r2)
	  lfs       f2, -0x6E28(r2)
	  addi      r3, r3, 0x2BC
	  bl        0x15724
	  li        r0, 0x1
	  sth       r0, 0x14(r31)
	  b         .loc_0x158

	.loc_0x13C:
	  li        r0, 0x1
	  sth       r0, 0x14(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6E2C(r2)
	  lfs       f2, -0x6E28(r2)
	  addi      r3, r3, 0x2BC
	  bl        0x156FC

	.loc_0x158:
	  lwz       r3, 0xC(r31)
	  bl        0xFD50
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1AC
	  lis       r3, 0x802B
	  lwz       r4, 0xC(r31)
	  subi      r0, r3, 0x3064
	  lfs       f0, -0x6E2C(r2)
	  stw       r0, 0x44(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2E74
	  stw       r4, 0x48(r1)
	  addi      r4, r1, 0x44
	  stw       r0, 0x44(r1)
	  stfs      f0, 0x4C(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x2AC(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x1AC:
	  addi      r3, r1, 0x34
	  li        r4, 0x2
	  bl        0x66DE0
	  addi      r30, r3, 0
	  addi      r3, r1, 0x3C
	  li        r4, 0x2
	  bl        0x66DD0
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x12840
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr

	.loc_0x1F0:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void ActEnter::routeMove()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800B81B4
 * Size:	0000CC
 */
void ActEnter::findLeg()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  lis       r31, 0x6261
	  addi      r4, r31, 0x7331
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  lwz       r3, 0x18(r3)
	  lwz       r3, 0x220(r3)
	  bl        -0x2EACC
	  stw       r3, 0x14(r1)
	  addi      r4, r31, 0x7332
	  lwz       r3, 0x18(r30)
	  lwz       r3, 0x220(r3)
	  bl        -0x2EAE0
	  stw       r3, 0x18(r1)
	  addi      r4, r31, 0x7333
	  lwz       r3, 0x18(r30)
	  lwz       r3, 0x220(r3)
	  bl        -0x2EAF4
	  stw       r3, 0x1C(r1)
	  bl        0x15FE64
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6E18(r2)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6E24(r2)
	  addi      r3, r1, 0x14
	  stw       r0, 0x28(r1)
	  lfs       f2, -0x6E2C(r2)
	  lfd       f1, 0x28(r1)
	  lfs       f0, -0x6E1C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6E20(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B8280
 * Size:	0000E8
 */
void ActEnter::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lhz       r0, 0x14(r3)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x50
	  lbz       r0, 0x306C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x50
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x6E10(r2)
	  lfs       f1, 0x94(r3)
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bgt-      .loc_0x50
	  lfs       f1, 0x98(r3)
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0

	.loc_0x50:
	  lhz       r0, 0x14(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xB8
	  bge-      .loc_0x6C
	  cmpwi     r0, 0
	  bge-      .loc_0x78
	  b         .loc_0xD0

	.loc_0x6C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xD0
	  b         .loc_0xC4

	.loc_0x78:
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6E2C(r2)
	  bl        0xF1E8
	  cmpwi     r3, 0
	  bne-      .loc_0xB0
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6E2C(r2)
	  lfs       f2, -0x6E28(r2)
	  addi      r3, r3, 0x2BC
	  bl        0x154F8
	  li        r0, 0x1
	  sth       r0, 0x14(r31)
	  li        r3, 0
	  b         .loc_0xD4

	.loc_0xB0:
	  li        r3, 0
	  b         .loc_0xD4

	.loc_0xB8:
	  mr        r3, r31
	  bl        0x84
	  b         .loc_0xD4

	.loc_0xC4:
	  mr        r3, r31
	  bl        0x224
	  b         .loc_0xD4

	.loc_0xD0:
	  li        r3, 0

	.loc_0xD4:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B8368
 * Size:	000058
 */
void ActEnter::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r4, 0x4(r5)
	  lwz       r3, 0x6C(r4)
	  cmpwi     r3, 0x34
	  bne-      .loc_0x44
	  lhz       r0, 0x14(r31)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x38
	  cmplwi    r0, 0x2
	  bne-      .loc_0x44

	.loc_0x38:
	  bl        -0x23968
	  li        r0, 0x1
	  stb       r0, 0x2C(r31)

	.loc_0x44:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B83C0
 * Size:	0001AC
 */
void ActEnter::gotoLeg()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r30, 0x58(r1)
	  lwz       r4, 0xC(r3)
	  lwz       r0, 0x158(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  li        r0, 0x2
	  sth       r0, 0x14(r31)
	  li        r5, 0xD9
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x18(r31)
	  bl        -0x2DE48
	  lwz       r5, 0xC(r31)
	  addi      r3, r1, 0x34
	  lfs       f0, -0x4A70(r13)
	  li        r4, 0x3E
	  stfsu     f0, 0x70(r5)
	  lfs       f0, -0x4A6C(r13)
	  stfs      f0, 0x4(r5)
	  lfs       f0, -0x4A68(r13)
	  stfs      f0, 0x8(r5)
	  lwz       r5, 0xC(r31)
	  lfs       f0, -0x4A64(r13)
	  stfsu     f0, 0xA4(r5)
	  lfs       f0, -0x4A60(r13)
	  stfs      f0, 0x4(r5)
	  lfs       f0, -0x4A5C(r13)
	  stfs      f0, 0x8(r5)
	  bl        0x66B18
	  addi      r30, r3, 0
	  addi      r3, r1, 0x3C
	  li        r4, 0x3E
	  bl        0x66B08
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x12578
	  li        r3, 0
	  b         .loc_0x194

	.loc_0xAC:
	  lbz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8
	  addi      r3, r4, 0x2BC
	  addi      r4, r4, 0x94
	  addi      r5, r31, 0x20
	  bl        0x153A8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xD8
	  li        r3, 0x1
	  b         .loc_0x194

	.loc_0xD8:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x20(r31)
	  stw       r0, 0x24(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x28(r31)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x1C(r31)
	  lfsu      f1, 0x4(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x48(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  lfs       f2, 0x50(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xAA8CC
	  lfs       f0, -0x6E48(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x180
	  lfs       f0, 0x48(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x50(r1)

	.loc_0x180:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x48
	  lfs       f1, -0x6E0C(r2)
	  bl        0x1388C
	  li        r3, 0

	.loc_0x194:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B856C
 * Size:	000234
 */
void ActEnter::climb()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stfd      f30, 0x118(r1)
	  stfd      f29, 0x110(r1)
	  stfd      f28, 0x108(r1)
	  stfd      f27, 0x100(r1)
	  stfd      f26, 0xF8(r1)
	  stfd      f25, 0xF0(r1)
	  stw       r31, 0xEC(r1)
	  mr        r31, r3
	  lwz       r4, 0xC(r3)
	  lwz       r0, 0x158(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x50
	  lfs       f1, 0x15C(r4)
	  lfs       f0, -0x6E08(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x60

	.loc_0x50:
	  lwz       r3, 0x18(r31)
	  bl        0x32C98
	  li        r3, 0x1
	  b         .loc_0x204

	.loc_0x60:
	  lbz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  li        r3, 0x1
	  b         .loc_0x204

	.loc_0x74:
	  lfs       f0, -0x6E04(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xBC
	  li        r0, 0
	  stb       r0, 0x409(r4)
	  lwz       r3, 0xC(r31)
	  lfs       f2, -0x6E2C(r2)
	  lfs       f0, 0x15C(r3)
	  lfs       f1, -0x6E00(r2)
	  fsubs     f2, f2, f0
	  lfs       f0, -0x6E48(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB0
	  fmr       f1, f0

	.loc_0xB0:
	  stfsu     f1, 0x7C(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f1, 0x8(r3)

	.loc_0xBC:
	  bl        0x15FA48
	  xoris     r0, r3, 0x8000
	  lwz       r4, 0xC(r31)
	  stw       r0, 0xE4(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x158(r4)
	  stw       r0, 0xE0(r1)
	  lfsu      f31, 0x2C4(r3)
	  lfd       f2, -0x6E18(r2)
	  lfd       f0, 0xE0(r1)
	  lfs       f1, -0x6E24(r2)
	  fsubs     f4, f0, f2
	  lfs       f3, -0x6E2C(r2)
	  lfs       f0, -0x6E0C(r2)
	  lfs       f2, -0x6DFC(r2)
	  fdivs     f4, f4, f1
	  lfs       f30, 0x4(r3)
	  lfs       f29, 0x8(r3)
	  lfs       f1, 0xA0(r4)
	  fmuls     f3, f3, f4
	  fsubs     f0, f3, f0
	  fmuls     f28, f2, f0
	  bl        0x1634D4
	  lwz       r3, 0xC(r31)
	  fmr       f27, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x163658
	  lfs       f6, -0x4A58(r13)
	  fmuls     f4, f27, f30
	  fmuls     f2, f27, f31
	  fmuls     f5, f6, f29
	  fmuls     f0, f1, f29
	  fmuls     f3, f1, f30
	  fsubs     f27, f5, f4
	  fsubs     f26, f2, f0
	  fmuls     f2, f6, f31
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fsubs     f25, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f25, f25
	  fadds     f1, f1, f0
	  bl        -0xAAA90
	  lfs       f0, -0x6E48(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x180
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x180:
	  lfs       f2, -0x6DF8(r2)
	  fmuls     f4, f27, f28
	  fmuls     f1, f26, f28
	  li        r3, 0
	  fmuls     f0, f31, f2
	  fmuls     f3, f30, f2
	  stfs      f4, 0x68(r1)
	  fmuls     f2, f29, f2
	  stfs      f0, 0x74(r1)
	  fmuls     f0, f25, f28
	  lfs       f4, 0x74(r1)
	  stfs      f4, 0x9C(r1)
	  stfs      f3, 0xA0(r1)
	  stfs      f2, 0xA4(r1)
	  lfs       f3, 0x9C(r1)
	  lfs       f2, 0x68(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x5C(r1)
	  lfs       f2, 0x5C(r1)
	  stfs      f2, 0xA8(r1)
	  lfs       f2, 0xA0(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xAC(r1)
	  lfs       f1, 0xA4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lwz       r5, 0xC(r31)
	  lwz       r4, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r4, 0x70(r5)
	  stw       r0, 0x74(r5)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x78(r5)

	.loc_0x204:
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  lfd       f30, 0x118(r1)
	  lfd       f29, 0x110(r1)
	  lfd       f28, 0x108(r1)
	  lfd       f27, 0x100(r1)
	  lfd       f26, 0xF8(r1)
	  lfd       f25, 0xF0(r1)
	  lwz       r31, 0xEC(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B87A0
 * Size:	000024
 */
void ActEnter::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0xC(r3)
	  bl        -0x27BC4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B87C4
 * Size:	000064
 */
ActEnter::~ActEnter()
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
	  addi      r0, r3, 0x6558
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0xB610
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x7165C

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
