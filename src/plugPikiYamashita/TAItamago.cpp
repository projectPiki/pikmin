#include "TAI/Tamago.h"
#include "ParaParameters.h"

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
 * Address:	801CFE0C
 * Size:	000084
 */
TAItamagoSoundTable::TAItamagoSoundTable()
    : PaniSoundTable(1)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xB0DB8
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x188E3C
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x9A
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
 * Address:	801CFE90
 * Size:	0002F4
 */
TAItamagoParameters::TAItamagoParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x14
	  stw       r0, 0x4(r1)
	  li        r5, 0x34
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  addi      r31, r3, 0
	  bl        -0x84164
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3D30
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
	  add       r10, r7, r6
	  addi      r5, r5, 0x38CC
	  stw       r5, 0x0(r10)
	  add       r11, r7, r0
	  addi      r3, r3, 0x38E4
	  lfs       f5, -0x43C8(r2)
	  li        r9, 0x16
	  li        r8, 0x5
	  stfs      f5, 0x4(r10)
	  li        r7, 0x2
	  li        r6, 0xA
	  lfs       f0, -0x43C4(r2)
	  li        r5, 0x3
	  li        r0, 0x1
	  stfs      f0, 0x8(r10)
	  stw       r3, 0x0(r11)
	  stfs      f5, 0x4(r11)
	  stfs      f0, 0x8(r11)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43C0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43BC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xCC(r3)
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
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x43B8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x43B4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43B0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x43AC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x43A8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x10(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r31
	  lfs       f0, -0x43A4(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x14(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f1, -0x43A0(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x18(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x439C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x1C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x70(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x20(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4398(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x24(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x28(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4394(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x2C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4390(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x30(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x438C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x3C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x40(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4388(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x78(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4384(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x7C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4380(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x437C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4378(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x5C(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f5, 0x60(r4)
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D0184
 * Size:	0002DC
 */
TAItamagoStrategy::TAItamagoStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x4
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x58(r1)
	  stmw      r23, 0x34(r1)
	  addi      r31, r3, 0
	  bl        0x194B4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3C78
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x1891B0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x60
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r30)

	.loc_0x60:
	  li        r3, 0xC
	  bl        -0x1891E4
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x8C
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x235AC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3BF0
	  stw       r0, 0x4(r29)

	.loc_0x8C:
	  li        r3, 0xC
	  bl        -0x189210
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xC8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0xE10
	  li        r0, 0
	  stw       r3, 0x4(r28)
	  stb       r0, 0x8(r28)

	.loc_0xC8:
	  li        r3, 0x8
	  bl        -0x18924C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x6EC
	  stw       r0, 0x4(r27)

	.loc_0xFC:
	  li        r3, 0xC
	  bl        -0x189280
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x144
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x3
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r26)
	  addi      r0, r3, 0x3B8C
	  lfs       f0, -0x43C8(r2)
	  stfs      f0, 0x8(r26)
	  stw       r0, 0x4(r26)

	.loc_0x144:
	  li        r3, 0xC
	  bl        -0x1892C8
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x170
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x23690
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3B24
	  stw       r0, 0x4(r25)

	.loc_0x170:
	  li        r3, 0x8
	  bl        -0x1892F4
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x1A4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r24)
	  addi      r0, r3, 0x3AD0
	  stw       r0, 0x4(r24)

	.loc_0x1A4:
	  li        r3, 0xC
	  bl        -0x189328
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x1C0
	  li        r4, 0x2
	  bl        -0xA92A8

	.loc_0x1C0:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r23)
	  li        r3, 0xC
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x0(r4)
	  bl        -0x18936C
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x204
	  li        r4, 0x3
	  bl        -0xA92EC

	.loc_0x204:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r23)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r30, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r23)
	  stwx      r24, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x4(r4)
	  bl        -0x1893C0
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x258
	  li        r4, 0x3
	  bl        -0xA9340

	.loc_0x258:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r23)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r30, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r23)
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x8(r4)
	  bl        -0x189414
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x2AC
	  li        r4, 0x1
	  bl        -0xA9394

	.loc_0x2AC:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r25, r3, r0
	  mr        r3, r31
	  lwz       r4, 0x8(r31)
	  stw       r23, 0xC(r4)
	  lwz       r0, 0x5C(r1)
	  lmw       r23, 0x34(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D0460
 * Size:	0006FC
 */
void TAItamagoAnimation::makeDefaultAnimations()
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
	  addi      r30, r3, 0x38B0
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0x4C
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x2CF14
	  addi      r3, r31, 0
	  addi      r4, r30, 0x6C
	  bl        -0x2CF20
	  addi      r3, r31, 0
	  addi      r4, r30, 0x8C
	  bl        -0x2CF2C
	  li        r3, 0x10
	  bl        -0x1894C4
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
	  bl        -0x18950C
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
	  addi      r4, r30, 0xAC
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2CFCC
	  li        r3, 0x10
	  bl        -0x189564
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
	  bl        -0x1895AC
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
	  addi      r4, r30, 0xCC
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D06C
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x180248
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17FE00
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17FE18
	  li        r3, 0x10
	  bl        -0x189640
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
	  bl        -0x18968C
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
	  addi      r4, r30, 0xF0
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D150
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x18032C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17FEE4
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17FEFC
	  li        r3, 0x10
	  bl        -0x189724
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
	  bl        -0x189770
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
	  addi      r4, r30, 0x114
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D234
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x180410
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17FFC8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17FFE0
	  li        r3, 0x10
	  bl        -0x189808
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
	  bl        -0x189854
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
	  addi      r4, r30, 0x134
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D318
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x1804F4
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1800AC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1800C4
	  li        r3, 0x10
	  bl        -0x1898EC
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
	  bl        -0x189938
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
	  addi      r4, r30, 0x154
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D3FC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x180184
	  li        r3, 0x10
	  bl        -0x1899AC
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
	  addi      r4, r30, 0x174
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D470
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1801F8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x180210
	  li        r3, 0x10
	  bl        -0x189A38
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
	  bl        -0x189A84
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
	  addi      r4, r30, 0x194
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2D548
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1802D0
	  li        r3, 0x10
	  bl        -0x189AF8
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
 * Address:	801D0B5C
 * Size:	000024
 */
bool TAIAcountStartTamago::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x2E124
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D0B80
 * Size:	00004C
 */
void TAIAhatch::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x23F1C
	  mr        r3, r31
	  bl        -0x146888
	  mr        r3, r31
	  lwz       r4, -0x9B4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
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
 * Address:	801D0BCC
 * Size:	000174
 */
bool TAIAhatch::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  li        r30, 0
	  stw       r29, 0x34(r1)
	  mr        r29, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x130
	  lfs       f0, 0x94(r29)
	  addi      r31, r29, 0x94
	  addi      r5, r1, 0x24
	  stfs      f0, 0x24(r1)
	  li        r4, 0xA9
	  li        r6, 0
	  lfs       f0, 0x98(r29)
	  li        r7, 0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x9C(r29)
	  lfs       f0, -0x4374(r2)
	  stfs      f1, 0x2C(r1)
	  lfs       f1, 0x28(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x34100
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x24
	  li        r4, 0xAA
	  li        r6, 0
	  li        r7, 0
	  bl        -0x34118
	  mr        r3, r29
	  bl        -0x88EE4
	  mr        r3, r29
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0x2D4
	  bl        -0x142B30
	  lwz       r3, 0x2C4(r29)
	  li        r4, 0x3
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  bl        .loc_0x174
	  lwz       r12, 0x0(r29)
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x198(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0
	  addi      r4, r29, 0
	  li        r5, 0x9A
	  bl        -0x146718
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r31, 0
	  li        r4, 0x2
	  bl        -0xACD04
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x53F1C
	  mr        r3, r29
	  bl        -0x88F84

	.loc_0x130:
	  lwz       r0, 0x3A8(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x154
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0x1

	.loc_0x154:
	  mr        r3, r30
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x174:
	*/
}

/*
 * --INFO--
 * Address:	801D0D50
 * Size:	0000BC
 */
void TAIAtimerReactionTamago::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r4, 0
	  li        r4, 0x32
	  lfs       f0, -0x43C8(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xAE8B0
	  lwz       r3, 0x2C4(r31)
	  fmr       f30, f1
	  li        r4, 0x33
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xAE8C8
	  fmr       f31, f1
	  bl        0x472CC
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x64(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x84(r3)
	  fsubs     f0, f31, f30
	  stw       r0, 0x60(r1)
	  lfd       f3, -0x4368(r2)
	  li        r4, 0x32
	  lfd       f2, 0x60(r1)
	  lfs       f1, -0x4370(r2)
	  fsubs     f2, f2, f3
	  lwz       r3, 0x4(r3)
	  fdivs     f1, f2, f1
	  fmuls     f30, f0, f1
	  bl        -0xAE910
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
 * Address:	801D0E0C
 * Size:	00005C
 */
bool TAIAtimerReactionTamago::act(Teki&)
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
 * Address:	801D0E68
 * Size:	000008
 */
f32 TAIAtimerReactionTamago::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x47C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D0E70
 * Size:	000064
 */
void TAIAdyingTamago::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x2420C
	  mr        r3, r31
	  bl        -0x146B78
	  mr        r3, r31
	  lwz       r4, -0x9B4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
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
 * Address:	801D0ED4
 * Size:	0000E8
 */
bool TAIAdyingTamago::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  mr        r30, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xA8
	  lfs       f0, 0x94(r30)
	  addi      r5, r1, 0x14
	  li        r4, 0xA9
	  stfs      f0, 0x14(r1)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x18(r1)
	  lfs       f1, 0x9C(r30)
	  lfs       f0, -0x4374(r2)
	  stfs      f1, 0x1C(r1)
	  lfs       f1, 0x18(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x34400
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0xA8
	  li        r6, 0
	  li        r7, 0
	  bl        -0x34418
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0xA7
	  li        r6, 0
	  li        r7, 0
	  bl        -0x34430
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x9A
	  bl        -0x1469C4

	.loc_0xA8:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xCC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0x1

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
