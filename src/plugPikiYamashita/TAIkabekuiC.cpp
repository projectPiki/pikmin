#include "TAI/KabekuiC.h"

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
 * Address:	801CD720
 * Size:	000084
 */
TAIkabekuiCSoundTable::TAIkabekuiCSoundTable()
    : PaniSoundTable(3)
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
	  bl        -0xAE6CC
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x186750
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x7C
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
 * Address:	801CD7A4
 * Size:	000478
 */
TAIkabekuiCParameters::TAIkabekuiCParameters()
    : TekiParameters(20, 60)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x3C
	  stwu      r1, -0xF0(r1)
	  stw       r31, 0xEC(r1)
	  addi      r31, r4, 0x2E00
	  li        r4, 0x14
	  stw       r30, 0xE8(r1)
	  addi      r30, r3, 0
	  bl        -0x81A84
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3880
	  stw       r0, 0x0(r30)
	  li        r0, 0x32
	  li        r7, 0x33
	  lwz       r4, 0x84(r30)
	  li        r6, 0x34
	  li        r5, 0x35
	  lwz       r9, 0x4(r4)
	  li        r3, 0x36
	  mulli     r8, r0, 0xC
	  lwz       r0, 0x8(r9)
	  add       r9, r0, r8
	  addi      r8, r31, 0x1C
	  stw       r8, 0x0(r9)
	  mulli     r8, r7, 0xC
	  lfs       f1, -0x4448(r2)
	  mulli     r7, r6, 0xC
	  stfs      f1, 0x4(r9)
	  lfs       f0, -0x4444(r2)
	  mulli     r6, r5, 0xC
	  stfs      f0, 0x8(r9)
	  add       r9, r0, r8
	  addi      r5, r31, 0x34
	  stw       r5, 0x0(r9)
	  mulli     r5, r3, 0xC
	  stfs      f1, 0x4(r9)
	  li        r3, 0x37
	  lfs       f2, -0x4440(r2)
	  mulli     r8, r3, 0xC
	  stfs      f2, 0x8(r9)
	  add       r10, r0, r7
	  addi      r3, r31, 0x44
	  stw       r3, 0x0(r10)
	  li        r3, 0x38
	  mulli     r7, r3, 0xC
	  stfs      f1, 0x4(r10)
	  lfs       f5, -0x443C(r2)
	  add       r11, r0, r6
	  addi      r9, r31, 0x6C
	  stfs      f5, 0x8(r10)
	  li        r3, 0x39
	  mulli     r6, r3, 0xC
	  stw       r9, 0x0(r11)
	  stfs      f1, 0x4(r11)
	  add       r10, r0, r5
	  addi      r9, r31, 0x94
	  stfs      f5, 0x8(r11)
	  li        r3, 0x3A
	  mulli     r5, r3, 0xC
	  stw       r9, 0x0(r10)
	  stfs      f1, 0x4(r10)
	  add       r9, r0, r8
	  addi      r8, r31, 0xAC
	  stfs      f0, 0x8(r10)
	  li        r3, 0x3B
	  mulli     r3, r3, 0xC
	  stw       r8, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  add       r8, r0, r7
	  addi      r7, r31, 0xC8
	  stfs      f0, 0x8(r9)
	  add       r9, r0, r6
	  addi      r6, r31, 0xE0
	  stw       r7, 0x0(r8)
	  add       r7, r0, r5
	  addi      r5, r31, 0xF4
	  stfs      f1, 0x4(r8)
	  add       r3, r0, r3
	  stfs      f2, 0x8(r8)
	  stw       r6, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f2, 0x8(r9)
	  stw       r5, 0x0(r7)
	  stfs      f1, 0x4(r7)
	  stfs      f2, 0x8(r7)
	  addi      r0, r31, 0x108
	  stw       r0, 0x0(r3)
	  li        r0, 0x1
	  li        r9, -0x1
	  stfs      f1, 0x4(r3)
	  li        r8, 0x5
	  li        r7, 0x2
	  stfs      f2, 0x8(r3)
	  li        r6, 0xA
	  li        r5, 0x3
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4438(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4434(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4430(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x442C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xD8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4428(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xDC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4424(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xE0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xE4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4420(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xE8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xEC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r9, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x30(r3)
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
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x441C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4418(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4414(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4410(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x440C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4408(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x4404(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4400(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43FC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43F8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43F4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43F0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43EC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x80(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43E8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x84(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x88(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x8C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x43E4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x90(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43E0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x94(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x98(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x50(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x54(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x74(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f5, 0x4C(r4)
	  lwz       r0, 0xF4(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CDC1C
 * Size:	00129C
 */
TAIkabekuiCStrategy::TAIkabekuiCStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x11
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x158(r1)
	  stmw      r14, 0x110(r1)
	  addi      r31, r3, 0
	  bl        0x1BA1C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x37C4
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x186C48
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x60
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r28)

	.loc_0x60:
	  li        r3, 0x10
	  bl        -0x186C7C
	  stw       r3, 0x10C(r1)
	  lwz       r3, 0x10C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x21048
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0x10C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0xD30
	  lwz       r3, 0x10C(r1)
	  stw       r0, 0x4(r3)
	  li        r0, 0x44
	  lwz       r3, 0x10C(r1)
	  stw       r0, 0xC(r3)

	.loc_0xB0:
	  li        r3, 0xC
	  bl        -0x186CCC
	  stw       r3, 0x108(r1)
	  lwz       r0, 0x108(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x100
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x108(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x108(r1)
	  subi      r4, r4, 0xE10
	  stw       r0, 0x0(r3)
	  li        r0, 0x1
	  lwz       r3, 0x108(r1)
	  stw       r4, 0x4(r3)
	  lwz       r3, 0x108(r1)
	  stb       r0, 0x8(r3)

	.loc_0x100:
	  li        r3, 0x8
	  bl        -0x186D1C
	  stw       r3, 0x104(r1)
	  lwz       r0, 0x104(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x144
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x104(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x104(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6EC
	  lwz       r3, 0x104(r1)
	  stw       r0, 0x4(r3)

	.loc_0x144:
	  li        r3, 0xC
	  bl        -0x186D60
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x170
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x2109C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x720
	  stw       r0, 0x4(r24)

	.loc_0x170:
	  li        r3, 0x10
	  bl        -0x186D8C
	  stw       r3, 0x100(r1)
	  lwz       r3, 0x100(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x1B0
	  li        r4, -0x1
	  li        r5, 0x4
	  bl        -0x21158
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  lwz       r3, 0x100(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x100(r1)
	  lfs       f0, -0x4448(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x1B0:
	  li        r3, 0x8
	  bl        -0x186DCC
	  stw       r3, 0xFC(r1)
	  lwz       r0, 0xFC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xFC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0xFC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xEC
	  lwz       r3, 0xFC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x1F4:
	  li        r3, 0x8
	  bl        -0x186E10
	  cmplwi    r3, 0
	  beq-      .loc_0x224
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lis       r4, 0x802E
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x124
	  stw       r0, 0x4(r3)

	.loc_0x224:
	  li        r3, 0x14
	  bl        -0x186E40
	  stw       r3, 0xF8(r1)
	  lwz       r3, 0xF8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x280
	  li        r4, 0x3
	  li        r5, 0x4
	  bl        -0x2120C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  lwz       r3, 0xF8(r1)
	  stw       r0, 0x4(r3)
	  lis       r3, 0x802E
	  subi      r4, r3, 0x3EC
	  lwz       r3, 0xF8(r1)
	  lfs       f0, -0x4400(r2)
	  li        r0, 0x1
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0xF8(r1)
	  stw       r4, 0x4(r3)
	  lwz       r3, 0xF8(r1)
	  stb       r0, 0x10(r3)

	.loc_0x280:
	  li        r3, 0x8
	  bl        -0x186E9C
	  stw       r3, 0xF4(r1)
	  lwz       r0, 0xF4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xF4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x4
	  lwz       r3, 0xF4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x510
	  lwz       r3, 0xF4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2C4:
	  li        r3, 0xC
	  bl        -0x186EE0
	  stw       r3, 0xF0(r1)
	  lwz       r3, 0xF0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  li        r4, 0x3
	  li        r5, 0x6
	  bl        -0x21220
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0xF0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2F8:
	  li        r3, 0x8
	  bl        -0x186F14
	  stw       r3, 0xEC(r1)
	  lwz       r0, 0xEC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x33C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xEC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x5
	  lwz       r3, 0xEC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xEC
	  lwz       r3, 0xEC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x33C:
	  li        r3, 0x8
	  bl        -0x186F58
	  stw       r3, 0xE8(r1)
	  lwz       r0, 0xE8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x380
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xE8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x5
	  lwz       r3, 0xE8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x124
	  lwz       r3, 0xE8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x380:
	  li        r3, 0xC
	  bl        -0x186F9C
	  stw       r3, 0xE4(r1)
	  lwz       r3, 0xE4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x3B4
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x212DC
	  lis       r3, 0x802E
	  subi      r0, r3, 0x638
	  lwz       r3, 0xE4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x3B4:
	  li        r3, 0x8
	  bl        -0x186FD0
	  stw       r3, 0xE0(r1)
	  lwz       r0, 0xE0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x3F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xE0(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x6
	  lwz       r3, 0xE0(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x160
	  lwz       r3, 0xE0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x3F8:
	  li        r3, 0x8
	  bl        -0x187014
	  stw       r3, 0xDC(r1)
	  lwz       r0, 0xDC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x43C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xDC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lwz       r3, 0xDC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1A0
	  lwz       r3, 0xDC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x43C:
	  li        r3, 0x14
	  bl        -0x187058
	  stw       r3, 0xD8(r1)
	  lwz       r3, 0xD8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x498
	  li        r4, 0x7
	  li        r5, 0xA
	  bl        -0x21398
	  lis       r3, 0x802E
	  addi      r0, r3, 0x298
	  lwz       r3, 0xD8(r1)
	  li        r5, 0x3
	  stw       r0, 0x4(r3)
	  li        r0, 0x7
	  lwz       r3, 0xD8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0xC(r3)
	  addi      r0, r4, 0x36D8
	  lwz       r3, 0xD8(r1)
	  stw       r5, 0x10(r3)
	  lwz       r3, 0xD8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x498:
	  li        r3, 0xC
	  bl        -0x1870B4
	  stw       r3, 0xD4(r1)
	  lwz       r3, 0xD4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x4CC
	  li        r4, 0x3
	  li        r5, 0xB
	  bl        -0x213F4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x250
	  lwz       r3, 0xD4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x4CC:
	  li        r3, 0x8
	  bl        -0x1870E8
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x518
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0x8
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  addi      r0, r3, 0x3660
	  lis       r3, 0x802E
	  stw       r0, 0x4(r21)
	  addi      r0, r3, 0x188
	  lis       r3, 0x802E
	  stw       r0, 0x4(r21)
	  addi      r0, r3, 0x3640
	  stw       r0, 0x4(r21)

	.loc_0x518:
	  li        r3, 0x14
	  bl        -0x187134
	  stw       r3, 0xD0(r1)
	  lwz       r3, 0xD0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x578
	  li        r4, 0x9
	  li        r5, 0xC
	  bl        -0x21474
	  lis       r3, 0x802E
	  addi      r0, r3, 0x35CC
	  lwz       r3, 0xD0(r1)
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x600
	  lwz       r3, 0xD0(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x10(r3)
	  addi      r0, r4, 0x358C
	  lwz       r3, 0xD0(r1)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0xD0(r1)
	  lfs       f0, -0x43DC(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x578:
	  li        r3, 0xC
	  bl        -0x187194
	  stw       r3, 0xCC(r1)
	  lwz       r0, 0xCC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xCC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0xCC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xA04
	  lwz       r3, 0xCC(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0xCC(r1)
	  lfs       f0, -0x43D8(r2)
	  stfs      f0, 0x8(r3)

	.loc_0x5C8:
	  li        r3, 0x8
	  bl        -0x1871E4
	  stw       r3, 0xC8(r1)
	  lwz       r0, 0xC8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x61C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xC8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0xC8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x9CC
	  lwz       r3, 0xC8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x351C
	  lwz       r3, 0xC8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x61C:
	  li        r3, 0xC
	  bl        -0x187238
	  stw       r3, 0xC4(r1)
	  lwz       r3, 0xC4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x650
	  li        r4, -0x1
	  li        r5, 0x3
	  bl        -0x21578
	  lis       r3, 0x802E
	  addi      r0, r3, 0x34B8
	  lwz       r3, 0xC4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x650:
	  li        r3, 0x8
	  bl        -0x18726C
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x690
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0xC74
	  lis       r3, 0x802E
	  stw       r0, 0x4(r20)
	  addi      r0, r3, 0x346C
	  stw       r0, 0x4(r20)

	.loc_0x690:
	  li        r3, 0x8
	  bl        -0x1872AC
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x6DC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  addi      r0, r3, 0x3660
	  lis       r3, 0x802E
	  stw       r0, 0x4(r19)
	  addi      r0, r3, 0x144
	  lis       r3, 0x802E
	  stw       r0, 0x4(r19)
	  addi      r0, r3, 0x33F8
	  stw       r0, 0x4(r19)

	.loc_0x6DC:
	  li        r3, 0xC
	  bl        -0x1872F8
	  stw       r3, 0xC0(r1)
	  lwz       r3, 0xC0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x710
	  li        r4, 0x3
	  li        r5, 0xD
	  bl        -0x21638
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3368
	  lwz       r3, 0xC0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x710:
	  li        r3, 0x8
	  bl        -0x18732C
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x744
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0xB
	  lis       r3, 0x802E
	  stw       r0, 0x0(r23)
	  subi      r0, r3, 0xC74
	  stw       r0, 0x4(r23)

	.loc_0x744:
	  li        r3, 0x10
	  bl        -0x187360
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0x790
	  li        r4, -0x1
	  li        r5, 0x1
	  bl        -0x21728
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lis       r3, 0x802E
	  stw       r0, 0x4(r17)
	  subi      r0, r3, 0xD30
	  stw       r0, 0x4(r17)
	  li        r0, 0x44
	  lis       r3, 0x802E
	  stw       r0, 0xC(r17)
	  subi      r0, r3, 0xD4C
	  stw       r0, 0x4(r17)

	.loc_0x790:
	  li        r3, 0x8
	  bl        -0x1873AC
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x7C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, 0xC
	  lis       r3, 0x802E
	  stw       r0, 0x0(r22)
	  addi      r0, r3, 0x1CC
	  stw       r0, 0x4(r22)

	.loc_0x7C4:
	  li        r3, 0x8
	  bl        -0x1873E0
	  stw       r3, 0xBC(r1)
	  lwz       r0, 0xBC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x808
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xBC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2540
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x808:
	  li        r3, 0x8
	  bl        -0x187424
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x83C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r24)
	  addi      r0, r3, 0x1B60
	  stw       r0, 0x4(r24)

	.loc_0x83C:
	  li        r3, 0x8
	  bl        -0x187458
	  stw       r3, 0xB8(r1)
	  lwz       r0, 0xB8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x880
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xB8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xD
	  lwz       r3, 0xB8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x478
	  lwz       r3, 0xB8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x880:
	  li        r3, 0xC
	  bl        -0x18749C
	  stw       r3, 0xB4(r1)
	  lwz       r3, 0xB4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x8B4
	  li        r4, 0xE
	  li        r5, 0x6
	  bl        -0x217DC
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x8B4:
	  li        r3, 0x14
	  bl        -0x1874D0
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x8FC
	  li        r4, 0x4
	  li        r5, 0x6
	  bl        -0x2180C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x588
	  stw       r0, 0x4(r14)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0xC(r14)
	  li        r0, 0x8
	  addi      r3, r3, 0x32A0
	  stw       r0, 0x10(r14)
	  stw       r3, 0x4(r14)

	.loc_0x8FC:
	  li        r3, 0x8
	  bl        -0x187518
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x930
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  addi      r0, r3, 0x1CC
	  stw       r0, 0x4(r25)

	.loc_0x930:
	  li        r3, 0xC
	  bl        -0x18754C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x978
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xF
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r27)
	  addi      r0, r3, 0x31D8
	  lfs       f0, -0x4424(r2)
	  stfs      f0, 0x8(r27)
	  stw       r0, 0x4(r27)

	.loc_0x978:
	  li        r3, 0x14
	  bl        -0x187594
	  addi      r15, r3, 0
	  mr.       r3, r15
	  beq-      .loc_0x9C0
	  li        r4, 0x10
	  li        r5, 0x5
	  bl        -0x2195C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  stw       r0, 0x4(r15)
	  lis       r3, 0x802E
	  subi      r3, r3, 0x3EC
	  lfs       f0, -0x4400(r2)
	  li        r0, 0
	  stfs      f0, 0xC(r15)
	  stw       r3, 0x4(r15)
	  stb       r0, 0x10(r15)

	.loc_0x9C0:
	  li        r3, 0xC
	  bl        -0x1875DC
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0xA08
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r18)
	  addi      r0, r3, 0x3190
	  lfs       f0, -0x4424(r2)
	  stfs      f0, 0x8(r18)
	  stw       r0, 0x4(r18)

	.loc_0xA08:
	  li        r3, 0x8
	  bl        -0x187624
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0xA3C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  addi      r0, r3, 0x2348
	  stw       r0, 0x4(r26)

	.loc_0xA3C:
	  li        r3, 0x8
	  bl        -0x187658
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0xA70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  addi      r0, r3, 0x2310
	  stw       r0, 0x4(r16)

	.loc_0xA70:
	  li        r3, 0x10
	  bl        -0x18768C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xAC0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0xE44
	  lis       r3, 0x802E
	  stw       r0, 0x4(r30)
	  subi      r3, r3, 0xE60
	  li        r0, 0x1
	  stw       r3, 0x4(r30)
	  lfs       f0, -0x442C(r2)
	  stfs      f0, 0x8(r30)
	  stb       r0, 0xC(r30)

	.loc_0xAC0:
	  li        r3, 0xC
	  bl        -0x1876DC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xADC
	  li        r4, 0x2
	  bl        -0xA765C

	.loc_0xADC:
	  li        r0, 0
	  lwz       r4, 0x8(r29)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x10C(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x104(r1)
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x0(r4)
	  bl        -0x187728
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xB28
	  li        r4, 0x5
	  bl        -0xA76A8

	.loc_0xB28:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xBC(r1)
	  lwz       r5, 0x8(r29)
	  li        r3, 0x2
	  stwx      r0, r5, r4
	  li        r6, 0x3
	  li        r0, 0x4
	  rlwinm    r5,r6,2,0,29
	  lwz       r4, 0x8(r29)
	  rlwinm    r6,r0,2,0,29
	  lwz       r0, 0x100(r1)
	  rlwinm    r3,r3,2,0,29
	  stwx      r0, r4, r3
	  li        r3, 0xC
	  lwz       r0, 0xFC(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r25, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x4(r4)
	  bl        -0x1877A8
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xBA8
	  li        r4, 0x2
	  bl        -0xA7728

	.loc_0xBA8:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r26, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xF8(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x8(r4)
	  bl        -0x1877F0
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xBF0
	  li        r4, 0x2
	  bl        -0xA7770

	.loc_0xBF0:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xF4(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0xC(r4)
	  bl        -0x187838
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xC38
	  li        r4, 0xA
	  bl        -0xA77B8

	.loc_0xC38:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r5, 0x2
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x108(r1)
	  stwx      r23, r3, r4
	  li        r0, 0x3
	  lwz       r4, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x4
	  stwx      r5, r4, r6
	  li        r6, 0x9
	  li        r8, 0x5
	  lwz       r7, 0x8(r29)
	  li        r9, 0x6
	  li        r4, 0x7
	  stwx      r28, r7, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r7,r8,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r8,r9,2,0,29
	  li        r5, 0x8
	  stwx      r21, r3, r0
	  rlwinm    r9,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0xF0(r1)
	  lwz       r4, 0x8(r29)
	  rlwinm    r6,r6,2,0,29
	  stwx      r5, r4, r7
	  li        r3, 0xC
	  lwz       r5, 0xE8(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r5, r4, r8
	  lwz       r5, 0xEC(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r5, r4, r9
	  lwz       r4, 0x8(r29)
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r29)
	  stwx      r27, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x10(r4)
	  bl        -0x18790C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xD0C
	  li        r4, 0xA
	  bl        -0xA788C

	.loc_0xD0C:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x108(r1)
	  stwx      r23, r3, r0
	  li        r0, 0x5
	  lwz       r3, 0x8(r29)
	  li        r9, 0x6
	  li        r8, 0x7
	  stwx      r5, r3, r6
	  li        r4, 0x3
	  rlwinm    r5,r4,2,0,29
	  lwz       r6, 0x8(r29)
	  li        r7, 0x4
	  li        r4, 0x9
	  stwx      r28, r6, r5
	  rlwinm    r5,r7,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r6, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r9,r9,2,0,29
	  stwx      r21, r6, r5
	  li        r3, 0x8
	  rlwinm    r5,r3,2,0,29
	  lwz       r6, 0xE4(r1)
	  lwz       r4, 0x8(r29)
	  rlwinm    r8,r8,2,0,29
	  stwx      r6, r4, r0
	  li        r3, 0xC
	  lwz       r0, 0xE0(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r9
	  lwz       r0, 0xDC(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r8
	  lwz       r0, 0xE8(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r5
	  lwz       r0, 0xEC(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r7
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x14(r4)
	  bl        -0x1879E8
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xDE8
	  li        r4, 0x3
	  bl        -0xA7968

	.loc_0xDE8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r5,r4,2,0,29
	  stwx      r23, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0xD8(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x18(r4)
	  bl        -0x187A40
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xE40
	  li        r4, 0x4
	  bl        -0xA79C0

	.loc_0xE40:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x104(r1)
	  lwz       r4, 0x8(r27)
	  li        r5, 0x2
	  stwx      r0, r4, r3
	  rlwinm    r0,r5,2,0,29
	  li        r6, 0x3
	  lwz       r4, 0x8(r27)
	  rlwinm    r5,r6,2,0,29
	  li        r3, 0xC
	  stwx      r23, r4, r0
	  lwz       r0, 0xD4(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x1C(r4)
	  bl        -0x187AAC
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xEAC
	  li        r4, 0x4
	  bl        -0xA7A2C

	.loc_0xEAC:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r5, 0x2
	  li        r0, 0x3
	  stwx      r20, r4, r3
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xD0(r1)
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x20(r4)
	  bl        -0x187B14
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xF14
	  li        r4, 0x7
	  bl        -0xA7A94

	.loc_0xF14:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r5,r0,2,0,29
	  stwx      r20, r3, r4
	  li        r4, 0x5
	  li        r0, 0x6
	  lwz       r6, 0x8(r29)
	  li        r7, 0x3
	  li        r3, 0x4
	  stwx      r19, r6, r5
	  rlwinm    r6,r7,2,0,29
	  rlwinm    r5,r3,2,0,29
	  lwz       r7, 0xC8(r1)
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  stwx      r7, r3, r6
	  rlwinm    r0,r0,2,0,29
	  lwz       r7, 0xCC(r1)
	  li        r3, 0xC
	  lwz       r6, 0x8(r29)
	  stwx      r7, r6, r5
	  lwz       r6, 0xC4(r1)
	  lwz       r5, 0x8(r29)
	  stwx      r6, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x24(r4)
	  bl        -0x187BB4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xFB4
	  li        r4, 0x4
	  bl        -0xA7B34

	.loc_0xFB4:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r5, 0x2
	  li        r0, 0x3
	  stwx      r20, r4, r3
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xC0(r1)
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x28(r4)
	  bl        -0x187C1C
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x101C
	  li        r4, 0x2
	  bl        -0xA7B9C

	.loc_0x101C:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r17, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x104(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x2C(r4)
	  bl        -0x187C64
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x1064
	  li        r4, 0x1
	  bl        -0xA7BE4

	.loc_0x1064:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xB8(r1)
	  stwx      r0, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x30(r4)
	  bl        -0x187C9C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x109C
	  li        r4, 0x8
	  bl        -0xA7C1C

	.loc_0x109C:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r6,r4,2,0,29
	  lwz       r4, 0x108(r1)
	  lwz       r3, 0x8(r29)
	  li        r5, 0x3
	  stwx      r4, r3, r6
	  li        r0, 0x2
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r7, 0x4
	  li        r6, 0x5
	  stwx      r28, r3, r4
	  li        r4, 0x7
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r0, 0x6
	  rlwinm    r7,r7,2,0,29
	  stwx      r21, r3, r5
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xE8(r1)
	  rlwinm    r6,r6,2,0,29
	  lwz       r8, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  stwx      r0, r8, r7
	  li        r3, 0xC
	  lwz       r0, 0xEC(r1)
	  lwz       r7, 0x8(r29)
	  stwx      r0, r7, r6
	  lwz       r0, 0xB4(r1)
	  lwz       r6, 0x8(r29)
	  stwx      r23, r6, r5
	  lwz       r5, 0x8(r29)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x34(r4)
	  bl        -0x187D50
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1150
	  li        r4, 0x8
	  bl        -0xA7CD0

	.loc_0x1150:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x108(r1)
	  lwz       r3, 0x8(r29)
	  li        r5, 0x2
	  stwx      r0, r3, r4
	  rlwinm    r6,r5,2,0,29
	  li        r7, 0x3
	  lwz       r3, 0x8(r29)
	  li        r0, 0x4
	  li        r4, 0x5
	  stwx      r28, r3, r6
	  li        r6, 0x7
	  li        r5, 0x6
	  lwz       r3, 0x8(r29)
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r8,r6,2,0,29
	  stwx      r21, r3, r7
	  rlwinm    r0,r0,2,0,29
	  lwz       r7, 0xE8(r1)
	  rlwinm    r4,r4,2,0,29
	  lwz       r6, 0x8(r29)
	  rlwinm    r5,r5,2,0,29
	  stwx      r7, r6, r0
	  li        r3, 0xC
	  lwz       r0, 0xEC(r1)
	  lwz       r6, 0x8(r29)
	  stwx      r0, r6, r4
	  lwz       r4, 0x8(r29)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r14, r4, r8
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x38(r4)
	  bl        -0x187E00
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1200
	  li        r4, 0x3
	  bl        -0xA7D80

	.loc_0x1200:
	  li        r0, 0
	  lwz       r4, 0x8(r27)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xBC(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r15, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x104(r1)
	  lwz       r5, 0x8(r27)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x3C(r4)
	  bl        -0x187E5C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x125C
	  li        r4, 0x2
	  bl        -0xA7DDC

	.loc_0x125C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  mr        r3, r31
	  stwx      r18, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x40(r4)
	  lwz       r0, 0x15C(r1)
	  lmw       r14, 0x110(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CEEB8
 * Size:	0006FC
 */
void TAIkabekuiCAnimation::makeDefaultAnimations()
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
	  addi      r30, r3, 0x2E00
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0x11C
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x2B96C
	  addi      r3, r31, 0
	  addi      r4, r30, 0x13C
	  bl        -0x2B978
	  addi      r3, r31, 0
	  addi      r4, r30, 0x160
	  bl        -0x2B984
	  li        r3, 0x10
	  bl        -0x187F1C
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
	  bl        -0x187F64
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
	  addi      r4, r30, 0x180
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BA24
	  li        r3, 0x10
	  bl        -0x187FBC
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
	  bl        -0x188004
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
	  addi      r4, r30, 0x1A0
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BAC4
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17ECA0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17E858
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17E870
	  li        r3, 0x10
	  bl        -0x188098
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
	  bl        -0x1880E4
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
	  addi      r4, r30, 0x1C4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BBA8
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17ED84
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17E93C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17E954
	  li        r3, 0x10
	  bl        -0x18817C
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
	  bl        -0x1881C8
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
	  addi      r4, r30, 0x1E8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BC8C
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17EE68
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EA20
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EA38
	  li        r3, 0x10
	  bl        -0x188260
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
	  bl        -0x1882AC
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
	  addi      r4, r30, 0x208
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BD70
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17EF4C
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EB04
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EB1C
	  li        r3, 0x10
	  bl        -0x188344
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
	  bl        -0x188390
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
	  addi      r4, r30, 0x228
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BE54
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EBDC
	  li        r3, 0x10
	  bl        -0x188404
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
	  addi      r4, r30, 0x24C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BEC8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EC50
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17EC68
	  li        r3, 0x10
	  bl        -0x188490
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
	  bl        -0x1884DC
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
	  addi      r4, r30, 0x26C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2BFA0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17ED28
	  li        r3, 0x10
	  bl        -0x188550
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
 * Address:	801CF5B4
 * Size:	000018
 */
f32 TAIAsleepKabekuiC::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xE4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CF5CC
 * Size:	000018
 */
f32 TAIAdiveKabekuiC::getFrameMax(Teki&)
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
 * Address:	801CF5E4
 * Size:	000020
 */
void TAIAattackWorkObjectKabekuiC::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x21454
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CF604
 * Size:	000020
 */
bool TAIAattackWorkObjectKabekuiC::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x21438
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CF624
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiC::getDamage(Teki&)
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
 * Address:	801CF63C
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiC::getAttackPointRadius(Teki&)
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
 * Address:	801CF654
 * Size:	00016C
 */
void TAIAattackWorkObjectKabekuiC::attackEffect(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  lis       r4, 0x736C
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6F74
	  bl        -0x145F68
	  mr.       r31, r3
	  beq-      .loc_0x154
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD4
	  mr        r3, r31
	  bl        -0x147904
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  subi      r4, r4, 0x1
	  bl        -0x1478B8
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x4F
	  li        r6, 0
	  li        r7, 0
	  bl        -0x32B88
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  lfs       f0, 0x1F28(r13)
	  lfs       f1, 0x1F2C(r13)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x1F30(r13)
	  stfs      f1, 0x24(r1)
	  stfs      f0, 0x28(r1)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0xA8:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x7E
	  bl        -0x145154
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0xD4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x34
	  addi      r3, r3, 0x70
	  bl        -0x14BD24

	.loc_0xD4:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x154
	  cmpwi     r0, 0x3
	  bne-      .loc_0x154
	  mr        r3, r31
	  bl        -0x1479B0
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  subi      r4, r4, 0x1
	  bl        -0x147964
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x50
	  li        r6, 0
	  li        r7, 0
	  bl        -0x32C34
	  cmplwi    r3, 0
	  beq-      .loc_0x154
	  lfs       f0, 0x1F34(r13)
	  lfs       f1, 0x1F38(r13)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x1F3C(r13)
	  stfs      f1, 0x18(r1)
	  stfs      f0, 0x1C(r1)
	  lwz       r4, 0x14(r1)
	  lwz       r0, 0x18(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x154:
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
 * Address:	801CF7C0
 * Size:	000068
 */
void TAIAlandingKabekuiC::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x22AD0
	  lwz       r0, 0xC8(r31)
	  li        r3, 0x1
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  lbz       r0, 0x4C8(r31)
	  rlwimi    r0,r3,3,28,28
	  stb       r0, 0x4C8(r31)
	  lfs       f0, -0x4448(r2)
	  stfs      f0, 0x4C0(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CF828
 * Size:	0001E4
 */
bool TAIAlandingKabekuiC::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stw       r31, 0x74(r1)
	  li        r31, 0
	  stw       r30, 0x70(r1)
	  addi      r30, r4, 0
	  bl        -0x22994
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C0
	  lbz       r0, 0x4C8(r30)
	  rlwinm.   r0,r0,29,31,31
	  beq-      .loc_0xB0
	  lwz       r4, 0x2C4(r30)
	  mr        r3, r30
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f30, 0xC(r4)
	  bl        -0x86EE8
	  lfs       f2, 0xA8(r30)
	  lfs       f3, -0x443C(r2)
	  lfs       f0, -0x43D4(r2)
	  fmuls     f2, f2, f3
	  fsubs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fdivs     f0, f0, f3
	  stfs      f0, 0x4C0(r30)
	  lfs       f1, 0xA0(r30)
	  bl        0x4C2B0
	  lfs       f0, 0xA0(r30)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x4C434
	  fmuls     f1, f30, f1
	  li        r3, 0
	  fmuls     f0, f30, f31
	  stfs      f1, 0xA4(r30)
	  stfs      f0, 0xAC(r30)
	  lbz       r0, 0x4C8(r30)
	  rlwimi    r0,r3,3,28,28
	  stb       r0, 0x4C8(r30)

	.loc_0xB0:
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0x168
	  mr        r3, r30
	  bl        -0x86F54
	  lfs       f0, -0x4420(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x14C
	  lfs       f0, 0x94(r30)
	  li        r4, 0x1
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x64(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x5C(r1)
	  lfs       f2, 0x64(r1)
	  bl        -0x167A1C
	  stfs      f1, 0x60(r1)
	  addi      r5, r1, 0x5C
	  li        r4, 0x44
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x32E04
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC8(r30)
	  lfs       f0, 0xA4(r30)
	  lfs       f1, -0x43D0(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0xAC(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xAC(r30)

	.loc_0x14C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4C0(r30)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0xA8(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xA8(r30)

	.loc_0x168:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x1A8
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x78
	  bl        -0x1453BC
	  lwz       r0, 0xC8(r30)
	  li        r31, 0x1
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC8(r30)
	  lfs       f0, -0x4448(r2)
	  stfs      f0, 0xA8(r30)

	.loc_0x1A8:
	  lwz       r3, 0xA4(r30)
	  lwz       r0, 0xA8(r30)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0xAC(r30)
	  stw       r0, 0x78(r30)

	.loc_0x1C0:
	  mr        r3, r31
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFA0C
 * Size:	000018
 */
f32 TAIAmoreLifeKabekuiC::getLifePercentThreshold(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFA24
 * Size:	000008
 */
bool TAIAcheckPikiFlyKabekuiC::act(Teki&)
{
	return false;
}

/*
 * --INFO--
 * Address:	801CFA2C
 * Size:	00003C
 */
void TAIAflyingMotionKabekuiC::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x22D3C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x78
	  bl        -0x14549C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFA68
 * Size:	00003C
 */
f32 TAIAflyingBaseKabekuiC::getFlyingStayVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x4C8(r4)
	  rlwinm.   r0,r0,31,31,31
	  beq-      .loc_0x24
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD8(r3)
	  blr

	.loc_0x24:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xDC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFAA4
 * Size:	000028
 */
bool rippleEffect::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  lha       r3, 0x1C8(r4)
	  lha       r5, 0x90(r4)
	  subi      r0, r3, 0x1
	  cmpw      r5, r0
	  blt-      .loc_0x20
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x20:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFACC
 * Size:	0000C8
 */
void TAIAtakeOffKabekuiC::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  bl        -0x22DE4
	  lwz       r0, 0xC8(r31)
	  li        r4, 0x1D
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  lfs       f0, 0x1F40(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1F44(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x1F48(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xAD67C
	  lfs       f0, -0x43D4(r2)
	  li        r3, 0
	  lfs       f2, 0xC(r30)
	  fmuls     f1, f0, f1
	  fmuls     f0, f2, f2
	  fdivs     f0, f1, f0
	  stfs      f0, 0x4C0(r31)
	  lbz       r0, 0x4C8(r31)
	  rlwimi    r0,r3,3,28,28
	  stb       r0, 0x4C8(r31)
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
 * Address:	801CFB94
 * Size:	000230
 */
bool TAIAtakeOffKabekuiC::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stfd      f29, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x78(r1)
	  stw       r29, 0x74(r1)
	  addi      r29, r3, 0
	  bl        -0x22D08
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x204
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x17C
	  lwz       r4, 0x2C4(r31)
	  li        r3, 0x1
	  lbz       r0, 0x4C8(r31)
	  rlwimi    r0,r3,3,28,28
	  lwz       r3, 0x84(r4)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0xC(r3)
	  stb       r0, 0x4C8(r31)
	  lfs       f2, 0xC(r29)
	  lfs       f0, 0x4C0(r31)
	  lfs       f1, 0xA0(r31)
	  fmuls     f29, f2, f0
	  bl        0x4BF48
	  lfs       f0, 0xA0(r31)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x4C0CC
	  fmuls     f1, f30, f1
	  addi      r30, r31, 0x94
	  fmuls     f0, f30, f31
	  li        r4, 0x1
	  stfs      f1, 0xA4(r31)
	  stfs      f29, 0xA8(r31)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x167A70
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  bl        -0xB9BD4
	  cmpwi     r3, 0x5
	  bne-      .loc_0x17C
	  lfs       f0, -0x4448(r2)
	  mr        r5, r30
	  li        r4, 0xF
	  stfs      f0, 0x5C(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x3314C
	  lfs       f0, 0x0(r30)
	  li        r4, 0x1
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x5C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x54(r1)
	  lfs       f2, 0x5C(r1)
	  bl        -0x167DAC
	  stfs      f1, 0x58(r1)
	  addi      r5, r1, 0x54
	  addi      r6, r29, 0x10
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xE
	  li        r7, 0
	  bl        -0x33194
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x54
	  addi      r6, r29, 0x10
	  li        r4, 0xD
	  li        r7, 0
	  bl        -0x331AC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x54
	  addi      r6, r29, 0x10
	  li        r4, 0xC
	  li        r7, 0
	  bl        -0x331C4
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xA7
	  bl        -0x145758

	.loc_0x17C:
	  lbz       r0, 0x4C8(r31)
	  rlwinm.   r0,r0,29,31,31
	  beq-      .loc_0x1C0
	  lfs       f0, 0x4C0(r31)
	  lwz       r3, 0x2DEC(r13)
	  fneg      f1, f0
	  lfs       f2, 0xA8(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xA8(r31)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)

	.loc_0x1C0:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x1FC
	  lfs       f1, 0xA8(r31)
	  li        r3, 0x1
	  lfs       f0, -0x43CC(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xA8(r31)
	  lwz       r4, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  b         .loc_0x208

	.loc_0x1FC:
	  li        r3, 0
	  b         .loc_0x208

	.loc_0x204:
	  li        r3, 0

	.loc_0x208:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFDC4
 * Size:	000018
 */
f32 TAIAlessLifeKabekuiC::getLifePercentThreshold(Teki&)
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
 * Address:	801CFDDC
 * Size:	000018
 */
f32 TAIAbiteForKabekuiC::getPikiAttackSize(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xE8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CFDF4
 * Size:	000018
 */
f32 TAIAbiteForKabekuiC::getNaviAttackSize(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xEC(r3)
	  blr
	*/
}
