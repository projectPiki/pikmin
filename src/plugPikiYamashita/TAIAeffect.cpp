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
 * Address:	801D5E50
 * Size:	0000B8
 */
void TAIAeffCloudOfDust::init(EffectMgr::effTypeTable, bool, int, int, f32, int, int, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r8, 0x4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r27, r3
	  lwz       r30, 0x50(r1)
	  addi      r28, r9, 0
	  lwz       r31, 0x54(r1)
	  addi      r29, r10, 0
	  stb       r5, 0x20(r3)
	  bgt-      .loc_0xA4
	  stw       r4, 0x14(r27)
	  stw       r6, 0x18(r27)
	  stw       r7, 0x1C(r27)
	  stfs      f1, 0x10(r27)
	  stw       r8, 0xC(r27)
	  lwz       r0, 0xC(r27)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x18EE98
	  stw       r3, 0x8(r27)
	  lwz       r0, 0xC(r27)
	  cmpwi     r0, 0
	  ble-      .loc_0x68
	  lwz       r3, 0x8(r27)
	  stw       r28, 0x0(r3)

	.loc_0x68:
	  lwz       r0, 0xC(r27)
	  cmpwi     r0, 0x1
	  ble-      .loc_0x7C
	  lwz       r3, 0x8(r27)
	  stw       r29, 0x4(r3)

	.loc_0x7C:
	  lwz       r0, 0xC(r27)
	  cmpwi     r0, 0x2
	  ble-      .loc_0x90
	  lwz       r3, 0x8(r27)
	  stw       r30, 0x8(r3)

	.loc_0x90:
	  lwz       r0, 0xC(r27)
	  cmpwi     r0, 0x3
	  ble-      .loc_0xA4
	  lwz       r3, 0x8(r27)
	  stw       r31, 0xC(r3)

	.loc_0xA4:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D5F08
 * Size:	0000A0
 */
void TAIAeffCloudOfDust::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  li        r29, 0
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  rlwinm    r30,r29,2,0,29
	  li        r31, 0
	  b         .loc_0x80

	.loc_0x28:
	  lwz       r5, 0x8(r27)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  lwzx      r5, r5, r30
	  bl        0x2BC
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  lfs       f0, 0x8(r3)
	  addi      r3, r31, 0x480
	  li        r0, 0x1
	  stfsx     f0, r28, r3
	  slw       r3, r0, r29
	  li        r0, -0x1
	  lhz       r5, 0x4C8(r28)
	  rlwinm    r4,r5,27,28,31
	  or        r3, r4, r3
	  rlwimi    r5,r3,5,23,26
	  sth       r5, 0x4C8(r28)
	  stw       r0, 0x474(r28)

	.loc_0x74:
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1
	  addi      r31, r31, 0x4

	.loc_0x80:
	  lwz       r0, 0xC(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x28
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D5FA8
 * Size:	000068
 */
void TAIAeffCloudOfDust::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x3C

	.loc_0x28:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        0x74
	  addi      r31, r31, 0x1

	.loc_0x3C:
	  lwz       r0, 0xC(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x28
	  lwz       r0, 0x24(r1)
	  li        r3, 0
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
 * Address:	801D6010
 * Size:	000040
 */
void TAIAeffCloudOfDust::setType(Vector3f&, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lfs       f1, 0x0(r4)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x8(r31)
	  bl        -0x16E130
	  stfs      f1, 0x4(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D6050
 * Size:	0001AC
 */
void TAIAeffCloudOfDust::createCloudOfDust(Teki&, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r27, r3, 0
	  rlwinm    r26,r5,2,0,29
	  addi      r25, r5, 0
	  addi      r28, r4, 0
	  lwz       r3, 0x8(r3)
	  lwzx      r5, r3, r26
	  mr        r3, r27
	  bl        .loc_0x1AC
	  mr.       r31, r3
	  beq-      .loc_0x194
	  lhz       r4, 0x4C8(r28)
	  add       r29, r28, r26
	  li        r0, 0x1
	  lfs       f1, 0x8(r31)
	  lfsu      f0, 0x480(r29)
	  rlwinm    r3,r4,27,28,31
	  slw       r30, r0, r25
	  fsubs     f31, f1, f0
	  and.      r0, r3, r30
	  beq-      .loc_0x174
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x4(r31)
	  lfs       f2, 0xC(r31)
	  bl        -0x16E1C0
	  lfs       f2, 0x8(r31)
	  lfs       f0, 0x0(r31)
	  fsubs     f2, f2, f0
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x18C
	  lfs       f0, 0x98(r28)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x18C
	  lfs       f0, 0x10(r27)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x18C
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x4(r31)
	  lfs       f2, 0xC(r31)
	  bl        -0x16DF2C
	  cmplwi    r3, 0
	  beq-      .loc_0x18C
	  bl        -0xC0090
	  lfs       f0, 0x4(r31)
	  mr        r25, r3
	  addi      r3, r27, 0
	  stfs      f0, 0x20(r1)
	  addi      r5, r25, 0
	  addi      r4, r1, 0x20
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0xC(r31)
	  stfs      f0, 0x28(r1)
	  lwz       r12, 0x4(r27)
	  lwz       r6, 0x8(r27)
	  lwz       r12, 0x1C(r12)
	  lwzx      r6, r6, r26
	  mtlr      r12
	  blrl
	  lwz       r4, 0x14(r27)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x124
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x20
	  li        r6, 0
	  li        r7, 0
	  bl        -0x39638

	.loc_0x124:
	  lwz       r5, 0x18(r27)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x13C
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  bl        -0x14BBD4

	.loc_0x13C:
	  lwz       r4, 0x1C(r27)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x158
	  lwz       r3, 0x3178(r13)
	  addi      r6, r1, 0x20
	  li        r5, 0
	  bl        -0x593D0

	.loc_0x158:
	  stw       r25, 0x474(r28)
	  lhz       r3, 0x4C8(r28)
	  rlwinm    r0,r3,27,28,31
	  andc      r0, r0, r30
	  rlwimi    r3,r0,5,23,26
	  sth       r3, 0x4C8(r28)
	  b         .loc_0x18C

	.loc_0x174:
	  lfs       f0, -0x4268(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x18C
	  or        r0, r3, r30
	  rlwimi    r4,r0,5,23,26
	  sth       r4, 0x4C8(r28)

	.loc_0x18C:
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x0(r29)

	.loc_0x194:
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x1AC:
	*/
}

/*
 * --INFO--
 * Address:	801D61FC
 * Size:	000050
 */
void TAIAeffCloudOfDust::getCollPart(Teki&, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x220(r4)
	  addi      r4, r31, 0
	  bl        -0x14CB10
	  cmplwi    r3, 0
	  bne-      .loc_0x38
	  lbz       r0, 0x20(r30)
	  cmplwi    r0, 0

	.loc_0x38:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
