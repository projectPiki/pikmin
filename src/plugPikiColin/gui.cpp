#include "Menu.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005D6F8
 * Size:	0001C8
 */
Menu::Menu(Controller*, Font*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r7, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r7, 0x738C
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r27, r4, 0
	  lis       r3, 0x8022
	  li        r30, 0
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  subi      r4, r13, 0x6F40
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  addi      r3, r31, 0
	  stw       r0, 0x0(r31)
	  stw       r30, 0x10(r31)
	  stw       r30, 0xC(r31)
	  stw       r30, 0x8(r31)
	  bl        -0x38874
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6F40
	  bl        -0x1D024
	  lis       r3, 0x802B
	  subi      r0, r3, 0x79F4
	  stw       r0, 0x0(r31)
	  rlwinm    r0,r29,0,24,31
	  li        r3, 0x28
	  stw       r30, 0x54(r31)
	  stw       r30, 0x4C(r31)
	  stw       r30, 0x50(r31)
	  stw       r30, 0x48(r31)
	  stw       r30, 0x74(r31)
	  stw       r30, 0x6C(r31)
	  stw       r30, 0x70(r31)
	  stw       r30, 0x68(r31)
	  stw       r30, 0x84(r31)
	  stw       r30, 0x7C(r31)
	  stw       r30, 0x80(r31)
	  stw       r30, 0x78(r31)
	  stw       r27, 0x58(r31)
	  stw       r0, 0x3C(r31)
	  stw       r28, 0x9C(r31)
	  stw       r30, 0x20(r31)
	  stw       r30, 0xA8(r31)
	  bl        -0x167B8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xE8
	  li        r4, 0
	  li        r5, 0
	  subi      r6, r13, 0x6F38
	  li        r7, 0
	  bl        .loc_0x1C8

	.loc_0xE8:
	  stw       r30, 0x2C(r31)
	  lis       r3, 0x100
	  li        r30, 0
	  lwz       r5, 0x2C(r31)
	  li        r12, 0xA0
	  li        r11, 0x78
	  stw       r5, 0x4(r5)
	  li        r10, 0x6
	  li        r9, 0xC
	  lwz       r4, 0x2C(r31)
	  li        r8, 0x20
	  li        r7, 0x80
	  stw       r5, 0x0(r4)
	  li        r6, 0xC0
	  li        r5, 0x40
	  stw       r30, 0x40(r31)
	  li        r4, 0x1
	  addi      r0, r3, 0x1000
	  stw       r30, 0x38(r31)
	  mr        r3, r31
	  stw       r30, 0x30(r31)
	  stw       r30, 0x34(r31)
	  stw       r12, 0x48(r31)
	  stw       r11, 0x4C(r31)
	  stw       r30, 0x50(r31)
	  stw       r30, 0x54(r31)
	  stw       r10, 0x78(r31)
	  stw       r9, 0x7C(r31)
	  stw       r10, 0x80(r31)
	  stw       r9, 0x84(r31)
	  stb       r8, 0x60(r31)
	  stb       r8, 0x61(r31)
	  stb       r7, 0x62(r31)
	  stb       r6, 0x63(r31)
	  stb       r8, 0x64(r31)
	  stb       r8, 0x65(r31)
	  stb       r8, 0x66(r31)
	  stb       r5, 0x67(r31)
	  lfs       f0, -0x7970(r2)
	  stfs      f0, 0x44(r31)
	  stw       r30, 0x5C(r31)
	  stw       r30, 0x8C(r31)
	  stw       r30, 0x88(r31)
	  stw       r30, 0x94(r31)
	  stb       r4, 0x98(r31)
	  stb       r4, 0x99(r31)
	  stw       r0, 0xA4(r31)
	  stw       r30, 0xAC(r31)
	  lfs       f0, -0x796C(r2)
	  stfs      f0, 0xB0(r31)
	  stw       r30, 0x28(r31)
	  lwz       r0, 0x34(r1)
	  lmw       r27, 0x1C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x1C8:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::KeyEvent::insertAfter(Menu::KeyEvent*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::KeyEvent::remove()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::MenuItem::insertAfter(Menu::MenuItem*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::MenuItem::remove()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
Menu::KeyEvent::KeyEvent(int, int, IDelegate1<Menu&>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005D8C0
 * Size:	000094
 */
Menu::MenuItem::MenuItem(int, int, char*, IDelegate1<Menu&>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  stb       r0, 0x14(r3)
	  li        r3, 0x14
	  stw       r6, 0x18(r30)
	  stw       r5, 0x1C(r30)
	  stw       r4, 0x20(r30)
	  stw       r31, 0x4(r30)
	  stw       r31, 0x0(r30)
	  stw       r31, 0x8(r30)
	  stw       r31, 0xC(r30)
	  bl        -0x16900
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  stw       r31, 0x8(r3)
	  stw       r31, 0xC(r3)
	  stw       r31, 0x10(r3)
	  stw       r31, 0x4(r3)
	  stw       r31, 0x0(r3)

	.loc_0x64:
	  stw       r3, 0x24(r30)
	  mr        r3, r30
	  lwz       r5, 0x24(r30)
	  stw       r5, 0x0(r5)
	  lwz       r4, 0x24(r30)
	  stw       r5, 0x4(r4)
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
 * Address:	........
 * Size:	000008
 */
void Menu::setOnEnter(IDelegate1<Menu&>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Menu::setOnExit(IDelegate1<Menu&>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005D954
 * Size:	0000C8
 */
void Menu::addKeyEvent(int, int, IDelegate1<Menu&>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  li        r3, 0x14
	  bl        -0x16980
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  stw       r29, 0x8(r3)
	  li        r0, 0
	  stw       r30, 0xC(r3)
	  stw       r31, 0x10(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x0(r3)

	.loc_0x54:
	  lwz       r4, 0x34(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x84
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x0(r3)
	  lwz       r4, 0x4(r5)
	  stw       r3, 0x0(r4)
	  stw       r3, 0x4(r5)
	  b         .loc_0xA8

	.loc_0x84:
	  lwz       r4, 0x2C(r28)
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x0(r3)
	  lwz       r4, 0x4(r5)
	  stw       r3, 0x0(r4)
	  stw       r3, 0x4(r5)

	.loc_0xA8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DA1C
 * Size:	000004
 */
void Menu::enterOption() { }

/*
 * --INFO--
 * Address:	8005DA20
 * Size:	000048
 */
void Menu::enterMenu(Menu*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r4
	  addi      r3, r31, 0
	  beq-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
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
 * Address:	8005DA68
 * Size:	000044
 */
void Menu::exitMenu(Menu*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r4
	  addi      r3, r31, 0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
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
 * Address:	8005DAAC
 * Size:	00002C
 */
void Menu::open(bool)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x796C(r2)
	  li        r0, 0x1
	  stfs      f0, 0xB0(r3)
	  stw       r0, 0xAC(r3)
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lwz       r4, 0x2C(r3)
	  lwz       r0, 0x4(r4)
	  stw       r0, 0x30(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DAD8
 * Size:	000024
 */
void Menu::close()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x10
	  stw       r0, 0x24(r3)

	.loc_0x10:
	  lfs       f0, -0x7968(r2)
	  li        r0, 0x3
	  stfs      f0, 0xB0(r3)
	  stw       r0, 0xAC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DAFC
 * Size:	000020
 */
void Menu::resetOptions()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x40(r3)
	  stw       r0, 0x30(r3)
	  lwz       r4, 0x2C(r3)
	  stw       r4, 0x4(r4)
	  lwz       r3, 0x2C(r3)
	  stw       r4, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DB1C
 * Size:	000194
 */
void Menu::addOption(int, char*, IDelegate1<Menu&>*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r30, r3, 0
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  addi      r31, r6, 0
	  addi      r27, r7, 0
	  li        r3, 0x28
	  bl        -0x16B40
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x98
	  li        r0, 0x1
	  stb       r0, 0x14(r28)
	  li        r29, 0
	  li        r3, 0x14
	  stw       r26, 0x18(r28)
	  stw       r25, 0x1C(r28)
	  stw       r0, 0x20(r28)
	  stw       r29, 0x4(r28)
	  stw       r29, 0x0(r28)
	  stw       r29, 0x8(r28)
	  stw       r29, 0xC(r28)
	  bl        -0x16B7C
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  stw       r29, 0x8(r3)
	  stw       r29, 0xC(r3)
	  stw       r29, 0x10(r3)
	  stw       r29, 0x4(r3)
	  stw       r29, 0x0(r3)

	.loc_0x84:
	  stw       r3, 0x24(r28)
	  lwz       r4, 0x24(r28)
	  stw       r4, 0x0(r4)
	  lwz       r3, 0x24(r28)
	  stw       r4, 0x4(r3)

	.loc_0x98:
	  stw       r28, 0x34(r30)
	  cmplwi    r31, 0
	  lwz       r3, 0x34(r30)
	  stb       r27, 0x14(r3)
	  lwz       r3, 0x2C(r30)
	  lwz       r5, 0x34(r30)
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x4(r4)
	  stw       r0, 0x4(r5)
	  stw       r4, 0x0(r5)
	  lwz       r3, 0x4(r4)
	  stw       r5, 0x0(r3)
	  stw       r5, 0x4(r4)
	  beq-      .loc_0x154
	  lwz       r29, 0xA4(r30)
	  li        r3, 0x14
	  bl        -0x16BF0
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  li        r0, 0x10
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r29, 0xC(r3)
	  stw       r31, 0x10(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x0(r3)

	.loc_0x100:
	  lwz       r4, 0x34(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x130
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x0(r3)
	  lwz       r4, 0x4(r5)
	  stw       r3, 0x0(r4)
	  stw       r3, 0x4(r5)
	  b         .loc_0x154

	.loc_0x130:
	  lwz       r4, 0x2C(r30)
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x0(r3)
	  lwz       r4, 0x4(r5)
	  stw       r3, 0x0(r4)
	  stw       r3, 0x4(r5)

	.loc_0x154:
	  lwz       r0, 0x30(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x174
	  lwz       r3, 0x34(r30)
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x174
	  stw       r3, 0x30(r30)

	.loc_0x174:
	  lwz       r3, 0x40(r30)
	  addi      r0, r3, 0x1
	  stw       r0, 0x40(r30)
	  lwz       r0, 0x54(r1)
	  lmw       r25, 0x34(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DCB0
 * Size:	000184
 */
void Menu::addMenu(Menu*, int, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r26, 0x30(r1)
	  addi      r31, r3, 0
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  li        r3, 0x28
	  bl        -0x16CD0
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x98
	  li        r0, 0x1
	  stb       r0, 0x14(r29)
	  li        r0, 0x2
	  li        r30, 0
	  stw       r28, 0x18(r29)
	  li        r3, 0x14
	  stw       r27, 0x1C(r29)
	  stw       r0, 0x20(r29)
	  stw       r30, 0x4(r29)
	  stw       r30, 0x0(r29)
	  stw       r30, 0x8(r29)
	  stw       r30, 0xC(r29)
	  bl        -0x16D10
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  stw       r30, 0x8(r3)
	  stw       r30, 0xC(r3)
	  stw       r30, 0x10(r3)
	  stw       r30, 0x4(r3)
	  stw       r30, 0x0(r3)

	.loc_0x84:
	  stw       r3, 0x24(r29)
	  lwz       r4, 0x24(r29)
	  stw       r4, 0x0(r4)
	  lwz       r3, 0x24(r29)
	  stw       r4, 0x4(r3)

	.loc_0x98:
	  stw       r29, 0x34(r31)
	  li        r3, 0x14
	  lwz       r4, 0x34(r31)
	  stw       r26, 0xC(r4)
	  stw       r31, 0x20(r26)
	  lwz       r4, 0x2C(r31)
	  lwz       r6, 0x34(r31)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r6)
	  stw       r5, 0x0(r6)
	  lwz       r4, 0x4(r5)
	  stw       r6, 0x0(r4)
	  stw       r6, 0x4(r5)
	  lwz       r30, 0xA4(r31)
	  bl        -0x16D80
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  li        r0, 0x10
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r30, 0xC(r3)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x0(r3)

	.loc_0xFC:
	  lwz       r4, 0x34(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x12C
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x0(r3)
	  lwz       r4, 0x4(r5)
	  stw       r3, 0x0(r4)
	  stw       r3, 0x4(r5)
	  b         .loc_0x150

	.loc_0x12C:
	  lwz       r4, 0x2C(r31)
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x0(r3)
	  lwz       r4, 0x4(r5)
	  stw       r3, 0x0(r4)
	  stw       r3, 0x4(r5)

	.loc_0x150:
	  lwz       r0, 0x30(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x164
	  lwz       r0, 0x34(r31)
	  stw       r0, 0x30(r31)

	.loc_0x164:
	  lwz       r3, 0x40(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x40(r31)
	  lwz       r0, 0x4C(r1)
	  lmw       r26, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DE34
 * Size:	000150
 */
void Menu::checkNewOption()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r3, 0x58(r3)
	  lwz       r3, 0x2C(r3)
	  rlwinm.   r0,r3,0,28,28
	  bne-      .loc_0x2C
	  rlwinm.   r0,r3,0,10,10
	  beq-      .loc_0xAC

	.loc_0x2C:
	  lwz       r3, 0x30(r31)
	  addi      r4, r31, 0
	  li        r5, 0x2
	  bl        0x3A8
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x2C(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x84
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x30(r31)
	  b         .loc_0x84

	.loc_0x64:
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x2C(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x84
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x30(r31)

	.loc_0x84:
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq+      .loc_0x64
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  beq+      .loc_0x64
	  li        r0, 0x1
	  stb       r0, 0x99(r31)
	  b         .loc_0x138

	.loc_0xAC:
	  rlwinm.   r0,r3,0,29,29
	  bne-      .loc_0xBC
	  rlwinm.   r0,r3,0,12,12
	  beq-      .loc_0x138

	.loc_0xBC:
	  lwz       r3, 0x30(r31)
	  addi      r4, r31, 0
	  li        r5, 0x2
	  bl        0x318
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x2C(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x114
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x30(r31)
	  b         .loc_0x114

	.loc_0xF4:
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x2C(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x114
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x30(r31)

	.loc_0x114:
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq+      .loc_0xF4
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  beq+      .loc_0xF4
	  li        r0, 0x1
	  stb       r0, 0x99(r31)

	.loc_0x138:
	  lwz       r0, 0x2C(r1)
	  li        r3, 0
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DF84
 * Size:	00001C
 */
void Menu::checkSelectKey()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x58(r3)
	  lwz       r0, 0x28(r3)
	  rlwinm    r0,r0,0,19,19
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DFA0
 * Size:	00001C
 */
void Menu::checkCancelKey()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x58(r3)
	  lwz       r0, 0x28(r3)
	  rlwinm    r0,r0,0,18,18
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005DFBC
 * Size:	000258
 */
void Menu::doUpdate(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  mr        r30, r3
	  mr        r31, r30
	  stw       r29, 0x44(r1)
	  stw       r30, 0x24(r3)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7964(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x44(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x44(r30)
	  lwz       r0, 0xAC(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xE8
	  bge-      .loc_0x5C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x68
	  b         .loc_0x238

	.loc_0x5C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x238
	  b         .loc_0xA8

	.loc_0x68:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7960(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0xB0(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xB0(r30)
	  lfs       f1, 0xB0(r30)
	  lfs       f0, -0x7968(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x238
	  stfs      f0, 0xB0(r30)
	  li        r0, 0x2
	  stw       r0, 0xAC(r30)
	  b         .loc_0x238

	.loc_0xA8:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7960(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0xB0(r30)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0xB0(r30)
	  lfs       f1, 0xB0(r30)
	  lfs       f0, -0x796C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x238
	  stfs      f0, 0xB0(r30)
	  li        r0, 0
	  stw       r0, 0xAC(r30)
	  lwz       r31, 0x28(r30)
	  b         .loc_0x238

	.loc_0xE8:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xF8
	  li        r0, 0x1
	  stb       r0, 0x99(r30)

	.loc_0xF8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x98(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x148
	  lwz       r3, 0x88(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x138
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x138:
	  li        r0, 0
	  stb       r0, 0x98(r30)
	  li        r0, 0x1
	  stb       r0, 0x99(r30)

	.loc_0x148:
	  lbz       r0, 0x99(r30)
	  lis       r3, 0x1
	  subi      r29, r3, 0x4
	  cmplwi    r0, 0
	  beq-      .loc_0x190
	  lwz       r3, 0x94(r30)
	  ori       r29, r29, 0x1
	  cmplwi    r3, 0
	  beq-      .loc_0x180
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x180:
	  lfs       f0, -0x796C(r2)
	  li        r0, 0
	  stfs      f0, 0x44(r30)
	  stb       r0, 0x99(r30)

	.loc_0x190:
	  lwz       r3, 0x30(r30)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  bl        .loc_0x258
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1B8
	  lwz       r3, 0x2C(r30)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  bl        .loc_0x258

	.loc_0x1B8:
	  lwz       r0, 0x24(r30)
	  cmplw     r0, r30
	  beq-      .loc_0x238
	  lwz       r3, 0x30(r30)
	  addi      r4, r30, 0
	  li        r5, 0x2
	  bl        .loc_0x258
	  lwz       r3, 0x8C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F4
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1F4:
	  lwz       r3, 0x24(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x21C
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x24(r30)
	  b         .loc_0x230

	.loc_0x21C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x230:
	  lwz       r0, 0x24(r30)
	  stw       r0, 0x28(r30)

	.loc_0x238:
	  mr        r3, r31
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0x258:
	*/
}

/*
 * --INFO--
 * Address:	8005E214
 * Size:	0001FC
 */
void Menu::MenuItem::checkEvents(Menu*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  lwz       r6, 0x24(r3)
	  lis       r3, 0x802B
	  subi      r31, r3, 0x7AC0
	  lwz       r30, 0x4(r6)
	  b         .loc_0x1D8

	.loc_0x30:
	  lwz       r3, 0x8(r30)
	  and.      r0, r29, r3
	  beq-      .loc_0x1D4
	  cmplwi    r3, 0x20
	  bgt-      .loc_0x1D4
	  rlwinm    r0,r3,2,0,29
	  lwzx      r0, r31, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x10(r30)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1D4
	  lwz       r3, 0x10(r30)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1D4
	  lwz       r3, 0x58(r28)
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x20(r3)
	  and.      r0, r3, r0
	  beq-      .loc_0x1D4
	  lwz       r3, 0x10(r30)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1D4
	  lwz       r3, 0x58(r28)
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x2C(r3)
	  and.      r0, r3, r0
	  beq-      .loc_0x1D4
	  lwz       r3, 0x10(r30)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x1E8
	  lwz       r3, 0x58(r28)
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x2C(r3)
	  and.      r0, r3, r0
	  beq-      .loc_0x1D4
	  lwz       r3, 0x30(r28)
	  lwz       r0, 0x20(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x1B4
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  li        r5, 0x2
	  bl        .loc_0x0
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  stw       r28, 0x24(r28)
	  li        r4, 0
	  lwz       r3, 0x30(r28)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x28(r28)
	  lwz       r3, 0x28(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x28(r28)
	  lwz       r0, 0x3C(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x198
	  lwz       r3, 0x40(r28)
	  lwz       r0, 0xA0(r28)
	  mulli     r4, r3, 0xE
	  lwz       r3, 0x4C(r28)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  mulli     r0, r0, 0xE
	  sub       r3, r3, r4
	  add       r0, r3, r0
	  stw       r0, 0x4C(r5)

	.loc_0x198:
	  li        r0, 0x1
	  stb       r0, 0x98(r28)
	  li        r3, 0
	  lwz       r4, 0x30(r28)
	  lwz       r4, 0xC(r4)
	  stb       r0, 0x98(r4)
	  b         .loc_0x1E8

	.loc_0x1B4:
	  lwz       r3, 0x10(r30)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x1E8

	.loc_0x1D4:
	  lwz       r30, 0x4(r30)

	.loc_0x1D8:
	  lwz       r0, 0x24(r27)
	  cmplw     r30, r0
	  bne+      .loc_0x30
	  li        r3, 0

	.loc_0x1E8:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005E410
 * Size:	00060C
 */
void Menu::draw(Graphics&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stfd      f30, 0x1E8(r1)
	  fmr       f30, f1
	  stfd      f29, 0x1E0(r1)
	  stmw      r19, 0x1AC(r1)
	  mr        r27, r4
	  mr        r26, r3
	  li        r30, 0
	  lwz       r0, 0x40(r3)
	  lwz       r3, 0x2C(r3)
	  mulli     r4, r0, 0xE
	  lwz       r0, 0x4C(r26)
	  lwz       r19, 0x4(r3)
	  srawi     r3, r4, 0x1
	  addze     r3, r3
	  sub       r31, r0, r3
	  b         .loc_0x7C

	.loc_0x50:
	  lwz       r4, 0x18(r19)
	  cmplwi    r4, 0
	  beq-      .loc_0x78
	  lwz       r3, 0x9C(r26)
	  bl        -0x3633C
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  cmpw      r0, r30
	  ble-      .loc_0x78
	  mr        r30, r0

	.loc_0x78:
	  lwz       r19, 0x4(r19)

	.loc_0x7C:
	  lwz       r0, 0x2C(r26)
	  cmplw     r19, r0
	  bne+      .loc_0x50
	  lwz       r0, 0x40(r26)
	  addi      r24, r30, 0x10
	  lfs       f3, 0xB0(r26)
	  li        r28, 0x1
	  mulli     r3, r0, 0x7
	  lfs       f0, -0x7968(r2)
	  fmr       f31, f3
	  lwz       r29, 0x48(r26)
	  add       r21, r31, r3
	  fcmpu     cr0, f0, f3
	  addi      r21, r21, 0x3
	  addi      r20, r3, 0xE
	  beq-      .loc_0x144
	  lwz       r3, 0x28(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  lwz       r0, 0x3C(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xE4
	  lfs       f1, -0x795C(r2)
	  fmuls     f0, f1, f3
	  fadds     f31, f1, f0
	  b         .loc_0x144

	.loc_0xE4:
	  lfs       f0, -0x7968(r2)
	  fcmpu     cr0, f0, f3
	  beq-      .loc_0xF4
	  li        r28, 0

	.loc_0xF4:
	  xoris     r3, r24, 0x8000
	  lfd       f2, -0x7950(r2)
	  xoris     r0, r20, 0x8000
	  stw       r3, 0x1A4(r1)
	  lis       r3, 0x4330
	  stw       r0, 0x194(r1)
	  stw       r3, 0x1A0(r1)
	  stw       r3, 0x190(r1)
	  lfd       f1, 0x1A0(r1)
	  lfd       f0, 0x190(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fmuls     f1, f1, f3
	  fmuls     f0, f0, f3
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x198(r1)
	  stfd      f0, 0x188(r1)
	  lwz       r24, 0x19C(r1)
	  lwz       r20, 0x18C(r1)

	.loc_0x144:
	  mr        r3, r27
	  fmuls     f31, f31, f30
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x63(r26)
	  lis       r25, 0x4330
	  lfd       f1, -0x7948(r2)
	  addi      r4, r1, 0x70
	  stw       r0, 0x18C(r1)
	  lbz       r7, 0x62(r26)
	  mr        r3, r27
	  stw       r25, 0x188(r1)
	  li        r5, 0x1
	  lbz       r6, 0x61(r26)
	  lfd       f0, 0x188(r1)
	  lbz       r0, 0x60(r26)
	  fsubs     f0, f0, f1
	  stb       r0, 0x70(r1)
	  fmuls     f0, f0, f31
	  stb       r6, 0x71(r1)
	  stb       r7, 0x72(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x190(r1)
	  lwz       r0, 0x194(r1)
	  stb       r0, 0x73(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x67(r26)
	  addi      r4, r1, 0x6C
	  lfd       f1, -0x7948(r2)
	  mr        r3, r27
	  stw       r0, 0x19C(r1)
	  lbz       r6, 0x66(r26)
	  stw       r25, 0x198(r1)
	  lbz       r5, 0x65(r26)
	  lfd       f0, 0x198(r1)
	  lbz       r0, 0x64(r26)
	  fsubs     f0, f0, f1
	  stb       r0, 0x6C(r1)
	  fmuls     f0, f0, f31
	  stb       r5, 0x6D(r1)
	  stb       r6, 0x6E(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x1A0(r1)
	  lwz       r0, 0x1A4(r1)
	  stb       r0, 0x6F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  sub       r22, r29, r24
	  stw       r22, 0x5C(r1)
	  sub       r23, r21, r20
	  add       r24, r29, r24
	  stw       r23, 0x60(r1)
	  add       r21, r21, r20
	  addi      r4, r1, 0x5C
	  stw       r24, 0x64(r1)
	  mr        r3, r27
	  stw       r21, 0x68(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7958(r2)
	  li        r20, 0x40
	  stb       r20, 0x58(r1)
	  li        r19, 0xC0
	  fmuls     f0, f0, f31
	  stb       r20, 0x59(r1)
	  addi      r4, r1, 0x58
	  addi      r3, r27, 0
	  fctiwz    f29, f0
	  stb       r19, 0x5A(r1)
	  li        r5, 0x1
	  stfd      f29, 0x180(r1)
	  lwz       r0, 0x184(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r20, 0x54(r1)
	  addi      r4, r1, 0x54
	  addi      r3, r27, 0
	  stb       r20, 0x55(r1)
	  stfd      f29, 0x178(r1)
	  stb       r19, 0x56(r1)
	  lwz       r0, 0x17C(r1)
	  stb       r0, 0x57(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  stw       r22, 0x44(r1)
	  addi      r4, r1, 0x44
	  addi      r3, r27, 0
	  stw       r23, 0x48(r1)
	  stw       r24, 0x4C(r1)
	  stw       r21, 0x50(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xDC(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x5EC
	  lbz       r0, 0x63(r26)
	  li        r19, 0
	  lwz       r4, 0x2C(r26)
	  mulli     r3, r19, 0xE
	  stw       r0, 0x17C(r1)
	  lfd       f1, -0x7948(r2)
	  stw       r25, 0x178(r1)
	  addi      r0, r30, 0x8
	  sub       r21, r29, r0
	  lwz       r20, 0x4(r4)
	  lfd       f0, 0x178(r1)
	  li        r0, 0
	  fsubs     f0, f0, f1
	  stw       r0, 0xA0(r26)
	  add       r22, r31, r3
	  lfs       f29, -0x7968(r2)
	  addi      r23, r1, 0x34
	  fmuls     f0, f0, f30
	  lfs       f31, -0x7954(r2)
	  addi      r24, r1, 0x38
	  addi      r28, r1, 0x3C
	  fctiwz    f30, f0
	  addi      r25, r1, 0x40
	  b         .loc_0x51C

	.loc_0x364:
	  lwz       r0, 0x18(r20)
	  cmplwi    r0, 0
	  beq-      .loc_0x510
	  lwz       r0, 0x30(r26)
	  cmplw     r20, r0
	  bne-      .loc_0x424
	  lwz       r0, 0xAC(r26)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C8
	  li        r6, 0xC0
	  stfd      f30, 0x178(r1)
	  li        r5, 0
	  stb       r6, 0x40(r1)
	  mr        r3, r27
	  lwz       r0, 0x17C(r1)
	  mr        r4, r25
	  stb       r6, 0x41(r1)
	  stb       r5, 0x42(r1)
	  li        r5, 0x1
	  stb       r0, 0x43(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4AC

	.loc_0x3C8:
	  stw       r19, 0xA0(r26)
	  lfs       f1, 0x44(r26)
	  bl        0x1BD508
	  fadds     f0, f29, f1
	  stfd      f30, 0x180(r1)
	  mr        r3, r27
	  lwz       r0, 0x184(r1)
	  mr        r4, r28
	  fmuls     f0, f31, f0
	  li        r5, 0x1
	  fctiwz    f0, f0
	  stfd      f0, 0x178(r1)
	  lwz       r6, 0x17C(r1)
	  addi      r6, r6, 0x40
	  stb       r6, 0x3C(r1)
	  stb       r6, 0x3D(r1)
	  stb       r6, 0x3E(r1)
	  stb       r0, 0x3F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4AC

	.loc_0x424:
	  lbz       r0, 0x14(r20)
	  cmplwi    r0, 0
	  bne-      .loc_0x470
	  li        r6, 0xFF
	  stfd      f30, 0x178(r1)
	  li        r5, 0x80
	  stb       r6, 0x38(r1)
	  mr        r3, r27
	  lwz       r0, 0x17C(r1)
	  mr        r4, r24
	  stb       r6, 0x39(r1)
	  stb       r5, 0x3A(r1)
	  li        r5, 0x1
	  stb       r0, 0x3B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4AC

	.loc_0x470:
	  li        r6, 0x80
	  stfd      f30, 0x178(r1)
	  li        r5, 0x40
	  stb       r6, 0x34(r1)
	  mr        r3, r27
	  lwz       r0, 0x17C(r1)
	  mr        r4, r23
	  stb       r6, 0x35(r1)
	  stb       r5, 0x36(r1)
	  li        r5, 0x1
	  stb       r0, 0x37(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl

	.loc_0x4AC:
	  lwz       r5, 0x18(r20)
	  addi      r3, r1, 0x74
	  crclr     6, 0x6
	  subi      r4, r13, 0x6F30
	  bl        0x1B7CCC
	  lwz       r3, 0x9C(r26)
	  addi      r4, r1, 0x74
	  bl        -0x367A4
	  lwz       r0, 0xA8(r26)
	  cmpwi     r0, 0
	  bne-      .loc_0x4E8
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  sub       r5, r29, r0
	  b         .loc_0x4EC

	.loc_0x4E8:
	  mr        r5, r21

	.loc_0x4EC:
	  lwz       r12, 0x3B4(r27)
	  mr        r3, r27
	  lwz       r4, 0x9C(r26)
	  addi      r6, r22, 0
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  addi      r7, r1, 0x74
	  mtlr      r12
	  blrl

	.loc_0x510:
	  lwz       r20, 0x4(r20)
	  addi      r22, r22, 0xE
	  addi      r19, r19, 0x1

	.loc_0x51C:
	  lwz       r0, 0x40(r26)
	  cmpw      r19, r0
	  blt+      .loc_0x364
	  lwz       r0, 0xA0(r26)
	  li        r19, 0x80
	  addi      r4, r1, 0x30
	  stb       r19, 0x30(r1)
	  mulli     r3, r0, 0xE
	  stb       r19, 0x31(r1)
	  addi      r20, r3, 0x1
	  stb       r19, 0x32(r1)
	  mr        r3, r27
	  add       r20, r31, r20
	  stb       r19, 0x33(r1)
	  li        r5, 0x1
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xC0
	  stb       r0, 0x2C(r1)
	  addi      r4, r1, 0x2C
	  addi      r3, r27, 0
	  stb       r0, 0x2D(r1)
	  stb       r0, 0x2E(r1)
	  stb       r19, 0x2F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x48(r26)
	  addi      r0, r21, 0x4
	  addi      r4, r1, 0x1C
	  stw       r0, 0x1C(r1)
	  add       r3, r30, r3
	  addi      r5, r3, 0x4
	  stw       r20, 0x20(r1)
	  addi      r0, r20, 0xE
	  addi      r3, r27, 0
	  stw       r5, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xDC(r12)
	  mtlr      r12
	  blrl

	.loc_0x5EC:
	  lmw       r19, 0x1AC(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EA1C
 * Size:	000064
 */
void Menu::menuCloseMenu(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r0, 0x20(r4)
	  stw       r0, 0x28(r4)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
