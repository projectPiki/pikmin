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
 * Address:	801EAA70
 * Size:	000084
 */
TAIotamaSoundTable::TAIotamaSoundTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xCBA1C
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x1A3AA0
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0xA5
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
 * Address:	801EAAF4
 * Size:	00033C
 */
TAIotamaParameters::TAIotamaParameters()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x14
	  stw       r0, 0x4(r1)
	  li        r5, 0x34
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  addi      r31, r3, 0
	  bl        -0x9EDC8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x6C48
	  stw       r0, 0x0(r31)
	  li        r6, 0x32
	  lis       r5, 0x802E
	  lwz       r4, 0x84(r31)
	  li        r0, 0x33
	  lis       r3, 0x802E
	  lwz       r7, 0x4(r4)
	  mulli     r6, r6, 0xC
	  lwz       r7, 0x8(r7)
	  mulli     r0, r0, 0xC
	  add       r11, r7, r6
	  addi      r5, r5, 0x677C
	  stw       r5, 0x0(r11)
	  add       r12, r7, r0
	  addi      r3, r3, 0x6794
	  lfs       f6, -0x3F58(r2)
	  li        r10, -0x1
	  li        r9, 0x5
	  stfs      f6, 0x4(r11)
	  li        r8, 0x2
	  li        r7, 0xA
	  lfs       f0, -0x3F54(r2)
	  li        r6, 0x3
	  li        r5, 0
	  stfs      f0, 0x8(r11)
	  li        r0, 0x1
	  stw       r3, 0x0(r12)
	  stfs      f6, 0x4(r12)
	  stfs      f0, 0x8(r12)
	  lwz       r3, 0x4(r4)
	  lfs       f5, -0x3F50(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x3F4C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xCC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r10, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r9, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r9, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x40(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x18(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x3F48(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x3F44(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F40(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x3F3C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F38(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F34(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F30(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F2C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F28(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F24(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F20(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F1C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F18(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F14(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F10(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x80(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x84(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x88(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x8C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x90(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F0C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x94(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F08(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F04(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x3F00(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x98(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r31
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0x5C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0x60(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f5, 0x4C(r4)
	  lwz       r0, 0xDC(r1)
	  lwz       r31, 0xD4(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EAE30
 * Size:	000530
 */
TAIotamaStrategy::TAIotamaStrategy()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x7
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x78(r1)
	  stmw      r18, 0x40(r1)
	  addi      r28, r3, 0
	  bl        -0x17F8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x6B90
	  stw       r0, 0x0(r28)
	  li        r3, 0x8
	  bl        -0x1A3E5C
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x60
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r29)

	.loc_0x60:
	  li        r3, 0xC
	  bl        -0x1A3E90
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0x8C
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x3E258
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  stw       r0, 0x4(r20)

	.loc_0x8C:
	  li        r3, 0xC
	  bl        -0x1A3EBC
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0xC8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r31)
	  subi      r3, r3, 0xE10
	  li        r0, 0
	  stw       r3, 0x4(r31)
	  stb       r0, 0x8(r31)

	.loc_0xC8:
	  li        r3, 0x8
	  bl        -0x1A3EF8
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0xFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0x6EC
	  stw       r0, 0x4(r25)

	.loc_0xFC:
	  li        r3, 0xC
	  bl        -0x1A3F2C
	  addi      r21, r3, 0
	  mr.       r3, r21
	  beq-      .loc_0x128
	  li        r4, 0x2
	  li        r5, 0x2
	  bl        -0x3E268
	  lis       r3, 0x802E
	  addi      r0, r3, 0x6B08
	  stw       r0, 0x4(r21)

	.loc_0x128:
	  li        r3, 0x10
	  bl        -0x1A3F58
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x174
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r4, 0x3
	  lis       r3, 0x802E
	  stw       r4, 0x0(r30)
	  subi      r0, r3, 0x510
	  lis       r3, 0x802E
	  stw       r0, 0x4(r30)
	  addi      r3, r3, 0x6AC8
	  li        r0, 0x4
	  stw       r3, 0x4(r30)
	  stw       r4, 0x8(r30)
	  stw       r0, 0xC(r30)

	.loc_0x174:
	  li        r3, 0xC
	  bl        -0x1A3FA4
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x1A0
	  li        r4, 0x1
	  li        r5, 0x6
	  bl        -0x3E2E0
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  stw       r0, 0x4(r19)

	.loc_0x1A0:
	  li        r3, 0xC
	  bl        -0x1A3FD0
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x1D8
	  li        r4, 0x3
	  li        r5, 0x4
	  bl        -0x3E30C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2EC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r24)
	  addi      r0, r3, 0x6A50
	  stw       r0, 0x4(r24)

	.loc_0x1D8:
	  li        r3, 0x8
	  bl        -0x1A4008
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x20C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0xEC
	  stw       r0, 0x4(r27)

	.loc_0x20C:
	  li        r3, 0xC
	  bl        -0x1A403C
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x244
	  li        r4, 0x6
	  li        r5, 0x4
	  bl        -0x3E378
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2EC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r23)
	  addi      r0, r3, 0x6A50
	  stw       r0, 0x4(r23)

	.loc_0x244:
	  li        r3, 0xC
	  bl        -0x1A4074
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x280
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x149C
	  stw       r0, 0x4(r26)
	  lfs       f0, -0x3EFC(r2)
	  stfs      f0, 0x8(r26)

	.loc_0x280:
	  li        r3, 0xC
	  bl        -0x1A40B0
	  addi      r22, r3, 0
	  mr.       r3, r22
	  beq-      .loc_0x2AC
	  li        r4, 0x1
	  li        r5, 0x6
	  bl        -0x3E3EC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x6998
	  stw       r0, 0x4(r22)

	.loc_0x2AC:
	  li        r3, 0xC
	  bl        -0x1A40DC
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x2C8
	  li        r4, 0x2
	  bl        -0xC405C

	.loc_0x2C8:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r18)
	  li        r3, 0xC
	  stwx      r25, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0x0(r4)
	  bl        -0x1A4120
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x30C
	  li        r4, 0x4
	  bl        -0xC40A0

	.loc_0x30C:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x8(r18)
	  li        r3, 0xC
	  stwx      r21, r5, r4
	  lwz       r4, 0x8(r18)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0x4(r4)
	  bl        -0x1A4184
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x370
	  li        r4, 0x3
	  bl        -0xC4104

	.loc_0x370:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r18)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r29, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r18)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0x8(r4)
	  bl        -0x1A41D8
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x3C4
	  li        r4, 0x3
	  bl        -0xC4158

	.loc_0x3C4:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r18)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r29, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r18)
	  stwx      r24, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0x10(r4)
	  bl        -0x1A422C
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x418
	  li        r4, 0x5
	  bl        -0xC41AC

	.loc_0x418:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r29, r3, r0
	  li        r0, 0x4
	  rlwinm    r3,r4,2,0,29
	  lwz       r5, 0x8(r18)
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r5, r3
	  li        r3, 0xC
	  lwz       r5, 0x8(r18)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r18)
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0xC(r4)
	  bl        -0x1A42A0
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x48C
	  li        r4, 0x3
	  bl        -0xC4220

	.loc_0x48C:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r18)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r29, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r18)
	  stwx      r23, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0x14(r4)
	  bl        -0x1A42F4
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x4E0
	  li        r4, 0x3
	  bl        -0xC4274

	.loc_0x4E0:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r18)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r29, r4, r3
	  mr        r3, r28
	  lwz       r4, 0x8(r18)
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r28)
	  stw       r18, 0x18(r4)
	  lwz       r0, 0x7C(r1)
	  lmw       r18, 0x40(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EB360
 * Size:	0006FC
 */
void TAIotamaAnimation::makeDefaultAnimations()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r3
	  stw       r30, 0xD0(r1)
	  lwz       r0, 0x4(r3)
	  lis       r3, 0x802E
	  addi      r30, r3, 0x6760
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0x4C
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x47E14
	  addi      r3, r31, 0
	  addi      r4, r30, 0x68
	  bl        -0x47E20
	  addi      r3, r31, 0
	  addi      r4, r30, 0x88
	  bl        -0x47E2C
	  li        r3, 0x10
	  bl        -0x1A43C4
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x8C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x8C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A440C
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0xD8
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0xD8:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0xA8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x47ECC
	  li        r3, 0x10
	  bl        -0x1A4464
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x12C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x12C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A44AC
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x178
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x178:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0xC8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x47F6C
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x19B148
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19AD00
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19AD18
	  li        r3, 0x10
	  bl        -0x1A4540
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x20C
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x20C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A458C
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x25C
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x25C:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0xE8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x48050
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x19B22C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19ADE4
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19ADFC
	  li        r3, 0x10
	  bl        -0x1A4624
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x2F0
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x2F0:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A4670
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x340
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x340:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x108
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x48134
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x19B310
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19AEC8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19AEE0
	  li        r3, 0x10
	  bl        -0x1A4708
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x3D4
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x3D4:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A4754
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x424
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x424:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x128
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x48218
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x19B3F4
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19AFAC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19AFC4
	  li        r3, 0x10
	  bl        -0x1A47EC
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x4B8
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x4B8:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A4838
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x508
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x508:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x148
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x482FC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19B084
	  li        r3, 0x10
	  bl        -0x1A48AC
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x57C
	  li        r0, 0x1
	  stw       r0, 0x0(r7)
	  li        r3, 0x2
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x57C:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x168
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x48370
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19B0F8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19B110
	  li        r3, 0x10
	  bl        -0x1A4938
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x604
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x604:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1A4984
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x654
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x654:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x188
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x48448
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x19B1D0
	  li        r3, 0x10
	  bl        -0x1A49F8
	  cmplwi    r3, 0
	  beq-      .loc_0x6C4
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  li        r4, 0x2
	  li        r0, 0
	  stb       r4, 0x6(r3)
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)

	.loc_0x6C4:
	  lwz       r4, 0x8(r31)
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r3)
	  stw       r5, 0x8(r3)
	  lwz       r4, 0xC(r5)
	  stw       r3, 0x8(r4)
	  stw       r3, 0xC(r5)

	.loc_0x6E4:
	  lwz       r0, 0xDC(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EBA5C
 * Size:	000384
 */
void TAIArunAwayOtama::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stw       r31, 0x104(r1)
	  mr        r31, r4
	  stw       r30, 0x100(r1)
	  bl        -0x3ED74
	  lwz       r3, 0x3120(r13)
	  bl        -0xD46BC
	  lfs       f0, -0x3F58(r2)
	  addi      r7, r3, 0x94
	  addi      r6, r1, 0xA0
	  stfs      f0, 0xC0(r1)
	  addi      r5, r1, 0x9C
	  addi      r4, r1, 0x98
	  stfs      f0, 0xBC(r1)
	  addi      r30, r31, 0x94
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r3, r1, 0xCC
	  lfs       f1, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  bl        -0x1B49C0
	  lfs       f1, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xD4(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0xB8(r1)
	  lfs       f0, 0xBC(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1DDED8
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x6
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC965C
	  fcmpo     cr0, f31, f1
	  bgt-      .loc_0x348
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x10
	  lwz       r3, 0x84(r3)
	  bl        -0xC8938
	  fdivs     f1, f1, f31
	  lfs       f0, 0xB8(r1)
	  addi      r6, r1, 0x88
	  addi      r5, r1, 0x84
	  addi      r4, r1, 0x80
	  fmuls     f0, f0, f1
	  addi      r3, r1, 0xD8
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0xBC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lfs       f2, 0x8(r30)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xB8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x88(r1)
	  lfs       f2, 0x4(r30)
	  lfs       f1, 0xBC(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x84(r1)
	  lfs       f1, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x80(r1)
	  bl        -0x1B4A98
	  lfs       f0, 0xD8(r1)
	  addi      r6, r1, 0x78
	  addi      r5, r1, 0x74
	  stfs      f0, 0x388(r31)
	  addi      r4, r1, 0x70
	  addi      r3, r1, 0xA8
	  lfs       f0, 0xDC(r1)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0xE0(r1)
	  stfs      f0, 0x390(r31)
	  lwz       r7, 0x2C8(r31)
	  lfs       f0, -0x3F58(r2)
	  addi      r7, r7, 0x10
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0xA8(r1)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x390(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x38C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x388(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  bl        -0x18E59C
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0xAC(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xB0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1DE00C
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC9790
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x348
	  lwz       r3, 0x2C8(r31)
	  addi      r6, r1, 0x68
	  lfs       f1, 0x390(r31)
	  addi      r5, r1, 0x64
	  lfs       f0, 0x18(r3)
	  addi      r7, r3, 0x10
	  fsubs     f0, f1, f0
	  addi      r4, r1, 0x60
	  addi      r3, r1, 0xE4
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x38C(r31)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  bl        -0x1B4B9C
	  lfs       f1, 0xE4(r1)
	  lfs       f0, 0xE8(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xEC(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0xB8(r1)
	  lfs       f0, 0xBC(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1DE0B4
	  lfs       f0, -0x3F58(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2B0
	  addi      r3, r1, 0xB8
	  bl        -0x1627BC

	.loc_0x2B0:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  bl        -0xC8B08
	  lfs       f0, 0xB8(r1)
	  addi      r6, r1, 0x5C
	  addi      r5, r1, 0x58
	  fmuls     f0, f0, f1
	  addi      r4, r1, 0x54
	  addi      r3, r1, 0xF0
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0xBC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lwz       r7, 0x2C8(r31)
	  lfs       f1, 0xC0(r1)
	  addi      r7, r7, 0x10
	  lfs       f0, 0xB8(r1)
	  lfs       f2, 0x8(r7)
	  fadds     f1, f2, f1
	  stfs      f1, 0x5C(r1)
	  lfs       f2, 0x4(r7)
	  lfs       f1, 0xBC(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x58(r1)
	  lfs       f1, 0x0(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  bl        -0x1B4C6C
	  lfs       f0, 0xF0(r1)
	  stfs      f0, 0x388(r31)
	  lfs       f0, 0xF4(r1)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0xF8(r1)
	  stfs      f0, 0x390(r31)

	.loc_0x348:
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x3F40(r2)
	  stfs      f0, 0x3B4(r31)
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lwz       r31, 0x104(r1)
	  lwz       r30, 0x100(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EBDE0
 * Size:	0003D4
 */
void TAIArunAwayOtama::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stw       r31, 0x124(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x120(r1)
	  li        r30, 0
	  stw       r29, 0x11C(r1)
	  stw       r28, 0x118(r1)
	  bl        -0x3EF50
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3AC
	  lwz       r3, 0x3120(r13)
	  bl        -0xD4A54
	  lfs       f0, -0x3F58(r2)
	  addi      r7, r3, 0x94
	  addi      r6, r1, 0xC0
	  stfs      f0, 0xE0(r1)
	  addi      r5, r1, 0xBC
	  addi      r4, r1, 0xB8
	  stfs      f0, 0xDC(r1)
	  addi      r28, r31, 0x94
	  li        r29, 0
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r3, r1, 0xE8
	  lfs       f1, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB8(r1)
	  bl        -0x1B4D5C
	  lfs       f1, 0xE8(r1)
	  lfs       f0, 0xEC(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xF0(r1)
	  stfs      f0, 0xE0(r1)
	  lfs       f1, 0xD8(r1)
	  lfs       f0, 0xDC(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xE0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1DE274
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x6
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC99F8
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x100
	  li        r29, 0x1
	  b         .loc_0x368

	.loc_0x100:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x10
	  lwz       r3, 0x84(r3)
	  bl        -0xC8CDC
	  fdivs     f1, f1, f31
	  lfs       f0, 0xD8(r1)
	  addi      r6, r1, 0xA8
	  addi      r5, r1, 0xA4
	  addi      r4, r1, 0xA0
	  fmuls     f0, f0, f1
	  addi      r3, r1, 0xF4
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0xDC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xE0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f2, 0x8(r28)
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xD8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xA8(r1)
	  lfs       f2, 0x4(r28)
	  lfs       f1, 0xDC(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xA4(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  bl        -0x1B4E3C
	  lfs       f0, 0xF4(r1)
	  addi      r6, r1, 0x98
	  addi      r5, r1, 0x94
	  stfs      f0, 0x388(r31)
	  addi      r4, r1, 0x90
	  addi      r3, r1, 0xCC
	  lfs       f0, 0xF8(r1)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0xFC(r1)
	  stfs      f0, 0x390(r31)
	  lwz       r7, 0x2C8(r31)
	  lfs       f0, -0x3F58(r2)
	  addi      r7, r7, 0x10
	  stfs      f0, 0xD4(r1)
	  stfs      f0, 0xD0(r1)
	  stfs      f0, 0xCC(r1)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x390(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x38C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x388(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x90(r1)
	  bl        -0x18E940
	  lfs       f1, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xD4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1DE3B0
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC9B34
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x368
	  lwz       r3, 0x2C8(r31)
	  addi      r6, r1, 0x88
	  lfs       f1, 0x390(r31)
	  addi      r5, r1, 0x84
	  lfs       f0, 0x18(r3)
	  addi      r7, r3, 0x10
	  fsubs     f0, f1, f0
	  addi      r4, r1, 0x80
	  addi      r3, r1, 0x100
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x38C(r31)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x84(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x80(r1)
	  bl        -0x1B4F40
	  lfs       f1, 0x100(r1)
	  lfs       f0, 0x104(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0xE0(r1)
	  lfs       f1, 0xD8(r1)
	  lfs       f0, 0xDC(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xE0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1DE458
	  lfs       f0, -0x3F58(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2D0
	  addi      r3, r1, 0xD8
	  bl        -0x162B60

	.loc_0x2D0:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  bl        -0xC8EAC
	  lfs       f0, 0xD8(r1)
	  addi      r6, r1, 0x7C
	  addi      r5, r1, 0x78
	  fmuls     f0, f0, f1
	  addi      r4, r1, 0x74
	  addi      r3, r1, 0x10C
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0xDC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xE0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lwz       r7, 0x2C8(r31)
	  lfs       f1, 0xE0(r1)
	  addi      r7, r7, 0x10
	  lfs       f0, 0xD8(r1)
	  lfs       f2, 0x8(r7)
	  fadds     f1, f2, f1
	  stfs      f1, 0x7C(r1)
	  lfs       f2, 0x4(r7)
	  lfs       f1, 0xDC(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x78(r1)
	  lfs       f1, 0x0(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  bl        -0x1B5010
	  lfs       f0, 0x10C(r1)
	  stfs      f0, 0x388(r31)
	  lfs       f0, 0x110(r1)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0x114(r1)
	  stfs      f0, 0x390(r31)

	.loc_0x368:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x38C
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0x1

	.loc_0x38C:
	  lwz       r5, 0x2C4(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0x388
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f1, 0x10(r5)
	  bl        -0x496C0

	.loc_0x3AC:
	  mr        r3, r30
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  lwz       r29, 0x11C(r1)
	  lwz       r28, 0x118(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EC1B4
 * Size:	000090
 */
void TAIAappealOtama::flick(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x7C
	  mr        r3, r31
	  bl        -0xA4464
	  lwz       r3, 0x28C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  bl        -0xD6168
	  cmpwi     r3, 0x5
	  bne-      .loc_0x6C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xF
	  li        r6, 0
	  li        r7, 0
	  bl        -0x4F6D0
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xA7
	  bl        -0x161C64
	  b         .loc_0x7C

	.loc_0x6C:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xA5
	  bl        -0x161C78

	.loc_0x7C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EC244
 * Size:	000094
 */
void TAIAsetTargetOtama::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  bl        -0x42DB0
	  rlwinm.   r0,r3,0,24,31
	  addi      r31, r3, 0
	  beq-      .loc_0x78
	  bl        0x2BE04
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x3EF0(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x3EF8(r2)
	  stw       r0, 0x18(r1)
	  lfs       f1, -0x3F44(r2)
	  lfd       f3, 0x18(r1)
	  lfs       f0, -0x3F4C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x70
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x0(r30)
	  b         .loc_0x78

	.loc_0x70:
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x0(r30)

	.loc_0x78:
	  mr        r3, r31
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
 * Address:	801EC2D8
 * Size:	0000C0
 */
void TAIAwaitOtama::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r4
	  bl        -0x3F5F0
	  lfs       f0, -0x3F58(r2)
	  li        r4, 0x32
	  stfs      f0, 0x478(r31)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC9E3C
	  lwz       r3, 0x2C4(r31)
	  fmr       f30, f1
	  li        r4, 0x33
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC9E54
	  fmr       f31, f1
	  bl        0x2BD40
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x64(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x84(r3)
	  fsubs     f0, f31, f30
	  stw       r0, 0x60(r1)
	  lfd       f3, -0x3EF0(r2)
	  li        r4, 0x32
	  lfd       f2, 0x60(r1)
	  lfs       f1, -0x3EF8(r2)
	  fsubs     f2, f2, f3
	  lwz       r3, 0x4(r3)
	  fdivs     f1, f2, f1
	  fmuls     f30, f0, f1
	  bl        -0xC9E9C
	  fadds     f0, f1, f30
	  stfs      f0, 0x47C(r31)
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EC398
 * Size:	0000E0
 */
void TAIAwaitOtama::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  li        r31, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  bl        -0x3F4FC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x478(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r30)

	.loc_0x3C:
	  lfs       f0, 0xA4(r30)
	  lfs       f1, -0x3EE8(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0xAC(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xAC(r30)
	  lwz       r3, 0xA4(r30)
	  lwz       r0, 0xA8(r30)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0xAC(r30)
	  stw       r0, 0x78(r30)
	  lfs       f1, 0x478(r30)
	  lfs       f0, 0x47C(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC4
	  lfs       f1, 0xA4(r30)
	  lfs       f0, -0x3F58(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x94
	  fneg      f1, f1

	.loc_0x94:
	  lfs       f0, -0x3EE4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xC4
	  lfs       f1, 0xAC(r30)
	  lfs       f0, -0x3F58(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB4
	  fneg      f1, f1

	.loc_0xB4:
	  lfs       f0, -0x3EE4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xC4
	  li        r31, 0x1

	.loc_0xC4:
	  mr        r3, r31
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}
