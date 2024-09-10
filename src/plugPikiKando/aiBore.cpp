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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AA51C
 * Size:	000108
 */
ActFreeSelect::ActFreeSelect(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  mr        r31, r4
	  stw       r3, 0x10(r1)
	  lwz       r3, 0x10(r1)
	  bl        0x19894
	  lis       r3, 0x802B
	  lwz       r4, 0x10(r1)
	  addi      r0, r3, 0x5930
	  lis       r3, 0x802B
	  stw       r0, 0x0(r4)
	  addi      r0, r3, 0x55A4
	  stw       r0, 0x10(r4)
	  li        r3, 0x2C
	  bl        -0x6355C
	  mr.       r30, r3
	  beq-      .loc_0x5C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x186E4

	.loc_0x5C:
	  li        r3, 0x30
	  bl        -0x63578
	  mr.       r29, r3
	  beq-      .loc_0x7C
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0xDFC

	.loc_0x7C:
	  li        r3, 0x24
	  bl        -0x63598
	  mr.       r28, r3
	  beq-      .loc_0x9C
	  addi      r3, r28, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0x12BC

	.loc_0x9C:
	  li        r3, 0x30
	  bl        -0x635B8
	  mr.       r27, r3
	  beq-      .loc_0xBC
	  addi      r3, r27, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0x146C

	.loc_0xBC:
	  stw       r27, 0x8(r1)
	  li        r0, 0
	  addi      r5, r30, 0
	  crclr     6, 0x6
	  stw       r0, 0xC(r1)
	  mr        r7, r29
	  lwz       r3, 0x10(r1)
	  addi      r9, r28, 0
	  li        r4, 0x4
	  li        r6, 0
	  li        r8, 0
	  li        r10, 0
	  bl        0x19D68
	  lmw       r27, 0x1C(r1)
	  lwz       r3, 0x10(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA624
 * Size:	0000F4
 */
void ActFreeSelect::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r30, 0xC(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0x2C
	  addi      r30, r30, 0x2B8

	.loc_0x2C:
	  addi      r3, r1, 0x20
	  li        r4, 0x3
	  bl        0x74900
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x3
	  bl        0x74920
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x2035C
	  lwz       r4, 0x2DEC(r13)
	  li        r3, 0x1
	  lfs       f1, -0x7108(r2)
	  li        r0, -0x1
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r29)
	  stb       r3, 0x18(r29)
	  sth       r0, 0x8(r29)
	  bl        0x16D9CC
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x70F0(r2)
	  stw       r0, 0x34(r1)
	  lis       r3, 0x4330
	  lfs       f4, -0x7100(r2)
	  li        r0, 0
	  stw       r3, 0x30(r1)
	  lfs       f3, -0x7104(r2)
	  lfd       f0, 0x30(r1)
	  lfs       f1, -0x70F8(r2)
	  fsubs     f5, f0, f2
	  lfs       f2, -0x70FC(r2)
	  lfs       f0, -0x70F4(r2)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fsubs     f1, f3, f1
	  fmuls     f1, f2, f1
	  fdivs     f0, f1, f0
	  stfs      f0, 0x1C(r29)
	  stb       r0, 0x19(r29)
	  stb       r0, 0x1A(r29)
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
 * Address:	800AA718
 * Size:	000084
 */
void ActFreeSelect::finishRest()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lha       r0, 0x8(r3)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x30
	  bge-      .loc_0x68
	  cmpwi     r0, 0x2
	  bge-      .loc_0x4C
	  b         .loc_0x68

	.loc_0x30:
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  li        r4, 0x1
	  lwzx      r3, r3, r0
	  stb       r4, 0x18(r3)
	  stb       r4, 0x19(r31)
	  b         .loc_0x70

	.loc_0x4C:
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  bl        0x1180
	  li        r0, 0x1
	  stb       r0, 0x19(r31)
	  b         .loc_0x70

	.loc_0x68:
	  li        r0, 0x1
	  stb       r0, 0x1A(r31)

	.loc_0x70:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA79C
 * Size:	000108
 */
void ActFreeSelect::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lbz       r0, 0x1A(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x28
	  li        r3, 0x2
	  b         .loc_0xF4

	.loc_0x28:
	  lbz       r0, 0x19(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x58
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF4

	.loc_0x58:
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4F50(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4F4C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4F48(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xF0
	  mr        r3, r31
	  bl        0xDC
	  b         .loc_0xF0

	.loc_0xB0:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  beq-      .loc_0xF0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
	  li        r3, 0

	.loc_0xF4:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA8A4
 * Size:	000004
 */
void ActFreeSelect::cleanup() { }

/*
 * --INFO--
 * Address:	800AA8A8
 * Size:	000078
 */
void ActFreeSelect::procTargetMsg(Piki*, MsgTarget*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  li        r0, 0
	  stb       r0, 0x18(r3)
	  sth       r0, 0x8(r3)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwz       r4, 0x4(r5)
	  add       r3, r3, r0
	  bl        0x19444
	  b         .loc_0x68

	.loc_0x40:
	  lha       r0, 0x8(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x68
	  lwz       r4, 0x4(r3)
	  rlwinm    r3,r0,3,0,28
	  li        r0, 0
	  lwzx      r3, r4, r3
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x1C(r3)

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA920
 * Size:	0002D8
 */
void ActFreeSelect::determine()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  bl        0x16D728
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7100(r2)
	  stw       r0, 0x58(r1)
	  lfs       f1, -0x7104(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, -0x70F8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7108(r2)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  b         .loc_0x2B0

	.loc_0x7C:
	  lis       r3, 0x8022
	  addi      r6, r3, 0x2440
	  lwz       r5, 0x0(r6)
	  addi      r3, r1, 0x34
	  lwz       r0, 0x4(r6)
	  li        r4, 0x4
	  stw       r5, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  bl        0x6B724
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x2AC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  li        r3, 0

	.loc_0xE4:
	  li        r30, 0
	  stb       r30, 0x18(r31)
	  extsh     r0, r3
	  cmpwi     r3, 0x1
	  sth       r0, 0x8(r31)
	  li        r4, 0
	  beq-      .loc_0x29C
	  bge-      .loc_0x29C
	  cmpwi     r3, 0
	  bge-      .loc_0x110
	  b         .loc_0x29C

	.loc_0x110:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x6C(r12)
	  addi      r4, r4, 0x94
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x13C:
	  lwz       r3, 0x30AC(r13)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0xC(r31)
	  mr        r29, r0
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3168(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x1B8
	  mr        r3, r0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1BC

	.loc_0x1B8:
	  li        r3, 0

	.loc_0x1BC:
	  cmplwi    r3, 0
	  beq-      .loc_0x1CC
	  mr        r4, r3
	  b         .loc_0x29C

	.loc_0x1CC:
	  cmplwi    r30, 0
	  beq-      .loc_0x200
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r30)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9CED4
	  fmr       f31, f1
	  b         .loc_0x204

	.loc_0x200:
	  lfs       f31, -0x70E8(r2)

	.loc_0x204:
	  cmplwi    r29, 0
	  beq-      .loc_0x238
	  lfs       f1, 0x70(r29)
	  lfs       f0, 0x74(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9CF0C
	  fmr       f30, f1
	  b         .loc_0x23C

	.loc_0x238:
	  lfs       f30, -0x70E8(r2)

	.loc_0x23C:
	  cmplwi    r28, 0
	  beq-      .loc_0x26C
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x74(r28)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r28)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9CF44
	  b         .loc_0x270

	.loc_0x26C:
	  lfs       f1, -0x70E8(r2)

	.loc_0x270:
	  fcmpo     cr0, f31, f30
	  ble-      .loc_0x288
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x288
	  mr        r4, r30
	  b         .loc_0x29C

	.loc_0x288:
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x298
	  mr        r4, r29
	  b         .loc_0x29C

	.loc_0x298:
	  mr        r4, r28

	.loc_0x29C:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        0x19158

	.loc_0x2B0:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AABF8
 * Size:	000104
 */
ActBoreSelect::ActBoreSelect(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  mr        r31, r4
	  stw       r3, 0x10(r1)
	  lwz       r3, 0x10(r1)
	  bl        0x191B8
	  lis       r3, 0x802B
	  lwz       r4, 0x10(r1)
	  addi      r0, r3, 0x58A8
	  stw       r0, 0x0(r4)
	  subi      r0, r13, 0x4F44
	  li        r3, 0x2C
	  stw       r0, 0x10(r4)
	  bl        -0x63C34
	  mr.       r30, r3
	  beq-      .loc_0x58
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1800C

	.loc_0x58:
	  li        r3, 0x30
	  bl        -0x63C50
	  mr.       r29, r3
	  beq-      .loc_0x78
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0x724

	.loc_0x78:
	  li        r3, 0x24
	  bl        -0x63C70
	  mr.       r28, r3
	  beq-      .loc_0x98
	  addi      r3, r28, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0xBE4

	.loc_0x98:
	  li        r3, 0x30
	  bl        -0x63C90
	  mr.       r27, r3
	  beq-      .loc_0xB8
	  addi      r3, r27, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0xD94

	.loc_0xB8:
	  stw       r27, 0x8(r1)
	  li        r0, 0
	  addi      r5, r30, 0
	  crclr     6, 0x6
	  stw       r0, 0xC(r1)
	  mr        r7, r29
	  lwz       r3, 0x10(r1)
	  addi      r9, r28, 0
	  li        r4, 0x4
	  li        r6, 0
	  li        r8, 0
	  li        r10, 0
	  bl        0x19690
	  lmw       r27, 0x1C(r1)
	  lwz       r3, 0x10(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AACFC
 * Size:	0000F4
 */
void ActBoreSelect::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r30, 0xC(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0x2C
	  addi      r30, r30, 0x2B8

	.loc_0x2C:
	  addi      r3, r1, 0x20
	  li        r4, 0x3
	  bl        0x74228
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x3
	  bl        0x74248
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1FC84
	  lwz       r4, 0x2DEC(r13)
	  li        r3, 0x1
	  lfs       f1, -0x7108(r2)
	  li        r0, -0x1
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r29)
	  stb       r3, 0x18(r29)
	  sth       r0, 0x8(r29)
	  bl        0x16D2F4
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x70F0(r2)
	  stw       r0, 0x34(r1)
	  lis       r3, 0x4330
	  lfs       f4, -0x7100(r2)
	  li        r0, 0
	  stw       r3, 0x30(r1)
	  lfs       f3, -0x7104(r2)
	  lfd       f0, 0x30(r1)
	  lfs       f1, -0x70F8(r2)
	  fsubs     f5, f0, f2
	  lfs       f2, -0x70FC(r2)
	  lfs       f0, -0x70F4(r2)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fsubs     f1, f3, f1
	  fmuls     f1, f2, f1
	  fdivs     f0, f1, f0
	  stfs      f0, 0x1C(r29)
	  stb       r0, 0x19(r29)
	  stb       r0, 0x1A(r29)
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
 * Address:	800AADF0
 * Size:	00000C
 */
void ActBoreSelect::stop()
{
	// Generated from stb r0, 0x1A(r3)
	_1A = 1;
}

/*
 * --INFO--
 * Address:	800AADFC
 * Size:	000184
 */
void ActBoreSelect::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x170

	.loc_0x44:
	  lwz       r4, 0xC(r31)
	  lfs       f0, -0x7104(r2)
	  lwz       r3, 0x504(r4)
	  lfs       f1, 0x738(r3)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x68
	  lbz       r0, 0x1A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8

	.loc_0x68:
	  lwz       r0, 0x39C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x7C
	  li        r3, 0x2
	  b         .loc_0x170

	.loc_0x7C:
	  lha       r0, 0x8(r31)
	  cmpwi     r0, 0x3
	  bne-      .loc_0xA8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  li        r5, 0x1
	  lwzx      r4, r3, r0
	  li        r3, 0
	  stb       r5, 0x18(r4)
	  stb       r5, 0x19(r31)
	  b         .loc_0x170

	.loc_0xA8:
	  cmpwi     r0, 0x2
	  bne-      .loc_0xD0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  bl        0xA38
	  li        r0, 0x1
	  stb       r0, 0x19(r31)
	  li        r3, 0
	  b         .loc_0x170

	.loc_0xD0:
	  li        r3, 0x2
	  b         .loc_0x170

	.loc_0xD8:
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C
	  lfs       f0, -0x4F3C(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x4F38(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x4F34(r13)
	  stfs      f0, 0xAC(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x16C
	  mr        r3, r31
	  bl        0x198
	  b         .loc_0x16C

	.loc_0x12C:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  beq-      .loc_0x16C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x16C:
	  li        r3, 0

	.loc_0x170:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AAF80
 * Size:	000004
 */
void ActBoreSelect::cleanup() { }

/*
 * --INFO--
 * Address:	800AAF84
 * Size:	000078
 */
void ActBoreSelect::procTargetMsg(Piki*, MsgTarget*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  li        r0, 0
	  stb       r0, 0x18(r3)
	  sth       r0, 0x8(r3)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwz       r4, 0x4(r5)
	  add       r3, r3, r0
	  bl        0x18D68
	  b         .loc_0x68

	.loc_0x40:
	  lha       r0, 0x8(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x68
	  lwz       r4, 0x4(r3)
	  rlwinm    r3,r0,3,0,28
	  li        r0, 0
	  lwzx      r3, r4, r3
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x1C(r3)

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AAFFC
 * Size:	0000BC
 */
void ActBoreSelect::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x4C
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  addi      r4, r29, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA0

	.loc_0x4C:
	  lwz       r3, 0x4(r5)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x60
	  b         .loc_0xA0

	.loc_0x60:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x70
	  addi      r30, r30, 0x2B8

	.loc_0x70:
	  addi      r3, r1, 0x14
	  li        r4, 0x3
	  bl        0x73EE4
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x3
	  bl        0x73F04
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        0x1F940

	.loc_0xA0:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB0B8
 * Size:	0002D8
 */
void ActBoreSelect::determine()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  bl        0x16CF90
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7100(r2)
	  stw       r0, 0x58(r1)
	  lfs       f1, -0x7104(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, -0x70F8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7108(r2)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  b         .loc_0x2B0

	.loc_0x7C:
	  lis       r3, 0x8022
	  addi      r6, r3, 0x2460
	  lwz       r5, 0x0(r6)
	  addi      r3, r1, 0x34
	  lwz       r0, 0x4(r6)
	  li        r4, 0x4
	  stw       r5, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  bl        0x6AF8C
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x2AC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  li        r3, 0

	.loc_0xE4:
	  li        r30, 0
	  stb       r30, 0x18(r31)
	  extsh     r0, r3
	  cmpwi     r3, 0x1
	  sth       r0, 0x8(r31)
	  li        r4, 0
	  beq-      .loc_0x29C
	  bge-      .loc_0x29C
	  cmpwi     r3, 0
	  bge-      .loc_0x110
	  b         .loc_0x29C

	.loc_0x110:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x6C(r12)
	  addi      r4, r4, 0x94
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x13C:
	  lwz       r3, 0x30AC(r13)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0xC(r31)
	  mr        r29, r0
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3168(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x1B8
	  mr        r3, r0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1BC

	.loc_0x1B8:
	  li        r3, 0

	.loc_0x1BC:
	  cmplwi    r3, 0
	  beq-      .loc_0x1CC
	  mr        r4, r3
	  b         .loc_0x29C

	.loc_0x1CC:
	  cmplwi    r30, 0
	  beq-      .loc_0x200
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r30)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D66C
	  fmr       f31, f1
	  b         .loc_0x204

	.loc_0x200:
	  lfs       f31, -0x70E8(r2)

	.loc_0x204:
	  cmplwi    r29, 0
	  beq-      .loc_0x238
	  lfs       f1, 0x70(r29)
	  lfs       f0, 0x74(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D6A4
	  fmr       f30, f1
	  b         .loc_0x23C

	.loc_0x238:
	  lfs       f30, -0x70E8(r2)

	.loc_0x23C:
	  cmplwi    r28, 0
	  beq-      .loc_0x26C
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x74(r28)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r28)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D6DC
	  b         .loc_0x270

	.loc_0x26C:
	  lfs       f1, -0x70E8(r2)

	.loc_0x270:
	  fcmpo     cr0, f31, f30
	  ble-      .loc_0x288
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x288
	  mr        r4, r30
	  b         .loc_0x29C

	.loc_0x288:
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x298
	  mr        r4, r29
	  b         .loc_0x29C

	.loc_0x298:
	  mr        r4, r28

	.loc_0x29C:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        0x189C0

	.loc_0x2B0:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB390
 * Size:	000080
 */
ActBoreTalk::ActBoreTalk(Piki*)
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
	  bl        0x18A04
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5804
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
 * Address:	800AB410
 * Size:	0000E8
 */
void ActBoreTalk::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r3, 0
	  stb       r0, 0x24(r3)
	  stw       r0, 0x18(r3)
	  lwz       r3, 0xC(r3)
	  addi      r30, r3, 0x1B8
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0
	  cmpwi     r4, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x80

	.loc_0x6C:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  cmplwi    r29, 0
	  stw       r3, 0x1C(r29)
	  mr        r30, r29
	  beq-      .loc_0x94
	  lwz       r30, 0x14(r29)

	.loc_0x94:
	  addi      r3, r1, 0x1C
	  li        r4, 0xB
	  bl        0x73AAC
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x24
	  li        r4, 0xB
	  bl        0x73ACC
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1F508
	  lwz       r3, 0xC(r29)
	  bl        0x1F734
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
 * Address:	800AB4F8
 * Size:	000214
 */
void ActBoreTalk::startTalk()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stmw      r26, 0x70(r1)
	  mr        r30, r3
	  lwz       r3, 0xC(r3)
	  lwz       r4, 0x1C(r30)
	  addi      r31, r3, 0x1B8
	  addi      r4, r4, 0x94
	  bl        -0x20AE0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r26, r3, 0
	  subi      r28, r5, 0x3064
	  subi      r29, r4, 0x2D74
	  addi      r27, r1, 0x50
	  b         .loc_0xD4

	.loc_0x58:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x7C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x94

	.loc_0x7C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x94:
	  lwz       r0, 0xC(r30)
	  mr        r4, r27
	  stw       r28, 0x50(r1)
	  stw       r0, 0x54(r1)
	  stw       r29, 0x50(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0xD4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFC
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0xFC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x124
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r0, 0

	.loc_0x128:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x58
	  cmplwi    r30, 0
	  addi      r27, r30, 0
	  beq-      .loc_0x140
	  lwz       r27, 0x14(r30)

	.loc_0x140:
	  addi      r3, r1, 0x40
	  li        r4, 0x40
	  bl        0x73918
	  addi      r31, r3, 0
	  addi      r5, r27, 0
	  addi      r3, r1, 0x48
	  li        r4, 0x40
	  bl        0x73938
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1F374
	  lwz       r3, 0xC(r30)
	  bl        0x1F5A0
	  bl        0x16CA00
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x6C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x7100(r2)
	  stw       r0, 0x68(r1)
	  lfs       f2, -0x7104(r2)
	  lfd       f1, 0x68(r1)
	  lfs       f0, -0x7108(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x70E4(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  lwz       r3, 0xC(r30)
	  lhz       r0, 0x4FC(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x200
	  lwz       r3, 0x504(r3)
	  lwz       r0, 0x710(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x200
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x200
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x200
	  lwz       r3, 0x3030(r13)
	  li        r4, 0
	  bl        -0x80B8

	.loc_0x200:
	  lmw       r26, 0x70(r1)
	  lwz       r0, 0x8C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB70C
 * Size:	000128
 */
void ActBoreTalk::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r4, 0x1C(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0x110

	.loc_0x2C:
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xB8
	  lwz       r3, 0xC(r31)
	  lfsu      f3, 0x94(r4)
	  lfsu      f1, 0x94(r3)
	  lfs       f2, 0x8(r4)
	  lfs       f0, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x170298
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x731B8
	  fmr       f31, f1
	  lfs       f0, -0x70E0(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f31
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x73200
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)
	  stfs      f31, 0x3C(r1)
	  lfs       f0, -0x70E0(r2)
	  lwz       r0, 0x3C(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x3C(r1)
	  lfs       f1, 0x3C(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB8
	  li        r0, 0x1
	  stw       r0, 0x18(r31)
	  mr        r3, r31
	  bl        -0x2C8

	.loc_0xB8:
	  lbz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  li        r3, 0x2
	  b         .loc_0x110

	.loc_0xCC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x10C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x100
	  lwz       r4, 0x14(r31)

	.loc_0x100:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x742AC

	.loc_0x10C:
	  li        r3, 0

	.loc_0x110:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB834
 * Size:	000004
 */
void ActBoreTalk::cleanup() { }

/*
 * --INFO--
 * Address:	800AB838
 * Size:	000024
 */
void ActBoreTalk::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x18(r3)
	  cmpwi     r0, 0
	  beqlr-
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  bnelr-
	  li        r0, 0x1
	  stb       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
ActBoreListen::ActBoreListen(Piki*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AB85C
 * Size:	000004
 */
void ActBoreListen::init(Creature*) { }

/*
 * --INFO--
 * Address:	800AB860
 * Size:	000008
 */
u32 ActBoreListen::exec() { return 0x0; }

/*
 * --INFO--
 * Address:	800AB868
 * Size:	000004
 */
void ActBoreListen::cleanup() { }

/*
 * --INFO--
 * Address:	800AB86C
 * Size:	000004
 */
void ActBoreListen::procAnimMsg(Piki*, MsgAnim*) { }

/*
 * --INFO--
 * Address:	800AB870
 * Size:	000080
 */
ActBoreOneshot::ActBoreOneshot(Piki*)
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
	  addi      r0, r31, 0x1C
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x1C(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  li        r5, 0x1
	  bl        0x18524
	  lis       r3, 0x802B
	  addi      r3, r3, 0x56A8
	  stw       r3, 0x0(r31)
	  addi      r5, r3, 0x68
	  addi      r0, r31, 0x1C
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
 * Address:	800AB8F0
 * Size:	000038
 */
void ActBoreOneshot::finish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  addi      r4, r3, 0
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  lwz       r4, 0x14(r3)

	.loc_0x1C:
	  lwz       r3, 0xC(r3)
	  addi      r3, r3, 0x354
	  bl        0x741AC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB928
 * Size:	0000E0
 */
void ActBoreOneshot::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x4
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  stw       r28, 0x40(r1)
	  addi      r28, r3, 0
	  lis       r3, 0x8022
	  stb       r0, 0x18(r28)
	  addi      r6, r3, 0x2480
	  addi      r3, r1, 0x20
	  lwz       r5, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x20(r1)
	  stw       r0, 0x24(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x30(r1)
	  stw       r0, 0x34(r1)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x38(r1)
	  stw       r0, 0x3C(r1)
	  bl        0x6A770
	  cmplwi    r28, 0
	  addi      r29, r3, 0
	  addi      r30, r28, 0
	  beq-      .loc_0x90
	  lwz       r30, 0x14(r28)

	.loc_0x90:
	  addi      r3, r1, 0x10
	  addi      r4, r29, 0
	  bl        0x73598
	  addi      r31, r3, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  bl        0x735B8
	  mr        r4, r3
	  lwz       r3, 0xC(r28)
	  mr        r5, r31
	  bl        0x1EFF4
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ABA08
 * Size:	00001C
 */
void ActBoreOneshot::exec()
{
	/*
	.loc_0x0:
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x14
	  li        r3, 0x2
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ABA24
 * Size:	000004
 */
void ActBoreOneshot::cleanup() { }

/*
 * --INFO--
 * Address:	800ABA28
 * Size:	000018
 */
void ActBoreOneshot::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  bnelr-
	  li        r0, 0x1
	  stb       r0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ABA40
 * Size:	000080
 */
ActBoreRest::ActBoreRest(Piki*)
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
	  bl        0x18354
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5608
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
 * Address:	800ABAC0
 * Size:	00008C
 */
void ActBoreRest::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  stw       r31, 0x1C(r3)
	  bl        .loc_0x8C
	  bl        0x16C58C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x7100(r2)
	  stw       r0, 0x18(r1)
	  lfs       f2, -0x7104(r2)
	  lfd       f1, 0x18(r1)
	  lfs       f0, -0x70DC(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x70E4(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  stb       r31, 0x25(r30)
	  stb       r31, 0x24(r30)
	  stb       r31, 0x18(r30)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x8C:
	*/
}

/*
 * --INFO--
 * Address:	800ABB4C
 * Size:	0000E8
 */
void ActBoreRest::sitDown()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r0, 0x1C(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x84
	  bge-      .loc_0xCC
	  cmpwi     r0, 0
	  bge-      .loc_0x38
	  b         .loc_0xCC

	.loc_0x38:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x48
	  lwz       r30, 0x14(r29)

	.loc_0x48:
	  addi      r3, r1, 0x1C
	  li        r4, 0x32
	  bl        0x733BC
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x32
	  bl        0x733DC
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1EE18
	  li        r0, 0x1
	  stw       r0, 0x1C(r29)
	  b         .loc_0xCC

	.loc_0x84:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x94
	  lwz       r30, 0x14(r29)

	.loc_0x94:
	  addi      r3, r1, 0xC
	  li        r4, 0x34
	  bl        0x73370
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x34
	  bl        0x73390
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1EDCC
	  li        r0, 0x3
	  stw       r0, 0x1C(r29)

	.loc_0xCC:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void ActBoreRest::standUp()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800ABC34
 * Size:	0002E8
 */
void ActBoreRest::exec()
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
	  lbz       r0, 0x25(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0x2
	  b         .loc_0x2CC

	.loc_0x30:
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  lbz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xD4
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  blt-      .loc_0xCC
	  cmpwi     r0, 0x2
	  beq-      .loc_0xC4
	  bge-      .loc_0x6C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x78
	  b         .loc_0xC4

	.loc_0x6C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xC4
	  b         .loc_0xA0

	.loc_0x78:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x88
	  lwz       r4, 0x14(r31)

	.loc_0x88:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73DFC
	  li        r0, 0x1
	  stb       r0, 0x24(r31)
	  b         .loc_0xC4

	.loc_0xA0:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0xB0
	  lwz       r4, 0x14(r31)

	.loc_0xB0:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73DD4
	  li        r0, 0x1
	  stb       r0, 0x24(r31)

	.loc_0xC4:
	  li        r3, 0
	  b         .loc_0x2CC

	.loc_0xCC:
	  li        r3, 0x2
	  b         .loc_0x2CC

	.loc_0xD4:
	  li        r3, 0
	  b         .loc_0x2CC

	.loc_0xDC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lbz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C8
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2C8
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  bgt-      .loc_0x208
	  bl        0x16C324
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7100(r2)
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x7104(r2)
	  lfd       f3, 0x40(r1)
	  lfs       f0, -0x70F8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x208
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1BC
	  bge-      .loc_0x284
	  cmpwi     r0, 0
	  bge-      .loc_0x170
	  b         .loc_0x284

	.loc_0x170:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x180
	  lwz       r29, 0x14(r31)

	.loc_0x180:
	  addi      r3, r1, 0x24
	  li        r4, 0x32
	  bl        0x7319C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x32
	  bl        0x731BC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1EBF8
	  li        r0, 0x1
	  stw       r0, 0x1C(r31)
	  b         .loc_0x284

	.loc_0x1BC:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x1CC
	  lwz       r29, 0x14(r31)

	.loc_0x1CC:
	  addi      r3, r1, 0x34
	  li        r4, 0x34
	  bl        0x73150
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x2C
	  li        r4, 0x34
	  bl        0x73170
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1EBAC
	  li        r0, 0x3
	  stw       r0, 0x1C(r31)
	  b         .loc_0x284

	.loc_0x208:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  blt-      .loc_0x284
	  cmpwi     r0, 0x2
	  beq-      .loc_0x284
	  bge-      .loc_0x22C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x238
	  b         .loc_0x284

	.loc_0x22C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x284
	  b         .loc_0x260

	.loc_0x238:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x248
	  lwz       r4, 0x14(r31)

	.loc_0x248:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73C3C
	  li        r0, 0x1
	  stb       r0, 0x24(r31)
	  b         .loc_0x284

	.loc_0x260:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x270
	  lwz       r4, 0x14(r31)

	.loc_0x270:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73C14
	  li        r0, 0x1
	  stb       r0, 0x24(r31)

	.loc_0x284:
	  bl        0x16C1B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x7100(r2)
	  stw       r0, 0x40(r1)
	  lfs       f2, -0x7104(r2)
	  lfd       f1, 0x40(r1)
	  lfs       f0, -0x7108(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x70F4(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r31)

	.loc_0x2C8:
	  li        r3, 0

	.loc_0x2CC:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ABF1C
 * Size:	000004
 */
void ActBoreRest::cleanup() { }

/*
 * --INFO--
 * Address:	800ABF20
 * Size:	000104
 */
void ActBoreRest::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0xE8
	  bge-      .loc_0xE8
	  cmpwi     r0, 0
	  beq-      .loc_0x38
	  b         .loc_0xE8

	.loc_0x38:
	  lbz       r0, 0x24(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xE8
	  bge-      .loc_0x60
	  cmpwi     r0, 0x1
	  bge-      .loc_0x6C
	  b         .loc_0xE8

	.loc_0x60:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xE8
	  b         .loc_0x84

	.loc_0x6C:
	  li        r3, 0
	  stb       r3, 0x24(r29)
	  li        r0, 0x1
	  stw       r3, 0x1C(r29)
	  stb       r0, 0x25(r29)
	  b         .loc_0xE8

	.loc_0x84:
	  li        r0, 0
	  stb       r0, 0x24(r29)
	  li        r0, 0x1
	  cmplwi    r29, 0
	  stw       r0, 0x1C(r29)
	  mr        r30, r29
	  beq-      .loc_0xA4
	  lwz       r30, 0x14(r29)

	.loc_0xA4:
	  addi      r3, r1, 0x28
	  li        r4, 0x32
	  bl        0x72F8C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x32
	  bl        0x72FAC
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1E9E8
	  lfs       f0, -0x70D8(r2)
	  lwz       r3, 0xC(r29)
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r29)
	  stfs      f0, 0x3D8(r3)

	.loc_0xE8:
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
 * Address:	800AC024
 * Size:	000080
 */
ActBoreRest::~ActBoreRest()
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
	  addi      r3, r3, 0x5608
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
	  bl        0x17D94
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x64ED8

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

/*
 * --INFO--
 * Address:	800AC0A4
 * Size:	000080
 */
ActBoreOneshot::~ActBoreOneshot()
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
	  addi      r3, r3, 0x56A8
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x1C
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x17D14
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x64F58

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

/*
 * --INFO--
 * Address:	800AC124
 * Size:	000064
 */
ActBoreListen::~ActBoreListen()
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
	  addi      r0, r3, 0x5740
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x17CB0
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x64FBC

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

/*
 * --INFO--
 * Address:	800AC188
 * Size:	000080
 */
ActBoreTalk::~ActBoreTalk()
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
	  addi      r3, r3, 0x5804
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
	  bl        0x17C30
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x6503C

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

/*
 * --INFO--
 * Address:	800AC208
 * Size:	000064
 */
ActBoreSelect::~ActBoreSelect()
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
	  addi      r0, r3, 0x58A8
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x17BCC
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x650A0

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

/*
 * --INFO--
 * Address:	800AC26C
 * Size:	000064
 */
ActFreeSelect::~ActFreeSelect()
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
	  addi      r0, r3, 0x5930
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x17B68
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x65104

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

/*
 * --INFO--
 * Address:	800AC2D0
 * Size:	000014
 */
void ActBoreTalk::@40 @4 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  li        r11, 0x4
	  lwzx      r11, r3, r11
	  add       r3, r3, r11
	  subi      r3, r3, 0x28
	  b         -0xAA8
	*/
}

/*
 * --INFO--
 * Address:	800AC2E4
 * Size:	000014
 */
void ActBoreOneshot::@28 @4 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  li        r11, 0x4
	  lwzx      r11, r3, r11
	  add       r3, r3, r11
	  subi      r3, r3, 0x1C
	  b         -0x8CC
	*/
}

/*
 * --INFO--
 * Address:	800AC2F8
 * Size:	000014
 */
void ActBoreRest::@40 @4 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  li        r11, 0x4
	  lwzx      r11, r3, r11
	  add       r3, r3, r11
	  subi      r3, r3, 0x28
	  b         -0x3E8
	*/
}
