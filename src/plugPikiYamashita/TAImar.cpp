#include "TAI/Mar.h"
#include "PikiMgr.h"

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
 * Address:	801A5774
 * Size:	000084
 */
TAImarSoundTable::TAImarSoundTable()
    : PaniSoundTable(6)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x6
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x86720
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x15E7A4
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x80
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
 * Address:	801A57F8
 * Size:	000440
 */
TAImarParameters::TAImarParameters()
    : TekiParameters(23, 57)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x39
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  subi      r31, r4, 0x1B20
	  li        r4, 0x17
	  stw       r30, 0xD0(r1)
	  addi      r30, r3, 0
	  bl        -0x59AD8
	  lis       r3, 0x802E
	  subi      r0, r3, 0xF98
	  stw       r0, 0x0(r30)
	  li        r0, 0x14
	  li        r8, 0x15
	  lwz       r5, 0x84(r30)
	  li        r7, 0x16
	  li        r6, 0x32
	  lwz       r10, 0x0(r5)
	  li        r3, 0x33
	  lwz       r9, 0x4(r5)
	  mulli     r4, r0, 0xC
	  lwz       r11, 0x8(r10)
	  lwz       r0, 0x8(r9)
	  add       r10, r11, r4
	  addi      r4, r31, 0xC
	  stw       r4, 0x0(r10)
	  li        r4, 0
	  mulli     r8, r8, 0xC
	  stw       r4, 0x4(r10)
	  li        r9, 0x64
	  stw       r9, 0x8(r10)
	  add       r10, r11, r8
	  addi      r8, r31, 0x28
	  stw       r8, 0x0(r10)
	  mulli     r7, r7, 0xC
	  stw       r4, 0x4(r10)
	  add       r11, r11, r7
	  stw       r9, 0x8(r10)
	  addi      r8, r31, 0x40
	  mulli     r7, r6, 0xC
	  stw       r8, 0x0(r11)
	  stw       r4, 0x4(r11)
	  mulli     r6, r3, 0xC
	  stw       r9, 0x8(r11)
	  add       r9, r0, r7
	  addi      r3, r31, 0x58
	  stw       r3, 0x0(r9)
	  li        r3, 0x34
	  mulli     r8, r3, 0xC
	  lfs       f8, -0x4B20(r2)
	  stfs      f8, 0x4(r9)
	  li        r3, 0x35
	  mulli     r7, r3, 0xC
	  lfs       f7, -0x4B1C(r2)
	  stfs      f7, 0x8(r9)
	  add       r9, r0, r6
	  addi      r3, r31, 0x6C
	  stw       r3, 0x0(r9)
	  li        r3, 0x36
	  mulli     r6, r3, 0xC
	  stfs      f8, 0x4(r9)
	  lfs       f0, -0x4B18(r2)
	  add       r10, r0, r8
	  addi      r8, r31, 0x84
	  stfs      f0, 0x8(r9)
	  li        r3, 0x37
	  mulli     r3, r3, 0xC
	  stw       r8, 0x0(r10)
	  stfs      f8, 0x4(r10)
	  add       r8, r0, r7
	  addi      r7, r31, 0x9C
	  stfs      f7, 0x8(r10)
	  add       r9, r0, r6
	  addi      r6, r31, 0xBC
	  stw       r7, 0x0(r8)
	  add       r7, r0, r3
	  addi      r3, r31, 0xD4
	  stfs      f8, 0x4(r8)
	  lfs       f6, -0x4B14(r2)
	  stfs      f6, 0x8(r8)
	  stw       r6, 0x0(r9)
	  stfs      f8, 0x4(r9)
	  stfs      f6, 0x8(r9)
	  stw       r3, 0x0(r7)
	  stfs      f8, 0x4(r7)
	  stfs      f6, 0x8(r7)
	  li        r3, 0x38
	  mulli     r3, r3, 0xC
	  add       r6, r0, r3
	  addi      r0, r31, 0xF0
	  stw       r0, 0x0(r6)
	  li        r3, 0x1E
	  li        r0, 0xA
	  stfs      f8, 0x4(r6)
	  li        r9, -0x1
	  li        r8, 0x5
	  lfs       f5, -0x4B10(r2)
	  li        r7, 0x14
	  stfs      f5, 0x8(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x50(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r0, 0x54(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r0, 0x58(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4B0C(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0xC8(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4B08(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0xCC(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f6, 0xD0(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4B04(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0xD4(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4B00(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0xD8(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AFC(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0xDC(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f4, -0x4AF8(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f4, 0xE0(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r9, 0xC(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r8, 0x24(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r0, 0x28(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r7, 0x2C(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x30(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x34(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x38(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x3C(r6)
	  lwz       r6, 0x0(r5)
	  lwz       r6, 0x0(r6)
	  stw       r3, 0x40(r6)
	  lwz       r3, 0x4(r5)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x8(r3)
	  lwz       r3, 0x4(r5)
	  lfs       f3, -0x4AF4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x4(r3)
	  lwz       r3, 0x4(r5)
	  lfs       f0, -0x4AF0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r5)
	  lfs       f2, -0x4AEC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0xC(r3)
	  lwz       r6, 0x4(r5)
	  mr        r3, r30
	  lwz       r6, 0x0(r6)
	  stfs      f5, 0x10(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AE8(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x14(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AE4(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x18(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AE0(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x1C(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4ADC(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x70(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f1, -0x4AD8(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f1, 0x20(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AD4(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x24(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f6, 0x28(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AD0(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x2C(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f8, 0x30(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f7, 0x3C(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4ACC(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x40(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f4, 0x44(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f2, 0x48(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AC8(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x78(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AC4(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x7C(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f3, 0x80(r6)
	  lwz       r6, 0x4(r5)
	  lfs       f0, -0x4AC0(r2)
	  lwz       r6, 0x0(r6)
	  stfs      f0, 0x84(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f5, 0x88(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f8, 0x8C(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f8, 0x90(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f1, 0x94(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f2, 0x98(r6)
	  lwz       r6, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  stfs      f2, 0x74(r6)
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x0(r5)
	  stw       r4, 0x8(r5)
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
 * Address:	801A5C38
 * Size:	000DE8
 */
TAImarStrategy::TAImarStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xF
	  stw       r0, 0x4(r1)
	  li        r5, 0x2
	  stwu      r1, -0x108(r1)
	  stmw      r14, 0xC0(r1)
	  addi      r31, r3, 0
	  bl        0x43A00
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1860
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x15EC64
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x60
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r20)

	.loc_0x60:
	  li        r3, 0x8
	  bl        -0x15EC98
	  stw       r3, 0xBC(r1)
	  lwz       r0, 0xBC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xA4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xBC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x1
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xCB4
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x4(r3)

	.loc_0xA4:
	  li        r3, 0xC
	  bl        -0x15ECDC
	  stw       r3, 0xB8(r1)
	  lwz       r3, 0xB8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  li        r4, -0x1
	  li        r5, 0
	  bl        0x6F58
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0xB8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x1060
	  lwz       r3, 0xB8(r1)
	  stw       r0, 0x4(r3)
	  lfs       f1, -0x4AF4(r2)
	  lfs       f0, -0x4B20(r2)
	  stfs      f1, 0x3190(r13)
	  stfs      f0, 0x3198(r13)
	  stfs      f1, 0x3194(r13)

	.loc_0xFC:
	  li        r3, 0xC
	  bl        -0x15ED34
	  stw       r3, 0xB4(r1)
	  lwz       r3, 0xB4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x154
	  li        r4, -0x1
	  li        r5, 0xC
	  bl        0x6F00
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0xB4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x1060
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0x4(r3)
	  lfs       f1, -0x4AF4(r2)
	  lfs       f0, -0x4B20(r2)
	  stfs      f1, 0x3190(r13)
	  stfs      f0, 0x3198(r13)
	  stfs      f1, 0x3194(r13)

	.loc_0x154:
	  li        r3, 0x8
	  bl        -0x15ED8C
	  stw       r3, 0xB0(r1)
	  lwz       r0, 0xB0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x198
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xB0(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0xB0(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6EC
	  lwz       r3, 0xB0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x198:
	  li        r3, 0xC
	  bl        -0x15EDD0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1D4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  subi      r3, r3, 0xE10
	  li        r0, 0x1
	  stw       r3, 0x4(r30)
	  stb       r0, 0x8(r30)

	.loc_0x1D4:
	  li        r3, 0xC
	  bl        -0x15EE0C
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x210
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0xA04
	  stw       r0, 0x4(r25)
	  lfs       f0, -0x4ABC(r2)
	  stfs      f0, 0x8(r25)

	.loc_0x210:
	  li        r3, 0x8
	  bl        -0x15EE48
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x250
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x9CC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r26)
	  subi      r0, r3, 0x10CC
	  stw       r0, 0x4(r26)

	.loc_0x250:
	  li        r3, 0xC
	  bl        -0x15EE88
	  stw       r3, 0xAC(r1)
	  lwz       r3, 0xAC(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x274
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        0x6E38

	.loc_0x274:
	  li        r3, 0x8
	  bl        -0x15EEAC
	  stw       r3, 0xA8(r1)
	  lwz       r0, 0xA8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xA8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x4
	  lwz       r3, 0xA8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x116C
	  lwz       r3, 0xA8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2B8:
	  li        r3, 0xC
	  bl        -0x15EEF0
	  stw       r3, 0xA4(r1)
	  lwz       r3, 0xA4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x2FC
	  li        r4, 0x3
	  li        r5, 0x1
	  bl        0x6D44
	  lis       r3, 0x802E
	  addi      r0, r3, 0x34C
	  lwz       r3, 0xA4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x11EC
	  lwz       r3, 0xA4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2FC:
	  li        r3, 0xC
	  bl        -0x15EF34
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x344
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x1E0
	  lis       r3, 0x802E
	  stw       r0, 0x4(r16)
	  li        r4, 0
	  subi      r0, r3, 0x1274
	  stw       r4, 0x8(r16)
	  stw       r0, 0x4(r16)

	.loc_0x344:
	  li        r3, 0xC
	  bl        -0x15EF7C
	  stw       r3, 0xA0(r1)
	  lwz       r3, 0xA0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x378
	  li        r4, 0x6
	  li        r5, 0xB
	  bl        0x6D44
	  lis       r3, 0x802E
	  subi      r0, r3, 0xB70
	  lwz       r3, 0xA0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x378:
	  li        r3, 0xC
	  bl        -0x15EFB0
	  stw       r3, 0x9C(r1)
	  lwz       r3, 0x9C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x3BC
	  li        r4, 0x7
	  li        r5, 0x7
	  bl        0x6D10
	  lis       r3, 0x802E
	  subi      r0, r3, 0xBB0
	  lwz       r3, 0x9C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x12C0
	  lwz       r3, 0x9C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x3BC:
	  li        r3, 0xC
	  bl        -0x15EFF4
	  stw       r3, 0x98(r1)
	  lwz       r3, 0x98(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x3E0
	  li        r4, -0x1
	  li        r5, 0x2
	  bl        0x6CCC

	.loc_0x3E0:
	  li        r3, 0xC
	  bl        -0x15F018
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x428
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0x8
	  lis       r3, 0x802E
	  stw       r0, 0x0(r17)
	  addi      r0, r3, 0x3CC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r17)
	  li        r4, 0x1
	  subi      r0, r3, 0x132C
	  stw       r4, 0x8(r17)
	  stw       r0, 0x4(r17)

	.loc_0x428:
	  li        r3, 0xC
	  bl        -0x15F060
	  stw       r3, 0x94(r1)
	  lwz       r3, 0x94(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x46C
	  li        r4, 0x9
	  li        r5, 0x9
	  bl        0x6BD4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x34C
	  lwz       r3, 0x94(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x11EC
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x4(r3)

	.loc_0x46C:
	  li        r3, 0xC
	  bl        -0x15F0A4
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x4B4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r15)
	  li        r0, 0x7
	  lis       r3, 0x802E
	  stw       r0, 0x0(r15)
	  subi      r0, r3, 0x1E0
	  lis       r3, 0x802E
	  stw       r0, 0x4(r15)
	  li        r0, 0
	  subi      r3, r3, 0x1390
	  stw       r0, 0x8(r15)
	  stw       r3, 0x4(r15)

	.loc_0x4B4:
	  li        r3, 0x8
	  bl        -0x15F0EC
	  stw       r3, 0x90(r1)
	  lwz       r0, 0x90(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x4F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x90(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xA
	  lwz       r3, 0x90(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x211C
	  lwz       r3, 0x90(r1)
	  stw       r0, 0x4(r3)

	.loc_0x4F8:
	  li        r3, 0xC
	  bl        -0x15F130
	  stw       r3, 0x8C(r1)
	  lwz       r3, 0x8C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x53C
	  li        r4, 0x3
	  li        r5, 0xA
	  bl        0x6B90
	  lis       r3, 0x802E
	  subi      r0, r3, 0xBF0
	  lwz       r3, 0x8C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x1430
	  lwz       r3, 0x8C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x53C:
	  li        r3, 0xC
	  bl        -0x15F174
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x584
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r18)
	  subi      r0, r3, 0x14BC
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0x8(r18)
	  stw       r0, 0x4(r18)

	.loc_0x584:
	  li        r3, 0x8
	  bl        -0x15F1BC
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x5B8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0xB
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0xEC
	  stw       r0, 0x4(r19)

	.loc_0x5B8:
	  li        r3, 0x8
	  bl        -0x15F1F0
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x5EC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0xB
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x124
	  stw       r0, 0x4(r21)

	.loc_0x5EC:
	  li        r3, 0x18
	  bl        -0x15F224
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x660
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0xC
	  lis       r3, 0x802E
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x1510
	  lis       r3, 0x802E
	  stw       r0, 0x14(r29)
	  subi      r3, r3, 0xB14
	  lis       r4, 0x802E
	  lfs       f0, -0x4AB8(r2)
	  subi      r4, r4, 0x1540
	  addi      r5, r3, 0x1C
	  stfs      f0, 0x8(r29)
	  addi      r0, r4, 0x1C
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x4AB4(r2)
	  stfs      f0, 0x10(r29)
	  stw       r3, 0x4(r29)
	  stw       r5, 0x14(r29)
	  stw       r4, 0x4(r29)
	  stw       r0, 0x14(r29)

	.loc_0x660:
	  li        r3, 0x4
	  bl        -0x15F298
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x68C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1F24
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x15B4
	  stw       r0, 0x0(r27)

	.loc_0x68C:
	  li        r3, 0x10
	  bl        -0x15F2C4
	  stw       r3, 0x88(r1)
	  lwz       r3, 0x88(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x6D8
	  li        r4, 0x3
	  li        r5, 0x8
	  bl        0x69FC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x410
	  lwz       r3, 0x88(r1)
	  stw       r0, 0x4(r3)
	  lis       r3, 0x802E
	  subi      r0, r3, 0x160C
	  lwz       r3, 0x88(r1)
	  stw       r27, 0xC(r3)
	  lwz       r3, 0x88(r1)
	  stw       r0, 0x4(r3)

	.loc_0x6D8:
	  li        r3, 0x8
	  bl        -0x15F310
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x70C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, 0xD
	  lis       r3, 0x802E
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x20A4
	  stw       r0, 0x4(r14)

	.loc_0x70C:
	  li        r3, 0x1C
	  bl        -0x15F344
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x784
	  li        r4, 0x3
	  li        r5, 0x6
	  bl        0x6980
	  lis       r3, 0x802E
	  subi      r0, r3, 0xA4C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r27)
	  subi      r0, r3, 0x1510
	  stw       r0, 0x18(r27)
	  lis       r3, 0x802E
	  subi      r3, r3, 0xA7C
	  lfs       f0, -0x4AB8(r2)
	  lis       r4, 0x802E
	  subi      r4, r4, 0x16D4
	  stfs      f0, 0xC(r27)
	  addi      r5, r3, 0x24
	  addi      r0, r4, 0x24
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x4AB0(r2)
	  stfs      f0, 0x14(r27)
	  stw       r3, 0x4(r27)
	  stw       r5, 0x18(r27)
	  stw       r4, 0x4(r27)
	  stw       r0, 0x18(r27)

	.loc_0x784:
	  li        r3, 0xC
	  bl        -0x15F3BC
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x7C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0xE
	  lis       r3, 0x802E
	  stw       r0, 0x0(r23)
	  addi      r3, r3, 0x3CC
	  li        r0, 0x1
	  stw       r3, 0x4(r23)
	  stw       r0, 0x8(r23)

	.loc_0x7C0:
	  li        r3, 0x8
	  bl        -0x15F3F8
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x7F4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, 0xB
	  lis       r3, 0x802E
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x17DC
	  stw       r0, 0x4(r22)

	.loc_0x7F4:
	  li        r3, 0x8
	  bl        -0x15F42C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x828
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x3
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x1814
	  stw       r0, 0x4(r28)

	.loc_0x828:
	  li        r3, 0xC
	  bl        -0x15F460
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x844
	  li        r4, 0x2
	  bl        -0x7F3E0

	.loc_0x844:
	  li        r0, 0
	  lwz       r4, 0x8(r24)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xB8(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xB0(r1)
	  lwz       r5, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x0(r4)
	  bl        -0x15F4AC
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x890
	  li        r4, 0x2
	  bl        -0x7F42C

	.loc_0x890:
	  li        r0, 0
	  lwz       r4, 0x8(r24)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xB4(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xB0(r1)
	  lwz       r5, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x4(r4)
	  bl        -0x15F4F8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x8DC
	  li        r4, 0x1
	  bl        -0x7F478

	.loc_0x8DC:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x8(r4)
	  bl        -0x15F52C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x910
	  li        r4, 0x9
	  bl        -0x7F4AC

	.loc_0x910:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xBC(r1)
	  li        r5, 0x3
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  li        r8, 0x4
	  stwx      r26, r3, r4
	  li        r6, 0x6
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r8,r8,2,0,29
	  stwx      r25, r3, r0
	  li        r7, 0x5
	  li        r0, 0x7
	  lwz       r3, 0x8(r28)
	  li        r4, 0x8
	  rlwinm    r6,r6,2,0,29
	  stwx      r16, r3, r5
	  rlwinm    r5,r7,2,0,29
	  rlwinm    r7,r0,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r21, r4, r5
	  lwz       r5, 0xAC(r1)
	  lwz       r4, 0x8(r28)
	  stwx      r19, r4, r6
	  lwz       r4, 0x8(r28)
	  stwx      r23, r4, r7
	  lwz       r4, 0x8(r28)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0xC(r4)
	  bl        -0x15F5E8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x9CC
	  li        r4, 0x1
	  bl        -0x7F568

	.loc_0x9CC:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x38(r4)
	  bl        -0x15F61C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xA00
	  li        r4, 0x4
	  bl        -0x7F59C

	.loc_0xA00:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xBC(r1)
	  li        r5, 0x2
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r0, 0x3
	  rlwinm    r5,r5,2,0,29
	  stwx      r30, r4, r3
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xA4(r1)
	  li        r3, 0xC
	  lwz       r6, 0x8(r28)
	  stwx      r0, r6, r5
	  lwz       r5, 0x8(r28)
	  stwx      r26, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x10(r4)
	  bl        -0x15F688
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xA6C
	  li        r4, 0x3
	  bl        -0x7F608

	.loc_0xA6C:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xBC(r1)
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  li        r0, 0x2
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r25)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xA0(r1)
	  stwx      r0, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r25)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x14(r4)
	  bl        -0x15F6E4
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0xAC8
	  li        r4, 0x1
	  bl        -0x7F664

	.loc_0xAC8:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x9C(r1)
	  stwx      r0, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x18(r4)
	  bl        -0x15F71C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xB00
	  li        r4, 0x5
	  bl        -0x7F69C

	.loc_0xB00:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r30, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r17, r4, r5
	  lwz       r5, 0x98(r1)
	  lwz       r4, 0x8(r28)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x1C(r4)
	  bl        -0x15F794
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xB78
	  li        r4, 0x3
	  bl        -0x7F714

	.loc_0xB78:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r5,r4,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x94(r1)
	  lwz       r4, 0x8(r25)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x20(r4)
	  bl        -0x15F7EC
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xBD0
	  li        r4, 0x2
	  bl        -0x7F76C

	.loc_0xBD0:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r15, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x90(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x24(r4)
	  bl        -0x15F834
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0xC18
	  li        r4, 0x1
	  bl        -0x7F7B4

	.loc_0xC18:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x8C(r1)
	  stwx      r0, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x28(r4)
	  bl        -0x15F86C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xC50
	  li        r4, 0x7
	  bl        -0x7F7EC

	.loc_0xC50:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r28)
	  li        r0, 0x2
	  rlwinm    r6,r0,2,0,29
	  stwx      r29, r3, r5
	  li        r4, 0x3
	  li        r0, 0x6
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x4
	  stwx      r26, r3, r6
	  rlwinm    r6,r5,2,0,29
	  li        r7, 0x5
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r7,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r6
	  lwz       r6, 0xA8(r1)
	  lwz       r4, 0x8(r28)
	  stwx      r6, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x2C(r4)
	  bl        -0x15F904
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xCE8
	  li        r4, 0x5
	  bl        -0x7F884

	.loc_0xCE8:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0xB0(r1)
	  stwx      r30, r3, r0
	  li        r4, 0x3
	  lwz       r3, 0x8(r28)
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  stwx      r5, r3, r6
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x88(r1)
	  li        r3, 0xC
	  lwz       r5, 0x8(r28)
	  stwx      r6, r5, r4
	  lwz       r4, 0x8(r28)
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x30(r4)
	  bl        -0x15F980
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xD64
	  li        r4, 0x6
	  bl        -0x7F900

	.loc_0xD64:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r28)
	  li        r6, 0x2
	  li        r0, 0x3
	  stwx      r26, r3, r4
	  rlwinm    r6,r6,2,0,29
	  li        r4, 0x4
	  lwz       r3, 0x8(r28)
	  li        r5, 0x5
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r6
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r4,r5,2,0,29
	  lwz       r5, 0x8(r28)
	  mr        r3, r31
	  stwx      r16, r5, r0
	  lwz       r0, 0xA8(r1)
	  lwz       r5, 0x8(r28)
	  stwx      r30, r5, r6
	  lwz       r5, 0x8(r28)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x34(r4)
	  lmw       r14, 0xC0(r1)
	  lwz       r0, 0x10C(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A6A20
 * Size:	0001CC
 */
void TAImarStrategy::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  mr        r30, r4
	  bl        0x42D10
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7469
	  bl        -0x11D338
	  mr.       r31, r3
	  beq-      .loc_0x1B4
	  addi      r3, r1, 0x10
	  addi      r4, r31, 0
	  bl        -0x11EB44
	  lwz       r3, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r3, 0x5C(r1)
	  lwz       r3, 0x18(r1)
	  stw       r0, 0x60(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r3, 0x64(r1)
	  lwz       r3, 0x20(r1)
	  stw       r0, 0x68(r1)
	  lwz       r0, 0x24(r1)
	  stw       r3, 0x6C(r1)
	  lwz       r3, 0x28(r1)
	  stw       r0, 0x70(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x74(r1)
	  lwz       r3, 0x30(r1)
	  stw       r0, 0x78(r1)
	  lwz       r0, 0x34(r1)
	  stw       r3, 0x7C(r1)
	  lwz       r3, 0x38(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r3, 0x84(r1)
	  lwz       r3, 0x40(r1)
	  stw       r0, 0x88(r1)
	  lwz       r0, 0x44(r1)
	  stw       r3, 0x8C(r1)
	  lwz       r3, 0x48(r1)
	  stw       r0, 0x90(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r3, 0x94(r1)
	  lfs       f0, -0x4B20(r2)
	  stw       r0, 0x98(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x5C(r1)
	  lfs       f0, 0x6C(r1)
	  stfs      f1, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x58(r1)
	  lwz       r4, 0x498(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x13C
	  lwz       r0, 0x80(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x10C
	  li        r0, 0
	  stw       r0, 0x498(r30)
	  b         .loc_0x13C

	.loc_0x10C:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x8(r31)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0xA8(r4)

	.loc_0x13C:
	  lwz       r4, 0x49C(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x178
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x8(r31)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0xA8(r4)

	.loc_0x178:
	  lwz       r4, 0x4A0(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x1B4
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x8(r31)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0xA8(r4)

	.loc_0x1B4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A6BEC
 * Size:	0000C4
 */
bool TAImarStrategy::interact(Teki&, TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  b         .loc_0xA8

	.loc_0x28:
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9B4(r13)
	  lwz       r4, 0x4(r5)
	  and.      r0, r3, r0
	  bne-      .loc_0x6C
	  lfs       f1, 0x33C(r30)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x33C(r30)
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9A4(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x6C
	  lfs       f1, 0x340(r30)
	  lfs       f0, -0x4AF4(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r30)

	.loc_0x6C:
	  lwz       r3, 0x41C(r30)
	  lwz       r31, 0x4(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  beq-      .loc_0x8C
	  bl        -0xC2900
	  li        r0, 0
	  stw       r0, 0x41C(r30)

	.loc_0x8C:
	  stw       r31, 0x41C(r30)
	  lwz       r3, 0x41C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  bl        -0xC292C

	.loc_0xA0:
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
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
 * Address:	801A6CB0
 * Size:	00032C
 */
void TAImarAnimation::makeDefaultAnimations()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  mr        r30, r3
	  lwz       r0, 0x4(r3)
	  lis       r3, 0x802E
	  subi      r31, r3, 0x1B20
	  cmplwi    r0, 0
	  beq-      .loc_0x314
	  lwz       r6, 0x3160(r13)
	  mr        r3, r30
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r31, 0x100
	  lwz       r6, 0x118(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x3764
	  addi      r3, r30, 0
	  addi      r4, r31, 0x11C
	  bl        -0x3770
	  addi      r3, r30, 0
	  addi      r4, r31, 0x138
	  bl        -0x377C
	  li        r3, 0x10
	  bl        -0x15FD14
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x8C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x8C:
	  lwz       r4, 0x8(r30)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x15FD5C
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
	  lwz       r5, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0x154
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x381C
	  li        r3, 0x10
	  bl        -0x15FDB4
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x12C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x12C:
	  lwz       r4, 0x8(r30)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x15FDFC
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
	  lwz       r5, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0x170
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x38BC
	  addi      r3, r30, 0
	  addi      r4, r31, 0x190
	  bl        -0x38C8
	  addi      r3, r30, 0
	  addi      r4, r31, 0x1B0
	  bl        -0x38D4
	  li        r3, 0x10
	  bl        -0x15FE6C
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x1E4
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x1E4:
	  lwz       r4, 0x8(r30)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x15FEB4
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x230
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x230:
	  lwz       r5, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0x1CC
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x3974
	  li        r3, 0x10
	  bl        -0x15FF0C
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x284
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x284:
	  lwz       r4, 0x8(r30)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x15FF54
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x2D0
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x2D0:
	  lwz       r5, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0x1E8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x3A14
	  addi      r3, r30, 0
	  addi      r4, r31, 0x204
	  bl        -0x3A20
	  addi      r3, r30, 0
	  addi      r4, r31, 0x220
	  bl        -0x3A2C

	.loc_0x314:
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
 * Address:	801A6FDC
 * Size:	00000C
 */
void TAIAinitMar::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4AAC(r2)
	  stfs      f0, 0x270(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A6FE8
 * Size:	000008
 */
bool TAIAinitMar::act(Teki&)
{
	return true;
}

/*
 * --INFO--
 * Address:	801A6FF0
 * Size:	000070
 */
void TAIAwatchNavi::start(Teki&)
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
	  bl        -0x8FC48
	  lwz       r0, 0x418(r30)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  beq-      .loc_0x44
	  mr        r3, r0
	  bl        -0xC2CBC
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x44:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  bl        -0xC2CE8

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
 * Address:	801A7060
 * Size:	000008
 */
bool TAIAwatchNavi::act(Teki&)
{
	return true;
}

/*
 * --INFO--
 * Address:	801A7068
 * Size:	000018
 */
f32 TAIAflyingDistanceInTerritoryMar::getVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7080
 * Size:	000018
 */
f32 TAIAflyingDistanceInTerritoryMar::getOffset(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7098
 * Size:	00004C
 */
void TAIAfireBreathMar::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x7A1C
	  mr        r3, r31
	  bl        -0x466C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x38
	  addi      r3, r3, 0x70
	  bl        -0x1236CC

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A70E4
 * Size:	000020
 */
bool TAIAfireBreathMar::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x7A58
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7104
 * Size:	000008
 */
f32 TAIAfireBreathMar::getPreviousAnimSpeed(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4AEC(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A710C
 * Size:	000018
 */
f32 TAIAfireBreathMar::getAttackAnimSpeed(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7124
 * Size:	000274
 */
bool BreathEffect::invoke(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stfd      f28, 0xE0(r1)
	  stfd      f27, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r4
	  stw       r30, 0xD0(r1)
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x244
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x7469
	  bl        -0x11DA58
	  mr        r30, r3
	  lfs       f1, -0x4AA8(r2)
	  bl        0x749E0
	  lfs       f0, 0xA0(r31)
	  fmr       f30, f1
	  fmr       f1, f0
	  bl        0x749D0
	  fmr       f29, f1
	  lfs       f1, -0x4AA8(r2)
	  bl        0x74B58
	  lfs       f0, 0xA0(r31)
	  fmr       f28, f1
	  fmr       f1, f0
	  bl        0x74B48
	  lfs       f4, -0x4AA4(r2)
	  fmuls     f0, f30, f1
	  lfs       f2, -0x4AA0(r2)
	  fmuls     f3, f30, f29
	  fneg      f1, f4
	  stfs      f0, 0xC0(r1)
	  lfs       f0, -0x4AE0(r2)
	  fmuls     f1, f2, f1
	  stfs      f28, 0xC4(r1)
	  stfs      f3, 0xC8(r1)
	  fdivs     f27, f1, f0
	  fmr       f1, f27
	  bl        0x74980
	  lfs       f0, 0xA0(r31)
	  fmr       f28, f1
	  fmr       f1, f0
	  bl        0x74970
	  fmr       f29, f1
	  fmr       f1, f27
	  bl        0x74AF8
	  lfs       f0, 0xA0(r31)
	  fmr       f30, f1
	  fmr       f1, f0
	  bl        0x74AE8
	  fmr       f31, f1
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x82
	  bl        -0x11CC60
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xC
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x84D54
	  lwz       r3, 0x2C4(r31)
	  fmr       f27, f1
	  li        r4, 0x33
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x84D6C
	  lfs       f0, -0x4AA0(r2)
	  fmuls     f2, f28, f29
	  lfs       f3, -0x4AE0(r2)
	  addi      r6, r1, 0x60
	  fmuls     f4, f0, f1
	  fmuls     f0, f28, f31
	  lfs       f5, 0x1370(r13)
	  addi      r5, r1, 0x5C
	  fdivs     f28, f4, f3
	  addi      r4, r1, 0x58
	  addi      r3, r1, 0x84
	  fmuls     f1, f2, f5
	  fmuls     f0, f0, f5
	  stfs      f1, 0x60(r1)
	  fmuls     f1, f30, f5
	  stfs      f0, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  bl        -0x17016C
	  lfs       f0, 0x84(r1)
	  fmr       f2, f28
	  lfs       f1, 0x88(r1)
	  fmr       f4, f27
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x8C(r1)
	  stfs      f1, 0x70(r1)
	  addi      r7, r1, 0x6C
	  lfs       f1, -0x4AF4(r2)
	  mr        r5, r31
	  stfs      f0, 0x74(r1)
	  lfs       f3, -0x4B1C(r2)
	  addi      r3, r31, 0x51C
	  addi      r4, r31, 0x4CC
	  addi      r6, r30, 0x4
	  addi      r8, r13, 0x319C
	  bl        0x1DDCC
	  lwz       r3, 0x3180(r13)
	  addi      r6, r31, 0x51C
	  addi      r5, r30, 0x4
	  li        r4, 0xB0
	  li        r7, 0
	  bl        -0xA7AC
	  cmplwi    r3, 0
	  stw       r3, 0x498(r31)
	  beq-      .loc_0x230
	  lwz       r4, 0x4(r30)
	  lwz       r0, 0x8(r30)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0xC0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0xA8(r3)
	  lfs       f0, 0x1374(r13)
	  lfs       f1, 0x1378(r13)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x137C(r13)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x80(r1)
	  lwz       r4, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x230:
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x2A590

	.loc_0x244:
	  lwz       r0, 0x104(r1)
	  li        r3, 0x1
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  lfd       f27, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7398
 * Size:	000238
 */
bool TAIAflyingDistanceMar::act(Teki& teki)
{
	bool baseActResult = TAIAflyingDistance::act(teki);

	// if base flyingDistance act succeeds, check for puffy-specific act.
	if (baseActResult) {
		// the more pikis we find in range, the more likely this act succeeds (hyperbolic, for whatever reason, so min is 1)
		int weight = 1;
		int stackFixerUpperVariable[2];

		// loop through all pikis on field.
		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Creature* piki = *iter;

			// if piki is within DangerTerritoryRange, increase chance of success by a small amount
			f32 distance = piki->getPosition().distance(teki.getPosition());
			if (distance < teki.mTekiParams->getF(TPF_DangerTerritoryRange)) {
				weight++;
			}
		}

		// higher weight = smaller rand range = higher chance of success
		// work out the chance of this by taking the integral and finding the area under the distribution curve
		// P(XY <= 1) bounded by XY = 1 => Y = 1/X. take into account max X = A, max Y = 30, where A = 100 / weight
		// P(XY <= 1) = (ln(A) + ln(30) + 1) / (30 * A)
		// so, for:
		// - weight = 1 (no pikis in range), A = 100, chance of success is 0.3%
		// - weight = 51 (50 pikis in range), A = 100/51, chance of success is 8.6%
		// - weight = 101 (100 pikis in range), A = 100/101, chance of success is 14.8%
		f32 successChance = System::getRand(100.0f / weight) * System::getRand(30.0f);
		if (successChance <= 1.0f) {
			return true;
		}

		return false;
	}

	// if we're here, this always returns false.
	return baseActResult;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stmw      r27, 0xB4(r1)
	  mr        r30, r4
	  bl        0x4E28
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x220
	  lwz       r28, 0x3068(r13)
	  li        r31, 0x1
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x4B20(r2)
	  addi      r27, r3, 0
	  addi      r29, r30, 0x94
	  b         .loc_0x130

	.loc_0x50:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x74
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x8C

	.loc_0x74:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
	  stfs      f31, 0x80(r1)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x78(r1)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x0(r29)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r29)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x4(r29)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x68(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f3, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  lfs       f2, 0x80(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x199848
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x114
	  addi      r31, r31, 0x1

	.loc_0x114:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x130:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x158
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x158:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x180
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x180:
	  li        r0, 0

	.loc_0x184:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x50
	  bl        0x70B4C
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4A98(r2)
	  stw       r0, 0xAC(r1)
	  lis       r30, 0x4330
	  lfs       f1, -0x4A9C(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f0, -0x4B14(r2)
	  lfd       f2, 0xA8(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f31, f0, f1
	  bl        0x70B1C
	  xoris     r3, r3, 0x8000
	  lfd       f5, -0x4A98(r2)
	  xoris     r0, r31, 0x8000
	  stw       r3, 0xA4(r1)
	  lfs       f3, -0x4A9C(r2)
	  stw       r0, 0x9C(r1)
	  lfs       f2, -0x4B10(r2)
	  stw       r30, 0xA0(r1)
	  lfs       f0, -0x4AF4(r2)
	  stw       r30, 0x98(r1)
	  lfd       f4, 0xA0(r1)
	  lfd       f1, 0x98(r1)
	  fsubs     f4, f4, f5
	  fsubs     f1, f1, f5
	  fdivs     f3, f4, f3
	  fdivs     f1, f2, f1
	  fmuls     f1, f1, f3
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x21C
	  li        r3, 0x1
	  b         .loc_0x220

	.loc_0x21C:
	  li        r3, 0

	.loc_0x220:
	  lmw       r27, 0xB4(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A75D0
 * Size:	000008
 */
f32 TAIAflyingDistanceMar::getGoalAreaRange(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4AF8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A75D8
 * Size:	000018
 */
f32 TAIAflyingDistanceMar::getOffset(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A75F0
 * Size:	000008
 */
f32 FlyingDistance::getOffset(Teki&)
{
	return mOffset;
}

/*
 * --INFO--
 * Address:	801A75F8
 * Size:	000018
 */
f32 TAIAtimerTakeOffMar::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7610
 * Size:	00000C
 */
void TAIAtimerReaction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0x478(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A761C
 * Size:	00005C
 */
bool TAIAtimerReaction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x478(r4)
	  lfs       f0, 0x28C(r5)
	  fadds     f31, f1, f0
	  stfs      f31, 0x478(r4)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x44
	  li        r3, 0x1
	  b         .loc_0x48

	.loc_0x44:
	  li        r3, 0

	.loc_0x48:
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7678
 * Size:	000008
 */
f32 TAIAtimerReaction::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7680
 * Size:	0000CC
 */
void TAIAtakeOffMar::startFlying(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  addi      r31, r30, 0x94
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lfs       f1, 0x94(r4)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x9C(r30)
	  bl        -0x13F4DC
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  bl        -0x91640
	  cmpwi     r3, 0x5
	  bne-      .loc_0xA4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        -0xABA8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        -0xABC0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        -0xABD8
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x14
	  bl        -0x11D16C

	.loc_0xA4:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x5514
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
 * Address:	801A774C
 * Size:	000018
 */
int TAIAstickingPikiMar::getPikiNum(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x58(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7764
 * Size:	000004
 */
void TAIAstickingPiki::start(Teki&)
{
}

/*
 * --INFO--
 * Address:	801A7768
 * Size:	000018
 */
int TAIAflickCheckMar::getDamageCountLimit(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x50(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7780
 * Size:	000134
 */
void TAIAlandingMar::landingEffect(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  addi      r31, r30, 0x94
	  lfs       f1, 0x94(r4)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x9C(r30)
	  bl        -0x13F5D4
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  bl        -0x91738
	  cmpwi     r3, 0x5
	  bne-      .loc_0xA0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        -0xACA0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        -0xACB8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        -0xACD0
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x14
	  bl        -0x11D264
	  b         .loc_0xF4

	.loc_0xA0:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xE0
	  li        r6, 0
	  li        r7, 0
	  bl        -0xACFC
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x83
	  bl        -0x11D290
	  b         .loc_0xF4

	.loc_0xCC:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xE0
	  li        r6, 0
	  li        r7, 0
	  bl        -0xAD28
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x83
	  bl        -0x11D2BC

	.loc_0xF4:
	  addi      r31, r30, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3
	  bl        -0x838AC
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x2AAC4
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
 * Address:	801A78B4
 * Size:	000018
 */
int TAIAstickingPikiMarFly::getPikiNum(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x54(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A78CC
 * Size:	00003C
 */
void TAIAflickingMar::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x7478
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x3
	  bl        -0x11D33C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7908
 * Size:	000094
 */
void TAIAflickingMar::flick(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x80
	  lwz       r12, 0x4(r3)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C4(r31)
	  lis       r5, 0x802B
	  lis       r3, 0x802B
	  lwz       r6, 0x84(r4)
	  subi      r0, r3, 0x3168
	  subi      r5, r5, 0x3064
	  lwz       r6, 0x4(r6)
	  addi      r4, r1, 0x70
	  addi      r3, r31, 0
	  lwz       r6, 0x0(r6)
	  lfs       f0, 0x8C(r6)
	  lfs       f2, 0x84(r6)
	  stw       r5, 0x70(r1)
	  stw       r31, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f1, 0x80(r1)
	  bl        -0x5FB30

	.loc_0x80:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A799C
 * Size:	000008
 */
f32 TAIAflicking::getFlickDirection(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4A90(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A79A4
 * Size:	00000C
 */
void TAIAflickCheckTimerMar::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0x478(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A79B0
 * Size:	0000F0
 */
bool TAIAflickCheckTimerMar::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  li        r31, 0
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  addi      r4, r1, 0x50
	  stw       r0, 0x50(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x50(r1)
	  subi      r0, r3, 0x2A4C
	  addi      r3, r30, 0
	  stw       r0, 0x50(r1)
	  stw       r30, 0x54(r1)
	  bl        -0x5F59C
	  cmpwi     r3, 0
	  ble-      .loc_0x6C
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0x1
	  rlwimi    r0,r3,2,29,29
	  stb       r0, 0x4C8(r30)
	  b         .loc_0x84

	.loc_0x6C:
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0
	  rlwimi    r0,r3,2,29,29
	  stb       r0, 0x4C8(r30)
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0x478(r30)

	.loc_0x84:
	  lbz       r0, 0x4C8(r30)
	  rlwinm.   r0,r0,30,31,31
	  beq-      .loc_0xD4
	  lwz       r4, 0x2C4(r30)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x84(r4)
	  lfs       f1, 0x478(r30)
	  lwz       r4, 0x4(r4)
	  lfs       f0, 0x28C(r3)
	  lwz       r3, 0x0(r4)
	  fadds     f0, f1, f0
	  lfs       f1, 0xD4(r3)
	  fcmpo     cr0, f0, f1
	  stfs      f0, 0x478(r30)
	  ble-      .loc_0xD4
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0
	  rlwimi    r0,r3,2,29,29
	  stb       r0, 0x4C8(r30)
	  li        r31, 0x1

	.loc_0xD4:
	  mr        r3, r31
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
 * Address:	801A7AA0
 * Size:	000018
 */
f32 TAIAflyingBaseMar::getFlyingStayVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xE0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7AB8
 * Size:	000048
 */
void TAIAdyingMar::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0xA60
	  li        r0, 0
	  stw       r0, 0x49C(r31)
	  li        r4, 0x38
	  stw       r0, 0x4A0(r31)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0x124098
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7B00
 * Size:	0002D0
 */
bool TAIAdyingMar::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stmw      r27, 0xBC(r1)
	  mr        r27, r4
	  lwz       r0, 0x3A8(r4)
	  lwz       r31, 0x49C(r4)
	  cmpwi     r0, 0x2
	  lwz       r30, 0x4A0(r4)
	  bne-      .loc_0x60
	  cmplwi    r31, 0
	  beq-      .loc_0x3C
	  lwz       r0, 0x80(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r31)

	.loc_0x3C:
	  li        r0, 0
	  cmplwi    r30, 0
	  stw       r0, 0x49C(r27)
	  beq-      .loc_0x58
	  lwz       r0, 0x80(r30)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r30)

	.loc_0x58:
	  li        r0, 0
	  stw       r0, 0x4A0(r27)

	.loc_0x60:
	  mr        r4, r27
	  bl        0xAC0
	  rlwinm.   r0,r3,0,24,31
	  addi      r29, r3, 0
	  bne-      .loc_0x2B8
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r27)
	  addi      r4, r4, 0x7469
	  bl        -0x11E470
	  addi      r28, r3, 0
	  addi      r4, r28, 0
	  addi      r3, r1, 0x20
	  bl        -0x11FC78
	  lwz       r3, 0x20(r1)
	  cmplwi    r31, 0
	  lwz       r0, 0x24(r1)
	  stw       r3, 0x6C(r1)
	  lwz       r3, 0x28(r1)
	  stw       r0, 0x70(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x74(r1)
	  lwz       r3, 0x30(r1)
	  stw       r0, 0x78(r1)
	  lwz       r0, 0x34(r1)
	  stw       r3, 0x7C(r1)
	  lwz       r3, 0x38(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r3, 0x84(r1)
	  lwz       r3, 0x40(r1)
	  stw       r0, 0x88(r1)
	  lwz       r0, 0x44(r1)
	  stw       r3, 0x8C(r1)
	  lwz       r3, 0x48(r1)
	  stw       r0, 0x90(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r3, 0x94(r1)
	  lwz       r3, 0x50(r1)
	  stw       r0, 0x98(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0x9C(r1)
	  lwz       r3, 0x58(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0xA4(r1)
	  lfs       f0, -0x4B20(r2)
	  stw       r0, 0xA8(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x6C(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x68(r1)
	  beq-      .loc_0x1E0
	  cmplwi    r30, 0
	  beq-      .loc_0x1E0
	  lwz       r4, 0x60(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x64(r1)
	  stw       r4, 0xA0(r31)
	  stw       r3, 0xA4(r31)
	  lwz       r3, 0x68(r1)
	  stw       r3, 0xA8(r31)
	  lwz       r4, 0x60(r1)
	  lwz       r3, 0x64(r1)
	  stw       r4, 0xA0(r30)
	  stw       r3, 0xA4(r30)
	  lwz       r3, 0x68(r1)
	  stw       r3, 0xA8(r30)
	  lwz       r4, 0x2CC(r27)
	  lfd       f2, -0x4A98(r2)
	  lwz       r3, 0x28(r4)
	  lfs       f5, 0x3198(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x2C(r4)
	  lwz       r3, 0x30(r3)
	  fsubs     f3, f0, f5
	  lfs       f4, -0x4AF4(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f0, 0x3190(r13)
	  stw       r3, 0xB4(r1)
	  stw       r0, 0xB0(r1)
	  lfd       f1, 0xB0(r1)
	  fsubs     f1, f1, f2
	  fsubs     f1, f1, f5
	  fdivs     f1, f3, f1
	  fsubs     f1, f4, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF0(r31)
	  lfs       f0, 0x3194(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF0(r30)
	  b         .loc_0x2B8

	.loc_0x1E0:
	  lwz       r0, 0x3A8(r27)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x2B8
	  cmplwi    r28, 0
	  beq-      .loc_0x2B8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r28, 0x4
	  li        r4, 0xB3
	  li        r6, 0
	  li        r7, 0
	  bl        -0xB1D0
	  cmplwi    r3, 0
	  stw       r3, 0x49C(r27)
	  beq-      .loc_0x25C
	  lwz       r4, 0x4(r28)
	  lwz       r0, 0x8(r28)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0xC(r28)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0x60(r1)
	  lwz       r0, 0x64(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x68(r1)
	  stw       r0, 0xA8(r3)
	  lfs       f0, 0xF0(r3)
	  stfs      f0, 0x3190(r13)
	  lwz       r3, 0x2CC(r27)
	  lfs       f0, 0x2C(r3)
	  stfs      f0, 0x3198(r13)

	.loc_0x25C:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r28, 0x4
	  li        r4, 0xB4
	  li        r6, 0
	  li        r7, 0
	  bl        -0xB238
	  cmplwi    r3, 0
	  stw       r3, 0x4A0(r27)
	  beq-      .loc_0x2B8
	  lwz       r4, 0x4(r28)
	  lwz       r0, 0x8(r28)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0xC(r28)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0x60(r1)
	  lwz       r0, 0x64(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x68(r1)
	  stw       r0, 0xA8(r3)
	  lfs       f0, 0xF0(r3)
	  stfs      f0, 0x3194(r13)

	.loc_0x2B8:
	  mr        r3, r29
	  lmw       r27, 0xBC(r1)
	  lwz       r0, 0xD4(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7DD0
 * Size:	000010
 */
void __sinit_TAImar_cpp(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x802E
	  subi      r0, r3, 0xF1C
	  stw       r0, 0x319C(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7DE0
 * Size:	000208
 */
bool TAIeffectAttackEventCallBackMar::hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stmw      r26, 0x70(r1)
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  addi      r31, r7, 0
	  bl        0x70268
	  xoris     r0, r3, 0x8000
	  lwz       r27, 0x3120(r13)
	  stw       r0, 0x6C(r1)
	  lis       r0, 0x4330
	  addi      r3, r27, 0
	  lfd       f1, -0x4A98(r2)
	  stw       r0, 0x68(r1)
	  lwz       r12, 0x0(r27)
	  lfd       f0, 0x68(r1)
	  lwz       r12, 0xC(r12)
	  fsubs     f3, f0, f1
	  lfs       f2, -0x4A9C(r2)
	  lfs       f1, -0x4A8C(r2)
	  mtlr      r12
	  lfs       f0, -0x4A88(r2)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fadds     f30, f0, f1
	  blrl
	  lfs       f31, -0x4B20(r2)
	  mr        r26, r3
	  b         .loc_0xEC

	.loc_0x84:
	  cmpwi     r26, -0x1
	  bne-      .loc_0xA8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC0

	.loc_0xA8:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  cmplw     r30, r3
	  bne-      .loc_0xD0
	  lfs       f30, -0x4B1C(r2)
	  stfs      f31, 0x4(r31)

	.loc_0xD0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0xEC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x114
	  li        r0, 0x1
	  b         .loc_0x140

	.loc_0x114:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x13C
	  li        r0, 0x1
	  b         .loc_0x140

	.loc_0x13C:
	  li        r0, 0

	.loc_0x140:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x84
	  lfs       f0, 0x0(r31)
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  fmuls     f0, f0, f30
	  subi      r5, r4, 0x3064
	  subi      r0, r3, 0x3120
	  addi      r3, r30, 0
	  stfs      f0, 0x0(r31)
	  addi      r4, r1, 0x3C
	  lfs       f0, 0x4(r31)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x8(r31)
	  lfs       f1, 0x0(r31)
	  lfs       f2, 0x4(r31)
	  lfs       f3, 0x8(r31)
	  lwz       r6, 0x38(r29)
	  lfs       f0, -0x4B20(r2)
	  stw       r5, 0x3C(r1)
	  stw       r6, 0x40(r1)
	  stw       r0, 0x3C(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f2, 0x4C(r1)
	  stfs      f3, 0x50(r1)
	  stw       r28, 0x54(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x80(r28)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x1E8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1E8:
	  lmw       r26, 0x70(r1)
	  li        r3, 0
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A7FE8
 * Size:	000040
 */
void TAIeffectAttackEventCallBackMar::playEventSound(zen::particleGenerator*, TAIeffectAttackParam*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x38(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  lwz       r0, 0x80(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x30
	  addi      r4, r3, 0
	  li        r5, 0x82
	  bl        -0x11DA28

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8028
 * Size:	000458
 */
bool TAIeffectAttackEventCallBackMar::hitMap(TAIeffectAttackParam*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x138(r1)
	  stfd      f31, 0x130(r1)
	  stfd      f30, 0x128(r1)
	  stfd      f29, 0x120(r1)
	  stfd      f28, 0x118(r1)
	  stfd      f27, 0x110(r1)
	  stw       r31, 0x10C(r1)
	  mr        r31, r4
	  stw       r30, 0x108(r1)
	  li        r30, 0
	  lwz       r0, 0x3C(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x428
	  lwz       r0, 0x40(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x428
	  lfs       f0, -0x4B20(r2)
	  li        r7, 0
	  addi      r5, r1, 0xD4
	  stfs      f0, 0xDC(r1)
	  li        r4, 0
	  stfs      f0, 0xD8(r1)
	  stfs      f0, 0xD4(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE0(r1)
	  stb       r7, 0xF4(r1)
	  lwz       r3, 0x10(r31)
	  lwz       r0, 0x14(r31)
	  stw       r3, 0xD4(r1)
	  stw       r0, 0xD8(r1)
	  lwz       r0, 0x18(r31)
	  stw       r0, 0xDC(r1)
	  lwz       r3, 0x1C(r31)
	  lwz       r0, 0x20(r31)
	  stw       r3, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  lwz       r0, 0x24(r31)
	  stw       r0, 0xE8(r1)
	  lfs       f1, -0x4A84(r2)
	  lfs       f0, -0x4AF4(r2)
	  stfs      f1, 0xEC(r1)
	  lwz       r6, 0x2DEC(r13)
	  stw       r7, 0xF8(r1)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0xF0(r1)
	  lfs       f1, 0x28C(r6)
	  bl        -0x13F298
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0xE0(r1)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0xF8
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0xE4(r1)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0xF8
	  lfs       f1, 0x24(r31)
	  lfs       f0, 0xE8(r1)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x428

	.loc_0xF8:
	  lfs       f0, -0x4B20(r2)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x20(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x24(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19A510
	  lfs       f0, -0x4B20(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x15C
	  lfs       f0, 0x1C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x20(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20(r31)
	  lfs       f0, 0x24(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x24(r31)

	.loc_0x15C:
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xE8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19A564
	  lfs       f0, -0x4B20(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1B0
	  lfs       f0, 0xE0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE4(r1)
	  lfs       f0, 0xE8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE8(r1)

	.loc_0x1B0:
	  lfs       f3, 0x1C(r31)
	  lfs       f1, 0xE0(r1)
	  lfs       f2, 0x20(r31)
	  lfs       f0, 0xE4(r1)
	  fadds     f3, f3, f1
	  lfs       f1, 0x24(r31)
	  fadds     f2, f2, f0
	  lfs       f0, 0xE8(r1)
	  fneg      f30, f3
	  fadds     f0, f1, f0
	  fneg      f2, f2
	  fmuls     f1, f30, f30
	  fneg      f31, f0
	  fmuls     f0, f2, f2
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19A5DC
	  lfs       f0, -0x4B20(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x20C
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1

	.loc_0x20C:
	  lfs       f0, 0xD4(r1)
	  addi      r5, r1, 0xBC
	  lfs       f1, -0x4A84(r2)
	  li        r4, 0xB1
	  stfs      f0, 0xBC(r1)
	  li        r6, 0
	  lfs       f0, 0xD8(r1)
	  li        r7, 0
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xDC(r1)
	  stfs      f0, 0xC4(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0xB730
	  stw       r3, 0x3C(r31)
	  lwz       r0, 0x3C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x328
	  lfs       f2, -0x4B14(r2)
	  lfs       f1, 0xBC(r1)
	  fmuls     f0, f2, f30
	  lfs       f3, 0xC4(r1)
	  fmuls     f2, f2, f31
	  fadds     f0, f1, f0
	  fadds     f1, f3, f2
	  stfs      f0, 0xBC(r1)
	  stfs      f1, 0xC4(r1)
	  lwz       r30, 0x3C(r31)
	  lfs       f29, 0xBC(r1)
	  lfs       f28, 0xC0(r1)
	  mr        r3, r30
	  lfs       f27, 0xC4(r1)
	  bl        -0x93644
	  lfs       f0, 0x8(r3)
	  addi      r6, r1, 0x34
	  addi      r5, r1, 0x30
	  fsubs     f0, f27, f0
	  addi      r4, r1, 0x2C
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f28, f0
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x64
	  fsubs     f0, f29, f0
	  stfs      f0, 0x2C(r1)
	  bl        -0x1711D0
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x170(r30)
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x174(r30)
	  lfs       f0, 0x6C(r1)
	  stfs      f0, 0x178(r30)
	  lfs       f0, -0x4A80(r2)
	  stfs      f0, 0x17C(r30)
	  lwz       r0, 0x84(r30)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r30)
	  lfs       f0, 0x1358(r13)
	  lfs       f1, 0x135C(r13)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x1360(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lwz       r4, 0x3C(r31)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x1E4(r4)

	.loc_0x328:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0xBC
	  li        r4, 0xB2
	  li        r6, 0
	  li        r7, 0
	  bl        -0xB82C
	  stw       r3, 0x40(r31)
	  lwz       r0, 0x40(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x424
	  lfs       f2, -0x4ACC(r2)
	  lfs       f1, 0xBC(r1)
	  fmuls     f0, f2, f30
	  lfs       f3, 0xC4(r1)
	  fmuls     f2, f2, f31
	  fadds     f0, f1, f0
	  fadds     f1, f3, f2
	  stfs      f0, 0xBC(r1)
	  stfs      f1, 0xC4(r1)
	  lwz       r30, 0x40(r31)
	  lfs       f27, 0xBC(r1)
	  lfs       f28, 0xC0(r1)
	  mr        r3, r30
	  lfs       f29, 0xC4(r1)
	  bl        -0x93740
	  lfs       f0, 0x8(r3)
	  addi      r6, r1, 0x28
	  addi      r5, r1, 0x24
	  fsubs     f0, f29, f0
	  addi      r4, r1, 0x20
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f28, f0
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x54
	  fsubs     f0, f27, f0
	  stfs      f0, 0x20(r1)
	  bl        -0x1712CC
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x170(r30)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x174(r30)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x178(r30)
	  lfs       f0, -0x4A7C(r2)
	  stfs      f0, 0x17C(r30)
	  lwz       r0, 0x84(r30)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r30)
	  lfs       f0, 0x1364(r13)
	  lfs       f1, 0x1368(r13)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x136C(r13)
	  stfs      f1, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lwz       r4, 0x40(r31)
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x1E4(r4)

	.loc_0x424:
	  li        r30, 0x1

	.loc_0x428:
	  mr        r3, r30
	  lwz       r0, 0x13C(r1)
	  lfd       f31, 0x130(r1)
	  lfd       f30, 0x128(r1)
	  lfd       f29, 0x120(r1)
	  lfd       f28, 0x118(r1)
	  lfd       f27, 0x110(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  addi      r1, r1, 0x138
	  mtlr      r0
	  blr
	*/
}
