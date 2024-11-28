#include "TAI/Kinoko.h"

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
 * Address:	8012FB98
 * Size:	000084
 */
TaiKinokoSoundTable::TaiKinokoSoundTable()
    : PaniSoundTable(10)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xA
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x10B44
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xE8BC8
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x43
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
 * Address:	8012FC1C
 * Size:	000518
 */
TaiKinokoParameters::TaiKinokoParameters()
    : TekiParameters(22, 60)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r5, 0x3C
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  subi      r31, r4, 0x79B8
	  li        r4, 0x16
	  stw       r30, 0xF8(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xF4(r1)
	  bl        0x1C100
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7490
	  stw       r0, 0x0(r30)
	  li        r4, 0x14
	  li        r3, 0x15
	  lwz       r5, 0x84(r30)
	  li        r10, 0x32
	  li        r0, 0x33
	  lwz       r5, 0x0(r5)
	  li        r9, 0x34
	  mulli     r4, r4, 0xC
	  lwz       r7, 0x8(r5)
	  add       r6, r7, r4
	  addi      r4, r31, 0x1C
	  stw       r4, 0x0(r6)
	  li        r5, 0
	  mulli     r3, r3, 0xC
	  stw       r5, 0x4(r6)
	  li        r4, 0x1E
	  stw       r4, 0x8(r6)
	  add       r4, r7, r3
	  addi      r3, r31, 0x38
	  stw       r3, 0x0(r4)
	  li        r8, 0x35
	  li        r3, 0x64
	  stw       r5, 0x4(r4)
	  li        r7, 0x36
	  li        r6, 0x37
	  stw       r3, 0x8(r4)
	  li        r4, 0x38
	  mulli     r12, r10, 0xC
	  lwz       r10, 0x84(r30)
	  lwz       r29, 0x4(r10)
	  addi      r11, r31, 0x4C
	  mulli     r10, r0, 0xC
	  lwz       r0, 0x8(r29)
	  add       r12, r0, r12
	  stw       r11, 0x0(r12)
	  mulli     r9, r9, 0xC
	  lfs       f9, -0x5CB0(r2)
	  mulli     r8, r8, 0xC
	  stfs      f9, 0x4(r12)
	  lfs       f8, -0x5CAC(r2)
	  mulli     r7, r7, 0xC
	  stfs      f8, 0x8(r12)
	  add       r11, r0, r10
	  addi      r10, r31, 0x60
	  stw       r10, 0x0(r11)
	  mulli     r6, r6, 0xC
	  stfs      f9, 0x4(r11)
	  add       r10, r0, r9
	  stfs      f8, 0x8(r11)
	  addi      r9, r31, 0x74
	  mulli     r4, r4, 0xC
	  stw       r9, 0x0(r10)
	  stfs      f9, 0x4(r10)
	  add       r9, r0, r8
	  addi      r8, r31, 0x84
	  stfs      f8, 0x8(r10)
	  add       r10, r0, r7
	  addi      r7, r31, 0x98
	  stw       r8, 0x0(r9)
	  add       r8, r0, r6
	  addi      r6, r31, 0xB0
	  stfs      f9, 0x4(r9)
	  add       r11, r0, r4
	  addi      r4, r31, 0xC4
	  stfs      f8, 0x8(r9)
	  stw       r7, 0x0(r10)
	  stfs      f9, 0x4(r10)
	  lfs       f7, -0x5CA8(r2)
	  stfs      f7, 0x8(r10)
	  stw       r6, 0x0(r8)
	  stfs      f9, 0x4(r8)
	  lfs       f6, -0x5CA4(r2)
	  stfs      f6, 0x8(r8)
	  stw       r4, 0x0(r11)
	  stfs      f9, 0x4(r11)
	  li        r4, 0x39
	  stfs      f6, 0x8(r11)
	  mulli     r4, r4, 0xC
	  add       r6, r0, r4
	  addi      r4, r31, 0xD4
	  stw       r4, 0x0(r6)
	  li        r4, 0x3A
	  mulli     r4, r4, 0xC
	  stfs      f9, 0x4(r6)
	  stfs      f8, 0x8(r6)
	  add       r6, r0, r4
	  addi      r4, r31, 0xE4
	  stw       r4, 0x0(r6)
	  li        r4, 0x3B
	  mulli     r4, r4, 0xC
	  stfs      f9, 0x4(r6)
	  lfs       f5, -0x1CA4(r13)
	  add       r11, r0, r4
	  addi      r0, r31, 0xF8
	  stfs      f5, 0x8(r6)
	  li        r12, 0x1
	  li        r10, -0x1
	  stw       r0, 0x0(r11)
	  li        r9, 0x3
	  li        r8, 0x5
	  stfs      f9, 0x4(r11)
	  li        r4, 0xA
	  li        r0, 0x14
	  lfs       f0, -0x5CA0(r2)
	  li        r7, 0x28
	  stfs      f0, 0x8(r11)
	  lwz       r6, 0x84(r30)
	  lwz       r11, 0x0(r6)
	  lwz       r11, 0x0(r11)
	  stw       r12, 0x0(r11)
	  lwz       r11, 0x0(r6)
	  lwz       r11, 0x0(r11)
	  stw       r5, 0x18(r11)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r10, 0xC(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r9, 0x28(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r8, 0x2C(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r4, 0x30(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r4, 0x34(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x38(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r7, 0x3C(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r3, 0x40(r5)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x4(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C9C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C98(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C94(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  lfs       f4, -0x5C90(r2)
	  lwz       r3, 0x4(r6)
	  fmuls     f0, f5, f4
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f3, -0x5C8C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x18(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C88(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f2, -0x5C84(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x70(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x20(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C80(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x28(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C7C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xB4(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f1, -0x5C78(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x2C(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f9, 0x30(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f8, 0x44(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x48(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C74(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4C(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C70(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x50(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C6C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x54(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f8, 0x5C(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x3C(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x40(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C68(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C64(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x80(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x84(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x88(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f9, 0x8C(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f9, 0x90(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C60(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x98(r3)
	  lwz       r3, 0x4(r6)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x9C(r3)
	  lwz       r3, 0x4(r6)
	  lfs       f0, -0x5C5C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xA0(r3)
	  lwz       r5, 0x4(r6)
	  mr        r3, r30
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0xAC(r5)
	  lwz       r5, 0x4(r6)
	  lfs       f0, -0x5C58(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xB0(r5)
	  lwz       r5, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  stw       r4, 0x50(r5)
	  lwz       r4, 0x0(r6)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x54(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C54(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xC8(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C50(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xCC(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f6, 0xD0(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f8, 0xD4(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f4, 0xD8(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f7, 0xDC(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C4C(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xE0(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C48(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xE4(r4)
	  lfs       f0, -0x5C44(r2)
	  lwz       r4, 0x4(r6)
	  fdivs     f0, f5, f0
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xE8(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0xEC(r4)
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  lwz       r29, 0xF4(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80130134
 * Size:	001298
 */
TaiKinokoStrategy::TaiKinokoStrategy(TekiParameters*)
    : TaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x270(r1)
	  stmw      r14, 0x228(r1)
	  addi      r30, r4, 0
	  addi      r31, r3, 0
	  li        r4, 0xD
	  bl        -0x8D70
	  lis       r3, 0x802D
	  subi      r0, r3, 0x75D4
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0xE9164
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6140
	  stw       r0, 0x4(r28)

	.loc_0x64:
	  li        r3, 0xC
	  bl        -0xE9198
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0xA0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r25)
	  subi      r3, r3, 0x6C44
	  li        r0, 0x6
	  stw       r3, 0x4(r25)
	  stw       r0, 0x8(r25)

	.loc_0xA0:
	  li        r3, 0x8
	  bl        -0xE91D4
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0xD4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x6C84
	  stw       r0, 0x4(r19)

	.loc_0xD4:
	  li        r3, 0x8
	  bl        -0xE9208
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x108
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x42D8
	  stw       r0, 0x4(r24)

	.loc_0x108:
	  li        r3, 0x8
	  bl        -0xE923C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x13C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x42D8
	  stw       r0, 0x4(r27)

	.loc_0x13C:
	  li        r3, 0x8
	  bl        -0xE9270
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x170
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x45B8
	  stw       r0, 0x4(r26)

	.loc_0x170:
	  li        r3, 0xC
	  bl        -0xE92A4
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1B8
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x4540
	  lfs       f0, 0xD8(r6)
	  stw       r5, 0x4(r29)
	  stw       r4, 0x0(r29)
	  stw       r0, 0x4(r29)
	  stfs      f0, 0x8(r29)

	.loc_0x1B8:
	  li        r3, 0x24
	  bl        -0xE92EC
	  addi      r15, r3, 0
	  mr.       r3, r15
	  beq-      .loc_0x1D4
	  lfs       f1, -0x5C40(r2)
	  bl        0x1A50

	.loc_0x1D4:
	  li        r3, 0xC
	  bl        -0xE9308
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x21C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r14)
	  li        r4, 0
	  subi      r0, r3, 0x447C
	  stw       r4, 0x8(r14)
	  stw       r0, 0x4(r14)

	.loc_0x21C:
	  li        r3, 0x8
	  bl        -0xE9350
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x250
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x43C0
	  stw       r0, 0x4(r16)

	.loc_0x250:
	  li        r3, 0xC
	  bl        -0xE9384
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0x26C
	  li        r4, 0x3
	  bl        -0x9304

	.loc_0x26C:
	  li        r0, 0
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r17)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r16, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r17)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r17, 0x0(r4)
	  bl        -0xE93D8
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x2EC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r14)
	  li        r4, 0x1
	  subi      r0, r3, 0x447C
	  stw       r4, 0x8(r14)
	  stw       r0, 0x4(r14)

	.loc_0x2EC:
	  li        r3, 0xC
	  bl        -0xE9420
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0x308
	  li        r4, 0x3
	  bl        -0x93A0

	.loc_0x308:
	  li        r0, 0
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r17)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r16, r4, r3
	  li        r3, 0x8
	  lwz       r4, 0x8(r17)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r17, 0x4(r4)
	  bl        -0xE9474
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x374
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x7BBC
	  stw       r0, 0x4(r20)

	.loc_0x374:
	  li        r3, 0xC
	  bl        -0xE94A8
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x3BC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r21)
	  li        r4, 0x2
	  subi      r0, r3, 0x6A8C
	  stw       r4, 0x8(r21)
	  stw       r0, 0x4(r21)

	.loc_0x3BC:
	  li        r3, 0x8
	  bl        -0xE94F0
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x3F0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r23)
	  subi      r0, r3, 0x45FC
	  stw       r0, 0x4(r23)

	.loc_0x3F0:
	  li        r3, 0x14
	  bl        -0xE9524
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x448
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0xE4(r6)
	  stw       r5, 0x4(r14)
	  stw       r4, 0x0(r14)
	  stw       r3, 0x4(r14)
	  stw       r0, 0x8(r14)
	  stfs      f0, 0xC(r14)
	  lfs       f0, -0x5C3C(r2)
	  stfs      f0, 0x10(r14)

	.loc_0x448:
	  li        r3, 0xC
	  bl        -0xE957C
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x490
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x7AD4
	  lfs       f0, 0xEC(r6)
	  stw       r5, 0x4(r16)
	  stw       r4, 0x0(r16)
	  stw       r0, 0x4(r16)
	  stfs      f0, 0x8(r16)

	.loc_0x490:
	  li        r3, 0x10
	  bl        -0xE95C4
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x4CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0xA
	  lis       r3, 0x802C
	  stw       r0, 0x0(r17)
	  addi      r0, r3, 0x6E14
	  stw       r0, 0x4(r17)
	  stw       r14, 0x8(r17)
	  stw       r16, 0xC(r17)

	.loc_0x4CC:
	  li        r3, 0xC
	  bl        -0xE9600
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x4E8
	  li        r4, 0x7
	  bl        -0x9580

	.loc_0x4E8:
	  li        r0, 0
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r24, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r4,2,0,29
	  li        r8, 0x6
	  stwx      r29, r3, r0
	  rlwinm    r3,r5,2,0,29
	  rlwinm    r5,r6,2,0,29
	  lwz       r6, 0x8(r14)
	  rlwinm    r4,r7,2,0,29
	  rlwinm    r0,r8,2,0,29
	  stwx      r23, r6, r3
	  li        r3, 0x10
	  lwz       r6, 0x8(r14)
	  stwx      r20, r6, r5
	  lwz       r5, 0x8(r14)
	  stwx      r17, r5, r4
	  lwz       r4, 0x8(r14)
	  stwx      r21, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r14, 0x8(r4)
	  bl        -0xE9694
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x5C4
	  lwz       r3, 0x84(r30)
	  lis       r6, 0x802C
	  lis       r5, 0x802D
	  lwz       r7, 0x4(r3)
	  lis       r4, 0x802D
	  lis       r3, 0x802D
	  lwz       r7, 0x0(r7)
	  addi      r0, r6, 0x6620
	  li        r6, 0x4
	  lfs       f0, 0x14(r7)
	  subi      r5, r5, 0x6A6C
	  subi      r4, r4, 0x6A8C
	  stw       r0, 0x4(r21)
	  subi      r0, r3, 0x66E0
	  stw       r6, 0x0(r21)
	  stw       r5, 0x4(r21)
	  stw       r6, 0x8(r21)
	  stw       r4, 0x4(r21)
	  stw       r0, 0x4(r21)
	  stfs      f0, 0xC(r21)

	.loc_0x5C4:
	  li        r3, 0x8
	  bl        -0xE96F8
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x5F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x79D8
	  stw       r0, 0x4(r14)

	.loc_0x5F8:
	  li        r3, 0xC
	  bl        -0xE972C
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x630
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x7590
	  stw       r0, 0x4(r16)
	  stw       r14, 0x8(r16)

	.loc_0x630:
	  li        r3, 0x14
	  bl        -0xE9764
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x688
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x4
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0xC8(r6)
	  stw       r5, 0x4(r14)
	  stw       r4, 0x0(r14)
	  stw       r3, 0x4(r14)
	  stw       r0, 0x8(r14)
	  stfs      f0, 0xC(r14)
	  lfs       f0, -0x5CB0(r2)
	  stfs      f0, 0x10(r14)

	.loc_0x688:
	  li        r3, 0x8
	  bl        -0xE97BC
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x6BC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x45FC
	  stw       r0, 0x4(r17)

	.loc_0x6BC:
	  li        r3, 0xC
	  bl        -0xE97F0
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x6D8
	  li        r4, 0x8
	  bl        -0x9770

	.loc_0x6D8:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r24, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r4,2,0,29
	  li        r4, 0x6
	  stwx      r29, r3, r0
	  li        r8, 0x7
	  rlwinm    r0,r5,2,0,29
	  lwz       r3, 0x8(r18)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r7,2,0,29
	  stwx      r17, r3, r0
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r8,2,0,29
	  lwz       r7, 0x8(r18)
	  li        r3, 0x14
	  stwx      r16, r7, r6
	  lwz       r6, 0x8(r18)
	  stwx      r14, r6, r5
	  lwz       r5, 0x8(r18)
	  stwx      r21, r5, r4
	  lwz       r4, 0x8(r18)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r18, 0xC(r4)
	  bl        -0xE9894
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x7B8
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0xC
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0xCC(r6)
	  stw       r5, 0x4(r21)
	  stw       r4, 0x0(r21)
	  stw       r3, 0x4(r21)
	  stw       r0, 0x8(r21)
	  stfs      f0, 0xC(r21)
	  lfs       f0, -0x5CB0(r2)
	  stfs      f0, 0x10(r21)

	.loc_0x7B8:
	  li        r3, 0x10
	  bl        -0xE98EC
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x820
	  lwz       r3, 0x84(r30)
	  lis       r6, 0x802C
	  lis       r5, 0x802D
	  lwz       r7, 0x4(r3)
	  lis       r4, 0x802D
	  lis       r3, 0x802D
	  lwz       r8, 0x0(r7)
	  addi      r0, r6, 0x6620
	  li        r7, -0x1
	  lfs       f0, 0x10(r8)
	  subi      r6, r5, 0x6A6C
	  li        r5, 0x6
	  stw       r0, 0x4(r22)
	  subi      r4, r4, 0x6A8C
	  subi      r0, r3, 0x6868
	  stw       r7, 0x0(r22)
	  stw       r6, 0x4(r22)
	  stw       r5, 0x8(r22)
	  stw       r4, 0x4(r22)
	  stw       r0, 0x4(r22)
	  stfs      f0, 0xC(r22)

	.loc_0x820:
	  li        r3, 0xC
	  bl        -0xE9954
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x868
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x0(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x5
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x4500
	  lwz       r3, 0x50(r6)
	  stw       r5, 0x4(r18)
	  stw       r4, 0x0(r18)
	  stw       r0, 0x4(r18)
	  stw       r3, 0x8(r18)

	.loc_0x868:
	  li        r3, 0x8
	  bl        -0xE999C
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x89C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x44BC
	  stw       r0, 0x4(r17)

	.loc_0x89C:
	  li        r3, 0x8
	  bl        -0xE99D0
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x8D0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x77C4
	  stw       r0, 0x4(r16)

	.loc_0x8D0:
	  li        r3, 0xC
	  bl        -0xE9A04
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x8EC
	  li        r4, 0xA
	  bl        -0x9984

	.loc_0x8EC:
	  li        r0, 0
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,2,0,29
	  li        r7, 0x3
	  stwx      r16, r3, r0
	  li        r8, 0x4
	  li        r9, 0x5
	  lwz       r4, 0x8(r14)
	  rlwinm    r3,r5,2,0,29
	  li        r0, 0x6
	  stwx      r22, r4, r3
	  li        r10, 0x7
	  li        r3, 0x8
	  lwz       r6, 0x8(r14)
	  rlwinm    r5,r7,2,0,29
	  li        r4, 0x9
	  stwx      r24, r6, r5
	  rlwinm    r5,r8,2,0,29
	  rlwinm    r8,r9,2,0,29
	  lwz       r9, 0x8(r14)
	  rlwinm    r7,r0,2,0,29
	  rlwinm    r6,r10,2,0,29
	  stwx      r29, r9, r5
	  rlwinm    r5,r3,2,0,29
	  rlwinm    r0,r4,2,0,29
	  lwz       r4, 0x8(r14)
	  li        r3, 0x8
	  stwx      r26, r4, r8
	  lwz       r4, 0x8(r14)
	  stwx      r18, r4, r7
	  lwz       r4, 0x8(r14)
	  stwx      r17, r4, r6
	  lwz       r4, 0x8(r14)
	  stwx      r21, r4, r5
	  lwz       r4, 0x8(r14)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r14, 0x10(r4)
	  bl        -0xE9AC8
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x9C8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x7640
	  stw       r0, 0x4(r14)

	.loc_0x9C8:
	  li        r3, 0xC
	  bl        -0xE9AFC
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0xA04
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xA
	  stw       r3, 0x4(r16)
	  stw       r0, 0x8(r16)

	.loc_0xA04:
	  li        r3, 0xC
	  bl        -0xE9B38
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0xA40
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0x6
	  lis       r3, 0x802D
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x6B20
	  stw       r0, 0x4(r17)
	  lwz       r0, -0x99C(r13)
	  stw       r0, 0x8(r17)

	.loc_0xA40:
	  li        r3, 0xC
	  bl        -0xE9B74
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0xA5C
	  li        r4, 0x6
	  bl        -0x9AF4

	.loc_0xA5C:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r26, r3, r0
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r7,2,0,29
	  lwz       r6, 0x8(r18)
	  li        r3, 0x8
	  stwx      r17, r6, r5
	  lwz       r5, 0x8(r18)
	  stwx      r16, r5, r4
	  lwz       r4, 0x8(r18)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r18, 0x14(r4)
	  bl        -0xE9BF8
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0xAF8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x7
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x45B8
	  stw       r0, 0x4(r16)

	.loc_0xAF8:
	  li        r3, 0x14
	  bl        -0xE9C2C
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0xB50
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x8
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0xD0(r6)
	  stw       r5, 0x4(r14)
	  stw       r4, 0x0(r14)
	  stw       r3, 0x4(r14)
	  stw       r0, 0x8(r14)
	  stfs      f0, 0xC(r14)
	  lfs       f0, -0x5CB0(r2)
	  stfs      f0, 0x10(r14)

	.loc_0xB50:
	  li        r3, 0xC
	  bl        -0xE9C84
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0xB6C
	  li        r4, 0x4
	  bl        -0x9C04

	.loc_0xB6C:
	  li        r0, 0
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r28, r3, r0
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x8(r17)
	  li        r3, 0xC
	  stwx      r16, r5, r4
	  lwz       r4, 0x8(r17)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r17, 0x18(r4)
	  bl        -0xE9CE8
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0xBF0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, 0x8
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r3, r3, 0x3630
	  li        r0, 0
	  stw       r3, 0x4(r14)
	  stw       r0, 0x8(r14)

	.loc_0xBF0:
	  li        r3, 0xC
	  bl        -0xE9D24
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0xC0C
	  li        r4, 0x4
	  bl        -0x9CA4

	.loc_0xC0C:
	  li        r0, 0
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r28, r3, r0
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x8(r17)
	  li        r3, 0xC
	  stwx      r16, r5, r4
	  lwz       r4, 0x8(r17)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r17, 0x1C(r4)
	  bl        -0xE9D88
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0xC9C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r22)
	  li        r4, 0x9
	  subi      r0, r3, 0x6A8C
	  stw       r4, 0x8(r22)
	  stw       r0, 0x4(r22)

	.loc_0xC9C:
	  li        r3, 0x8
	  bl        -0xE9DD0
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xCD0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x76CC
	  stw       r0, 0x4(r27)

	.loc_0xCD0:
	  li        r3, 0x8
	  bl        -0xE9E04
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xD04
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x7684
	  stw       r0, 0x4(r28)

	.loc_0xD04:
	  li        r3, 0x10
	  bl        -0xE9E38
	  addi      r21, r3, 0
	  mr.       r3, r21
	  beq-      .loc_0xD24
	  li        r4, 0x2
	  li        r5, 0x2
	  bl        -0xA050

	.loc_0xD24:
	  li        r3, 0xC
	  bl        -0xE9E58
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0xD6C
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x0(r5)
	  addi      r5, r4, 0x6620
	  li        r4, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x6B60
	  lwz       r3, 0x54(r6)
	  stw       r5, 0x4(r7)
	  stw       r4, 0x0(r7)
	  stw       r0, 0x4(r7)
	  stw       r3, 0x8(r7)

	.loc_0xD6C:
	  lwz       r4, 0xC(r21)
	  li        r3, 0xC
	  stw       r7, 0x0(r4)
	  bl        -0xE9EA8
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0xDBC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r5)
	  li        r4, 0
	  subi      r0, r3, 0x6AD8
	  stw       r4, 0x8(r5)
	  stw       r0, 0x4(r5)

	.loc_0xDBC:
	  lwz       r4, 0xC(r21)
	  li        r3, 0xC
	  stw       r5, 0x4(r4)
	  bl        -0xE9EF8
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0xDE0
	  li        r4, 0x5
	  bl        -0x9E78

	.loc_0xDE0:
	  li        r0, 0
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,2,0,29
	  stwx      r26, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r28, r3, r0
	  li        r0, 0x4
	  rlwinm    r3,r4,2,0,29
	  lwz       r5, 0x8(r14)
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r5, r3
	  li        r3, 0xC
	  lwz       r5, 0x8(r14)
	  stwx      r21, r5, r4
	  lwz       r4, 0x8(r14)
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r14, 0x20(r4)
	  bl        -0xE9F6C
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0xE80
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r14)
	  li        r4, 0xC
	  subi      r0, r3, 0x6A8C
	  stw       r4, 0x8(r14)
	  stw       r0, 0x4(r14)

	.loc_0xE80:
	  li        r3, 0xC
	  bl        -0xE9FB4
	  addi      r16, r3, 0
	  mr.       r3, r16
	  beq-      .loc_0xE9C
	  li        r4, 0x6
	  bl        -0x9F34

	.loc_0xE9C:
	  li        r0, 0
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r26, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r28, r3, r0
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r7,2,0,29
	  lwz       r6, 0x8(r16)
	  li        r3, 0x10
	  stwx      r27, r6, r5
	  lwz       r5, 0x8(r16)
	  stwx      r21, r5, r4
	  lwz       r4, 0x8(r16)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r16, 0x30(r4)
	  bl        -0xEA038
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0xF24
	  li        r4, 0x2
	  li        r5, 0x2
	  bl        -0xA250

	.loc_0xF24:
	  li        r3, 0xC
	  bl        -0xEA058
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0xF6C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r5)
	  li        r4, 0
	  subi      r0, r3, 0x6AD8
	  stw       r4, 0x8(r5)
	  stw       r0, 0x4(r5)

	.loc_0xF6C:
	  lwz       r4, 0xC(r14)
	  li        r3, 0xC
	  stw       r5, 0x0(r4)
	  bl        -0xEA0A8
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0xFB0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xB
	  stw       r3, 0x4(r5)
	  stw       r0, 0x8(r5)

	.loc_0xFB0:
	  lwz       r4, 0xC(r14)
	  li        r3, 0xC
	  stw       r5, 0x4(r4)
	  bl        -0xEA0EC
	  addi      r16, r3, 0
	  mr.       r3, r16
	  beq-      .loc_0xFD4
	  li        r4, 0x2
	  bl        -0xA06C

	.loc_0xFD4:
	  li        r0, 0
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r0,2,0,29
	  stwx      r26, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r16)
	  li        r3, 0x10
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r16, 0x24(r4)
	  bl        -0xEA130
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x1064
	  lwz       r3, 0x84(r30)
	  lis       r6, 0x802C
	  lis       r5, 0x802D
	  lwz       r7, 0x4(r3)
	  lis       r4, 0x802D
	  lis       r3, 0x802D
	  lwz       r8, 0x0(r7)
	  addi      r0, r6, 0x6620
	  li        r7, 0xB
	  lfs       f0, 0xE8(r8)
	  subi      r6, r5, 0x6A6C
	  li        r5, 0x4
	  stw       r0, 0x4(r14)
	  subi      r4, r4, 0x6A8C
	  subi      r0, r3, 0x67CC
	  stw       r7, 0x0(r14)
	  stw       r6, 0x4(r14)
	  stw       r5, 0x8(r14)
	  stw       r4, 0x4(r14)
	  stw       r0, 0x4(r14)
	  stfs      f0, 0xC(r14)

	.loc_0x1064:
	  li        r3, 0x8
	  bl        -0xEA198
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x1098
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x69B4
	  stw       r0, 0x4(r16)

	.loc_0x1098:
	  li        r3, 0xC
	  bl        -0xEA1CC
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0x10B4
	  li        r4, 0x7
	  bl        -0xA14C

	.loc_0x10B4:
	  li        r0, 0
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r4,2,0,29
	  li        r8, 0x6
	  stwx      r23, r3, r0
	  rlwinm    r3,r5,2,0,29
	  rlwinm    r5,r6,2,0,29
	  lwz       r6, 0x8(r17)
	  rlwinm    r4,r7,2,0,29
	  rlwinm    r0,r8,2,0,29
	  stwx      r20, r6, r3
	  li        r3, 0x10
	  lwz       r6, 0x8(r17)
	  stwx      r16, r6, r5
	  lwz       r5, 0x8(r17)
	  stwx      r14, r5, r4
	  lwz       r4, 0x8(r17)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r17, 0x28(r4)
	  bl        -0xEA260
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x1194
	  lwz       r3, 0x84(r30)
	  lis       r6, 0x802C
	  lis       r5, 0x802D
	  lwz       r7, 0x4(r3)
	  lis       r4, 0x802D
	  lis       r3, 0x802D
	  lwz       r8, 0x0(r7)
	  addi      r0, r6, 0x6620
	  li        r7, -0x1
	  lfs       f0, 0xC(r8)
	  subi      r6, r5, 0x6A6C
	  li        r5, 0x6
	  stw       r0, 0x4(r14)
	  subi      r4, r4, 0x6A8C
	  subi      r0, r3, 0x65C4
	  stw       r7, 0x0(r14)
	  stw       r6, 0x4(r14)
	  stw       r5, 0x8(r14)
	  stw       r4, 0x4(r14)
	  stw       r0, 0x4(r14)
	  stfs      f0, 0xC(r14)

	.loc_0x1194:
	  li        r3, 0xC
	  bl        -0xEA2C8
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x11DC
	  lwz       r5, 0x84(r30)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x2
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x7B18
	  lfs       f0, 0x40(r6)
	  stw       r5, 0x4(r16)
	  stw       r4, 0x0(r16)
	  stw       r0, 0x4(r16)
	  stfs      f0, 0x8(r16)

	.loc_0x11DC:
	  li        r3, 0xC
	  bl        -0xEA310
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0x11F8
	  li        r4, 0x8
	  bl        -0xA290

	.loc_0x11F8:
	  li        r0, 0
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r14, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r17)
	  rlwinm    r0,r4,2,0,29
	  li        r4, 0x6
	  stwx      r24, r3, r0
	  li        r8, 0x7
	  rlwinm    r0,r5,2,0,29
	  lwz       r3, 0x8(r17)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r7,2,0,29
	  stwx      r29, r3, r0
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r8,2,0,29
	  lwz       r7, 0x8(r17)
	  mr        r3, r31
	  stwx      r23, r7, r6
	  lwz       r6, 0x8(r17)
	  stwx      r20, r6, r5
	  lwz       r5, 0x8(r17)
	  stwx      r16, r5, r4
	  lwz       r4, 0x8(r17)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r17, 0x2C(r4)
	  lwz       r0, 0x274(r1)
	  lmw       r14, 0x228(r1)
	  addi      r1, r1, 0x270
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801313CC
 * Size:	0000B0
 */
void TaiKinokoStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x1C
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  li        r4, 0x9C
	  lfs       f0, -0x1414(r13)
	  lfs       f1, -0x1410(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x140C(r13)
	  stfs      f1, 0x20(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x24(r1)
	  bl        0x6B724
	  lwz       r4, 0x3D8(r31)
	  addi      r5, r1, 0x10
	  li        r6, 0
	  stw       r3, 0x0(r4)
	  li        r4, 0x9C
	  li        r7, 0
	  lfs       f0, -0x1408(r13)
	  lfs       f1, -0x1404(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x1400(r13)
	  stfs      f1, 0x14(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x18(r1)
	  bl        0x6B6EC
	  lwz       r5, 0x3D8(r31)
	  mr        r4, r31
	  stw       r3, 0x4(r5)
	  mr        r3, r30
	  bl        -0x9FCC
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
 * Address:	8013147C
 * Size:	0001B4
 */
void TaiKinokoStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stw       r31, 0x84(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x80(r1)
	  addi      r30, r4, 0
	  bl        0x1BD24
	  lwz       r3, 0x3D8(r30)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x194
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9AC(r13)
	  and.      r0, r3, r0
	  bne-      .loc_0x64
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x18550
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        0x18544
	  b         .loc_0x194

	.loc_0x64:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x18510
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        0x18504
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x3C
	  addi      r3, r3, 0x1E0
	  bl        -0xF30C8
	  addi      r3, r1, 0x30
	  bl        -0x146B8
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xEA63C
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xEA7C4
	  stfs      f1, 0x30(r1)
	  addi      r3, r1, 0x24
	  lfs       f0, -0x1418(r13)
	  stfs      f0, 0x34(r1)
	  stfs      f31, 0x38(r1)
	  lfs       f0, 0x30(r1)
	  lfs       f1, -0x5C80(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  bl        -0x14710
	  addi      r3, r30, 0
	  addi      r4, r1, 0x24
	  addi      r6, r1, 0x3C
	  li        r5, 0x16
	  bl        0x182D0
	  lfs       f1, 0x24(r1)
	  mr        r3, r30
	  lfs       f0, 0x30(r1)
	  addi      r5, r1, 0x24
	  li        r4, 0
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x28(r1)
	  lfs       f0, 0x34(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x2C(r1)
	  lfs       f0, 0x38(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  bl        0x18488
	  addi      r3, r30, 0
	  addi      r4, r1, 0x24
	  addi      r6, r1, 0x3C
	  li        r5, 0x11
	  bl        0x1827C
	  lfs       f1, 0x24(r1)
	  mr        r3, r30
	  lfs       f0, 0x30(r1)
	  addi      r5, r1, 0x24
	  li        r4, 0x1
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x28(r1)
	  lfs       f0, 0x34(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x2C(r1)
	  lfs       f0, 0x38(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  bl        0x18434

	.loc_0x194:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80131630
 * Size:	000124
 */
void TaiKinokoStrategy::createEffect(Teki&, int)
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
	  bl        0x1BB74
	  lwz       r0, 0x3180(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  addi      r4, r30, 0x94
	  addi      r3, r1, 0x14
	  bl        -0x147E4
	  cmpwi     r31, 0
	  bne-      .loc_0x5C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x97
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B4B4
	  b         .loc_0x10C

	.loc_0x5C:
	  cmpwi     r31, 0x1
	  bne-      .loc_0x98
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x9A
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B490
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x98
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B478
	  b         .loc_0x10C

	.loc_0x98:
	  cmpwi     r31, 0x2
	  bne-      .loc_0xD4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x9B
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B454
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x99
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B43C
	  b         .loc_0x10C

	.loc_0xD4:
	  cmpwi     r31, 0x3
	  bne-      .loc_0x10C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x94
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B418
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x95
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B400

	.loc_0x10C:
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
 * Address:	80131754
 * Size:	000078
 */
void TaiKinokoTurningOverAction::start(Teki&)
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
	  lfs       f30, 0xA0(r4)
	  fmr       f1, f30
	  bl        0xEA3DC
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xEA564
	  lfs       f0, -0x5C84(r2)
	  mr        r3, r31
	  lfs       f3, -0x1418(r13)
	  fmuls     f1, f1, f0
	  fmuls     f3, f3, f0
	  fmuls     f2, f31, f0
	  stfs      f1, 0xA4(r31)
	  stfs      f3, 0xA8(r31)
	  stfs      f2, 0xAC(r31)
	  bl        0x16640
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
 * Address:	801317CC
 * Size:	000054
 */
bool TaiKinokoChargingSporesAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  lwz       r3, 0x414(r4)
	  lwz       r0, -0x998(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x40
	  addi      r4, r4, 0x94
	  addi      r3, r1, 0x20
	  bl        -0x14970
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x20
	  li        r4, 0x96
	  li        r6, 0
	  li        r7, 0
	  bl        0x6B330

	.loc_0x40:
	  li        r3, 0
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80131820
 * Size:	000004
 */
void TaiKinokoDischargingSporesAction::start(Teki&) { }

/*
 * --INFO--
 * Address:	80131824
 * Size:	000160
 */
bool TaiKinokoDischargingSporesAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r4
	  stw       r30, 0xB0(r1)
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x13C
	  lwz       r3, 0x414(r31)
	  lwz       r0, -0x99C(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x4C
	  mr        r3, r31
	  bl        0x16584
	  b         .loc_0x13C

	.loc_0x4C:
	  lwz       r0, -0x994(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x13C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x9C(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x301C
	  stw       r31, 0xA0(r1)
	  addi      r30, r1, 0x9C
	  li        r4, 0
	  stw       r0, 0x9C(r1)
	  lwz       r3, 0x2C8(r31)
	  bl        -0x99F0
	  fmr       f30, f1
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x1
	  bl        -0x99E8
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0xA
	  lwz       r3, 0x84(r3)
	  bl        -0xE6B8
	  lis       r3, 0x802B
	  fmuls     f0, f31, f30
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x88(r1)
	  addi      r9, r3, 0x6964
	  stw       r0, 0xA4(r1)
	  lis       r5, 0x802D
	  lis       r3, 0x802C
	  fmuls     f0, f1, f0
	  stw       r0, 0x94(r1)
	  lis       r4, 0x802D
	  stw       r9, 0x88(r1)
	  subi      r0, r5, 0x29D8
	  addi      r7, r3, 0x685C
	  stw       r9, 0xA4(r1)
	  subi      r8, r4, 0x295C
	  addi      r6, r1, 0x94
	  stw       r0, 0x88(r1)
	  addi      r0, r1, 0x88
	  addi      r3, r31, 0
	  stw       r9, 0x94(r1)
	  addi      r4, r30, 0
	  addi      r5, r1, 0xA4
	  stw       r7, 0xA4(r1)
	  stw       r31, 0x8C(r1)
	  stw       r8, 0x94(r1)
	  stw       r6, 0xA8(r1)
	  stfs      f0, 0x90(r1)
	  stw       r31, 0x98(r1)
	  stw       r0, 0xAC(r1)
	  bl        0x161D0
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x6
	  li        r5, 0
	  bl        0x4B478

	.loc_0x13C:
	  lwz       r0, 0xCC(r1)
	  li        r3, 0
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80131984
 * Size:	0003D0
 */
bool TaiKinokoTerritoryRunningAwayAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stfd      f31, 0x160(r1)
	  addi      r6, r1, 0x78
	  addi      r5, r1, 0x74
	  stfd      f30, 0x158(r1)
	  stfd      f29, 0x150(r1)
	  stfd      f28, 0x148(r1)
	  stfd      f27, 0x140(r1)
	  stw       r31, 0x13C(r1)
	  stw       r30, 0x138(r1)
	  mr        r30, r4
	  addi      r31, r30, 0x94
	  lwz       r3, 0x2C8(r4)
	  addi      r4, r1, 0x70
	  lfs       f0, -0x5CB0(r2)
	  addi      r7, r3, 0x10
	  stfs      f0, 0xA0(r1)
	  stfs      f0, 0x9C(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x18(r3)
	  addi      r3, r1, 0x98
	  lfs       f1, 0x9C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  bl        -0xD4380
	  lfs       f1, 0x98(r1)
	  lfs       f0, 0x9C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x123DF0
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xEC(r3)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xD8
	  li        r3, 0
	  b         .loc_0x3A4

	.loc_0xD8:
	  addi      r3, r1, 0x124
	  bl        -0x14C0C
	  lwz       r3, 0x2C8(r30)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x10(r3)
	  addi      r4, r3, 0x10
	  lfs       f3, 0x4(r31)
	  addi      r3, r1, 0x124
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r31)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x124(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x128(r1)
	  stfs      f0, 0x12C(r1)
	  bl        -0x14A88
	  addi      r3, r1, 0x118
	  bl        -0x14C54
	  lfs       f28, 0xA0(r30)
	  fmr       f1, f28
	  bl        0xEA0A0
	  fmr       f27, f1
	  fmr       f1, f28
	  bl        0xEA228
	  stfs      f1, 0x118(r1)
	  lfs       f0, -0x1418(r13)
	  stfs      f0, 0x11C(r1)
	  stfs      f27, 0x120(r1)
	  lfs       f3, 0x118(r1)
	  lfs       f2, 0x124(r1)
	  lfs       f1, 0x11C(r1)
	  lfs       f0, 0x128(r1)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x120(r1)
	  fmuls     f0, f1, f0
	  lfs       f3, 0x12C(r1)
	  lfs       f1, -0x5CB0(r2)
	  fmuls     f3, f4, f3
	  fadds     f0, f2, f0
	  fadds     f27, f3, f0
	  fcmpo     cr0, f27, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x194
	  li        r3, 0
	  b         .loc_0x3A4

	.loc_0x194:
	  fmr       f3, f1
	  lfs       f2, -0x5CA8(r2)
	  addi      r3, r1, 0x108
	  bl        -0x14C48
	  addi      r3, r1, 0xFC
	  bl        -0x14CD8
	  lfs       f0, 0x128(r1)
	  lfs       f2, 0x110(r1)
	  lfs       f3, 0x12C(r1)
	  lfs       f1, 0x10C(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0x108(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x124(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0xFC(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x100(r1)
	  stfs      f0, 0x104(r1)
	  lwz       r3, 0x2C4(r30)
	  lfs       f1, 0xFC(r1)
	  lwz       r3, 0x84(r3)
	  lfs       f5, 0x100(r1)
	  fneg      f30, f1
	  lfs       f3, 0x118(r1)
	  lwz       r3, 0x4(r3)
	  fneg      f29, f5
	  lfs       f2, 0x104(r1)
	  lfs       f0, 0x11C(r1)
	  fmuls     f4, f1, f3
	  lwz       r3, 0x0(r3)
	  fmuls     f3, f5, f0
	  lfs       f5, 0x120(r1)
	  lfs       f0, 0x3C(r3)
	  fmuls     f5, f2, f5
	  fadds     f3, f4, f3
	  fcmpo     cr0, f31, f0
	  fneg      f28, f2
	  fadds     f31, f5, f3
	  ble-      .loc_0x27C
	  lfs       f0, -0x5CB0(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x264
	  bl        -0x13DD4
	  stfs      f1, 0x394(r30)
	  b         .loc_0x274

	.loc_0x264:
	  fmr       f1, f30
	  fmr       f2, f28
	  bl        -0x13DE8
	  stfs      f1, 0x394(r30)

	.loc_0x274:
	  li        r3, 0
	  b         .loc_0x3A4

	.loc_0x27C:
	  lfs       f0, -0x5CB0(r2)
	  fcmpo     cr0, f27, f0
	  ble-      .loc_0x28C
	  b         .loc_0x290

	.loc_0x28C:
	  fneg      f27, f27

	.loc_0x290:
	  lfd       f5, -0x5C38(r2)
	  lfd       f4, -0x5C30(r2)
	  fsqrte    f2, f5
	  lfd       f3, -0x5C28(r2)
	  lfs       f0, -0x5C20(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f1, f5, f1
	  frsp      f1, f1
	  stfs      f1, 0x7C(r1)
	  lfs       f1, 0x7C(r1)
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x308
	  li        r3, 0
	  b         .loc_0x3A4

	.loc_0x308:
	  addi      r3, r1, 0xE0
	  bl        -0x14E3C
	  lfs       f1, 0x124(r1)
	  addi      r3, r1, 0xD4
	  lfs       f0, 0xFC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE0(r1)
	  lfs       f1, 0x128(r1)
	  lfs       f0, 0x100(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE4(r1)
	  lfs       f1, 0x12C(r1)
	  lfs       f0, 0x104(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE8(r1)
	  bl        -0x14E74
	  lfs       f0, 0x124(r1)
	  fadds     f0, f0, f30
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0x128(r1)
	  fadds     f0, f0, f29
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0x12C(r1)
	  fadds     f0, f0, f28
	  stfs      f0, 0xDC(r1)
	  lfs       f0, -0x5CB0(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x390
	  lfs       f1, 0xE0(r1)
	  lfs       f2, 0xE8(r1)
	  bl        -0x13F00
	  stfs      f1, 0x394(r30)
	  b         .loc_0x3A0

	.loc_0x390:
	  lfs       f1, 0xD4(r1)
	  lfs       f2, 0xDC(r1)
	  bl        -0x13F14
	  stfs      f1, 0x394(r30)

	.loc_0x3A0:
	  li        r3, 0

	.loc_0x3A4:
	  lwz       r0, 0x16C(r1)
	  lfd       f31, 0x160(r1)
	  lfd       f30, 0x158(r1)
	  lfd       f29, 0x150(r1)
	  lfd       f28, 0x148(r1)
	  lfd       f27, 0x140(r1)
	  lwz       r31, 0x13C(r1)
	  lwz       r30, 0x138(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80131D54
 * Size:	000058
 */
TaiKinokoLegEffectAction::TaiKinokoLegEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 0, 0, 0, 0, 0) // TODO: fix
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
	  bl        -0x374C
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7814
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
 * Address:	80131DAC
 * Size:	0000B0
 */
void TaiKinokoLegEffectAction::setType(Vector3f&, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  addi      r3, r1, 0x18
	  bl        -0xEDF80
	  addi      r3, r1, 0x18
	  addi      r4, r31, 0
	  bl        -0xEDF24
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x0(r29)
	  lfs       f2, 0x8(r29)
	  bl        -0xC9EF8
	  cmpwi     r30, 0x5
	  stfs      f1, 0x4(r29)
	  bne-      .loc_0x6C
	  li        r0, 0xF
	  stw       r0, 0x14(r28)
	  b         .loc_0x88

	.loc_0x6C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x80
	  li        r0, -0x1
	  stw       r0, 0x14(r28)
	  b         .loc_0x88

	.loc_0x80:
	  li        r0, 0x44
	  stw       r0, 0x14(r28)

	.loc_0x88:
	  li        r0, 0x43
	  stw       r0, 0x18(r28)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80131E5C
 * Size:	000030
 */
void TaiNotAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	80131E8C
 * Size:	000030
 */
void TaiNotAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
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
 * Address:	80131EBC
 * Size:	00003C
 */
bool TaiNotAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
