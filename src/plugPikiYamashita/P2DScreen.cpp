#include "P2D/Screen.h"
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
 * Address:	801B2B50
 * Size:	00004C
 */
void P2DScreen::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x2420
	  lwz       r3, 0xF0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  bl        -0x33B58

	.loc_0x28:
	  lwz       r3, 0xF4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  bl        -0x32BB4

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
 * Address:	801B2B9C
 * Size:	000064
 */
P2DScreen::~P2DScreen()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x48
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x1E0C
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x16BA34

	.loc_0x48:
	  mr        r3, r30
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
 * Address:	801B2C00
 * Size:	00012C
 */
void P2DScreen::set(const char*, bool, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stw       r31, 0x124(r1)
	  addi      r31, r7, 0
	  stw       r30, 0x120(r1)
	  addi      r30, r6, 0
	  stw       r29, 0x11C(r1)
	  addi      r29, r5, 0
	  addi      r5, r1, 0x14
	  stw       r28, 0x118(r1)
	  addi      r28, r3, 0
	  bl        0x61C
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r31, 0
	  addi      r4, r1, 0x14
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x88
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  addi      r5, r31, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        .loc_0x12C
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x88:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0xD0
	  li        r3, 0x198
	  bl        -0x16BCA4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xC0
	  mr        r4, r28
	  bl        -0x3413C

	.loc_0xC0:
	  stw       r31, 0xF0(r28)
	  lwz       r3, 0xF0(r28)
	  bl        -0x33E20
	  b         .loc_0xD8

	.loc_0xD0:
	  li        r0, 0
	  stw       r0, 0xF0(r28)

	.loc_0xD8:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x104
	  li        r3, 0x194
	  bl        -0x16BCE0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xFC
	  mr        r4, r28
	  bl        -0x32E1C

	.loc_0xFC:
	  stw       r31, 0xF4(r28)
	  b         .loc_0x10C

	.loc_0x104:
	  li        r0, 0
	  stw       r0, 0xF4(r28)

	.loc_0x10C:
	  lwz       r0, 0x12C(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  lwz       r29, 0x11C(r1)
	  lwz       r28, 0x118(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr

	.loc_0x12C:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void P2DScreen::set(RandomAccessStream*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B2D2C
 * Size:	0001A0
 */
void P2DScreen::makeHiearachyPanes(P2DPane*, RandomAccessStream*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r27, r4, 0
	  lis       r4, 0x802E
	  addi      r26, r3, 0
	  addi      r28, r5, 0
	  addi      r29, r27, 0
	  addi      r30, r4, 0x784
	  rlwinm    r31,r7,0,24,31

	.loc_0x2C:
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,16,31
	  cmplwi    r0, 0x13
	  addi      r25, r3, 0
	  bgt+      .loc_0x2C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r30, r0
	  mtctr     r0
	  bctr
	  b         .loc_0x18C
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r26, 0
	  addi      r4, r29, 0
	  addi      r5, r28, 0
	  li        r6, 0x1
	  li        r7, 0
	  bl        .loc_0x0
	  b         .loc_0x2C
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x18C
	  li        r3, 0xEC
	  bl        -0x16BDD8
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xD0
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  addi      r6, r25, 0
	  bl        -0x22C4

	.loc_0xD0:
	  cmplwi    r31, 0
	  beq+      .loc_0x2C
	  lha       r7, 0x1A(r29)
	  addi      r3, r1, 0x28
	  lha       r6, 0x1E(r29)
	  li        r4, 0
	  lha       r5, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r7, r6, r7
	  sub       r6, r0, r5
	  li        r5, 0
	  bl        0x800
	  lwz       r3, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x18(r26)
	  stw       r0, 0x1C(r26)
	  b         .loc_0x2C
	  li        r3, 0x12C
	  bl        -0x16BE40
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq+      .loc_0x2C
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  li        r6, 0x11
	  bl        0xB78
	  b         .loc_0x2C
	  li        r3, 0x114
	  bl        -0x16BE68
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq+      .loc_0x2C
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  li        r6, 0x12
	  bl        -0x1444
	  b         .loc_0x2C
	  li        r3, 0x118
	  bl        -0x16BE90
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq+      .loc_0x2C
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  li        r6, 0x13
	  bl        0x1684
	  b         .loc_0x2C

	.loc_0x18C:
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B2ECC
 * Size:	000008
 */
void P2DScreen::makeUserPane(u16, P2DPane*, RandomAccessStream*)
{
	// return 0x0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
P2DPane* P2DScreen::stop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B2ED4
 * Size:	000328
 */
void P2DScreen::draw(int, int, const P2DGrafContext*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E8(r1)
	  stmw      r27, 0x1D4(r1)
	  mr.       r30, r6
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  beq-      .loc_0x258
	  lis       r3, 0x802E
	  addi      r31, r3, 0x5D4
	  stw       r31, 0xFC(r1)
	  addi      r3, r1, 0x104
	  addi      r4, r30, 0x8
	  lwz       r0, 0x4(r30)
	  stw       r0, 0x100(r1)
	  bl        0x738
	  addi      r3, r1, 0x10C
	  addi      r4, r30, 0x10
	  bl        0x72C
	  lbz       r0, 0x18(r30)
	  stb       r0, 0x114(r1)
	  lbz       r0, 0x19(r30)
	  stb       r0, 0x115(r1)
	  lbz       r0, 0x1A(r30)
	  stb       r0, 0x116(r1)
	  lbz       r0, 0x1B(r30)
	  stb       r0, 0x117(r1)
	  lbz       r0, 0x1C(r30)
	  stb       r0, 0x118(r1)
	  lbz       r0, 0x1D(r30)
	  stb       r0, 0x119(r1)
	  lbz       r0, 0x1E(r30)
	  stb       r0, 0x11A(r1)
	  lbz       r0, 0x1F(r30)
	  stb       r0, 0x11B(r1)
	  lbz       r0, 0x20(r30)
	  stb       r0, 0x11C(r1)
	  lbz       r0, 0x21(r30)
	  stb       r0, 0x11D(r1)
	  lbz       r0, 0x22(r30)
	  stb       r0, 0x11E(r1)
	  lbz       r0, 0x23(r30)
	  stb       r0, 0x11F(r1)
	  lbz       r0, 0x24(r30)
	  stb       r0, 0x120(r1)
	  lbz       r0, 0x25(r30)
	  stb       r0, 0x121(r1)
	  lbz       r0, 0x26(r30)
	  stb       r0, 0x122(r1)
	  lbz       r0, 0x27(r30)
	  stb       r0, 0x123(r1)
	  lbz       r0, 0x28(r30)
	  stb       r0, 0x124(r1)
	  lha       r0, 0x2A(r30)
	  sth       r0, 0x126(r1)
	  lha       r0, 0x2C(r30)
	  sth       r0, 0x128(r1)
	  lwz       r3, 0x30(r30)
	  lwz       r0, 0x34(r30)
	  stw       r3, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  lwz       r3, 0x38(r30)
	  lwz       r0, 0x3C(r30)
	  stw       r3, 0x134(r1)
	  stw       r0, 0x138(r1)
	  lwz       r3, 0x40(r30)
	  lwz       r0, 0x44(r30)
	  stw       r3, 0x13C(r1)
	  stw       r0, 0x140(r1)
	  lwz       r3, 0x48(r30)
	  lwz       r0, 0x4C(r30)
	  stw       r3, 0x144(r1)
	  stw       r0, 0x148(r1)
	  lwz       r3, 0x50(r30)
	  lwz       r0, 0x54(r30)
	  stw       r3, 0x14C(r1)
	  stw       r0, 0x150(r1)
	  lwz       r3, 0x58(r30)
	  lwz       r0, 0x5C(r30)
	  stw       r3, 0x154(r1)
	  stw       r0, 0x158(r1)
	  lwz       r3, 0x60(r30)
	  lwz       r0, 0x64(r30)
	  stw       r3, 0x15C(r1)
	  stw       r0, 0x160(r1)
	  lwz       r3, 0x68(r30)
	  lwz       r0, 0x6C(r30)
	  stw       r3, 0x164(r1)
	  stw       r0, 0x168(r1)
	  lwz       r3, 0x70(r30)
	  lwz       r0, 0x74(r30)
	  stw       r3, 0x16C(r1)
	  stw       r0, 0x170(r1)
	  lwz       r3, 0x78(r30)
	  lwz       r0, 0x7C(r30)
	  stw       r3, 0x174(r1)
	  stw       r0, 0x178(r1)
	  lwz       r3, 0x80(r30)
	  lwz       r0, 0x84(r30)
	  stw       r3, 0x17C(r1)
	  stw       r0, 0x180(r1)
	  lwz       r3, 0x88(r30)
	  lwz       r0, 0x8C(r30)
	  stw       r3, 0x184(r1)
	  stw       r0, 0x188(r1)
	  lwz       r3, 0x90(r30)
	  lwz       r0, 0x94(r30)
	  stw       r3, 0x18C(r1)
	  stw       r0, 0x190(r1)
	  lwz       r3, 0x98(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r3, 0x194(r1)
	  stw       r0, 0x198(r1)
	  lwz       r3, 0xA0(r30)
	  lwz       r0, 0xA4(r30)
	  stw       r3, 0x19C(r1)
	  stw       r0, 0x1A0(r1)
	  lwz       r3, 0xA8(r30)
	  lwz       r0, 0xAC(r30)
	  stw       r3, 0x1A4(r1)
	  stw       r0, 0x1A8(r1)
	  lwz       r6, 0xB0(r30)
	  mr        r3, r27
	  lwz       r0, 0xB4(r30)
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  stw       r6, 0x1AC(r1)
	  mr        r6, r30
	  stw       r0, 0x1B0(r1)
	  lwz       r0, 0xB8(r30)
	  stw       r0, 0x1B4(r1)
	  lwz       r7, 0xBC(r30)
	  lwz       r0, 0xC0(r30)
	  stw       r7, 0x1B8(r1)
	  stw       r0, 0x1BC(r1)
	  lwz       r0, 0xC4(r30)
	  stw       r0, 0x1C0(r1)
	  lwz       r7, 0xC8(r30)
	  lwz       r0, 0xCC(r30)
	  stw       r7, 0x1C4(r1)
	  stw       r0, 0x1C8(r1)
	  lwz       r0, 0xD0(r30)
	  stw       r0, 0x1CC(r1)
	  lbz       r7, 0xEC(r27)
	  bl        -0x2274
	  addi      r3, r1, 0xFC
	  bl        -0x3680
	  stw       r31, 0xFC(r1)
	  b         .loc_0x2B0

	.loc_0x258:
	  addi      r3, r1, 0x18
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        -0x3450
	  addi      r3, r1, 0x18
	  bl        -0x3394
	  lbz       r7, 0xEC(r27)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r6, r1, 0x18
	  bl        -0x22BC
	  addi      r3, r1, 0x18
	  bl        -0x36C8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x624
	  lis       r3, 0x802E
	  stw       r0, 0x18(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x18(r1)

	.loc_0x2B0:
	  li        r3, 0
	  bl        0x5D5A0
	  li        r3, 0x1
	  bl        0x607D4
	  li        r3, 0
	  li        r4, 0x4
	  bl        0x5FE00
	  li        r3, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x60614
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x5ED50
	  li        r3, 0xD
	  li        r4, 0
	  bl        0x5C224
	  li        r3, 0
	  bl        0x5DC64
	  lmw       r27, 0x1D4(r1)
	  lwz       r0, 0x1EC(r1)
	  addi      r1, r1, 0x1E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B31FC
 * Size:	000030
 */
P2DPane* P2DScreen::search(u32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x1C
	  li        r3, 0
	  b         .loc_0x20

	.loc_0x1C:
	  bl        -0x1E84

	.loc_0x20:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B322C
 * Size:	000020
 */
void P2DScreen::loadResource()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1BA4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B324C
 * Size:	000028
 */
void P2DScreen::makeResName(const char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x44(r3)
	  bl        0x3F1C4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
