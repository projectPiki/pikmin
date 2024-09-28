#include "TAI/Palm.h"

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
 * Address:	8013DAB4
 * Size:	000084
 */
TaiPalmSoundTable::TaiPalmSoundTable()
    : PaniSoundTable(5)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x1EA60
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xF6AE4
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x2E
	  stw       r0, 0x0(r3)

	.loc_0x48:
	  lwz       r4, 0x4(r29)
	  addi      r30, r30, 0x1
	  stwx      r3, r4, r31
	  addi      r31, r31, 0x4

	.loc_0x58:
	  lwz       r0, 0x0(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x30
	  mr        r3, r29
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
 * Address:	8013DB38
 * Size:	0001F4
 */
TaiPalmParameters::TaiPalmParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r5, 0x35
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x68(r1)
	  subi      r30, r4, 0x4E68
	  li        r4, 0x14
	  bl        0xE1E8
	  lis       r3, 0x802D
	  subi      r0, r3, 0x496C
	  stw       r0, 0x0(r31)
	  li        r4, 0x32
	  li        r3, 0x33
	  lwz       r5, 0x84(r31)
	  li        r0, 0x34
	  mulli     r4, r4, 0xC
	  lwz       r5, 0x4(r5)
	  lwz       r6, 0x8(r5)
	  mulli     r3, r3, 0xC
	  add       r5, r6, r4
	  addi      r4, r30, 0xC
	  stw       r4, 0x0(r5)
	  mulli     r0, r0, 0xC
	  lfs       f3, -0x5A28(r2)
	  add       r7, r6, r3
	  stfs      f3, 0x4(r5)
	  addi      r4, r30, 0x24
	  add       r8, r6, r0
	  lfs       f0, -0x5A24(r2)
	  addi      r3, r30, 0x48
	  li        r6, 0
	  stfs      f0, 0x8(r5)
	  li        r5, -0x1
	  li        r0, 0x1
	  stw       r4, 0x0(r7)
	  stfs      f3, 0x4(r7)
	  lfs       f2, -0x5A20(r2)
	  stfs      f2, 0x8(r7)
	  stw       r3, 0x0(r8)
	  stfs      f3, 0x4(r8)
	  stfs      f0, 0x8(r8)
	  lwz       r4, 0x84(r31)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5A1C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A18(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A14(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A10(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A0C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A08(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A04(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x9C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5A00(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xA0(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r31
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0xAC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x59FC(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xB0(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x59F8(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xC8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0xCC(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0xD0(r4)
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013DD2C
 * Size:	0004F0
 */
TaiPalmStrategy::TaiPalmStrategy(TekiParameters*)
    : TaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stmw      r23, 0x9C(r1)
	  addi      r26, r4, 0
	  addi      r31, r3, 0
	  li        r4, 0x4
	  bl        -0x16968
	  lis       r3, 0x802D
	  subi      r0, r3, 0x4A40
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0xF6D5C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x42D8
	  stw       r0, 0x4(r28)

	.loc_0x64:
	  li        r3, 0x8
	  bl        -0xF6D90
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x98
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x4580
	  stw       r0, 0x4(r27)

	.loc_0x98:
	  li        r3, 0x8
	  bl        -0xF6DC4
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xCC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x4D14
	  stw       r0, 0x4(r29)

	.loc_0xCC:
	  li        r3, 0x14
	  bl        -0xF6DF8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x124
	  lwz       r5, 0x84(r26)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x4DDC
	  li        r0, 0x1
	  lfs       f0, 0xCC(r6)
	  lfs       f1, 0xC8(r6)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x0(r30)
	  stw       r3, 0x4(r30)
	  stw       r0, 0x8(r30)
	  stfs      f1, 0xC(r30)
	  stfs      f0, 0x10(r30)

	.loc_0x124:
	  li        r3, 0x8
	  bl        -0xF6E50
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x158
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0x4D98
	  stw       r0, 0x4(r25)

	.loc_0x158:
	  li        r3, 0xC
	  bl        -0xF6E84
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x1AC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x6A6C
	  lis       r4, 0x802D
	  stw       r0, 0x4(r24)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x8(r24)
	  subi      r4, r4, 0x447C
	  subi      r0, r3, 0x4B94
	  stw       r4, 0x4(r24)
	  stw       r0, 0x4(r24)

	.loc_0x1AC:
	  li        r3, 0xC
	  bl        -0xF6ED8
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x1C8
	  li        r4, 0x2
	  bl        -0x16E58

	.loc_0x1C8:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r23)
	  li        r3, 0xC
	  stwx      r24, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x0(r4)
	  bl        -0xF6F1C
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x244
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x6A6C
	  lis       r4, 0x802D
	  stw       r0, 0x4(r24)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r24)
	  subi      r4, r4, 0x4650
	  subi      r0, r3, 0x4C04
	  stw       r4, 0x4(r24)
	  stw       r0, 0x4(r24)

	.loc_0x244:
	  li        r3, 0xC
	  bl        -0xF6F70
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x260
	  li        r4, 0x4
	  bl        -0x16EF0

	.loc_0x260:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x8(r25)
	  li        r3, 0xC
	  stwx      r24, r5, r4
	  lwz       r4, 0x8(r25)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x4(r4)
	  bl        -0xF6FD4
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x2F0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r24)
	  li        r4, 0x4
	  subi      r0, r3, 0x4B50
	  stw       r4, 0x8(r24)
	  stw       r0, 0x4(r24)

	.loc_0x2F0:
	  li        r3, 0x8
	  bl        -0xF701C
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x324
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0x4C98
	  stw       r0, 0x4(r25)

	.loc_0x324:
	  li        r3, 0x14
	  bl        -0xF7050
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x37C
	  lwz       r5, 0x84(r26)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0xD0(r6)
	  stw       r5, 0x4(r23)
	  stw       r4, 0x0(r23)
	  stw       r3, 0x4(r23)
	  stw       r0, 0x8(r23)
	  stfs      f0, 0xC(r23)
	  lfs       f0, -0x5A28(r2)
	  stfs      f0, 0x10(r23)

	.loc_0x37C:
	  li        r3, 0xC
	  bl        -0xF70A8
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x398
	  li        r4, 0x3
	  bl        -0x17028

	.loc_0x398:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r26)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r25, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r26)
	  stwx      r23, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x8(r4)
	  bl        -0xF70FC
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x40C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0x2
	  lis       r3, 0x802D
	  stw       r0, 0x0(r23)
	  subi      r3, r3, 0x4CD8
	  li        r0, 0
	  stw       r3, 0x4(r23)
	  stw       r0, 0x8(r23)

	.loc_0x40C:
	  li        r3, 0xC
	  bl        -0xF7138
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x454
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r24)
	  li        r4, 0x2
	  subi      r0, r3, 0x4B50
	  stw       r4, 0x8(r24)
	  stw       r0, 0x4(r24)

	.loc_0x454:
	  li        r3, 0xC
	  bl        -0xF7180
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x470
	  li        r4, 0x6
	  bl        -0x17100

	.loc_0x470:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r27, r3, r0
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r7,2,0,29
	  lwz       r6, 0x8(r25)
	  mr        r3, r31
	  stwx      r24, r6, r5
	  lwz       r5, 0x8(r25)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r25)
	  stwx      r23, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r25, 0xC(r4)
	  lwz       r0, 0xC4(r1)
	  lmw       r23, 0x9C(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E21C
 * Size:	0002B4
 */
void TaiPalmStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x218(r1)
	  stfd      f31, 0x210(r1)
	  stmw      r25, 0x1F4(r1)
	  mr        r30, r4
	  bl        -0x16DA0
	  lwz       r4, 0x2C8(r30)
	  lwz       r3, 0x34(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x10(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x44
	  lwz       r0, 0x24(r4)
	  stw       r0, 0x3BC(r30)
	  b         .loc_0x50

	.loc_0x44:
	  li        r3, 0x2
	  bl        -0x1F9C0
	  stw       r3, 0x3BC(r30)

	.loc_0x50:
	  lwz       r3, 0x2C4(r30)
	  lis       r8, 0x802D
	  lis       r6, 0x802C
	  lwz       r3, 0x84(r3)
	  lis       r10, 0x802B
	  subi      r26, r10, 0xF68
	  lwz       r3, 0x4(r3)
	  lis       r9, 0x802C
	  lis       r7, 0x802D
	  lwz       r11, 0x0(r3)
	  subi      r29, r7, 0x2754
	  subi      r28, r8, 0x29D8
	  lfs       f0, 0xD0(r11)
	  addi      r12, r6, 0x685C
	  lis       r3, 0x802C
	  stfs      f0, 0x3C4(r30)
	  addi      r27, r9, 0x6964
	  lis       r4, 0x802D
	  lwz       r8, 0x2C8(r30)
	  addi      r11, r1, 0x1AC
	  lfs       f0, -0x1CA8(r13)
	  subi      r9, r4, 0x2998
	  lwz       r6, 0x34(r8)
	  addi      r31, r30, 0x94
	  lwz       r6, 0x4(r6)
	  addi      r8, r3, 0x6890
	  addi      r10, r1, 0x1A0
	  lwz       r3, 0x0(r6)
	  addi      r6, r1, 0x1C8
	  addi      r7, r1, 0x1C0
	  lfs       f1, 0x8(r3)
	  addi      r0, r1, 0x1B4
	  addi      r5, r1, 0x1D0
	  fmuls     f0, f1, f0
	  mr        r4, r31
	  stfs      f0, 0xA0(r30)
	  lwz       r3, 0x2C4(r30)
	  lfs       f1, -0x59F8(r2)
	  lwz       r25, 0x84(r3)
	  lwz       r3, 0x3160(r13)
	  lwz       r25, 0x4(r25)
	  lwz       r25, 0x0(r25)
	  lfs       f0, 0xB0(r25)
	  stw       r26, 0x1A0(r1)
	  fmuls     f31, f1, f0
	  stw       r27, 0x1A0(r1)
	  stw       r28, 0x1A0(r1)
	  stw       r30, 0x1A4(r1)
	  stfs      f31, 0x1A8(r1)
	  lwz       r25, 0x320(r30)
	  stw       r26, 0x1B4(r1)
	  stw       r26, 0x1D0(r1)
	  stw       r26, 0x1AC(r1)
	  stw       r27, 0x1B4(r1)
	  stw       r26, 0x1C0(r1)
	  stw       r26, 0x1C8(r1)
	  stw       r27, 0x1D0(r1)
	  stw       r27, 0x1AC(r1)
	  stw       r12, 0x1B4(r1)
	  stw       r27, 0x1C0(r1)
	  stw       r27, 0x1C8(r1)
	  stw       r12, 0x1D0(r1)
	  stw       r29, 0x1AC(r1)
	  stw       r11, 0x1B8(r1)
	  stw       r9, 0x1C0(r1)
	  stw       r8, 0x1C8(r1)
	  stw       r6, 0x1D4(r1)
	  stw       r25, 0x1B0(r1)
	  stw       r10, 0x1BC(r1)
	  stw       r30, 0x1C4(r1)
	  stw       r7, 0x1CC(r1)
	  stw       r0, 0x1D8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr.       r29, r3
	  beq-      .loc_0x284
	  mr        r3, r31
	  bl        -0x21580
	  addi      r3, r1, 0x1DC
	  bl        -0x2155C
	  lfs       f1, 0x0(r31)
	  addi      r3, r1, 0x1DC
	  lfs       f0, 0x94(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1DC(r1)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x98(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1E0(r1)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x9C(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1E4(r1)
	  lfs       f0, -0x5A28(r2)
	  stfs      f0, 0x1E0(r1)
	  bl        -0x213D8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1F8
	  lfs       f1, -0xE0C(r13)
	  lfs       f0, -0xE08(r13)
	  stfs      f1, 0x1DC(r1)
	  stfs      f0, 0x1E0(r1)
	  lfs       f0, -0xE04(r13)
	  stfs      f0, 0x1E4(r1)

	.loc_0x1F8:
	  lfs       f0, 0x1DC(r1)
	  li        r4, 0x1
	  fmuls     f0, f0, f31
	  stfs      f0, 0x1DC(r1)
	  lfs       f0, 0x1E0(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x1E0(r1)
	  lfs       f0, 0x1E4(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x1E4(r1)
	  lfs       f1, 0x1DC(r1)
	  lfs       f0, 0x94(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1DC(r1)
	  lfs       f1, 0x1E0(r1)
	  lfs       f0, 0x98(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E0(r1)
	  lfs       f1, 0x1E4(r1)
	  lfs       f0, 0x9C(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E4(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x1DC(r1)
	  lfs       f2, 0x1E4(r1)
	  bl        -0xD6574
	  stfs      f1, 0x1E0(r1)
	  addi      r3, r30, 0x94
	  lwz       r4, 0x1DC(r1)
	  lwz       r0, 0x1E0(r1)
	  stw       r4, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0x1E4(r1)
	  stw       r0, 0x9C(r30)
	  bl        -0x21674

	.loc_0x284:
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x388(r30)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x38C(r30)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x390(r30)
	  lmw       r25, 0x1F4(r1)
	  lwz       r0, 0x21C(r1)
	  lfd       f31, 0x210(r1)
	  addi      r1, r1, 0x218
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E4D0
 * Size:	000038
 */
void TaiPalmStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0x388(r4)
	  lwz       r0, 0x38C(r4)
	  stw       r6, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x390(r4)
	  stw       r0, 0x9C(r4)
	  bl        0xECD0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E508
 * Size:	000148
 */
void TaiPalmStrategy::createEffect(Teki&, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x4C(r1)
	  addi      r29, r4, 0
	  bl        0xEC90
	  lwz       r0, 0x3180(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  addi      r4, r29, 0x94
	  addi      r3, r1, 0x38
	  bl        -0x216C8
	  cmpwi     r30, 0
	  li        r31, 0
	  bne-      .loc_0x70
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x38
	  li        r4, 0x46
	  li        r6, 0
	  li        r7, 0
	  bl        0x5E5CC
	  mr        r31, r3
	  b         .loc_0xD4

	.loc_0x70:
	  cmpwi     r30, 0x1
	  bne-      .loc_0x98
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x38
	  li        r4, 0x47
	  li        r6, 0
	  li        r7, 0
	  bl        0x5E5A4
	  mr        r31, r3
	  b         .loc_0xD4

	.loc_0x98:
	  cmpwi     r30, 0x2
	  bne-      .loc_0xD4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x38
	  li        r4, 0x48
	  li        r6, 0
	  li        r7, 0
	  bl        0x5E57C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x38
	  li        r4, 0x49
	  li        r6, 0
	  li        r7, 0
	  bl        0x5E564
	  mr        r31, r3

	.loc_0xD4:
	  cmplwi    r31, 0
	  beq-      .loc_0x124
	  addi      r3, r1, 0x2C
	  bl        -0x21794
	  lfs       f30, 0xA0(r29)
	  fmr       f1, f30
	  bl        0xDD560
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xDD6E8
	  stfs      f1, 0x2C(r1)
	  lfs       f0, -0xE10(r13)
	  stfs      f0, 0x30(r1)
	  stfs      f31, 0x34(r1)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r3, 0xA0(r31)
	  stw       r0, 0xA4(r31)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0xA8(r31)

	.loc_0x124:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E650
 * Size:	000100
 */
void TaiPalmStrategy::translateMotionIndex(Teki&, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  lwz       r3, 0x2C8(r4)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stfd      f0, 0x48(r1)
	  cmpwi     r0, 0
	  lwz       r0, 0x4C(r1)
	  bne-      .loc_0x74
	  cmpwi     r5, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0xF8

	.loc_0x44:
	  cmpwi     r5, 0x1
	  bne-      .loc_0x54
	  li        r3, 0x1
	  b         .loc_0xF8

	.loc_0x54:
	  cmpwi     r5, 0x2
	  bne-      .loc_0x64
	  li        r3, 0x2
	  b         .loc_0xF8

	.loc_0x64:
	  cmpwi     r5, 0x4
	  bne-      .loc_0xF4
	  li        r3, 0x9
	  b         .loc_0xF8

	.loc_0x74:
	  cmpwi     r0, 0x1
	  bne-      .loc_0xBC
	  cmpwi     r5, 0
	  bne-      .loc_0x8C
	  li        r3, 0x3
	  b         .loc_0xF8

	.loc_0x8C:
	  cmpwi     r5, 0x1
	  bne-      .loc_0x9C
	  li        r3, 0x4
	  b         .loc_0xF8

	.loc_0x9C:
	  cmpwi     r5, 0x2
	  bne-      .loc_0xAC
	  li        r3, 0x5
	  b         .loc_0xF8

	.loc_0xAC:
	  cmpwi     r5, 0x4
	  bne-      .loc_0xF4
	  li        r3, 0xA
	  b         .loc_0xF8

	.loc_0xBC:
	  cmpwi     r0, 0x2
	  bne-      .loc_0xF4
	  cmpwi     r5, 0
	  bne-      .loc_0xD4
	  li        r3, 0x6
	  b         .loc_0xF8

	.loc_0xD4:
	  cmpwi     r5, 0x1
	  bne-      .loc_0xE4
	  li        r3, 0x7
	  b         .loc_0xF8

	.loc_0xE4:
	  cmpwi     r5, 0x2
	  bne-      .loc_0xF4
	  li        r3, 0x8
	  b         .loc_0xF8

	.loc_0xF4:
	  li        r3, 0

	.loc_0xF8:
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E750
 * Size:	000064
 */
void TaiPalmMotionAction::start(Teki&)
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
	  addi      r3, r31, 0
	  bl        0xA1C4
	  lwz       r5, 0x8(r30)
	  mr        r4, r31
	  bl        -0x12C
	  lwz       r12, 0x0(r31)
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x174(r12)
	  mr        r4, r0
	  mtlr      r12
	  blrl
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
 * Address:	8013E7B4
 * Size:	000084
 */
void TaiPalmDyingAction::start(Teki&)
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
	  addi      r3, r31, 0
	  bl        0xA160
	  lwz       r5, 0x8(r30)
	  mr        r4, r31
	  bl        -0x190
	  lwz       r12, 0x0(r31)
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x174(r12)
	  mr        r4, r0
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x5A28(r2)
	  stfs      f0, 0x58(r31)
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
 * Address:	8013E838
 * Size:	000060
 */
bool TaiPalmDyingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x48
	  mr        r3, r31
	  bl        0x7608
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x4C

	.loc_0x48:
	  li        r3, 0

	.loc_0x4C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E898
 * Size:	000078
 */
void TaiPalmDamagingAction::start(Teki&)
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
	  addi      r3, r31, 0
	  bl        0xA07C
	  lwz       r5, 0x8(r30)
	  mr        r4, r31
	  bl        -0x274
	  lwz       r12, 0x0(r31)
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x174(r12)
	  mr        r4, r0
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x18C(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8013E910
 * Size:	000054
 */
void TaiPalmGrowingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x68(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x2C8(r4)
	  lfd       f1, -0x59F0(r2)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  addi      r4, r3, 0x4
	  fctiwz    f0, f0
	  stfd      f0, 0x60(r1)
	  lwz       r3, 0x64(r1)
	  addi      r3, r3, 0x1
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x5C(r1)
	  stw       r0, 0x58(r1)
	  lfd       f0, 0x58(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x0(r4)
	  addi      r1, r1, 0x68
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E964
 * Size:	000068
 */
bool TaiPalmGrowAction::act(Teki&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  lwz       r5, 0x2C8(r4)
	  lwz       r5, 0x34(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0x4(r5)
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x60

	.loc_0x34:
	  lwz       r0, 0x8(r3)
	  lfs       f0, -0x5A28(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r4, r0
	  lfs       f1, 0x3C4(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x60

	.loc_0x5C:
	  li        r3, 0x1

	.loc_0x60:
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013E9CC
 * Size:	000038
 */
bool TaiPalmFlowerDamageAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x33C(r4)
	  lfs       f0, -0x5A28(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1C
	  li        r3, 0
	  blr

	.loc_0x1C:
	  lwz       r0, 0x344(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x30
	  li        r3, 0x1
	  blr

	.loc_0x30:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EA04
 * Size:	000034
 */
bool TaiPalmSunflowerAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x2F00(r13)
	  lwz       r4, 0x4(r5)
	  addi      r4, r4, 0x1408
	  bl        -0xB3FE4
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EA38
 * Size:	000064
 */
void TaiPalmSettingPelletAction::start(Teki&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x58(r1)
	  lwz       r0, 0x3BC(r4)
	  lwz       r3, 0x2C8(r4)
	  stw       r0, 0x24(r3)
	  lwz       r3, 0x2C8(r4)
	  lwz       r5, 0x34(r3)
	  lwz       r3, 0x4(r5)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x5C
	  lwz       r3, 0x0(r5)
	  li        r0, 0
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x2C8(r4)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x4(r3)

	.loc_0x5C:
	  addi      r1, r1, 0x58
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EA9C
 * Size:	000004
 */
void TaiPalmChangingColorAction::start(Teki&) { }

/*
 * --INFO--
 * Address:	8013EAA0
 * Size:	000090
 */
bool TaiPalmChangingColorAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x2C8(r4)
	  lwz       r5, 0x34(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r0, 0x10(r5)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x80

	.loc_0x30:
	  lwz       r0, 0x8(r3)
	  lfs       f0, -0x5A28(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r5, r4, r0
	  lfs       f1, 0x3C4(r5)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x80

	.loc_0x58:
	  lwz       r5, 0x3BC(r4)
	  addi      r0, r5, 0x1
	  stw       r0, 0x3BC(r4)
	  lwz       r0, 0x3BC(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x78
	  li        r0, 0
	  stw       r0, 0x3BC(r4)

	.loc_0x78:
	  bl        .loc_0x90
	  li        r3, 0

	.loc_0x80:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x90:
	*/
}

/*
 * --INFO--
 * Address:	8013EB30
 * Size:	0000A8
 */
void TaiPalmChangingColorAction::resetTimer(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stfd      f30, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lfs       f30, 0x10(r3)
	  lfs       f31, 0xC(r3)
	  bl        0xD9514
	  xoris     r3, r3, 0x8000
	  lwz       r0, 0x8(r30)
	  stw       r3, 0x24(r1)
	  lis       r3, 0x4330
	  rlwinm    r0,r0,2,0,29
	  lfd       f1, -0x59F0(r2)
	  stw       r3, 0x20(r1)
	  lfs       f3, -0x59E8(r2)
	  add       r3, r31, r0
	  lfd       f0, 0x20(r1)
	  lfs       f2, -0x5A20(r2)
	  fsubs     f4, f0, f1
	  lfs       f0, -0x59E4(r2)
	  lfs       f1, -0x59F8(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f31, f0
	  fmuls     f0, f30, f0
	  fadds     f0, f31, f0
	  stfs      f0, 0x3C4(r3)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}
