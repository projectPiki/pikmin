#include "zen/DrawCommon.h"
#include "zen/Number.h"
#include "PSU/Tree.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	801BF574
 * Size:	000108
 */
zen::DrawScreen::DrawScreen(char*, P2DGrafContext*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r27, r4, 0
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  addi      r30, r7, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x1580
	  lwz       r31, 0x8(r1)
	  addi      r3, r1, 0x18
	  stw       r0, 0x0(r31)
	  addi      r26, r31, 0x4
	  bl        -0xBF98
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x18
	  addi      r3, r26, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        -0xEC14
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r26)
	  li        r0, 0
	  addi      r3, r26, 0
	  stb       r0, 0xEC(r26)
	  addi      r4, r27, 0
	  addi      r5, r29, 0
	  stw       r0, 0xF0(r26)
	  addi      r6, r30, 0
	  li        r7, 0x1
	  stw       r0, 0xF4(r26)
	  bl        -0xCA14
	  cmplwi    r28, 0
	  beq-      .loc_0xB4
	  stw       r28, 0xFC(r31)
	  b         .loc_0xF0

	.loc_0xB4:
	  li        r3, 0xE4
	  bl        -0x178628
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xE8
	  lfs       f1, -0x4760(r2)
	  li        r4, 0
	  lfs       f2, -0x475C(r2)
	  li        r5, 0
	  lfs       f3, -0x4758(r2)
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        -0xF4C8

	.loc_0xE8:
	  lwz       r3, 0x8(r1)
	  stw       r31, 0xFC(r3)

	.loc_0xF0:
	  lmw       r26, 0x20(r1)
	  lwz       r3, 0x8(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF67C
 * Size:	000024
 */
void zen::DrawScreen::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xCB3C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF6A0
 * Size:	000050
 */
void zen::DrawScreen::draw()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0xFC(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0xFC(r31)
	  addi      r3, r31, 0x4
	  li        r4, 0
	  li        r5, 0
	  bl        -0xC804
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF6F0
 * Size:	0000B4
 */
zen::NumberTex::NumberTex()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803D
	  stw       r0, 0x4(r1)
	  lis       r4, 0x803D
	  stwu      r1, -0x128(r1)
	  stmw      r26, 0x110(r1)
	  addi      r29, r5, 0x2360
	  addi      r28, r4, 0x2388
	  lis       r5, 0x802E
	  lis       r4, 0x802E
	  addi      r26, r3, 0
	  addi      r30, r5, 0x14A4
	  addi      r31, r4, 0x14B0
	  li        r27, 0

	.loc_0x38:
	  addi      r4, r30, 0
	  crclr     6, 0x6
	  addi      r5, r27, 0
	  addi      r3, r1, 0xC
	  bl        0x56E60
	  addi      r3, r1, 0xC
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x32E98
	  stw       r3, 0x0(r29)
	  addi      r4, r31, 0
	  addi      r5, r27, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0xC
	  bl        0x56E38
	  addi      r3, r1, 0xC
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x32E70
	  addi      r27, r27, 0x1
	  stw       r3, 0x0(r28)
	  cmpwi     r27, 0xA
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x4
	  blt+      .loc_0x38
	  mr        r3, r26
	  lmw       r26, 0x110(r1)
	  lwz       r0, 0x12C(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF7A4
 * Size:	000118
 */
void zen::P2DPaneLibrary::makeResident(P2DPane* pane)
{
	pane->makeResident();
	PSUTree<P2DPane>* tree = pane->getPaneTree();
	PSUTreeIterator<P2DPane> iterator(tree->getFirstChild());
	while (iterator != tree->getEndChild()) {
		makeResident(iterator.getObject());
		++iterator;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  stw       r30, 0x98(r1)
	  stw       r29, 0x94(r1)
	  stw       r28, 0x90(r1)
	  mr        r28, r3
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0xD0(r28)
	  cmplwi    r28, 0
	  beq-      .loc_0xF0
	  subi      r28, r28, 0xC
	  b         .loc_0xF0

	.loc_0x44:
	  lwz       r31, 0xC(r28)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0xD0
	  bl        -0xEF8C
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  subi      r3, r3, 0xC

	.loc_0x70:
	  mr        r29, r3
	  b         .loc_0xD8

	.loc_0x78:
	  lwz       r31, 0xC(r29)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0xD0
	  bl        0x8C
	  mr        r30, r3
	  b         .loc_0xB8

	.loc_0xA0:
	  lwz       r3, 0xC(r30)
	  bl        .loc_0x0
	  lwz       r30, 0x18(r30)
	  cmplwi    r30, 0
	  beq-      .loc_0xB8
	  subi      r30, r30, 0xC

	.loc_0xB8:
	  addi      r3, r31, 0xD0
	  bl        .loc_0x118
	  cmplw     r30, r3
	  bne+      .loc_0xA0
	  lwz       r29, 0x18(r29)
	  cmplwi    r29, 0
	  beq-      .loc_0xD8
	  subi      r29, r29, 0xC

	.loc_0xD8:
	  cmplwi    r29, 0
	  bne+      .loc_0x78
	  lwz       r28, 0x18(r28)
	  cmplwi    r28, 0
	  beq-      .loc_0xF0
	  subi      r28, r28, 0xC

	.loc_0xF0:
	  cmplwi    r28, 0
	  bne+      .loc_0x44
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  lwz       r28, 0x90(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr

	.loc_0x118:
	*/
}

/*
 * --INFO--
 * Address:	801BF8D8
 * Size:	0000EC
 */
void zen::P2DPaneLibrary::setFamilyAlpha(P2DPane*, u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stmw      r27, 0x9C(r1)
	  addi      r27, r3, 0
	  addi      r31, r4, 0
	  bl        .loc_0xEC
	  lwz       r27, 0xD0(r27)
	  cmplwi    r27, 0
	  beq-      .loc_0xD0
	  subi      r27, r27, 0xC
	  b         .loc_0xD0

	.loc_0x30:
	  lwz       r30, 0xC(r27)
	  addi      r4, r31, 0
	  addi      r3, r30, 0
	  bl        .loc_0xEC
	  addi      r3, r30, 0xD0
	  bl        -0xF0A4
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  subi      r3, r3, 0xC

	.loc_0x54:
	  mr        r28, r3
	  b         .loc_0xB8

	.loc_0x5C:
	  lwz       r30, 0xC(r28)
	  addi      r4, r31, 0
	  addi      r3, r30, 0
	  bl        .loc_0xEC
	  addi      r3, r30, 0xD0
	  bl        -0x84
	  mr        r29, r3
	  b         .loc_0x98

	.loc_0x7C:
	  lwz       r3, 0xC(r29)
	  mr        r4, r31
	  bl        .loc_0x0
	  lwz       r29, 0x18(r29)
	  cmplwi    r29, 0
	  beq-      .loc_0x98
	  subi      r29, r29, 0xC

	.loc_0x98:
	  addi      r3, r30, 0xD0
	  bl        -0xB8
	  cmplw     r29, r3
	  bne+      .loc_0x7C
	  lwz       r28, 0x18(r28)
	  cmplwi    r28, 0
	  beq-      .loc_0xB8
	  subi      r28, r28, 0xC

	.loc_0xB8:
	  cmplwi    r28, 0
	  bne+      .loc_0x5C
	  lwz       r27, 0x18(r27)
	  cmplwi    r27, 0
	  beq-      .loc_0xD0
	  subi      r27, r27, 0xC

	.loc_0xD0:
	  cmplwi    r27, 0
	  bne+      .loc_0x30
	  lmw       r27, 0x9C(r1)
	  lwz       r0, 0xB4(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr

	.loc_0xEC:
	*/
}

/*
 * --INFO--
 * Address:	801BF9C4
 * Size:	000030
 */
void zen::P2DPaneLibrary::setAlpha(P2DPane*, u8)
{
	/*
	.loc_0x0:
	  lhz       r0, 0x8(r3)
	  cmpwi     r0, 0x12
	  beq-      .loc_0x1C
	  bltlr-
	  cmpwi     r0, 0x14
	  bgelr-
	  b         .loc_0x24

	.loc_0x1C:
	  stb       r4, 0xF0(r3)
	  blr

	.loc_0x24:
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void zen::P2DPaneLibrary::setMirror(P2DPane*, P2DMirror)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801BF9F4
 * Size:	000120
 */
void zen::P2DPaneLibrary::setFamilyMirror(P2DPane*, P2DMirror)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stmw      r27, 0xB4(r1)
	  addi      r31, r4, 0
	  lhz       r0, 0x8(r3)
	  cmpwi     r0, 0x12
	  beq-      .loc_0x2C
	  bge-      .loc_0x30
	  b         .loc_0x30
	  b         .loc_0x30

	.loc_0x2C:
	  stw       r31, 0xF8(r3)

	.loc_0x30:
	  lwz       r27, 0xD0(r3)
	  cmplwi    r27, 0
	  beq-      .loc_0x104
	  subi      r27, r27, 0xC
	  b         .loc_0x104

	.loc_0x44:
	  lwz       r3, 0xC(r27)
	  lhz       r0, 0x8(r3)
	  cmpwi     r0, 0x12
	  beq-      .loc_0x60
	  bge-      .loc_0x64
	  b         .loc_0x64
	  b         .loc_0x64

	.loc_0x60:
	  stw       r31, 0xF8(r3)

	.loc_0x64:
	  addi      r3, r3, 0xD0
	  bl        -0xF1E4
	  cmplwi    r3, 0
	  beq-      .loc_0x78
	  subi      r3, r3, 0xC

	.loc_0x78:
	  mr        r28, r3
	  b         .loc_0xEC

	.loc_0x80:
	  lwz       r30, 0xC(r28)
	  lhz       r0, 0x8(r30)
	  cmpwi     r0, 0x12
	  beq-      .loc_0x9C
	  bge-      .loc_0xA0
	  b         .loc_0xA0
	  b         .loc_0xA0

	.loc_0x9C:
	  stw       r31, 0xF8(r30)

	.loc_0xA0:
	  addi      r3, r30, 0xD0
	  bl        -0x1D4
	  mr        r29, r3
	  b         .loc_0xCC

	.loc_0xB0:
	  lwz       r3, 0xC(r29)
	  mr        r4, r31
	  bl        .loc_0x0
	  lwz       r29, 0x18(r29)
	  cmplwi    r29, 0
	  beq-      .loc_0xCC
	  subi      r29, r29, 0xC

	.loc_0xCC:
	  addi      r3, r30, 0xD0
	  bl        -0x208
	  cmplw     r29, r3
	  bne+      .loc_0xB0
	  lwz       r28, 0x18(r28)
	  cmplwi    r28, 0
	  beq-      .loc_0xEC
	  subi      r28, r28, 0xC

	.loc_0xEC:
	  cmplwi    r28, 0
	  bne+      .loc_0x80
	  lwz       r27, 0x18(r27)
	  cmplwi    r27, 0
	  beq-      .loc_0x104
	  subi      r27, r27, 0xC

	.loc_0x104:
	  cmplwi    r27, 0
	  bne+      .loc_0x44
	  lmw       r27, 0xB4(r1)
	  lwz       r0, 0xCC(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BFB14
 * Size:	00001C
 */
void zen::P2DPaneLibrary::getParentPane(P2DPane*)
{
	/*
	.loc_0x0:
	  lwz       r3, 0xE0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r3, 0xC(r3)
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BFB30
 * Size:	000070
 */
void zen::P2DPaneLibrary::getWorldPos(P2DPane*, int*, int*)
{
	/*
	.loc_0x0:
	  lha       r0, 0x18(r3)
	  stw       r0, 0x0(r4)
	  lha       r0, 0x1A(r3)
	  stw       r0, 0x0(r5)
	  lwz       r3, 0xE0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x24
	  lwz       r6, 0xC(r3)
	  b         .loc_0x64

	.loc_0x24:
	  li        r6, 0
	  b         .loc_0x64

	.loc_0x2C:
	  lwz       r3, 0x0(r4)
	  lha       r0, 0x18(r6)
	  add       r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x0(r5)
	  lha       r0, 0x1A(r6)
	  add       r0, r3, r0
	  stw       r0, 0x0(r5)
	  lwz       r3, 0xE0(r6)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lwz       r6, 0xC(r3)
	  b         .loc_0x64

	.loc_0x60:
	  li        r6, 0

	.loc_0x64:
	  cmplwi    r6, 0
	  bne+      .loc_0x2C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BFBA0
 * Size:	000124
 */
void zen::P2DPaneLibrary::changeParent(P2DPane*, P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  stw       r29, 0x5C(r1)
	  lwz       r3, 0xE0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r29, 0xC(r3)
	  b         .loc_0x80

	.loc_0x34:
	  li        r29, 0
	  b         .loc_0x80

	.loc_0x3C:
	  mr        r3, r30
	  lha       r0, 0x1A(r29)
	  lwz       r12, 0x0(r30)
	  lha       r4, 0x1A(r30)
	  lwz       r12, 0x14(r12)
	  lha       r6, 0x18(r29)
	  add       r5, r4, r0
	  lha       r0, 0x18(r30)
	  mtlr      r12
	  add       r4, r0, r6
	  blrl
	  lwz       r3, 0xE0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lwz       r29, 0xC(r3)
	  b         .loc_0x80

	.loc_0x7C:
	  li        r29, 0

	.loc_0x80:
	  cmplwi    r29, 0
	  bne+      .loc_0x3C
	  addic.    r0, r30, 0xD0
	  lwz       r3, 0xE0(r30)
	  addi      r4, r30, 0xD0
	  beq-      .loc_0x9C
	  addi      r4, r4, 0xC

	.loc_0x9C:
	  bl        -0xC6C4
	  addic.    r0, r30, 0xD0
	  addi      r4, r30, 0xD0
	  beq-      .loc_0xB0
	  addi      r4, r4, 0xC

	.loc_0xB0:
	  addi      r3, r31, 0xD0
	  bl        -0xC798
	  b         .loc_0x100

	.loc_0xBC:
	  mr        r3, r30
	  lha       r0, 0x1A(r31)
	  lwz       r12, 0x0(r30)
	  lha       r4, 0x1A(r30)
	  lwz       r12, 0x14(r12)
	  lha       r6, 0x18(r31)
	  sub       r5, r4, r0
	  lha       r0, 0x18(r30)
	  mtlr      r12
	  sub       r4, r0, r6
	  blrl
	  lwz       r3, 0xE0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  lwz       r31, 0xC(r3)
	  b         .loc_0x100

	.loc_0xFC:
	  li        r31, 0

	.loc_0x100:
	  cmplwi    r31, 0
	  bne+      .loc_0xBC
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void zen::P2DPaneLibrary::printTag(P2DPane*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::P2DPaneLibrary::printUseTexName(P2DPane*, IDelegate1<char*>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void zen::P2DPaneLibrary::printUseTexName(char*, IDelegate1<char*>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801BFCC4
 * Size:	000168
 */
zen::BalloonPane::BalloonPane(P2DPane*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802D
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0x3004
	  li        r5, 0x10
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  fmr       f31, f1
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r30, 0x4
	  bl        -0xF600
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x1544
	  stw       r0, 0x0(r30)
	  lis       r4, 0x4330
	  addi      r3, r30, 0
	  lfs       f0, -0x4754(r2)
	  stfs      f0, 0x10(r30)
	  stfs      f0, 0xC(r30)
	  stfs      f0, 0x8(r30)
	  stfs      f0, 0x1C(r30)
	  stfs      f0, 0x18(r30)
	  stfs      f0, 0x14(r30)
	  stfs      f0, 0x28(r30)
	  stfs      f0, 0x24(r30)
	  stfs      f0, 0x20(r30)
	  stfs      f0, 0x34(r30)
	  stfs      f0, 0x30(r30)
	  stfs      f0, 0x2C(r30)
	  lha       r7, 0x1A(r31)
	  lha       r6, 0x1E(r31)
	  lha       r5, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r6, r6, r7
	  srawi     r6, r6, 0x1
	  sub       r0, r0, r5
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r6
	  sth       r0, 0xBA(r31)
	  lha       r0, 0x18(r31)
	  lha       r5, 0x1A(r31)
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x4750(r2)
	  stw       r0, 0x3C(r1)
	  xoris     r0, r5, 0x8000
	  stw       r0, 0x44(r1)
	  stw       r4, 0x38(r1)
	  stw       r4, 0x40(r1)
	  lfd       f0, 0x38(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f0, f0, f2
	  fsubs     f1, f1, f2
	  stfs      f0, 0x8(r30)
	  stfs      f1, 0xC(r30)
	  lfs       f0, 0x1AE0(r13)
	  stfs      f0, 0x10(r30)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x14(r30)
	  lfs       f0, 0xC(r30)
	  stfs      f0, 0x18(r30)
	  lfs       f0, 0x10(r30)
	  stfs      f0, 0x1C(r30)
	  stfs      f31, 0x4(r30)
	  lfs       f0, 0x1AE4(r13)
	  stfs      f0, 0x2C(r30)
	  lfs       f0, 0x1AE8(r13)
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x1AEC(r13)
	  stfs      f0, 0x34(r30)
	  bl        0x3C8
	  mr        r3, r30
	  bl        0x49C
	  mr        r3, r30
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BFE2C
 * Size:	00039C
 */
bool zen::BalloonPane::invoke(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stfd      f30, 0xC8(r1)
	  stfd      f29, 0xC0(r1)
	  stw       r31, 0xBC(r1)
	  mr        r31, r4
	  stw       r30, 0xB8(r1)
	  mr        r30, r3
	  lfs       f4, 0x24(r3)
	  lfs       f3, 0x18(r3)
	  lfs       f2, 0x20(r3)
	  lfs       f1, 0x14(r3)
	  fsubs     f30, f4, f3
	  lfs       f3, 0x28(r3)
	  fsubs     f29, f2, f1
	  lfs       f2, 0x1C(r3)
	  fmuls     f1, f30, f30
	  fsubs     f31, f3, f2
	  lfs       f0, -0x4754(r2)
	  fmuls     f2, f29, f29
	  fmuls     f3, f31, f31
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xC4
	  fsqrte    f1, f4
	  lfd       f3, -0x4748(r2)
	  lfd       f2, -0x4740(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x70(r1)
	  lfs       f4, 0x70(r1)

	.loc_0xC4:
	  lfs       f0, 0x4(r30)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0xD8
	  mr        r3, r30
	  bl        .loc_0x39C

	.loc_0xD8:
	  bl        0x5816C
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4750(r2)
	  stw       r0, 0xB4(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x4734(r2)
	  stw       r0, 0xB0(r1)
	  lfs       f1, -0x4738(r2)
	  lfd       f0, 0xB0(r1)
	  lwz       r3, 0x2DEC(r13)
	  fsubs     f4, f0, f2
	  lfs       f0, 0x2C(r30)
	  lfs       f2, 0x28C(r3)
	  fdivs     f3, f4, f3
	  fmuls     f3, f1, f3
	  fadds     f1, f1, f3
	  fmuls     f1, f2, f1
	  fmuls     f3, f29, f1
	  fmuls     f2, f30, f1
	  fmuls     f1, f31, f1
	  fadds     f0, f0, f3
	  stfs      f0, 0x2C(r30)
	  lfs       f0, 0x30(r30)
	  fadds     f0, f0, f2
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x34(r30)
	  fadds     f0, f0, f1
	  stfs      f0, 0x34(r30)
	  lfs       f0, 0x2C(r30)
	  lfs       f1, -0x4730(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r30)
	  lfs       f0, 0x30(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x34(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r30)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x2C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x30(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r30)
	  lfs       f1, 0x1C(r30)
	  lfs       f0, 0x34(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r30)
	  lfs       f3, 0x18(r30)
	  lfs       f0, 0xC(r30)
	  lfs       f2, 0x14(r30)
	  lfs       f1, 0x8(r30)
	  fsubs     f0, f3, f0
	  lfs       f4, 0x1C(r30)
	  fsubs     f1, f2, f1
	  lfs       f2, 0x10(r30)
	  fmuls     f3, f0, f0
	  fsubs     f6, f4, f2
	  lfs       f2, -0x4754(r2)
	  fmuls     f4, f1, f1
	  fmuls     f5, f6, f6
	  fadds     f3, f4, f3
	  fadds     f7, f5, f3
	  fcmpo     cr0, f7, f2
	  ble-      .loc_0x23C
	  fsqrte    f3, f7
	  lfd       f5, -0x4748(r2)
	  lfd       f4, -0x4740(r2)
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f7, f2
	  fsub      f2, f4, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f7, f2
	  fsub      f2, f4, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f5, f3
	  fmul      f2, f7, f2
	  fsub      f2, f4, f2
	  fmul      f2, f3, f2
	  fmul      f2, f7, f2
	  frsp      f2, f2
	  stfs      f2, 0x68(r1)
	  lfs       f7, 0x68(r1)

	.loc_0x23C:
	  lfs       f3, -0x472C(r2)
	  lfs       f2, 0x4(r30)
	  fmuls     f2, f3, f2
	  fcmpo     cr0, f7, f2
	  ble-      .loc_0x284
	  fdivs     f5, f2, f7
	  lfs       f2, 0x8(r30)
	  lfs       f3, 0xC(r30)
	  lfs       f4, 0x10(r30)
	  fmuls     f8, f1, f5
	  fmuls     f7, f0, f5
	  fmuls     f1, f6, f5
	  fadds     f0, f2, f8
	  fadds     f2, f3, f7
	  fadds     f1, f4, f1
	  stfs      f0, 0x14(r30)
	  stfs      f2, 0x18(r30)
	  stfs      f1, 0x1C(r30)

	.loc_0x284:
	  lfs       f1, 0x18(r30)
	  lfs       f0, -0x4754(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2A4
	  lfs       f0, -0x4728(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x2AC

	.loc_0x2A4:
	  lfs       f0, -0x4728(r2)
	  fsubs     f0, f1, f0

	.loc_0x2AC:
	  lfs       f2, 0x14(r30)
	  fctiwz    f1, f0
	  lfs       f0, -0x4754(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0xB0(r1)
	  lwz       r5, 0xB4(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2D8
	  lfs       f0, -0x4728(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x2E0

	.loc_0x2D8:
	  lfs       f0, -0x4728(r2)
	  fsubs     f0, f2, f0

	.loc_0x2E0:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0xB0(r1)
	  mtlr      r12
	  lwz       r4, 0xB4(r1)
	  blrl
	  lfs       f2, 0x3C(r30)
	  lfs       f1, 0xBC(r31)
	  lfs       f0, -0x4724(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  fmr       f3, f1
	  ble-      .loc_0x328
	  lfs       f0, -0x4720(r2)
	  fsubs     f3, f3, f0
	  b         .loc_0x33C

	.loc_0x328:
	  lfs       f0, -0x471C(r2)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x33C
	  lfs       f0, -0x4720(r2)
	  fadds     f3, f3, f0

	.loc_0x33C:
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f2, -0x4738(r2)
	  li        r4, 0x7A
	  lfs       f1, 0x28C(r5)
	  lfs       f0, 0x38(r30)
	  fmuls     f1, f2, f1
	  fmuls     f3, f3, f1
	  fadds     f0, f0, f3
	  stfs      f0, 0x38(r30)
	  lfs       f1, 0x38(r30)
	  lfs       f0, 0xBC(r31)
	  fadds     f1, f1, f0
	  bl        -0x39990
	  lwz       r0, 0xDC(r1)
	  li        r3, 0
	  lfd       f31, 0xD0(r1)
	  lfd       f30, 0xC8(r1)
	  lfd       f29, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr

	.loc_0x39C:
	*/
}

/*
 * --INFO--
 * Address:	801C01C8
 * Size:	0000DC
 */
void zen::BalloonPane::setGoalPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  mr        r30, r3
	  bl        0x57E8C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4750(r2)
	  stw       r0, 0x64(r1)
	  lis       r31, 0x4330
	  lfs       f3, -0x4734(r2)
	  stw       r31, 0x60(r1)
	  lfs       f2, -0x4718(r2)
	  lfd       f1, 0x60(r1)
	  lfs       f0, -0x475C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, 0x4(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f31, f1, f0
	  bl        0x57E4C
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0xC(r30)
	  stw       r0, 0x5C(r1)
	  lfd       f1, -0x4750(r2)
	  fadds     f7, f0, f31
	  stw       r31, 0x58(r1)
	  lfs       f3, -0x4734(r2)
	  lfd       f0, 0x58(r1)
	  lfs       f5, -0x4718(r2)
	  fsubs     f4, f0, f1
	  lfs       f0, -0x475C(r2)
	  lfs       f1, 0x4(r30)
	  lfs       f2, 0x8(r30)
	  fdivs     f6, f4, f3
	  lfs       f4, 0x10(r30)
	  lfs       f3, 0x1AF0(r13)
	  fmuls     f5, f5, f6
	  fadds     f3, f4, f3
	  fsubs     f0, f5, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x20(r30)
	  stfs      f7, 0x24(r30)
	  stfs      f3, 0x28(r30)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C02A4
 * Size:	00006C
 */
void zen::BalloonPane::setGoalRotate()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  bl        0x57DB8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4750(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x4734(r2)
	  stw       r0, 0x18(r1)
	  lfs       f2, -0x4718(r2)
	  lfd       f1, 0x18(r1)
	  lfs       f0, -0x475C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x4714(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0x3C(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
