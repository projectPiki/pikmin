#include "TAI/Napkid.h"
#include "TekiConditions.h"

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
 * Address:	80135C20
 * Size:	000084
 */
TaiNapkidSoundTable::TaiNapkidSoundTable()
    : PaniSoundTable(4)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x16BCC
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xEEC50
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x78
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
 * Address:	80135CA4
 * Size:	000564
 */
TaiNapkidParameters::TaiNapkidParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r5, 0x3F
	  stwu      r1, -0x110(r1)
	  stw       r31, 0x10C(r1)
	  subi      r31, r4, 0x60E0
	  li        r4, 0x15
	  stw       r30, 0x108(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x104(r1)
	  bl        0x16078
	  lis       r3, 0x802D
	  subi      r0, r3, 0x562C
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  li        r0, 0x32
	  lwz       r4, 0x84(r30)
	  li        r10, 0x33
	  li        r9, 0x34
	  lwz       r4, 0x0(r4)
	  li        r8, 0x35
	  mulli     r3, r3, 0xC
	  lwz       r4, 0x8(r4)
	  add       r4, r4, r3
	  addi      r3, r31, 0x1C
	  stw       r3, 0x0(r4)
	  li        r3, 0
	  li        r7, 0x36
	  stw       r3, 0x4(r4)
	  li        r3, 0xA
	  li        r6, 0x37
	  stw       r3, 0x8(r4)
	  li        r5, 0x38
	  li        r4, 0x39
	  lwz       r11, 0x84(r30)
	  mulli     r12, r0, 0xC
	  lwz       r29, 0x4(r11)
	  addi      r11, r31, 0x30
	  lwz       r0, 0x8(r29)
	  mulli     r10, r10, 0xC
	  add       r12, r0, r12
	  stw       r11, 0x0(r12)
	  mulli     r9, r9, 0xC
	  lfs       f8, -0x5B98(r2)
	  mulli     r8, r8, 0xC
	  stfs      f8, 0x4(r12)
	  lfs       f7, -0x5B94(r2)
	  mulli     r7, r7, 0xC
	  stfs      f7, 0x8(r12)
	  add       r11, r0, r10
	  addi      r10, r31, 0x44
	  stw       r10, 0x0(r11)
	  mulli     r6, r6, 0xC
	  stfs      f8, 0x4(r11)
	  add       r10, r0, r9
	  stfs      f7, 0x8(r11)
	  addi      r9, r31, 0x5C
	  mulli     r5, r5, 0xC
	  stw       r9, 0x0(r10)
	  stfs      f8, 0x4(r10)
	  add       r9, r0, r8
	  addi      r8, r31, 0x78
	  stfs      f7, 0x8(r10)
	  mulli     r4, r4, 0xC
	  stw       r8, 0x0(r9)
	  add       r8, r0, r7
	  stfs      f8, 0x4(r9)
	  addi      r7, r31, 0x90
	  add       r10, r0, r6
	  lfs       f6, -0x5B90(r2)
	  addi      r6, r31, 0xAC
	  add       r11, r0, r5
	  stfs      f6, 0x8(r9)
	  addi      r5, r31, 0xC4
	  add       r9, r0, r4
	  stw       r7, 0x0(r8)
	  addi      r4, r31, 0xE0
	  stfs      f8, 0x4(r8)
	  lfs       f5, -0x5B8C(r2)
	  stfs      f5, 0x8(r8)
	  stw       r6, 0x0(r10)
	  stfs      f8, 0x4(r10)
	  stfs      f6, 0x8(r10)
	  stw       r5, 0x0(r11)
	  stfs      f8, 0x4(r11)
	  stfs      f5, 0x8(r11)
	  stw       r4, 0x0(r9)
	  stfs      f8, 0x4(r9)
	  li        r4, 0x3A
	  stfs      f6, 0x8(r9)
	  mulli     r4, r4, 0xC
	  add       r5, r0, r4
	  addi      r4, r31, 0xF8
	  stw       r4, 0x0(r5)
	  li        r4, 0x3B
	  mulli     r4, r4, 0xC
	  stfs      f8, 0x4(r5)
	  stfs      f5, 0x8(r5)
	  add       r5, r0, r4
	  addi      r4, r31, 0x114
	  stw       r4, 0x0(r5)
	  li        r4, 0x3C
	  mulli     r4, r4, 0xC
	  stfs      f8, 0x4(r5)
	  stfs      f6, 0x8(r5)
	  add       r5, r0, r4
	  addi      r4, r31, 0x12C
	  stw       r4, 0x0(r5)
	  li        r4, 0x3D
	  mulli     r4, r4, 0xC
	  stfs      f8, 0x4(r5)
	  stfs      f5, 0x8(r5)
	  add       r5, r0, r4
	  addi      r4, r31, 0x148
	  stw       r4, 0x0(r5)
	  li        r4, 0x3E
	  mulli     r4, r4, 0xC
	  stfs      f8, 0x4(r5)
	  lfs       f4, -0x5B88(r2)
	  add       r6, r0, r4
	  addi      r4, r31, 0x158
	  stfs      f4, 0x8(r5)
	  li        r0, 0x1
	  li        r12, 0x2
	  stw       r4, 0x0(r6)
	  li        r11, -0x1
	  li        r10, 0x3
	  stfs      f8, 0x4(r6)
	  li        r9, 0x8
	  li        r8, 0xF
	  lfs       f0, -0x5B84(r2)
	  li        r7, 0x5
	  li        r5, 0x14
	  stfs      f0, 0x8(r6)
	  lwz       r4, 0x84(r30)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r0, 0x0(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r12, 0x18(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r11, 0xC(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r0, 0x24(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r0, 0x8(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r10, 0x28(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r9, 0x2C(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r8, 0x30(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r7, 0x34(r6)
	  lwz       r6, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x38(r6)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B80(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5B7C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B78(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B74(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x20(r3)
	  lfs       f0, -0x1CA4(r13)
	  lfs       f3, -0x5B70(r2)
	  lwz       r3, 0x4(r4)
	  fdivs     f0, f0, f3
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B6C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B68(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B64(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xB4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B60(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B5C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x5B58(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B54(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B50(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5B4C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5B48(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x80(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x84(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x88(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B44(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x74(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x9C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B40(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xA0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0xAC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B3C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xB0(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B38(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xC8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0xCC(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0xD0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0xD4(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B34(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xD8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0xDC(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xE0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0xE4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xE8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0xEC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B30(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xF0(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5B2C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xF4(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f7, 0xF8(r4)
	  lwz       r0, 0x114(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  lwz       r29, 0x104(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80136208
 * Size:	0022C4
 */
TaiNapkidStrategy::TaiNapkidStrategy(TekiParameters*)
    : TaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x3C8(r1)
	  stmw      r14, 0x380(r1)
	  addi      r22, r4, 0
	  addi      r25, r3, 0
	  li        r4, 0x17
	  bl        -0xEE44
	  lis       r3, 0x802D
	  subi      r0, r3, 0x5770
	  stw       r0, 0x0(r25)
	  li        r3, 0x8
	  bl        -0xEF238
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x6140
	  stw       r0, 0x4(r14)

	.loc_0x64:
	  li        r3, 0x8
	  bl        -0xEF26C
	  stw       r3, 0x378(r1)
	  lwz       r0, 0x378(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x378(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x378(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x617C
	  lwz       r3, 0x378(r1)
	  stw       r0, 0x4(r3)

	.loc_0xA8:
	  li        r3, 0x8
	  bl        -0xEF2B0
	  stw       r3, 0x374(r1)
	  lwz       r0, 0x374(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x374(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x374(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x61BC
	  lwz       r3, 0x374(r1)
	  stw       r0, 0x4(r3)

	.loc_0xEC:
	  li        r3, 0x8
	  bl        -0xEF2F4
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x120
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x6318
	  stw       r0, 0x4(r16)

	.loc_0x120:
	  li        r3, 0x8
	  bl        -0xEF328
	  stw       r3, 0x370(r1)
	  lwz       r0, 0x370(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x370(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x370(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6358
	  lwz       r3, 0x370(r1)
	  stw       r0, 0x4(r3)

	.loc_0x164:
	  li        r3, 0x8
	  bl        -0xEF36C
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x198
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x6394
	  stw       r0, 0x4(r18)

	.loc_0x198:
	  li        r3, 0x8
	  bl        -0xEF3A0
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x6290
	  stw       r0, 0x4(r19)

	.loc_0x1CC:
	  li        r3, 0x8
	  bl        -0xEF3D4
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x200
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x61FC
	  stw       r0, 0x4(r17)

	.loc_0x200:
	  li        r3, 0x8
	  bl        -0xEF408
	  cmplwi    r3, 0
	  beq-      .loc_0x230
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lis       r4, 0x802D
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6244
	  stw       r0, 0x4(r3)

	.loc_0x230:
	  li        r3, 0x8
	  bl        -0xEF438
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x264
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0xF
	  lis       r3, 0x802D
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x7CA0
	  stw       r0, 0x4(r21)

	.loc_0x264:
	  li        r3, 0x8
	  bl        -0xEF46C
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x298
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0xF
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x42D8
	  stw       r0, 0x4(r20)

	.loc_0x298:
	  li        r3, 0x8
	  bl        -0xEF4A0
	  stw       r3, 0x36C(r1)
	  lwz       r0, 0x36C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2DC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x36C(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lwz       r3, 0x36C(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x42D8
	  lwz       r3, 0x36C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2DC:
	  li        r3, 0x8
	  bl        -0xEF4E4
	  cmplwi    r3, 0
	  beq-      .loc_0x30C
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x15
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x677C
	  stw       r0, 0x4(r3)

	.loc_0x30C:
	  li        r3, 0x8
	  bl        -0xEF514
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x340
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x591C
	  stw       r0, 0x4(r26)

	.loc_0x340:
	  li        r3, 0x8
	  bl        -0xEF548
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x374
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x45B8
	  stw       r0, 0x4(r24)

	.loc_0x374:
	  li        r3, 0xC
	  bl        -0xEF57C
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x3BC
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, -0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x5A6C
	  lfs       f0, 0x74(r5)
	  stw       r4, 0x4(r23)
	  stw       r0, 0x0(r23)
	  stw       r3, 0x4(r23)
	  stfs      f0, 0x8(r23)

	.loc_0x3BC:
	  li        r3, 0xC
	  bl        -0xEF5C4
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x404
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, -0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x5A6C
	  lfs       f0, 0xCC(r5)
	  stw       r4, 0x4(r15)
	  stw       r0, 0x0(r15)
	  stw       r3, 0x4(r15)
	  stfs      f0, 0x8(r15)

	.loc_0x404:
	  li        r3, 0xC
	  bl        -0xEF60C
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x44C
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

	.loc_0x44C:
	  li        r3, 0x8
	  bl        -0xEF654
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x480
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x43C0
	  stw       r0, 0x4(r30)

	.loc_0x480:
	  li        r3, 0xC
	  bl        -0xEF688
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x49C
	  li        r4, 0x3
	  bl        -0xF608

	.loc_0x49C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r14, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r4
	  li        r3, 0x10
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r28, 0x0(r4)
	  bl        -0xEF6DC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x53C
	  lwz       r3, 0x84(r22)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x4(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x0(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lfs       f0, 0xC(r3)
	  subi      r6, r6, 0x6A6C
	  li        r3, 0x6
	  stw       r7, 0x4(r29)
	  subi      r5, r5, 0x6A8C
	  subi      r4, r4, 0x5878
	  stw       r0, 0x0(r29)
	  stw       r6, 0x4(r29)
	  stw       r3, 0x8(r29)
	  stw       r5, 0x4(r29)
	  stw       r4, 0x4(r29)
	  stfs      f0, 0xC(r29)

	.loc_0x53C:
	  li        r3, 0x18
	  bl        -0xEF744
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x5A8
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r6, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r5, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x2
	  subi      r7, r6, 0x35D8
	  lfs       f1, 0xD8(r4)
	  li        r6, 0
	  lfs       f0, 0xD4(r4)
	  subi      r4, r5, 0x3670
	  stw       r3, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r7, 0x4(r30)
	  stw       r6, 0x8(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r30)
	  stw       r4, 0x4(r30)
	  stfs      f1, 0x14(r30)

	.loc_0x5A8:
	  li        r3, 0xC
	  bl        -0xEF7B0
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x5E4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x69F0
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x5B58(r2)
	  stfs      f0, 0x8(r28)

	.loc_0x5E4:
	  li        r3, 0xC
	  bl        -0xEF7EC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x600
	  li        r4, 0x9
	  bl        -0xF76C

	.loc_0x600:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x378(r1)
	  li        r7, 0x4
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r24, r3, r5
	  li        r5, 0x5
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r21, r3, r0
	  li        r6, 0x6
	  li        r0, 0x7
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r7,r6,2,0,29
	  stwx      r20, r3, r4
	  li        r9, 0x8
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r9,2,0,29
	  stwx      r26, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x4(r4)
	  bl        -0xEF8A4
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x6E4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r28)
	  li        r0, 0x6
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r28)
	  stw       r3, 0x4(r28)

	.loc_0x6E4:
	  li        r3, 0x18
	  bl        -0xEF8EC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x750
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r6, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r5, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x1
	  subi      r7, r6, 0x35D8
	  lfs       f1, 0xE0(r4)
	  li        r6, 0
	  lfs       f0, 0xDC(r4)
	  subi      r4, r5, 0x3670
	  stw       r3, 0x4(r29)
	  stw       r0, 0x0(r29)
	  stw       r7, 0x4(r29)
	  stw       r6, 0x8(r29)
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r29)
	  stw       r4, 0x4(r29)
	  stfs      f1, 0x14(r29)

	.loc_0x750:
	  li        r3, 0x18
	  bl        -0xEF958
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x7BC
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r5, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r7, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x3
	  subi      r6, r5, 0x35D8
	  lfs       f1, 0xE8(r4)
	  li        r5, 0x1
	  lfs       f0, 0xE4(r4)
	  subi      r4, r7, 0x3670
	  stw       r3, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r5, 0x8(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r30)
	  stw       r4, 0x4(r30)
	  stfs      f1, 0x14(r30)

	.loc_0x7BC:
	  li        r3, 0xC
	  bl        -0xEF9C4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x7D8
	  li        r4, 0x9
	  bl        -0xF944

	.loc_0x7D8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r14, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r4,2,0,29
	  li        r4, 0x3
	  stwx      r24, r3, r5
	  li        r7, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r21, r3, r0
	  li        r0, 0x7
	  li        r9, 0x8
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r20, r3, r4
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r7,r6,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r6,r9,2,0,29
	  stwx      r26, r3, r8
	  li        r3, 0x18
	  lwz       r4, 0x8(r31)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x8(r4)
	  bl        -0xEFA78
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x8DC
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r6, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r5, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x1
	  subi      r7, r6, 0x35D8
	  lfs       f1, 0xF0(r4)
	  li        r6, 0
	  lfs       f0, 0xEC(r4)
	  subi      r4, r5, 0x3670
	  stw       r3, 0x4(r31)
	  stw       r0, 0x0(r31)
	  stw       r7, 0x4(r31)
	  stw       r6, 0x8(r31)
	  stfs      f0, 0xC(r31)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r31)
	  stw       r4, 0x4(r31)
	  stfs      f1, 0x14(r31)

	.loc_0x8DC:
	  li        r3, 0xC
	  bl        -0xEFAE4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x924
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x2
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x924:
	  li        r3, 0xC
	  bl        -0xEFB2C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x940
	  li        r4, 0x7
	  bl        -0xFAAC

	.loc_0x940:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r21, r4, r0
	  li        r0, 0x4
	  li        r4, 0x5
	  lwz       r5, 0x8(r29)
	  rlwinm    r3,r3,2,0,29
	  li        r7, 0x6
	  stwx      r20, r5, r3
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r7,2,0,29
	  stwx      r26, r3, r6
	  li        r3, 0x8
	  lwz       r6, 0x8(r29)
	  stwx      r23, r6, r5
	  lwz       r5, 0x8(r29)
	  stwx      r31, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r29, 0xC(r4)
	  bl        -0xEFBC0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x9EC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x591C
	  stw       r0, 0x4(r30)

	.loc_0x9EC:
	  li        r3, 0x8
	  bl        -0xEFBF4
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0xA20
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x7
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5AF0
	  stw       r0, 0x4(r26)

	.loc_0xA20:
	  li        r3, 0x8
	  bl        -0xEFC28
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xA54
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5960
	  stw       r0, 0x4(r27)

	.loc_0xA54:
	  li        r3, 0x8
	  bl        -0xEFC5C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xA88
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x59A0
	  stw       r0, 0x4(r28)

	.loc_0xA88:
	  li        r3, 0x10
	  bl        -0xEFC90
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xAF0
	  lwz       r4, 0x84(r22)
	  lis       r5, 0x802C
	  lis       r3, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r7, 0x802D
	  lis       r8, 0x802D
	  lwz       r4, 0x0(r4)
	  addi      r0, r5, 0x6620
	  li        r6, -0x1
	  lfs       f0, 0x10(r4)
	  subi      r5, r3, 0x6A6C
	  li        r4, 0x6
	  stw       r0, 0x4(r29)
	  subi      r3, r7, 0x6A8C
	  subi      r0, r8, 0x6574
	  stw       r6, 0x0(r29)
	  stw       r5, 0x4(r29)
	  stw       r4, 0x8(r29)
	  stw       r3, 0x4(r29)
	  stw       r0, 0x4(r29)
	  stfs      f0, 0xC(r29)

	.loc_0xAF0:
	  li        r3, 0xC
	  bl        -0xEFCF8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xB0C
	  li        r4, 0x9
	  bl        -0xFC78

	.loc_0xB0C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r8, 0x3
	  stwx      r21, r3, r4
	  li        r7, 0x4
	  li        r6, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x6
	  stwx      r20, r4, r0
	  li        r4, 0x7
	  li        r9, 0x8
	  lwz       r5, 0x8(r31)
	  rlwinm    r0,r8,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r26, r5, r0
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r7,r3,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r9,2,0,29
	  stwx      r30, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r23, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x10(r4)
	  bl        -0xEFDAC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xBE0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x6
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x59E4
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x5B28(r2)
	  stfs      f0, 0x8(r28)

	.loc_0xBE0:
	  li        r3, 0x14
	  bl        -0xEFDE8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xC2C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x6
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  stw       r3, 0x4(r29)
	  stw       r0, 0x8(r29)
	  lfs       f0, -0x5B24(r2)
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x10(r29)

	.loc_0xC2C:
	  li        r3, 0xC
	  bl        -0xEFE34
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC74
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x6
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0xC74:
	  li        r3, 0xC
	  bl        -0xEFE7C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xC90
	  li        r4, 0x8
	  bl        -0xFDFC

	.loc_0xC90:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r21, r3, r4
	  li        r4, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r20, r3, r0
	  li        r0, 0x7
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r26, r3, r5
	  rlwinm    r5,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x8(r31)
	  li        r3, 0x8
	  stwx      r23, r6, r4
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x14(r4)
	  bl        -0xEFF20
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xD4C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5A2C
	  stw       r0, 0x4(r28)

	.loc_0xD4C:
	  li        r3, 0xC
	  bl        -0xEFF54
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xD88
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x62D4
	  stw       r0, 0x4(r30)
	  lfs       f0, -0x5B20(r2)
	  stfs      f0, 0x8(r30)

	.loc_0xD88:
	  li        r3, 0xC
	  bl        -0xEFF90
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xDA4
	  li        r4, 0x6
	  bl        -0xFF10

	.loc_0xDA4:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x3
	  stwx      r21, r3, r4
	  li        r4, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r29)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r6
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r18, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x18(r4)
	  bl        -0xF0014
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xE54
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x8
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0xE54:
	  li        r3, 0xC
	  bl        -0xF005C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xE70
	  li        r4, 0x5
	  bl        -0xFFDC

	.loc_0xE70:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r21, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r29)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x1C(r4)
	  bl        -0xF00D0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xEFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x5C84
	  stw       r0, 0x4(r30)

	.loc_0xEFC:
	  li        r3, 0x8
	  bl        -0xF0104
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xF30
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5B34
	  stw       r0, 0x4(r27)

	.loc_0xF30:
	  li        r3, 0xC
	  bl        -0xF0138
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xF6C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x8
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0xF6C:
	  li        r3, 0x8
	  bl        -0xF0174
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0xFA0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5C3C
	  stw       r0, 0x4(r26)

	.loc_0xFA0:
	  li        r3, 0xC
	  bl        -0xF01A8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xFDC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x9
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6454
	  stw       r0, 0x4(r29)
	  lfs       f0, -0x5B88(r2)
	  stfs      f0, 0x8(r29)

	.loc_0xFDC:
	  li        r3, 0xC
	  bl        -0xF01E4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xFF8
	  li        r4, 0x9
	  bl        -0x10164

	.loc_0xFF8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r9, 0x3
	  stwx      r26, r3, r4
	  li        r7, 0x4
	  li        r3, 0x5
	  lwz       r5, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x6
	  stwx      r30, r5, r0
	  li        r5, 0x7
	  li        r8, 0x8
	  lwz       r6, 0x8(r31)
	  rlwinm    r0,r9,2,0,29
	  rlwinm    r9,r7,2,0,29
	  stwx      r16, r6, r0
	  rlwinm    r6,r3,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r0,r8,2,0,29
	  stwx      r29, r3, r9
	  li        r3, 0x8
	  lwz       r5, 0x8(r31)
	  stwx      r19, r5, r6
	  lwz       r5, 0x8(r31)
	  stwx      r28, r5, r7
	  lwz       r5, 0x8(r31)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r17, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x20(r4)
	  bl        -0xF0298
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x10C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5CC8
	  stw       r0, 0x4(r28)

	.loc_0x10C4:
	  li        r3, 0xC
	  bl        -0xF02CC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1100
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6454
	  stw       r0, 0x4(r29)
	  lfs       f0, -0x5B88(r2)
	  stfs      f0, 0x8(r29)

	.loc_0x1100:
	  li        r3, 0xC
	  bl        -0xF0308
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x111C
	  li        r4, 0x8
	  bl        -0x10288

	.loc_0x111C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r5,r3,2,0,29
	  li        r3, 0x3
	  stwx      r28, r4, r5
	  li        r5, 0x4
	  li        r8, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r6,r0,2,0,29
	  li        r0, 0x6
	  stwx      r30, r4, r6
	  li        r4, 0x7
	  rlwinm    r7,r3,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r8,2,0,29
	  stwx      r16, r3, r7
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0x8
	  stwx      r29, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r17, r4, r7
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x24(r4)
	  bl        -0xF03AC
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x11D8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xB
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x7C5C
	  stw       r0, 0x4(r27)

	.loc_0x11D8:
	  li        r3, 0x8
	  bl        -0xF03E0
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x120C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0xC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x6DDC
	  stw       r0, 0x4(r28)

	.loc_0x120C:
	  li        r3, 0xC
	  bl        -0xF0414
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1228
	  li        r4, 0x5
	  bl        -0x10394

	.loc_0x1228:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r30)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r30)
	  stwx      r27, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x28(r4)
	  bl        -0xF0488
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x12B4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5D0C
	  stw       r0, 0x4(r27)

	.loc_0x12B4:
	  li        r3, 0xC
	  bl        -0xF04BC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x12FC
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0x74(r5)
	  stw       r4, 0x4(r28)
	  stw       r0, 0x0(r28)
	  stw       r3, 0x4(r28)
	  stfs      f0, 0x8(r28)

	.loc_0x12FC:
	  li        r3, 0x10
	  bl        -0xF0504
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x131C
	  li        r4, 0x13
	  li        r5, 0x2
	  bl        -0x1071C

	.loc_0x131C:
	  li        r3, 0xC
	  bl        -0xF0524
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0x1364
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r5)
	  li        r0, 0xD
	  subi      r3, r3, 0x6B9C
	  stw       r0, 0x8(r5)
	  stw       r3, 0x4(r5)

	.loc_0x1364:
	  lwz       r4, 0xC(r26)
	  li        r3, 0xC
	  stw       r5, 0x0(r4)
	  bl        -0xF0574
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0x13A8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x6
	  stw       r3, 0x4(r5)
	  stw       r0, 0x8(r5)

	.loc_0x13A8:
	  lwz       r4, 0xC(r26)
	  li        r3, 0xC
	  stw       r5, 0x4(r4)
	  bl        -0xF05B8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x13CC
	  li        r4, 0x7
	  bl        -0x10538

	.loc_0x13CC:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r16, r4, r0
	  li        r0, 0x4
	  li        r7, 0x5
	  lwz       r4, 0x8(r30)
	  rlwinm    r3,r3,2,0,29
	  li        r6, 0x6
	  stwx      r29, r4, r3
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r7,2,0,29
	  rlwinm    r6,r6,2,0,29
	  stwx      r19, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r30)
	  stwx      r26, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x30(r4)
	  bl        -0xF064C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1478
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5D0C
	  stw       r0, 0x4(r27)

	.loc_0x1478:
	  li        r3, 0xC
	  bl        -0xF0680
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x14C0
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0xD
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0xCC(r5)
	  stw       r4, 0x4(r28)
	  stw       r0, 0x0(r28)
	  stw       r3, 0x4(r28)
	  stfs      f0, 0x8(r28)

	.loc_0x14C0:
	  li        r3, 0xC
	  bl        -0xF06C8
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x1508
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r31)
	  li        r0, 0x5
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r31)
	  stw       r3, 0x4(r31)

	.loc_0x1508:
	  li        r3, 0xC
	  bl        -0xF0710
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1524
	  li        r4, 0x7
	  bl        -0x10690

	.loc_0x1524:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r30)
	  rlwinm    r5,r3,2,0,29
	  li        r3, 0x3
	  stwx      r31, r4, r5
	  li        r4, 0x4
	  li        r5, 0x5
	  lwz       r7, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r27, r7, r0
	  rlwinm    r3,r3,2,0,29
	  rlwinm    r0,r4,2,0,29
	  lwz       r4, 0x8(r30)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r6,r6,2,0,29
	  stwx      r16, r4, r3
	  li        r3, 0x10
	  lwz       r4, 0x8(r30)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r19, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x2C(r4)
	  bl        -0xF07A4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1604
	  lwz       r3, 0x84(r22)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x4(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x0(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lfs       f0, 0xC8(r3)
	  subi      r6, r6, 0x6A6C
	  li        r3, 0x5
	  stw       r7, 0x4(r30)
	  subi      r5, r5, 0x6A8C
	  subi      r4, r4, 0x5878
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0x1604:
	  li        r3, 0x14
	  bl        -0xF080C
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x165C
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r5, 0x802D
	  lwz       r4, 0x4(r4)
	  addi      r3, r3, 0x6620
	  li        r0, 0xE
	  lwz       r4, 0x0(r4)
	  subi      r6, r5, 0x35D8
	  li        r5, 0
	  lfs       f0, 0xF4(r4)
	  stw       r3, 0x4(r31)
	  stw       r0, 0x0(r31)
	  stw       r6, 0x4(r31)
	  stw       r5, 0x8(r31)
	  stfs      f0, 0xC(r31)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r31)

	.loc_0x165C:
	  li        r3, 0xC
	  bl        -0xF0864
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1678
	  li        r4, 0x6
	  bl        -0x107E4

	.loc_0x1678:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x3
	  stwx      r21, r3, r4
	  li        r4, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r29)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r6
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r31, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r15, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x34(r4)
	  bl        -0xF08E8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1728
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0xD
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x4
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x1728:
	  li        r3, 0x8
	  bl        -0xF0930
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x175C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5DE8
	  stw       r0, 0x4(r27)

	.loc_0x175C:
	  li        r3, 0x8
	  bl        -0xF0964
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1790
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x7C5C
	  stw       r0, 0x4(r29)

	.loc_0x1790:
	  li        r3, 0xC
	  bl        -0xF0998
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x17C8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x7590
	  stw       r0, 0x4(r28)
	  stw       r29, 0x8(r28)

	.loc_0x17C8:
	  li        r3, 0xC
	  bl        -0xF09D0
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x17E4
	  li        r4, 0x5
	  bl        -0x10950

	.loc_0x17E4:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r20, r3, r0
	  li        r0, 0x4
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r29)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x38(r4)
	  bl        -0xF0A44
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1878
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xA
	  stw       r3, 0x4(r30)
	  stw       r0, 0x8(r30)

	.loc_0x1878:
	  li        r3, 0x8
	  bl        -0xF0A80
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x18AC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5E6C
	  stw       r0, 0x4(r27)

	.loc_0x18AC:
	  li        r3, 0x8
	  bl        -0xF0AB4
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x18E0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5EAC
	  stw       r0, 0x4(r26)

	.loc_0x18E0:
	  li        r3, 0xC
	  bl        -0xF0AE8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1924
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6828
	  stw       r0, 0x4(r28)
	  lfs       f1, -0x5B1C(r2)
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r28)

	.loc_0x1924:
	  li        r3, 0xC
	  bl        -0xF0B2C
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1960
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x11
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6454
	  stw       r0, 0x4(r29)
	  lfs       f0, -0x5B88(r2)
	  stfs      f0, 0x8(r29)

	.loc_0x1960:
	  li        r3, 0xC
	  bl        -0xF0B68
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x197C
	  li        r4, 0x8
	  bl        -0x10AE8

	.loc_0x197C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r7, 0x4
	  stwx      r26, r3, r4
	  li        r3, 0x5
	  rlwinm    r8,r3,2,0,29
	  lwz       r5, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r30, r5, r0
	  rlwinm    r0,r6,2,0,29
	  li        r5, 0x7
	  lwz       r6, 0x8(r31)
	  li        r4, 0x6
	  rlwinm    r7,r7,2,0,29
	  stwx      r27, r6, r0
	  rlwinm    r0,r4,2,0,29
	  lwz       r6, 0x370(r1)
	  rlwinm    r5,r5,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0xC
	  stwx      r28, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r6, r4, r8
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x3C(r4)
	  bl        -0xF0C10
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1A4C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6828
	  stw       r0, 0x4(r28)
	  lfs       f1, -0x5B2C(r2)
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r28)

	.loc_0x1A4C:
	  li        r3, 0xC
	  bl        -0xF0C54
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x1A68
	  li        r4, 0x8
	  bl        -0x10BD4

	.loc_0x1A68:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r0, 0x2
	  rlwinm    r6,r0,2,0,29
	  stwx      r30, r4, r5
	  li        r3, 0x3
	  li        r0, 0x6
	  lwz       r4, 0x8(r31)
	  rlwinm    r7,r3,2,0,29
	  li        r5, 0x4
	  stwx      r27, r4, r6
	  li        r8, 0x5
	  rlwinm    r6,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r4, 0x7
	  rlwinm    r5,r8,2,0,29
	  stwx      r28, r3, r7
	  rlwinm    r8,r4,2,0,29
	  lwz       r7, 0x370(r1)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0xC
	  stwx      r7, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r8
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x40(r4)
	  bl        -0xF0CFC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1B3C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x12
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x1B3C:
	  li        r3, 0x8
	  bl        -0xF0D44
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1B70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5EF0
	  stw       r0, 0x4(r28)

	.loc_0x1B70:
	  li        r3, 0xC
	  bl        -0xF0D78
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1B8C
	  li        r4, 0x5
	  bl        -0x10CF8

	.loc_0x1B8C:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x374(r1)
	  stwx      r14, r3, r0
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
	  stwx      r24, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x44(r4)
	  bl        -0xF0DF0
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1C30
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0xB
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x1C30:
	  li        r3, 0x10
	  bl        -0xF0E38
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x1C50
	  li        r4, 0x13
	  li        r5, 0x2
	  bl        -0x11050

	.loc_0x1C50:
	  li        r3, 0xC
	  bl        -0xF0E58
	  addi      r4, r3, 0
	  mr.       r0, r4
	  beq-      .loc_0x1C98
	  lwz       r6, 0x84(r22)
	  lis       r5, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x0(r6)
	  addi      r5, r5, 0x6620
	  li        r0, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x6B60
	  lwz       r6, 0x50(r6)
	  stw       r5, 0x4(r4)
	  stw       r0, 0x0(r4)
	  stw       r3, 0x4(r4)
	  stw       r6, 0x8(r4)

	.loc_0x1C98:
	  lwz       r5, 0xC(r26)
	  li        r3, 0xC
	  stw       r4, 0x0(r5)
	  bl        -0xF0EA8
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0x1CE8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r5)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r5)
	  stw       r3, 0x4(r5)

	.loc_0x1CE8:
	  lwz       r4, 0xC(r26)
	  li        r3, 0xC
	  stw       r5, 0x4(r4)
	  bl        -0xF0EF8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1D0C
	  li        r4, 0x4
	  bl        -0x10E78

	.loc_0x1D0C:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x36C(r1)
	  li        r5, 0x2
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r30)
	  li        r3, 0x3
	  stwx      r24, r4, r0
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r30)
	  li        r3, 0x8
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x48(r4)
	  bl        -0xF0F60
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x1D8C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5F3C
	  stw       r0, 0x4(r26)

	.loc_0x1D8C:
	  li        r3, 0x8
	  bl        -0xF0F94
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1DC0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5D54
	  stw       r0, 0x4(r27)

	.loc_0x1DC0:
	  li        r3, 0xC
	  bl        -0xF0FC8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1E08
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0x14
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0xD0(r5)
	  stw       r4, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r3, 0x4(r30)
	  stfs      f0, 0x8(r30)

	.loc_0x1E08:
	  li        r3, 0xC
	  bl        -0xF1010
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1E50
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0xC
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x1E50:
	  li        r3, 0xC
	  bl        -0xF1058
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1E8C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x14
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6494
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x8(r28)

	.loc_0x1E8C:
	  li        r3, 0xC
	  bl        -0xF1094
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x1EA8
	  li        r4, 0x9
	  bl        -0x11014

	.loc_0x1EA8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  lwz       r4, 0x378(r1)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r4, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r7, 0x8
	  stwx      r24, r3, r4
	  li        r4, 0x4
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r6,r4,2,0,29
	  stwx      r27, r3, r0
	  li        r8, 0x6
	  li        r0, 0x7
	  lwz       r3, 0x8(r31)
	  li        r9, 0x5
	  rlwinm    r4,r8,2,0,29
	  stwx      r16, r3, r5
	  rlwinm    r5,r9,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r7,r7,2,0,29
	  stwx      r28, r3, r6
	  li        r3, 0x8
	  lwz       r6, 0x8(r31)
	  stwx      r30, r6, r5
	  lwz       r5, 0x8(r31)
	  stwx      r19, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r26, r4, r7
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x4C(r4)
	  bl        -0xF114C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1F78
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x7CA0
	  stw       r0, 0x4(r28)

	.loc_0x1F78:
	  li        r3, 0xC
	  bl        -0xF1180
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x1FB0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, 0x16
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x7590
	  stw       r0, 0x4(r31)
	  stw       r28, 0x8(r31)

	.loc_0x1FB0:
	  li        r3, 0x8
	  bl        -0xF11B8
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1FE4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x15
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5E2C
	  stw       r0, 0x4(r27)

	.loc_0x1FE4:
	  li        r3, 0x8
	  bl        -0xF11EC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x2018
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x10
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x6DDC
	  stw       r0, 0x4(r28)

	.loc_0x2018:
	  li        r3, 0xC
	  bl        -0xF1220
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x2054
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r30)
	  addi      r3, r3, 0x7F58
	  li        r0, 0
	  stw       r3, 0x4(r30)
	  stw       r0, 0x8(r30)

	.loc_0x2054:
	  li        r3, 0xC
	  bl        -0xF125C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x2070
	  li        r4, 0x4
	  bl        -0x111DC

	.loc_0x2070:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r31, r3, r0
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r3, 0xC
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x50(r4)
	  bl        -0xF12C0
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x2100
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x16
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802C
	  stw       r0, 0x4(r29)
	  li        r4, 0x9
	  addi      r0, r3, 0x66C0
	  stw       r4, 0x8(r29)
	  stw       r0, 0x4(r29)

	.loc_0x2100:
	  li        r3, 0xC
	  bl        -0xF1308
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x211C
	  li        r4, 0x2
	  bl        -0x11288

	.loc_0x211C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0x8
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r28, 0x54(r4)
	  bl        -0xF134C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x2178
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5DA0
	  stw       r0, 0x4(r28)

	.loc_0x2178:
	  li        r3, 0xC
	  bl        -0xF1380
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x21C0
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0x74(r5)
	  stw       r4, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r3, 0x4(r30)
	  stfs      f0, 0x8(r30)

	.loc_0x21C0:
	  li        r3, 0xC
	  bl        -0xF13C8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x2208
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0x6
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x2208:
	  li        r3, 0xC
	  bl        -0xF1410
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x2224
	  li        r4, 0x8
	  bl        -0x11390

	.loc_0x2224:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r5,r3,2,0,29
	  li        r3, 0x3
	  stwx      r21, r4, r5
	  li        r6, 0x4
	  li        r5, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r7,r0,2,0,29
	  li        r0, 0x6
	  stwx      r20, r4, r7
	  li        r4, 0x7
	  rlwinm    r7,r3,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r28, r3, r7
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r4, 0x8(r31)
	  mr        r3, r25
	  stwx      r16, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r7
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x58(r4)
	  lwz       r0, 0x3CC(r1)
	  lmw       r14, 0x380(r1)
	  addi      r1, r1, 0x3C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801384CC
 * Size:	000084
 */
void TaiNapkidStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x10
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  li        r4, 0x54
	  lfs       f0, -0x106C(r13)
	  lfs       f1, -0x1068(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x1064(r13)
	  stfs      f1, 0x14(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x18(r1)
	  bl        0x64624
	  lwz       r5, 0x3D8(r31)
	  li        r4, 0
	  stw       r3, 0x0(r5)
	  mr        r3, r31
	  bl        0x114F4
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x110A0
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
 * Address:	80138550
 * Size:	0000BC
 */
void TaiNapkidStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  bl        0x14C58
	  lwz       r3, 0x3D8(r31)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  addi      r3, r1, 0x2C
	  bl        -0x1B730
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE35C4
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE374C
	  stfs      f1, 0x2C(r1)
	  mr        r3, r31
	  lfs       f0, -0x1070(r13)
	  addi      r5, r1, 0x2C
	  li        r4, 0
	  stfs      f0, 0x30(r1)
	  stfs      f31, 0x34(r1)
	  bl        0x114B4
	  addi      r3, r1, 0x20
	  bl        -0x1B770
	  lwz       r6, 0x94(r31)
	  mr        r3, r31
	  lwz       r0, 0x98(r31)
	  addi      r5, r1, 0x20
	  li        r4, 0
	  stw       r6, 0x20(r1)
	  stw       r0, 0x24(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x28(r1)
	  bl        0x11454

	.loc_0xA0:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013860C
 * Size:	000250
 */
void TaiNapkidStrategy::drawDebugInfo(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  addi      r6, r1, 0xD0
	  stfd      f30, 0x100(r1)
	  stmw      r26, 0xE8(r1)
	  addi      r30, r4, 0
	  li        r28, 0
	  addi      r31, r5, 0
	  addi      r26, r30, 0x94
	  li        r29, 0xFF
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r5, r26, 0
	  stb       r28, 0xD0(r1)
	  stb       r28, 0xD1(r1)
	  stb       r29, 0xD2(r1)
	  stb       r29, 0xD3(r1)
	  lwz       r7, 0x2C4(r30)
	  lwz       r7, 0x84(r7)
	  lwz       r7, 0x4(r7)
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x18(r7)
	  bl        0x10D08
	  li        r0, 0x1E
	  lfs       f1, -0x5B18(r2)
	  stb       r0, 0xCC(r1)
	  addi      r6, r1, 0xCC
	  addi      r3, r30, 0
	  stb       r0, 0xCD(r1)
	  addi      r4, r31, 0
	  mr        r5, r26
	  stb       r0, 0xCE(r1)
	  stb       r29, 0xCF(r1)
	  bl        0x10CDC
	  stb       r29, 0xC8(r1)
	  addi      r27, r1, 0xC8
	  li        r4, 0
	  stb       r29, 0xC9(r1)
	  stb       r28, 0xCA(r1)
	  stb       r29, 0xCB(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  bl        -0x154AC
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x154C0
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x16214
	  fmuls     f0, f30, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r5, r26, 0
	  fmuls     f1, f1, f0
	  addi      r6, r27, 0
	  bl        0x10C70
	  lwz       r3, 0x2CC(r30)
	  lwz       r0, 0x44(r3)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x1C0
	  lfs       f31, 0x2C(r3)
	  li        r4, 0x2
	  bl        -0x18F2C
	  fmr       f30, f1
	  lwz       r3, 0x2CC(r30)
	  li        r4, 0x3
	  bl        -0x18F3C
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x1C0
	  fcmpo     cr0, f31, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x1C0
	  addi      r3, r1, 0xD4
	  bl        -0x1B8FC
	  addi      r3, r30, 0
	  addi      r4, r1, 0xD4
	  bl        0xF2B4
	  stb       r29, 0xC4(r1)
	  addi      r26, r1, 0xC4
	  li        r4, 0
	  stb       r28, 0xC5(r1)
	  stb       r28, 0xC6(r1)
	  stb       r29, 0xC7(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  bl        -0x15570
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x15584
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0xB
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x162D8
	  fmuls     f0, f30, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r6, r26, 0
	  fmuls     f1, f1, f0
	  addi      r5, r1, 0xD4
	  bl        0x10BAC

	.loc_0x1C0:
	  li        r3, 0xFF
	  stb       r3, 0xC0(r1)
	  li        r0, 0
	  addi      r26, r1, 0xC0
	  stb       r0, 0xC1(r1)
	  li        r4, 0
	  stb       r3, 0xC2(r1)
	  stb       r3, 0xC3(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  bl        -0x155E4
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x155F8
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x2D
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x1634C
	  fmuls     f0, f31, f30
	  addi      r5, r30, 0x94
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  fmuls     f1, f1, f0
	  mr        r6, r26
	  bl        0x10B38
	  lmw       r26, 0xE8(r1)
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013885C
 * Size:	0000BC
 */
bool TekiNapkidTargetPikiCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x24
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x24:
	  lwz       r0, 0x184(r4)
	  addi      r31, r4, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x3C:
	  lis       r5, 0x802B
	  lwz       r6, 0x4(r3)
	  subi      r0, r5, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x24(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x24(r1)
	  subi      r0, r3, 0x2AF4
	  stw       r0, 0x24(r1)
	  addi      r3, r1, 0x24
	  stw       r6, 0x28(r1)
	  lwz       r12, 0x24(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x8C:
	  mr        r3, r31
	  bl        -0x70398
	  cmpwi     r3, 0x1E
	  bne-      .loc_0xA4
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0xA4:
	  li        r3, 0x1

	.loc_0xA8:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138918
 * Size:	0000A0
 */
bool TekiNapkidShortRangeCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x20:
	  lwz       r0, 0x184(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x34:
	  lis       r5, 0x802B
	  lwz       r6, 0x4(r3)
	  subi      r0, r5, 0xF68
	  lfs       f0, -0x5B18(r2)
	  lis       r3, 0x802C
	  stw       r0, 0x24(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x24(r1)
	  subi      r0, r3, 0x29D8
	  stw       r0, 0x24(r1)
	  addi      r3, r1, 0x24
	  stw       r6, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lwz       r12, 0x24(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0

	.loc_0x90:
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801389B8
 * Size:	000054
 */
void TaiNapkidWanderingRouteAction::start(Teki&)
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
	  bl        -0x4964
	  mr        r3, r31
	  bl        0x1013C
	  lwz       r0, 0x10(r3)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  stw       r0, 0x354(r31)
	  bl        0xC8
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
 * Address:	80138A0C
 * Size:	0000AC
 */
bool TaiNapkidWanderingRouteAction::act(Teki&)
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
	  bl        -0x48BC
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x48:
	  mr        r3, r31
	  lwz       r4, 0x354(r31)
	  bl        0x100F0
	  mr.       r4, r3
	  bne-      .loc_0x70
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xAC
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x70:
	  lfs       f1, 0xC(r30)
	  mr        r3, r31
	  bl        0xE96C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xAC

	.loc_0x90:
	  li        r3, 0

	.loc_0x94:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0xAC:
	*/
}

/*
 * --INFO--
 * Address:	80138AB8
 * Size:	0000A8
 */
void TaiNapkidWanderingRouteAction::makeTargetPosition(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  mr        r3, r30
	  lwz       r4, 0x354(r4)
	  bl        0x10074
	  mr.       r31, r3
	  bne-      .loc_0x30
	  b         .loc_0x90

	.loc_0x30:
	  lwz       r3, 0x34(r31)
	  subi      r3, r3, 0x1
	  bl        -0x1A24C
	  lwz       r0, 0x34(r31)
	  addi      r4, r31, 0
	  li        r6, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  li        r5, 0
	  ble-      .loc_0x90

	.loc_0x58:
	  lwz       r0, 0x14(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x84
	  cmpw      r6, r3
	  bne-      .loc_0x80
	  rlwinm    r0,r5,2,0,29
	  add       r3, r31, r0
	  lwz       r0, 0x14(r3)
	  stw       r0, 0x354(r30)
	  b         .loc_0x90

	.loc_0x80:
	  addi      r6, r6, 0x1

	.loc_0x84:
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x58

	.loc_0x90:
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
 * Address:	80138B60
 * Size:	0000B8
 */
bool TaiNapkidTargetPikiAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  addi      r4, r30, 0x94
	  stw       r0, 0x18(r1)
	  addi      r0, r5, 0x6964
	  lis       r5, 0x802D
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x18(r1)
	  subi      r0, r5, 0x57CC
	  stw       r0, 0x18(r1)
	  addi      r5, r1, 0x18
	  stw       r30, 0x1C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  bne-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0xA0

	.loc_0x6C:
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  beq-      .loc_0x88
	  bl        -0x54870
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x88:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  bl        -0x5489C

	.loc_0x9C:
	  li        r3, 0x1

	.loc_0xA0:
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
 * Address:	80138C18
 * Size:	0000A8
 */
bool TaiNapkidPikiLostAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  lwz       r0, 0x418(r4)
	  cmplwi    r0, 0
	  mr        r4, r0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0x94

	.loc_0x2C:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x2C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x2C(r1)
	  subi      r0, r3, 0x57CC
	  stw       r0, 0x2C(r1)
	  addi      r3, r1, 0x2C
	  stw       r31, 0x30(r1)
	  lwz       r12, 0x2C(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x90
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  bl        -0x54928
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0x88:
	  li        r3, 0x1
	  b         .loc_0x94

	.loc_0x90:
	  li        r3, 0

	.loc_0x94:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138CC0
 * Size:	000088
 */
bool TaiNapkidShortRangeAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  lwz       r0, 0x418(r4)
	  cmplwi    r0, 0
	  mr        r5, r0
	  bne-      .loc_0x24
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x24:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x2C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x2C(r1)
	  subi      r0, r3, 0x5824
	  stw       r0, 0x2C(r1)
	  addi      r3, r1, 0x2C
	  stw       r4, 0x30(r1)
	  mr        r4, r5
	  lwz       r12, 0x2C(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x74:
	  li        r3, 0

	.loc_0x78:
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138D48
 * Size:	0000A8
 */
void TaiNapkidStraightFlyingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  addi      r3, r1, 0x1C
	  stfd      f30, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  bl        -0x1BF14
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE2DE0
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2F68
	  stfs      f1, 0x1C(r1)
	  lfs       f0, -0x1070(r13)
	  stfs      f0, 0x20(r1)
	  stfs      f31, 0x24(r1)
	  lfs       f0, 0x1C(r1)
	  lfs       f1, -0x5B20(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x20(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x24(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x20(r1)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138DF0
 * Size:	000098
 */
bool TaiNapkidStraightFlyingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x418(r4)
	  cmplwi    r4, 0
	  bne-      .loc_0x30
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x30:
	  addi      r4, r4, 0x94
	  addi      r3, r1, 0x34
	  bl        -0x1BFA8
	  lfs       f3, 0x3C(r1)
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x12B210
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x7C
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x7C:
	  li        r3, 0

	.loc_0x80:
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
 * Address:	80138E88
 * Size:	00029C
 */
void TaiNapkidCirclingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stfd      f28, 0xE8(r1)
	  stfd      f27, 0xE0(r1)
	  stfd      f26, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  stw       r30, 0xD0(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  cmplwi    r31, 0
	  beq-      .loc_0x26C
	  addi      r3, r1, 0xC0
	  bl        -0x1C074
	  lfs       f0, 0x94(r30)
	  addi      r3, r1, 0xC0
	  lfs       f1, 0x94(r31)
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x98(r30)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x9C(r31)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f3, f2
	  stfs      f0, 0xC0(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xC4(r1)
	  stfs      f0, 0xC8(r1)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0xC4(r1)
	  bl        -0x1BEF0
	  addi      r3, r1, 0xB4
	  bl        -0x1C0BC
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xE2C38
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2DC0
	  stfs      f1, 0xB4(r1)
	  addi      r3, r1, 0xA8
	  lfs       f0, -0x1070(r13)
	  stfs      f0, 0xB8(r1)
	  stfs      f31, 0xBC(r1)
	  bl        -0x1C0EC
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x74
	  lfs       f2, -0x5B8C(r2)
	  fmr       f3, f1
	  bl        -0x1C078
	  lfs       f0, 0x78(r1)
	  li        r31, 0
	  lfs       f2, 0xBC(r1)
	  lfs       f3, 0x7C(r1)
	  lfs       f1, 0xB8(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0xB4(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x74(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0xA8(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f3, 0xA8(r1)
	  lfs       f2, 0xC0(r1)
	  lfs       f1, 0xAC(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f2, f3, f2
	  lfs       f4, 0xB0(r1)
	  fmuls     f1, f1, f0
	  lfs       f3, 0xC8(r1)
	  lfs       f0, -0x5B98(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x158
	  li        r31, 0x1

	.loc_0x158:
	  lfs       f28, -0x5B58(r2)
	  addi      r3, r1, 0xA8
	  lfs       f2, -0x1CA4(r13)
	  lfs       f0, -0x5B20(r2)
	  fmuls     f1, f28, f2
	  fdivs     f0, f1, f0
	  fdivs     f26, f2, f0
	  fmr       f27, f0
	  bl        -0x1BFE8
	  lfs       f30, 0xA8(r1)
	  rlwinm.   r0,r31,0,24,31
	  lfs       f0, -0x5B58(r2)
	  lfs       f31, 0xAC(r1)
	  lfs       f29, 0xB0(r1)
	  fmuls     f30, f30, f0
	  fmuls     f31, f31, f0
	  fmuls     f29, f29, f0
	  beq-      .loc_0x1B0
	  fneg      f30, f30
	  fneg      f31, f31
	  fneg      f29, f29
	  fneg      f26, f26

	.loc_0x1B0:
	  addi      r3, r1, 0x80
	  bl        -0x1C1E8
	  addi      r31, r30, 0x94
	  lfs       f0, 0x94(r30)
	  addi      r3, r30, 0x368
	  lfs       f1, 0x98(r30)
	  addi      r4, r1, 0x80
	  fadds     f0, f0, f30
	  lfs       f2, 0x9C(r30)
	  fadds     f1, f1, f31
	  stfs      f0, 0x80(r1)
	  fadds     f0, f2, f29
	  stfs      f1, 0x84(r1)
	  stfs      f0, 0x88(r1)
	  lwz       r12, 0x368(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r31, 0
	  addi      r3, r1, 0x68
	  bl        -0x1C208
	  lwz       r12, 0x358(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fmr       f1, f27
	  lwz       r3, 0x464(r30)
	  fmr       f3, f28
	  lfs       f2, -0x5B8C(r2)
	  fmr       f5, f26
	  lfs       f4, -0x5B98(r2)
	  addi      r4, r30, 0x358
	  addi      r5, r30, 0x368
	  bl        -0x12CD8
	  lwz       r3, 0x464(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x464(r30)
	  lfs       f0, 0x10(r3)
	  stfs      f0, 0x394(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x200
	  stw       r0, 0xC8(r30)

	.loc_0x26C:
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lfd       f28, 0xE8(r1)
	  lfd       f27, 0xE0(r1)
	  lfd       f26, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139124
 * Size:	000018
 */
void TaiNapkidCirclingAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,23,21
	  stw       r0, 0xC8(r4)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x3A4(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013913C
 * Size:	000124
 */
bool TaiNapkidCirclingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x50
	  bl        -0x1C300
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x50
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x44
	  bl        -0x1C320
	  lfs       f1, 0x50(r1)
	  addi      r3, r1, 0x44
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x54(r1)
	  lfs       f2, 0x98(r31)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x9C(r31)
	  lfs       f4, 0x58(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x44(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x48(r1)
	  stfs      f0, 0x4C(r1)
	  bl        -0x1C194
	  addi      r3, r1, 0x38
	  bl        -0x1C360
	  lfs       f1, 0x44(r1)
	  lfs       f0, 0xA4(r31)
	  lfs       f3, 0x48(r1)
	  lfs       f2, 0xA8(r31)
	  fadds     f0, f1, f0
	  lfs       f4, 0x4C(r1)
	  lfs       f1, 0xAC(r31)
	  fadds     f2, f3, f2
	  stfs      f0, 0x38(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x1B3E8
	  stfs      f1, 0xA0(r31)
	  lwz       r3, 0x464(r31)
	  lfs       f0, 0x394(r31)
	  lfs       f1, 0x10(r3)
	  fsubs     f1, f1, f0
	  bl        0xE2AE0
	  lfs       f2, -0x1CA4(r13)
	  lfs       f0, -0x5B14(r2)
	  fneg      f2, f2
	  fmuls     f0, f2, f0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3A4(r31)
	  lwz       r3, 0x464(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  li        r3, 0x1
	  b         .loc_0x110

	.loc_0x10C:
	  li        r3, 0

	.loc_0x110:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139260
 * Size:	000060
 */
bool TaiNapkidFlyingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        0xF6E0
	  lfs       f0, 0x8(r30)
	  li        r3, 0
	  lfs       f2, 0x98(r31)
	  fadds     f0, f0, f1
	  lfs       f1, -0x5B10(r2)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x98(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801392C0
 * Size:	000024
 */
bool TaiNapkidAscendingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x3150(r13)
	  lfs       f1, 0x8(r3)
	  li        r3, 0
	  lfs       f0, 0x28C(r5)
	  lfs       f2, 0x98(r4)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x98(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801392E4
 * Size:	00006C
 */
bool TaiNapkidApproachPikiAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x418(r4)
	  cmplwi    r3, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x5C

	.loc_0x20:
	  lwz       r5, 0x2C4(r4)
	  addi      r0, r3, 0x94
	  addi      r3, r4, 0
	  lwz       r5, 0x84(r5)
	  mr        r4, r0
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f2, 0x24(r5)
	  lfs       f1, 0x20(r5)
	  bl        0xD930
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x5C

	.loc_0x58:
	  li        r3, 0x1

	.loc_0x5C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139350
 * Size:	000364
 */
bool TaiNapkidCatchingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C0(r1)
	  stfd      f31, 0x1B8(r1)
	  stfd      f30, 0x1B0(r1)
	  stfd      f29, 0x1A8(r1)
	  stmw      r22, 0x180(r1)
	  mr        r26, r4
	  lwz       r3, 0x2CC(r4)
	  li        r4, 0x2
	  lfs       f30, 0x2C(r3)
	  bl        -0x19B88
	  fcmpo     cr0, f30, f1
	  bge-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x344

	.loc_0x40:
	  lwz       r3, 0x2CC(r26)
	  li        r4, 0x3
	  bl        -0x19BA4
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x5C
	  li        r3, 0x1
	  b         .loc_0x344

	.loc_0x5C:
	  lfs       f31, 0xA0(r26)
	  fmr       f1, f31
	  bl        0xE27A0
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0xE2928
	  lwz       r3, 0x2C4(r26)
	  fmr       f31, f1
	  lfs       f29, -0x1070(r13)
	  li        r4, 0xA
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x16F08
	  fmuls     f31, f31, f1
	  addi      r3, r1, 0x160
	  fmuls     f29, f29, f1
	  fmuls     f30, f30, f1
	  bl        -0x1C59C
	  lfs       f0, 0x94(r26)
	  lis       r8, 0x802B
	  lfs       f1, 0x98(r26)
	  lis       r5, 0x802C
	  fadds     f0, f0, f31
	  lfs       f2, 0x9C(r26)
	  lis       r7, 0x802D
	  fadds     f1, f1, f29
	  subi      r9, r7, 0x2A4C
	  stfs      f0, 0x160(r1)
	  fadds     f0, f2, f30
	  subi      r30, r8, 0xF68
	  stfs      f1, 0x164(r1)
	  lis       r6, 0x802C
	  addi      r31, r5, 0x6964
	  stfs      f0, 0x168(r1)
	  lis       r3, 0x802C
	  addi      r5, r3, 0x685C
	  stw       r30, 0x154(r1)
	  lis       r4, 0x802D
	  addi      r8, r6, 0x6890
	  stw       r30, 0x124(r1)
	  subi      r6, r4, 0x295C
	  addi      r3, r1, 0x134
	  stw       r30, 0x12C(r1)
	  addi      r7, r1, 0x124
	  addi      r0, r1, 0x12C
	  stw       r30, 0x134(r1)
	  li        r4, 0xB
	  stw       r31, 0x154(r1)
	  stw       r31, 0x124(r1)
	  stw       r31, 0x12C(r1)
	  stw       r31, 0x134(r1)
	  stw       r5, 0x154(r1)
	  stw       r9, 0x124(r1)
	  stw       r8, 0x12C(r1)
	  stw       r6, 0x134(r1)
	  stw       r3, 0x158(r1)
	  stw       r26, 0x128(r1)
	  stw       r7, 0x130(r1)
	  stw       r26, 0x138(r1)
	  stw       r0, 0x15C(r1)
	  lwz       r3, 0x2C4(r26)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x16FD4
	  lfs       f0, 0x160(r1)
	  lis       r4, 0x802D
	  subi      r0, r4, 0x28E0
	  fmr       f31, f1
	  stfs      f0, 0x104(r1)
	  addi      r5, r1, 0x108
	  lfs       f0, 0x164(r1)
	  addi      r6, r1, 0x10C
	  addi      r3, r1, 0x114
	  stfs      f0, 0x108(r1)
	  addi      r4, r1, 0x104
	  lfs       f0, 0x168(r1)
	  stfs      f0, 0x10C(r1)
	  stw       r30, 0x110(r1)
	  lfs       f0, -0x5B98(r2)
	  stw       r31, 0x110(r1)
	  stw       r0, 0x110(r1)
	  stfs      f0, 0x11C(r1)
	  stfs      f0, 0x118(r1)
	  stfs      f0, 0x114(r1)
	  bl        -0xDBE70
	  lwz       r28, 0x3068(r13)
	  addi      r31, r1, 0x154
	  stfs      f31, 0x120(r1)
	  addi      r29, r1, 0x110
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r27, r3, 0
	  subi      r24, r5, 0x3064
	  subi      r25, r4, 0x3244
	  addi      r30, r1, 0xF4
	  b         .loc_0x2E4

	.loc_0x1F0:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x214
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x22C

	.loc_0x214:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x22C:
	  cmplwi    r3, 0
	  addi      r22, r3, 0
	  beq-      .loc_0x340
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r4, r22, 0
	  li        r23, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  li        r23, 0x1

	.loc_0x280:
	  rlwinm.   r0,r23,0,24,31
	  beq-      .loc_0x2C8
	  mr        r3, r26
	  bl        0xFF84
	  cmplwi    r3, 0
	  beq-      .loc_0x340
	  stw       r24, 0xF4(r1)
	  li        r0, 0
	  addi      r4, r30, 0
	  stw       r26, 0xF8(r1)
	  stw       r25, 0xF4(r1)
	  stw       r0, 0xFC(r1)
	  stw       r3, 0x100(r1)
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x2E4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x30C
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x30C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1F0

	.loc_0x340:
	  li        r3, 0

	.loc_0x344:
	  lmw       r22, 0x180(r1)
	  lwz       r0, 0x1C4(r1)
	  lfd       f31, 0x1B8(r1)
	  lfd       f30, 0x1B0(r1)
	  lfd       f29, 0x1A8(r1)
	  addi      r1, r1, 0x1C0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801396B4
 * Size:	00017C
 */
void TaiNapkidCatchDescendingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1078
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1074
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  addi      r3, r1, 0x28
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  subi      r4, r13, 0x107C
	  bl        -0x1025C4
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x28
	  addi      r5, r1, 0x2C
	  addi      r6, r1, 0x30
	  bl        -0xDC068
	  addi      r3, r1, 0x1C
	  subi      r4, r13, 0x1088
	  subi      r5, r13, 0x1084
	  subi      r6, r13, 0x1080
	  bl        -0x1025EC
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0xDC090
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x34
	  bl        -0x1C8A8
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x4C
	  bl        -0x1C8F4
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE2400
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2588
	  stfs      f1, 0x4C(r1)
	  addi      r3, r31, 0x368
	  lfs       f0, -0x1070(r13)
	  addi      r4, r1, 0x4C
	  stfs      f0, 0x50(r1)
	  stfs      f31, 0x54(r1)
	  lfs       f0, 0x4C(r1)
	  lfs       f1, -0x5B28(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x54(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x54(r1)
	  lfs       f0, -0x5B0C(r2)
	  stfs      f0, 0x50(r1)
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x40
	  lfs       f2, -0x5B08(r2)
	  fmr       f3, f1
	  bl        -0x1C8F0
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x40
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0x138B8
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139830
 * Size:	0002CC
 */
bool TaiNapkidCatchTracingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  addi      r3, r1, 0xB8
	  stfd      f30, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  stw       r30, 0xC8(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  bl        -0x1CA04
	  lwz       r4, 0x94(r31)
	  addi      r3, r1, 0xAC
	  lwz       r0, 0x98(r31)
	  lfs       f0, -0x5B98(r2)
	  stw       r4, 0xB8(r1)
	  stw       r0, 0xBC(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0xC0(r1)
	  stfs      f0, 0xBC(r1)
	  bl        -0x1CA2C
	  lwz       r4, 0x94(r30)
	  addi      r3, r1, 0xA0
	  lwz       r0, 0x98(r30)
	  lfs       f0, -0x5B98(r2)
	  stw       r4, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  bl        -0x1CA54
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xE22A0
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2428
	  stfs      f1, 0xA0(r1)
	  addi      r3, r1, 0x94
	  lfs       f0, -0x1070(r13)
	  stfs      f0, 0xA4(r1)
	  stfs      f31, 0xA8(r1)
	  bl        -0x1CA84
	  lfs       f1, 0xB8(r1)
	  addi      r3, r1, 0x94
	  lfs       f0, 0xAC(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xB0(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xB4(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  bl        -0x1C8F8
	  addi      r3, r1, 0x88
	  bl        -0x1CAC4
	  lfs       f0, 0x98(r1)
	  addi      r3, r1, 0x7C
	  lfs       f2, 0xA8(r1)
	  lfs       f3, 0x9C(r1)
	  lfs       f1, 0xA4(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0xA0(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x94(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x88(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x8C(r1)
	  stfs      f0, 0x90(r1)
	  bl        -0x1CB14
	  addi      r3, r30, 0x378
	  lwz       r12, 0x378(r30)
	  addi      r4, r1, 0x7C
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x8C(r1)
	  lfs       f0, -0x5B98(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  b         .loc_0x16C

	.loc_0x168:
	  fneg      f1, f1

	.loc_0x16C:
	  lfs       f0, -0x5B04(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x188
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x84(r1)
	  b         .loc_0x258

	.loc_0x188:
	  addi      r3, r1, 0x70
	  bl        -0x1CB68
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x4C
	  lfs       f2, -0x5B8C(r2)
	  fmr       f3, f1
	  bl        -0x1CAF4
	  lfs       f0, 0xA4(r1)
	  addi      r3, r1, 0x70
	  lfs       f2, 0x54(r1)
	  lfs       f3, 0xA8(r1)
	  lfs       f1, 0x50(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0x4C(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0xA0(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x70(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  bl        -0x1CA08
	  lfs       f0, 0x70(r1)
	  lfs       f1, -0x5B00(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, -0x5B98(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x240
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x84(r1)
	  b         .loc_0x258

	.loc_0x240:
	  lfs       f0, 0x70(r1)
	  fneg      f0, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x78(r1)
	  fneg      f0, f0
	  stfs      f0, 0x84(r1)

	.loc_0x258:
	  addi      r3, r30, 0x378
	  lwz       r12, 0x378(r30)
	  addi      r4, r1, 0x7C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x64
	  bl        -0x1CC50
	  addi      r3, r30, 0x368
	  lwz       r12, 0x368(r30)
	  addi      r4, r1, 0x64
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x368
	  lwz       r12, 0x368(r30)
	  addi      r4, r1, 0x64
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xE4(r1)
	  li        r3, 0
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139AFC
 * Size:	0000E4
 */
void TaiNapkidCatchFlyingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x10
	  bl        -0x1CC98
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x28
	  bl        -0x1CCE4
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x28
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x5B98(r2)
	  addi      r3, r31, 0x368
	  addi      r4, r1, 0x28
	  stfs      f0, 0x2C(r1)
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x1C
	  fmr       f2, f1
	  fmr       f3, f1
	  bl        -0x1CCA8
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x1C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0x13C70
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139BE0
 * Size:	0000E4
 */
void TaiNapkidCatchAscendingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x10
	  bl        -0x1CD7C
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x28
	  bl        -0x1CDC8
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x28
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x5B98(r2)
	  addi      r3, r31, 0x368
	  addi      r4, r1, 0x28
	  stfs      f0, 0x2C(r1)
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x1C
	  lfs       f2, -0x5B94(r2)
	  fmr       f3, f1
	  bl        -0x1CD8C
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x1C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0x13D54
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139CC4
 * Size:	000198
 */
void TaiNapkidTakingOffAscendingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  addi      r3, r1, 0x60
	  stfd      f30, 0x88(r1)
	  stfd      f29, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  addi      r30, r4, 0
	  bl        -0xA9068
	  lwz       r31, 0x68(r1)
	  addi      r3, r1, 0x44
	  addi      r4, r1, 0x58
	  bl        -0x1E484
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x44
	  lfs       f2, -0x5B8C(r2)
	  lfs       f3, -0x5B88(r2)
	  lfs       f4, -0x5B30(r2)
	  bl        -0x1E3F8
	  xoris     r0, r31, 0x8000
	  lfd       f1, -0x5AF0(r2)
	  stw       r0, 0x74(r1)
	  lis       r0, 0x4330
	  addi      r3, r1, 0x44
	  stw       r0, 0x70(r1)
	  lfd       f0, 0x70(r1)
	  fsubs     f1, f0, f1
	  bl        -0x1E38C
	  fmr       f30, f1
	  addi      r4, r30, 0x94
	  addi      r3, r1, 0x20
	  bl        -0x1CEC8
	  lwz       r12, 0x358(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x38
	  bl        -0x1CF14
	  lfs       f29, 0xA0(r30)
	  fmr       f1, f29
	  bl        0xE1DE0
	  fmr       f31, f1
	  fmr       f1, f29
	  bl        0xE1F68
	  stfs      f1, 0x38(r1)
	  addi      r3, r30, 0x368
	  lfs       f0, -0x1070(r13)
	  addi      r4, r1, 0x38
	  stfs      f0, 0x3C(r1)
	  stfs      f31, 0x40(r1)
	  lfs       f0, 0x38(r1)
	  lfs       f1, -0x5B5C(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x40(r1)
	  lfs       f0, -0x5AFC(r2)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x3C(r1)
	  lwz       r12, 0x368(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x2C
	  lfs       f2, -0x5AF8(r2)
	  fmr       f3, f1
	  bl        -0x1CF14
	  addi      r3, r30, 0x378
	  lwz       r12, 0x378(r30)
	  addi      r4, r1, 0x2C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r30)
	  addi      r5, r30, 0x358
	  addi      r6, r30, 0x368
	  addi      r7, r30, 0x378
	  li        r4, 0
	  bl        -0x13EDC
	  lwz       r3, 0x460(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139E5C
 * Size:	00012C
 */
void TaiNapkidRisingAscendingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  addi      r3, r1, 0x1C
	  stfd      f30, 0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  addi      r4, r31, 0x94
	  bl        -0x1D000
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x34
	  bl        -0x1D04C
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE1CA8
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE1E30
	  stfs      f1, 0x34(r1)
	  addi      r3, r31, 0x368
	  lfs       f0, -0x1070(r13)
	  addi      r4, r1, 0x34
	  stfs      f0, 0x38(r1)
	  stfs      f31, 0x3C(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f1, -0x5B5C(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x38(r1)
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x28
	  lfs       f2, -0x5B94(r2)
	  fmr       f3, f1
	  bl        -0x1D048
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0x14010
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139F88
 * Size:	0001D4
 */
bool TaiNapkidThrowingPikiAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r4
	  stw       r30, 0xA0(r1)
	  stw       r29, 0x9C(r1)
	  stw       r28, 0x98(r1)
	  lwz       r0, -0x99C(r13)
	  lwz       r3, 0x414(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0x1B0
	  addi      r4, r31, 0x70
	  addi      r3, r1, 0x8C
	  bl        -0x1D140
	  lwz       r3, 0x2C4(r31)
	  mr        r4, r31
	  lwz       r5, 0x84(r3)
	  addi      r3, r1, 0x7C
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xF8(r5)
	  fneg      f0, f0
	  stfs      f0, 0x90(r1)
	  bl        -0xA9364
	  addi      r29, r1, 0x7C
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x154

	.loc_0x84:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xAC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC8

	.loc_0xAC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC8:
	  cmplwi    r30, 0
	  beq-      .loc_0x1B0
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x138
	  mr        r3, r30
	  bl        -0xAA04C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x68(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2F38
	  stw       r31, 0x6C(r1)
	  addi      r4, r1, 0x68
	  addi      r3, r30, 0
	  stw       r0, 0x68(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x8C(r1)
	  li        r3, 0
	  stfs      f0, 0x70(r30)
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0x74(r30)
	  lfs       f0, 0x94(r1)
	  stfs      f0, 0x78(r30)
	  b         .loc_0x1B4

	.loc_0x138:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x154:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x17C
	  li        r0, 0x1
	  b         .loc_0x1A8

	.loc_0x17C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1A4
	  li        r0, 0x1
	  b         .loc_0x1A8

	.loc_0x1A4:
	  li        r0, 0

	.loc_0x1A8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x84

	.loc_0x1B0:
	  li        r3, 0

	.loc_0x1B4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  lwz       r28, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A15C
 * Size:	0000C4
 */
bool TaiNapkidFlickAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  addi      r3, r1, 0x44
	  stw       r31, 0x6C(r1)
	  bl        -0xA94F0
	  lwz       r31, 0x4C(r1)
	  addi      r3, r1, 0x28
	  addi      r4, r1, 0x3C
	  bl        -0x1E90C
	  lfs       f1, -0x5B8C(r2)
	  addi      r3, r1, 0x28
	  lfs       f2, -0x5B04(r2)
	  lfs       f3, -0x5B24(r2)
	  lfs       f4, -0x5B30(r2)
	  bl        -0x1E880
	  xoris     r0, r31, 0x8000
	  lfd       f1, -0x5AF0(r2)
	  stw       r0, 0x64(r1)
	  lis       r31, 0x4330
	  addi      r3, r1, 0x28
	  stw       r31, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f1, f0, f1
	  bl        -0x1E814
	  fmr       f31, f1
	  bl        0xDDEA8
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x5AF0(r2)
	  stw       r0, 0x5C(r1)
	  lfs       f1, -0x5AE8(r2)
	  stw       r31, 0x58(r1)
	  lfs       f0, -0x5B8C(r2)
	  lfd       f2, 0x58(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0xA8
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A220
 * Size:	0001A8
 */
void TaiNapkidFallingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r3, r1, 0x28
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  addi      r4, r30, 0x94
	  bl        -0x1D3C0
	  lwz       r12, 0x358(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x50
	  lfs       f2, -0x5AE4(r2)
	  fmr       f3, f1
	  bl        -0x1D390
	  mr        r3, r30
	  bl        0xE6B4
	  fmr       f2, f1
	  lwz       r3, 0x45C(r30)
	  lfs       f1, -0x5B84(r2)
	  addi      r5, r30, 0x358
	  addi      r6, r1, 0x50
	  li        r4, 0
	  bl        -0x14148
	  lwz       r3, 0x45C(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x40
	  addi      r4, r30, 0
	  bl        -0xA962C
	  addi      r31, r1, 0x40
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x134

	.loc_0xB4:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xD8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF0

	.loc_0xD8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  beq-      .loc_0x118
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x118
	  bl        -0xAA30C
	  cmpwi     r30, 0
	  blt-      .loc_0x118
	  subi      r30, r30, 0x1

	.loc_0x118:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x134:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15C
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x15C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x184
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x184:
	  li        r0, 0

	.loc_0x188:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB4

	.loc_0x190:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A3C8
 * Size:	000008
 */
bool TaiNapkidFallingAction::act(Teki&) { return false; }

/*
 * --INFO--
 * Address:	8013A3D0
 * Size:	000014
 */
void TaiNapkidShockFallingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x98(r4)
	  lfs       f0, -0x5B88(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A3E4
 * Size:	0000D8
 */
void TaiNapkidFallingWaterEffectAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  bl        0xF534
	  lfs       f0, 0x94(r30)
	  mr        r31, r3
	  li        r4, 0x1
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x1C(r1)
	  lfs       f2, 0x24(r1)
	  bl        -0xD252C
	  cmpwi     r31, 0x5
	  stfs      f1, 0x20(r1)
	  bne-      .loc_0x90
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x1C
	  li        r4, 0x55
	  li        r6, 0
	  li        r7, 0
	  bl        0x626E4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x15
	  lwz       r12, 0x1C0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC0

	.loc_0x90:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x1C
	  li        r4, 0x44
	  li        r6, 0
	  li        r7, 0
	  bl        0x626B0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x10
	  lwz       r12, 0x1C0(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
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
 * Address:	8013A4BC
 * Size:	000044
 */
void TaiNapkidStartDroppingWaterAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  bl        0xF460
	  cmpwi     r3, 0x5
	  bne-      .loc_0x30
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0xF510

	.loc_0x30:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
