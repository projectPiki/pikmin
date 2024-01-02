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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
GmWin::GmWin()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GmWin::setRect(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GmWin::moveHome(Vector2i&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80111E14
 * Size:	00000C
 */
void GmWin::open()
{
	// Generated from stw r0, 0x28(r3)
	_28 = 4096;
}

/*
 * --INFO--
 * Address:	80111E20
 * Size:	00004C
 */
void GmWin::close()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x14(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  li        r0, 0x1002
	  stw       r0, 0x28(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80111E6C
 * Size:	00019C
 */
void GmWin::render(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  mr        r31, r4
	  addi      r4, r1, 0x24
	  stw       r30, 0x80(r1)
	  mr        r30, r3
	  addi      r5, r1, 0x64
	  stw       r29, 0x7C(r1)
	  li        r29, 0
	  lwz       r6, 0x1C(r3)
	  lwz       r0, 0x18(r3)
	  addi      r3, r31, 0
	  stw       r29, 0x64(r1)
	  stw       r29, 0x68(r1)
	  stw       r0, 0x6C(r1)
	  stw       r6, 0x70(r1)
	  lwz       r6, 0x64(r1)
	  lwz       r0, 0x20(r30)
	  add       r0, r6, r0
	  stw       r0, 0x64(r1)
	  lwz       r6, 0x6C(r1)
	  lwz       r0, 0x20(r30)
	  add       r0, r6, r0
	  stw       r0, 0x6C(r1)
	  lwz       r6, 0x68(r1)
	  lwz       r0, 0x24(r30)
	  add       r0, r6, r0
	  stw       r0, 0x68(r1)
	  lwz       r6, 0x70(r1)
	  lwz       r0, 0x24(r30)
	  add       r0, r6, r0
	  stw       r0, 0x70(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x38
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x3C
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x30F0(r13)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  stw       r29, 0x14(r1)
	  li        r0, 0x80
	  addi      r5, r1, 0x14
	  stw       r29, 0x18(r1)
	  mr        r3, r31
	  addi      r4, r1, 0x64
	  stw       r0, 0x1C(r1)
	  li        r6, 0
	  stw       r0, 0x20(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r31, 0
	  stb       r0, 0x11(r1)
	  li        r5, 0x1
	  stb       r0, 0x12(r1)
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GmWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80112008
 * Size:	000024
 */
void GmWin::placeCentre()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x1C(r3)
	  lwz       r0, 0x18(r3)
	  srawi     r4, r4, 0x1
	  srawi     r0, r0, 0x1
	  subfic    r0, r0, 0x140
	  stw       r0, 0x20(r3)
	  subfic    r0, r4, 0xF0
	  stw       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011202C
 * Size:	000050
 */
void GmWin::print(Graphics&, int, int, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r9, r3, 0
	  stw       r0, 0x4(r1)
	  mr        r0, r4
	  mr        r3, r0
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r8, 0x20(r9)
	  lwz       r12, 0xEC(r12)
	  lwz       r0, 0x24(r9)
	  add       r5, r5, r8
	  lwz       r4, 0x30F4(r13)
	  mtlr      r12
	  add       r6, r6, r0
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011207C
 * Size:	000080
 */
void GmWin::printcentre(Graphics&, int, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  mr        r27, r3
	  addi      r30, r6, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r4, r30, 0
	  lwz       r0, 0x18(r27)
	  lwz       r3, 0x30F4(r13)
	  srawi     r31, r0, 0x1
	  bl        -0xE9F78
	  srawi     r6, r3, 0x1
	  lwz       r4, 0x20(r27)
	  mr        r3, r28
	  lwz       r0, 0x24(r27)
	  lwz       r12, 0x3B4(r28)
	  add       r5, r4, r31
	  lwz       r4, 0x30F4(r13)
	  mr        r7, r30
	  lwz       r12, 0xEC(r12)
	  sub       r5, r5, r6
	  crclr     6, 0x6
	  mtlr      r12
	  add       r6, r29, r0
	  blrl
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801120FC
 * Size:	000080
 */
void GmWin::printright(Graphics&, int, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  mr        r27, r3
	  mr        r30, r6
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r4, r30, 0
	  lwz       r3, 0x30F4(r13)
	  lwz       r31, 0x18(r27)
	  bl        -0xE9FF4
	  mr        r5, r3
	  lwz       r4, 0x20(r27)
	  mr        r3, r28
	  lwz       r0, 0x24(r27)
	  lwz       r12, 0x3B4(r28)
	  add       r4, r4, r31
	  sub       r5, r4, r5
	  lwz       r4, 0x30F4(r13)
	  lwz       r12, 0xEC(r12)
	  addi      r7, r30, 0
	  crclr     6, 0x6
	  mtlr      r12
	  subi      r5, r5, 0x20
	  add       r6, r29, r0
	  blrl
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011217C
 * Size:	000058
 */
void GmWin::printleft(Graphics&, int, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r7, r3, 0
	  stw       r0, 0x4(r1)
	  mr        r0, r4
	  mr        r3, r0
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  mr        r9, r5
	  lwz       r12, 0x3B4(r3)
	  lwz       r8, 0x20(r7)
	  lwz       r12, 0xEC(r12)
	  lwz       r0, 0x24(r7)
	  addi      r7, r6, 0
	  lwz       r4, 0x30F4(r13)
	  mtlr      r12
	  addi      r5, r8, 0x20
	  add       r6, r9, r0
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801121D4
 * Size:	000068
 */
void GmWin::printStart(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x40
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x44
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8011223C
 * Size:	000098
 */
void GmWin::texture(Graphics&, Texture*, int, int, int, int, RectArea)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r26, r4
	  addi      r4, r5, 0
	  mr        r29, r8
	  addi      r30, r9, 0
	  addi      r31, r10, 0
	  li        r5, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r11, 0x20(r3)
	  lwz       r12, 0xCC(r12)
	  lwz       r0, 0x24(r3)
	  mr        r3, r26
	  mtlr      r12
	  add       r27, r6, r11
	  add       r28, r7, r0
	  blrl
	  stw       r27, 0x28(r1)
	  add       r5, r27, r29
	  add       r0, r28, r30
	  stw       r28, 0x2C(r1)
	  addi      r4, r1, 0x28
	  addi      r3, r26, 0
	  stw       r5, 0x30(r1)
	  mr        r5, r31
	  li        r6, 0
	  stw       r0, 0x34(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801122D4
 * Size:	0000A8
 */
void GmWin::texturecentre(Graphics&, Texture*, int, int, int, RectArea)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r26, r4
	  addi      r28, r7, 0
	  srawi     r11, r28, 0x1
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r4, 0x18(r3)
	  lwz       r12, 0xCC(r12)
	  lwz       r0, 0x24(r3)
	  srawi     r4, r4, 0x1
	  lwz       r10, 0x20(r3)
	  mtlr      r12
	  mr        r3, r26
	  add       r7, r10, r4
	  addi      r4, r5, 0
	  sub       r31, r7, r11
	  add       r27, r6, r0
	  li        r5, 0
	  blrl
	  stw       r31, 0x24(r1)
	  add       r5, r31, r28
	  add       r0, r27, r29
	  stw       r27, 0x28(r1)
	  addi      r4, r1, 0x24
	  addi      r3, r26, 0
	  stw       r5, 0x2C(r1)
	  mr        r5, r30
	  li        r6, 0
	  stw       r0, 0x30(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011237C
 * Size:	000098
 */
void GmWin::textureleft(Graphics&, Texture*, int, int, int, RectArea)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r26, r4
	  addi      r4, r5, 0
	  mr        r28, r7
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  li        r5, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r10, 0x20(r3)
	  lwz       r12, 0xCC(r12)
	  lwz       r0, 0x24(r3)
	  mr        r3, r26
	  mtlr      r12
	  addi      r31, r10, 0x20
	  add       r27, r6, r0
	  blrl
	  stw       r31, 0x24(r1)
	  add       r5, r31, r28
	  add       r0, r27, r29
	  stw       r27, 0x28(r1)
	  addi      r4, r1, 0x24
	  addi      r3, r26, 0
	  stw       r5, 0x2C(r1)
	  mr        r5, r30
	  li        r6, 0
	  stw       r0, 0x30(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80112414
 * Size:	0000A4
 */
void GmWin::textureright(Graphics&, Texture*, int, int, int, RectArea)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r26, r4
	  mr        r28, r7
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r10, 0x20(r3)
	  lwz       r4, 0x18(r3)
	  lwz       r0, 0x24(r3)
	  mr        r3, r26
	  lwz       r12, 0xCC(r12)
	  add       r4, r10, r4
	  sub       r7, r4, r28
	  addi      r4, r5, 0
	  mtlr      r12
	  subi      r31, r7, 0x20
	  add       r27, r6, r0
	  li        r5, 0
	  blrl
	  stw       r31, 0x24(r1)
	  add       r5, r31, r28
	  add       r0, r27, r29
	  stw       r27, 0x28(r1)
	  addi      r4, r1, 0x24
	  addi      r3, r26, 0
	  stw       r5, 0x2C(r1)
	  mr        r5, r30
	  li        r6, 0
	  stw       r0, 0x30(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
GmWinMgr::GmWinMgr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GmWinMgr::addWindow(GmWin*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void GmWinMgr::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GmWin::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void GmWinMgr::render(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void GmWinMgr::getWindow(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0005B4
 */
void ContainerWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ContainerWin::setWin(int, int, ContainerWin::Listener*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000310
 */
void ContainerWin::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void ContainerWin::open()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void ContainerWin::close()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void ResultWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ResultWin::update()
{
	// UNUSED FUNCTION
}
