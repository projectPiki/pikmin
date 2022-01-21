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
 * Address:	8012AAC0
 * Size:	000084
 */
TaiCollecSoundTable::TaiCollecSoundTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x8
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xBA6C
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xE3AF0
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x6E
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
 * Address:	8012AB44
 * Size:	000484
 */
TaiCollecParameters::TaiCollecParameters()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  li        r5, 0x3C
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  addi      r31, r4, 0x7060
	  li        r4, 0x15
	  stw       r30, 0xD8(r1)
	  addi      r30, r3, 0
	  bl        0x211DC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x7C20
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  li        r0, 0x32
	  lwz       r4, 0x84(r30)
	  li        r9, 0x33
	  li        r8, 0x34
	  lwz       r4, 0x0(r4)
	  li        r7, 0x35
	  mulli     r3, r3, 0xC
	  lwz       r4, 0x8(r4)
	  add       r4, r4, r3
	  addi      r3, r31, 0x1C
	  stw       r3, 0x0(r4)
	  li        r3, 0
	  li        r6, 0x36
	  stw       r3, 0x4(r4)
	  li        r3, 0x14
	  li        r5, 0x37
	  stw       r3, 0x8(r4)
	  li        r4, 0x38
	  li        r3, 0x39
	  lwz       r10, 0x84(r30)
	  mulli     r11, r0, 0xC
	  lwz       r12, 0x4(r10)
	  addi      r10, r31, 0x28
	  lwz       r0, 0x8(r12)
	  mulli     r9, r9, 0xC
	  add       r11, r0, r11
	  stw       r10, 0x0(r11)
	  mulli     r8, r8, 0xC
	  lfs       f7, -0x5D60(r2)
	  mulli     r7, r7, 0xC
	  stfs      f7, 0x4(r11)
	  lfs       f0, -0x5D5C(r2)
	  mulli     r6, r6, 0xC
	  stfs      f0, 0x8(r11)
	  add       r10, r0, r9
	  addi      r9, r31, 0x38
	  stw       r9, 0x0(r10)
	  mulli     r5, r5, 0xC
	  stfs      f7, 0x4(r10)
	  add       r9, r0, r8
	  stfs      f0, 0x8(r10)
	  addi      r8, r31, 0x48
	  mulli     r4, r4, 0xC
	  stw       r8, 0x0(r9)
	  stfs      f7, 0x4(r9)
	  mulli     r3, r3, 0xC
	  lfs       f0, -0x5D58(r2)
	  add       r8, r0, r7
	  stfs      f0, 0x8(r9)
	  addi      r7, r31, 0x64
	  add       r9, r0, r6
	  stw       r7, 0x0(r8)
	  addi      r6, r31, 0x78
	  add       r7, r0, r5
	  stfs      f7, 0x4(r8)
	  addi      r5, r31, 0x98
	  add       r10, r0, r4
	  lfs       f6, -0x5D54(r2)
	  addi      r4, r31, 0xB4
	  add       r11, r0, r3
	  stfs      f6, 0x8(r8)
	  addi      r3, r31, 0xC0
	  stw       r6, 0x0(r9)
	  stfs      f7, 0x4(r9)
	  lfs       f5, -0x5D50(r2)
	  stfs      f5, 0x8(r9)
	  stw       r5, 0x0(r7)
	  stfs      f7, 0x4(r7)
	  lfs       f2, -0x5D4C(r2)
	  lfs       f4, -0x1CA4(r13)
	  fmuls     f0, f2, f4
	  stfs      f0, 0x8(r7)
	  stw       r4, 0x0(r10)
	  stfs      f7, 0x4(r10)
	  lfs       f0, -0x5D48(r2)
	  stfs      f0, 0x8(r10)
	  stw       r3, 0x0(r11)
	  li        r3, 0x3A
	  stfs      f7, 0x4(r11)
	  mulli     r3, r3, 0xC
	  stfs      f6, 0x8(r11)
	  add       r4, r0, r3
	  addi      r3, r31, 0xD4
	  stw       r3, 0x0(r4)
	  li        r3, 0x3B
	  mulli     r3, r3, 0xC
	  stfs      f7, 0x4(r4)
	  stfs      f6, 0x8(r4)
	  add       r3, r0, r3
	  addi      r0, r31, 0xE8
	  stw       r0, 0x0(r3)
	  li        r7, 0x1
	  li        r6, -0x1
	  stfs      f7, 0x4(r3)
	  li        r0, 0x2
	  li        r5, 0x3
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0x84(r30)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x18(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D44(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D40(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D3C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5D38(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D34(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D30(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D2C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x5D28(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D24(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0xB4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x80(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D20(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x84(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x5D1C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x88(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x8C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x90(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x94(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x9C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5D18(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xA0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0xAC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D14(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xB0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D10(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5D0C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5D08(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0xD8(r3)
	  lfs       f0, -0x5D04(r2)
	  mr        r3, r30
	  lwz       r5, 0x4(r4)
	  fmuls     f0, f0, f4
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xDC(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0xE0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xE4(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5D00(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xE8(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0xEC(r4)
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012AFC8
 * Size:	00179C
 */
TaiCollecStrategy::TaiCollecStrategy(TekiParameters*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x280(r1)
	  stmw      r14, 0x238(r1)
	  mr        r23, r3
	  stw       r4, 0x220(r1)
	  li        r4, 0xF
	  bl        -0x3C04
	  lis       r3, 0x802C
	  addi      r0, r3, 0x7B68
	  stw       r0, 0x0(r23)
	  li        r3, 0x8
	  bl        -0xE3FF8
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x6140
	  stw       r0, 0x4(r21)

	.loc_0x64:
	  li        r3, 0x8
	  bl        -0xE402C
	  stw       r3, 0x230(r1)
	  lwz       r0, 0x230(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x230(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lwz       r3, 0x230(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x42D8
	  lwz       r3, 0x230(r1)
	  stw       r0, 0x4(r3)

	.loc_0xA8:
	  li        r3, 0x8
	  bl        -0xE4070
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0xDC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, 0x2
	  lis       r3, 0x802C
	  stw       r0, 0x0(r22)
	  addi      r0, r3, 0x677C
	  stw       r0, 0x4(r22)

	.loc_0xDC:
	  li        r3, 0x8
	  bl        -0xE40A4
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x110
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x47F0
	  stw       r0, 0x4(r24)

	.loc_0x110:
	  li        r3, 0x8
	  bl        -0xE40D8
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x144
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x45B8
	  stw       r0, 0x4(r20)

	.loc_0x144:
	  li        r3, 0x24
	  bl        -0xE410C
	  stw       r3, 0x22C(r1)
	  lwz       r3, 0x22C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x164
	  lfs       f1, -0x5CFC(r2)
	  bl        0x2EAC

	.loc_0x164:
	  li        r3, 0x8
	  bl        -0xE412C
	  stw       r3, 0x228(r1)
	  lwz       r0, 0x228(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x228(r1)
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x228(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x6A60
	  lwz       r3, 0x228(r1)
	  stw       r0, 0x4(r3)

	.loc_0x1A8:
	  li        r3, 0x8
	  bl        -0xE4170
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1DC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x3
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x7860
	  stw       r0, 0x4(r29)

	.loc_0x1DC:
	  li        r3, 0x8
	  bl        -0xE41A4
	  stw       r3, 0x224(r1)
	  lwz       r0, 0x224(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x220
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x224(r1)
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0xB
	  lwz       r3, 0x224(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x7490
	  lwz       r3, 0x224(r1)
	  stw       r0, 0x4(r3)

	.loc_0x220:
	  li        r3, 0x14
	  bl        -0xE41E8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x27C
	  lwz       r3, 0x220(r1)
	  lis       r5, 0x802C
	  addi      r6, r5, 0x7AE4
	  lwz       r4, 0x84(r3)
	  lis       r3, 0x802C
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x4(r4)
	  li        r0, 0x8
	  li        r5, 0
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0xEC(r4)
	  lfs       f1, 0xE8(r4)
	  stw       r3, 0x4(r28)
	  stw       r0, 0x0(r28)
	  stw       r6, 0x4(r28)
	  stw       r5, 0x8(r28)
	  stfs      f1, 0xC(r28)
	  stfs      f0, 0x10(r28)

	.loc_0x27C:
	  li        r3, 0x8
	  bl        -0xE4244
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x2B0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r18)
	  addi      r0, r3, 0x7AA0
	  stw       r0, 0x4(r18)

	.loc_0x2B0:
	  li        r3, 0x10
	  bl        -0xE4278
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x2F0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0
	  lis       r3, 0x802C
	  stw       r0, 0x0(r17)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r17)
	  lwz       r0, 0x230(r1)
	  stw       r18, 0x8(r17)
	  stw       r0, 0xC(r17)

	.loc_0x2F0:
	  li        r3, 0x10
	  bl        -0xE42B8
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x32C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, 0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r14)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r14)
	  stw       r18, 0x8(r14)
	  stw       r24, 0xC(r14)

	.loc_0x32C:
	  li        r3, 0x10
	  bl        -0xE42F4
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x368
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r15)
	  li        r0, 0x2
	  lis       r3, 0x802C
	  stw       r0, 0x0(r15)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r15)
	  stw       r18, 0x8(r15)
	  stw       r22, 0xC(r15)

	.loc_0x368:
	  li        r3, 0x10
	  bl        -0xE4330
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x3A4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x3
	  lis       r3, 0x802C
	  stw       r0, 0x0(r16)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r16)
	  stw       r18, 0x8(r16)
	  stw       r29, 0xC(r16)

	.loc_0x3A4:
	  li        r3, 0x10
	  bl        -0xE436C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x3E0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x8
	  lis       r3, 0x802C
	  stw       r0, 0x0(r19)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r19)
	  stw       r18, 0x8(r19)
	  stw       r28, 0xC(r19)

	.loc_0x3E0:
	  li        r3, 0xC
	  bl        -0xE43A8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x428
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  subi      r3, r3, 0x447C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x428:
	  li        r3, 0x8
	  bl        -0xE43F0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x45C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x43C0
	  stw       r0, 0x4(r30)

	.loc_0x45C:
	  li        r3, 0xC
	  bl        -0xE4424
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x478
	  li        r4, 0x3
	  bl        -0x43A4

	.loc_0x478:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r23)
	  stw       r27, 0x0(r4)
	  bl        -0xE4478
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x4F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0x1
	  subi      r3, r3, 0x4650
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x4F8:
	  li        r3, 0xC
	  bl        -0xE44C0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x544
	  lwz       r3, 0x220(r1)
	  lis       r4, 0x802C
	  addi      r4, r4, 0x6620
	  lwz       r5, 0x84(r3)
	  lis       r3, 0x802D
	  li        r0, -0x1
	  lwz       r5, 0x4(r5)
	  subi      r3, r3, 0x434C
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xCC(r5)
	  stw       r4, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r3, 0x4(r30)
	  stfs      f0, 0x8(r30)

	.loc_0x544:
	  li        r3, 0xC
	  bl        -0xE450C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x560
	  li        r4, 0x3
	  bl        -0x448C

	.loc_0x560:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r23)
	  stw       r27, 0x4(r4)
	  bl        -0xE4560
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x5E0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802C
	  stw       r0, 0x4(r29)
	  li        r0, 0x9
	  addi      r3, r3, 0x6704
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x5E0:
	  li        r3, 0xC
	  bl        -0xE45A8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x5FC
	  li        r4, 0x4
	  bl        -0x4528

	.loc_0x5FC:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x230(r1)
	  lwz       r4, 0x8(r30)
	  li        r5, 0x2
	  stwx      r0, r4, r3
	  rlwinm    r0,r5,2,0,29
	  li        r6, 0x3
	  lwz       r4, 0x8(r30)
	  rlwinm    r5,r6,2,0,29
	  li        r3, 0x8
	  stwx      r20, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r23)
	  stw       r30, 0x8(r4)
	  bl        -0xE4610
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x67C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x4
	  lis       r3, 0x802C
	  stw       r0, 0x0(r26)
	  addi      r0, r3, 0x7A58
	  stw       r0, 0x4(r26)

	.loc_0x67C:
	  li        r3, 0x10
	  bl        -0xE4644
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x6E8
	  lwz       r3, 0x220(r1)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x4(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lwz       r3, 0x0(r3)
	  subi      r6, r6, 0x6A6C
	  subi      r5, r5, 0x6A8C
	  lfs       f0, 0xC(r3)
	  li        r3, 0x6
	  subi      r4, r4, 0x6518
	  stw       r7, 0x4(r29)
	  stw       r0, 0x0(r29)
	  stw       r6, 0x4(r29)
	  stw       r3, 0x8(r29)
	  stw       r5, 0x4(r29)
	  stw       r4, 0x4(r29)
	  stfs      f0, 0xC(r29)

	.loc_0x6E8:
	  li        r3, 0xC
	  bl        -0xE46B0
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x724
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x69F0
	  stw       r0, 0x4(r27)
	  lfs       f0, -0x5D1C(r2)
	  stfs      f0, 0x8(r27)

	.loc_0x724:
	  li        r3, 0x14
	  bl        -0xE46EC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x77C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x35D8
	  lis       r3, 0x802C
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  addi      r3, r3, 0x791C
	  stw       r0, 0x8(r30)
	  lfs       f0, -0x5D2C(r2)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x5D60(r2)
	  stfs      f0, 0x10(r30)
	  stw       r3, 0x4(r30)

	.loc_0x77C:
	  li        r3, 0xC
	  bl        -0xE4744
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x798
	  li        r4, 0xA
	  bl        -0x46C4

	.loc_0x798:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x230(r1)
	  li        r7, 0x7
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r4
	  li        r8, 0x3
	  li        r3, 0x4
	  lwz       r4, 0x8(r31)
	  li        r9, 0x5
	  li        r10, 0x6
	  stwx      r22, r4, r0
	  rlwinm    r0,r8,2,0,29
	  rlwinm    r8,r9,2,0,29
	  lwz       r5, 0x8(r31)
	  li        r4, 0x9
	  rlwinm    r9,r10,2,0,29
	  stwx      r20, r5, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r7,r7,2,0,29
	  li        r6, 0x8
	  stwx      r26, r3, r0
	  rlwinm    r0,r6,2,0,29
	  lwz       r6, 0x22C(r1)
	  li        r3, 0x8
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r8
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r9
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r6, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r23)
	  stw       r31, 0xC(r4)
	  bl        -0xE4810
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x87C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, 0x3
	  lis       r3, 0x802C
	  stw       r0, 0x0(r25)
	  addi      r0, r3, 0x78A4
	  stw       r0, 0x4(r25)

	.loc_0x87C:
	  li        r3, 0x8
	  bl        -0xE4844
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x8B0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r26)
	  addi      r0, r3, 0x7A58
	  stw       r0, 0x4(r26)

	.loc_0x8B0:
	  li        r3, 0x8
	  bl        -0xE4878
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x8E4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x5
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x7814
	  stw       r0, 0x4(r29)

	.loc_0x8E4:
	  li        r3, 0x10
	  bl        -0xE48AC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x950
	  lwz       r3, 0x220(r1)
	  lis       r5, 0x802C
	  addi      r0, r5, 0x6620
	  lwz       r4, 0x84(r3)
	  lis       r3, 0x802D
	  li        r6, -0x1
	  lwz       r4, 0x4(r4)
	  subi      r5, r3, 0x6A6C
	  lis       r7, 0x802D
	  lwz       r4, 0x0(r4)
	  subi      r3, r7, 0x6A8C
	  lis       r8, 0x802D
	  lfs       f0, 0x10(r4)
	  li        r4, 0x6
	  stw       r0, 0x4(r30)
	  subi      r0, r8, 0x6574
	  stw       r6, 0x0(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x8(r30)
	  stw       r3, 0x4(r30)
	  stw       r0, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0x950:
	  li        r3, 0x8
	  bl        -0xE4918
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x984
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x3
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x796C
	  stw       r0, 0x4(r27)

	.loc_0x984:
	  li        r3, 0xC
	  bl        -0xE494C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x9A0
	  li        r4, 0xB
	  bl        -0x48CC

	.loc_0x9A0:
	  li        r0, 0
	  lwz       r4, 0x8(r31)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x230(r1)
	  li        r8, 0x5
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  li        r10, 0x6
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x2
	  stwx      r24, r3, r0
	  rlwinm    r0,r5,2,0,29
	  li        r7, 0x3
	  lwz       r4, 0x8(r31)
	  li        r3, 0x4
	  rlwinm    r8,r8,2,0,29
	  stwx      r22, r4, r0
	  li        r4, 0x8
	  rlwinm    r0,r7,2,0,29
	  lwz       r5, 0x8(r31)
	  li        r6, 0x7
	  rlwinm    r7,r6,2,0,29
	  stwx      r20, r5, r0
	  rlwinm    r0,r3,2,0,29
	  li        r5, 0xA
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r10,r10,2,0,29
	  stwx      r27, r3, r0
	  li        r9, 0x9
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r9,2,0,29
	  stwx      r25, r3, r8
	  li        r3, 0xC
	  lwz       r5, 0x8(r31)
	  stwx      r26, r5, r10
	  lwz       r5, 0x8(r31)
	  stwx      r30, r5, r7
	  lwz       r7, 0x22C(r1)
	  lwz       r5, 0x8(r31)
	  stwx      r7, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r6
	  lwz       r4, 0x8(r23)
	  stw       r31, 0x10(r4)
	  bl        -0xE4A28
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xA9C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x7
	  stw       r3, 0x4(r29)
	  stw       r0, 0x8(r29)

	.loc_0xA9C:
	  li        r3, 0xC
	  bl        -0xE4A64
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xAD8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x6
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6B20
	  stw       r0, 0x4(r28)
	  lwz       r0, -0x990(r13)
	  stw       r0, 0x8(r28)

	.loc_0xAD8:
	  li        r3, 0x8
	  bl        -0xE4AA0
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xB0C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x77D0
	  stw       r0, 0x4(r27)

	.loc_0xB0C:
	  li        r3, 0xC
	  bl        -0xE4AD4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xB28
	  li        r4, 0xA
	  bl        -0x4A54

	.loc_0xB28:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x3
	  stwx      r17, r4, r0
	  li        r0, 0x5
	  li        r9, 0x6
	  lwz       r4, 0x8(r31)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r3,r3,2,0,29
	  stwx      r14, r4, r5
	  li        r5, 0x7
	  li        r7, 0x4
	  lwz       r4, 0x8(r31)
	  li        r6, 0x9
	  rlwinm    r0,r0,2,0,29
	  stwx      r15, r4, r3
	  rlwinm    r3,r7,2,0,29
	  rlwinm    r7,r6,2,0,29
	  lwz       r4, 0x8(r31)
	  rlwinm    r9,r9,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r16, r4, r3
	  li        r8, 0x8
	  rlwinm    r4,r8,2,0,29
	  lwz       r6, 0x8(r31)
	  li        r3, 0x10
	  stwx      r20, r6, r0
	  lwz       r0, 0x228(r1)
	  lwz       r6, 0x8(r31)
	  stwx      r28, r6, r9
	  lwz       r6, 0x8(r31)
	  stwx      r29, r6, r5
	  lwz       r5, 0x8(r31)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r7
	  lwz       r4, 0x8(r23)
	  stw       r31, 0x14(r4)
	  bl        -0xE4B9C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC30
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x8
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r4, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x7
	  lis       r3, 0x802C
	  stw       r0, 0x8(r30)
	  subi      r0, r4, 0x6A8C
	  addi      r3, r3, 0x75C0
	  stw       r0, 0x4(r30)
	  li        r0, 0x3
	  stw       r3, 0x4(r30)
	  stw       r0, 0xC(r30)

	.loc_0xC30:
	  li        r3, 0x8
	  bl        -0xE4BF8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xC64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0xE
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x751C
	  stw       r0, 0x4(r28)

	.loc_0xC64:
	  li        r3, 0x8
	  bl        -0xE4C2C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xC98
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x8
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x7680
	  stw       r0, 0x4(r27)

	.loc_0xC98:
	  li        r3, 0x8
	  bl        -0xE4C60
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0xCCC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x7
	  lis       r3, 0x802C
	  stw       r0, 0x0(r24)
	  addi      r0, r3, 0x76C8
	  stw       r0, 0x4(r24)

	.loc_0xCCC:
	  li        r3, 0x8
	  bl        -0xE4C94
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0xD00
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r22)
	  addi      r0, r3, 0x7790
	  stw       r0, 0x4(r22)

	.loc_0xD00:
	  li        r3, 0xC
	  bl        -0xE4CC8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xD1C
	  li        r4, 0xD
	  bl        -0x4C48

	.loc_0xD1C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x224(r1)
	  li        r6, 0x4
	  stwx      r0, r3, r4
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r0, 0x2
	  li        r7, 0x5
	  stwx      r17, r4, r5
	  li        r3, 0x3
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r9, 0x8
	  stwx      r14, r4, r0
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r7,r7,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0x9
	  li        r8, 0x6
	  stwx      r15, r4, r5
	  li        r0, 0x7
	  rlwinm    r9,r9,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r5, 0xA
	  li        r11, 0xB
	  stwx      r16, r4, r6
	  rlwinm    r4,r8,2,0,29
	  rlwinm    r8,r0,2,0,29
	  lwz       r6, 0x8(r31)
	  li        r10, 0xC
	  rlwinm    r0,r10,2,0,29
	  stwx      r20, r6, r7
	  rlwinm    r7,r3,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r11,2,0,29
	  stwx      r24, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r8
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r9
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r5
	  lwz       r5, 0x228(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r23)
	  stw       r31, 0x18(r4)
	  bl        -0xE4DC4
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xE30
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x770C
	  stw       r0, 0x4(r28)

	.loc_0xE30:
	  li        r3, 0x10
	  bl        -0xE4DF8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xE6C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x4
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r29)
	  stw       r18, 0x8(r29)
	  stw       r28, 0xC(r29)

	.loc_0xE6C:
	  li        r3, 0xC
	  bl        -0xE4E34
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xEA8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xA
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0xEA8:
	  li        r3, 0x8
	  bl        -0xE4E70
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xEDC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x7750
	  stw       r0, 0x4(r27)

	.loc_0xEDC:
	  li        r3, 0xC
	  bl        -0xE4EA4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xEF8
	  li        r4, 0x9
	  bl        -0x4E24

	.loc_0xEF8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x224(r1)
	  li        r7, 0x3
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r6, 0x6
	  stwx      r17, r3, r4
	  li        r4, 0x4
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r14, r3, r0
	  li        r5, 0x5
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  li        r8, 0x8
	  stwx      r15, r3, r7
	  rlwinm    r7,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r8,2,0,29
	  stwx      r16, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stwx      r20, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r23)
	  stw       r31, 0x1C(r4)
	  bl        -0xE4F5C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xFD0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x9
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xC
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0xFD0:
	  li        r3, 0x8
	  bl        -0xE4F98
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1004
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x7644
	  stw       r0, 0x4(r27)

	.loc_0x1004:
	  li        r3, 0xC
	  bl        -0xE4FCC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1020
	  li        r4, 0x4
	  bl        -0x4F4C

	.loc_0x1020:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  li        r5, 0x3
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x2
	  stwx      r27, r3, r0
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r3, 0x14
	  stwx      r28, r4, r0
	  lwz       r0, 0x228(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r23)
	  stw       r29, 0x20(r4)
	  bl        -0xE5034
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x10C8
	  lwz       r3, 0x220(r1)
	  lis       r5, 0x802D
	  subi      r6, r5, 0x35D8
	  lwz       r4, 0x84(r3)
	  lis       r3, 0x802C
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x4(r4)
	  li        r0, 0xA
	  li        r5, 0x1
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0xD8(r4)
	  lfs       f1, 0xD4(r4)
	  stw       r3, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r5, 0x8(r30)
	  stfs      f1, 0xC(r30)
	  stfs      f0, 0x10(r30)

	.loc_0x10C8:
	  li        r3, 0x10
	  bl        -0xE5090
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x111C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  addi      r3, r3, 0x6B14
	  li        r0, 0
	  stw       r3, 0x4(r29)
	  lwz       r4, -0x9D4(r13)
	  lwz       r3, -0x9C8(r13)
	  lwz       r5, -0x9D0(r13)
	  or        r3, r4, r3
	  or        r3, r5, r3
	  stw       r3, 0x8(r29)
	  stb       r0, 0xC(r29)

	.loc_0x111C:
	  li        r3, 0x8
	  bl        -0xE50E4
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1150
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x60FC
	  stw       r0, 0x4(r27)

	.loc_0x1150:
	  li        r3, 0xC
	  bl        -0xE5118
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x116C
	  li        r4, 0x4
	  bl        -0x5098

	.loc_0x116C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x3
	  stwx      r21, r4, r0
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0xC
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r23)
	  stw       r28, 0x24(r4)
	  bl        -0xE517C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x11F0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xB
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0x11F0:
	  li        r3, 0x10
	  bl        -0xE51B8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1244
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r30)
	  addi      r3, r3, 0x6B14
	  li        r0, 0x1
	  stw       r3, 0x4(r30)
	  lwz       r4, -0x9D4(r13)
	  lwz       r3, -0x9C8(r13)
	  lwz       r5, -0x9D0(r13)
	  or        r3, r4, r3
	  or        r3, r5, r3
	  stw       r3, 0x8(r30)
	  stb       r0, 0xC(r30)

	.loc_0x1244:
	  li        r3, 0x8
	  bl        -0xE520C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1278
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x7368
	  stw       r0, 0x4(r27)

	.loc_0x1278:
	  li        r3, 0xC
	  bl        -0xE5240
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1294
	  li        r4, 0x5
	  bl        -0x51C0

	.loc_0x1294:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x230(r1)
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  rlwinm    r6,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r5, 0x2
	  li        r0, 0x3
	  stwx      r4, r3, r6
	  li        r4, 0x4
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r28, r3, r5
	  li        r3, 0x8
	  lwz       r5, 0x8(r29)
	  stwx      r27, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r23)
	  stw       r29, 0x28(r4)
	  bl        -0xE52B8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1324
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0xC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x7440
	  stw       r0, 0x4(r28)

	.loc_0x1324:
	  li        r3, 0xC
	  bl        -0xE52EC
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x1340
	  li        r4, 0x1
	  bl        -0x526C

	.loc_0x1340:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r3, 0xC
	  lwz       r4, 0x8(r23)
	  stw       r25, 0x2C(r4)
	  bl        -0xE5320
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x13A0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x13A0:
	  li        r3, 0xC
	  bl        -0xE5368
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x13EC
	  lwz       r3, 0x220(r1)
	  lis       r4, 0x802C
	  addi      r4, r4, 0x6620
	  lwz       r5, 0x84(r3)
	  lis       r3, 0x802D
	  li        r0, -0x1
	  lwz       r5, 0x4(r5)
	  subi      r3, r3, 0x6828
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xDC(r5)
	  stw       r4, 0x4(r31)
	  stw       r0, 0x0(r31)
	  stw       r3, 0x4(r31)
	  stfs      f0, 0x8(r31)

	.loc_0x13EC:
	  li        r3, 0x8
	  bl        -0xE53B4
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x1420
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0
	  lis       r3, 0x802C
	  stw       r0, 0x0(r26)
	  addi      r0, r3, 0x73EC
	  stw       r0, 0x4(r26)

	.loc_0x1420:
	  li        r3, 0x8
	  bl        -0xE53E8
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1454
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xD
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x73A8
	  stw       r0, 0x4(r27)

	.loc_0x1454:
	  li        r3, 0xC
	  bl        -0xE541C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1490
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r3, r3, 0x6AD8
	  li        r0, 0x74
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0x1490:
	  li        r3, 0xC
	  bl        -0xE5458
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x14AC
	  li        r4, 0x6
	  bl        -0x53D8

	.loc_0x14AC:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r30)
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x3
	  stwx      r29, r3, r4
	  li        r3, 0x4
	  li        r4, 0x5
	  lwz       r6, 0x8(r30)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r6, r5
	  rlwinm    r5,r3,2,0,29
	  rlwinm    r6,r4,2,0,29
	  lwz       r4, 0x8(r30)
	  li        r3, 0xC
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r27, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r23)
	  stw       r30, 0x30(r4)
	  bl        -0xE54DC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1550
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xD
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0x1550:
	  li        r3, 0xC
	  bl        -0xE5518
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x159C
	  lwz       r3, 0x220(r1)
	  lis       r4, 0x802C
	  addi      r4, r4, 0x6620
	  lwz       r5, 0x84(r3)
	  lis       r3, 0x802D
	  li        r0, -0x1
	  lwz       r5, 0x4(r5)
	  subi      r3, r3, 0x434C
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xC8(r5)
	  stw       r4, 0x4(r29)
	  stw       r0, 0x0(r29)
	  stw       r3, 0x4(r29)
	  stfs      f0, 0x8(r29)

	.loc_0x159C:
	  li        r3, 0xC
	  bl        -0xE5564
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x15B8
	  li        r4, 0x3
	  bl        -0x54E4

	.loc_0x15B8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r4
	  li        r3, 0x14
	  lwz       r4, 0x8(r27)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r23)
	  stw       r27, 0x34(r4)
	  bl        -0xE55B8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x164C
	  lwz       r3, 0x220(r1)
	  lis       r5, 0x802D
	  subi      r6, r5, 0x35D8
	  lwz       r4, 0x84(r3)
	  lis       r3, 0x802C
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x4(r4)
	  li        r0, 0xA
	  li        r5, 0x1
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0xE8(r4)
	  stw       r3, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r5, 0x8(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x5D60(r2)
	  stfs      f0, 0x10(r30)

	.loc_0x164C:
	  li        r3, 0x10
	  bl        -0xE5614
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1688
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x8
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x7BB0
	  stw       r0, 0x4(r29)
	  stw       r18, 0x8(r29)
	  stw       r30, 0xC(r29)

	.loc_0x1688:
	  li        r3, 0x8
	  bl        -0xE5650
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x16BC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x74D4
	  stw       r0, 0x4(r27)

	.loc_0x16BC:
	  li        r3, 0xC
	  bl        -0xE5684
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x16D8
	  li        r4, 0xA
	  bl        -0x5604

	.loc_0x16D8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  lwz       r4, 0x224(r1)
	  rlwinm    r0,r0,2,0,29
	  li        r8, 0x4
	  stwx      r4, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r17, r3, r5
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r4, 0x9
	  li        r5, 0x5
	  stwx      r14, r3, r0
	  li        r0, 0x7
	  li        r9, 0x6
	  lwz       r7, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x8
	  stwx      r15, r7, r6
	  rlwinm    r7,r8,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r8, 0x8(r31)
	  rlwinm    r5,r9,2,0,29
	  stwx      r16, r8, r7
	  rlwinm    r8,r4,2,0,29
	  rlwinm    r7,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  mr        r3, r23
	  stwx      r20, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r24, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r22, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r8
	  lwz       r4, 0x8(r23)
	  stw       r31, 0x38(r4)
	  lmw       r14, 0x238(r1)
	  lwz       r0, 0x284(r1)
	  addi      r1, r1, 0x280
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012C764
 * Size:	000168
 */
void TaiCollecStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x34
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  li        r4, 0x61
	  lfs       f0, -0x174C(r13)
	  lfs       f1, -0x1748(r13)
	  stfs      f0, 0x34(r1)
	  lfs       f0, -0x1744(r13)
	  stfs      f1, 0x38(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x3C(r1)
	  bl        0x7038C
	  lwz       r5, 0x3D8(r31)
	  li        r4, 0
	  stw       r3, 0x0(r5)
	  mr        r3, r31
	  bl        0x1D25C
	  lfs       f0, -0x1740(r13)
	  addi      r5, r1, 0x28
	  lfs       f1, -0x173C(r13)
	  li        r4, 0x62
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x1738(r13)
	  li        r6, 0
	  stfs      f1, 0x2C(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x30(r1)
	  bl        0x70348
	  lwz       r5, 0x3D8(r31)
	  li        r4, 0x1
	  stw       r3, 0x4(r5)
	  mr        r3, r31
	  bl        0x1D218
	  lfs       f0, -0x1734(r13)
	  addi      r5, r1, 0x1C
	  lfs       f1, -0x1730(r13)
	  li        r4, 0x5E
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x172C(r13)
	  li        r6, 0
	  stfs      f1, 0x20(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x24(r1)
	  bl        0x70304
	  lwz       r5, 0x3D8(r31)
	  li        r4, 0x2
	  stw       r3, 0x8(r5)
	  mr        r3, r31
	  bl        0x1D1D4
	  lfs       f0, -0x1728(r13)
	  addi      r5, r1, 0x10
	  lfs       f1, -0x1724(r13)
	  li        r4, 0x5D
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x1720(r13)
	  li        r6, 0
	  stfs      f1, 0x14(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x18(r1)
	  bl        0x702C0
	  lwz       r5, 0x3D8(r31)
	  li        r4, 0x3
	  stw       r3, 0xC(r5)
	  mr        r3, r31
	  bl        0x1D190
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x5404
	  mr        r3, r31
	  lwz       r4, -0x9C0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8012C8CC
 * Size:	000110
 */
void TaiCollecStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r4
	  bl        0x208E0
	  lwz       r3, 0x3D8(r30)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  addi      r5, r30, 0x94
	  addi      r3, r30, 0
	  li        r4, 0x3
	  bl        0x1D13C
	  mr        r3, r30
	  bl        0x1D028
	  cmpwi     r3, 0x5
	  bne-      .loc_0x6C
	  lwz       r3, 0x3D8(r30)
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  b         .loc_0x88

	.loc_0x6C:
	  lwz       r3, 0x3D8(r30)
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)

	.loc_0x88:
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  addi      r31, r3, 0x94
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  li        r4, 0x2
	  bl        0x1D0D0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1CF74
	  cmpwi     r3, 0x5
	  bne-      .loc_0xDC
	  lwz       r3, 0x3D8(r30)
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  b         .loc_0xF8

	.loc_0xDC:
	  lwz       r3, 0x3D8(r30)
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)

	.loc_0xF8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void TaiCollecStrategy::outputUndergroundPosition(Teki&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8012C9DC
 * Size:	0001F0
 */
void TekiCollecTargetPelletCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x34
	  beq-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x1D0

	.loc_0x34:
	  lwz       r3, 0x55C(r4)
	  addi      r31, r4, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  lwz       r0, 0x5C(r3)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x5C

	.loc_0x58:
	  li        r0, 0

	.loc_0x5C:
	  cmpwi     r0, 0
	  beq-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0x1D0

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r4, 0x8(r30)
	  bl        -0x96928
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x88
	  li        r3, 0
	  b         .loc_0x1D0

	.loc_0x88:
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x8(r30)
	  lwz       r3, 0x7C(r3)
	  cmpw      r3, r0
	  ble-      .loc_0xA4
	  li        r3, 0
	  b         .loc_0x1D0

	.loc_0xA4:
	  addi      r3, r1, 0x48
	  addi      r4, r31, 0
	  bl        -0x9BE04
	  addi      r29, r1, 0x48
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x15C

	.loc_0xD0:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xF4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x10C

	.loc_0xF4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x10C:
	  cmplwi    r3, 0
	  beq-      .loc_0x1B8
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x37
	  bne-      .loc_0x140
	  lwz       r0, 0x4(r30)
	  cmplw     r3, r0
	  beq-      .loc_0x140
	  lwz       r0, 0x320(r3)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x140
	  li        r3, 0
	  b         .loc_0x1D0

	.loc_0x140:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x15C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x184
	  li        r0, 0x1
	  b         .loc_0x1B0

	.loc_0x184:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1AC
	  li        r0, 0x1
	  b         .loc_0x1B0

	.loc_0x1AC:
	  li        r0, 0

	.loc_0x1B0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD0

	.loc_0x1B8:
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1CC
	  li        r3, 0
	  b         .loc_0x1D0

	.loc_0x1CC:
	  li        r3, 0x1

	.loc_0x1D0:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012CBCC
 * Size:	000040
 */
void TaiCollecImpassableAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x330(r4)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x30
	  cmpwi     r0, 0x4
	  beq-      .loc_0x30
	  cmpwi     r0, 0x6
	  bne-      .loc_0x2C
	  b         .loc_0x30

	.loc_0x2C:
	  bl        0xC0

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012CC0C
 * Size:	0000AC
 */
void TaiCollecImpassableAction::act(Teki&)
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
	  lfs       f2, 0x9C(r4)
	  lfs       f3, 0x390(r4)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x11F00C
	  lfs       f0, 0x10(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x68
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xAC
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x68:
	  lwz       r0, 0x8(r30)
	  lfs       f0, -0x5D60(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  lfs       f1, 0x3C4(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x90
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x90:
	  li        r3, 0x1

	.loc_0x94:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0xAC:
	*/
}

/*
 * --INFO--
 * Address:	8012CCB8
 * Size:	000030
 */
void TaiCollecImpassableAction::resetPosition(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x94(r4)
	  stfs      f0, 0x388(r4)
	  lfs       f0, 0x98(r4)
	  stfs      f0, 0x38C(r4)
	  lfs       f0, 0x9C(r4)
	  stfs      f0, 0x390(r4)
	  lwz       r0, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r4, r0
	  stfs      f0, 0x3C4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012CCE8
 * Size:	000070
 */
void TaiCollecLetGoOfPelletAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0x1
	  b         .loc_0x5C

	.loc_0x28:
	  mr        r3, r0
	  addi      r4, r31, 0
	  bl        -0x96C84
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        -0x489BC
	  li        r0, 0
	  stw       r0, 0x420(r31)

	.loc_0x4C:
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        0x1CCE0
	  li        r3, 0x1

	.loc_0x5C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012CD58
 * Size:	000074
 */
void TaiCollecLetGoOfPelletAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  lwz       r3, 0x4(r4)
	  lwz       r0, 0x420(r3)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0x60

	.loc_0x2C:
	  mr        r3, r0
	  addi      r4, r31, 0
	  bl        -0x96CF8
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  bl        -0x48A30
	  li        r0, 0
	  stw       r0, 0x420(r31)

	.loc_0x50:
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        0x1CC6C
	  li        r3, 0x1

	.loc_0x60:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012CDCC
 * Size:	000158
 */
void TaiCollecTargetPelletAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r8, 0x802C
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  addi      r12, r8, 0x7B34
	  stwu      r1, -0x130(r1)
	  lis       r11, 0x802D
	  lis       r9, 0x802C
	  stmw      r25, 0x114(r1)
	  mr        r31, r4
	  subi      r26, r5, 0xF68
	  addi      r29, r9, 0x6890
	  subi      r28, r11, 0x2998
	  addi      r9, r1, 0xE8
	  addi      r30, r1, 0xCC
	  addi      r8, r1, 0xDC
	  addi      r5, r1, 0xFC
	  lwz       r6, 0x2C4(r4)
	  lis       r4, 0x802C
	  addi      r27, r4, 0x6964
	  lwz       r0, 0x424(r31)
	  lwz       r6, 0x84(r6)
	  lwz       r3, 0x301C(r13)
	  addi      r4, r31, 0x94
	  lwz       r7, 0x0(r6)
	  lis       r6, 0x802C
	  lwz       r10, 0x0(r7)
	  lis       r7, 0x802D
	  subi      r11, r7, 0x2AF4
	  lwz       r25, 0x50(r10)
	  addi      r10, r6, 0x685C
	  addi      r7, r1, 0xF0
	  stw       r26, 0xDC(r1)
	  addi      r6, r1, 0xD4
	  stw       r26, 0xF0(r1)
	  stw       r26, 0xFC(r1)
	  stw       r26, 0xCC(r1)
	  stw       r26, 0xD4(r1)
	  stw       r27, 0xDC(r1)
	  stw       r26, 0xE8(r1)
	  stw       r27, 0xF0(r1)
	  stw       r27, 0xFC(r1)
	  stw       r27, 0xCC(r1)
	  stw       r27, 0xD4(r1)
	  stw       r12, 0xDC(r1)
	  stw       r27, 0xE8(r1)
	  stw       r10, 0xF0(r1)
	  stw       r10, 0xFC(r1)
	  stw       r28, 0xCC(r1)
	  stw       r29, 0xD4(r1)
	  stw       r31, 0xE0(r1)
	  stw       r11, 0xE8(r1)
	  stw       r9, 0xF4(r1)
	  stw       r7, 0x100(r1)
	  stw       r0, 0xD0(r1)
	  stw       r30, 0xD8(r1)
	  stw       r25, 0xE4(r1)
	  stw       r31, 0xEC(r1)
	  stw       r8, 0xF8(r1)
	  stw       r6, 0x104(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  bne-      .loc_0x110
	  li        r3, 0
	  b         .loc_0x144

	.loc_0x110:
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  beq-      .loc_0x12C
	  bl        -0x48B80
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0x12C:
	  stw       r30, 0x418(r31)
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x140
	  bl        -0x48BAC

	.loc_0x140:
	  li        r3, 0x1

	.loc_0x144:
	  lmw       r25, 0x114(r1)
	  lwz       r0, 0x134(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012CF24
 * Size:	0000E0
 */
void TaiCollecVisibleHeightPelletLostAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  bne-      .loc_0x30
	  li        r3, 0x1
	  b         .loc_0xC8

	.loc_0x30:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x30(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x30(r1)
	  subi      r0, r3, 0x2B2C
	  stw       r0, 0x30(r1)
	  addi      r3, r1, 0x30
	  stw       r30, 0x34(r1)
	  lwz       r12, 0x30(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC4
	  lwz       r3, 0x424(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x90
	  beq-      .loc_0x90
	  bl        -0x48C3C
	  li        r0, 0
	  stw       r0, 0x424(r30)

	.loc_0x90:
	  stw       r31, 0x424(r30)
	  lwz       r3, 0x424(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  bl        -0x48C68

	.loc_0xA4:
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xBC
	  bl        -0x48C68
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0xBC:
	  li        r3, 0x1
	  b         .loc_0xC8

	.loc_0xC4:
	  li        r3, 0

	.loc_0xC8:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D004
 * Size:	000064
 */
void TaiCollecVisibleHeightPelletLostTimerAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r0, 0x8(r3)
	  lfs       f0, -0x5D60(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  lfs       f1, 0x3C4(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4C
	  lwz       r3, 0x424(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        -0x48CD8
	  li        r0, 0
	  stw       r0, 0x424(r31)

	.loc_0x4C:
	  lwz       r0, 0x24(r1)
	  li        r3, 0
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D068
 * Size:	0000FC
 */
void TaiCollecPelletLostAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stw       r31, 0xAC(r1)
	  mr        r31, r4
	  lwz       r0, 0x418(r4)
	  cmplwi    r0, 0
	  mr        r4, r0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0xE8

	.loc_0x2C:
	  lwz       r3, 0x2C4(r31)
	  lis       r7, 0x802D
	  lis       r9, 0x802B
	  lwz       r3, 0x84(r3)
	  lis       r8, 0x802C
	  lis       r6, 0x802C
	  lwz       r10, 0x0(r3)
	  lis       r5, 0x802C
	  subi      r7, r7, 0x2AF4
	  lwz       r11, 0x0(r10)
	  subi      r10, r9, 0xF68
	  addi      r9, r8, 0x6964
	  lwz       r11, 0x50(r11)
	  addi      r8, r6, 0x7B34
	  addi      r6, r5, 0x685C
	  stw       r10, 0x84(r1)
	  addi      r5, r1, 0x90
	  addi      r0, r1, 0x84
	  stw       r10, 0x98(r1)
	  addi      r3, r1, 0x98
	  stw       r9, 0x84(r1)
	  stw       r10, 0x90(r1)
	  stw       r9, 0x98(r1)
	  stw       r8, 0x84(r1)
	  stw       r9, 0x90(r1)
	  stw       r6, 0x98(r1)
	  stw       r31, 0x88(r1)
	  stw       r7, 0x90(r1)
	  stw       r5, 0x9C(r1)
	  stw       r11, 0x8C(r1)
	  stw       r31, 0x94(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r12, 0x98(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xE4
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xDC
	  bl        -0x48DCC
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0xDC:
	  li        r3, 0x1
	  b         .loc_0xE8

	.loc_0xE4:
	  li        r3, 0

	.loc_0xE8:
	  lwz       r0, 0xB4(r1)
	  lwz       r31, 0xAC(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D164
 * Size:	0000BC
 */
void TaiCollecPelletDisappearedAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r4, 0xC(r1)
	  lwz       r31, 0xC(r1)
	  lwz       r0, 0x420(r31)
	  addi      r30, r31, 0x420
	  cmplwi    r0, 0
	  mr        r4, r0
	  bne-      .loc_0x38
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0x38:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x3C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x3C(r1)
	  subi      r0, r3, 0x2AF4
	  stw       r0, 0x3C(r1)
	  addi      r3, r1, 0x3C
	  stw       r31, 0x40(r1)
	  lwz       r12, 0x3C(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA0
	  lwz       r0, 0x0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  lwz       r3, 0x420(r31)
	  bl        -0x48E84
	  li        r0, 0
	  stw       r0, 0x420(r31)

	.loc_0x98:
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r3, 0

	.loc_0xA4:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D220
 * Size:	000110
 */
void TaiCollecHoldPelletAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0xF4

	.loc_0x34:
	  mr        r3, r30
	  bl        0x1C848
	  lfs       f31, -0x5D50(r2)
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x50
	  li        r3, 0
	  b         .loc_0xF4

	.loc_0x50:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x188(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f31, f1
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0x972E0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x9C
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x94
	  bl        -0x48F3C
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x94:
	  li        r3, 0
	  b         .loc_0xF4

	.loc_0x9C:
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  bl        -0x48F5C
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0xB4:
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  beq-      .loc_0xD0
	  bl        -0x48F78
	  li        r0, 0
	  stw       r0, 0x420(r30)

	.loc_0xD0:
	  stw       r31, 0x420(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  bl        -0x48FA4

	.loc_0xE4:
	  addi      r3, r30, 0
	  li        r4, 0x2
	  bl        0x1C6EC
	  li        r3, 0x1

	.loc_0xF4:
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D330
 * Size:	000050
 */
void TaiCollecCatchingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2CC(r31)
	  lwz       r3, 0x28(r3)
	  lfs       f0, 0x34(r3)
	  stfs      f0, 0x3B4(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D380
 * Size:	000034
 */
void TaiCollecCatchingAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D3B4
 * Size:	000034
 */
void TaiCollecCarryingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D3E8
 * Size:	000034
 */
void TaiCollecCarryingAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D41C
 * Size:	0000B8
 */
void TaiCollecCarryingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  mr        r29, r4
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x9C

	.loc_0x30:
	  lwz       r3, 0x2C4(r29)
	  addi      r4, r29, 0xA4
	  mr        r31, r0
	  lwz       r5, 0x84(r3)
	  addi      r3, r1, 0x50
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r30, 0x50(r5)
	  bl        -0x105EC
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r1, 0x50
	  rlwinm    r6,r30,0,16,31
	  bl        -0x97844
	  lfs       f1, 0xA4(r29)
	  lfs       f0, 0xA8(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xAC(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x11F864
	  mr        r3, r29
	  bl        0x17C90
	  stfs      f1, 0x3B4(r29)
	  li        r3, 0

	.loc_0x9C:
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
 * Address:	8012D4D4
 * Size:	000028
 */
void TaiCollecBeingDraggedAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x3
	  stwu      r1, -0x8(r1)
	  bl        0x1C510
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D4FC
 * Size:	000028
 */
void TaiCollecBeingDraggedAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x3
	  stwu      r1, -0x8(r1)
	  bl        0x1C50C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D524
 * Size:	0000A0
 */
void TaiCollecWinCarryingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  mr        r9, r0
	  bne-      .loc_0x24
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x24:
	  lwz       r3, 0x2C4(r4)
	  lis       r5, 0x802C
	  lis       r7, 0x802B
	  lwz       r8, 0x84(r3)
	  lis       r6, 0x802C
	  addi      r0, r5, 0x7B34
	  lwz       r8, 0x0(r8)
	  subi      r7, r7, 0xF68
	  addi      r6, r6, 0x6964
	  lwz       r8, 0x0(r8)
	  addi      r3, r1, 0x58
	  lwz       r5, 0x50(r8)
	  stw       r7, 0x58(r1)
	  stw       r6, 0x58(r1)
	  stw       r0, 0x58(r1)
	  stw       r4, 0x5C(r1)
	  mr        r4, r9
	  stw       r5, 0x60(r1)
	  lwz       r12, 0x58(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0x1

	.loc_0x90:
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D5C4
 * Size:	0000A0
 */
void TaiCollecDefeatCarryingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  mr        r9, r0
	  bne-      .loc_0x24
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x24:
	  lwz       r3, 0x2C4(r4)
	  lis       r5, 0x802C
	  lis       r7, 0x802B
	  lwz       r8, 0x84(r3)
	  lis       r6, 0x802C
	  addi      r0, r5, 0x7B34
	  lwz       r8, 0x0(r8)
	  subi      r7, r7, 0xF68
	  addi      r6, r6, 0x6964
	  lwz       r8, 0x0(r8)
	  addi      r3, r1, 0x58
	  lwz       r5, 0x50(r8)
	  stw       r7, 0x58(r1)
	  stw       r6, 0x58(r1)
	  stw       r0, 0x58(r1)
	  stw       r4, 0x5C(r1)
	  mr        r4, r9
	  stw       r5, 0x60(r1)
	  lwz       r12, 0x58(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0x1

	.loc_0x90:
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D664
 * Size:	00015C
 */
void TaiCollecPutAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  stw       r30, 0xA8(r1)
	  mr        r30, r4
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x13C

	.loc_0x34:
	  addi      r3, r1, 0x98
	  bl        -0x10848
	  mr        r3, r30
	  bl        0x1B290
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x34
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xB1E4
	  lfs       f30, 0xA0(r30)
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xEE48C
	  stfs      f1, 0x68(r1)
	  fmr       f1, f30
	  addi      r31, r1, 0x68
	  bl        0xEE610
	  stfs      f1, 0x64(r1)
	  addi      r4, r1, 0x64
	  addi      r6, r31, 0
	  addi      r3, r1, 0x98
	  subi      r5, r13, 0x1750
	  bl        -0xD0064
	  lfs       f0, 0x98(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x9C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0x2C8(r30)
	  lfs       f1, 0x98(r1)
	  lfsu      f0, 0x10(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f3, 0xA0(r1)
	  lfs       f2, 0x9C(r30)
	  lfs       f1, 0x98(r1)
	  lfs       f0, 0x94(r30)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x11FB30
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f2, 0xC(r3)
	  bl        0x16DE8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x138
	  li        r3, 0
	  b         .loc_0x13C

	.loc_0x138:
	  li        r3, 0x1

	.loc_0x13C:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D7C0
 * Size:	0000E0
 */
void TaiCollecPuttingPelletAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  addi      r30, r4, 0
	  addi      r31, r30, 0x94
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  li        r4, 0
	  bl        0x1C258
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x1C204
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        0x1C23C
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        0x1C1E8
	  lwz       r0, 0x420(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xC8
	  mr        r31, r0
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0x97798
	  lis       r4, 0x736C
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6F74
	  bl        -0xA412C
	  li        r4, 0
	  bl        -0xA5A58
	  lis       r4, 0x802B
	  subi      r0, r4, 0x3064
	  stw       r0, 0x34(r1)
	  lis       r5, 0x802B
	  subi      r5, r5, 0x3244
	  stw       r30, 0x38(r1)
	  li        r0, 0
	  addi      r4, r1, 0x34
	  stw       r5, 0x34(r1)
	  stw       r0, 0x3C(r1)
	  stw       r3, 0x40(r1)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xC8:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D8A0
 * Size:	000040
 */
void TaiCollecPuttingPelletAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x1C160
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0x1C154
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012D8E0
 * Size:	0000BC
 */
void TaiCollecPuttingPelletAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r4
	  lwz       r31, 0x420(r4)
	  cmplwi    r31, 0
	  bne-      .loc_0x2C
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x2C:
	  lwz       r3, 0x2CC(r30)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xA0
	  mr        r3, r30
	  bl        0x1A4CC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x2C(r1)
	  lis       r4, 0x802B
	  subi      r0, r4, 0x328C
	  stw       r30, 0x30(r1)
	  addi      r3, r31, 0
	  li        r31, 0
	  stw       r0, 0x2C(r1)
	  addi      r4, r1, 0x2C
	  stw       r31, 0x34(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x94
	  bl        -0x49600
	  stw       r31, 0x420(r30)

	.loc_0x94:
	  addi      r3, r30, 0
	  li        r4, 0x2
	  bl        0x1C0A0

	.loc_0xA0:
	  li        r3, 0

	.loc_0xA4:
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
 * Address:	8012D99C
 * Size:	000044
 */
void TaiCollecCarryingToNestAction::start(Teki&)
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
	  bl        0x66B8
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x230
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
 * Address:	8012D9E0
 * Size:	000214
 */
void TaiCollecCarryingToNestAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xA0(r1)
	  addi      r30, r3, 0
	  bl        0x6764
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x54
	  li        r3, 0
	  b         .loc_0x1F0

	.loc_0x54:
	  lwz       r5, 0x34C(r31)
	  lwz       r4, 0x348(r31)
	  cmpw      r5, r4
	  ble-      .loc_0x88
	  lwz       r3, 0x354(r31)
	  subi      r0, r4, 0x1
	  cmpw      r3, r0
	  ble-      .loc_0x88
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x214
	  li        r3, 0
	  b         .loc_0x1F0

	.loc_0x88:
	  lwz       r3, 0x2C4(r31)
	  cmpwi     r5, 0
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x84(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfsx      f29, r3, r0
	  beq-      .loc_0xBC
	  lwz       r4, 0x354(r31)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  ble-      .loc_0x19C

	.loc_0xBC:
	  addi      r3, r1, 0x90
	  bl        -0x10C4C
	  mr        r3, r31
	  bl        0x1AE8C
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x34
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xB5E8
	  lfs       f30, 0xA0(r31)
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xEE088
	  stfs      f1, 0x54(r1)
	  fmr       f1, f30
	  addi      r30, r1, 0x54
	  bl        0xEE20C
	  stfs      f1, 0x50(r1)
	  addi      r4, r1, 0x50
	  addi      r6, r30, 0
	  addi      r3, r1, 0x90
	  subi      r5, r13, 0x1750
	  bl        -0xD0468
	  lfs       f0, 0x90(r1)
	  fmr       f1, f29
	  addi      r3, r31, 0x94
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x90
	  addi      r5, r31, 0xA4
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x98(r1)
	  lwz       r6, 0x2C8(r31)
	  lfs       f2, 0x90(r1)
	  lfsu      f0, 0x10(r6)
	  fadds     f0, f2, f0
	  stfs      f0, 0x90(r1)
	  lfs       f2, 0x94(r1)
	  lfs       f0, 0x4(r6)
	  fadds     f0, f2, f0
	  stfs      f0, 0x94(r1)
	  lfs       f2, 0x98(r1)
	  lfs       f0, 0x8(r6)
	  fadds     f0, f2, f0
	  stfs      f0, 0x98(r1)
	  bl        0x167D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x194
	  li        r3, 0x1
	  b         .loc_0x1F0

	.loc_0x194:
	  li        r3, 0
	  b         .loc_0x1F0

	.loc_0x19C:
	  mr        r3, r31
	  bl        0x1AFFC
	  mr.       r4, r3
	  bne-      .loc_0x1B4
	  li        r3, 0
	  b         .loc_0x1F0

	.loc_0x1B4:
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x1C8
	  li        r3, 0
	  b         .loc_0x1F0

	.loc_0x1C8:
	  fmr       f1, f29
	  addi      r3, r3, 0x94
	  addi      r5, r31, 0xA4
	  bl        0x16784
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1EC
	  lwz       r3, 0x354(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x354(r31)

	.loc_0x1EC:
	  li        r3, 0

	.loc_0x1F0:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x214:
	*/
}

/*
 * --INFO--
 * Address:	8012DBF4
 * Size:	000054
 */
void TaiCollecCarryingToNestAction::makePositionRoute(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  lwz       r3, 0x420(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x40
	  lwz       r5, 0x2C8(r31)
	  addi      r4, r3, 0x94
	  addi      r3, r31, 0
	  addi      r5, r5, 0x10
	  li        r6, 0
	  bl        0x1ADB0
	  li        r0, 0
	  stw       r0, 0x354(r31)

	.loc_0x40:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DC48
 * Size:	0000A0
 */
void TaiCollecRouteImpassableAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x34C(r4)
	  cmpwi     r5, 0
	  bne-      .loc_0x20
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x20:
	  lwz       r6, 0x348(r4)
	  cmpw      r5, r6
	  ble-      .loc_0x44
	  lwz       r3, 0x354(r4)
	  subi      r0, r6, 0x1
	  cmpw      r3, r0
	  ble-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x44:
	  lwz       r6, 0x354(r4)
	  subi      r0, r5, 0x1
	  cmpw      r6, r0
	  ble-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x5C:
	  addi      r3, r4, 0
	  addi      r4, r6, 0
	  bl        0x1AED0
	  cmplwi    r3, 0
	  bne-      .loc_0x78
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x78:
	  lbz       r0, 0x38(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x8C
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0

	.loc_0x90:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DCE8
 * Size:	000014
 */
void TaiCollecRoundCarryAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x1CA4(r13)
	  lfs       f0, 0xA0(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x394(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DCFC
 * Size:	0000E8
 */
void TaiCollecRoundCarryAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  addi      r3, r1, 0x78
	  stfd      f30, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r4
	  lwz       r4, 0x2C4(r4)
	  lwz       r5, 0x3150(r13)
	  lwz       r4, 0x84(r4)
	  lfs       f1, 0x28C(r5)
	  lwz       r4, 0x4(r4)
	  lfs       f2, 0x394(r31)
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0x14(r4)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x394(r31)
	  bl        -0x10EF4
	  lfs       f30, 0x394(r31)
	  fmr       f1, f30
	  bl        0xEDE00
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xEDF88
	  stfs      f1, 0x78(r1)
	  li        r3, 0
	  lfs       f0, -0x1750(r13)
	  stfs      f0, 0x7C(r1)
	  stfs      f31, 0x80(r1)
	  lwz       r4, 0x2C4(r31)
	  lfs       f0, 0x78(r1)
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f1, 0xC(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DDE4
 * Size:	000064
 */
void TaiCollecPelletStartContainerizedAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0x1
	  b         .loc_0x50

	.loc_0x28:
	  mr        r3, r0
	  bl        -0x988D8
	  cmpwi     r3, 0x1
	  bne-      .loc_0x4C
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        0x1BBF8
	  li        r3, 0x1
	  b         .loc_0x50

	.loc_0x4C:
	  li        r3, 0

	.loc_0x50:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DE48
 * Size:	000058
 */
void TaiCollecPelletFinishContainerizedAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r0, 0x184(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x40
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  bl        -0x49B08
	  li        r0, 0
	  stw       r0, 0x420(r31)

	.loc_0x38:
	  li        r3, 0x1
	  b         .loc_0x44

	.loc_0x40:
	  li        r3, 0

	.loc_0x44:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DEA0
 * Size:	000078
 */
void TaiCollecDeadFallingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  lwz       r3, 0x2C4(r4)
	  lfs       f1, 0x58(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC8(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x3C:
	  mr        r3, r31
	  bl        0x1AA80
	  lfs       f2, -0x5D4C(r2)
	  lfs       f0, 0x98(r31)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x60
	  li        r3, 0x1
	  b         .loc_0x64

	.loc_0x60:
	  li        r3, 0

	.loc_0x64:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DF18
 * Size:	000050
 */
void TaiCollecFallingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  bl        0x1AA30
	  lfs       f2, -0x5D4C(r2)
	  lfs       f0, 0x98(r31)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x38
	  li        r3, 0x1
	  b         .loc_0x3C

	.loc_0x38:
	  li        r3, 0

	.loc_0x3C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DF68
 * Size:	00006C
 */
void TaiCollecGetOutAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  lwz       r3, 0x414(r4)
	  lwz       r0, -0x99C(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x54
	  addi      r31, r4, 0x94
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x5F
	  li        r6, 0
	  li        r7, 0
	  bl        0x6EB98
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x60
	  li        r6, 0
	  li        r7, 0
	  bl        0x6EB80

	.loc_0x54:
	  lwz       r0, 0x24(r1)
	  li        r3, 0
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012DFD4
 * Size:	000058
 */
TaiCollecLegEffectAction::TaiCollecLegEffectAction(float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x6C6C
	  stw       r0, 0x4(r1)
	  lis       r4, 0x726C
	  addi      r6, r4, 0x6567
	  stwu      r1, -0x18(r1)
	  addi      r5, r5, 0x6567
	  li        r4, 0x2
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x634
	  lis       r3, 0x802C
	  addi      r0, r3, 0x7324
	  stw       r0, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E02C
 * Size:	000090
 */
void TaiCollecLegEffectAction::setType(Vector3f&, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r5
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r4)
	  lfs       f2, 0x8(r4)
	  li        r4, 0x1
	  bl        -0xC615C
	  cmpwi     r31, 0x5
	  stfs      f1, 0x4(r30)
	  bne-      .loc_0x50
	  li        r0, 0xF
	  stw       r0, 0x14(r29)
	  b         .loc_0x6C

	.loc_0x50:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x64
	  li        r0, -0x1
	  stw       r0, 0x14(r29)
	  b         .loc_0x6C

	.loc_0x64:
	  li        r0, 0x44
	  stw       r0, 0x14(r29)

	.loc_0x6C:
	  li        r0, 0x70
	  stw       r0, 0x18(r29)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E0BC
 * Size:	000088
 */
TaiHollecParameters::TaiHollecParameters()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x14
	  stw       r0, 0x4(r1)
	  li        r5, 0x32
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  bl        0x1DC70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x7264
	  stw       r0, 0x0(r31)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  lwz       r5, 0x84(r31)
	  lwz       r4, 0x0(r5)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0xC(r4)
	  lwz       r4, 0x4(r5)
	  lfs       f0, -0x5D48(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0x4(r5)
	  lfs       f0, -0x5CF8(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x4(r4)
	  lwz       r4, 0x4(r5)
	  lfs       f0, -0x5D50(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x0(r4)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E144
 * Size:	0000C4
 */
TaiHollecStrategy::TaiHollecStrategy(TekiParameters*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  bl        -0x6D84
	  lis       r3, 0x802C
	  addi      r0, r3, 0x71AC
	  stw       r0, 0x0(r29)
	  li        r3, 0xC
	  bl        -0xE7178
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x2
	  stw       r3, 0x4(r31)
	  stw       r0, 0x8(r31)

	.loc_0x70:
	  li        r3, 0xC
	  bl        -0xE71B4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x8C
	  li        r4, 0x1
	  bl        -0x7134

	.loc_0x8C:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  mr        r3, r29
	  lwz       r4, 0x8(r29)
	  stw       r30, 0x0(r4)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E208
 * Size:	000058
 */
void TaiHollecStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  bl        0x1B7A8
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        0x1EF84
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E260
 * Size:	00008C
 */
void TaiHollecStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x6DE0
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E2EC
 * Size:	000060
 */
void TaiDependenceAction::start(Teki&)
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
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  mr        r4, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	8012E34C
 * Size:	000060
 */
void TaiDependenceAction::finish(Teki&)
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
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  mr        r4, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
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
 * Address:	8012E3AC
 * Size:	000070
 */
void TaiDependenceAction::act(Teki&)
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
	  lwz       r3, 0xC(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  lwz       r3, 0x8(r30)
	  mr        r4, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x58

	.loc_0x54:
	  li        r3, 0

	.loc_0x58:
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
 * Address:	8012E41C
 * Size:	000070
 */
void TaiDependenceAction::actByEvent(TekiEvent&)
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
	  lwz       r3, 0xC(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  lwz       r3, 0x8(r30)
	  mr        r4, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x58

	.loc_0x54:
	  li        r3, 0

	.loc_0x58:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
