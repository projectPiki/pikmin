#include "TAI/KabekuiB.h"

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
 * Address:	801CBB68
 * Size:	000084
 */
TAIkabekuiBSoundTable::TAIkabekuiBSoundTable()
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
	  bl        -0xACB14
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x184B98
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
 * Address:	801CBBEC
 * Size:	0003C0
 */
TAIkabekuiBParameters::TAIkabekuiBParameters()
    : TekiParameters(20, 56)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x38
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  addi      r31, r4, 0x2710
	  li        r4, 0x14
	  stw       r30, 0xD0(r1)
	  addi      r30, r3, 0
	  bl        -0x7FECC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2DCC
	  stw       r0, 0x0(r30)
	  li        r7, 0x32
	  li        r6, 0x33
	  lwz       r4, 0x84(r30)
	  li        r5, 0x34
	  li        r3, 0x35
	  lwz       r8, 0x4(r4)
	  li        r0, 0x36
	  mulli     r7, r7, 0xC
	  lwz       r10, 0x8(r8)
	  add       r8, r10, r7
	  addi      r7, r31, 0x1C
	  stw       r7, 0x0(r8)
	  mulli     r7, r6, 0xC
	  lfs       f2, -0x44A8(r2)
	  mulli     r6, r5, 0xC
	  stfs      f2, 0x4(r8)
	  lfs       f0, -0x44A4(r2)
	  mulli     r5, r3, 0xC
	  stfs      f0, 0x8(r8)
	  add       r7, r10, r7
	  addi      r3, r31, 0x34
	  stw       r3, 0x0(r7)
	  mulli     r3, r0, 0xC
	  stfs      f2, 0x4(r7)
	  li        r0, 0x37
	  lfs       f1, -0x44A0(r2)
	  mulli     r0, r0, 0xC
	  stfs      f1, 0x8(r7)
	  add       r7, r10, r6
	  addi      r6, r31, 0x44
	  stw       r6, 0x0(r7)
	  add       r8, r10, r5
	  addi      r5, r31, 0x5C
	  stfs      f2, 0x4(r7)
	  add       r9, r10, r3
	  addi      r6, r31, 0x70
	  stfs      f1, 0x8(r7)
	  add       r7, r10, r0
	  addi      r3, r31, 0x84
	  stw       r5, 0x0(r8)
	  li        r0, 0x1
	  li        r5, -0x1
	  stfs      f2, 0x4(r8)
	  stfs      f1, 0x8(r8)
	  stw       r6, 0x0(r9)
	  stfs      f2, 0x4(r9)
	  stfs      f1, 0x8(r9)
	  stw       r3, 0x0(r7)
	  stfs      f2, 0x4(r7)
	  stfs      f1, 0x8(r7)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x449C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x4498(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4494(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4490(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xDC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  li        r8, 0x5
	  li        r7, 0x2
	  lwz       r3, 0x0(r3)
	  li        r6, 0xA
	  li        r5, 0x3
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
	  stfs      f1, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x448C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4488(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x4484(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4480(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x447C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4478(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4474(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x4470(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x446C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4468(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4464(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4460(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x40(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lfs       f0, -0x445C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x78(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4458(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x7C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f2, -0x4454(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f1, -0x4450(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x444C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x54(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x98(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f4, 0x4C(r4)
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
 * Address:	801CBFAC
 * Size:	000E3C
 */
TAIkabekuiBStrategy::TAIkabekuiBStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xE
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x118(r1)
	  stmw      r14, 0xD0(r1)
	  addi      r31, r3, 0
	  bl        0x1D68C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2D10
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x184FD8
	  stw       r3, 0xCC(r1)
	  lwz       r0, 0xCC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xCC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lwz       r3, 0xCC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xCB4
	  lwz       r3, 0xCC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x70:
	  li        r3, 0x10
	  bl        -0x18501C
	  stw       r3, 0xC8(r1)
	  lwz       r3, 0xC8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x1F3E8
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0xC8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0xD30
	  lwz       r3, 0xC8(r1)
	  stw       r0, 0x4(r3)
	  li        r0, 0x44
	  lwz       r3, 0xC8(r1)
	  stw       r0, 0xC(r3)

	.loc_0xC0:
	  li        r3, 0xC
	  bl        -0x18506C
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0xFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r23)
	  subi      r3, r3, 0xE10
	  li        r0, 0x1
	  stw       r3, 0x4(r23)
	  stb       r0, 0x8(r23)

	.loc_0xFC:
	  li        r3, 0x8
	  bl        -0x1850A8
	  stw       r3, 0xC4(r1)
	  lwz       r0, 0xC4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x140
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xC4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0xC4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6EC
	  lwz       r3, 0xC4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x140:
	  li        r3, 0xC
	  bl        -0x1850EC
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x16C
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x1F428
	  lis       r3, 0x802E
	  subi      r0, r3, 0x720
	  stw       r0, 0x4(r24)

	.loc_0x16C:
	  li        r3, 0x10
	  bl        -0x185118
	  stw       r3, 0xC0(r1)
	  lwz       r3, 0xC0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x1AC
	  li        r4, -0x1
	  li        r5, 0x4
	  bl        -0x1F4E4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  lwz       r3, 0xC0(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0xC0(r1)
	  lfs       f0, -0x44A8(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x1AC:
	  li        r3, 0x8
	  bl        -0x185158
	  stw       r3, 0xBC(r1)
	  lwz       r0, 0xBC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xBC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xEC
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x1F0:
	  li        r3, 0x8
	  bl        -0x18519C
	  cmplwi    r3, 0
	  beq-      .loc_0x220
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lis       r4, 0x802E
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x124
	  stw       r0, 0x4(r3)

	.loc_0x220:
	  li        r3, 0x14
	  bl        -0x1851CC
	  stw       r3, 0xB8(r1)
	  lwz       r3, 0xB8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x27C
	  li        r4, 0x3
	  li        r5, 0x4
	  bl        -0x1F598
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  lwz       r3, 0xB8(r1)
	  stw       r0, 0x4(r3)
	  lis       r3, 0x802E
	  subi      r4, r3, 0x3EC
	  lwz       r3, 0xB8(r1)
	  lfs       f0, -0x446C(r2)
	  li        r0, 0x1
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0xB8(r1)
	  stw       r4, 0x4(r3)
	  lwz       r3, 0xB8(r1)
	  stb       r0, 0x10(r3)

	.loc_0x27C:
	  li        r3, 0x8
	  bl        -0x185228
	  stw       r3, 0xB4(r1)
	  lwz       r0, 0xB4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xB4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x4
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x510
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2C0:
	  li        r3, 0xC
	  bl        -0x18526C
	  stw       r3, 0xB0(r1)
	  lwz       r3, 0xB0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F4
	  li        r4, 0x3
	  li        r5, 0x6
	  bl        -0x1F5AC
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0xB0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2F4:
	  li        r3, 0x8
	  bl        -0x1852A0
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x328
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0xEC
	  stw       r0, 0x4(r21)

	.loc_0x328:
	  li        r3, 0x8
	  bl        -0x1852D4
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x35C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x124
	  stw       r0, 0x4(r22)

	.loc_0x35C:
	  li        r3, 0xC
	  bl        -0x185308
	  stw       r3, 0xAC(r1)
	  lwz       r3, 0xAC(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x390
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x1F648
	  lis       r3, 0x802E
	  subi      r0, r3, 0x638
	  lwz       r3, 0xAC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x390:
	  li        r3, 0x8
	  bl        -0x18533C
	  stw       r3, 0xA8(r1)
	  lwz       r0, 0xA8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x3D4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xA8(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x6
	  lwz       r3, 0xA8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x160
	  lwz       r3, 0xA8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x3D4:
	  li        r3, 0x8
	  bl        -0x185380
	  stw       r3, 0xA4(r1)
	  lwz       r0, 0xA4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x418
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xA4(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lwz       r3, 0xA4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1A0
	  lwz       r3, 0xA4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x418:
	  li        r3, 0x14
	  bl        -0x1853C4
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x460
	  li        r4, 0x7
	  li        r5, 0xA
	  bl        -0x1F700
	  lis       r3, 0x802E
	  addi      r0, r3, 0x298
	  stw       r0, 0x4(r19)
	  li        r0, 0x7
	  lis       r3, 0x802E
	  stw       r0, 0xC(r19)
	  li        r4, 0x3
	  addi      r0, r3, 0x2C24
	  stw       r4, 0x10(r19)
	  stw       r0, 0x4(r19)

	.loc_0x460:
	  li        r3, 0xC
	  bl        -0x18540C
	  stw       r3, 0xA0(r1)
	  lwz       r3, 0xA0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x494
	  li        r4, 0x3
	  li        r5, 0xB
	  bl        -0x1F74C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x250
	  lwz       r3, 0xA0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x494:
	  li        r3, 0x8
	  bl        -0x185440
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x4C8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x8
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0xC74
	  stw       r0, 0x4(r28)

	.loc_0x4C8:
	  li        r3, 0x10
	  bl        -0x185474
	  addi      r16, r3, 0
	  mr.       r3, r16
	  beq-      .loc_0x514
	  li        r4, -0x1
	  li        r5, 0x1
	  bl        -0x1F83C
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lis       r3, 0x802E
	  stw       r0, 0x4(r16)
	  subi      r0, r3, 0xD30
	  stw       r0, 0x4(r16)
	  li        r0, 0x44
	  lis       r3, 0x802E
	  stw       r0, 0xC(r16)
	  subi      r0, r3, 0xD4C
	  stw       r0, 0x4(r16)

	.loc_0x514:
	  li        r3, 0x8
	  bl        -0x1854C0
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x548
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0x9
	  lis       r3, 0x802E
	  stw       r0, 0x0(r20)
	  addi      r0, r3, 0x1CC
	  stw       r0, 0x4(r20)

	.loc_0x548:
	  li        r3, 0x8
	  bl        -0x1854F4
	  stw       r3, 0x9C(r1)
	  lwz       r0, 0x9C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x58C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x9C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x9C(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2540
	  lwz       r3, 0x9C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x58C:
	  li        r3, 0x8
	  bl        -0x185538
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x5C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r24)
	  addi      r0, r3, 0x1B60
	  stw       r0, 0x4(r24)

	.loc_0x5C0:
	  li        r3, 0x8
	  bl        -0x18556C
	  stw       r3, 0x98(r1)
	  lwz       r0, 0x98(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x604
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x98(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xA
	  lwz       r3, 0x98(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x478
	  lwz       r3, 0x98(r1)
	  stw       r0, 0x4(r3)

	.loc_0x604:
	  li        r3, 0xC
	  bl        -0x1855B0
	  stw       r3, 0x94(r1)
	  lwz       r3, 0x94(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x638
	  li        r4, 0xB
	  li        r5, 0x6
	  bl        -0x1F8F0
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x4(r3)

	.loc_0x638:
	  li        r3, 0x14
	  bl        -0x1855E4
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x680
	  li        r4, 0x4
	  li        r5, 0x6
	  bl        -0x1F920
	  lis       r3, 0x802E
	  addi      r0, r3, 0x588
	  stw       r0, 0x4(r14)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0xC(r14)
	  li        r0, 0x8
	  addi      r3, r3, 0x2B2C
	  stw       r0, 0x10(r14)
	  stw       r3, 0x4(r14)

	.loc_0x680:
	  li        r3, 0x8
	  bl        -0x18562C
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x6B4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  addi      r0, r3, 0x1CC
	  stw       r0, 0x4(r25)

	.loc_0x6B4:
	  li        r3, 0xC
	  bl        -0x185660
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x6FC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xC
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r27)
	  addi      r0, r3, 0x2A64
	  lfs       f0, -0x4494(r2)
	  stfs      f0, 0x8(r27)
	  stw       r0, 0x4(r27)

	.loc_0x6FC:
	  li        r3, 0x14
	  bl        -0x1856A8
	  addi      r15, r3, 0
	  mr.       r3, r15
	  beq-      .loc_0x744
	  li        r4, 0xD
	  li        r5, 0x5
	  bl        -0x1FA70
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  stw       r0, 0x4(r15)
	  lis       r3, 0x802E
	  subi      r3, r3, 0x3EC
	  lfs       f0, -0x446C(r2)
	  li        r0, 0
	  stfs      f0, 0xC(r15)
	  stw       r3, 0x4(r15)
	  stb       r0, 0x10(r15)

	.loc_0x744:
	  li        r3, 0xC
	  bl        -0x1856F0
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x78C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r18)
	  addi      r0, r3, 0x2A1C
	  lfs       f0, -0x4494(r2)
	  stfs      f0, 0x8(r18)
	  stw       r0, 0x4(r18)

	.loc_0x78C:
	  li        r3, 0x8
	  bl        -0x185738
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x7C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  addi      r0, r3, 0x2348
	  stw       r0, 0x4(r26)

	.loc_0x7C0:
	  li        r3, 0x8
	  bl        -0x18576C
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x7F4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r17)
	  addi      r0, r3, 0x2310
	  stw       r0, 0x4(r17)

	.loc_0x7F4:
	  li        r3, 0x10
	  bl        -0x1857A0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x844
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
	  lfs       f0, -0x4454(r2)
	  stfs      f0, 0x8(r30)
	  stb       r0, 0xC(r30)

	.loc_0x844:
	  li        r3, 0xC
	  bl        -0x1857F0
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x860
	  li        r4, 0x2
	  bl        -0xA5770

	.loc_0x860:
	  li        r0, 0
	  lwz       r4, 0x8(r29)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xC8(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xC4(r1)
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x0(r4)
	  bl        -0x18583C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x8AC
	  li        r4, 0x5
	  bl        -0xA57BC

	.loc_0x8AC:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r17, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x9C(r1)
	  lwz       r5, 0x8(r29)
	  li        r3, 0x2
	  stwx      r0, r5, r4
	  li        r6, 0x3
	  li        r0, 0x4
	  rlwinm    r5,r6,2,0,29
	  lwz       r4, 0x8(r29)
	  rlwinm    r6,r0,2,0,29
	  lwz       r0, 0xC0(r1)
	  rlwinm    r3,r3,2,0,29
	  stwx      r0, r4, r3
	  li        r3, 0xC
	  lwz       r0, 0xBC(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r25, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x4(r4)
	  bl        -0x1858BC
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x92C
	  li        r4, 0x2
	  bl        -0xA583C

	.loc_0x92C:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r26, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xB8(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x8(r4)
	  bl        -0x185904
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x974
	  li        r4, 0x2
	  bl        -0xA5884

	.loc_0x974:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xB4(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0xC(r4)
	  bl        -0x18594C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x9BC
	  li        r4, 0x9
	  bl        -0xA58CC

	.loc_0x9BC:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r28, r3, r5
	  li        r5, 0x4
	  rlwinm    r9,r5,2,0,29
	  lwz       r5, 0xCC(r1)
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r23, r3, r0
	  li        r6, 0x5
	  li        r0, 0x7
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r6,r6,2,0,29
	  stwx      r5, r3, r4
	  li        r7, 0x6
	  lwz       r4, 0xB0(r1)
	  rlwinm    r5,r7,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r8, 0x8
	  stwx      r4, r3, r9
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r8,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r3, 0xC
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r29)
	  stwx      r21, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r20, r4, r0
	  lwz       r4, 0x8(r29)
	  stwx      r27, r4, r7
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x10(r4)
	  bl        -0x185A08
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xA78
	  li        r4, 0x9
	  bl        -0xA5988

	.loc_0xA78:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r5, 0x2
	  rlwinm    r7,r5,2,0,29
	  stwx      r28, r3, r4
	  li        r3, 0x4
	  li        r0, 0x3
	  lwz       r6, 0x8(r29)
	  rlwinm    r9,r3,2,0,29
	  lwz       r3, 0xCC(r1)
	  rlwinm    r0,r0,2,0,29
	  stwx      r23, r6, r7
	  li        r5, 0x6
	  lwz       r8, 0x8(r29)
	  li        r6, 0x7
	  li        r4, 0x5
	  stwx      r3, r8, r0
	  rlwinm    r8,r5,2,0,29
	  rlwinm    r5,r6,2,0,29
	  lwz       r6, 0xAC(r1)
	  lwz       r3, 0x8(r29)
	  li        r7, 0x8
	  stwx      r6, r3, r9
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r4,r7,2,0,29
	  lwz       r7, 0xA8(r1)
	  lwz       r6, 0x8(r29)
	  li        r3, 0xC
	  stwx      r7, r6, r0
	  lwz       r0, 0xA4(r1)
	  lwz       r6, 0x8(r29)
	  stwx      r0, r6, r8
	  lwz       r6, 0x8(r29)
	  stwx      r22, r6, r5
	  lwz       r5, 0x8(r29)
	  stwx      r21, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x14(r4)
	  bl        -0x185ACC
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xB3C
	  li        r4, 0x3
	  bl        -0xA5A4C

	.loc_0xB3C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x18(r4)
	  bl        -0x185B20
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xB90
	  li        r4, 0x4
	  bl        -0xA5AA0

	.loc_0xB90:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xC4(r1)
	  lwz       r4, 0x8(r27)
	  li        r5, 0x2
	  stwx      r0, r4, r3
	  rlwinm    r0,r5,2,0,29
	  li        r6, 0x3
	  lwz       r4, 0x8(r27)
	  rlwinm    r5,r6,2,0,29
	  li        r3, 0xC
	  stwx      r28, r4, r0
	  lwz       r0, 0xA0(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x1C(r4)
	  bl        -0x185B8C
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0xBFC
	  li        r4, 0x2
	  bl        -0xA5B0C

	.loc_0xBFC:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xC4(r1)
	  lwz       r4, 0x8(r25)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x20(r4)
	  bl        -0x185BD4
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0xC44
	  li        r4, 0x1
	  bl        -0xA5B54

	.loc_0xC44:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x98(r1)
	  stwx      r0, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x24(r4)
	  bl        -0x185C0C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xC7C
	  li        r4, 0x7
	  bl        -0xA5B8C

	.loc_0xC7C:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r23, r3, r5
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0xCC(r1)
	  li        r5, 0x4
	  lwz       r8, 0x8(r29)
	  li        r6, 0x5
	  stwx      r0, r8, r3
	  rlwinm    r3,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r4, 0x8(r29)
	  rlwinm    r5,r6,2,0,29
	  li        r7, 0x6
	  stwx      r22, r4, r3
	  rlwinm    r6,r7,2,0,29
	  li        r3, 0xC
	  lwz       r4, 0x8(r29)
	  stwx      r21, r4, r0
	  lwz       r0, 0x94(r1)
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x28(r4)
	  bl        -0x185CA8
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xD18
	  li        r4, 0x6
	  bl        -0xA5C28

	.loc_0xD18:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r7, 0xCC(r1)
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r3, 0x2
	  li        r0, 0x3
	  stwx      r23, r4, r5
	  li        r6, 0x5
	  rlwinm    r3,r3,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r5, 0x4
	  rlwinm    r0,r0,2,0,29
	  stwx      r7, r4, r3
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r6,r6,2,0,29
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r22, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r21, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r14, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x2C(r4)
	  bl        -0x185D30
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xDA0
	  li        r4, 0x3
	  bl        -0xA5CB0

	.loc_0xDA0:
	  li        r0, 0
	  lwz       r4, 0x8(r27)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x9C(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r15, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0xC4(r1)
	  lwz       r5, 0x8(r27)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x30(r4)
	  bl        -0x185D8C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xDFC
	  li        r4, 0x2
	  bl        -0xA5D0C

	.loc_0xDFC:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r17, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  mr        r3, r31
	  stwx      r18, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x34(r4)
	  lwz       r0, 0x11C(r1)
	  lmw       r14, 0xD0(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CCDE8
 * Size:	0006FC
 */
void TAIkabekuiBAnimation::makeDefaultAnimations()
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
	  addi      r30, r3, 0x2710
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0x98
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x2989C
	  addi      r3, r31, 0
	  addi      r4, r30, 0xB8
	  bl        -0x298A8
	  addi      r3, r31, 0
	  addi      r4, r30, 0xDC
	  bl        -0x298B4
	  li        r3, 0x10
	  bl        -0x185E4C
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
	  bl        -0x185E94
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
	  addi      r4, r30, 0xFC
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29954
	  li        r3, 0x10
	  bl        -0x185EEC
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
	  bl        -0x185F34
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
	  addi      r4, r30, 0x11C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x299F4
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17CBD0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17C788
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17C7A0
	  li        r3, 0x10
	  bl        -0x185FC8
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
	  bl        -0x186014
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
	  addi      r4, r30, 0x140
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29AD8
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17CCB4
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17C86C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17C884
	  li        r3, 0x10
	  bl        -0x1860AC
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
	  bl        -0x1860F8
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
	  addi      r4, r30, 0x164
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29BBC
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17CD98
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17C950
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17C968
	  li        r3, 0x10
	  bl        -0x186190
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
	  bl        -0x1861DC
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
	  addi      r4, r30, 0x184
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29CA0
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17CE7C
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17CA34
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17CA4C
	  li        r3, 0x10
	  bl        -0x186274
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
	  bl        -0x1862C0
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
	  addi      r4, r30, 0x1A4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29D84
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17CB0C
	  li        r3, 0x10
	  bl        -0x186334
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
	  addi      r4, r30, 0x1C8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29DF8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17CB80
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17CB98
	  li        r3, 0x10
	  bl        -0x1863C0
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
	  bl        -0x18640C
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
	  addi      r4, r30, 0x1E8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x29ED0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17CC58
	  li        r3, 0x10
	  bl        -0x186480
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
 * Address:	801CD4E4
 * Size:	000018
 */
f32 TAIAsleepKabekuiB::getFrameMax(Teki&)
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
 * Address:	801CD4FC
 * Size:	000018
 */
f32 TAIAdiveKabekuiB::getFrameMax(Teki&)
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
 * Address:	801CD514
 * Size:	000020
 */
void TAIAattackWorkObjectKabekuiB::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1F384
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CD534
 * Size:	000020
 */
bool TAIAattackWorkObjectKabekuiB::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1F368
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CD554
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiB::getDamage(Teki&)
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
 * Address:	801CD56C
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiB::getAttackPointRadius(Teki&)
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
 * Address:	801CD584
 * Size:	00016C
 */
void TAIAattackWorkObjectKabekuiB::attackEffect(Teki&)
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
	  bl        -0x143E98
	  mr.       r31, r3
	  beq-      .loc_0x154
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD4
	  mr        r3, r31
	  bl        -0x145834
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  subi      r4, r4, 0x1
	  bl        -0x1457E8
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x4F
	  li        r6, 0
	  li        r7, 0
	  bl        -0x30AB8
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  lfs       f0, 0x1E60(r13)
	  lfs       f1, 0x1E64(r13)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x1E68(r13)
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
	  bl        -0x143084
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0xD4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x34
	  addi      r3, r3, 0x70
	  bl        -0x149C54

	.loc_0xD4:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x154
	  cmpwi     r0, 0x3
	  bne-      .loc_0x154
	  mr        r3, r31
	  bl        -0x1458E0
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  subi      r4, r4, 0x1
	  bl        -0x145894
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x50
	  li        r6, 0
	  li        r7, 0
	  bl        -0x30B64
	  cmplwi    r3, 0
	  beq-      .loc_0x154
	  lfs       f0, 0x1E6C(r13)
	  lfs       f1, 0x1E70(r13)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x1E74(r13)
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
 * Address:	801CD6F0
 * Size:	000018
 */
f32 TAIAbiteForKabekuiB::getPikiAttackSize(Teki&)
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
 * Address:	801CD708
 * Size:	000018
 */
f32 TAIAbiteForKabekuiB::getNaviAttackSize(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xDC(r3)
	  blr
	*/
}
