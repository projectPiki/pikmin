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
 * Size:	0000C8
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800697FC
 * Size:	000058
 */
void PositionMenu::menuEnterZ(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r6, r13, 0x6A30
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r7, 0xB4(r3)
	  addi      r0, r7, 0x8
	  stw       r0, 0xBC(r3)
	  subi      r0, r5, 0x6AFC
	  stw       r6, 0xC0(r3)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACD58
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069854
 * Size:	000058
 */
void PositionMenu::menuEnterY(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r6, r13, 0x6A2C
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r7, 0xB4(r3)
	  addi      r0, r7, 0x4
	  stw       r0, 0xBC(r3)
	  subi      r0, r5, 0x6AFC
	  stw       r6, 0xC0(r3)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACD00
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800698AC
 * Size:	000054
 */
void PositionMenu::menuEnterX(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r6, r13, 0x6A28
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xB4(r3)
	  stw       r0, 0xBC(r3)
	  subi      r0, r5, 0x6AFC
	  stw       r6, 0xC0(r3)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACCAC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069900
 * Size:	0000A4
 */
void PositionMenu::menuIncrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0xB8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  lwz       r6, 0xBC(r3)
	  lis       r5, 0x802B
	  lfs       f0, -0x7808(r2)
	  subi      r0, r5, 0x6AFC
	  lfs       f1, 0x0(r6)
	  crset     6, 0x6
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACC48
	  b         .loc_0x94

	.loc_0x58:
	  lwz       r6, 0xBC(r3)
	  lis       r5, 0x802B
	  lfs       f0, -0x7804(r2)
	  subi      r0, r5, 0x6AFC
	  lfs       f1, 0x0(r6)
	  crset     6, 0x6
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACC08

	.loc_0x94:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800699A4
 * Size:	0000A4
 */
void PositionMenu::menuDecrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0xB8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  lwz       r6, 0xBC(r3)
	  lis       r5, 0x802B
	  lfs       f0, -0x7808(r2)
	  subi      r0, r5, 0x6AFC
	  lfs       f1, 0x0(r6)
	  crset     6, 0x6
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACBA4
	  b         .loc_0x94

	.loc_0x58:
	  lwz       r6, 0xBC(r3)
	  lis       r5, 0x802B
	  lfs       f0, -0x7804(r2)
	  subi      r0, r5, 0x6AFC
	  lfs       f1, 0x0(r6)
	  crset     6, 0x6
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ACB64

	.loc_0x94:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069A48
 * Size:	000050
 */
void ColourMenu::menuEnterA(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x6A24
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0xB4(r3)
	  addi      r5, r5, 0x3
	  stw       r5, 0xB8(r3)
	  stw       r0, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  subi      r4, r13, 0x6A20
	  lwz       r7, 0xB8(r3)
	  lwz       r5, 0xBC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r6, 0x0(r7)
	  bl        0x1ACB14
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069A98
 * Size:	000050
 */
void ColourMenu::menuEnterB(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x6A18
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0xB4(r3)
	  addi      r5, r5, 0x2
	  stw       r5, 0xB8(r3)
	  stw       r0, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  subi      r4, r13, 0x6A20
	  lwz       r7, 0xB8(r3)
	  lwz       r5, 0xBC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r6, 0x0(r7)
	  bl        0x1ACAC4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069AE8
 * Size:	000050
 */
void ColourMenu::menuEnterG(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x6A14
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0xB4(r3)
	  addi      r5, r5, 0x1
	  stw       r5, 0xB8(r3)
	  stw       r0, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  subi      r4, r13, 0x6A20
	  lwz       r7, 0xB8(r3)
	  lwz       r5, 0xBC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r6, 0x0(r7)
	  bl        0x1ACA74
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069B38
 * Size:	00004C
 */
void ColourMenu::menuEnterR(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x6A10
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0xB4(r3)
	  stw       r5, 0xB8(r3)
	  stw       r0, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  subi      r4, r13, 0x6A20
	  lwz       r7, 0xB8(r3)
	  lwz       r5, 0xBC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r6, 0x0(r7)
	  bl        0x1ACA28
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069B84
 * Size:	000054
 */
void ColourMenu::menuIncrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0xB8(r3)
	  lbz       r5, 0x0(r6)
	  cmplwi    r5, 0xFF
	  bge-      .loc_0x24
	  addi      r0, r5, 0x1
	  stb       r0, 0x0(r6)

	.loc_0x24:
	  lwz       r6, 0x30(r4)
	  crclr     6, 0x6
	  lwz       r7, 0xB8(r3)
	  subi      r4, r13, 0x6A20
	  lwz       r5, 0xBC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r6, 0x0(r7)
	  bl        0x1AC9D4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069BD8
 * Size:	000054
 */
void ColourMenu::menuDecrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0xB8(r3)
	  lbz       r5, 0x0(r6)
	  cmplwi    r5, 0
	  beq-      .loc_0x24
	  subi      r0, r5, 0x1
	  stb       r0, 0x0(r6)

	.loc_0x24:
	  lwz       r6, 0x30(r4)
	  crclr     6, 0x6
	  lwz       r7, 0xB8(r3)
	  subi      r4, r13, 0x6A20
	  lwz       r5, 0xBC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r6, 0x0(r7)
	  bl        0x1AC980
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069C2C
 * Size:	000054
 */
void FogMenu::menuEnterFar(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r6, r13, 0x6A0C
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xB8(r3)
	  stw       r0, 0xBC(r3)
	  subi      r0, r5, 0x6AFC
	  stw       r6, 0xC0(r3)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1AC92C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069C80
 * Size:	000054
 */
void FogMenu::menuEnterNear(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r6, r13, 0x6A08
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xB4(r3)
	  stw       r0, 0xBC(r3)
	  subi      r0, r5, 0x6AFC
	  stw       r6, 0xC0(r3)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1AC8D8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069CD4
 * Size:	000058
 */
void FogMenu::menuIncrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x6AFC
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0xBC(r3)
	  lfs       f0, -0x7808(r2)
	  lfs       f1, 0x0(r6)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1AC880
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069D2C
 * Size:	000058
 */
void FogMenu::menuDecrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x6AFC
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0xBC(r3)
	  lfs       f0, -0x7808(r2)
	  lfs       f1, 0x0(r6)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xBC(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC0(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1AC828
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069D84
 * Size:	000434
 */
void LightMenu::menuChangeMove(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  subi      r30, r5, 0x6B80
	  stw       r29, 0x64(r1)
	  lwz       r4, 0xB8(r3)
	  lwz       r0, 0x0(r4)
	  xori      r0, r0, 0x1
	  stw       r0, 0x0(r4)
	  bl        -0xC2BC
	  lwz       r4, 0xBC(r31)
	  li        r3, 0x14
	  lwz       r0, 0x14(r4)
	  rlwinm    r0,r0,2,22,29
	  add       r4, r30, r0
	  lwz       r0, 0x19C(r4)
	  stw       r0, 0xB4(r31)
	  bl        -0x22DD4
	  mr.       r6, r3
	  beq-      .loc_0xAC
	  lwz       r0, 0x1BC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1C0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x24(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x28(r1)
	  lwz       r4, 0x1C4(r30)
	  stw       r4, 0x2C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x24(r1)
	  lwz       r0, 0x28(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x10(r3)

	.loc_0xAC:
	  lwz       r4, 0xBC(r31)
	  mr        r3, r31
	  li        r7, 0x1
	  lwz       r0, 0x14(r4)
	  li        r4, 0
	  rlwinm    r0,r0,2,22,29
	  add       r5, r30, r0
	  lwz       r5, 0x18C(r5)
	  bl        -0xC334
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xC34C
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  bne-      .loc_0x304
	  addi      r0, r3, 0x20
	  stw       r0, 0xC0(r31)
	  li        r3, 0x14
	  bl        -0x22E88
	  mr.       r6, r3
	  beq-      .loc_0x160
	  lwz       r0, 0x1C8(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1CC(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x30(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x34(r1)
	  lwz       r4, 0x1D0(r30)
	  stw       r4, 0x38(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x10(r3)

	.loc_0x160:
	  lwz       r4, 0xB8(r31)
	  subi      r5, r13, 0x69DC
	  addi      r3, r31, 0
	  lwz       r0, 0x0(r4)
	  li        r4, 0
	  li        r7, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r5, r0
	  bl        -0xC3E8
	  li        r3, 0x40
	  bl        -0x22F08
	  lwz       r4, 0xC0(r31)
	  crset     6, 0x6
	  addi      r29, r3, 0
	  lfs       f1, 0x0(r4)
	  addi      r4, r30, 0x1F8
	  bl        0x1AC674
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xC420
	  li        r3, 0x14
	  bl        -0x22F40
	  mr.       r6, r3
	  beq-      .loc_0x218
	  lwz       r0, 0x1D4(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1D8(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x3C(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x40(r1)
	  lwz       r4, 0x1DC(r30)
	  stw       r4, 0x44(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x10(r3)

	.loc_0x218:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xC654
	  li        r3, 0x14
	  bl        -0x22FAC
	  mr.       r6, r3
	  beq-      .loc_0x284
	  lwz       r0, 0x1E0(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1E4(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x48(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x4C(r1)
	  lwz       r4, 0x1E8(r30)
	  stw       r4, 0x50(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x10(r3)

	.loc_0x284:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xC6C4
	  li        r3, 0x14
	  bl        -0x2301C
	  mr.       r6, r3
	  beq-      .loc_0x2F4
	  lwz       r0, 0x1EC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1F0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x54(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x58(r1)
	  lwz       r4, 0x1F4(r30)
	  stw       r4, 0x5C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x54(r1)
	  lwz       r0, 0x58(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x5C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x2F4:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xC730

	.loc_0x304:
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x360
	  li        r3, 0xC4
	  bl        -0x2309C
	  mr.       r29, r3
	  beq-      .loc_0x34C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x54
	  li        r8, 0
	  bl        0xD74

	.loc_0x34C:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r6, r30, 0x204
	  li        r5, 0
	  bl        -0xC430

	.loc_0x360:
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  bne-      .loc_0x3BC
	  li        r3, 0xC4
	  bl        -0x230F8
	  mr.       r29, r3
	  beq-      .loc_0x3A8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x60
	  li        r8, 0x1
	  bl        0xD18

	.loc_0x3A8:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r6, r30, 0x210
	  li        r5, 0
	  bl        -0xC48C

	.loc_0x3BC:
	  li        r3, 0xC0
	  bl        -0x23140
	  mr.       r29, r3
	  beq-      .loc_0x3EC
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x6C
	  bl        0x5A8

	.loc_0x3EC:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  subi      r6, r13, 0x69D4
	  bl        -0xC4D0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8006A1B8
 * Size:	000458
 */
void LightMenu::menuChangeType(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r4, r13, 0x69EC
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  subi      r30, r5, 0x6B80
	  stw       r29, 0x64(r1)
	  lwz       r0, 0xB4(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0xB4(r3)
	  lwz       r5, 0xBC(r31)
	  lwz       r0, 0xB4(r31)
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  rlwinm    r4,r5,0,0,23
	  or        r0, r4, r0
	  stw       r0, 0x0(r6)
	  bl        -0xC714
	  lwz       r4, 0xBC(r31)
	  li        r3, 0x14
	  lwz       r0, 0x14(r4)
	  rlwinm    r0,r0,2,22,29
	  add       r4, r30, r0
	  lwz       r0, 0x19C(r4)
	  stw       r0, 0xB4(r31)
	  bl        -0x2322C
	  mr.       r6, r3
	  beq-      .loc_0xD0
	  lwz       r0, 0x1BC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1C0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x24(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x28(r1)
	  lwz       r4, 0x1C4(r30)
	  stw       r4, 0x2C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x24(r1)
	  lwz       r0, 0x28(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x10(r3)

	.loc_0xD0:
	  lwz       r4, 0xBC(r31)
	  mr        r3, r31
	  li        r7, 0x1
	  lwz       r0, 0x14(r4)
	  li        r4, 0
	  rlwinm    r0,r0,2,22,29
	  add       r5, r30, r0
	  lwz       r5, 0x18C(r5)
	  bl        -0xC78C
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xC7A4
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  bne-      .loc_0x328
	  addi      r0, r3, 0x20
	  stw       r0, 0xC0(r31)
	  li        r3, 0x14
	  bl        -0x232E0
	  mr.       r6, r3
	  beq-      .loc_0x184
	  lwz       r0, 0x1C8(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1CC(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x30(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x34(r1)
	  lwz       r4, 0x1D0(r30)
	  stw       r4, 0x38(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x10(r3)

	.loc_0x184:
	  lwz       r4, 0xB8(r31)
	  subi      r5, r13, 0x69DC
	  addi      r3, r31, 0
	  lwz       r0, 0x0(r4)
	  li        r4, 0
	  li        r7, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r5, r0
	  bl        -0xC840
	  li        r3, 0x40
	  bl        -0x23360
	  lwz       r4, 0xC0(r31)
	  crset     6, 0x6
	  addi      r29, r3, 0
	  lfs       f1, 0x0(r4)
	  addi      r4, r30, 0x1F8
	  bl        0x1AC21C
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xC878
	  li        r3, 0x14
	  bl        -0x23398
	  mr.       r6, r3
	  beq-      .loc_0x23C
	  lwz       r0, 0x1D4(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1D8(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x3C(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x40(r1)
	  lwz       r4, 0x1DC(r30)
	  stw       r4, 0x44(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x10(r3)

	.loc_0x23C:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xCAAC
	  li        r3, 0x14
	  bl        -0x23404
	  mr.       r6, r3
	  beq-      .loc_0x2A8
	  lwz       r0, 0x1E0(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1E4(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x48(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x4C(r1)
	  lwz       r4, 0x1E8(r30)
	  stw       r4, 0x50(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x10(r3)

	.loc_0x2A8:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xCB1C
	  li        r3, 0x14
	  bl        -0x23474
	  mr.       r6, r3
	  beq-      .loc_0x318
	  lwz       r0, 0x1EC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1F0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x54(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x58(r1)
	  lwz       r4, 0x1F4(r30)
	  stw       r4, 0x5C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x54(r1)
	  lwz       r0, 0x58(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x5C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x318:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xCB88

	.loc_0x328:
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x384
	  li        r3, 0xC4
	  bl        -0x234F4
	  mr.       r29, r3
	  beq-      .loc_0x370
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x54
	  li        r8, 0
	  bl        0x91C

	.loc_0x370:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r6, r30, 0x204
	  li        r5, 0
	  bl        -0xC888

	.loc_0x384:
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  bne-      .loc_0x3E0
	  li        r3, 0xC4
	  bl        -0x23550
	  mr.       r29, r3
	  beq-      .loc_0x3CC
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x60
	  li        r8, 0x1
	  bl        0x8C0

	.loc_0x3CC:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r6, r30, 0x210
	  li        r5, 0
	  bl        -0xC8E4

	.loc_0x3E0:
	  li        r3, 0xC0
	  bl        -0x23598
	  mr.       r29, r3
	  beq-      .loc_0x410
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x6C
	  bl        0x150

	.loc_0x410:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  subi      r6, r13, 0x69D4
	  bl        -0xC928
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8006A610
 * Size:	000054
 */
void LightMenu::menuEnterNear(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r6, r13, 0x69CC
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xC0(r3)
	  stw       r0, 0xC4(r3)
	  subi      r0, r5, 0x6AFC
	  stw       r6, 0xC8(r3)
	  lwz       r7, 0xC4(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC8(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ABF48
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006A664
 * Size:	000058
 */
void LightMenu::menuIncrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x6AFC
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0xC4(r3)
	  lfs       f0, -0x7800(r2)
	  lfs       f1, 0x0(r6)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xC4(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC8(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ABEF0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006A6BC
 * Size:	000058
 */
void LightMenu::menuDecrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x6AFC
	  crset     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0xC4(r3)
	  lfs       f0, -0x7800(r2)
	  lfs       f1, 0x0(r6)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lwz       r7, 0xC4(r3)
	  lwz       r6, 0x30(r4)
	  mr        r4, r0
	  lwz       r5, 0xC8(r3)
	  lwz       r3, 0x18(r6)
	  lfs       f1, 0x0(r7)
	  bl        0x1ABE98
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006A714
 * Size:	00072C
 */
ColourMenu::ColourMenu(Colour*, Controller*, Font*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r8, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stw       r31, 0xC4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xC0(r1)
	  subi      r30, r8, 0x6B80
	  stw       r29, 0xBC(r1)
	  addi      r29, r4, 0
	  addi      r4, r5, 0
	  addi      r5, r6, 0
	  addi      r6, r7, 0
	  bl        -0xD050
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6398
	  stw       r0, 0x0(r31)
	  li        r0, 0x1
	  li        r6, 0x20
	  stw       r29, 0xB4(r31)
	  li        r5, 0x80
	  li        r4, 0xC0
	  stw       r0, 0xA8(r31)
	  li        r0, 0x40
	  li        r3, 0x14
	  lwz       r7, -0x7848(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r31)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x4C(r31)
	  stb       r6, 0x60(r31)
	  stb       r5, 0x61(r31)
	  stb       r5, 0x62(r31)
	  stb       r4, 0x63(r31)
	  stb       r6, 0x64(r31)
	  stb       r0, 0x65(r31)
	  stb       r6, 0x66(r31)
	  stb       r0, 0x67(r31)
	  bl        -0x237B4
	  mr.       r6, r3
	  beq-      .loc_0xFC
	  lwz       r0, 0x90(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x94(r30)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xAC(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0xB0(r1)
	  lwz       r4, 0x98(r30)
	  stw       r4, 0xB4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x10(r3)

	.loc_0xFC:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xCEC8
	  li        r3, 0x40
	  bl        -0x23820
	  lwz       r4, 0xB4(r31)
	  crclr     6, 0x6
	  addi      r29, r3, 0
	  lbz       r5, 0x0(r4)
	  subi      r4, r13, 0x69C8
	  bl        0x1ABD5C
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xCD38
	  li        r3, 0x14
	  bl        -0x23858
	  mr.       r6, r3
	  beq-      .loc_0x1A0
	  lwz       r0, 0x9C(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xA0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xA0(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xA4(r1)
	  lwz       r4, 0xA4(r30)
	  stw       r4, 0xA8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1A0:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xCF6C
	  li        r3, 0x14
	  bl        -0x238C4
	  mr.       r6, r3
	  beq-      .loc_0x20C
	  lwz       r0, 0xA8(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xAC(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x94(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x98(r1)
	  lwz       r4, 0xB0(r30)
	  stw       r4, 0x9C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x20C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xCFDC
	  li        r3, 0x14
	  bl        -0x23934
	  mr.       r6, r3
	  beq-      .loc_0x27C
	  lwz       r0, 0xB4(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xB8(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x88(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x8C(r1)
	  lwz       r4, 0xBC(r30)
	  stw       r4, 0x90(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x10(r3)

	.loc_0x27C:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xD048
	  li        r3, 0x40
	  bl        -0x239A0
	  lwz       r4, 0xB4(r31)
	  crclr     6, 0x6
	  addi      r29, r3, 0
	  lbz       r5, 0x1(r4)
	  subi      r4, r13, 0x69C0
	  bl        0x1ABBDC
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xCEB8
	  li        r3, 0x14
	  bl        -0x239D8
	  mr.       r6, r3
	  beq-      .loc_0x320
	  lwz       r0, 0xC0(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xC4(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x7C(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x80(r1)
	  lwz       r4, 0xC8(r30)
	  stw       r4, 0x84(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x7C(r1)
	  lwz       r0, 0x80(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x10(r3)

	.loc_0x320:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xD0EC
	  li        r3, 0x14
	  bl        -0x23A44
	  mr.       r6, r3
	  beq-      .loc_0x38C
	  lwz       r0, 0xCC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xD0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x70(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x74(r1)
	  lwz       r4, 0xD4(r30)
	  stw       r4, 0x78(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x10(r3)

	.loc_0x38C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xD15C
	  li        r3, 0x14
	  bl        -0x23AB4
	  mr.       r6, r3
	  beq-      .loc_0x3FC
	  lwz       r0, 0xD8(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xDC(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x64(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x68(r1)
	  lwz       r4, 0xE0(r30)
	  stw       r4, 0x6C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x3FC:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xD1C8
	  li        r3, 0x40
	  bl        -0x23B20
	  lwz       r4, 0xB4(r31)
	  crclr     6, 0x6
	  addi      r29, r3, 0
	  lbz       r5, 0x2(r4)
	  subi      r4, r13, 0x69B8
	  bl        0x1ABA5C
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xD038
	  li        r3, 0x14
	  bl        -0x23B58
	  mr.       r6, r3
	  beq-      .loc_0x4A0
	  lwz       r0, 0xE4(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xE8(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x58(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x5C(r1)
	  lwz       r4, 0xEC(r30)
	  stw       r4, 0x60(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x10(r3)

	.loc_0x4A0:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xD26C
	  li        r3, 0x14
	  bl        -0x23BC4
	  mr.       r6, r3
	  beq-      .loc_0x50C
	  lwz       r0, 0xF0(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0xF4(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x4C(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x50(r1)
	  lwz       r4, 0xF8(r30)
	  stw       r4, 0x54(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x10(r3)

	.loc_0x50C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xD2DC
	  li        r3, 0x14
	  bl        -0x23C34
	  mr.       r6, r3
	  beq-      .loc_0x57C
	  lwz       r0, 0xFC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x100(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x40(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x44(r1)
	  lwz       r4, 0x104(r30)
	  stw       r4, 0x48(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x10(r3)

	.loc_0x57C:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xD348
	  li        r3, 0x40
	  bl        -0x23CA0
	  lwz       r4, 0xB4(r31)
	  crclr     6, 0x6
	  addi      r29, r3, 0
	  lbz       r5, 0x3(r4)
	  subi      r4, r13, 0x69B0
	  bl        0x1AB8DC
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xD1B8
	  li        r3, 0x14
	  bl        -0x23CD8
	  mr.       r6, r3
	  beq-      .loc_0x620
	  lwz       r0, 0x108(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x10C(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x34(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x38(r1)
	  lwz       r4, 0x110(r30)
	  stw       r4, 0x3C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x620:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xD3EC
	  li        r3, 0x14
	  bl        -0x23D44
	  mr.       r6, r3
	  beq-      .loc_0x68C
	  lwz       r0, 0x114(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x118(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x28(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x2C(r1)
	  lwz       r4, 0x11C(r30)
	  stw       r4, 0x30(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x10(r3)

	.loc_0x68C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xD45C
	  li        r3, 0x14
	  bl        -0x23DB4
	  mr.       r6, r3
	  beq-      .loc_0x6FC
	  lwz       r0, 0x120(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x124(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x1C(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x20(r1)
	  lwz       r4, 0x128(r30)
	  stw       r4, 0x24(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x10(r3)

	.loc_0x6FC:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xD4C8
	  mr        r3, r31
	  lwz       r0, 0xCC(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  lwz       r29, 0xBC(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006AE40
 * Size:	0005BC
 */
PositionMenu::PositionMenu(Vector3f*, Controller*, Font*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r9, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xA0(r1)
	  subi      r30, r9, 0x6B80
	  stw       r29, 0x9C(r1)
	  addi      r29, r8, 0
	  stw       r28, 0x98(r1)
	  addi      r28, r4, 0
	  addi      r4, r5, 0
	  addi      r5, r6, 0
	  addi      r6, r7, 0
	  bl        -0xD784
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6484
	  stw       r0, 0x0(r31)
	  li        r7, 0x1
	  li        r6, 0x20
	  stw       r28, 0xB4(r31)
	  li        r5, 0x80
	  li        r4, 0xC0
	  stb       r29, 0xB8(r31)
	  li        r0, 0x40
	  li        r3, 0x14
	  stw       r7, 0xA8(r31)
	  lwz       r7, -0x7848(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r31)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x4C(r31)
	  stb       r6, 0x60(r31)
	  stb       r5, 0x61(r31)
	  stb       r5, 0x62(r31)
	  stb       r4, 0x63(r31)
	  stb       r6, 0x64(r31)
	  stb       r0, 0x65(r31)
	  stb       r6, 0x66(r31)
	  stb       r0, 0x67(r31)
	  bl        -0x23EEC
	  mr.       r6, r3
	  beq-      .loc_0x108
	  lwz       r0, 0xC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x10(r30)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x88(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x8C(r1)
	  lwz       r4, 0x14(r30)
	  stw       r4, 0x90(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x10(r3)

	.loc_0x108:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xD600
	  li        r3, 0x40
	  bl        -0x23F58
	  lwz       r4, 0xB4(r31)
	  crset     6, 0x6
	  addi      r29, r3, 0
	  lfs       f1, 0x0(r4)
	  addi      r4, r30, 0x228
	  bl        0x1AB624
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xD470
	  li        r3, 0x14
	  bl        -0x23F90
	  mr.       r6, r3
	  beq-      .loc_0x1AC
	  lwz       r0, 0x18(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1C(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x7C(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x80(r1)
	  lwz       r4, 0x20(r30)
	  stw       r4, 0x84(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x7C(r1)
	  lwz       r0, 0x80(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1AC:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xD6A4
	  li        r3, 0x14
	  bl        -0x23FFC
	  mr.       r6, r3
	  beq-      .loc_0x218
	  lwz       r0, 0x24(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x28(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x70(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x74(r1)
	  lwz       r4, 0x2C(r30)
	  stw       r4, 0x78(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x10(r3)

	.loc_0x218:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xD714
	  li        r3, 0x14
	  bl        -0x2406C
	  mr.       r6, r3
	  beq-      .loc_0x288
	  lwz       r0, 0x30(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x34(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x64(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x68(r1)
	  lwz       r4, 0x38(r30)
	  stw       r4, 0x6C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x288:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xD780
	  li        r3, 0x40
	  bl        -0x240D8
	  lwz       r4, 0xB4(r31)
	  crset     6, 0x6
	  addi      r29, r3, 0
	  lfs       f1, 0x4(r4)
	  addi      r4, r30, 0x234
	  bl        0x1AB4A4
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xD5F0
	  li        r3, 0x14
	  bl        -0x24110
	  mr.       r6, r3
	  beq-      .loc_0x32C
	  lwz       r0, 0x3C(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x40(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x58(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x5C(r1)
	  lwz       r4, 0x44(r30)
	  stw       r4, 0x60(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x10(r3)

	.loc_0x32C:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xD824
	  li        r3, 0x14
	  bl        -0x2417C
	  mr.       r6, r3
	  beq-      .loc_0x398
	  lwz       r0, 0x48(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x4C(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x4C(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x50(r1)
	  lwz       r4, 0x50(r30)
	  stw       r4, 0x54(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x10(r3)

	.loc_0x398:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xD894
	  li        r3, 0x14
	  bl        -0x241EC
	  mr.       r6, r3
	  beq-      .loc_0x408
	  lwz       r0, 0x54(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x58(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x40(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x44(r1)
	  lwz       r4, 0x5C(r30)
	  stw       r4, 0x48(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x10(r3)

	.loc_0x408:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xD900
	  li        r3, 0x40
	  bl        -0x24258
	  lwz       r4, 0xB4(r31)
	  crset     6, 0x6
	  addi      r29, r3, 0
	  lfs       f1, 0x8(r4)
	  addi      r4, r30, 0x240
	  bl        0x1AB324
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xD770
	  li        r3, 0x14
	  bl        -0x24290
	  mr.       r6, r3
	  beq-      .loc_0x4AC
	  lwz       r0, 0x60(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x64(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x34(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x38(r1)
	  lwz       r4, 0x68(r30)
	  stw       r4, 0x3C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x4AC:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xD9A4
	  li        r3, 0x14
	  bl        -0x242FC
	  mr.       r6, r3
	  beq-      .loc_0x518
	  lwz       r0, 0x6C(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x70(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x28(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x2C(r1)
	  lwz       r4, 0x74(r30)
	  stw       r4, 0x30(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x10(r3)

	.loc_0x518:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xDA14
	  li        r3, 0x14
	  bl        -0x2436C
	  mr.       r6, r3
	  beq-      .loc_0x588
	  lwz       r0, 0x78(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x7C(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x1C(r1)
	  subi      r0, r4, 0x64C4
	  stw       r7, 0x20(r1)
	  lwz       r4, 0x80(r30)
	  stw       r4, 0x24(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x10(r3)

	.loc_0x588:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xDA80
	  mr        r3, r31
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
 * Address:	........
 * Size:	000034
 */
void DayMgr::updateComponent(Menu&, char*, int*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8006B3FC
 * Size:	00005C
 */
void DayMgr::menuBIncrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x1414(r3)
	  addi      r6, r5, 0x4BC
	  lwz       r5, 0x4BC(r5)
	  cmpwi     r5, 0xFF
	  bge-      .loc_0x28
	  addi      r0, r5, 0x1
	  stw       r0, 0x0(r6)

	.loc_0x28:
	  lwz       r5, 0x1414(r3)
	  crclr     6, 0x6
	  lwz       r3, 0x30(r4)
	  subi      r4, r13, 0x6A20
	  addi      r6, r5, 0x4BC
	  lwz       r3, 0x18(r3)
	  subi      r5, r13, 0x69A8
	  lwz       r6, 0x0(r6)
	  bl        0x1AB154
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006B458
 * Size:	00005C
 */
void DayMgr::menuBDecrease(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x1414(r3)
	  addi      r6, r5, 0x4BC
	  lwz       r5, 0x4BC(r5)
	  cmpwi     r5, 0
	  ble-      .loc_0x28
	  subi      r0, r5, 0x1
	  stw       r0, 0x0(r6)

	.loc_0x28:
	  lwz       r5, 0x1414(r3)
	  crclr     6, 0x6
	  lwz       r3, 0x30(r4)
	  subi      r4, r13, 0x6A20
	  addi      r6, r5, 0x4BC
	  lwz       r3, 0x18(r3)
	  subi      r5, r13, 0x69A8
	  lwz       r6, 0x0(r6)
	  bl        0x1AB0F8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006B4B4
 * Size:	001B80
 */
DayMgr::DayMgr(MapMgr*, Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8003
	  stw       r0, 0x4(r1)
	  subi      r0, r6, 0x65B8
	  li        r6, 0x2D4
	  stwu      r1, -0x118(r1)
	  li        r7, 0x7
	  stmw      r25, 0xFC(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x802B
	  addi      r26, r5, 0
	  addi      r25, r4, 0
	  subi      r29, r3, 0x6B80
	  mr        r4, r0
	  addi      r3, r30, 0x8
	  li        r5, 0
	  bl        0x1A957C
	  li        r28, 0xFF
	  stb       r28, 0x74(r30)
	  li        r27, 0x1
	  addi      r3, r30, 0x8
	  stb       r28, 0x75(r30)
	  stb       r28, 0x76(r30)
	  stb       r28, 0x77(r30)
	  lfs       f0, -0x6AD8(r13)
	  stfs      f0, 0x5C(r30)
	  lfs       f0, -0x6AD4(r13)
	  stfs      f0, 0x60(r30)
	  lfs       f0, -0x6AD0(r13)
	  stfs      f0, 0x64(r30)
	  lfs       f0, -0x6ACC(r13)
	  stfs      f0, 0x68(r30)
	  lfs       f0, -0x6AC8(r13)
	  stfs      f0, 0x6C(r30)
	  lfs       f0, -0x6AC4(r13)
	  stfs      f0, 0x70(r30)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0x20(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x28(r30)
	  stw       r27, 0x1C(r30)
	  bl        -0x41690
	  stb       r28, 0x348(r30)
	  addi      r3, r30, 0x2DC
	  stb       r28, 0x349(r30)
	  stb       r28, 0x34A(r30)
	  stb       r28, 0x34B(r30)
	  lfs       f0, -0x6AC0(r13)
	  stfs      f0, 0x330(r30)
	  lfs       f0, -0x6ABC(r13)
	  stfs      f0, 0x334(r30)
	  lfs       f0, -0x6AB8(r13)
	  stfs      f0, 0x338(r30)
	  lfs       f0, -0x6AB4(r13)
	  stfs      f0, 0x33C(r30)
	  lfs       f0, -0x6AB0(r13)
	  stfs      f0, 0x340(r30)
	  lfs       f0, -0x6AAC(r13)
	  stfs      f0, 0x344(r30)
	  lfs       f0, -0x77F4(r2)
	  stfs      f0, 0x2F4(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x2FC(r30)
	  stw       r27, 0x2F0(r30)
	  bl        -0x416EC
	  stb       r28, 0x61C(r30)
	  addi      r3, r30, 0x5B0
	  stb       r28, 0x61D(r30)
	  stb       r28, 0x61E(r30)
	  stb       r28, 0x61F(r30)
	  lfs       f0, -0x6AA8(r13)
	  stfs      f0, 0x604(r30)
	  lfs       f0, -0x6AA4(r13)
	  stfs      f0, 0x608(r30)
	  lfs       f0, -0x6AA0(r13)
	  stfs      f0, 0x60C(r30)
	  lfs       f0, -0x6A9C(r13)
	  stfs      f0, 0x610(r30)
	  lfs       f0, -0x6A98(r13)
	  stfs      f0, 0x614(r30)
	  lfs       f0, -0x6A94(r13)
	  stfs      f0, 0x618(r30)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0x5C8(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x5D0(r30)
	  stw       r27, 0x5C4(r30)
	  bl        -0x41748
	  stb       r28, 0x8F0(r30)
	  addi      r3, r30, 0x884
	  stb       r28, 0x8F1(r30)
	  stb       r28, 0x8F2(r30)
	  stb       r28, 0x8F3(r30)
	  lfs       f0, -0x6A90(r13)
	  stfs      f0, 0x8D8(r30)
	  lfs       f0, -0x6A8C(r13)
	  stfs      f0, 0x8DC(r30)
	  lfs       f0, -0x6A88(r13)
	  stfs      f0, 0x8E0(r30)
	  lfs       f0, -0x6A84(r13)
	  stfs      f0, 0x8E4(r30)
	  lfs       f0, -0x6A80(r13)
	  stfs      f0, 0x8E8(r30)
	  lfs       f0, -0x6A7C(r13)
	  stfs      f0, 0x8EC(r30)
	  lfs       f0, -0x77F4(r2)
	  stfs      f0, 0x89C(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x8A4(r30)
	  stw       r27, 0x898(r30)
	  bl        -0x417A4
	  stb       r28, 0xBC4(r30)
	  addi      r3, r30, 0xB58
	  stb       r28, 0xBC5(r30)
	  stb       r28, 0xBC6(r30)
	  stb       r28, 0xBC7(r30)
	  lfs       f0, -0x6A78(r13)
	  stfs      f0, 0xBAC(r30)
	  lfs       f0, -0x6A74(r13)
	  stfs      f0, 0xBB0(r30)
	  lfs       f0, -0x6A70(r13)
	  stfs      f0, 0xBB4(r30)
	  lfs       f0, -0x6A6C(r13)
	  stfs      f0, 0xBB8(r30)
	  lfs       f0, -0x6A68(r13)
	  stfs      f0, 0xBBC(r30)
	  lfs       f0, -0x6A64(r13)
	  stfs      f0, 0xBC0(r30)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0xB70(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0xB78(r30)
	  stw       r27, 0xB6C(r30)
	  bl        -0x41800
	  stb       r28, 0xE98(r30)
	  addi      r3, r30, 0xE2C
	  stb       r28, 0xE99(r30)
	  stb       r28, 0xE9A(r30)
	  stb       r28, 0xE9B(r30)
	  lfs       f0, -0x6A60(r13)
	  stfs      f0, 0xE80(r30)
	  lfs       f0, -0x6A5C(r13)
	  stfs      f0, 0xE84(r30)
	  lfs       f0, -0x6A58(r13)
	  stfs      f0, 0xE88(r30)
	  lfs       f0, -0x6A54(r13)
	  stfs      f0, 0xE8C(r30)
	  lfs       f0, -0x6A50(r13)
	  stfs      f0, 0xE90(r30)
	  lfs       f0, -0x6A4C(r13)
	  stfs      f0, 0xE94(r30)
	  lfs       f0, -0x77F4(r2)
	  stfs      f0, 0xE44(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0xE4C(r30)
	  stw       r27, 0xE40(r30)
	  bl        -0x4185C
	  stb       r28, 0x116C(r30)
	  addi      r3, r30, 0x1100
	  stb       r28, 0x116D(r30)
	  stb       r28, 0x116E(r30)
	  stb       r28, 0x116F(r30)
	  lfs       f0, -0x6A48(r13)
	  stfs      f0, 0x1154(r30)
	  lfs       f0, -0x6A44(r13)
	  stfs      f0, 0x1158(r30)
	  lfs       f0, -0x6A40(r13)
	  stfs      f0, 0x115C(r30)
	  lfs       f0, -0x6A3C(r13)
	  stfs      f0, 0x1160(r30)
	  lfs       f0, -0x6A38(r13)
	  stfs      f0, 0x1164(r30)
	  lfs       f0, -0x6A34(r13)
	  stfs      f0, 0x1168(r30)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0x1118(r30)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x1120(r30)
	  stw       r27, 0x1114(r30)
	  bl        -0x418B8
	  li        r5, 0x30
	  stb       r5, 0x13F0(r30)
	  li        r4, 0x2
	  li        r0, 0x7
	  stb       r5, 0x13F1(r30)
	  li        r3, 0x63E0
	  stb       r5, 0x13F2(r30)
	  stb       r5, 0x13F3(r30)
	  stb       r5, 0x13FC(r30)
	  stb       r5, 0x13FD(r30)
	  stb       r5, 0x13FE(r30)
	  stb       r5, 0x13FF(r30)
	  lfs       f0, -0x77F0(r2)
	  stfs      f0, 0x13F4(r30)
	  lfs       f0, -0x77EC(r2)
	  stfs      f0, 0x13F8(r30)
	  lfs       f0, -0x77E8(r2)
	  stfs      f0, 0x1410(r30)
	  stfs      f0, 0x140C(r30)
	  stfs      f0, 0x1408(r30)
	  stw       r25, 0x1414(r30)
	  stw       r4, 0x0(r30)
	  stw       r0, 0x4(r30)
	  bl        -0x247DC
	  lis       r4, 0x8007
	  subi      r4, r4, 0x1F70
	  li        r5, 0
	  li        r6, 0x13F8
	  li        r7, 0x5
	  bl        0x1A9430
	  stw       r3, 0x1400(r30)
	  li        r3, 0xB4
	  bl        -0x24800
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x374
	  lwz       r5, 0x2DEC(r13)
	  mr        r4, r26
	  li        r6, 0
	  lwz       r5, 0x10(r5)
	  bl        -0xE12C

	.loc_0x374:
	  stw       r25, 0x1404(r30)
	  li        r0, 0x1
	  li        r6, 0x20
	  lwz       r3, 0x1404(r30)
	  li        r5, 0x80
	  li        r4, 0xC0
	  stw       r0, 0xA8(r3)
	  li        r0, 0x40
	  li        r3, 0x14
	  lwz       r8, -0x7848(r13)
	  lwz       r7, 0x1404(r30)
	  srawi     r8, r8, 0x1
	  addze     r8, r8
	  stw       r8, 0x48(r7)
	  lwz       r8, -0x7844(r13)
	  lwz       r7, 0x1404(r30)
	  srawi     r8, r8, 0x1
	  addze     r8, r8
	  addi      r8, r8, 0x5A
	  stw       r8, 0x4C(r7)
	  lwz       r7, 0x1404(r30)
	  stbu      r6, 0x60(r7)
	  stb       r5, 0x1(r7)
	  stb       r6, 0x2(r7)
	  stb       r4, 0x3(r7)
	  lwz       r4, 0x1404(r30)
	  stbu      r6, 0x64(r4)
	  stb       r0, 0x1(r4)
	  stb       r6, 0x2(r4)
	  stb       r0, 0x3(r4)
	  bl        -0x2489C
	  mr.       r6, r3
	  beq-      .loc_0x448
	  lwz       r0, 0x258(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x25C(r29)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xE8(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0xEC(r1)
	  lwz       r4, 0x260(r29)
	  stw       r4, 0xF0(r1)
	  lwz       r4, 0x1404(r30)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0xE8(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0x10(r3)

	.loc_0x448:
	  lwz       r3, 0x1404(r30)
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xDFB4
	  li        r3, 0x40
	  bl        -0x2490C
	  lwz       r5, 0x0(r30)
	  crclr     6, 0x6
	  addi      r25, r3, 0
	  addi      r4, r29, 0x2B8
	  bl        0x1AAC74
	  lwz       r3, 0x1404(r30)
	  addi      r5, r25, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xDE20
	  li        r3, 0x14
	  bl        -0x24940
	  mr.       r6, r3
	  beq-      .loc_0x4E8
	  lwz       r0, 0x264(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x268(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xDC(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0xE0(r1)
	  lwz       r4, 0x26C(r29)
	  stw       r4, 0xE4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x10(r3)

	.loc_0x4E8:
	  lis       r4, 0x1
	  lwz       r3, 0x1404(r30)
	  subi      r5, r4, 0x8000
	  li        r4, 0x8
	  bl        -0xE058
	  li        r3, 0x14
	  bl        -0x249B0
	  mr.       r6, r3
	  beq-      .loc_0x558
	  lwz       r0, 0x270(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x274(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xD0(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0xD4(r1)
	  lwz       r4, 0x278(r29)
	  stw       r4, 0xD8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xD8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x558:
	  lwz       r3, 0x1404(r30)
	  li        r4, 0x8
	  li        r5, 0x4000
	  bl        -0xE0C4
	  li        r3, 0x40
	  bl        -0x24A1C
	  lis       r4, 0x803A
	  crset     6, 0x6
	  subi      r4, r4, 0x2848
	  lfs       f1, 0x2F0(r4)
	  addi      r25, r3, 0
	  addi      r4, r29, 0x2C8
	  bl        0x1AAB5C
	  lwz       r3, 0x1404(r30)
	  addi      r5, r25, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xDF38
	  li        r3, 0x14
	  bl        -0x24A58
	  mr.       r6, r3
	  beq-      .loc_0x600
	  lwz       r0, 0x27C(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x280(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xC4(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0xC8(r1)
	  lwz       r4, 0x284(r29)
	  stw       r4, 0xCC(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xC4(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xCC(r1)
	  stw       r0, 0x10(r3)

	.loc_0x600:
	  lis       r4, 0x1
	  lwz       r3, 0x1404(r30)
	  subi      r5, r4, 0x8000
	  li        r4, 0x4
	  bl        -0xE170
	  li        r3, 0x14
	  bl        -0x24AC8
	  mr.       r6, r3
	  beq-      .loc_0x670
	  lwz       r0, 0x288(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x28C(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xB8(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0xBC(r1)
	  lwz       r4, 0x290(r29)
	  stw       r4, 0xC0(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x10(r3)

	.loc_0x670:
	  lwz       r3, 0x1404(r30)
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xE1DC
	  lwz       r3, 0x1404(r30)
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xE02C
	  li        r3, 0x14
	  bl        -0x24B4C
	  mr.       r6, r3
	  beq-      .loc_0x6F4
	  lwz       r0, 0x294(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x298(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xAC(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0xB0(r1)
	  lwz       r4, 0x29C(r29)
	  stw       r4, 0xB4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x10(r3)

	.loc_0x6F4:
	  lwz       r3, 0x1404(r30)
	  addi      r5, r29, 0x2D8
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0xE09C
	  lwz       r3, 0x1404(r30)
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xE0B4
	  li        r3, 0x40
	  bl        -0x24BD4
	  lis       r4, 0x803A
	  crset     6, 0x6
	  subi      r4, r4, 0x2848
	  addi      r27, r4, 0x20
	  lwz       r4, 0x20(r4)
	  mr        r28, r3
	  lfs       f1, 0x50(r4)
	  addi      r4, r29, 0x2E8
	  bl        0x1AA99C
	  li        r3, 0xB8
	  bl        -0x24C00
	  mr.       r31, r3
	  beq-      .loc_0xAE8
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r31
	  lwz       r6, 0x1400(r30)
	  mr        r4, r26
	  lwz       r5, 0x10(r5)
	  addi      r25, r6, 0x13F8
	  li        r6, 0
	  bl        -0xE534
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6578
	  stw       r0, 0x0(r31)
	  li        r6, 0x20
	  li        r5, 0x80
	  stw       r25, 0xB4(r31)
	  li        r4, 0xC0
	  li        r0, 0x40
	  lwz       r7, -0x7848(r13)
	  li        r3, 0x14
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r31)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  addi      r7, r7, 0x3C
	  stw       r7, 0x4C(r31)
	  stb       r6, 0x60(r31)
	  stb       r5, 0x61(r31)
	  stb       r6, 0x62(r31)
	  stb       r4, 0x63(r31)
	  stb       r6, 0x64(r31)
	  stb       r0, 0x65(r31)
	  stb       r6, 0x66(r31)
	  stb       r0, 0x67(r31)
	  bl        -0x24C94
	  mr.       r6, r3
	  beq-      .loc_0x83C
	  lwz       r0, 0x24C(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x250(r29)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x84(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x88(r1)
	  lwz       r4, 0x254(r29)
	  stw       r4, 0x8C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x84(r1)
	  lwz       r0, 0x88(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x8C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x83C:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xE3A8
	  li        r3, 0xC0
	  bl        -0x24D00
	  mr.       r25, r3
	  beq-      .loc_0x87C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r8, 0xB4(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x13E8
	  bl        -0x1618

	.loc_0x87C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x2FC
	  li        r5, 0
	  bl        -0xE090
	  li        r3, 0xC4
	  bl        -0x24D44
	  mr.       r25, r3
	  beq-      .loc_0x8C8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r6, 0xB4(r31)
	  li        r9, 0x1
	  lwz       r7, 0x58(r31)
	  lwz       r8, 0x10(r4)
	  addi      r4, r6, 0x13F4
	  addi      r5, r6, 0x13EC
	  addi      r6, r6, 0x13F0
	  bl        0x17E8

	.loc_0x8C8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  li        r5, 0
	  subi      r6, r13, 0x69A0
	  bl        -0xE0DC
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xE288
	  li        r3, 0xCC
	  bl        -0x24DA8
	  mr.       r25, r3
	  beq-      .loc_0x924
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r4, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r7, 0x10(r5)
	  lwz       r6, 0x58(r31)
	  addi      r5, r4, 0x13CC
	  bl        .loc_0x1B80

	.loc_0x924:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x30C
	  li        r5, 0
	  bl        -0xE138
	  li        r3, 0xCC
	  bl        -0x24DEC
	  mr.       r25, r3
	  beq-      .loc_0x96C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x2D4
	  addi      r5, r5, 0x13D0
	  bl        .loc_0x1B80

	.loc_0x96C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x318
	  li        r5, 0
	  bl        -0xE180
	  li        r3, 0xCC
	  bl        -0x24E34
	  mr.       r25, r3
	  beq-      .loc_0x9B4
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x5A8
	  addi      r5, r5, 0x13D4
	  bl        .loc_0x1B80

	.loc_0x9B4:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x324
	  li        r5, 0
	  bl        -0xE1C8
	  li        r3, 0xCC
	  bl        -0x24E7C
	  mr.       r25, r3
	  beq-      .loc_0x9FC
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x87C
	  addi      r5, r5, 0x13D8
	  bl        .loc_0x1B80

	.loc_0x9FC:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x330
	  li        r5, 0
	  bl        -0xE210
	  li        r3, 0xCC
	  bl        -0x24EC4
	  mr.       r25, r3
	  beq-      .loc_0xA44
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xB50
	  addi      r5, r5, 0x13DC
	  bl        .loc_0x1B80

	.loc_0xA44:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x33C
	  li        r5, 0
	  bl        -0xE258
	  li        r3, 0xCC
	  bl        -0x24F0C
	  mr.       r25, r3
	  beq-      .loc_0xA8C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xE24
	  addi      r5, r5, 0x13E0
	  bl        .loc_0x1B80

	.loc_0xA8C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x348
	  li        r5, 0
	  bl        -0xE2A0
	  li        r3, 0xCC
	  bl        -0x24F54
	  mr.       r25, r3
	  beq-      .loc_0xAD4
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x10F8
	  addi      r5, r5, 0x13E4
	  bl        .loc_0x1B80

	.loc_0xAD4:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x354
	  li        r5, 0
	  bl        -0xE2E8

	.loc_0xAE8:
	  lwz       r3, 0x1404(r30)
	  addi      r4, r31, 0
	  addi      r6, r28, 0
	  li        r5, 0
	  bl        -0xE2FC
	  li        r3, 0x40
	  bl        -0x24FB0
	  lwz       r5, 0x0(r27)
	  crset     6, 0x6
	  mr        r28, r3
	  lfs       f2, 0x70(r5)
	  addi      r4, r29, 0x360
	  lfs       f1, 0x60(r5)
	  bl        0x1AA5C8
	  li        r3, 0xB8
	  bl        -0x24FD4
	  mr.       r31, r3
	  beq-      .loc_0xEBC
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r31
	  lwz       r6, 0x1400(r30)
	  mr        r4, r26
	  lwz       r5, 0x10(r5)
	  addi      r25, r6, 0x27F0
	  li        r6, 0
	  bl        -0xE908
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6578
	  stw       r0, 0x0(r31)
	  li        r6, 0x20
	  li        r5, 0x80
	  stw       r25, 0xB4(r31)
	  li        r4, 0xC0
	  li        r0, 0x40
	  lwz       r7, -0x7848(r13)
	  li        r3, 0x14
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r31)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  addi      r7, r7, 0x3C
	  stw       r7, 0x4C(r31)
	  stb       r6, 0x60(r31)
	  stb       r5, 0x61(r31)
	  stb       r6, 0x62(r31)
	  stb       r4, 0x63(r31)
	  stb       r6, 0x64(r31)
	  stb       r0, 0x65(r31)
	  stb       r6, 0x66(r31)
	  stb       r0, 0x67(r31)
	  bl        -0x25068
	  mr.       r6, r3
	  beq-      .loc_0xC10
	  lwz       r0, 0x24C(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x250(r29)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x70(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x74(r1)
	  lwz       r4, 0x254(r29)
	  stw       r4, 0x78(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x10(r3)

	.loc_0xC10:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xE77C
	  li        r3, 0xC0
	  bl        -0x250D4
	  mr.       r25, r3
	  beq-      .loc_0xC50
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r8, 0xB4(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x13E8
	  bl        -0x19EC

	.loc_0xC50:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x2FC
	  li        r5, 0
	  bl        -0xE464
	  li        r3, 0xC4
	  bl        -0x25118
	  mr.       r25, r3
	  beq-      .loc_0xC9C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r6, 0xB4(r31)
	  li        r9, 0x1
	  lwz       r7, 0x58(r31)
	  lwz       r8, 0x10(r4)
	  addi      r4, r6, 0x13F4
	  addi      r5, r6, 0x13EC
	  addi      r6, r6, 0x13F0
	  bl        0x1414

	.loc_0xC9C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  li        r5, 0
	  subi      r6, r13, 0x69A0
	  bl        -0xE4B0
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xE65C
	  li        r3, 0xCC
	  bl        -0x2517C
	  mr.       r25, r3
	  beq-      .loc_0xCF8
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r4, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r7, 0x10(r5)
	  lwz       r6, 0x58(r31)
	  addi      r5, r4, 0x13CC
	  bl        .loc_0x1B80

	.loc_0xCF8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x30C
	  li        r5, 0
	  bl        -0xE50C
	  li        r3, 0xCC
	  bl        -0x251C0
	  mr.       r25, r3
	  beq-      .loc_0xD40
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x2D4
	  addi      r5, r5, 0x13D0
	  bl        .loc_0x1B80

	.loc_0xD40:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x318
	  li        r5, 0
	  bl        -0xE554
	  li        r3, 0xCC
	  bl        -0x25208
	  mr.       r25, r3
	  beq-      .loc_0xD88
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x5A8
	  addi      r5, r5, 0x13D4
	  bl        .loc_0x1B80

	.loc_0xD88:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x324
	  li        r5, 0
	  bl        -0xE59C
	  li        r3, 0xCC
	  bl        -0x25250
	  mr.       r25, r3
	  beq-      .loc_0xDD0
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x87C
	  addi      r5, r5, 0x13D8
	  bl        .loc_0x1B80

	.loc_0xDD0:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x330
	  li        r5, 0
	  bl        -0xE5E4
	  li        r3, 0xCC
	  bl        -0x25298
	  mr.       r25, r3
	  beq-      .loc_0xE18
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xB50
	  addi      r5, r5, 0x13DC
	  bl        .loc_0x1B80

	.loc_0xE18:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x33C
	  li        r5, 0
	  bl        -0xE62C
	  li        r3, 0xCC
	  bl        -0x252E0
	  mr.       r25, r3
	  beq-      .loc_0xE60
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xE24
	  addi      r5, r5, 0x13E0
	  bl        .loc_0x1B80

	.loc_0xE60:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x348
	  li        r5, 0
	  bl        -0xE674
	  li        r3, 0xCC
	  bl        -0x25328
	  mr.       r25, r3
	  beq-      .loc_0xEA8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x10F8
	  addi      r5, r5, 0x13E4
	  bl        .loc_0x1B80

	.loc_0xEA8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x354
	  li        r5, 0
	  bl        -0xE6BC

	.loc_0xEBC:
	  lwz       r3, 0x1404(r30)
	  addi      r4, r31, 0
	  addi      r6, r28, 0
	  li        r5, 0
	  bl        -0xE6D0
	  li        r3, 0x40
	  bl        -0x25384
	  lwz       r4, 0x0(r27)
	  crset     6, 0x6
	  addi      r28, r3, 0
	  lfs       f1, 0x80(r4)
	  addi      r4, r29, 0x37C
	  bl        0x1AA1F8
	  li        r3, 0xB8
	  bl        -0x253A4
	  mr.       r31, r3
	  beq-      .loc_0x128C
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r31
	  lwz       r6, 0x1400(r30)
	  mr        r4, r26
	  lwz       r5, 0x10(r5)
	  addi      r25, r6, 0x3BE8
	  li        r6, 0
	  bl        -0xECD8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6578
	  stw       r0, 0x0(r31)
	  li        r6, 0x20
	  li        r5, 0x80
	  stw       r25, 0xB4(r31)
	  li        r4, 0xC0
	  li        r0, 0x40
	  lwz       r7, -0x7848(r13)
	  li        r3, 0x14
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r31)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  addi      r7, r7, 0x3C
	  stw       r7, 0x4C(r31)
	  stb       r6, 0x60(r31)
	  stb       r5, 0x61(r31)
	  stb       r6, 0x62(r31)
	  stb       r4, 0x63(r31)
	  stb       r6, 0x64(r31)
	  stb       r0, 0x65(r31)
	  stb       r6, 0x66(r31)
	  stb       r0, 0x67(r31)
	  bl        -0x25438
	  mr.       r6, r3
	  beq-      .loc_0xFE0
	  lwz       r0, 0x24C(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x250(r29)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x60(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x64(r1)
	  lwz       r4, 0x254(r29)
	  stw       r4, 0x68(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x60(r1)
	  lwz       r0, 0x64(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x68(r1)
	  stw       r0, 0x10(r3)

	.loc_0xFE0:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xEB4C
	  li        r3, 0xC0
	  bl        -0x254A4
	  mr.       r25, r3
	  beq-      .loc_0x1020
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r8, 0xB4(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x13E8
	  bl        -0x1DBC

	.loc_0x1020:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x2FC
	  li        r5, 0
	  bl        -0xE834
	  li        r3, 0xC4
	  bl        -0x254E8
	  mr.       r25, r3
	  beq-      .loc_0x106C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r6, 0xB4(r31)
	  li        r9, 0x1
	  lwz       r7, 0x58(r31)
	  lwz       r8, 0x10(r4)
	  addi      r4, r6, 0x13F4
	  addi      r5, r6, 0x13EC
	  addi      r6, r6, 0x13F0
	  bl        0x1044

	.loc_0x106C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  li        r5, 0
	  subi      r6, r13, 0x69A0
	  bl        -0xE880
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xEA2C
	  li        r3, 0xCC
	  bl        -0x2554C
	  mr.       r25, r3
	  beq-      .loc_0x10C8
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r4, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r7, 0x10(r5)
	  lwz       r6, 0x58(r31)
	  addi      r5, r4, 0x13CC
	  bl        .loc_0x1B80

	.loc_0x10C8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x30C
	  li        r5, 0
	  bl        -0xE8DC
	  li        r3, 0xCC
	  bl        -0x25590
	  mr.       r25, r3
	  beq-      .loc_0x1110
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x2D4
	  addi      r5, r5, 0x13D0
	  bl        .loc_0x1B80

	.loc_0x1110:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x318
	  li        r5, 0
	  bl        -0xE924
	  li        r3, 0xCC
	  bl        -0x255D8
	  mr.       r25, r3
	  beq-      .loc_0x1158
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x5A8
	  addi      r5, r5, 0x13D4
	  bl        .loc_0x1B80

	.loc_0x1158:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x324
	  li        r5, 0
	  bl        -0xE96C
	  li        r3, 0xCC
	  bl        -0x25620
	  mr.       r25, r3
	  beq-      .loc_0x11A0
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x87C
	  addi      r5, r5, 0x13D8
	  bl        .loc_0x1B80

	.loc_0x11A0:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x330
	  li        r5, 0
	  bl        -0xE9B4
	  li        r3, 0xCC
	  bl        -0x25668
	  mr.       r25, r3
	  beq-      .loc_0x11E8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xB50
	  addi      r5, r5, 0x13DC
	  bl        .loc_0x1B80

	.loc_0x11E8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x33C
	  li        r5, 0
	  bl        -0xE9FC
	  li        r3, 0xCC
	  bl        -0x256B0
	  mr.       r25, r3
	  beq-      .loc_0x1230
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xE24
	  addi      r5, r5, 0x13E0
	  bl        .loc_0x1B80

	.loc_0x1230:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x348
	  li        r5, 0
	  bl        -0xEA44
	  li        r3, 0xCC
	  bl        -0x256F8
	  mr.       r25, r3
	  beq-      .loc_0x1278
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x10F8
	  addi      r5, r5, 0x13E4
	  bl        .loc_0x1B80

	.loc_0x1278:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x354
	  li        r5, 0
	  bl        -0xEA8C

	.loc_0x128C:
	  lwz       r3, 0x1404(r30)
	  addi      r4, r31, 0
	  addi      r6, r28, 0
	  li        r5, 0
	  bl        -0xEAA0
	  li        r3, 0x40
	  bl        -0x25754
	  lwz       r5, 0x0(r27)
	  crset     6, 0x6
	  mr        r28, r3
	  lfs       f2, 0x40(r5)
	  addi      r4, r29, 0x390
	  lfs       f1, 0x90(r5)
	  bl        0x1A9E24
	  li        r3, 0xB8
	  bl        -0x25778
	  addi      r27, r3, 0
	  mr.       r31, r27
	  beq-      .loc_0x1660
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r31
	  lwz       r25, 0x1400(r30)
	  mr        r4, r26
	  lwz       r5, 0x10(r5)
	  li        r6, 0
	  bl        -0xF0AC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6578
	  stw       r0, 0x0(r27)
	  li        r6, 0x20
	  li        r5, 0x80
	  stw       r25, 0xB4(r27)
	  li        r4, 0xC0
	  li        r0, 0x40
	  lwz       r7, -0x7848(r13)
	  li        r3, 0x14
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r27)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  addi      r7, r7, 0x3C
	  stw       r7, 0x4C(r27)
	  stb       r6, 0x60(r27)
	  stb       r5, 0x61(r27)
	  stb       r6, 0x62(r27)
	  stb       r4, 0x63(r27)
	  stb       r6, 0x64(r27)
	  stb       r0, 0x65(r27)
	  stb       r6, 0x66(r27)
	  stb       r0, 0x67(r27)
	  bl        -0x2580C
	  mr.       r6, r3
	  beq-      .loc_0x13B4
	  lwz       r0, 0x24C(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x250(r29)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x4C(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x50(r1)
	  lwz       r4, 0x254(r29)
	  stw       r4, 0x54(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r27, 0x4(r3)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x10(r3)

	.loc_0x13B4:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xEF20
	  li        r3, 0xC0
	  bl        -0x25878
	  mr.       r25, r3
	  beq-      .loc_0x13F4
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r8, 0xB4(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x13E8
	  bl        -0x2190

	.loc_0x13F4:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x2FC
	  li        r5, 0
	  bl        -0xEC08
	  li        r3, 0xC4
	  bl        -0x258BC
	  mr.       r25, r3
	  beq-      .loc_0x1440
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r6, 0xB4(r31)
	  li        r9, 0x1
	  lwz       r7, 0x58(r31)
	  lwz       r8, 0x10(r4)
	  addi      r4, r6, 0x13F4
	  addi      r5, r6, 0x13EC
	  addi      r6, r6, 0x13F0
	  bl        0xC70

	.loc_0x1440:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  li        r5, 0
	  subi      r6, r13, 0x69A0
	  bl        -0xEC54
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xEE00
	  li        r3, 0xCC
	  bl        -0x25920
	  mr.       r25, r3
	  beq-      .loc_0x149C
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r4, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r7, 0x10(r5)
	  lwz       r6, 0x58(r31)
	  addi      r5, r4, 0x13CC
	  bl        .loc_0x1B80

	.loc_0x149C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x30C
	  li        r5, 0
	  bl        -0xECB0
	  li        r3, 0xCC
	  bl        -0x25964
	  mr.       r25, r3
	  beq-      .loc_0x14E4
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x2D4
	  addi      r5, r5, 0x13D0
	  bl        .loc_0x1B80

	.loc_0x14E4:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x318
	  li        r5, 0
	  bl        -0xECF8
	  li        r3, 0xCC
	  bl        -0x259AC
	  mr.       r25, r3
	  beq-      .loc_0x152C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x5A8
	  addi      r5, r5, 0x13D4
	  bl        .loc_0x1B80

	.loc_0x152C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x324
	  li        r5, 0
	  bl        -0xED40
	  li        r3, 0xCC
	  bl        -0x259F4
	  mr.       r25, r3
	  beq-      .loc_0x1574
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x87C
	  addi      r5, r5, 0x13D8
	  bl        .loc_0x1B80

	.loc_0x1574:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x330
	  li        r5, 0
	  bl        -0xED88
	  li        r3, 0xCC
	  bl        -0x25A3C
	  mr.       r25, r3
	  beq-      .loc_0x15BC
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xB50
	  addi      r5, r5, 0x13DC
	  bl        .loc_0x1B80

	.loc_0x15BC:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x33C
	  li        r5, 0
	  bl        -0xEDD0
	  li        r3, 0xCC
	  bl        -0x25A84
	  mr.       r25, r3
	  beq-      .loc_0x1604
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xE24
	  addi      r5, r5, 0x13E0
	  bl        .loc_0x1B80

	.loc_0x1604:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x348
	  li        r5, 0
	  bl        -0xEE18
	  li        r3, 0xCC
	  bl        -0x25ACC
	  mr.       r25, r3
	  beq-      .loc_0x164C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x10F8
	  addi      r5, r5, 0x13E4
	  bl        .loc_0x1B80

	.loc_0x164C:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x354
	  li        r5, 0
	  bl        -0xEE60

	.loc_0x1660:
	  lwz       r3, 0x1404(r30)
	  addi      r4, r31, 0
	  addi      r6, r28, 0
	  li        r5, 0
	  bl        -0xEE74
	  li        r3, 0x40
	  bl        -0x25B28
	  lfd       f1, -0x77E0(r2)
	  crset     6, 0x6
	  addi      r28, r3, 0
	  fmr       f2, f1
	  addi      r4, r29, 0x3AC
	  bl        0x1A9A54
	  li        r3, 0xB8
	  bl        -0x25B48
	  addi      r27, r3, 0
	  mr.       r31, r27
	  beq-      .loc_0x1A34
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r31
	  lwz       r6, 0x1400(r30)
	  mr        r4, r26
	  lwz       r5, 0x10(r5)
	  addi      r25, r6, 0x4FE0
	  li        r6, 0
	  bl        -0xF480
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6578
	  stw       r0, 0x0(r27)
	  li        r6, 0x20
	  li        r5, 0x80
	  stw       r25, 0xB4(r27)
	  li        r4, 0xC0
	  li        r0, 0x40
	  lwz       r7, -0x7848(r13)
	  li        r3, 0x14
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r27)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  addi      r7, r7, 0x3C
	  stw       r7, 0x4C(r27)
	  stb       r6, 0x60(r27)
	  stb       r5, 0x61(r27)
	  stb       r6, 0x62(r27)
	  stb       r4, 0x63(r27)
	  stb       r6, 0x64(r27)
	  stb       r0, 0x65(r27)
	  stb       r6, 0x66(r27)
	  stb       r0, 0x67(r27)
	  bl        -0x25BE0
	  mr.       r6, r3
	  beq-      .loc_0x1788
	  lwz       r0, 0x24C(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x250(r29)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x40(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x44(r1)
	  lwz       r4, 0x254(r29)
	  stw       r4, 0x48(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r27, 0x4(r3)
	  lwz       r4, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1788:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xF2F4
	  li        r3, 0xC0
	  bl        -0x25C4C
	  mr.       r25, r3
	  beq-      .loc_0x17C8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r8, 0xB4(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x13E8
	  bl        -0x2564

	.loc_0x17C8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x2FC
	  li        r5, 0
	  bl        -0xEFDC
	  li        r3, 0xC4
	  bl        -0x25C90
	  mr.       r25, r3
	  beq-      .loc_0x1814
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r6, 0xB4(r31)
	  li        r9, 0x1
	  lwz       r7, 0x58(r31)
	  lwz       r8, 0x10(r4)
	  addi      r4, r6, 0x13F4
	  addi      r5, r6, 0x13EC
	  addi      r6, r6, 0x13F0
	  bl        0x89C

	.loc_0x1814:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  li        r5, 0
	  subi      r6, r13, 0x69A0
	  bl        -0xF028
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xF1D4
	  li        r3, 0xCC
	  bl        -0x25CF4
	  mr.       r25, r3
	  beq-      .loc_0x1870
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r4, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r7, 0x10(r5)
	  lwz       r6, 0x58(r31)
	  addi      r5, r4, 0x13CC
	  bl        .loc_0x1B80

	.loc_0x1870:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x30C
	  li        r5, 0
	  bl        -0xF084
	  li        r3, 0xCC
	  bl        -0x25D38
	  mr.       r25, r3
	  beq-      .loc_0x18B8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x2D4
	  addi      r5, r5, 0x13D0
	  bl        .loc_0x1B80

	.loc_0x18B8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x318
	  li        r5, 0
	  bl        -0xF0CC
	  li        r3, 0xCC
	  bl        -0x25D80
	  mr.       r25, r3
	  beq-      .loc_0x1900
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x5A8
	  addi      r5, r5, 0x13D4
	  bl        .loc_0x1B80

	.loc_0x1900:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x324
	  li        r5, 0
	  bl        -0xF114
	  li        r3, 0xCC
	  bl        -0x25DC8
	  mr.       r25, r3
	  beq-      .loc_0x1948
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x87C
	  addi      r5, r5, 0x13D8
	  bl        .loc_0x1B80

	.loc_0x1948:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x330
	  li        r5, 0
	  bl        -0xF15C
	  li        r3, 0xCC
	  bl        -0x25E10
	  mr.       r25, r3
	  beq-      .loc_0x1990
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xB50
	  addi      r5, r5, 0x13DC
	  bl        .loc_0x1B80

	.loc_0x1990:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x33C
	  li        r5, 0
	  bl        -0xF1A4
	  li        r3, 0xCC
	  bl        -0x25E58
	  mr.       r25, r3
	  beq-      .loc_0x19D8
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0xE24
	  addi      r5, r5, 0x13E0
	  bl        .loc_0x1B80

	.loc_0x19D8:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x348
	  li        r5, 0
	  bl        -0xF1EC
	  li        r3, 0xCC
	  bl        -0x25EA0
	  mr.       r25, r3
	  beq-      .loc_0x1A20
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r25
	  lwz       r5, 0xB4(r31)
	  li        r8, 0x1
	  lwz       r6, 0x58(r31)
	  lwz       r7, 0x10(r4)
	  addi      r4, r5, 0x10F8
	  addi      r5, r5, 0x13E4
	  bl        .loc_0x1B80

	.loc_0x1A20:
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r6, r29, 0x354
	  li        r5, 0
	  bl        -0xF234

	.loc_0x1A34:
	  lwz       r3, 0x1404(r30)
	  addi      r4, r31, 0
	  addi      r6, r28, 0
	  li        r5, 0
	  bl        -0xF248
	  lwz       r0, 0x1414(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B68
	  li        r3, 0x40
	  bl        -0x25F08
	  lwz       r4, 0x1414(r30)
	  crclr     6, 0x6
	  addi      r25, r3, 0
	  lwz       r5, 0x4BC(r4)
	  addi      r4, r29, 0x3C8
	  bl        0x1A9674
	  lwz       r3, 0x1404(r30)
	  addi      r5, r25, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xF420
	  li        r3, 0x14
	  bl        -0x25F40
	  mr.       r6, r3
	  beq-      .loc_0x1AE8
	  lwz       r0, 0x2A0(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x2A4(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xA0(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0xA4(r1)
	  lwz       r4, 0x2A8(r29)
	  stw       r4, 0xA8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1AE8:
	  lis       r4, 0x1
	  lwz       r3, 0x1404(r30)
	  subi      r5, r4, 0x8000
	  li        r4, 0x4
	  bl        -0xF658
	  li        r3, 0x14
	  bl        -0x25FB0
	  mr.       r6, r3
	  beq-      .loc_0x1B58
	  lwz       r0, 0x2AC(r29)
	  lis       r5, 0x802A
	  lwz       r7, 0x2B0(r29)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x94(r1)
	  subi      r0, r4, 0x64FC
	  stw       r7, 0x98(r1)
	  lwz       r4, 0x2B4(r29)
	  stw       r4, 0x9C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1B58:
	  lwz       r3, 0x1404(r30)
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xF6C4

	.loc_0x1B68:
	  mr        r3, r30
	  lmw       r25, 0xFC(r1)
	  lwz       r0, 0x11C(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr

	.loc_0x1B80:
	*/
}

/*
 * --INFO--
 * Address:	8006D034
 * Size:	00052C
 */
LightMenu::LightMenu(Light*, int*, Controller*, Font*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r9, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x88(r1)
	  subi      r30, r9, 0x6B80
	  stw       r29, 0x84(r1)
	  addi      r29, r5, 0
	  addi      r5, r7, 0
	  stw       r28, 0x80(r1)
	  addi      r28, r4, 0
	  addi      r4, r6, 0
	  addi      r6, r8, 0
	  bl        -0xF978
	  lis       r3, 0x802B
	  subi      r0, r3, 0x65FC
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  subi      r7, r13, 0x69EC
	  stw       r28, 0xBC(r31)
	  li        r6, 0x20
	  li        r5, 0x80
	  stw       r0, 0xB4(r31)
	  li        r4, 0xC0
	  li        r0, 0x40
	  stw       r29, 0xB8(r31)
	  li        r3, 0x14
	  lwz       r9, 0xBC(r31)
	  lwz       r8, 0xB4(r31)
	  addi      r10, r9, 0x14
	  rlwinm    r8,r8,2,0,29
	  lwz       r9, 0x14(r9)
	  lwzx      r7, r7, r8
	  rlwinm    r8,r9,0,0,23
	  or        r7, r8, r7
	  stw       r7, 0x0(r10)
	  lwz       r7, -0x7848(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r31)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x4C(r31)
	  stb       r6, 0x60(r31)
	  stb       r5, 0x61(r31)
	  stb       r5, 0x62(r31)
	  stb       r4, 0x63(r31)
	  stb       r6, 0x64(r31)
	  stb       r0, 0x65(r31)
	  stb       r6, 0x66(r31)
	  stb       r0, 0x67(r31)
	  bl        -0x26108
	  mr.       r6, r3
	  beq-      .loc_0x130
	  lwz       r0, 0x21C(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x220(r30)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x70(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x74(r1)
	  lwz       r4, 0x224(r30)
	  stw       r4, 0x78(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x10(r3)

	.loc_0x130:
	  addi      r3, r31, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xF81C
	  lwz       r4, 0xBC(r31)
	  li        r3, 0x14
	  lwz       r0, 0x14(r4)
	  rlwinm    r0,r0,2,22,29
	  add       r4, r30, r0
	  lwz       r0, 0x19C(r4)
	  stw       r0, 0xB4(r31)
	  bl        -0x2618C
	  mr.       r6, r3
	  beq-      .loc_0x1B4
	  lwz       r0, 0x1BC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1C0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x34(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x38(r1)
	  lwz       r4, 0x1C4(r30)
	  stw       r4, 0x3C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1B4:
	  lwz       r4, 0xBC(r31)
	  mr        r3, r31
	  li        r7, 0x1
	  lwz       r0, 0x14(r4)
	  li        r4, 0
	  rlwinm    r0,r0,2,22,29
	  add       r5, r30, r0
	  lwz       r5, 0x18C(r5)
	  bl        -0xF6EC
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xF704
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  bne-      .loc_0x40C
	  addi      r0, r3, 0x20
	  stw       r0, 0xC0(r31)
	  li        r3, 0x14
	  bl        -0x26240
	  mr.       r6, r3
	  beq-      .loc_0x268
	  lwz       r0, 0x1C8(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1CC(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x40(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x44(r1)
	  lwz       r4, 0x1D0(r30)
	  stw       r4, 0x48(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x10(r3)

	.loc_0x268:
	  lwz       r4, 0xB8(r31)
	  subi      r5, r13, 0x69DC
	  addi      r3, r31, 0
	  lwz       r0, 0x0(r4)
	  li        r4, 0
	  li        r7, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r5, r0
	  bl        -0xF7A0
	  li        r3, 0x40
	  bl        -0x262C0
	  lwz       r4, 0xC0(r31)
	  crset     6, 0x6
	  addi      r29, r3, 0
	  lfs       f1, 0x0(r4)
	  addi      r4, r30, 0x1F8
	  bl        0x1A92BC
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xF7D8
	  li        r3, 0x14
	  bl        -0x262F8
	  mr.       r6, r3
	  beq-      .loc_0x320
	  lwz       r0, 0x1D4(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1D8(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x4C(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x50(r1)
	  lwz       r4, 0x1DC(r30)
	  stw       r4, 0x54(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x10(r3)

	.loc_0x320:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xFA0C
	  li        r3, 0x14
	  bl        -0x26364
	  mr.       r6, r3
	  beq-      .loc_0x38C
	  lwz       r0, 0x1E0(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1E4(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x58(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x5C(r1)
	  lwz       r4, 0x1E8(r30)
	  stw       r4, 0x60(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x10(r3)

	.loc_0x38C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        -0xFA7C
	  li        r3, 0x14
	  bl        -0x263D4
	  mr.       r6, r3
	  beq-      .loc_0x3FC
	  lwz       r0, 0x1EC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1F0(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x64(r1)
	  subi      r0, r4, 0x6318
	  stw       r7, 0x68(r1)
	  lwz       r4, 0x1F4(r30)
	  stw       r4, 0x6C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x3FC:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xFAE8

	.loc_0x40C:
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x468
	  li        r3, 0xC4
	  bl        -0x26454
	  mr.       r28, r3
	  beq-      .loc_0x454
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r28
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x54
	  li        r8, 0
	  bl        -0x2644

	.loc_0x454:
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  addi      r6, r30, 0x204
	  li        r5, 0
	  bl        -0xF7E8

	.loc_0x468:
	  lwz       r3, 0xBC(r31)
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  bne-      .loc_0x4C4
	  li        r3, 0xC4
	  bl        -0x264B0
	  mr.       r28, r3
	  beq-      .loc_0x4B0
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r28
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x60
	  li        r8, 0x1
	  bl        -0x26A0

	.loc_0x4B0:
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  addi      r6, r30, 0x210
	  li        r5, 0
	  bl        -0xF844

	.loc_0x4C4:
	  li        r3, 0xC0
	  bl        -0x264F8
	  mr.       r28, r3
	  beq-      .loc_0x4F4
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r28
	  lwz       r8, 0xBC(r31)
	  li        r7, 0x1
	  lwz       r5, 0x58(r31)
	  lwz       r6, 0x10(r4)
	  addi      r4, r8, 0x6C
	  bl        -0x2E10

	.loc_0x4F4:
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  li        r5, 0
	  subi      r6, r13, 0x69D4
	  bl        -0xF888
	  mr        r3, r31
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  lwz       r28, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006D560
 * Size:	000B30
 */
FogMenu::FogMenu(Colour*, f32*, f32*, Controller*, Font*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r10, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stmw      r26, 0x148(r1)
	  addi      r26, r4, 0
	  addi      r28, r5, 0
	  addi      r27, r6, 0
	  addi      r29, r3, 0
	  addi      r4, r7, 0
	  addi      r5, r8, 0
	  addi      r6, r9, 0
	  subi      r31, r10, 0x6B80
	  bl        -0xFE9C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6680
	  stw       r0, 0x0(r29)
	  li        r7, 0x1
	  li        r6, 0x20
	  stw       r28, 0xB4(r29)
	  li        r5, 0x80
	  li        r4, 0xC0
	  stw       r27, 0xB8(r29)
	  li        r0, 0x40
	  li        r3, 0x14
	  stw       r7, 0xA8(r29)
	  lwz       r7, -0x7848(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r29)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x4C(r29)
	  stb       r6, 0x60(r29)
	  stb       r5, 0x61(r29)
	  stb       r5, 0x62(r29)
	  stb       r4, 0x63(r29)
	  stb       r6, 0x64(r29)
	  stb       r0, 0x65(r29)
	  stb       r6, 0x66(r29)
	  stb       r0, 0x67(r29)
	  bl        -0x26604
	  mr.       r6, r3
	  beq-      .loc_0x100
	  lwz       r0, 0x12C(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x130(r31)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x13C(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x140(r1)
	  lwz       r4, 0x134(r31)
	  stw       r4, 0x144(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x13C(r1)
	  lwz       r0, 0x140(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x144(r1)
	  stw       r0, 0x10(r3)

	.loc_0x100:
	  addi      r3, r29, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xFD18
	  li        r3, 0xC0
	  bl        -0x26670
	  mr.       r30, r3
	  beq-      .loc_0x80C
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r30
	  lwz       r4, 0x58(r29)
	  li        r6, 0x1
	  lwz       r5, 0x10(r5)
	  bl        -0xFF9C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6398
	  stw       r0, 0x0(r30)
	  li        r0, 0x1
	  li        r6, 0x20
	  stw       r26, 0xB4(r30)
	  li        r5, 0x80
	  li        r4, 0xC0
	  stw       r0, 0xA8(r30)
	  li        r0, 0x40
	  li        r3, 0x14
	  lwz       r7, -0x7848(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x48(r30)
	  lwz       r7, -0x7844(r13)
	  srawi     r7, r7, 0x1
	  addze     r7, r7
	  stw       r7, 0x4C(r30)
	  stb       r6, 0x60(r30)
	  stb       r5, 0x61(r30)
	  stb       r5, 0x62(r30)
	  stb       r4, 0x63(r30)
	  stb       r6, 0x64(r30)
	  stb       r0, 0x65(r30)
	  stb       r6, 0x66(r30)
	  stb       r0, 0x67(r30)
	  bl        -0x26700
	  mr.       r6, r3
	  beq-      .loc_0x1FC
	  lwz       r0, 0x90(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x94(r31)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x58(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x5C(r1)
	  lwz       r4, 0x98(r31)
	  stw       r4, 0x60(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1FC:
	  addi      r3, r30, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0xFE14
	  li        r3, 0x40
	  bl        -0x2676C
	  lwz       r4, 0xB4(r30)
	  crclr     6, 0x6
	  addi      r26, r3, 0
	  lbz       r5, 0x0(r4)
	  subi      r4, r13, 0x69C8
	  bl        0x1A8E10
	  addi      r3, r30, 0
	  addi      r5, r26, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xFC84
	  li        r3, 0x14
	  bl        -0x267A4
	  mr.       r6, r3
	  beq-      .loc_0x2A0
	  lwz       r0, 0x9C(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xA0(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x64(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x68(r1)
	  lwz       r4, 0xA4(r31)
	  stw       r4, 0x6C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x2A0:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0xFEB8
	  li        r3, 0x14
	  bl        -0x26810
	  mr.       r6, r3
	  beq-      .loc_0x30C
	  lwz       r0, 0xA8(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xAC(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x70(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x74(r1)
	  lwz       r4, 0xB0(r31)
	  stw       r4, 0x78(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x10(r3)

	.loc_0x30C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        -0xFF28
	  li        r3, 0x14
	  bl        -0x26880
	  mr.       r6, r3
	  beq-      .loc_0x37C
	  lwz       r0, 0xB4(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xB8(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x7C(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x80(r1)
	  lwz       r4, 0xBC(r31)
	  stw       r4, 0x84(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x7C(r1)
	  lwz       r0, 0x80(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x10(r3)

	.loc_0x37C:
	  addi      r3, r30, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0xFF94
	  li        r3, 0x40
	  bl        -0x268EC
	  lwz       r4, 0xB4(r30)
	  crclr     6, 0x6
	  addi      r26, r3, 0
	  lbz       r5, 0x1(r4)
	  subi      r4, r13, 0x69C0
	  bl        0x1A8C90
	  addi      r3, r30, 0
	  addi      r5, r26, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xFE04
	  li        r3, 0x14
	  bl        -0x26924
	  mr.       r6, r3
	  beq-      .loc_0x420
	  lwz       r0, 0xC0(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xC4(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x88(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x8C(r1)
	  lwz       r4, 0xC8(r31)
	  stw       r4, 0x90(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x10(r3)

	.loc_0x420:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0x10038
	  li        r3, 0x14
	  bl        -0x26990
	  mr.       r6, r3
	  beq-      .loc_0x48C
	  lwz       r0, 0xCC(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xD0(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x94(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0x98(r1)
	  lwz       r4, 0xD4(r31)
	  stw       r4, 0x9C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x48C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        -0x100A8
	  li        r3, 0x14
	  bl        -0x26A00
	  mr.       r6, r3
	  beq-      .loc_0x4FC
	  lwz       r0, 0xD8(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xDC(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xA0(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xA4(r1)
	  lwz       r4, 0xE0(r31)
	  stw       r4, 0xA8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x4FC:
	  addi      r3, r30, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0x10114
	  li        r3, 0x40
	  bl        -0x26A6C
	  lwz       r4, 0xB4(r30)
	  crclr     6, 0x6
	  addi      r26, r3, 0
	  lbz       r5, 0x2(r4)
	  subi      r4, r13, 0x69B8
	  bl        0x1A8B10
	  addi      r3, r30, 0
	  addi      r5, r26, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0xFF84
	  li        r3, 0x14
	  bl        -0x26AA4
	  mr.       r6, r3
	  beq-      .loc_0x5A0
	  lwz       r0, 0xE4(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xE8(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xAC(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xB0(r1)
	  lwz       r4, 0xEC(r31)
	  stw       r4, 0xB4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x10(r3)

	.loc_0x5A0:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0x101B8
	  li        r3, 0x14
	  bl        -0x26B10
	  mr.       r6, r3
	  beq-      .loc_0x60C
	  lwz       r0, 0xF0(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xF4(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xB8(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xBC(r1)
	  lwz       r4, 0xF8(r31)
	  stw       r4, 0xC0(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x10(r3)

	.loc_0x60C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        -0x10228
	  li        r3, 0x14
	  bl        -0x26B80
	  mr.       r6, r3
	  beq-      .loc_0x67C
	  lwz       r0, 0xFC(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x100(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xC4(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xC8(r1)
	  lwz       r4, 0x104(r31)
	  stw       r4, 0xCC(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xC4(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xCC(r1)
	  stw       r0, 0x10(r3)

	.loc_0x67C:
	  addi      r3, r30, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0x10294
	  li        r3, 0x40
	  bl        -0x26BEC
	  lwz       r4, 0xB4(r30)
	  crclr     6, 0x6
	  addi      r26, r3, 0
	  lbz       r5, 0x3(r4)
	  subi      r4, r13, 0x69B0
	  bl        0x1A8990
	  addi      r3, r30, 0
	  addi      r5, r26, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x10104
	  li        r3, 0x14
	  bl        -0x26C24
	  mr.       r6, r3
	  beq-      .loc_0x720
	  lwz       r0, 0x108(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x10C(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xD0(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xD4(r1)
	  lwz       r4, 0x110(r31)
	  stw       r4, 0xD8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xD8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x720:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0x10338
	  li        r3, 0x14
	  bl        -0x26C90
	  mr.       r6, r3
	  beq-      .loc_0x78C
	  lwz       r0, 0x114(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x118(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xDC(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xE0(r1)
	  lwz       r4, 0x11C(r31)
	  stw       r4, 0xE4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x10(r3)

	.loc_0x78C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        -0x103A8
	  li        r3, 0x14
	  bl        -0x26D00
	  mr.       r6, r3
	  beq-      .loc_0x7FC
	  lwz       r0, 0x120(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x124(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xE8(r1)
	  subi      r0, r4, 0x6404
	  stw       r7, 0xEC(r1)
	  lwz       r4, 0x128(r31)
	  stw       r4, 0xF0(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xE8(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0x10(r3)

	.loc_0x7FC:
	  addi      r3, r30, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0x10414

	.loc_0x80C:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r6, r31, 0x3D4
	  li        r5, 0
	  bl        -0x100CC
	  li        r3, 0x40
	  bl        -0x26D80
	  lfs       f1, 0x0(r28)
	  crset     6, 0x6
	  addi      r26, r3, 0
	  addi      r4, r31, 0x3E0
	  bl        0x1A8800
	  addi      r3, r29, 0
	  addi      r5, r26, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x10294
	  li        r3, 0x14
	  bl        -0x26DB4
	  mr.       r6, r3
	  beq-      .loc_0x8B0
	  lwz       r0, 0x138(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x13C(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x130(r1)
	  subi      r0, r4, 0x66F8
	  stw       r7, 0x134(r1)
	  lwz       r4, 0x140(r31)
	  stw       r4, 0x138(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x138(r1)
	  stw       r0, 0x10(r3)

	.loc_0x8B0:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0x104C8
	  li        r3, 0x14
	  bl        -0x26E20
	  mr.       r6, r3
	  beq-      .loc_0x91C
	  lwz       r0, 0x144(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x148(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x124(r1)
	  subi      r0, r4, 0x66F8
	  stw       r7, 0x128(r1)
	  lwz       r4, 0x14C(r31)
	  stw       r4, 0x12C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x124(r1)
	  lwz       r0, 0x128(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x12C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x91C:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r29, 0
	  li        r4, 0x4
	  bl        -0x10538
	  li        r3, 0x14
	  bl        -0x26E90
	  mr.       r6, r3
	  beq-      .loc_0x98C
	  lwz       r0, 0x150(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x154(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x118(r1)
	  subi      r0, r4, 0x66F8
	  stw       r7, 0x11C(r1)
	  lwz       r4, 0x158(r31)
	  stw       r4, 0x120(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x118(r1)
	  lwz       r0, 0x11C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x120(r1)
	  stw       r0, 0x10(r3)

	.loc_0x98C:
	  addi      r3, r29, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0x105A4
	  li        r3, 0x40
	  bl        -0x26EFC
	  lfs       f1, 0x0(r27)
	  crset     6, 0x6
	  addi      r26, r3, 0
	  addi      r4, r31, 0x3EC
	  bl        0x1A8684
	  addi      r3, r29, 0
	  addi      r5, r26, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x10410
	  li        r3, 0x14
	  bl        -0x26F30
	  mr.       r6, r3
	  beq-      .loc_0xA2C
	  lwz       r0, 0x15C(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x160(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x10C(r1)
	  subi      r0, r4, 0x66F8
	  stw       r7, 0x110(r1)
	  lwz       r4, 0x164(r31)
	  stw       r4, 0x114(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x114(r1)
	  stw       r0, 0x10(r3)

	.loc_0xA2C:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0x10644
	  li        r3, 0x14
	  bl        -0x26F9C
	  mr.       r6, r3
	  beq-      .loc_0xA98
	  lwz       r0, 0x168(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x16C(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x100(r1)
	  subi      r0, r4, 0x66F8
	  stw       r7, 0x104(r1)
	  lwz       r4, 0x170(r31)
	  stw       r4, 0x108(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x100(r1)
	  lwz       r0, 0x104(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x108(r1)
	  stw       r0, 0x10(r3)

	.loc_0xA98:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r29, 0
	  li        r4, 0x4
	  bl        -0x106B4
	  li        r3, 0x14
	  bl        -0x2700C
	  mr.       r6, r3
	  beq-      .loc_0xB08
	  lwz       r0, 0x174(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x178(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xF4(r1)
	  subi      r0, r4, 0x66F8
	  stw       r7, 0xF8(r1)
	  lwz       r4, 0x17C(r31)
	  stw       r4, 0xFC(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xF4(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xFC(r1)
	  stw       r0, 0x10(r3)

	.loc_0xB08:
	  addi      r3, r29, 0
	  li        r4, 0x4
	  li        r5, 0x4000
	  bl        -0x10720
	  mr        r3, r29
	  lmw       r26, 0x148(r1)
	  lwz       r0, 0x164(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006E090
 * Size:	000314
 */
TimeSetting::TimeSetting()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8003
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x65B8
	  li        r5, 0
	  stwu      r1, -0x20(r1)
	  li        r6, 0x2D4
	  li        r7, 0x7
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        0x1A69B0
	  li        r30, 0xFF
	  stb       r30, 0x6C(r29)
	  li        r31, 0x1
	  addi      r3, r29, 0
	  stb       r30, 0x6D(r29)
	  stb       r30, 0x6E(r29)
	  stb       r30, 0x6F(r29)
	  lfs       f0, -0x6AD8(r13)
	  stfs      f0, 0x54(r29)
	  lfs       f0, -0x6AD4(r13)
	  stfs      f0, 0x58(r29)
	  lfs       f0, -0x6AD0(r13)
	  stfs      f0, 0x5C(r29)
	  lfs       f0, -0x6ACC(r13)
	  stfs      f0, 0x60(r29)
	  lfs       f0, -0x6AC8(r13)
	  stfs      f0, 0x64(r29)
	  lfs       f0, -0x6AC4(r13)
	  stfs      f0, 0x68(r29)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0x18(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x20(r29)
	  stw       r31, 0x14(r29)
	  bl        -0x4425C
	  stb       r30, 0x340(r29)
	  addi      r3, r29, 0x2D4
	  stb       r30, 0x341(r29)
	  stb       r30, 0x342(r29)
	  stb       r30, 0x343(r29)
	  lfs       f0, -0x6AC0(r13)
	  stfs      f0, 0x328(r29)
	  lfs       f0, -0x6ABC(r13)
	  stfs      f0, 0x32C(r29)
	  lfs       f0, -0x6AB8(r13)
	  stfs      f0, 0x330(r29)
	  lfs       f0, -0x6AB4(r13)
	  stfs      f0, 0x334(r29)
	  lfs       f0, -0x6AB0(r13)
	  stfs      f0, 0x338(r29)
	  lfs       f0, -0x6AAC(r13)
	  stfs      f0, 0x33C(r29)
	  lfs       f0, -0x77F4(r2)
	  stfs      f0, 0x2EC(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x2F4(r29)
	  stw       r31, 0x2E8(r29)
	  bl        -0x442B8
	  stb       r30, 0x614(r29)
	  addi      r3, r29, 0x5A8
	  stb       r30, 0x615(r29)
	  stb       r30, 0x616(r29)
	  stb       r30, 0x617(r29)
	  lfs       f0, -0x6AA8(r13)
	  stfs      f0, 0x5FC(r29)
	  lfs       f0, -0x6AA4(r13)
	  stfs      f0, 0x600(r29)
	  lfs       f0, -0x6AA0(r13)
	  stfs      f0, 0x604(r29)
	  lfs       f0, -0x6A9C(r13)
	  stfs      f0, 0x608(r29)
	  lfs       f0, -0x6A98(r13)
	  stfs      f0, 0x60C(r29)
	  lfs       f0, -0x6A94(r13)
	  stfs      f0, 0x610(r29)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0x5C0(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x5C8(r29)
	  stw       r31, 0x5BC(r29)
	  bl        -0x44314
	  stb       r30, 0x8E8(r29)
	  addi      r3, r29, 0x87C
	  stb       r30, 0x8E9(r29)
	  stb       r30, 0x8EA(r29)
	  stb       r30, 0x8EB(r29)
	  lfs       f0, -0x6A90(r13)
	  stfs      f0, 0x8D0(r29)
	  lfs       f0, -0x6A8C(r13)
	  stfs      f0, 0x8D4(r29)
	  lfs       f0, -0x6A88(r13)
	  stfs      f0, 0x8D8(r29)
	  lfs       f0, -0x6A84(r13)
	  stfs      f0, 0x8DC(r29)
	  lfs       f0, -0x6A80(r13)
	  stfs      f0, 0x8E0(r29)
	  lfs       f0, -0x6A7C(r13)
	  stfs      f0, 0x8E4(r29)
	  lfs       f0, -0x77F4(r2)
	  stfs      f0, 0x894(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x89C(r29)
	  stw       r31, 0x890(r29)
	  bl        -0x44370
	  stb       r30, 0xBBC(r29)
	  addi      r3, r29, 0xB50
	  stb       r30, 0xBBD(r29)
	  stb       r30, 0xBBE(r29)
	  stb       r30, 0xBBF(r29)
	  lfs       f0, -0x6A78(r13)
	  stfs      f0, 0xBA4(r29)
	  lfs       f0, -0x6A74(r13)
	  stfs      f0, 0xBA8(r29)
	  lfs       f0, -0x6A70(r13)
	  stfs      f0, 0xBAC(r29)
	  lfs       f0, -0x6A6C(r13)
	  stfs      f0, 0xBB0(r29)
	  lfs       f0, -0x6A68(r13)
	  stfs      f0, 0xBB4(r29)
	  lfs       f0, -0x6A64(r13)
	  stfs      f0, 0xBB8(r29)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0xB68(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0xB70(r29)
	  stw       r31, 0xB64(r29)
	  bl        -0x443CC
	  stb       r30, 0xE90(r29)
	  addi      r3, r29, 0xE24
	  stb       r30, 0xE91(r29)
	  stb       r30, 0xE92(r29)
	  stb       r30, 0xE93(r29)
	  lfs       f0, -0x6A60(r13)
	  stfs      f0, 0xE78(r29)
	  lfs       f0, -0x6A5C(r13)
	  stfs      f0, 0xE7C(r29)
	  lfs       f0, -0x6A58(r13)
	  stfs      f0, 0xE80(r29)
	  lfs       f0, -0x6A54(r13)
	  stfs      f0, 0xE84(r29)
	  lfs       f0, -0x6A50(r13)
	  stfs      f0, 0xE88(r29)
	  lfs       f0, -0x6A4C(r13)
	  stfs      f0, 0xE8C(r29)
	  lfs       f0, -0x77F4(r2)
	  stfs      f0, 0xE3C(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0xE44(r29)
	  stw       r31, 0xE38(r29)
	  bl        -0x44428
	  stb       r30, 0x1164(r29)
	  addi      r3, r29, 0x10F8
	  stb       r30, 0x1165(r29)
	  stb       r30, 0x1166(r29)
	  stb       r30, 0x1167(r29)
	  lfs       f0, -0x6A48(r13)
	  stfs      f0, 0x114C(r29)
	  lfs       f0, -0x6A44(r13)
	  stfs      f0, 0x1150(r29)
	  lfs       f0, -0x6A40(r13)
	  stfs      f0, 0x1154(r29)
	  lfs       f0, -0x6A3C(r13)
	  stfs      f0, 0x1158(r29)
	  lfs       f0, -0x6A38(r13)
	  stfs      f0, 0x115C(r29)
	  lfs       f0, -0x6A34(r13)
	  stfs      f0, 0x1160(r29)
	  lfs       f0, -0x77FC(r2)
	  stfs      f0, 0x1110(r29)
	  lfs       f0, -0x77F8(r2)
	  stfs      f0, 0x1118(r29)
	  stw       r31, 0x110C(r29)
	  bl        -0x44484
	  li        r0, 0x30
	  stb       r0, 0x13E8(r29)
	  mr        r3, r29
	  stb       r0, 0x13E9(r29)
	  stb       r0, 0x13EA(r29)
	  stb       r0, 0x13EB(r29)
	  stb       r0, 0x13F4(r29)
	  stb       r0, 0x13F5(r29)
	  stb       r0, 0x13F6(r29)
	  stb       r0, 0x13F7(r29)
	  lfs       f0, -0x77F0(r2)
	  stfs      f0, 0x13EC(r29)
	  lfs       f0, -0x77EC(r2)
	  stfs      f0, 0x13F0(r29)
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
 * Address:	........
 * Size:	000038
 */
void DayMgr::updateLightCount(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8006E3A4
 * Size:	000058
 */
void DayMgr::menuIncreaseLights(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x0(r3)
	  addi      r0, r5, 0x1
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  lwz       r5, 0x4(r3)
	  cmpw      r0, r5
	  ble-      .loc_0x2C
	  stw       r5, 0x0(r3)

	.loc_0x2C:
	  lwz       r6, 0x30(r4)
	  lis       r4, 0x802B
	  lwz       r5, 0x0(r3)
	  subi      r4, r4, 0x68C8
	  lwz       r3, 0x18(r6)
	  crclr     6, 0x6
	  bl        0x1A81B0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006E3FC
 * Size:	000058
 */
void DayMgr::menuDecreaseLights(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x0(r3)
	  subi      r0, r5, 0x1
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x2C
	  li        r0, 0
	  stw       r0, 0x0(r3)

	.loc_0x2C:
	  lwz       r6, 0x30(r4)
	  lis       r4, 0x802B
	  lwz       r5, 0x0(r3)
	  subi      r4, r4, 0x68C8
	  lwz       r3, 0x18(r6)
	  crclr     6, 0x6
	  bl        0x1A8158
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DayMgr::updateTime(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8006E454
 * Size:	000084
 */
void DayMgr::menuIncreaseTime(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x2848
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0x2F0
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lfs       f2, -0x77D8(r2)
	  lfs       f1, 0x2F0(r3)
	  lfs       f0, -0x77D4(r2)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x40
	  fmr       f1, f0

	.loc_0x40:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x2D8
	  bl        -0x1CC84
	  lwz       r5, 0x30(r30)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x68B8
	  lfs       f1, 0x0(r31)
	  lwz       r3, 0x18(r5)
	  crset     6, 0x6
	  bl        0x1A80DC
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
 * Address:	8006E4D8
 * Size:	000084
 */
void DayMgr::menuDecreaseTime(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x2848
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0x2F0
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lfs       f1, -0x77D8(r2)
	  lfs       f2, 0x2F0(r3)
	  lfs       f0, -0x77E8(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x40
	  fmr       f1, f0

	.loc_0x40:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x2D8
	  bl        -0x1CD08
	  lwz       r5, 0x30(r30)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x68B8
	  lfs       f1, 0x0(r31)
	  lwz       r3, 0x18(r5)
	  crset     6, 0x6
	  bl        0x1A8058
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
 * Address:	8006E55C
 * Size:	000A38
 */
void DayMgr::refresh(Graphics&, f32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x280(r1)
	  stfd      f31, 0x278(r1)
	  stmw      r23, 0x254(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  lwz       r31, 0x0(r3)
	  cmpw      r5, r31
	  bge-      .loc_0x2C
	  mr        r31, r5

	.loc_0x2C:
	  lfs       f0, -0x77D0(r2)
	  lfs       f2, -0x77E8(r2)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x4C
	  lwz       r3, 0x1400(r29)
	  addi      r9, r3, 0x4FE0
	  addi      r8, r9, 0
	  b         .loc_0x138

	.loc_0x4C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x20(r3)
	  lfs       f0, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x74
	  lfs       f4, 0x90(r3)
	  fcmpo     cr0, f1, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x84

	.loc_0x74:
	  lwz       r9, 0x1400(r29)
	  lfs       f2, -0x77E8(r2)
	  mr        r8, r9
	  b         .loc_0x138

	.loc_0x84:
	  lfs       f3, 0x50(r3)
	  fcmpo     cr0, f1, f3
	  bge-      .loc_0xAC
	  fsubs     f2, f1, f0
	  lwz       r3, 0x1400(r29)
	  fsubs     f0, f3, f0
	  addi      r8, r3, 0
	  addi      r9, r3, 0x13F8
	  fdivs     f2, f2, f0
	  b         .loc_0x138

	.loc_0xAC:
	  lfs       f0, 0x60(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xD4
	  fsubs     f2, f1, f3
	  lwz       r3, 0x1400(r29)
	  fsubs     f0, f0, f3
	  addi      r8, r3, 0x13F8
	  addi      r9, r3, 0x27F0
	  fdivs     f2, f2, f0
	  b         .loc_0x138

	.loc_0xD4:
	  lfs       f3, 0x70(r3)
	  fcmpo     cr0, f1, f3
	  bge-      .loc_0xF0
	  lwz       r3, 0x1400(r29)
	  addi      r9, r3, 0x27F0
	  addi      r8, r9, 0
	  b         .loc_0x138

	.loc_0xF0:
	  lfs       f0, 0x80(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x118
	  fsubs     f2, f1, f3
	  lwz       r3, 0x1400(r29)
	  fsubs     f0, f0, f3
	  addi      r8, r3, 0x27F0
	  addi      r9, r3, 0x3BE8
	  fdivs     f2, f2, f0
	  b         .loc_0x138

	.loc_0x118:
	  fcmpo     cr0, f1, f4
	  bge-      .loc_0x138
	  fsubs     f2, f1, f0
	  lwz       r3, 0x1400(r29)
	  fsubs     f0, f4, f0
	  addi      r9, r3, 0
	  addi      r8, r3, 0x3BE8
	  fdivs     f2, f2, f0

	.loc_0x138:
	  lbz       r10, 0x13E8(r8)
	  lis       r0, 0x4330
	  lbz       r3, 0x13E8(r9)
	  cmpwi     r31, 0
	  stw       r10, 0x23C(r1)
	  lfd       f0, -0x77B8(r2)
	  mtctr     r31
	  stw       r3, 0x244(r1)
	  addi      r3, r8, 0
	  addi      r4, r9, 0
	  stw       r0, 0x240(r1)
	  addi      r5, r29, 0
	  addi      r6, r8, 0
	  stw       r0, 0x238(r1)
	  mr        r7, r29
	  lfd       f4, 0x240(r1)
	  lfd       f3, 0x238(r1)
	  stw       r10, 0x24C(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x248(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x248(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x230(r1)
	  lwz       r10, 0x234(r1)
	  stb       r10, 0x13F0(r29)
	  lbz       r11, 0x13E9(r8)
	  lbz       r10, 0x13E9(r9)
	  stw       r11, 0x21C(r1)
	  stw       r10, 0x224(r1)
	  stw       r0, 0x220(r1)
	  stw       r0, 0x218(r1)
	  lfd       f4, 0x220(r1)
	  lfd       f3, 0x218(r1)
	  stw       r11, 0x22C(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x228(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x228(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x210(r1)
	  lwz       r10, 0x214(r1)
	  stb       r10, 0x13F1(r29)
	  lbz       r11, 0x13EA(r8)
	  lbz       r10, 0x13EA(r9)
	  stw       r11, 0x1FC(r1)
	  stw       r10, 0x204(r1)
	  stw       r0, 0x200(r1)
	  stw       r0, 0x1F8(r1)
	  lfd       f4, 0x200(r1)
	  lfd       f3, 0x1F8(r1)
	  stw       r11, 0x20C(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x208(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x208(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x1F0(r1)
	  lwz       r10, 0x1F4(r1)
	  stb       r10, 0x13F2(r29)
	  lbz       r11, 0x13EB(r8)
	  lbz       r10, 0x13EB(r9)
	  stw       r11, 0x1DC(r1)
	  stw       r10, 0x1E4(r1)
	  stw       r0, 0x1E0(r1)
	  stw       r0, 0x1D8(r1)
	  lfd       f4, 0x1E0(r1)
	  lfd       f3, 0x1D8(r1)
	  stw       r11, 0x1EC(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x1E8(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x1E8(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x1D0(r1)
	  lwz       r10, 0x1D4(r1)
	  stb       r10, 0x13F3(r29)
	  ble-      .loc_0x4E8

	.loc_0x2B0:
	  lbz       r11, 0x6C(r3)
	  lbz       r10, 0x6C(r4)
	  stw       r11, 0x1E4(r1)
	  stw       r10, 0x1DC(r1)
	  stw       r0, 0x1D8(r1)
	  stw       r0, 0x1E0(r1)
	  lfd       f4, 0x1D8(r1)
	  lfd       f3, 0x1E0(r1)
	  stw       r11, 0x1D4(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x1D0(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x1D0(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x1E8(r1)
	  lwz       r10, 0x1EC(r1)
	  stb       r10, 0x74(r5)
	  lbz       r11, 0x6D(r3)
	  lbz       r10, 0x6D(r4)
	  stw       r11, 0x204(r1)
	  stw       r10, 0x1FC(r1)
	  stw       r0, 0x1F8(r1)
	  stw       r0, 0x200(r1)
	  lfd       f4, 0x1F8(r1)
	  lfd       f3, 0x200(r1)
	  stw       r11, 0x1F4(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x1F0(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x1F0(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x208(r1)
	  lwz       r10, 0x20C(r1)
	  stb       r10, 0x75(r5)
	  lbz       r11, 0x6E(r3)
	  lbz       r10, 0x6E(r4)
	  stw       r11, 0x224(r1)
	  stw       r10, 0x21C(r1)
	  stw       r0, 0x218(r1)
	  stw       r0, 0x220(r1)
	  lfd       f4, 0x218(r1)
	  lfd       f3, 0x220(r1)
	  stw       r11, 0x214(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x210(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x210(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x228(r1)
	  lwz       r10, 0x22C(r1)
	  stb       r10, 0x76(r5)
	  lbz       r11, 0x6F(r3)
	  lbz       r10, 0x6F(r4)
	  stw       r11, 0x244(r1)
	  stw       r10, 0x23C(r1)
	  stw       r0, 0x238(r1)
	  stw       r0, 0x240(r1)
	  lfd       f4, 0x238(r1)
	  lfd       f3, 0x240(r1)
	  stw       r11, 0x234(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r0, 0x230(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x230(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x248(r1)
	  lwz       r10, 0x24C(r1)
	  stb       r10, 0x77(r5)
	  lwz       r10, 0x14(r3)
	  stw       r10, 0x1C(r5)
	  lwz       r10, 0x13CC(r6)
	  addi      r6, r6, 0x4
	  stw       r10, 0x13D4(r7)
	  addi      r7, r7, 0x4
	  lfs       f4, 0x18(r3)
	  lfs       f3, 0x18(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x20(r5)
	  lfs       f4, 0x20(r3)
	  lfs       f3, 0x20(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x28(r5)
	  lfs       f4, 0x54(r3)
	  lfs       f3, 0x54(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x5C(r5)
	  lfs       f4, 0x58(r3)
	  lfs       f3, 0x58(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x60(r5)
	  lfs       f4, 0x5C(r3)
	  lfs       f3, 0x5C(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x64(r5)
	  lfs       f4, 0x60(r3)
	  lfs       f3, 0x60(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x68(r5)
	  lfs       f4, 0x64(r3)
	  lfs       f3, 0x64(r4)
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x6C(r5)
	  lfs       f4, 0x68(r3)
	  addi      r3, r3, 0x2D4
	  lfs       f3, 0x68(r4)
	  addi      r4, r4, 0x2D4
	  fsubs     f3, f3, f4
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  stfs      f3, 0x70(r5)
	  addi      r5, r5, 0x2D4
	  bdnz+     .loc_0x2B0

	.loc_0x4E8:
	  lbz       r4, 0x13F4(r8)
	  lis       r3, 0x4330
	  lbz       r0, 0x13F4(r9)
	  stw       r4, 0x1E4(r1)
	  lfd       f0, -0x77B8(r2)
	  stw       r0, 0x1DC(r1)
	  stw       r3, 0x1D8(r1)
	  stw       r3, 0x1E0(r1)
	  lfd       f4, 0x1D8(r1)
	  lfd       f3, 0x1E0(r1)
	  stw       r4, 0x1D4(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r3, 0x1D0(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x1D0(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x1E8(r1)
	  lwz       r0, 0x1EC(r1)
	  stb       r0, 0x13FC(r29)
	  lbz       r4, 0x13F5(r8)
	  lbz       r0, 0x13F5(r9)
	  stw       r4, 0x204(r1)
	  stw       r0, 0x1FC(r1)
	  stw       r3, 0x1F8(r1)
	  stw       r3, 0x200(r1)
	  lfd       f4, 0x1F8(r1)
	  lfd       f3, 0x200(r1)
	  stw       r4, 0x1F4(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r3, 0x1F0(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x1F0(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x208(r1)
	  lwz       r0, 0x20C(r1)
	  stb       r0, 0x13FD(r29)
	  lbz       r4, 0x13F6(r8)
	  lbz       r0, 0x13F6(r9)
	  stw       r4, 0x224(r1)
	  stw       r0, 0x21C(r1)
	  stw       r3, 0x218(r1)
	  stw       r3, 0x220(r1)
	  lfd       f4, 0x218(r1)
	  lfd       f3, 0x220(r1)
	  stw       r4, 0x214(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r3, 0x210(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x210(r1)
	  fsubs     f4, f4, f0
	  fmuls     f3, f2, f3
	  fadds     f3, f4, f3
	  fctiwz    f3, f3
	  stfd      f3, 0x228(r1)
	  lwz       r0, 0x22C(r1)
	  stb       r0, 0x13FE(r29)
	  lbz       r4, 0x13F7(r8)
	  lbz       r0, 0x13F7(r9)
	  stw       r4, 0x244(r1)
	  stw       r0, 0x23C(r1)
	  stw       r3, 0x238(r1)
	  stw       r3, 0x240(r1)
	  lfd       f4, 0x238(r1)
	  lfd       f3, 0x240(r1)
	  stw       r4, 0x234(r1)
	  fsubs     f4, f4, f0
	  fsubs     f3, f3, f0
	  stw       r3, 0x230(r1)
	  fsubs     f3, f4, f3
	  lfd       f4, 0x230(r1)
	  fsubs     f4, f4, f0
	  fmuls     f0, f2, f3
	  fadds     f0, f4, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x248(r1)
	  lwz       r0, 0x24C(r1)
	  stb       r0, 0x13FF(r29)
	  lfs       f3, 0x13EC(r8)
	  addi      r6, r1, 0x124
	  lfs       f0, 0x13EC(r9)
	  addi      r5, r1, 0x134
	  addi      r4, r1, 0x140
	  fsubs     f0, f0, f3
	  addi      r3, r1, 0x18C
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x13F4(r29)
	  lfs       f3, 0x13F0(r8)
	  lfs       f0, 0x13F0(r9)
	  fsubs     f0, f0, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x13F8(r29)
	  lwz       r0, 0x13F0(r29)
	  stw       r0, 0x368(r30)
	  lfs       f0, -0x77C8(r2)
	  lfs       f4, -0x6988(r13)
	  fdivs     f1, f1, f0
	  lfs       f3, -0x77CC(r2)
	  lfs       f0, -0x699C(r13)
	  stfs      f4, 0x124(r1)
	  lfs       f4, -0x6984(r13)
	  fmuls     f3, f3, f1
	  lfs       f2, -0x77C4(r2)
	  stfs      f0, 0x140(r1)
	  lfs       f1, -0x6998(r13)
	  fsubs     f2, f3, f2
	  lfs       f0, -0x6990(r13)
	  stfs      f4, 0x128(r1)
	  lfs       f3, -0x6980(r13)
	  stfs      f2, 0x134(r1)
	  lfs       f2, -0x698C(r13)
	  stfs      f0, 0x138(r1)
	  lfs       f0, -0x6994(r13)
	  stfs      f1, 0x144(r1)
	  stfs      f3, 0x12C(r1)
	  stfs      f2, 0x13C(r1)
	  stfs      f0, 0x148(r1)
	  bl        -0x30B4C
	  lfs       f0, -0x697C(r13)
	  addi      r3, r29, 0x1408
	  addi      r4, r1, 0x18C
	  stfs      f0, 0x1408(r29)
	  lfs       f0, -0x6978(r13)
	  stfs      f0, 0x140C(r29)
	  lfs       f0, -0x6974(r13)
	  stfs      f0, 0x1410(r29)
	  bl        -0x37518
	  lfs       f0, 0x1410(r29)
	  lfs       f1, 0x1408(r29)
	  fneg      f0, f0
	  stfs      f1, 0x1410(r29)
	  stfs      f0, 0x1408(r29)
	  lwz       r3, 0x1408(r29)
	  lwz       r0, 0x140C(r29)
	  stw       r3, 0x33C(r30)
	  stw       r0, 0x340(r30)
	  lwz       r0, 0x1410(r29)
	  stw       r0, 0x344(r30)
	  lwz       r3, 0x1414(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x770
	  lfs       f3, -0x77C0(r2)
	  lfs       f0, 0x1408(r29)
	  lfs       f2, 0x140C(r29)
	  fdivs     f0, f0, f3
	  lfs       f1, -0x77BC(r2)
	  lfs       f4, 0x1410(r29)
	  stfsu     f0, 0x8(r3)
	  fdivs     f1, f2, f1
	  fdivs     f0, f4, f3
	  stfs      f1, 0x4(r3)
	  stfs      f0, 0x8(r3)

	.loc_0x770:
	  lfs       f31, -0x77E8(r2)
	  addi      r25, r29, 0
	  addi      r24, r29, 0
	  addi      r27, r1, 0xF4
	  addi      r28, r1, 0x100
	  addi      r26, r1, 0x10C
	  li        r23, 0
	  b         .loc_0x9AC

	.loc_0x790:
	  lwz       r0, 0x1C(r25)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x1
	  bne-      .loc_0x8C8
	  rlwinm.   r0,r23,0,31,31
	  bne-      .loc_0x838
	  lfs       f0, 0x1408(r29)
	  stfs      f0, 0x5C(r25)
	  lfs       f0, 0x140C(r29)
	  stfs      f0, 0x60(r25)
	  lfs       f0, 0x1410(r29)
	  stfs      f0, 0x64(r25)
	  lfs       f0, 0x1408(r29)
	  lfs       f1, 0x140C(r29)
	  fneg      f0, f0
	  lfs       f2, 0x1410(r29)
	  fneg      f1, f1
	  fneg      f2, f2
	  stfs      f0, 0x68(r25)
	  stfs      f1, 0x6C(r25)
	  stfs      f2, 0x70(r25)
	  lfs       f1, 0x68(r25)
	  lfs       f0, 0x6C(r25)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x70(r25)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x61120
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x9A0
	  lfs       f0, 0x68(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x68(r25)
	  lfs       f0, 0x6C(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x6C(r25)
	  lfs       f0, 0x70(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r25)
	  b         .loc_0x9A0

	.loc_0x838:
	  lfs       f0, 0x1408(r29)
	  lfs       f1, 0x140C(r29)
	  fneg      f0, f0
	  lfs       f2, 0x1410(r29)
	  fneg      f1, f1
	  fneg      f2, f2
	  stfs      f0, 0x5C(r25)
	  stfs      f1, 0x60(r25)
	  stfs      f2, 0x64(r25)
	  lfs       f0, 0x1408(r29)
	  stfs      f0, 0x68(r25)
	  lfs       f0, 0x140C(r29)
	  stfs      f0, 0x6C(r25)
	  lfs       f0, 0x1410(r29)
	  stfs      f0, 0x70(r25)
	  lfs       f1, 0x68(r25)
	  lfs       f0, 0x6C(r25)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x70(r25)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x611B0
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x9A0
	  lfs       f0, 0x68(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x68(r25)
	  lfs       f0, 0x6C(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x6C(r25)
	  lfs       f0, 0x70(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r25)
	  b         .loc_0x9A0

	.loc_0x8C8:
	  lwz       r0, 0x13D4(r24)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x9A0
	  lwz       r3, 0x3120(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x9A0
	  bl        0xA8588
	  cmplwi    r3, 0
	  beq-      .loc_0x9A0
	  lfs       f0, -0x695C(r13)
	  lfs       f1, -0x6958(r13)
	  stfs      f0, 0xF4(r1)
	  lfs       f0, -0x6954(r13)
	  stfs      f1, 0xF8(r1)
	  lwz       r3, 0x3120(r13)
	  stfs      f0, 0xFC(r1)
	  bl        0xA8560
	  lfs       f1, -0x6964(r13)
	  mr        r4, r26
	  lfs       f0, -0x6970(r13)
	  mr        r5, r28
	  stfs      f1, 0x100(r1)
	  lfs       f1, -0x696C(r13)
	  mr        r6, r27
	  lfs       f3, 0xA0(r3)
	  addi      r3, r1, 0x14C
	  lfs       f2, -0x6960(r13)
	  stfs      f0, 0x10C(r1)
	  lfs       f0, -0x6968(r13)
	  stfs      f3, 0x104(r1)
	  stfs      f1, 0x110(r1)
	  stfs      f2, 0x108(r1)
	  stfs      f0, 0x114(r1)
	  bl        -0x30DB4
	  addi      r3, r25, 0x68
	  addi      r4, r1, 0x14C
	  bl        -0x378A8
	  addi      r3, r25, 0x5C
	  addi      r4, r1, 0x14C
	  bl        -0x378B4
	  lwz       r3, 0x3120(r13)
	  bl        0xA84FC
	  lfs       f1, 0x5C(r25)
	  lfsu      f0, 0x94(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r25)
	  lfs       f1, 0x60(r25)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x60(r25)
	  lfs       f1, 0x64(r25)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x64(r25)

	.loc_0x9A0:
	  addi      r25, r25, 0x2D4
	  addi      r24, r24, 0x4
	  addi      r23, r23, 0x1

	.loc_0x9AC:
	  cmpw      r23, r31
	  blt+      .loc_0x790
	  li        r23, 0
	  mulli     r0, r23, 0x2D4
	  add       r24, r29, r0
	  li        r27, 0
	  subi      r28, r13, 0x6950
	  b         .loc_0xA08

	.loc_0x9CC:
	  addi      r3, r24, 0x8
	  bl        -0x45064
	  stw       r27, 0x18(r24)
	  addi      r3, r30, 0x10
	  addi      r4, r24, 0x8
	  stw       r27, 0x14(r24)
	  stw       r27, 0x10(r24)
	  stw       r28, 0xC(r24)
	  lwz       r6, 0x2DEC(r13)
	  lwz       r5, 0x1B0(r6)
	  addi      r0, r5, 0x1
	  stw       r0, 0x1B0(r6)
	  bl        -0x2E980
	  addi      r24, r24, 0x2D4
	  addi      r23, r23, 0x1

	.loc_0xA08:
	  cmpw      r23, r31
	  blt+      .loc_0x9CC
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        .loc_0xA38
	  lmw       r23, 0x254(r1)
	  lwz       r0, 0x284(r1)
	  lfd       f31, 0x278(r1)
	  addi      r1, r1, 0x280
	  mtlr      r0
	  blr

	.loc_0xA38:
	*/
}

/*
 * --INFO--
 * Address:	8006EF94
 * Size:	000054
 */
void DayMgr::setFog(Graphics&, Colour*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r5, 0
	  stw       r0, 0x4(r1)
	  addi      r6, r3, 0
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  b         .loc_0x20

	.loc_0x1C:
	  addi      r5, r6, 0x13FC

	.loc_0x20:
	  lwz       r12, 0x3B4(r4)
	  mr        r3, r4
	  lfs       f1, -0x7800(r2)
	  li        r4, 0x1
	  lwz       r12, 0xBC(r12)
	  lfs       f2, 0x13F4(r6)
	  lfs       f3, 0x13F8(r6)
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
 * Address:	8006EFE8
 * Size:	000084
 */
void DayMgr::menuDumpSettings(Menu&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2DEC(r13)
	  li        r8, 0
	  li        r0, 0x1
	  lwz       r11, 0x1C(r5)
	  addi      r6, r5, 0x1C
	  addi      r9, r8, 0
	  stw       r0, 0x0(r6)
	  li        r12, 0

	.loc_0x20:
	  lwz       r0, 0x0(r3)
	  li        r6, 0
	  addi      r7, r6, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x64

	.loc_0x38:
	  lwz       r0, 0x1400(r3)
	  add       r0, r0, r9
	  add       r10, r0, r7
	  lwz       r0, 0x14(r10)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x3
	  cmpwi     r0, 0x1
	  cmpwi     r0, 0x3
	  addi      r6, r6, 0x4
	  addi      r7, r7, 0x2D4
	  bdnz+     .loc_0x38

	.loc_0x64:
	  addi      r12, r12, 0x1
	  cmpwi     r12, 0x5
	  addi      r8, r8, 0x4
	  addi      r9, r9, 0x13F8
	  blt+      .loc_0x20
	  lwz       r3, 0x2DEC(r13)
	  stw       r11, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006F06C
 * Size:	0008C0
 */
void DayMgr::init(CmdStream*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x88(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x802B
	  stw       r29, 0x84(r1)
	  subi      r29, r3, 0x6B80
	  stw       r0, 0x0(r30)
	  b         .loc_0x868

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2DFF8
	  addi      r3, r31, 0
	  addi      r4, r29, 0x428
	  bl        -0x2DCE0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E018
	  b         .loc_0x868

	.loc_0x64:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x434
	  bl        -0x2DD04
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x868
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E03C
	  crclr     6, 0x6
	  addi      r5, r1, 0x7C
	  subi      r4, r13, 0x6914
	  bl        0x1A8F98
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E058
	  b         .loc_0x82C

	.loc_0xA4:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E068
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6910
	  bl        -0x2DD50
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x46C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E088
	  crclr     6, 0x6
	  addi      r5, r1, 0x78
	  subi      r4, r13, 0x6914
	  bl        0x1A8F4C
	  lwz       r3, 0x0(r30)
	  lwz       r4, 0x78(r1)
	  subi      r0, r3, 0x1
	  cmpw      r4, r0
	  ble-      .loc_0xFC
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r30)

	.loc_0xFC:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E0C0
	  b         .loc_0x42C

	.loc_0x10C:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E0D0
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6908
	  bl        -0x2DDB8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x180
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E0F0
	  crclr     6, 0x6
	  addi      r5, r1, 0x74
	  subi      r4, r13, 0x6914
	  bl        0x1A8EE4
	  lwz       r3, 0x7C(r1)
	  lwz       r0, 0x78(r1)
	  mulli     r4, r3, 0x13F8
	  lwz       r5, 0x1400(r30)
	  lwz       r3, 0x74(r1)
	  mulli     r0, r0, 0x2D4
	  add       r4, r4, r0
	  addi      r4, r4, 0x14
	  add       r4, r5, r4
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,0,23
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x42C

	.loc_0x180:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6900
	  bl        -0x2DE20
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E158
	  lwz       r4, 0x7C(r1)
	  crclr     6, 0x6
	  lwz       r0, 0x78(r1)
	  mulli     r4, r4, 0x13F8
	  lwz       r6, 0x1400(r30)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r4, r0
	  addi      r5, r4, 0x13CC
	  add       r5, r6, r5
	  subi      r4, r13, 0x6914
	  bl        0x1A8E60
	  b         .loc_0x42C

	.loc_0x1D0:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x68F8
	  bl        -0x2DE70
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x220
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E1A8
	  lwz       r4, 0x7C(r1)
	  crclr     6, 0x6
	  lwz       r0, 0x78(r1)
	  mulli     r4, r4, 0x13F8
	  lwz       r6, 0x1400(r30)
	  mulli     r0, r0, 0x2D4
	  add       r4, r4, r0
	  addi      r5, r4, 0x20
	  add       r5, r6, r5
	  subi      r4, r13, 0x68F4
	  bl        0x1A8E10
	  b         .loc_0x42C

	.loc_0x220:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x204
	  bl        -0x2DEC0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C4
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E1F8
	  crclr     6, 0x6
	  addi      r5, r1, 0x70
	  subi      r4, r13, 0x68F4
	  bl        0x1A8DDC
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E214
	  crclr     6, 0x6
	  addi      r5, r1, 0x6C
	  subi      r4, r13, 0x68F4
	  bl        0x1A8DC0
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E230
	  crclr     6, 0x6
	  addi      r5, r1, 0x68
	  subi      r4, r13, 0x68F4
	  bl        0x1A8DA4
	  lwz       r3, 0x7C(r1)
	  lwz       r0, 0x78(r1)
	  mulli     r3, r3, 0x13F8
	  lwz       r4, 0x1400(r30)
	  lfs       f0, 0x70(r1)
	  mulli     r0, r0, 0x2D4
	  add       r3, r3, r0
	  addi      r3, r3, 0x54
	  add       r3, r4, r3
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x6C(r1)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x42C

	.loc_0x2C4:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x210
	  bl        -0x2DF64
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x368
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E29C
	  crclr     6, 0x6
	  addi      r5, r1, 0x64
	  subi      r4, r13, 0x68F4
	  bl        0x1A8D38
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E2B8
	  crclr     6, 0x6
	  addi      r5, r1, 0x60
	  subi      r4, r13, 0x68F4
	  bl        0x1A8D1C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E2D4
	  crclr     6, 0x6
	  addi      r5, r1, 0x5C
	  subi      r4, r13, 0x68F4
	  bl        0x1A8D00
	  lwz       r3, 0x7C(r1)
	  lwz       r0, 0x78(r1)
	  mulli     r3, r3, 0x13F8
	  lwz       r4, 0x1400(r30)
	  lfs       f0, 0x64(r1)
	  mulli     r0, r0, 0x2D4
	  add       r3, r3, r0
	  addi      r3, r3, 0x60
	  add       r3, r4, r3
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x42C

	.loc_0x368:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x69D4
	  bl        -0x2E008
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x42C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E340
	  crclr     6, 0x6
	  addi      r5, r1, 0x58
	  subi      r4, r13, 0x6914
	  bl        0x1A8C94
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E35C
	  crclr     6, 0x6
	  addi      r5, r1, 0x54
	  subi      r4, r13, 0x6914
	  bl        0x1A8C78
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E378
	  crclr     6, 0x6
	  addi      r5, r1, 0x50
	  subi      r4, r13, 0x6914
	  bl        0x1A8C5C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E394
	  crclr     6, 0x6
	  addi      r5, r1, 0x4C
	  subi      r4, r13, 0x6914
	  bl        0x1A8C40
	  lwz       r0, 0x7C(r1)
	  lwz       r3, 0x78(r1)
	  mulli     r4, r0, 0x13F8
	  lwz       r5, 0x1400(r30)
	  lwz       r0, 0x58(r1)
	  lwz       r8, 0x4C(r1)
	  mulli     r3, r3, 0x2D4
	  lwz       r7, 0x50(r1)
	  lwz       r6, 0x54(r1)
	  add       r3, r4, r3
	  addi      r3, r3, 0x6C
	  add       r3, r5, r3
	  stb       r0, 0x0(r3)
	  stb       r6, 0x1(r3)
	  stb       r7, 0x2(r3)
	  stb       r8, 0x3(r3)

	.loc_0x42C:
	  mr        r3, r31
	  bl        -0x2E744
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x44C
	  mr        r3, r31
	  bl        -0x2E024
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x10C

	.loc_0x44C:
	  mr        r3, r31
	  bl        -0x2E764
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x82C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E420
	  b         .loc_0x82C

	.loc_0x46C:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x68F0
	  bl        -0x2E10C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x594
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E444
	  b         .loc_0x554

	.loc_0x490:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E454
	  addi      r3, r31, 0
	  subi      r4, r13, 0x69D4
	  bl        -0x2E13C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x554
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E474
	  crclr     6, 0x6
	  addi      r5, r1, 0x48
	  subi      r4, r13, 0x6914
	  bl        0x1A8B60
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E490
	  crclr     6, 0x6
	  addi      r5, r1, 0x44
	  subi      r4, r13, 0x6914
	  bl        0x1A8B44
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E4AC
	  crclr     6, 0x6
	  addi      r5, r1, 0x40
	  subi      r4, r13, 0x6914
	  bl        0x1A8B28
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E4C8
	  crclr     6, 0x6
	  addi      r5, r1, 0x3C
	  subi      r4, r13, 0x6914
	  bl        0x1A8B0C
	  lwz       r3, 0x7C(r1)
	  lwz       r4, 0x1400(r30)
	  mulli     r3, r3, 0x13F8
	  lwz       r0, 0x48(r1)
	  lwz       r6, 0x3C(r1)
	  lwz       r5, 0x40(r1)
	  addi      r7, r3, 0x13E8
	  lwz       r3, 0x44(r1)
	  add       r7, r4, r7
	  stb       r0, 0x0(r7)
	  stb       r3, 0x1(r7)
	  stb       r5, 0x2(r7)
	  stb       r6, 0x3(r7)

	.loc_0x554:
	  mr        r3, r31
	  bl        -0x2E86C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x574
	  mr        r3, r31
	  bl        -0x2E14C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x490

	.loc_0x574:
	  mr        r3, r31
	  bl        -0x2E88C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x82C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E548
	  b         .loc_0x82C

	.loc_0x594:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x440
	  bl        -0x2E234
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x688
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E56C
	  b         .loc_0x648

	.loc_0x5B8:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E57C
	  addi      r3, r31, 0
	  subi      r4, r13, 0x69D4
	  bl        -0x2E264
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x648
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E59C
	  crclr     6, 0x6
	  addi      r5, r1, 0x38
	  subi      r4, r13, 0x6914
	  bl        0x1A8A38
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E5B8
	  crclr     6, 0x6
	  addi      r5, r1, 0x34
	  subi      r4, r13, 0x6914
	  bl        0x1A8A1C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E5D4
	  crclr     6, 0x6
	  addi      r5, r1, 0x30
	  subi      r4, r13, 0x6914
	  bl        0x1A8A00
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E5F0
	  crclr     6, 0x6
	  addi      r5, r1, 0x2C
	  subi      r4, r13, 0x6914
	  bl        0x1A89E4

	.loc_0x648:
	  mr        r3, r31
	  bl        -0x2E960
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x668
	  mr        r3, r31
	  bl        -0x2E240
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x5B8

	.loc_0x668:
	  mr        r3, r31
	  bl        -0x2E980
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x82C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E63C
	  b         .loc_0x82C

	.loc_0x688:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x69A0
	  bl        -0x2E328
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x82C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E660
	  b         .loc_0x7F0

	.loc_0x6AC:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E670
	  addi      r3, r31, 0
	  subi      r4, r13, 0x69D4
	  bl        -0x2E358
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x774
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E690
	  crclr     6, 0x6
	  addi      r5, r1, 0x28
	  subi      r4, r13, 0x6914
	  bl        0x1A8944
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E6AC
	  crclr     6, 0x6
	  addi      r5, r1, 0x24
	  subi      r4, r13, 0x6914
	  bl        0x1A8928
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E6C8
	  crclr     6, 0x6
	  addi      r5, r1, 0x20
	  subi      r4, r13, 0x6914
	  bl        0x1A890C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E6E4
	  crclr     6, 0x6
	  addi      r5, r1, 0x1C
	  subi      r4, r13, 0x6914
	  bl        0x1A88F0
	  lwz       r3, 0x7C(r1)
	  lwz       r4, 0x1400(r30)
	  mulli     r3, r3, 0x13F8
	  lwz       r0, 0x28(r1)
	  lwz       r6, 0x1C(r1)
	  lwz       r5, 0x20(r1)
	  addi      r7, r3, 0x13F4
	  lwz       r3, 0x24(r1)
	  add       r7, r4, r7
	  stb       r0, 0x0(r7)
	  stb       r3, 0x1(r7)
	  stb       r5, 0x2(r7)
	  stb       r6, 0x3(r7)
	  b         .loc_0x7F0

	.loc_0x774:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x68E8
	  bl        -0x2E414
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7F0
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E74C
	  crclr     6, 0x6
	  addi      r5, r1, 0x18
	  subi      r4, r13, 0x68F4
	  bl        0x1A8888
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E768
	  crclr     6, 0x6
	  addi      r5, r1, 0x14
	  subi      r4, r13, 0x68F4
	  bl        0x1A886C
	  lwz       r0, 0x7C(r1)
	  lfs       f0, 0x18(r1)
	  mulli     r3, r0, 0x13F8
	  lwz       r4, 0x1400(r30)
	  addi      r0, r3, 0x13EC
	  stfsx     f0, r4, r0
	  lwz       r0, 0x7C(r1)
	  lfs       f0, 0x14(r1)
	  mulli     r3, r0, 0x13F8
	  lwz       r4, 0x1400(r30)
	  addi      r0, r3, 0x13F0
	  stfsx     f0, r4, r0

	.loc_0x7F0:
	  mr        r3, r31
	  bl        -0x2EB08
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x810
	  mr        r3, r31
	  bl        -0x2E3E8
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x6AC

	.loc_0x810:
	  mr        r3, r31
	  bl        -0x2EB28
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x82C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E7E4

	.loc_0x82C:
	  mr        r3, r31
	  bl        -0x2EB44
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x84C
	  mr        r3, r31
	  bl        -0x2E424
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xA4

	.loc_0x84C:
	  mr        r3, r31
	  bl        -0x2EB64
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x868
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E820

	.loc_0x868:
	  mr        r3, r31
	  bl        -0x2EB80
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x888
	  mr        r3, r31
	  bl        -0x2E460
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x34

	.loc_0x888:
	  mr        r3, r31
	  bl        -0x2EBA0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8A4
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2E85C

	.loc_0x8A4:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006F92C
 * Size:	000030
 */
void Delegate1<DayMgr, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1A53EC
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006F95C
 * Size:	000030
 */
void Delegate1<LightMenu, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1A53BC
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006F98C
 * Size:	000030
 */
void Delegate1<FogMenu, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1A538C
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006F9BC
 * Size:	000030
 */
void Delegate1<ColourMenu, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1A535C
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006F9EC
 * Size:	000030
 */
void Delegate1<PositionMenu, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1A532C
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
