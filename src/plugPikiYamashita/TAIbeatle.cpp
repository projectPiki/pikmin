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
 * Address:	801C59D4
 * Size:	000084
 */
TAIbeatleSoundTable::TAIbeatleSoundTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x7
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xA6980
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x17EA04
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x5B
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
 * Address:	801C5A58
 * Size:	000418
 */
TAIbeatleParameters::TAIbeatleParameters()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x37
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  addi      r31, r4, 0x1850
	  li        r4, 0x14
	  stw       r30, 0xF8(r1)
	  addi      r30, r3, 0
	  bl        -0x79D38
	  lis       r3, 0x802E
	  addi      r0, r3, 0x1FC4
	  stw       r0, 0x0(r30)
	  li        r7, 0x32
	  li        r6, 0x33
	  lwz       r4, 0x84(r30)
	  li        r5, 0x34
	  li        r3, 0x35
	  lwz       r8, 0x4(r4)
	  li        r0, 0x36
	  mulli     r7, r7, 0xC
	  lwz       r12, 0x8(r8)
	  add       r8, r12, r7
	  addi      r7, r31, 0x1C
	  stw       r7, 0x0(r8)
	  mulli     r6, r6, 0xC
	  lfs       f10, -0x4620(r2)
	  mulli     r5, r5, 0xC
	  stfs      f10, 0x4(r8)
	  lfs       f9, -0x461C(r2)
	  mulli     r3, r3, 0xC
	  stfs      f9, 0x8(r8)
	  add       r7, r12, r6
	  addi      r6, r31, 0x28
	  stw       r6, 0x0(r7)
	  mulli     r0, r0, 0xC
	  stfs      f10, 0x4(r7)
	  add       r10, r12, r5
	  lfs       f1, -0x4618(r2)
	  addi      r5, r31, 0x40
	  add       r11, r12, r3
	  stfs      f1, 0x8(r7)
	  addi      r9, r31, 0x54
	  add       r12, r12, r0
	  stw       r5, 0x0(r10)
	  addi      r3, r31, 0x64
	  li        r8, 0x2
	  stfs      f10, 0x4(r10)
	  li        r7, 0x5
	  li        r6, 0xA
	  stfs      f9, 0x8(r10)
	  li        r0, 0x14
	  li        r5, 0x1E
	  stw       r9, 0x0(r11)
	  stfs      f10, 0x4(r11)
	  lfs       f0, -0x4614(r2)
	  stfs      f0, 0x8(r11)
	  stw       r3, 0x0(r12)
	  stfs      f10, 0x4(r12)
	  lfs       f8, -0x4610(r2)
	  stfs      f8, 0x8(r12)
	  lwz       r3, 0x4(r4)
	  lfs       f7, -0x460C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f6, -0x4608(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f5, -0x4604(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x4600(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xD4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45FC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x28(r3)
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
	  li        r0, 0
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x40(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f8, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x45F8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x45F4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45F0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45EC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x45E8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45E4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f9, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45E0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f7, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45DC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f10, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f8, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45D8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45D4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f10, 0x64(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45D0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x45CC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r5, 0x4(r4)
	  li        r6, 0x1
	  addi      r3, r30, 0
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f10, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f10, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x45C8(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x74(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x45C4(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x45C0(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x5C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x60(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x9C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xA0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f10, 0xA4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f10, 0xA8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x54(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x8(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r6, 0x44(r5)
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0x0(r4)
	  stw       r6, 0x0(r4)
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C5E70
 * Size:	000EF4
 */
TAIbeatleStrategy::TAIbeatleStrategy()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xE
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x110(r1)
	  stmw      r14, 0xC8(r1)
	  addi      r31, r3, 0
	  bl        0x237C8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x1950
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x17EE9C
	  stw       r3, 0xC4(r1)
	  lwz       r0, 0xC4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xC4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0xC4(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x1EFC
	  lwz       r3, 0xC4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x70:
	  li        r3, 0x8
	  bl        -0x17EEE0
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xA4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r27)

	.loc_0xA4:
	  li        r3, 0xC
	  bl        -0x17EF14
	  stw       r3, 0xC0(r1)
	  lwz       r3, 0xC0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x192E0
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0xC0(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x1EC4
	  lwz       r3, 0xC0(r1)
	  stw       r0, 0x4(r3)

	.loc_0xE8:
	  li        r3, 0x8
	  bl        -0x17EF58
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x11C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x6EC
	  stw       r0, 0x4(r22)

	.loc_0x11C:
	  li        r3, 0xC
	  bl        -0x17EF8C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x164
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0xE10
	  lis       r3, 0x802E
	  stw       r0, 0x4(r30)
	  li        r4, 0x1
	  addi      r0, r3, 0x1E58
	  stb       r4, 0x8(r30)
	  stw       r0, 0x4(r30)

	.loc_0x164:
	  li        r3, 0xC
	  bl        -0x17EFD4
	  cmplwi    r3, 0
	  beq-      .loc_0x180
	  li        r4, -0x1
	  li        r5, 0x2
	  bl        -0x1930C

	.loc_0x180:
	  li        r3, 0xC
	  bl        -0x17EFF0
	  stw       r3, 0xBC(r1)
	  lwz       r0, 0xBC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1D0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xBC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x149C
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0xBC(r1)
	  lfs       f0, -0x45BC(r2)
	  stfs      f0, 0x8(r3)

	.loc_0x1D0:
	  li        r3, 0xC
	  bl        -0x17F040
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x1FC
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x1937C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x720
	  stw       r0, 0x4(r23)

	.loc_0x1FC:
	  li        r3, 0x14
	  bl        -0x17F06C
	  stw       r3, 0xB8(r1)
	  lwz       r3, 0xB8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x248
	  li        r4, -0x1
	  li        r5, 0x2
	  bl        -0x193AC
	  lis       r3, 0x802E
	  subi      r0, r3, 0x68C
	  lwz       r3, 0xB8(r1)
	  li        r4, 0xA
	  stw       r0, 0x4(r3)
	  li        r0, 0xB
	  lwz       r3, 0xB8(r1)
	  stw       r4, 0xC(r3)
	  lwz       r3, 0xB8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x248:
	  li        r3, 0x8
	  bl        -0x17F0B8
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x27C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0xEC
	  stw       r0, 0x4(r17)

	.loc_0x27C:
	  li        r3, 0x8
	  bl        -0x17F0EC
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x2B0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  addi      r0, r3, 0x1DBC
	  stw       r0, 0x4(r19)

	.loc_0x2B0:
	  li        r3, 0x18
	  bl        -0x17F120
	  addi      r21, r3, 0
	  mr.       r3, r21
	  beq-      .loc_0x300
	  li        r4, 0x8
	  li        r5, 0xA
	  bl        -0x1945C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r21)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0xC(r21)
	  li        r0, 0xB
	  li        r4, 0x1
	  stw       r0, 0x10(r21)
	  subi      r0, r3, 0x780
	  stb       r4, 0x14(r21)
	  stw       r0, 0x4(r21)

	.loc_0x300:
	  li        r3, 0x8
	  bl        -0x17F170
	  stw       r3, 0xB4(r1)
	  lwz       r0, 0xB4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x344
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xB4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1A0
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x344:
	  li        r3, 0xC
	  bl        -0x17F1B4
	  stw       r3, 0xB0(r1)
	  lwz       r3, 0xB0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x378
	  li        r4, 0x8
	  li        r5, 0x6
	  bl        -0x194F4
	  lis       r3, 0x802E
	  subi      r0, r3, 0x638
	  lwz       r3, 0xB0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x378:
	  li        r3, 0x8
	  bl        -0x17F1E8
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x3C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x8
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  addi      r0, r3, 0xDC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r16)
	  addi      r0, r3, 0xB4
	  lis       r3, 0x802E
	  stw       r0, 0x4(r16)
	  addi      r0, r3, 0x1D70
	  stw       r0, 0x4(r16)

	.loc_0x3C4:
	  li        r3, 0x14
	  bl        -0x17F234
	  stw       r3, 0xAC(r1)
	  lwz       r3, 0xAC(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x410
	  li        r4, 0xD
	  li        r5, 0x8
	  bl        -0x19574
	  lis       r3, 0x802E
	  addi      r0, r3, 0x1CC8
	  lwz       r3, 0xAC(r1)
	  li        r4, 0xD
	  stw       r0, 0x4(r3)
	  li        r0, 0xB
	  lwz       r3, 0xAC(r1)
	  stw       r4, 0xC(r3)
	  lwz       r3, 0xAC(r1)
	  stw       r0, 0x10(r3)

	.loc_0x410:
	  li        r3, 0x8
	  bl        -0x17F280
	  stw       r3, 0xA8(r1)
	  lwz       r0, 0xA8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x454
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xA8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x9
	  lwz       r3, 0xA8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x20A4
	  lwz       r3, 0xA8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x454:
	  li        r3, 0x14
	  bl        -0x17F2C4
	  addi      r15, r3, 0
	  mr.       r3, r15
	  beq-      .loc_0x49C
	  li        r4, 0xA
	  li        r5, 0xA
	  bl        -0x19600
	  lis       r3, 0x802E
	  subi      r0, r3, 0x760
	  lis       r3, 0x802E
	  stw       r0, 0x4(r15)
	  subi      r0, r3, 0x8C8
	  stw       r0, 0x4(r15)
	  li        r3, 0xA
	  li        r0, 0xB
	  stw       r3, 0xC(r15)
	  stw       r0, 0x10(r15)

	.loc_0x49C:
	  li        r3, 0xC
	  bl        -0x17F30C
	  stw       r3, 0xA4(r1)
	  lwz       r3, 0xA4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x4D0
	  li        r4, 0x2
	  li        r5, 0x6
	  bl        -0x1964C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x938
	  lwz       r3, 0xA4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x4D0:
	  li        r3, 0x10
	  bl        -0x17F340
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x51C
	  li        r4, 0x2
	  li        r5, 0x9
	  bl        -0x1967C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x364
	  stw       r0, 0x4(r14)
	  lis       r4, 0x802E
	  lis       r3, 0x802E
	  lfs       f0, -0x4620(r2)
	  addi      r0, r4, 0x500
	  addi      r3, r3, 0x1C40
	  stfs      f0, 0xC(r14)
	  stw       r0, 0x4(r14)
	  stw       r3, 0x4(r14)

	.loc_0x51C:
	  li        r3, 0x8
	  bl        -0x17F38C
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x550
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  addi      r0, r3, 0x1B60
	  stw       r0, 0x4(r25)

	.loc_0x550:
	  li        r3, 0x8
	  bl        -0x17F3C0
	  stw       r3, 0xA0(r1)
	  lwz       r0, 0xA0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x594
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xA0(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0xA0(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x1B60
	  lwz       r3, 0xA0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x594:
	  li        r3, 0x10
	  bl        -0x17F404
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x5D8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, 0xC
	  lis       r3, 0x802E
	  stw       r0, 0x0(r18)
	  subi      r3, r3, 0x298
	  li        r0, 0
	  stw       r3, 0x4(r18)
	  lfs       f0, -0x45B8(r2)
	  stfs      f0, 0x8(r18)
	  stb       r0, 0xC(r18)

	.loc_0x5D8:
	  li        r3, 0xC
	  bl        -0x17F448
	  stw       r3, 0x9C(r1)
	  lwz       r3, 0x9C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x61C
	  li        r4, 0xD
	  li        r5, 0xC
	  bl        -0x19814
	  lis       r3, 0x802E
	  addi      r0, r3, 0x34C
	  lwz       r3, 0x9C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x1AE4
	  lwz       r3, 0x9C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x61C:
	  li        r3, 0xC
	  bl        -0x17F48C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x658
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x4
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x558
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x45EC(r2)
	  stfs      f0, 0x8(r28)

	.loc_0x658:
	  li        r3, 0x18
	  bl        -0x17F4C8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x69C
	  li        r4, 0x5
	  li        r5, 0xA
	  bl        -0x19804
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r24)
	  li        r0, 0xA
	  li        r3, 0xB
	  stw       r0, 0xC(r24)
	  li        r0, 0x1
	  stw       r3, 0x10(r24)
	  stb       r0, 0x14(r24)

	.loc_0x69C:
	  li        r3, 0xC
	  bl        -0x17F50C
	  stw       r3, 0x98(r1)
	  lwz       r3, 0x98(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x6D0
	  li        r4, 0x2
	  li        r5, 0x6
	  bl        -0x1984C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5A0
	  lwz       r3, 0x98(r1)
	  stw       r0, 0x4(r3)

	.loc_0x6D0:
	  li        r3, 0x8
	  bl        -0x17F540
	  stw       r3, 0x94(r1)
	  lwz       r0, 0x94(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x714
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x94(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x211C
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x4(r3)

	.loc_0x714:
	  li        r3, 0x8
	  bl        -0x17F584
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x748
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r20)
	  addi      r0, r3, 0x1A24
	  stw       r0, 0x4(r20)

	.loc_0x748:
	  li        r3, 0x24
	  bl        -0x17F5B8
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x7C0
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r5, 0x7268
	  lis       r4, 0x802E
	  stw       r0, 0x0(r29)
	  addi      r0, r4, 0x4BA8
	  lis       r4, 0x6C66
	  stw       r0, 0x4(r29)
	  addi      r0, r4, 0x6F74
	  lis       r4, 0x7266
	  stw       r0, 0x8(r1)
	  addi      r0, r4, 0x6F74
	  stw       r0, 0xC(r1)
	  lis       r4, 0x6C68
	  addi      r9, r4, 0x6E64
	  lfs       f1, -0x45B4(r2)
	  addi      r10, r5, 0x6E64
	  li        r4, 0x43
	  li        r5, 0x1
	  li        r6, 0x60
	  li        r7, 0xF
	  li        r8, 0x4
	  bl        0xF824

	.loc_0x7C0:
	  li        r3, 0x10
	  bl        -0x17F630
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x810
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x18
	  lis       r3, 0x802E
	  stw       r0, 0x4(r26)
	  li        r0, 0xA
	  addi      r3, r3, 0x19E0
	  stw       r0, 0x8(r26)
	  lfs       f0, -0x4620(r2)
	  stfs      f0, 0xC(r26)
	  stw       r3, 0x4(r26)

	.loc_0x810:
	  li        r3, 0xC
	  bl        -0x17F680
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x82C
	  li        r4, 0x1
	  bl        -0x9F600

	.loc_0x82C:
	  li        r0, 0
	  lwz       r4, 0x8(r23)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xC4(r1)
	  stwx      r0, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x4(r4)
	  bl        -0x17F6B8
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x864
	  li        r4, 0x2
	  bl        -0x9F638

	.loc_0x864:
	  li        r0, 0
	  lwz       r4, 0x8(r23)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xC0(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r23)
	  li        r3, 0xC
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x0(r4)
	  bl        -0x17F700
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x8AC
	  li        r4, 0x2
	  bl        -0x9F680

	.loc_0x8AC:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r23)
	  li        r3, 0xC
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0xC(r4)
	  bl        -0x17F744
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x8F0
	  li        r4, 0x9
	  bl        -0x9F6C4

	.loc_0x8F0:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r28)
	  rlwinm    r3,r3,2,0,29
	  li        r8, 0x3
	  stwx      r22, r4, r3
	  li        r7, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r27, r3, r0
	  li        r0, 0x7
	  li        r9, 0x8
	  lwz       r4, 0x8(r28)
	  rlwinm    r3,r8,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r30, r4, r3
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r8,r9,2,0,29
	  stwx      r24, r3, r7
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r17, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r19, r4, r6
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r26, r4, r8
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x10(r4)
	  bl        -0x17F7F8
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x9A4
	  li        r4, 0x9
	  bl        -0x9F778

	.loc_0x9A4:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  li        r6, 0x6
	  stwx      r22, r3, r4
	  li        r5, 0x7
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r28)
	  li        r9, 0x3
	  li        r4, 0x5
	  stwx      r27, r3, r0
	  rlwinm    r0,r9,2,0,29
	  li        r7, 0x4
	  lwz       r3, 0x8(r28)
	  rlwinm    r9,r7,2,0,29
	  li        r8, 0x8
	  stwx      r30, r3, r0
	  rlwinm    r0,r4,2,0,29
	  lwz       r4, 0x98(r1)
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r5,2,0,29
	  stwx      r4, r3, r9
	  rlwinm    r7,r8,2,0,29
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r17, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r19, r4, r6
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r26, r4, r7
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x14(r4)
	  bl        -0x17F8B0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xA5C
	  li        r4, 0xB
	  bl        -0x9F830

	.loc_0xA5C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  li        r9, 0x6
	  stwx      r25, r3, r4
	  li        r3, 0x4
	  li        r8, 0x8
	  lwz       r4, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r7, 0x9
	  stwx      r22, r4, r0
	  li        r6, 0x3
	  rlwinm    r0,r6,2,0,29
	  lwz       r5, 0x8(r28)
	  rlwinm    r3,r3,2,0,29
	  li        r4, 0x7
	  stwx      r27, r5, r0
	  li        r10, 0x5
	  li        r5, 0xA
	  lwz       r6, 0x8(r28)
	  rlwinm    r0,r10,2,0,29
	  rlwinm    r9,r9,2,0,29
	  stwx      r30, r6, r3
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r4,r5,2,0,29
	  lwz       r5, 0xB8(r1)
	  lwz       r3, 0x8(r28)
	  rlwinm    r8,r8,2,0,29
	  stwx      r5, r3, r0
	  rlwinm    r7,r7,2,0,29
	  lwz       r0, 0xBC(r1)
	  li        r3, 0xC
	  lwz       r5, 0x8(r28)
	  stwx      r17, r5, r9
	  lwz       r5, 0x8(r28)
	  stwx      r19, r5, r6
	  lwz       r5, 0x8(r28)
	  stwx      r0, r5, r8
	  lwz       r5, 0x8(r28)
	  stwx      r29, r5, r7
	  lwz       r5, 0x8(r28)
	  stwx      r26, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x8(r4)
	  bl        -0x17F98C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xB38
	  li        r4, 0x7
	  bl        -0x9F90C

	.loc_0xB38:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r0, 0x2
	  li        r7, 0x5
	  stwx      r30, r4, r5
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x3
	  lwz       r6, 0x8(r28)
	  li        r4, 0x4
	  li        r5, 0x6
	  stwx      r21, r6, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r4,r5,2,0,29
	  lwz       r3, 0x8(r28)
	  lwz       r5, 0xB4(r1)
	  rlwinm    r7,r7,2,0,29
	  stwx      r5, r3, r0
	  li        r3, 0xC
	  lwz       r5, 0x8(r28)
	  stwx      r18, r5, r6
	  lwz       r5, 0x8(r28)
	  stwx      r29, r5, r7
	  lwz       r5, 0x8(r28)
	  stwx      r26, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x18(r4)
	  bl        -0x17FA24
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xBD0
	  li        r4, 0x7
	  bl        -0x9F9A4

	.loc_0xBD0:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r0, 0x2
	  li        r7, 0x5
	  stwx      r30, r4, r5
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x3
	  lwz       r6, 0x8(r28)
	  li        r4, 0x4
	  li        r5, 0x6
	  stwx      r16, r6, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r4,r5,2,0,29
	  lwz       r3, 0x8(r28)
	  lwz       r5, 0xB0(r1)
	  rlwinm    r7,r7,2,0,29
	  stwx      r5, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0xA8(r1)
	  lwz       r5, 0x8(r28)
	  stwx      r0, r5, r6
	  lwz       r5, 0x8(r28)
	  stwx      r29, r5, r7
	  lwz       r5, 0x8(r28)
	  stwx      r26, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x1C(r4)
	  bl        -0x17FAC0
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xC6C
	  li        r4, 0x5
	  bl        -0x9FA40

	.loc_0xC6C:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r26)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r27, r3, r4
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x4
	  lwz       r3, 0x8(r26)
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r4,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0xAC(r1)
	  lwz       r4, 0x8(r26)
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r26)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x20(r4)
	  bl        -0x17FB38
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xCE4
	  li        r4, 0x5
	  bl        -0x9FAB8

	.loc_0xCE4:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r27, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r26)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r26)
	  stwx      r15, r4, r5
	  lwz       r4, 0x8(r26)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x24(r4)
	  bl        -0x17FBAC
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xD58
	  li        r4, 0x6
	  bl        -0x9FB2C

	.loc_0xD58:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r4, 0x8(r26)
	  li        r0, 0x3
	  li        r3, 0x2
	  stwx      r30, r4, r5
	  rlwinm    r7,r0,2,0,29
	  lwz       r0, 0xA4(r1)
	  rlwinm    r3,r3,2,0,29
	  lwz       r4, 0x8(r26)
	  li        r5, 0x4
	  stwx      r0, r4, r3
	  rlwinm    r0,r5,2,0,29
	  li        r6, 0x5
	  lwz       r4, 0x8(r26)
	  rlwinm    r5,r6,2,0,29
	  li        r3, 0xC
	  stwx      r17, r4, r7
	  lwz       r4, 0x8(r26)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r26)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x28(r4)
	  bl        -0x17FC34
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xDE0
	  li        r4, 0x5
	  bl        -0x9FBB4

	.loc_0xDE0:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xA0(r1)
	  li        r5, 0x2
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r26)
	  li        r0, 0x3
	  rlwinm    r5,r5,2,0,29
	  stwx      r27, r3, r4
	  li        r4, 0x4
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r26)
	  rlwinm    r4,r4,2,0,29
	  stwx      r30, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r26)
	  stwx      r14, r5, r0
	  lwz       r5, 0x8(r26)
	  stwx      r29, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x2C(r4)
	  bl        -0x17FCAC
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0xE58
	  li        r4, 0x2
	  bl        -0x9FC2C

	.loc_0xE58:
	  li        r0, 0
	  lwz       r4, 0x8(r24)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x9C(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r24)
	  li        r3, 0xC
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x30(r4)
	  bl        -0x17FCF4
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xEA0
	  li        r4, 0x3
	  bl        -0x9FC74

	.loc_0xEA0:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r17, r3, r0
	  mr        r3, r31
	  lwz       r0, 0x94(r1)
	  lwz       r5, 0x8(r25)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x34(r4)
	  lmw       r14, 0xC8(r1)
	  lwz       r0, 0x114(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C6D64
 * Size:	000140
 */
void TAIbeatleStrategy::interact(Teki&, TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xCC
	  bge-      .loc_0x124
	  cmpwi     r0, 0
	  bge-      .loc_0x34
	  b         .loc_0x124

	.loc_0x34:
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9B4(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x128

	.loc_0x4C:
	  lwz       r31, 0x4(r5)
	  mr        r3, r31
	  bl        -0x14AD78
	  stw       r3, 0x344(r30)
	  lwz       r0, 0x344(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xC4
	  lfs       f1, 0x33C(r30)
	  lfs       f0, 0x8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x33C(r30)
	  lfs       f1, 0x340(r30)
	  lfs       f0, -0x45F8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r30)
	  lwz       r3, 0x41C(r30)
	  lwz       r31, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  beq-      .loc_0xA8
	  bl        -0xE2A94
	  li        r0, 0
	  stw       r0, 0x41C(r30)

	.loc_0xA8:
	  stw       r31, 0x41C(r30)
	  lwz       r3, 0x41C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xBC
	  bl        -0xE2AC0

	.loc_0xBC:
	  li        r3, 0x1
	  b         .loc_0x128

	.loc_0xC4:
	  li        r3, 0
	  b         .loc_0x128

	.loc_0xCC:
	  lwz       r31, 0x4(r5)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x124
	  bl        -0xFE8F0
	  cmpwi     r3, 0xE
	  bne-      .loc_0x124
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x8
	  li        r4, 0x45
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2A32C
	  lwz       r3, 0x20(r31)
	  bl        -0x13F12C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x5F
	  bl        -0x13C8D0

	.loc_0x124:
	  li        r3, 0

	.loc_0x128:
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
 * Address:	801C6EA4
 * Size:	00041C
 */
void TAIbeatleStrategy::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x198(r1)
	  stfd      f31, 0x190(r1)
	  stfd      f30, 0x188(r1)
	  stfd      f29, 0x180(r1)
	  stfd      f28, 0x178(r1)
	  stfd      f27, 0x170(r1)
	  stfd      f26, 0x168(r1)
	  stfd      f25, 0x160(r1)
	  stfd      f24, 0x158(r1)
	  stfd      f23, 0x150(r1)
	  stw       r31, 0x14C(r1)
	  mr        r31, r4
	  stw       r30, 0x148(r1)
	  stw       r29, 0x144(r1)
	  bl        0x22864
	  lis       r4, 0x6D65
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x5F6C
	  bl        -0x13D7E4
	  mr.       r29, r3
	  beq-      .loc_0x210
	  addi      r3, r1, 0xFC
	  addi      r4, r29, 0
	  bl        -0x13EFF0
	  lfs       f24, 0x104(r1)
	  lfs       f25, 0x114(r1)
	  fmuls     f1, f24, f24
	  lfs       f26, 0x124(r1)
	  fmuls     f0, f25, f25
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B92EC
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xA4
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1

	.loc_0xA4:
	  lfs       f27, 0x100(r1)
	  lfs       f28, 0x110(r1)
	  fmuls     f1, f27, f27
	  lfs       f3, -0x45B0(r2)
	  fmuls     f0, f28, f28
	  lfs       f29, 0x120(r1)
	  fmuls     f24, f24, f3
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fmuls     f25, f25, f3
	  fmuls     f26, f26, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9338
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xF0
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0xF0:
	  lfs       f30, 0xFC(r1)
	  lfs       f31, 0x10C(r1)
	  fmuls     f1, f30, f30
	  lfs       f3, -0x45B0(r2)
	  fmuls     f0, f31, f31
	  lfs       f23, 0x11C(r1)
	  fmuls     f27, f27, f3
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fmuls     f28, f28, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9384
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x13C
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f23, f23, f1

	.loc_0x13C:
	  lfs       f0, -0x45BC(r2)
	  lwz       r30, 0x498(r31)
	  fmuls     f30, f30, f0
	  cmplwi    r30, 0
	  fmuls     f31, f31, f0
	  fmuls     f23, f23, f0
	  beq-      .loc_0x210
	  lwz       r0, 0x80(r30)
	  addi      r6, r1, 0x2C
	  addi      r5, r1, 0x28
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r30)
	  addi      r4, r1, 0x24
	  addi      r3, r1, 0xB4
	  lfs       f0, 0xC(r29)
	  fadds     f0, f0, f23
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f31
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f30
	  stfs      f0, 0x24(r1)
	  bl        -0x18FF20
	  lfs       f2, 0xBC(r1)
	  addi      r6, r1, 0x50
	  lfs       f1, 0xB8(r1)
	  addi      r5, r1, 0x4C
	  lfs       f0, 0xB4(r1)
	  fadds     f2, f2, f29
	  addi      r4, r1, 0x48
	  fadds     f1, f1, f28
	  addi      r3, r1, 0xC0
	  fadds     f0, f0, f27
	  stfs      f2, 0x50(r1)
	  stfs      f1, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  bl        -0x18FF58
	  lfs       f0, 0xC0(r1)
	  lfs       f1, 0xC4(r1)
	  fadds     f2, f0, f24
	  lfs       f0, 0xC8(r1)
	  fadds     f1, f1, f25
	  fadds     f0, f0, f26
	  stfs      f2, 0xCC(r1)
	  stfs      f1, 0xD0(r1)
	  stfs      f0, 0xD4(r1)
	  lwz       r3, 0xCC(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r3, 0xC(r30)
	  stw       r0, 0x10(r30)
	  lwz       r0, 0xD4(r1)
	  stw       r0, 0x14(r30)

	.loc_0x210:
	  lis       r4, 0x6D65
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x5F72
	  bl        -0x13D9B0
	  mr.       r29, r3
	  beq-      .loc_0x3DC
	  addi      r3, r1, 0xFC
	  addi      r4, r29, 0
	  bl        -0x13F1BC
	  lfs       f31, 0x104(r1)
	  lfs       f30, 0x114(r1)
	  fmuls     f1, f31, f31
	  lfs       f29, 0x124(r1)
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B94B8
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x270
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x270:
	  lfs       f28, 0x100(r1)
	  lfs       f27, 0x110(r1)
	  fmuls     f1, f28, f28
	  lfs       f3, -0x45AC(r2)
	  fmuls     f0, f27, f27
	  lfs       f26, 0x120(r1)
	  fmuls     f31, f31, f3
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fmuls     f30, f30, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9504
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2BC
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x2BC:
	  lfs       f25, 0xFC(r1)
	  lfs       f24, 0x10C(r1)
	  fmuls     f1, f25, f25
	  lfs       f3, -0x45B0(r2)
	  fmuls     f0, f24, f24
	  lfs       f23, 0x11C(r1)
	  fmuls     f28, f28, f3
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fmuls     f27, f27, f3
	  fmuls     f26, f26, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9550
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x308
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x308:
	  lfs       f0, -0x45BC(r2)
	  lwz       r30, 0x49C(r31)
	  fmuls     f25, f25, f0
	  cmplwi    r30, 0
	  fmuls     f24, f24, f0
	  fmuls     f23, f23, f0
	  beq-      .loc_0x3DC
	  lwz       r0, 0x80(r30)
	  addi      r6, r1, 0x20
	  addi      r5, r1, 0x1C
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r30)
	  addi      r4, r1, 0x18
	  addi      r3, r1, 0x90
	  lfs       f0, 0xC(r29)
	  fadds     f0, f0, f23
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f24
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f25
	  stfs      f0, 0x18(r1)
	  bl        -0x1900EC
	  lfs       f2, 0x98(r1)
	  addi      r6, r1, 0x38
	  lfs       f1, 0x94(r1)
	  addi      r5, r1, 0x34
	  lfs       f0, 0x90(r1)
	  fadds     f2, f2, f26
	  addi      r4, r1, 0x30
	  fadds     f1, f1, f27
	  addi      r3, r1, 0x9C
	  fadds     f0, f0, f28
	  stfs      f2, 0x38(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0x190124
	  lfs       f0, 0x9C(r1)
	  lfs       f1, 0xA0(r1)
	  fadds     f2, f0, f31
	  lfs       f0, 0xA4(r1)
	  fadds     f1, f1, f30
	  fadds     f0, f0, f29
	  stfs      f2, 0xA8(r1)
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lwz       r3, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r3, 0xC(r30)
	  stw       r0, 0x10(r30)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x14(r30)

	.loc_0x3DC:
	  lwz       r0, 0x19C(r1)
	  lfd       f31, 0x190(r1)
	  lfd       f30, 0x188(r1)
	  lfd       f29, 0x180(r1)
	  lfd       f28, 0x178(r1)
	  lfd       f27, 0x170(r1)
	  lfd       f26, 0x168(r1)
	  lfd       f25, 0x160(r1)
	  lfd       f24, 0x158(r1)
	  lfd       f23, 0x150(r1)
	  lwz       r31, 0x14C(r1)
	  lwz       r30, 0x148(r1)
	  lwz       r29, 0x144(r1)
	  addi      r1, r1, 0x198
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C72C0
 * Size:	000024
 */
void TAIbeatleAnimation::makeDefaultAnimations()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  beqlr-
	  lwz       r4, 0x3160(r13)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x11C(r4)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x1FC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C72E4
 * Size:	000018
 */
void TAIAcheckInsideRangePikiBeatle::getRange(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x28(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C72FC
 * Size:	000024
 */
void TAIAdisableStick::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x13CFF8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C7320
 * Size:	00011C
 */
void TAIAflickingBeatle::flick(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stw       r31, 0x104(r1)
	  stw       r30, 0x100(r1)
	  stw       r29, 0xFC(r1)
	  addi      r29, r3, 0
	  stw       r28, 0xF8(r1)
	  mr        r28, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xFC
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r28
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x2C4(r28)
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  lwz       r5, 0x84(r5)
	  subi      r30, r4, 0x3064
	  subi      r31, r3, 0x3168
	  lwz       r5, 0x4(r5)
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  lwz       r5, 0x0(r5)
	  addi      r29, r1, 0xE4
	  lfs       f0, 0x8C(r5)
	  lfs       f2, 0x84(r5)
	  stw       r30, 0xE4(r1)
	  stw       r28, 0xE8(r1)
	  stw       r31, 0xE4(r1)
	  stfs      f2, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f1, 0xF4(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C4(r28)
	  addi      r5, r1, 0xD0
	  addi      r3, r28, 0
	  lwz       r6, 0x84(r4)
	  mr        r4, r29
	  lwz       r6, 0x4(r6)
	  lwz       r6, 0x0(r6)
	  lfs       f0, 0x90(r6)
	  lfs       f2, 0x88(r6)
	  stw       r30, 0xD0(r1)
	  stw       r28, 0xD4(r1)
	  stw       r31, 0xD0(r1)
	  stfs      f2, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  stfs      f1, 0xE0(r1)
	  bl        -0x7F658
	  lwz       r3, 0x3180(r13)
	  addi      r5, r28, 0x94
	  li        r4, 0xE0
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2A8E0

	.loc_0xFC:
	  lwz       r0, 0x10C(r1)
	  lwz       r31, 0x104(r1)
	  lwz       r30, 0x100(r1)
	  lwz       r29, 0xFC(r1)
	  lwz       r28, 0xF8(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C743C
 * Size:	000034
 */
void TAIAinvincibleOff::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9B4(r13)
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
 * Address:	801C7470
 * Size:	000094
 */
void TAIAflickingAfterMotionLoopBeatle::start(Teki&)
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
	  bl        -0x18CA8
	  li        r0, 0
	  stw       r0, 0x4A0(r31)
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  stw       r0, 0x4A4(r31)
	  stw       r0, 0x4A8(r31)
	  stw       r0, 0x4AC(r31)
	  beq-      .loc_0x44
	  lwz       r5, 0x2C0(r31)

	.loc_0x44:
	  lwz       r4, 0x8(r30)
	  addi      r3, r1, 0x10
	  bl        -0xA8530
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0xA8308
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x62
	  bl        -0x13CF24
	  lbz       r0, 0x4C8(r31)
	  li        r3, 0
	  rlwimi    r0,r3,6,25,25
	  stb       r0, 0x4C8(r31)
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
 * Address:	801C7504
 * Size:	0008D4
 */
void TAIAflickingAfterMotionLoopBeatle::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2C8(r1)
	  stfd      f31, 0x2C0(r1)
	  stfd      f30, 0x2B8(r1)
	  stfd      f29, 0x2B0(r1)
	  stfd      f28, 0x2A8(r1)
	  stmw      r26, 0x290(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  lwz       r3, 0x220(r4)
	  lis       r4, 0x6B75
	  addi      r4, r4, 0x7469
	  bl        -0x13DE28
	  lwz       r0, 0x3A8(r31)
	  addi      r27, r3, 0
	  cmpwi     r0, 0x3
	  beq-      .loc_0x174
	  bge-      .loc_0x5C
	  cmpwi     r0, 0x1
	  beq-      .loc_0x200
	  bge-      .loc_0x6C
	  b         .loc_0x544

	.loc_0x5C:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x534
	  bge-      .loc_0x544
	  b         .loc_0x23C

	.loc_0x6C:
	  mr        r3, r31
	  bl        -0x13D2A8
	  cmplwi    r27, 0
	  beq-      .loc_0x544
	  addi      r3, r1, 0x1E0
	  addi      r4, r27, 0
	  bl        -0x13F670
	  lwz       r3, 0x1E0(r1)
	  addi      r5, r27, 0x4
	  lwz       r0, 0x1E4(r1)
	  li        r4, 0x88
	  stw       r3, 0x22C(r1)
	  lwz       r3, 0x1E8(r1)
	  li        r6, 0
	  stw       r0, 0x230(r1)
	  li        r7, 0
	  lwz       r0, 0x1EC(r1)
	  stw       r3, 0x234(r1)
	  lwz       r3, 0x1F0(r1)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x1F4(r1)
	  stw       r3, 0x23C(r1)
	  lwz       r3, 0x1F8(r1)
	  stw       r0, 0x240(r1)
	  lwz       r0, 0x1FC(r1)
	  stw       r3, 0x244(r1)
	  lwz       r3, 0x200(r1)
	  stw       r0, 0x248(r1)
	  lwz       r0, 0x204(r1)
	  stw       r3, 0x24C(r1)
	  lwz       r3, 0x208(r1)
	  stw       r0, 0x250(r1)
	  lwz       r0, 0x20C(r1)
	  stw       r3, 0x254(r1)
	  lwz       r3, 0x210(r1)
	  stw       r0, 0x258(r1)
	  lwz       r0, 0x214(r1)
	  stw       r3, 0x25C(r1)
	  lwz       r3, 0x218(r1)
	  stw       r0, 0x260(r1)
	  lwz       r0, 0x21C(r1)
	  stw       r3, 0x264(r1)
	  lfs       f0, -0x4620(r2)
	  stw       r0, 0x268(r1)
	  stfs      f0, 0x228(r1)
	  stfs      f0, 0x224(r1)
	  stfs      f0, 0x220(r1)
	  lfs       f1, 0x22C(r1)
	  lfs       f0, 0x23C(r1)
	  stfs      f1, 0x220(r1)
	  stfs      f0, 0x224(r1)
	  lfs       f0, 0x24C(r1)
	  stfs      f0, 0x228(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x2AB10
	  cmplwi    r3, 0
	  beq-      .loc_0x544
	  addi      r0, r27, 0x4
	  stw       r0, 0x18(r3)
	  lwz       r4, 0x220(r1)
	  lwz       r0, 0x224(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x228(r1)
	  stw       r0, 0xA8(r3)
	  b         .loc_0x544

	.loc_0x174:
	  mr        r3, r31
	  bl        -0x13D368
	  lwz       r3, 0x4A0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x194
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x194:
	  lwz       r3, 0x4A4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1AC
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1AC:
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C4
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1C4:
	  lwz       r3, 0x4AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1DC:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x61
	  bl        -0x13D100
	  lbz       r0, 0x4C8(r31)
	  li        r3, 0
	  rlwimi    r0,r3,6,25,25
	  stb       r0, 0x4C8(r31)
	  b         .loc_0x544

	.loc_0x200:
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x544
	  beq-      .loc_0x220
	  beq-      .loc_0x220
	  bl        -0xE33AC
	  li        r0, 0
	  stw       r0, 0x420(r31)

	.loc_0x220:
	  li        r0, 0
	  stw       r0, 0x420(r31)
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x544
	  bl        -0xE33DC
	  b         .loc_0x544

	.loc_0x23C:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x61
	  bl        -0x13D198
	  li        r29, 0
	  stw       r29, 0x13C(r1)
	  li        r3, 0x1
	  li        r0, 0x2
	  stw       r3, 0x140(r1)
	  li        r4, 0x3
	  li        r3, 0x4
	  lfd       f29, -0x4588(r2)
	  stw       r0, 0x144(r1)
	  li        r0, 0x5
	  lfs       f30, -0x4594(r2)
	  stw       r4, 0x148(r1)
	  addi      r27, r1, 0x13C
	  lfs       f31, -0x4598(r2)
	  lis       r26, 0x4330
	  stw       r3, 0x14C(r1)
	  stw       r0, 0x150(r1)

	.loc_0x290:
	  bl        0x508DC
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x28C(r1)
	  stw       r26, 0x288(r1)
	  lfd       f0, 0x288(r1)
	  fsubs     f0, f0, f29
	  fdivs     f0, f0, f30
	  fmuls     f28, f31, f0
	  bl        0x508BC
	  xoris     r0, r3, 0x8000
	  fctiwz    f0, f28
	  stw       r0, 0x284(r1)
	  addi      r29, r29, 0x1
	  addi      r4, r1, 0x13C
	  stw       r26, 0x280(r1)
	  addi      r5, r1, 0x13C
	  lfd       f1, 0x280(r1)
	  cmpwi     r29, 0xA
	  stfd      f0, 0x278(r1)
	  fsubs     f0, f1, f29
	  lwz       r0, 0x27C(r1)
	  fdivs     f0, f0, f30
	  rlwinm    r0,r0,2,0,29
	  add       r4, r4, r0
	  lwz       r3, 0x0(r4)
	  fmuls     f0, f31, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x270(r1)
	  lwz       r0, 0x274(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r5, r5, r0
	  lwz       r0, 0x0(r5)
	  stw       r0, 0x0(r4)
	  stw       r3, 0x0(r5)
	  blt+      .loc_0x290
	  li        r29, 0
	  lis       r26, 0x7374

	.loc_0x324:
	  lwz       r0, 0x0(r27)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x398
	  bge-      .loc_0x34C
	  cmpwi     r0, 0x1
	  beq-      .loc_0x370
	  bge-      .loc_0x384
	  cmpwi     r0, 0
	  bge-      .loc_0x35C
	  b         .loc_0x3D0

	.loc_0x34C:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x3C0
	  bge-      .loc_0x3D0
	  b         .loc_0x3AC

	.loc_0x35C:
	  lwz       r3, 0x220(r31)
	  addi      r4, r26, 0x6D30
	  bl        -0x13E158
	  mr        r28, r3
	  b         .loc_0x3D0

	.loc_0x370:
	  lwz       r3, 0x220(r31)
	  addi      r4, r26, 0x6D31
	  bl        -0x13E16C
	  mr        r28, r3
	  b         .loc_0x3D0

	.loc_0x384:
	  lwz       r3, 0x220(r31)
	  addi      r4, r26, 0x6D32
	  bl        -0x13E180
	  mr        r28, r3
	  b         .loc_0x3D0

	.loc_0x398:
	  lwz       r3, 0x220(r31)
	  addi      r4, r26, 0x6D33
	  bl        -0x13E194
	  mr        r28, r3
	  b         .loc_0x3D0

	.loc_0x3AC:
	  lwz       r3, 0x220(r31)
	  addi      r4, r26, 0x6D34
	  bl        -0x13E1A8
	  mr        r28, r3
	  b         .loc_0x3D0

	.loc_0x3C0:
	  lwz       r3, 0x220(r31)
	  addi      r4, r26, 0x6D35
	  bl        -0x13E1BC
	  mr        r28, r3

	.loc_0x3D0:
	  cmplwi    r28, 0
	  beq-      .loc_0x410
	  lwz       r3, 0x3180(r13)
	  addi      r5, r28, 0x4
	  li        r4, 0x8B
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2ADB8
	  cmplwi    r3, 0
	  beq-      .loc_0x400
	  addi      r0, r28, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x400:
	  addi      r0, r29, 0x3
	  rlwinm    r4,r0,2,0,29
	  addi      r0, r4, 0x498
	  stwx      r3, r31, r0

	.loc_0x410:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r27, r27, 0x4
	  blt+      .loc_0x324
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x7469
	  bl        -0x13E220
	  mr.       r28, r3
	  beq-      .loc_0x544
	  addi      r3, r1, 0x1A0
	  addi      r4, r28, 0
	  bl        -0x13FA2C
	  lwz       r3, 0x1A0(r1)
	  addi      r5, r28, 0x4
	  lwz       r0, 0x1A4(r1)
	  li        r4, 0x8C
	  stw       r3, 0x154(r1)
	  lwz       r3, 0x1A8(r1)
	  li        r6, 0
	  stw       r0, 0x158(r1)
	  li        r7, 0
	  lwz       r0, 0x1AC(r1)
	  stw       r3, 0x15C(r1)
	  lwz       r3, 0x1B0(r1)
	  stw       r0, 0x160(r1)
	  lwz       r0, 0x1B4(r1)
	  stw       r3, 0x164(r1)
	  lwz       r3, 0x1B8(r1)
	  stw       r0, 0x168(r1)
	  lwz       r0, 0x1BC(r1)
	  stw       r3, 0x16C(r1)
	  lwz       r3, 0x1C0(r1)
	  stw       r0, 0x170(r1)
	  lwz       r0, 0x1C4(r1)
	  stw       r3, 0x174(r1)
	  lwz       r3, 0x1C8(r1)
	  stw       r0, 0x178(r1)
	  lwz       r0, 0x1CC(r1)
	  stw       r3, 0x17C(r1)
	  lwz       r3, 0x1D0(r1)
	  stw       r0, 0x180(r1)
	  lwz       r0, 0x1D4(r1)
	  stw       r3, 0x184(r1)
	  lwz       r3, 0x1D8(r1)
	  stw       r0, 0x188(r1)
	  lwz       r0, 0x1DC(r1)
	  stw       r3, 0x18C(r1)
	  lfs       f0, -0x4620(r2)
	  stw       r0, 0x190(r1)
	  stfs      f0, 0x19C(r1)
	  stfs      f0, 0x198(r1)
	  stfs      f0, 0x194(r1)
	  lfs       f1, 0x154(r1)
	  lfs       f0, 0x164(r1)
	  stfs      f1, 0x194(r1)
	  stfs      f0, 0x198(r1)
	  lfs       f0, 0x174(r1)
	  stfs      f0, 0x19C(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x2AECC
	  cmplwi    r3, 0
	  beq-      .loc_0x52C
	  addi      r0, r28, 0x4
	  stw       r0, 0x18(r3)
	  lwz       r4, 0x194(r1)
	  lwz       r0, 0x198(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x19C(r1)
	  stw       r0, 0xA8(r3)

	.loc_0x52C:
	  stw       r3, 0x4A0(r31)
	  b         .loc_0x544

	.loc_0x534:
	  lbz       r0, 0x4C8(r31)
	  li        r3, 0x1
	  rlwimi    r0,r3,6,25,25
	  stb       r0, 0x4C8(r31)

	.loc_0x544:
	  lbz       r0, 0x4C8(r31)
	  rlwinm.   r0,r0,26,31,31
	  beq-      .loc_0x8A4
	  lwz       r3, 0x3120(r13)
	  bl        -0xB0694
	  lfs       f0, -0x4620(r2)
	  addi      r7, r3, 0x94
	  addi      r6, r1, 0xC4
	  stfs      f0, 0xFC(r1)
	  addi      r5, r1, 0xC0
	  addi      r4, r1, 0xBC
	  stfs      f0, 0xF8(r1)
	  addi      r26, r31, 0x94
	  stfs      f0, 0xF4(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r3, r1, 0x104
	  lfs       f1, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC4(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  bl        -0x190998
	  lfs       f1, 0x104(r1)
	  lfs       f0, 0x108(r1)
	  stfs      f1, 0xF4(r1)
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0x10C(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f1, 0xF4(r1)
	  lfs       f0, 0xF8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xFC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B9EB0
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x10
	  lwz       r3, 0x84(r3)
	  bl        -0xA48F4
	  fdivs     f1, f1, f31
	  lfs       f0, 0xF4(r1)
	  addi      r6, r1, 0xB0
	  addi      r5, r1, 0xAC
	  addi      r4, r1, 0xA8
	  fmuls     f0, f0, f1
	  addi      r3, r1, 0x110
	  stfs      f0, 0xF4(r1)
	  lfs       f0, 0xF8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0xFC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xFC(r1)
	  lfs       f2, 0x8(r26)
	  lfs       f1, 0xFC(r1)
	  lfs       f0, 0xF4(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xB0(r1)
	  lfs       f2, 0x4(r26)
	  lfs       f1, 0xF8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xAC(r1)
	  lfs       f1, 0x0(r26)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  bl        -0x190A54
	  lfs       f0, 0x110(r1)
	  addi      r6, r1, 0xA0
	  addi      r5, r1, 0x9C
	  stfs      f0, 0x388(r31)
	  addi      r4, r1, 0x98
	  addi      r3, r1, 0xCC
	  lfs       f0, 0x114(r1)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0x118(r1)
	  stfs      f0, 0x390(r31)
	  lwz       r7, 0x2C8(r31)
	  lfs       f0, -0x4620(r2)
	  addi      r7, r7, 0x10
	  stfs      f0, 0xD4(r1)
	  stfs      f0, 0xD0(r1)
	  stfs      f0, 0xCC(r1)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x390(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x38C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x388(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  bl        -0x16A558
	  lfs       f1, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xD4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B9FC8
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xA574C
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x85C
	  lwz       r3, 0x2C8(r31)
	  addi      r6, r1, 0x90
	  lfs       f1, 0x390(r31)
	  addi      r5, r1, 0x8C
	  lfs       f0, 0x18(r3)
	  addi      r7, r3, 0x10
	  fsubs     f0, f1, f0
	  addi      r4, r1, 0x88
	  addi      r3, r1, 0x11C
	  stfs      f0, 0x90(r1)
	  lfs       f1, 0x38C(r31)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8C(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x88(r1)
	  bl        -0x190B58
	  lfs       f1, 0x11C(r1)
	  lfs       f0, 0x120(r1)
	  stfs      f1, 0xF4(r1)
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0x124(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f1, 0xF4(r1)
	  lfs       f0, 0xF8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xFC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1BA070
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x7C4
	  addi      r3, r1, 0xF4
	  bl        -0x13E778

	.loc_0x7C4:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  bl        -0xA4AC4
	  lfs       f0, 0xF4(r1)
	  addi      r6, r1, 0x84
	  addi      r5, r1, 0x80
	  fmuls     f0, f0, f1
	  addi      r4, r1, 0x7C
	  addi      r3, r1, 0x128
	  stfs      f0, 0xF4(r1)
	  lfs       f0, 0xF8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0xFC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xFC(r1)
	  lwz       r7, 0x2C8(r31)
	  lfs       f1, 0xFC(r1)
	  addi      r7, r7, 0x10
	  lfs       f0, 0xF4(r1)
	  lfs       f2, 0x8(r7)
	  fadds     f1, f2, f1
	  stfs      f1, 0x84(r1)
	  lfs       f2, 0x4(r7)
	  lfs       f1, 0xF8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x80(r1)
	  lfs       f1, 0x0(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  bl        -0x190C28
	  lfs       f0, 0x128(r1)
	  stfs      f0, 0x388(r31)
	  lfs       f0, 0x12C(r1)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0x130(r1)
	  stfs      f0, 0x390(r31)

	.loc_0x85C:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x5
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xA589C
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x3
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xA58B4
	  lfs       f2, -0x4590(r2)
	  mr        r3, r31
	  lfs       f0, -0x458C(r2)
	  addi      r4, r31, 0x388
	  fmuls     f1, f2, f1
	  fmuls     f2, f0, f31
	  bl        -0x252A8

	.loc_0x8A4:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x1956C
	  lmw       r26, 0x290(r1)
	  lwz       r0, 0x2CC(r1)
	  lfd       f31, 0x2C0(r1)
	  lfd       f30, 0x2B8(r1)
	  lfd       f29, 0x2B0(r1)
	  lfd       f28, 0x2A8(r1)
	  addi      r1, r1, 0x2C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C7DD8
 * Size:	00001C
 */
void TAIAflickingAfterMotionLoopBeatle::permitFlick(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C7DF4
 * Size:	000018
 */
void TAIAflickingAfterMotionLoopBeatle::getFrameMax(Teki&)
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
 * Address:	801C7E0C
 * Size:	0000A0
 */
void TAIArockAttack::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  bl        -0x1B120
	  lbz       r0, 0x4C8(r30)
	  li        r31, 0
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0x4C8(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  beq-      .loc_0x44
	  bl        -0xE3ADC
	  stw       r31, 0x420(r30)

	.loc_0x44:
	  li        r0, 0
	  stw       r0, 0x420(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  bl        -0xE3B08

	.loc_0x5C:
	  li        r0, 0
	  stw       r0, 0x4B0(r30)
	  mr        r3, r30
	  stw       r0, 0x4B4(r30)
	  bl        -0x25430
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x88
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2F
	  addi      r3, r3, 0x70
	  bl        -0x144490

	.loc_0x88:
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
 * Address:	801C7EAC
 * Size:	0010B0
 */
void TAIArockAttack::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x670(r1)
	  stfd      f31, 0x668(r1)
	  stfd      f30, 0x660(r1)
	  stfd      f29, 0x658(r1)
	  stfd      f28, 0x650(r1)
	  stfd      f27, 0x648(r1)
	  stfd      f26, 0x640(r1)
	  stfd      f25, 0x638(r1)
	  stfd      f24, 0x630(r1)
	  stfd      f23, 0x628(r1)
	  stfd      f22, 0x620(r1)
	  stfd      f21, 0x618(r1)
	  stfd      f20, 0x610(r1)
	  stmw      r23, 0x5EC(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  li        r28, 0
	  bl        -0x1B040
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1054
	  lis       r4, 0x736C
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6F74
	  bl        -0x13E800
	  lfs       f0, -0x4620(r2)
	  mr        r31, r3
	  stfs      f0, 0x5DC(r1)
	  stfs      f0, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x5D4(r1)
	  stw       r0, 0x5D8(r1)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x5DC(r1)
	  lwz       r3, 0x2C4(r30)
	  lfs       f1, 0xA0(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f20, 0xD8(r3)
	  bl        0x53D90
	  fmuls     f1, f1, f20
	  lfs       f2, 0x5D4(r1)
	  lfs       f0, -0x4580(r2)
	  fadds     f1, f2, f1
	  stfs      f1, 0x5D4(r1)
	  lfs       f1, 0x5D8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5D8(r1)
	  lwz       r3, 0x2C4(r30)
	  lfs       f1, 0xA0(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f20, 0xD8(r3)
	  bl        0x53BC0
	  fmuls     f0, f1, f20
	  lfs       f1, 0x5DC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5DC(r1)
	  lfs       f1, 0x5DC(r1)
	  lfs       f0, 0xC(r31)
	  lfs       f2, 0x5D8(r1)
	  fsubs     f23, f1, f0
	  lfs       f0, 0x8(r31)
	  lwz       r3, 0x2CC(r30)
	  fsubs     f22, f2, f0
	  lfs       f1, 0x5D4(r1)
	  lfs       f0, 0x4(r31)
	  fmr       f31, f23
	  fmr       f30, f22
	  fsubs     f21, f1, f0
	  lfs       f1, 0x2C(r3)
	  lfs       f0, -0x4620(r2)
	  fcmpo     cr0, f1, f0
	  fmr       f29, f21
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x150
	  lfs       f0, -0x458C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x158

	.loc_0x150:
	  lfs       f0, -0x458C(r2)
	  fsubs     f0, f1, f0

	.loc_0x158:
	  fctiwz    f0, f0
	  stfd      f0, 0x5E0(r1)
	  lwz       r0, 0x5E4(r1)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x2AC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x5D4
	  li        r4, 0x8E
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2B4F4
	  stw       r3, 0x4B0(r30)
	  addi      r5, r1, 0x5D4
	  li        r4, 0x8F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2B510
	  mr.       r24, r3
	  beq-      .loc_0x2AC
	  lfs       f0, -0x4620(r2)
	  stfs      f0, 0x5AC(r1)
	  stfs      f0, 0x5A8(r1)
	  stfs      f0, 0x5A4(r1)
	  lfs       f2, -0x457C(r2)
	  lfs       f3, 0x8(r31)
	  lfs       f1, 0x5D4(r1)
	  lfs       f0, 0x4(r31)
	  fsubs     f2, f3, f2
	  lfs       f3, 0x5D8(r1)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x5DC(r1)
	  lfs       f1, 0xC(r31)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x5A4(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x5A8(r1)
	  stfs      f0, 0x5AC(r1)
	  lfs       f1, 0x5A4(r1)
	  lfs       f0, 0x5A8(r1)
	  lfs       f2, 0x5AC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1BA47C
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x244
	  lfs       f0, 0x5A4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x5A4(r1)
	  lfs       f0, 0x5A8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x5A8(r1)
	  lfs       f0, 0x5AC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x5AC(r1)

	.loc_0x244:
	  lfs       f0, 0x5A4(r1)
	  lfs       f1, -0x4578(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5A4(r1)
	  lfs       f0, 0x5A8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5A8(r1)
	  lfs       f0, 0x5AC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5AC(r1)
	  lwz       r3, 0x5A4(r1)
	  lwz       r0, 0x5A8(r1)
	  stw       r3, 0x1DC(r24)
	  stw       r0, 0x1E0(r24)
	  lwz       r0, 0x5AC(r1)
	  stw       r0, 0x1E4(r24)
	  lfs       f0, 0x5A4(r1)
	  stfs      f0, 0x138(r24)
	  lfs       f0, 0x5A8(r1)
	  stfs      f0, 0x13C(r24)
	  lfs       f0, 0x5AC(r1)
	  stfs      f0, 0x140(r24)
	  lwz       r0, 0x84(r24)
	  oris      r0, r0, 0x2
	  stw       r0, 0x84(r24)
	  stw       r24, 0x4B4(r30)

	.loc_0x2AC:
	  fmuls     f1, f21, f21
	  fmuls     f0, f22, f22
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1BA52C
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2DC
	  fdivs     f21, f21, f1
	  fdivs     f22, f22, f1
	  fdivs     f23, f23, f1

	.loc_0x2DC:
	  lwz       r23, 0x4B0(r30)
	  cmplwi    r23, 0
	  beq-      .loc_0x3A8
	  lfs       f0, 0x1C14(r13)
	  addi      r6, r1, 0x1C4
	  addi      r5, r1, 0x1C0
	  fmuls     f2, f23, f0
	  addi      r4, r1, 0x1BC
	  fmuls     f1, f22, f0
	  addi      r3, r1, 0x3B8
	  fmuls     f0, f21, f0
	  stfs      f2, 0x1C4(r1)
	  stfs      f1, 0x1C0(r1)
	  stfs      f0, 0x1BC(r1)
	  bl        -0x1910A4
	  lfs       f1, 0xC(r31)
	  mr        r3, r23
	  lfs       f0, 0x3C0(r1)
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0x3BC(r1)
	  fadds     f24, f1, f0
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x3B8(r1)
	  fadds     f25, f3, f2
	  lfs       f20, 0x17C(r23)
	  fadds     f26, f1, f0
	  bl        -0xB3580
	  lfs       f0, 0x8(r3)
	  addi      r6, r1, 0x1FC
	  addi      r5, r1, 0x1F8
	  fsubs     f0, f24, f0
	  addi      r4, r1, 0x1F4
	  stfs      f0, 0x1FC(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f25, f0
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x26C
	  fsubs     f0, f26, f0
	  stfs      f0, 0x1F4(r1)
	  bl        -0x19110C
	  lfs       f0, 0x26C(r1)
	  stfs      f0, 0x170(r23)
	  lfs       f0, 0x270(r1)
	  stfs      f0, 0x174(r23)
	  lfs       f0, 0x274(r1)
	  stfs      f0, 0x178(r23)
	  stfs      f20, 0x17C(r23)
	  lwz       r0, 0x84(r23)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r23)

	.loc_0x3A8:
	  lwz       r4, 0x4B4(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x434
	  lfs       f0, -0x4620(r2)
	  stfs      f0, 0x594(r1)
	  stfs      f0, 0x590(r1)
	  stfs      f0, 0x58C(r1)
	  stfs      f21, 0x58C(r1)
	  stfs      f22, 0x590(r1)
	  stfs      f23, 0x594(r1)
	  lfs       f0, 0x58C(r1)
	  lfs       f1, -0x4574(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x58C(r1)
	  lfs       f0, 0x590(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x590(r1)
	  lfs       f0, 0x594(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x594(r1)
	  lwz       r3, 0x58C(r1)
	  lwz       r0, 0x590(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x594(r1)
	  stw       r0, 0x1E4(r4)
	  lfs       f0, 0x58C(r1)
	  stfs      f0, 0x138(r4)
	  lfs       f0, 0x590(r1)
	  stfs      f0, 0x13C(r4)
	  lfs       f0, 0x594(r1)
	  stfs      f0, 0x140(r4)
	  lwz       r0, 0x84(r4)
	  oris      r0, r0, 0x2
	  stw       r0, 0x84(r4)

	.loc_0x434:
	  lwz       r3, 0x2CC(r30)
	  lfs       f0, -0x4620(r2)
	  lfs       f1, 0x2C(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x458
	  lfs       f0, -0x458C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x460

	.loc_0x458:
	  lfs       f0, -0x458C(r2)
	  fsubs     f0, f1, f0

	.loc_0x460:
	  fctiwz    f0, f0
	  stfd      f0, 0x5E0(r1)
	  lwz       r0, 0x5E4(r1)
	  cmpwi     r0, 0x4
	  ble-      .loc_0x780
	  lwz       r0, 0x4B0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x780
	  lwz       r27, 0x3068(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f27, -0x4620(r2)
	  lis       r4, 0x802B
	  lfs       f28, -0x4610(r2)
	  lfs       f26, -0x4570(r2)
	  mr        r26, r3
	  lfs       f20, -0x45E4(r2)
	  subi      r24, r5, 0x3064
	  lfd       f24, -0x45A8(r2)
	  lfd       f25, -0x45A0(r2)
	  subi      r25, r4, 0x3120
	  b         .loc_0x724

	.loc_0x4C8:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x4F0
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3
	  b         .loc_0x50C

	.loc_0x4F0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3

	.loc_0x50C:
	  cmplwi    r23, 0
	  beq-      .loc_0x708
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x708
	  lfs       f0, 0x8(r31)
	  lfs       f2, 0x98(r23)
	  lfs       f1, 0x94(r23)
	  fsubs     f22, f2, f0
	  lfs       f0, 0x4(r31)
	  lfs       f2, 0x9C(r23)
	  fsubs     f23, f1, f0
	  lfs       f0, 0xC(r31)
	  fsubs     f21, f2, f0
	  fmuls     f1, f29, f23
	  fmuls     f0, f30, f22
	  fmuls     f2, f31, f21
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f27
	  ble-      .loc_0x708
	  fmuls     f1, f29, f29
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f27
	  ble-      .loc_0x5DC
	  fsqrte    f2, f0
	  fmul      f1, f2, f2
	  fmul      f2, f24, f2
	  fmul      f1, f0, f1
	  fsub      f1, f25, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f24, f2
	  fmul      f1, f0, f1
	  fsub      f1, f25, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f24, f2
	  fmul      f1, f0, f1
	  fsub      f1, f25, f1
	  fmul      f1, f2, f1
	  fmul      f0, f0, f1
	  frsp      f0, f0
	  stfs      f0, 0x240(r1)
	  lfs       f0, 0x240(r1)

	.loc_0x5DC:
	  fmuls     f2, f23, f23
	  fmuls     f1, f22, f22
	  fmuls     f3, f21, f21
	  fadds     f1, f2, f1
	  fadds     f3, f3, f1
	  fcmpo     cr0, f3, f27
	  ble-      .loc_0x648
	  fsqrte    f2, f3
	  fmul      f1, f2, f2
	  fmul      f2, f24, f2
	  fmul      f1, f3, f1
	  fsub      f1, f25, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f24, f2
	  fmul      f1, f3, f1
	  fsub      f1, f25, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f24, f2
	  fmul      f1, f3, f1
	  fsub      f1, f25, f1
	  fmul      f1, f2, f1
	  fmul      f1, f3, f1
	  frsp      f1, f1
	  stfs      f1, 0x23C(r1)
	  lfs       f3, 0x23C(r1)

	.loc_0x648:
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x708
	  fcmpu     cr0, f27, f0
	  beq-      .loc_0x664
	  fdivs     f29, f29, f0
	  fdivs     f30, f30, f0
	  fdivs     f31, f31, f0

	.loc_0x664:
	  fcmpu     cr0, f27, f3
	  beq-      .loc_0x678
	  fdivs     f23, f23, f3
	  fdivs     f22, f22, f3
	  fdivs     f21, f21, f3

	.loc_0x678:
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xD4(r3)
	  fmuls     f0, f26, f0
	  fdivs     f1, f0, f20
	  bl        0x53614
	  fmuls     f2, f29, f23
	  fmuls     f0, f30, f22
	  fmuls     f3, f31, f21
	  fadds     f0, f2, f0
	  fadds     f0, f3, f0
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x708
	  stw       r24, 0x538(r1)
	  fneg      f2, f23
	  fneg      f1, f22
	  li        r0, 0
	  stw       r30, 0x53C(r1)
	  fneg      f0, f21
	  stw       r25, 0x538(r1)
	  fmuls     f2, f2, f28
	  mr        r3, r23
	  stfs      f27, 0x540(r1)
	  fmuls     f1, f1, f28
	  addi      r4, r1, 0x538
	  stfs      f2, 0x544(r1)
	  fmuls     f0, f0, f28
	  stfs      f1, 0x548(r1)
	  stfs      f0, 0x54C(r1)
	  stw       r0, 0x550(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x708:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x724:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74C
	  li        r0, 0x1
	  b         .loc_0x778

	.loc_0x74C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x774
	  li        r0, 0x1
	  b         .loc_0x778

	.loc_0x774:
	  li        r0, 0

	.loc_0x778:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4C8

	.loc_0x780:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x79C
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0x1
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0x4C8(r30)

	.loc_0x79C:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x7B8
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0x4C8(r30)

	.loc_0x7B8:
	  lbz       r0, 0x4C8(r30)
	  rlwinm.   r0,r0,25,31,31
	  beq-      .loc_0xBC4
	  lwz       r0, 0x420(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xBC4
	  cmplwi    r31, 0
	  beq-      .loc_0xBC4
	  lwz       r26, 0x3068(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f22, -0x4620(r2)
	  mr        r25, r3
	  lfd       f21, -0x45A8(r2)
	  lfd       f20, -0x45A0(r2)
	  b         .loc_0xB68

	.loc_0x804:
	  cmpwi     r25, -0x1
	  bne-      .loc_0x82C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x848

	.loc_0x82C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r25
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x848:
	  cmplwi    r27, 0
	  beq-      .loc_0xB4C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB4C
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0x98(r27)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x94(r27)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r31)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r27)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f22
	  ble-      .loc_0x8FC
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f21, f1
	  fmul      f0, f2, f0
	  fsub      f0, f20, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f21, f1
	  fmul      f0, f2, f0
	  fsub      f0, f20, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f21, f1
	  fmul      f0, f2, f0
	  fsub      f0, f20, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x228(r1)
	  lfs       f2, 0x228(r1)

	.loc_0x8FC:
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xD0(r3)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xB4C
	  addi      r3, r1, 0x330
	  addi      r4, r31, 0
	  bl        -0x1408B4
	  lwz       r3, 0x330(r1)
	  lwz       r0, 0x334(r1)
	  stw       r3, 0x4DC(r1)
	  lwz       r3, 0x338(r1)
	  stw       r0, 0x4E0(r1)
	  lwz       r0, 0x33C(r1)
	  stw       r3, 0x4E4(r1)
	  lwz       r3, 0x340(r1)
	  stw       r0, 0x4E8(r1)
	  lwz       r0, 0x344(r1)
	  stw       r3, 0x4EC(r1)
	  lwz       r3, 0x348(r1)
	  stw       r0, 0x4F0(r1)
	  lwz       r0, 0x34C(r1)
	  stw       r3, 0x4F4(r1)
	  lwz       r3, 0x350(r1)
	  stw       r0, 0x4F8(r1)
	  lwz       r0, 0x354(r1)
	  stw       r3, 0x4FC(r1)
	  lwz       r3, 0x358(r1)
	  stw       r0, 0x500(r1)
	  lwz       r0, 0x35C(r1)
	  stw       r3, 0x504(r1)
	  lwz       r3, 0x360(r1)
	  stw       r0, 0x508(r1)
	  lwz       r0, 0x364(r1)
	  stw       r3, 0x50C(r1)
	  lwz       r3, 0x368(r1)
	  stw       r0, 0x510(r1)
	  lwz       r0, 0x36C(r1)
	  stw       r3, 0x514(r1)
	  lfs       f0, -0x4620(r2)
	  stw       r0, 0x518(r1)
	  stfs      f0, 0x4D8(r1)
	  stfs      f0, 0x4D4(r1)
	  stfs      f0, 0x4D0(r1)
	  lfs       f1, 0x4DC(r1)
	  lfs       f0, 0x4EC(r1)
	  stfs      f1, 0x4D0(r1)
	  stfs      f0, 0x4D4(r1)
	  lfs       f0, 0x4FC(r1)
	  stfs      f0, 0x4D8(r1)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x9E8
	  beq-      .loc_0x9E8
	  bl        -0xE451C
	  li        r0, 0
	  stw       r0, 0x420(r30)

	.loc_0x9E8:
	  stw       r27, 0x420(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x9FC
	  bl        -0xE4548

	.loc_0x9FC:
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x4C0(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x3244
	  stw       r30, 0x4C4(r1)
	  li        r0, 0
	  addi      r3, r27, 0
	  stw       r4, 0x4C0(r1)
	  addi      r4, r1, 0x4C0
	  stw       r0, 0x4C8(r1)
	  stw       r31, 0x4CC(r1)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4B0(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4C
	  bl        -0x27CF8

	.loc_0xA4C:
	  lwz       r3, 0x4B4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA5C
	  bl        -0x27D08

	.loc_0xA5C:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x89
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2BDE4
	  cmplwi    r3, 0
	  beq-      .loc_0xAC4
	  lwz       r4, 0x4D0(r1)
	  lwz       r0, 0x4D4(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x4D8(r1)
	  stw       r0, 0xA8(r3)
	  lfs       f0, 0x1C18(r13)
	  lfs       f1, 0x1C1C(r13)
	  stfs      f0, 0x324(r1)
	  lfs       f0, 0x1C20(r13)
	  stfs      f1, 0x328(r1)
	  stfs      f0, 0x32C(r1)
	  lwz       r4, 0x324(r1)
	  lwz       r0, 0x328(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x32C(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0xAC4:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x8A
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2BE4C
	  cmplwi    r3, 0
	  beq-      .loc_0xB2C
	  lwz       r4, 0x4D0(r1)
	  lwz       r0, 0x4D4(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x4D8(r1)
	  stw       r0, 0xA8(r3)
	  lfs       f0, 0x1C24(r13)
	  lfs       f1, 0x1C28(r13)
	  stfs      f0, 0x318(r1)
	  lfs       f0, 0x1C2C(r13)
	  stfs      f1, 0x31C(r1)
	  stfs      f0, 0x320(r1)
	  lwz       r4, 0x318(r1)
	  lwz       r0, 0x31C(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x320(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0xB2C:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x5C
	  bl        -0x13E430
	  lwz       r0, 0x10(r29)
	  li        r28, 0x1
	  stw       r0, 0x0(r29)
	  b         .loc_0xBC4

	.loc_0xB4C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r25
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3

	.loc_0xB68:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r25
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB90
	  li        r0, 0x1
	  b         .loc_0xBBC

	.loc_0xB90:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r25
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xBB8
	  li        r0, 0x1
	  b         .loc_0xBBC

	.loc_0xBB8:
	  li        r0, 0

	.loc_0xBBC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x804

	.loc_0xBC4:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x4
	  bne-      .loc_0xBD8
	  mr        r3, r30
	  bl        -0x80D0C

	.loc_0xBD8:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x3
	  bne-      .loc_0xFFC
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7469
	  bl        -0x13F38C
	  mr.       r25, r3
	  beq-      .loc_0xFFC
	  addi      r3, r1, 0x2D8
	  addi      r4, r25, 0
	  bl        -0x140B98
	  lwz       r4, 0x2D8(r1)
	  mr        r3, r30
	  lwz       r0, 0x2DC(r1)
	  stw       r4, 0x480(r1)
	  lwz       r4, 0x2E0(r1)
	  stw       r0, 0x484(r1)
	  lwz       r0, 0x2E4(r1)
	  stw       r4, 0x488(r1)
	  lwz       r4, 0x2E8(r1)
	  stw       r0, 0x48C(r1)
	  lwz       r0, 0x2EC(r1)
	  stw       r4, 0x490(r1)
	  lwz       r4, 0x2F0(r1)
	  stw       r0, 0x494(r1)
	  lwz       r0, 0x2F4(r1)
	  stw       r4, 0x498(r1)
	  lwz       r4, 0x2F8(r1)
	  stw       r0, 0x49C(r1)
	  lwz       r0, 0x2FC(r1)
	  stw       r4, 0x4A0(r1)
	  lwz       r4, 0x300(r1)
	  stw       r0, 0x4A4(r1)
	  lwz       r0, 0x304(r1)
	  stw       r4, 0x4A8(r1)
	  lwz       r4, 0x308(r1)
	  stw       r0, 0x4AC(r1)
	  lwz       r0, 0x30C(r1)
	  stw       r4, 0x4B0(r1)
	  lwz       r4, 0x310(r1)
	  stw       r0, 0x4B4(r1)
	  lwz       r0, 0x314(r1)
	  stw       r4, 0x4B8(r1)
	  lfs       f0, -0x4620(r2)
	  stw       r0, 0x4BC(r1)
	  stfs      f0, 0x47C(r1)
	  stfs      f0, 0x478(r1)
	  stfs      f0, 0x474(r1)
	  stfs      f0, 0x470(r1)
	  stfs      f0, 0x46C(r1)
	  stfs      f0, 0x468(r1)
	  lwz       r4, 0x2C4(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r4, 0x84(r4)
	  lwz       r12, 0x198(r12)
	  lwz       r4, 0x0(r4)
	  mtlr      r12
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0xC(r4)
	  blrl
	  mr.       r26, r3
	  beq-      .loc_0xF08
	  lfs       f1, 0x480(r1)
	  addi      r6, r1, 0x1E4
	  lfs       f0, 0x490(r1)
	  addi      r5, r1, 0x1E0
	  stfs      f1, 0x468(r1)
	  addi      r4, r1, 0x1DC
	  stfs      f0, 0x46C(r1)
	  addi      r3, r1, 0x2C0
	  lfs       f0, 0x4A0(r1)
	  stfs      f0, 0x470(r1)
	  lfs       f1, 0x470(r1)
	  lfs       f2, 0x1C30(r13)
	  lfs       f0, 0x468(r1)
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f2
	  stfs      f1, 0x1E4(r1)
	  lfs       f1, 0x46C(r1)
	  fmuls     f1, f1, f2
	  stfs      f0, 0x1DC(r1)
	  stfs      f1, 0x1E0(r1)
	  bl        -0x191AB4
	  lfs       f1, 0x4(r25)
	  addi      r5, r1, 0x474
	  lfs       f0, 0x2C0(r1)
	  li        r4, 0x90
	  lfs       f3, 0x8(r25)
	  lfs       f2, 0x2C4(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0xC(r25)
	  li        r6, 0
	  lfs       f1, 0x2C8(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x474(r1)
	  fadds     f0, f4, f1
	  li        r7, 0
	  stfs      f2, 0x478(r1)
	  stfs      f0, 0x47C(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x2C0E0
	  cmplwi    r3, 0
	  beq-      .loc_0xD90
	  lwz       r4, 0x468(r1)
	  lwz       r0, 0x46C(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x470(r1)
	  stw       r0, 0xA8(r3)

	.loc_0xD90:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x474
	  li        r4, 0x91
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2C118
	  cmplwi    r3, 0
	  beq-      .loc_0xDC8
	  lwz       r4, 0x468(r1)
	  lwz       r0, 0x46C(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x470(r1)
	  stw       r0, 0xA8(r3)

	.loc_0xDC8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x474
	  li        r4, 0x92
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2C150
	  cmplwi    r3, 0
	  beq-      .loc_0xE00
	  lwz       r4, 0x468(r1)
	  lwz       r0, 0x46C(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x470(r1)
	  stw       r0, 0xA8(r3)

	.loc_0xE00:
	  lwz       r4, 0x2C8(r26)
	  li        r0, 0x1
	  addi      r3, r30, 0
	  lwz       r5, 0x34(r4)
	  addi      r4, r1, 0x45C
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x10(r5)
	  lfs       f0, -0x4620(r2)
	  stfs      f0, 0x464(r1)
	  stfs      f0, 0x460(r1)
	  stfs      f0, 0x45C(r1)
	  bl        -0x8272C
	  lwz       r3, 0x45C(r1)
	  lwz       r0, 0x460(r1)
	  stw       r3, 0x94(r26)
	  stw       r0, 0x98(r26)
	  lwz       r0, 0x464(r1)
	  stw       r0, 0x9C(r26)
	  lfs       f20, 0xA0(r30)
	  fmr       f1, f20
	  bl        0x52E54
	  fmr       f22, f1
	  fmr       f1, f20
	  bl        0x52FDC
	  lwz       r3, 0x2C8(r30)
	  fmr       f21, f1
	  lfs       f23, 0x1C10(r13)
	  li        r4, 0x1
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xA6854
	  lwz       r3, 0x2C4(r30)
	  fmr       f20, f1
	  li        r4, 0x18
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xA686C
	  fmuls     f0, f1, f20
	  addi      r3, r26, 0
	  li        r4, 0
	  fmuls     f1, f21, f0
	  fmuls     f23, f23, f0
	  fmuls     f0, f22, f0
	  stfs      f1, 0x70(r26)
	  stfs      f23, 0x74(r26)
	  stfs      f0, 0x78(r26)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x5E
	  bl        -0x13E7D0
	  addi      r23, r30, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r23, 0
	  li        r4, 0x3
	  bl        -0xA4DC0
	  lwz       r3, 0x3178(r13)
	  addi      r6, r23, 0
	  li        r4, 0xE
	  li        r5, 0
	  bl        -0x4BFD8
	  b         .loc_0xFFC

	.loc_0xF08:
	  addi      r3, r1, 0x280
	  addi      r4, r25, 0
	  bl        -0x140EA4
	  lwz       r3, 0x280(r1)
	  addi      r5, r25, 0x4
	  lwz       r0, 0x284(r1)
	  li        r4, 0x88
	  stw       r3, 0x410(r1)
	  lwz       r3, 0x288(r1)
	  li        r6, 0
	  stw       r0, 0x414(r1)
	  li        r7, 0
	  lwz       r0, 0x28C(r1)
	  stw       r3, 0x418(r1)
	  lwz       r3, 0x290(r1)
	  stw       r0, 0x41C(r1)
	  lwz       r0, 0x294(r1)
	  stw       r3, 0x420(r1)
	  lwz       r3, 0x298(r1)
	  stw       r0, 0x424(r1)
	  lwz       r0, 0x29C(r1)
	  stw       r3, 0x428(r1)
	  lwz       r3, 0x2A0(r1)
	  stw       r0, 0x42C(r1)
	  lwz       r0, 0x2A4(r1)
	  stw       r3, 0x430(r1)
	  lwz       r3, 0x2A8(r1)
	  stw       r0, 0x434(r1)
	  lwz       r0, 0x2AC(r1)
	  stw       r3, 0x438(r1)
	  lwz       r3, 0x2B0(r1)
	  stw       r0, 0x43C(r1)
	  lwz       r0, 0x2B4(r1)
	  stw       r3, 0x440(r1)
	  lwz       r3, 0x2B8(r1)
	  stw       r0, 0x444(r1)
	  lwz       r0, 0x2BC(r1)
	  stw       r3, 0x448(r1)
	  lfs       f0, -0x4620(r2)
	  stw       r0, 0x44C(r1)
	  stfs      f0, 0x40C(r1)
	  stfs      f0, 0x408(r1)
	  stfs      f0, 0x404(r1)
	  lfs       f1, 0x410(r1)
	  lfs       f0, 0x420(r1)
	  stfs      f1, 0x404(r1)
	  stfs      f0, 0x408(r1)
	  lfs       f0, 0x430(r1)
	  stfs      f0, 0x40C(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x2C344
	  cmplwi    r3, 0
	  beq-      .loc_0xFFC
	  addi      r0, r25, 0x4
	  stw       r0, 0x18(r3)
	  lwz       r4, 0x404(r1)
	  lwz       r0, 0x408(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x40C(r1)
	  stw       r0, 0xA8(r3)

	.loc_0xFFC:
	  lwz       r0, 0x420(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x1044
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x6
	  bne-      .loc_0x1044
	  lwz       r0, 0xC(r29)
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  stw       r0, 0x0(r29)
	  beq-      .loc_0x102C
	  lwz       r5, 0x2C0(r30)

	.loc_0x102C:
	  addi      r3, r1, 0x278
	  li        r4, -0x1
	  bl        -0xA9F54
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0xA9CBC

	.loc_0x1044:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x1054
	  li        r28, 0x1

	.loc_0x1054:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x1068
	  li        r0, 0
	  stw       r0, 0x4B0(r30)
	  stw       r0, 0x4B4(r30)

	.loc_0x1068:
	  mr        r3, r28
	  lmw       r23, 0x5EC(r1)
	  lwz       r0, 0x674(r1)
	  lfd       f31, 0x668(r1)
	  lfd       f30, 0x660(r1)
	  lfd       f29, 0x658(r1)
	  lfd       f28, 0x650(r1)
	  lfd       f27, 0x648(r1)
	  lfd       f26, 0x640(r1)
	  lfd       f25, 0x638(r1)
	  lfd       f24, 0x630(r1)
	  lfd       f23, 0x628(r1)
	  lfd       f22, 0x620(r1)
	  lfd       f21, 0x618(r1)
	  lfd       f20, 0x610(r1)
	  addi      r1, r1, 0x670
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C8F5C
 * Size:	000020
 */
void TAIAinsideOptionalRangeBeatle::setTargetPosition(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1BB5C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C8F7C
 * Size:	000018
 */
void TAIAinsideOptionalRangeBeatle::getOptionalRange(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xCC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C8F94
 * Size:	0001F0
 */
void TAIAvisiblePikiBeatle::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stmw      r26, 0x60(r1)
	  addi      r31, r4, 0
	  li        r26, 0
	  lwz       r28, 0x3068(r13)
	  lwz       r12, 0x0(r28)
	  addi      r3, r28, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f30, -0x4620(r2)
	  addi      r27, r3, 0
	  lfs       f31, -0x461C(r2)
	  addi      r29, r31, 0x94
	  b         .loc_0x174

	.loc_0x4C:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x74
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x90

	.loc_0x74:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x90:
	  addi      r4, r30, 0
	  addi      r3, r31, 0
	  bl        -0x82318
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x158
	  lwz       r0, 0x184(r30)
	  cmplw     r0, r31
	  beq-      .loc_0x158
	  stfs      f30, 0x4C(r1)
	  stfs      f30, 0x48(r1)
	  stfs      f30, 0x44(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x0(r29)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r29)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x4(r29)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x34(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f3, 0x4C(r1)
	  lfs       f1, 0x44(r1)
	  lfs       f0, 0x48(r1)
	  lfs       f2, 0x4C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1BB468
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x158
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  beq-      .loc_0x13C
	  bl        -0xE4D58
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0x13C:
	  stw       r30, 0x418(r31)
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  bl        -0xE4D84

	.loc_0x150:
	  li        r26, 0x1
	  b         .loc_0x1D0

	.loc_0x158:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x174:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19C
	  li        r0, 0x1
	  b         .loc_0x1C8

	.loc_0x19C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1C4
	  li        r0, 0x1
	  b         .loc_0x1C8

	.loc_0x1C4:
	  li        r0, 0

	.loc_0x1C8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4C

	.loc_0x1D0:
	  mr        r3, r26
	  lmw       r26, 0x60(r1)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C9184
 * Size:	000024
 */
void TAIAdamageBeatle::judgeDamage(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x344(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lfs       f0, -0x4620(r2)
	  li        r3, 0
	  stfs      f0, 0x33C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C91A8
 * Size:	000160
 */
void TAIAdyingBeatle::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x20C90
	  addi      r5, r31, 0x498
	  lwz       r4, 0x498(r31)
	  li        r0, 0
	  cmplwi    r4, 0
	  beq-      .loc_0x3C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0x3C:
	  addi      r5, r31, 0x49C
	  lwz       r4, 0x49C(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0x5C:
	  addi      r5, r31, 0x4A0
	  lwz       r4, 0x4A0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x7C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0x7C:
	  addi      r5, r31, 0x4A4
	  lwz       r4, 0x4A4(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x9C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0x9C:
	  addi      r5, r31, 0x4A8
	  lwz       r4, 0x4A8(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xBC
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0xBC:
	  addi      r5, r31, 0x4AC
	  lwz       r4, 0x4AC(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xDC
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0xDC:
	  addi      r5, r31, 0x4B0
	  lwz       r4, 0x4B0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xFC
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0xFC:
	  addi      r5, r31, 0x4B4
	  lwz       r4, 0x4B4(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x11C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0x11C:
	  addi      r5, r31, 0x4B8
	  lwz       r4, 0x4B8(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x13C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  stw       r0, 0x0(r5)

	.loc_0x13C:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2F
	  addi      r3, r3, 0x70
	  bl        -0x1458A0
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C9308
 * Size:	00005C
 */
void TAIAdyingBeatle::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x63
	  bl        -0x13ED88

	.loc_0x38:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x20D24
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
 * Address:	801C9364
 * Size:	000160
 */
void TAIAinitBeatle::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r12, 0x8
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  rlwinm    r10,r0,2,0,29
	  li        r0, 0x2
	  stwu      r1, -0x20(r1)
	  rlwinm    r9,r0,2,0,29
	  li        r0, 0x3
	  stw       r31, 0x1C(r1)
	  rlwinm    r8,r0,2,0,29
	  li        r0, 0x4
	  rlwinm    r7,r0,2,0,29
	  li        r0, 0x5
	  rlwinm    r6,r0,2,0,29
	  li        r0, 0x6
	  rlwinm    r5,r0,2,0,29
	  li        r0, 0x7
	  li        r11, 0
	  rlwinm    r3,r0,2,0,29
	  stw       r11, 0x498(r4)
	  subfic    r0, r12, 0x9
	  addi      r31, r4, 0
	  mtctr     r0
	  addi      r0, r10, 0x498
	  stwx      r11, r31, r0
	  addi      r4, r9, 0x498
	  addi      r0, r8, 0x498
	  stwx      r11, r31, r4
	  addi      r7, r7, 0x498
	  addi      r6, r6, 0x498
	  stwx      r11, r31, r0
	  addi      r0, r3, 0x498
	  addi      r4, r5, 0x498
	  stwx      r11, r31, r7
	  cmpwi     r12, 0x9
	  rlwinm    r3,r12,2,0,29
	  stwx      r11, r31, r6
	  stwx      r11, r31, r4
	  stwx      r11, r31, r0
	  bge-      .loc_0xB4

	.loc_0xA4:
	  addi      r0, r3, 0x498
	  stwx      r11, r31, r0
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0xA4

	.loc_0xB4:
	  lis       r4, 0x6D65
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x5F6C
	  bl        -0x13FD14
	  mr.       r4, r3
	  beq-      .loc_0xFC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x8D
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2C90C
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0xF8:
	  stw       r3, 0x498(r31)

	.loc_0xFC:
	  lis       r4, 0x6D65
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x5F72
	  bl        -0x13FD5C
	  mr.       r4, r3
	  beq-      .loc_0x144
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x8D
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2C954
	  cmplwi    r3, 0
	  beq-      .loc_0x140
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x140:
	  stw       r3, 0x49C(r31)

	.loc_0x144:
	  lfs       f0, -0x456C(r2)
	  stfs      f0, 0x270(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C94C4
 * Size:	000008
 */
u32 TAIAinitBeatle::act(Teki&) { return 0x1; }
