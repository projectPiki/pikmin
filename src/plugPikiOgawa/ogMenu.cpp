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
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void zen::ogDrawScrMenu::setScreen(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80191294
 * Size:	0000C0
 */
zen::ogDrawScrMenu::ogDrawScrMenu()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  li        r3, 0xF8
	  bl        -0x14A2AC
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x80
	  addi      r3, r1, 0xC
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x22354
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0xC
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1F6D8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stb       r0, 0xEC(r31)
	  stw       r0, 0xF0(r31)
	  stw       r0, 0xF4(r31)

	.loc_0x80:
	  stw       r31, 0x0(r30)
	  li        r0, 0
	  addi      r3, r30, 0
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0xC(r30)
	  stfs      f0, 0x10(r30)
	  stfs      f0, 0x14(r30)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r30)
	  stw       r0, 0x18(r30)
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
 * Address:	........
 * Size:	000034
 */
void zen::ChkAngle(f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void zen::ogDrawScrMenu::calcAngleSpeed(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80191354
 * Size:	000350
 */
void zen::ogDrawScrMenu::update(Controller*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r5,0,24,31
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0xC0
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E74(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x50
	  lfs       f0, -0x4E80(r2)
	  fadds     f1, f1, f0

	.loc_0x50:
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x64
	  fsubs     f1, f1, f0

	.loc_0x64:
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r30)
	  lfs       f2, 0x10(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E7C(r2)
	  fsubs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x90
	  lfs       f0, -0x4E80(r2)
	  fadds     f2, f2, f0

	.loc_0x90:
	  lfs       f0, -0x4E78(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xA4
	  lfs       f0, -0x4E80(r2)
	  fsubs     f2, f2, f0

	.loc_0xA4:
	  lfs       f0, -0x4E70(r2)
	  li        r3, 0x118
	  lfs       f1, 0x14(r30)
	  fdivs     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  bl        -0xEC09C

	.loc_0xC0:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x160
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E74(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xF0
	  lfs       f0, -0x4E80(r2)
	  fadds     f1, f1, f0

	.loc_0xF0:
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x104
	  fsubs     f1, f1, f0

	.loc_0x104:
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r30)
	  lfs       f2, 0x10(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E7C(r2)
	  fsubs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x130
	  lfs       f0, -0x4E80(r2)
	  fadds     f2, f2, f0

	.loc_0x130:
	  lfs       f0, -0x4E78(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x144
	  lfs       f0, -0x4E80(r2)
	  fsubs     f2, f2, f0

	.loc_0x144:
	  lfs       f0, -0x4E70(r2)
	  li        r3, 0x118
	  lfs       f1, 0x14(r30)
	  fdivs     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  bl        -0xEC13C

	.loc_0x160:
	  lfs       f2, 0x10(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E7C(r2)
	  fsubs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x180
	  lfs       f0, -0x4E80(r2)
	  fadds     f2, f2, f0

	.loc_0x180:
	  lfs       f0, -0x4E78(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x194
	  lfs       f0, -0x4E80(r2)
	  fsubs     f2, f2, f0

	.loc_0x194:
	  lfs       f0, -0x4E6C(r2)
	  lfs       f1, 0x14(r30)
	  fdivs     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f1, 0x14(r30)
	  lfs       f0, -0x4E68(r2)
	  fmuls     f0, f0, f1
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f0, 0x14(r30)
	  lfs       f2, -0x4E64(r2)
	  stfs      f0, 0x3C(r1)
	  lwz       r0, 0x3C(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x3C(r1)
	  lfs       f0, 0x3C(r1)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x218
	  lfs       f1, 0xC(r30)
	  lfs       f0, 0x10(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lwz       r0, 0x38(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x218
	  lfs       f0, 0x10(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r30)

	.loc_0x218:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x4E60(r2)
	  lfs       f1, 0x28C(r3)
	  lfs       f2, 0x14(r30)
	  fdivs     f0, f1, f0
	  lfs       f1, 0xC(r30)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E88(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x254
	  lfs       f0, -0x4E80(r2)
	  fadds     f1, f1, f0

	.loc_0x254:
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x268
	  fsubs     f1, f1, f0

	.loc_0x268:
	  stfs      f1, 0xC(r30)
	  lfs       f1, 0xC(r30)
	  bl        0x8A590
	  lfs       f0, 0xC(r30)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x8A714
	  lfs       f3, 0x1C(r30)
	  li        r5, 0
	  lwz       r3, 0x8(r30)
	  fmuls     f1, f3, f1
	  fneg      f0, f3
	  lwz       r12, 0x0(r3)
	  fctiwz    f2, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f2, 0x48(r1)
	  fadds     f1, f3, f0
	  lwz       r4, 0x4C(r1)
	  blrl
	  lfs       f0, 0xC(r30)
	  li        r4, 0x140
	  lwz       r3, 0x8(r30)
	  li        r0, 0xF0
	  fneg      f1, f0
	  sth       r4, 0xB8(r3)
	  li        r4, 0x79
	  sth       r0, 0xBA(r3)
	  bl        -0xAE24
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E5C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x314
	  lfs       f0, -0x4E58(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x314
	  lwz       r3, 0x8(r30)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x328

	.loc_0x314:
	  lwz       r3, 0x8(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x328:
	  lwz       r3, 0x0(r30)
	  bl        0x214D0
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801916A4
 * Size:	000040
 */
void P2DPane::move(int, int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  fmr       f31, f1
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x18
	  bl        0x22060
	  stfs      f31, 0x14(r31)
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogDrawScrMenu::draw(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801916E4
 * Size:	000278
 */
zen::ogDrawScrController::ogDrawScrController()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r24, 0x18(r1)
	  addi      r31, r3, 0
	  addi      r28, r4, 0x5E68
	  li        r3, 0xF8
	  bl        -0x14A700
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x88
	  addi      r24, r29, 0
	  addi      r3, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x21EFC
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x10
	  addi      r3, r24, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1F280
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r29)
	  li        r0, 0
	  stb       r0, 0xEC(r29)
	  stw       r0, 0xF0(r29)
	  stw       r0, 0xF4(r29)

	.loc_0x88:
	  stw       r29, 0x0(r31)
	  li        r29, 0
	  addi      r4, r28, 0x12C
	  lfs       f0, -0x4E88(r2)
	  li        r5, 0x1
	  li        r6, 0x1
	  stfs      f0, 0xC(r31)
	  li        r7, 0x1
	  stfs      f0, 0x10(r31)
	  stfs      f0, 0x14(r31)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r31)
	  stw       r29, 0x18(r31)
	  lwz       r3, 0x0(r31)
	  bl        0x2145C
	  lwz       r3, 0x0(r31)
	  lis       r4, 0x726F
	  addi      r4, r4, 0x6F74
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r31)
	  li        r4, 0x7374
	  li        r5, 0
	  lwz       r25, 0x0(r31)
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  addi      r3, r25, 0
	  lwz       r12, 0x0(r25)
	  lis       r4, 0x7374
	  addi      r4, r4, 0x5F63
	  lwz       r12, 0x34(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r4, r30
	  bl        -0x12D80
	  li        r0, 0xFF
	  stb       r0, 0xC4(r31)
	  lis       r4, 0x3364
	  addi      r3, r25, 0
	  stb       r0, 0xC5(r31)
	  addi      r4, r4, 0x5F77
	  li        r5, 0x1
	  stb       r0, 0xC6(r31)
	  stb       r0, 0xC7(r31)
	  stb       r29, 0xC8(r31)
	  stb       r29, 0xC9(r31)
	  stb       r29, 0xCA(r31)
	  stb       r29, 0xCB(r31)
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  li        r24, 0
	  stw       r3, 0xB4(r31)
	  rlwinm    r0,r24,2,0,29
	  add       r28, r28, r0
	  addi      r29, r31, 0
	  addi      r28, r28, 0x9C

	.loc_0x190:
	  mr        r3, r25
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x0(r25)
	  addi      r30, r28, 0x24
	  addi      r27, r30, 0x24
	  lwz       r12, 0x34(r12)
	  addi      r26, r27, 0x24
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r29)
	  addi      r3, r25, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r25)
	  lwz       r4, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r29)
	  addi      r3, r25, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r25)
	  lwz       r4, 0x0(r27)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x6C(r29)
	  addi      r3, r25, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r25)
	  lwz       r4, 0x0(r26)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x90(r29)
	  lwz       r3, 0x6C(r29)
	  lwz       r4, 0x24(r29)
	  bl        -0x12E74
	  lwz       r3, 0x6C(r29)
	  lwz       r4, 0x48(r29)
	  bl        -0x12E80
	  addi      r24, r24, 0x1
	  cmpwi     r24, 0x9
	  addi      r28, r28, 0x4
	  addi      r29, r29, 0x4
	  blt+      .loc_0x190
	  li        r0, 0
	  sth       r0, 0xB8(r31)
	  li        r0, 0x1
	  addi      r3, r31, 0
	  lfs       f0, -0x4E50(r2)
	  stfs      f0, 0xBC(r31)
	  stb       r0, 0xD0(r31)
	  lwz       r0, 0x3C(r1)
	  lmw       r24, 0x18(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void zen::ogDrawScrController::setWinColor()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void zen::ogDrawScrController::setOriginalColor()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::ogDrawScrController::setHantenColor()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019195C
 * Size:	00041C
 */
void zen::ogDrawScrController::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  mr        r31, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0xBC(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r3)
	  lfs       f0, 0xBC(r3)
	  lfs       f2, -0x4E88(r2)
	  fcmpo     cr0, f0, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x1B8
	  lfs       f0, -0x4E50(r2)
	  addi      r3, r1, 0xBC
	  stfs      f0, 0xBC(r31)
	  lha       r0, 0xB8(r31)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r31, r0
	  lwz       r4, 0x6C(r4)
	  addi      r4, r4, 0xF4
	  bl        -0x5FE8
	  lbz       r4, 0xBC(r1)
	  addi      r3, r1, 0xC0
	  lbz       r0, 0xBD(r1)
	  stb       r4, 0xB4(r1)
	  lbz       r4, 0xBE(r1)
	  stb       r0, 0xB5(r1)
	  lbz       r0, 0xBF(r1)
	  stb       r4, 0xB6(r1)
	  stb       r0, 0xB7(r1)
	  lha       r0, 0xB8(r31)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r31, r0
	  lwz       r4, 0x6C(r4)
	  addi      r4, r4, 0xF8
	  bl        -0x6024
	  lbz       r3, 0xC0(r1)
	  li        r4, 0
	  lbz       r0, 0xC1(r1)
	  stb       r3, 0xB8(r1)
	  lbz       r3, 0xC2(r1)
	  stb       r0, 0xB9(r1)
	  lbz       r0, 0xC3(r1)
	  stb       r3, 0xBA(r1)
	  stb       r0, 0xBB(r1)
	  stb       r4, 0xBB(r1)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0xB4(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x24(r3)
	  stw       r0, 0x108(r3)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0xB8(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x24(r3)
	  stw       r0, 0x10C(r3)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0xB4(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x48(r3)
	  stw       r0, 0x108(r3)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0xB8(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x48(r3)
	  stw       r0, 0x10C(r3)
	  stb       r4, 0xD0(r31)
	  lha       r3, 0xB8(r31)
	  addi      r0, r3, 0x1
	  sth       r0, 0xB8(r31)
	  lha       r0, 0xB8(r31)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x144
	  sth       r4, 0xB8(r31)

	.loc_0x144:
	  lha       r4, 0xB8(r31)
	  li        r0, 0x1
	  lwz       r3, 0xC4(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x24(r4)
	  stw       r3, 0x108(r4)
	  lha       r4, 0xB8(r31)
	  lwz       r3, 0xC8(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x24(r4)
	  stw       r3, 0x10C(r4)
	  lha       r4, 0xB8(r31)
	  lwz       r3, 0xC4(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x48(r4)
	  stw       r3, 0x108(r4)
	  lha       r4, 0xB8(r31)
	  lwz       r3, 0xC8(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x48(r4)
	  stw       r3, 0x10C(r4)
	  stb       r0, 0xD0(r31)
	  lfs       f0, -0x4E48(r2)
	  stfs      f0, 0xC0(r31)
	  b         .loc_0x33C

	.loc_0x1B8:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xC0(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC0(r31)
	  lfs       f0, 0xC0(r31)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x33C
	  lfs       f0, -0x4E48(r2)
	  stfs      f0, 0xC0(r31)
	  lbz       r0, 0xD0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D4
	  lha       r0, 0xB8(r31)
	  addi      r3, r1, 0x88
	  rlwinm    r0,r0,2,0,29
	  add       r4, r31, r0
	  lwz       r4, 0x6C(r4)
	  addi      r4, r4, 0xF4
	  bl        -0x6190
	  lbz       r4, 0x88(r1)
	  addi      r3, r1, 0x8C
	  lbz       r0, 0x89(r1)
	  stb       r4, 0x80(r1)
	  lbz       r4, 0x8A(r1)
	  stb       r0, 0x81(r1)
	  lbz       r0, 0x8B(r1)
	  stb       r4, 0x82(r1)
	  stb       r0, 0x83(r1)
	  lha       r0, 0xB8(r31)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r31, r0
	  lwz       r4, 0x6C(r4)
	  addi      r4, r4, 0xF8
	  bl        -0x61CC
	  lbz       r3, 0x8C(r1)
	  li        r4, 0
	  lbz       r0, 0x8D(r1)
	  stb       r3, 0x84(r1)
	  lbz       r3, 0x8E(r1)
	  stb       r0, 0x85(r1)
	  lbz       r0, 0x8F(r1)
	  stb       r3, 0x86(r1)
	  stb       r0, 0x87(r1)
	  stb       r4, 0x87(r1)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0x80(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x24(r3)
	  stw       r0, 0x108(r3)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0x84(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x24(r3)
	  stw       r0, 0x10C(r3)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0x80(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x48(r3)
	  stw       r0, 0x108(r3)
	  lha       r3, 0xB8(r31)
	  lwz       r0, 0x84(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r31, r3
	  lwz       r3, 0x48(r3)
	  stw       r0, 0x10C(r3)
	  stb       r4, 0xD0(r31)
	  b         .loc_0x33C

	.loc_0x2D4:
	  lha       r4, 0xB8(r31)
	  li        r0, 0x1
	  lwz       r3, 0xC4(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x24(r4)
	  stw       r3, 0x108(r4)
	  lha       r4, 0xB8(r31)
	  lwz       r3, 0xC8(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x24(r4)
	  stw       r3, 0x10C(r4)
	  lha       r4, 0xB8(r31)
	  lwz       r3, 0xC4(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x48(r4)
	  stw       r3, 0x108(r4)
	  lha       r4, 0xB8(r31)
	  lwz       r3, 0xC8(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r31, r4
	  lwz       r4, 0x48(r4)
	  stw       r3, 0x10C(r4)
	  stb       r0, 0xD0(r31)

	.loc_0x33C:
	  lwz       r4, 0xB4(r31)
	  addi      r3, r1, 0x68
	  addi      r4, r4, 0x108
	  bl        -0x62D4
	  lbz       r3, 0x68(r1)
	  li        r4, 0x8
	  lbz       r0, 0x69(r1)
	  stb       r3, 0x64(r1)
	  lbz       r3, 0x6A(r1)
	  stb       r0, 0x65(r1)
	  lbz       r0, 0x6B(r1)
	  stb       r3, 0x66(r1)
	  stb       r0, 0x67(r1)
	  lwz       r3, 0x90(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0x98(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0x9C(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0xA0(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0xA8(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0xAC(r31)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  b         .loc_0x3FC

	.loc_0x3D4:
	  subfic    r0, r4, 0x9
	  cmpwi     r4, 0x9
	  mtctr     r0
	  bge-      .loc_0x408

	.loc_0x3E4:
	  lwz       r3, 0x90(r5)
	  addi      r5, r5, 0x4
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x108(r3)
	  bdnz+     .loc_0x3E4
	  b         .loc_0x408

	.loc_0x3FC:
	  rlwinm    r0,r4,2,0,29
	  add       r5, r31, r0
	  b         .loc_0x3D4

	.loc_0x408:
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80191D78
 * Size:	000554
 */
zen::ogDrawScrInfo::ogDrawScrInfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  addi      r30, r3, 0
	  li        r3, 0xF8
	  bl        -0x14AD8C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x80
	  addi      r27, r28, 0
	  addi      r3, r1, 0x18
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x21870
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x18
	  addi      r3, r27, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1EBF4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r28)
	  li        r0, 0
	  stb       r0, 0xEC(r28)
	  stw       r0, 0xF0(r28)
	  stw       r0, 0xF4(r28)

	.loc_0x80:
	  stw       r28, 0x0(r30)
	  lis       r3, 0x802D
	  li        r31, 0
	  lfs       f0, -0x4E88(r2)
	  addi      r4, r3, 0x5FAC
	  li        r5, 0x1
	  stfs      f0, 0xC(r30)
	  li        r6, 0x1
	  li        r7, 0x1
	  stfs      f0, 0x10(r30)
	  stfs      f0, 0x14(r30)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r30)
	  stw       r31, 0x18(r30)
	  lwz       r3, 0x0(r30)
	  bl        0x20DCC
	  lwz       r3, 0x0(r30)
	  lis       r28, 0x726F
	  addi      r4, r28, 0x6F74
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r30)
	  addi      r4, r28, 0x6F74
	  li        r5, 0x1
	  lwz       r27, 0x0(r30)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x3C(r30)
	  addi      r3, r27, 0
	  lis       r4, 0x6964
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6F75
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x40(r30)
	  addi      r3, r27, 0
	  lis       r4, 0x7A6F
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6F6D
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x44(r30)
	  lis       r29, 0x7270
	  addi      r3, r27, 0
	  stw       r31, 0x7C(r30)
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x7C
	  stw       r31, 0x80(r30)
	  li        r6, 0x64
	  stw       r31, 0x84(r30)
	  stw       r31, 0x88(r30)
	  stw       r31, 0x8C(r30)
	  stw       r31, 0x90(r30)
	  stw       r31, 0x94(r30)
	  stw       r31, 0x98(r30)
	  bl        -0x13618
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0x7C
	  li        r6, 0xA
	  bl        -0x1362C
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x7C
	  li        r6, 0x1
	  bl        -0x13640
	  lis       r29, 0x6270
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x80
	  li        r6, 0x64
	  bl        -0x13658
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0x80
	  li        r6, 0xA
	  bl        -0x1366C
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x80
	  li        r6, 0x1
	  bl        -0x13680
	  lis       r29, 0x7970
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x84
	  li        r6, 0x64
	  bl        -0x13698
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0x84
	  li        r6, 0xA
	  bl        -0x136AC
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x84
	  li        r6, 0x1
	  bl        -0x136C0
	  lis       r29, 0x7263
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x88
	  li        r6, 0x64
	  bl        -0x136D8
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0x88
	  li        r6, 0xA
	  bl        -0x136EC
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x88
	  li        r6, 0x1
	  bl        -0x13700
	  lis       r29, 0x6263
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x8C
	  li        r6, 0x64
	  bl        -0x13718
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0x8C
	  li        r6, 0xA
	  bl        -0x1372C
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x8C
	  li        r6, 0x1
	  bl        -0x13740
	  lis       r29, 0x7963
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x90
	  li        r6, 0x64
	  bl        -0x13758
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0x90
	  li        r6, 0xA
	  bl        -0x1376C
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x90
	  li        r6, 0x1
	  bl        -0x13780
	  lis       r29, 0x7274
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0x98
	  li        r6, 0xA
	  bl        -0x13798
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0x98
	  li        r6, 0x1
	  bl        -0x137AC
	  addi      r3, r27, 0
	  addi      r4, r28, 0x5F6C
	  addi      r5, r30, 0x94
	  li        r6, 0xA
	  bl        -0x137C0
	  addi      r3, r27, 0
	  addi      r4, r28, 0x5F72
	  addi      r5, r30, 0x94
	  li        r6, 0x1
	  bl        -0x137D4
	  lis       r29, 0x6670
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r30, 0xA0
	  li        r6, 0x64
	  bl        -0x137EC
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F63
	  addi      r5, r30, 0xA0
	  li        r6, 0xA
	  bl        -0x13800
	  addi      r3, r27, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r30, 0xA0
	  li        r6, 0x1
	  bl        -0x13814
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r29, 0x705F
	  addi      r4, r29, 0x7270
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x64(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x7263
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x68(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x6270
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x6C(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x6263
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x70(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x7970
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x7963
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x78(r30)
	  addi      r3, r27, 0
	  lis       r29, 0x7469
	  lwz       r12, 0x0(r27)
	  addi      r4, r29, 0x3030
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x3031
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x3032
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x30(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x3033
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r30)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x3034
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x38(r30)
	  mr        r3, r30
	  lwz       r4, 0x28(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x2C(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x30(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x34(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x38(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r0, 0x44(r1)
	  lmw       r27, 0x2C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801922CC
 * Size:	000300
 */
void zen::ogDrawScrInfo::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r10, 0x803D
	  stw       r0, 0x4(r1)
	  lis       r6, 0x803D
	  lis       r7, 0x803D
	  stwu      r1, -0x90(r1)
	  lis       r8, 0x803D
	  lis       r4, 0x803D
	  stw       r31, 0x8C(r1)
	  addi      r12, r10, 0x1DF0
	  lis       r9, 0x803D
	  stw       r30, 0x88(r1)
	  addi      r10, r9, 0x1EA0
	  addi      r6, r6, 0x1E88
	  stw       r29, 0x84(r1)
	  addi      r29, r3, 0
	  addi      r7, r7, 0x1E7C
	  lwzu      r0, 0x1E70(r4)
	  addi      r8, r8, 0x1E94
	  stw       r0, 0x80(r3)
	  lwz       r0, 0x4(r4)
	  stw       r0, 0x7C(r29)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x84(r29)
	  lwz       r11, 0x8(r12)
	  lwz       r0, 0x4(r12)
	  lwz       r9, 0x0(r12)
	  add       r0, r0, r11
	  add       r0, r9, r0
	  stw       r0, 0x8C(r29)
	  lwz       r11, 0x14(r12)
	  lwz       r0, 0x10(r12)
	  lwz       r9, 0xC(r12)
	  add       r0, r0, r11
	  add       r0, r9, r0
	  stw       r0, 0x88(r29)
	  lwz       r11, 0x20(r12)
	  lwz       r0, 0x1C(r12)
	  lwz       r9, 0x18(r12)
	  add       r0, r0, r11
	  add       r0, r9, r0
	  stw       r0, 0x90(r29)
	  lwz       r9, 0x8(r10)
	  lwz       r0, 0x4(r10)
	  lwz       r11, 0x8(r4)
	  lwz       r5, 0x4(r4)
	  add       r0, r0, r9
	  lwz       r3, 0x0(r10)
	  add       r5, r5, r11
	  lwz       r4, 0x0(r4)
	  add       r0, r3, r0
	  add       r0, r0, r5
	  add       r0, r4, r0
	  stw       r0, 0x9C(r29)
	  lwz       r3, 0x8(r6)
	  lwz       r0, 0x4(r6)
	  lwz       r5, 0x8(r7)
	  lwz       r4, 0x4(r7)
	  add       r0, r0, r3
	  lwz       r3, 0x0(r6)
	  add       r4, r4, r5
	  lwz       r6, 0x8(r8)
	  add       r0, r3, r0
	  lwz       r5, 0x4(r8)
	  add       r0, r0, r4
	  lwz       r3, 0x0(r7)
	  add       r4, r5, r6
	  lwz       r5, 0x0(r8)
	  add       r0, r3, r0
	  add       r0, r0, r4
	  add       r0, r5, r0
	  stw       r0, 0xA0(r29)
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x144
	  bl        -0x111788
	  stw       r3, 0x94(r29)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x11179C
	  stw       r3, 0x98(r29)
	  b         .loc_0x154

	.loc_0x144:
	  li        r0, 0x1
	  stw       r0, 0x94(r29)
	  li        r0, 0x4D
	  stw       r0, 0x98(r29)

	.loc_0x154:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  li        r31, 0x1
	  li        r5, 0
	  lhz       r0, 0x26(r3)
	  li        r4, 0
	  rlwinm    r0,r0,2,0,29
	  add       r3, r29, r0
	  lwz       r3, 0x28(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x64(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x68(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x6C(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x70(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x74(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x78(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x111EEC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x218
	  lwz       r3, 0x6C(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x70(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x218:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1
	  bl        -0x111F20
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x250
	  lwz       r3, 0x64(r29)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x68(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x250:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2
	  bl        -0x111F58
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x288
	  lwz       r3, 0x74(r29)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x78(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x288:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x2C0
	  lwz       r3, 0x40(r29)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x44(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x2E4

	.loc_0x2C0:
	  lwz       r3, 0x40(r29)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x44(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2E4:
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
 * Address:	........
 * Size:	000004
 */
void zen::ogDrawScrInfo::update(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
zen::ogDrawScrInfo2::ogDrawScrInfo2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::ogDrawScrInfo2::start()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::ogDrawScrInfo2::update(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void zen::ogDrawScrInfo2::drawHougaku(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801925CC
 * Size:	0003FC
 */
zen::ogScrMenuMgr::ogScrMenuMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stmw      r27, 0x64(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x802D
	  addi      r31, r3, 0x5E68
	  li        r3, 0x20
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x68(r30)
	  stfs      f0, 0x64(r30)
	  stfs      f0, 0x60(r30)
	  bl        -0x14B5F8
	  mr.       r27, r3
	  beq-      .loc_0x14C
	  li        r3, 0xF8
	  bl        -0x14B608
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xA4
	  addi      r3, r1, 0x40
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x20FF8
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x40
	  addi      r3, r28, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1E37C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r28)
	  li        r0, 0
	  stb       r0, 0xEC(r28)
	  stw       r0, 0xF0(r28)
	  stw       r0, 0xF4(r28)

	.loc_0xA4:
	  stw       r28, 0x0(r27)
	  addi      r4, r31, 0x174
	  li        r5, 0
	  lwz       r3, 0x0(r27)
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x20578
	  lfs       f0, -0x4E88(r2)
	  lis       r29, 0x7961
	  li        r28, 0
	  stfs      f0, 0x10(r27)
	  addi      r4, r29, 0x5F6C
	  li        r5, 0x1
	  lfs       f1, -0x4E50(r2)
	  stfs      f1, 0x14(r27)
	  fmr       f0, f1
	  stfs      f1, 0x18(r27)
	  stfs      f0, 0x1C(r27)
	  stb       r28, 0x4(r27)
	  stb       r28, 0x5(r27)
	  lwz       r3, 0x0(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r27)
	  addi      r4, r29, 0x5F72
	  li        r5, 0x1
	  lwz       r3, 0x0(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r27)
	  lwz       r3, 0x8(r27)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xC(r27)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x14C:
	  stw       r27, 0x10(r30)
	  li        r5, 0
	  li        r3, 0x45C
	  lwz       r4, 0x10(r30)
	  stb       r5, 0x4(r4)
	  lwz       r4, 0x8(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x10(r30)
	  stb       r5, 0x5(r4)
	  lwz       r4, 0xC(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  bl        -0x14B750
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x19C
	  bl        -0xD6C4

	.loc_0x19C:
	  stw       r27, 0x14(r30)
	  li        r3, 0xA4
	  bl        -0x14B76C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1B8
	  bl        -0xA08

	.loc_0x1B8:
	  stw       r27, 0x48(r30)
	  li        r3, 0xD4
	  bl        -0x14B788
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1D4
	  bl        -0x10B8

	.loc_0x1D4:
	  stw       r27, 0x4C(r30)
	  li        r3, 0x38
	  bl        -0x14B7A4
	  mr.       r27, r3
	  beq-      .loc_0x2A0
	  mr        r3, r27
	  bl        -0x1524
	  lfs       f0, -0x4E88(r2)
	  addi      r4, r31, 0x15C
	  li        r5, 0x1
	  stfs      f0, 0x30(r27)
	  li        r6, 0x1
	  li        r7, 0x1
	  stfs      f0, 0x2C(r27)
	  stfs      f0, 0x28(r27)
	  lwz       r3, 0x0(r27)
	  bl        0x20420
	  lwz       r3, 0x0(r27)
	  lis       r4, 0x726F
	  addi      r4, r4, 0x6F74
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r27)
	  lis       r3, 0x6D61
	  addi      r4, r3, 0x7073
	  lwz       r28, 0x0(r27)
	  li        r5, 0x1
	  lfs       f0, 0xDC8(r13)
	  mr        r3, r28
	  stfs      f0, 0x28(r27)
	  lfs       f0, 0xDCC(r13)
	  stfs      f0, 0x2C(r27)
	  lfs       f0, 0xDD0(r13)
	  stfs      f0, 0x30(r27)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r27)
	  addi      r3, r28, 0
	  lis       r4, 0x7961
	  lwz       r12, 0x0(r28)
	  addi      r4, r4, 0x6A69
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r27)

	.loc_0x2A0:
	  stw       r27, 0x50(r30)
	  li        r3, 0xF8
	  lwz       r0, 0x48(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x4C(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x50(r30)
	  stw       r0, 0x20(r30)
	  lwz       r4, 0x18(r30)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x30(r30)
	  lwz       r4, 0x1C(r30)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x34(r30)
	  lwz       r4, 0x20(r30)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x38(r30)
	  bl        -0x14B8AC
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x348
	  addi      r3, r1, 0x50
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x20D54
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x50
	  addi      r3, r27, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1E0D8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r27)
	  li        r0, 0
	  stb       r0, 0xEC(r27)
	  stw       r0, 0xF0(r27)
	  stw       r0, 0xF4(r27)

	.loc_0x348:
	  stw       r27, 0x8(r30)
	  addi      r4, r31, 0x18C
	  li        r5, 0
	  lwz       r3, 0x8(r30)
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x202D4
	  lwz       r3, 0x8(r30)
	  lis       r4, 0x626C
	  addi      r4, r4, 0x636B
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r30)
	  lis       r3, 0x7365
	  addi      r4, r3, 0x5F63
	  lwz       r3, 0x48(r30)
	  li        r5, 0x1
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lbz       r3, 0xF7(r3)
	  li        r5, 0
	  li        r0, -0x1
	  stb       r3, 0x5D(r30)
	  mr        r3, r30
	  lwz       r4, 0xC(r30)
	  stb       r5, 0xF0(r4)
	  sth       r5, 0x4(r30)
	  lfs       f0, 0xDD4(r13)
	  stfs      f0, 0x60(r30)
	  lfs       f0, 0xDD8(r13)
	  stfs      f0, 0x64(r30)
	  lfs       f0, 0xDDC(r13)
	  stfs      f0, 0x68(r30)
	  stw       r0, 0x0(r30)
	  lwz       r0, 0x7C(r1)
	  lmw       r27, 0x64(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801929C8
 * Size:	00026C
 */
void zen::ogScrMenuMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stmw      r27, 0x44(r1)
	  li        r28, 0x1
	  addi      r31, r3, 0
	  stw       r28, 0x0(r3)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x58(r3)
	  sth       r28, 0x4(r3)
	  lwz       r3, 0x10(r3)
	  stfs      f0, 0x10(r3)
	  lfs       f0, -0x4E50(r2)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  stb       r4, 0x4(r3)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0x10(r31)
	  stb       r4, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r31)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x48(r31)
	  bl        -0x780
	  lwz       r30, 0x18(r31)
	  sth       r28, 0x20(r30)
	  lfs       f1, -0x4E88(r2)
	  stfs      f1, 0xC(r30)
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r30)
	  stfs      f1, 0x14(r30)
	  lfs       f1, 0xC(r30)
	  bl        0x890E0
	  lfs       f0, 0xC(r30)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x89264
	  lfs       f2, 0x1C(r30)
	  li        r5, 0
	  lwz       r3, 0x8(r30)
	  fmuls     f1, f2, f1
	  fneg      f0, f2
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f1, 0x38(r1)
	  fadds     f1, f2, f0
	  lwz       r4, 0x3C(r1)
	  blrl
	  lfs       f0, 0xC(r30)
	  li        r29, 0x140
	  lwz       r3, 0x8(r30)
	  li        r30, 0xF0
	  fneg      f1, f0
	  sth       r29, 0xB8(r3)
	  li        r4, 0x79
	  sth       r30, 0xBA(r3)
	  bl        -0xC2D4
	  lwz       r27, 0x1C(r31)
	  li        r0, 0x2
	  sth       r0, 0x20(r27)
	  lfs       f0, -0x4E74(r2)
	  stfs      f0, 0xC(r27)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r27)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r27)
	  lfs       f1, 0xC(r27)
	  bl        0x89044
	  lfs       f0, 0xC(r27)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x891C8
	  lfs       f2, 0x1C(r27)
	  li        r5, 0
	  lwz       r3, 0x8(r27)
	  fmuls     f1, f2, f1
	  fneg      f0, f2
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f1, 0x30(r1)
	  fadds     f1, f2, f0
	  lwz       r4, 0x34(r1)
	  blrl
	  lfs       f0, 0xC(r27)
	  li        r4, 0x79
	  lwz       r3, 0x8(r27)
	  fneg      f1, f0
	  sth       r29, 0xB8(r3)
	  sth       r30, 0xBA(r3)
	  bl        -0xC368
	  lwz       r27, 0x20(r31)
	  sth       r28, 0x20(r27)
	  lfs       f1, -0x4E88(r2)
	  stfs      f1, 0xC(r27)
	  stfs      f1, 0x10(r27)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r27)
	  stfs      f1, 0x14(r27)
	  lfs       f1, 0xC(r27)
	  bl        0x88FB8
	  lfs       f0, 0xC(r27)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x8913C
	  lfs       f2, 0x1C(r27)
	  li        r5, 0
	  lwz       r3, 0x8(r27)
	  fmuls     f1, f2, f1
	  fneg      f0, f2
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f1, 0x28(r1)
	  fadds     f1, f2, f0
	  lwz       r4, 0x2C(r1)
	  blrl
	  lfs       f0, 0xC(r27)
	  li        r4, 0x79
	  lwz       r3, 0x8(r27)
	  fneg      f1, f0
	  sth       r29, 0xB8(r3)
	  sth       r30, 0xBA(r3)
	  bl        -0xC3F4
	  lwz       r4, 0x50(r31)
	  lwz       r3, 0x14(r31)
	  lwz       r4, 0x24(r4)
	  bl        -0xC3BC
	  li        r3, 0x116
	  bl        -0xED8A4
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrMenuMgr::updateInfo(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void zen::ogScrMenuMgr::updateCont(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80192C34
 * Size:	000598
 */
void zen::ogScrMenuMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stw       r31, 0x114(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x110(r1)
	  mr        r30, r3
	  stw       r29, 0x10C(r1)
	  stw       r28, 0x108(r1)
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x38
	  b         .loc_0x574

	.loc_0x38:
	  li        r28, 0
	  rlwinm    r0,r28,2,0,29
	  add       r29, r30, r0

	.loc_0x44:
	  lwz       r3, 0x18(r29)
	  mr        r4, r31
	  lbz       r5, 0x54(r30)
	  lbz       r6, 0x55(r30)
	  bl        -0x1934
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  addi      r29, r29, 0x4
	  blt+      .loc_0x44
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1C8
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r30)
	  lfs       f1, 0x58(r30)
	  lfs       f0, -0x4E44(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE8
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x30(r30)
	  lfs       f0, -0x4E50(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x1C0

	.loc_0xE8:
	  fdivs     f2, f1, f0
	  lfs       f0, -0x4E40(r2)
	  lis       r4, 0x4330
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x100(r1)
	  lwz       r0, 0x104(r1)
	  stb       r0, 0x5C(r30)
	  lwz       r3, 0x30(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lfd       f1, -0x4E28(r2)
	  stw       r0, 0xFC(r1)
	  lwz       r3, 0xC(r30)
	  stw       r4, 0xF8(r1)
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xF0(r1)
	  lwz       r0, 0xF4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xEC(r1)
	  stw       r4, 0xE8(r1)
	  lfd       f0, 0xE8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xDC(r1)
	  stw       r4, 0xD8(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x1C0:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x574

	.loc_0x1C8:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x32C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r30)
	  lfs       f0, 0x58(r30)
	  lfs       f1, -0x4E44(r2)
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x244
	  li        r0, 0x3
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  lwz       r3, 0x30(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0xC(r30)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x324

	.loc_0x244:
	  fsubs     f2, f1, f0
	  lfs       f0, -0x4E40(r2)
	  lis       r4, 0x4330
	  fmuls     f0, f0, f2
	  fdivs     f2, f2, f1
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stb       r0, 0x5C(r30)
	  lwz       r3, 0x30(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lfd       f1, -0x4E28(r2)
	  stw       r0, 0xDC(r1)
	  lwz       r3, 0xC(r30)
	  stw       r4, 0xD8(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xEC(r1)
	  stw       r4, 0xE8(r1)
	  lfd       f0, 0xE8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xF0(r1)
	  lwz       r0, 0xF4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xFC(r1)
	  stw       r4, 0xF8(r1)
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x100(r1)
	  lwz       r0, 0x104(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x324:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x574

	.loc_0x32C:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x344
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x574

	.loc_0x344:
	  li        r0, 0
	  stb       r0, 0x54(r30)
	  stb       r0, 0x55(r30)
	  lwz       r0, 0x28(r31)
	  andi.     r0, r0, 0xA000
	  beq-      .loc_0x37C
	  lfs       f0, -0x4E88(r2)
	  li        r0, 0x2
	  li        r3, 0x117
	  stfs      f0, 0x58(r30)
	  stw       r0, 0x0(r30)
	  bl        -0xEDC30
	  lwz       r3, 0x14(r30)
	  bl        -0xB9C4

	.loc_0x37C:
	  lha       r3, 0x4(r30)
	  extsh.    r0, r3
	  beq-      .loc_0x470
	  cmpwi     r3, 0x1
	  bne-      .loc_0x404
	  lwz       r3, 0x10(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stb       r5, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r30)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r31)
	  rlwinm.   r0,r3,0,14,14
	  bne-      .loc_0x3F4
	  rlwinm.   r0,r3,0,13,13
	  beq-      .loc_0x3F4
	  lha       r3, 0x4(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x4(r30)
	  stb       r4, 0x55(r30)
	  lwz       r3, 0x14(r30)
	  bl        -0xBA3C

	.loc_0x3F4:
	  lwz       r3, 0x14(r30)
	  mr        r4, r31
	  bl        -0xC190
	  b         .loc_0x470

	.loc_0x404:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x470
	  lwz       r3, 0x10(r30)
	  li        r5, 0x1
	  li        r4, 0
	  stb       r5, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r30)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x468
	  lha       r3, 0x4(r30)
	  subi      r0, r3, 0x1
	  sth       r0, 0x4(r30)
	  stb       r5, 0x54(r30)
	  lwz       r3, 0x14(r30)
	  bl        -0xC71C

	.loc_0x468:
	  lwz       r3, 0x4C(r30)
	  bl        -0x1744

	.loc_0x470:
	  lwz       r31, 0x10(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x10(r31)
	  lfs       f31, 0x28C(r3)
	  fneg      f1, f0
	  bl        0x88C30
	  lfs       f0, -0x4E38(r2)
	  lfs       f2, -0x4E3C(r2)
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x10(r31)
	  fneg      f1, f0
	  bl        0x88C10
	  lfs       f0, -0x4E38(r2)
	  lfs       f2, -0x4E3C(r2)
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x10(r31)
	  fneg      f1, f0
	  bl        0x88A5C
	  lfs       f0, -0x4E30(r2)
	  li        r3, 0x30
	  lfs       f2, -0x4E34(r2)
	  li        r0, 0
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x1C(r31)
	  lwz       r4, 0x8(r31)
	  sth       r3, 0xB8(r4)
	  sth       r3, 0xBA(r4)
	  lwz       r4, 0xC(r31)
	  sth       r0, 0xB8(r4)
	  sth       r3, 0xBA(r4)
	  lfs       f1, 0x1C(r31)
	  lwz       r3, 0x8(r31)
	  lfs       f0, 0x14(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f1, 0xC4(r3)
	  lfs       f1, -0x4E50(r2)
	  stfs      f1, 0xC8(r3)
	  lfs       f2, 0x1C(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x18(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f1, 0xC8(r3)
	  lfs       f0, -0x4E60(r2)
	  lfs       f1, -0x4E2C(r2)
	  fdivs     f0, f31, f0
	  lfs       f2, 0x10(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x568
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r31)

	.loc_0x568:
	  lwz       r3, 0x8(r30)
	  bl        0x1F9B0
	  lwz       r3, 0x0(r30)

	.loc_0x574:
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lwz       r31, 0x114(r1)
	  lwz       r30, 0x110(r1)
	  lwz       r29, 0x10C(r1)
	  lwz       r28, 0x108(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801931CC
 * Size:	0003C8
 */
void zen::ogScrMenuMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x430(r1)
	  stmw      r27, 0x41C(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x2C
	  li        r3, 0
	  b         .loc_0x3B4

	.loc_0x2C:
	  lfs       f1, -0x4E54(r2)
	  addi      r3, r1, 0x334
	  lfs       f2, -0x4E50(r2)
	  li        r4, 0
	  lfs       f3, -0x4E4C(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CF78
	  addi      r3, r1, 0x334
	  bl        0x1D080
	  lfs       f2, -0x4E50(r2)
	  addi      r4, r1, 0x320
	  lwz       r0, -0x4E20(r2)
	  li        r3, 0
	  fmr       f4, f2
	  stw       r0, 0x320(r1)
	  lfs       f1, -0x4E88(r2)
	  lfs       f3, -0x4E1C(r2)
	  bl        0x80754
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x808F8
	  lwz       r3, 0x8(r29)
	  addi      r6, r1, 0x334
	  li        r4, 0
	  li        r5, 0
	  bl        0x1FC6C
	  lwz       r28, 0x18(r29)
	  addi      r3, r1, 0x23C
	  lfs       f1, -0x4E54(r2)
	  li        r4, 0
	  lfs       f2, -0x4E50(r2)
	  lfs       f3, -0x4E4C(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CF00
	  addi      r3, r1, 0x23C
	  bl        0x1D008
	  lwz       r3, 0x0(r28)
	  addi      r6, r1, 0x23C
	  li        r4, 0
	  li        r5, 0
	  bl        0x1FC28
	  lis       r3, 0x802E
	  lfs       f1, -0x4E54(r2)
	  addi      r28, r3, 0x698
	  lfs       f2, -0x4E50(r2)
	  lis       r3, 0x802E
	  stw       r28, 0x23C(r1)
	  addi      r31, r3, 0x5D4
	  lfs       f3, -0x4E4C(r2)
	  stw       r31, 0x23C(r1)
	  addi      r3, r1, 0x158
	  li        r4, 0
	  lwz       r27, 0x1C(r29)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CEA4
	  addi      r3, r1, 0x158
	  bl        0x1CFAC
	  lwz       r3, 0x0(r27)
	  addi      r6, r1, 0x158
	  li        r4, 0
	  li        r5, 0
	  bl        0x1FBCC
	  stw       r28, 0x158(r1)
	  stw       r31, 0x158(r1)
	  lha       r0, 0x4(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1CC
	  lwz       r3, 0x48(r29)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x10(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x180
	  lfs       f1, -0x4E88(r2)
	  lfs       f0, 0x14(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x180
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x180:
	  li        r0, 0

	.loc_0x184:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1CC
	  lfs       f0, 0x64(r29)
	  lfs       f1, -0x4E50(r2)
	  fmr       f2, f0
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x1B4
	  lfs       f0, -0x4E2C(r2)
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x1B4
	  fmr       f2, f1

	.loc_0x1B4:
	  lfs       f0, 0xDE0(r13)
	  stfs      f0, 0x60(r29)
	  stfs      f2, 0x64(r29)
	  lfs       f0, 0xDE4(r13)
	  stfs      f0, 0x68(r29)
	  b         .loc_0x1E4

	.loc_0x1CC:
	  lfs       f0, 0xDE8(r13)
	  stfs      f0, 0x60(r29)
	  lfs       f0, 0xDEC(r13)
	  stfs      f0, 0x64(r29)
	  lfs       f0, 0xDF0(r13)
	  stfs      f0, 0x68(r29)

	.loc_0x1E4:
	  lwz       r4, 0x50(r29)
	  lwz       r3, 0x14(r29)
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x3C(r3)
	  lwz       r3, 0x60(r29)
	  lwz       r0, 0x64(r29)
	  stw       r3, 0xC0(r5)
	  stw       r0, 0xC4(r5)
	  lwz       r0, 0x68(r29)
	  stw       r0, 0xC8(r5)
	  lha       r6, 0x1A(r4)
	  lha       r0, 0x1E(r4)
	  lha       r7, 0x18(r4)
	  sub       r3, r0, r6
	  lha       r0, 0x1C(r4)
	  srawi     r3, r3, 0x1
	  addze     r3, r3
	  sub       r0, r0, r7
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r7, r0
	  extsh     r0, r0
	  add       r3, r6, r3
	  sth       r0, 0xB8(r5)
	  extsh     r0, r3
	  sth       r0, 0xBA(r5)
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x398
	  lwz       r3, 0x14(r29)
	  mr        r4, r30
	  bl        -0xBE08
	  lwz       r31, 0x50(r29)
	  lwz       r4, 0x2E4(r30)
	  lwz       r5, 0x34(r31)
	  lfs       f0, 0x194(r4)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  fneg      f1, f0
	  lfs       f0, 0x19C(r4)
	  sub       r4, r0, r3
	  lha       r3, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  srawi     r28, r4, 0x1
	  fneg      f2, f0
	  addze     r28, r28
	  sub       r0, r0, r3
	  srawi     r27, r0, 0x1
	  addze     r27, r27
	  bl        0x88584
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  lhz       r0, 0x26(r3)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x2CC
	  lfs       f0, -0x4E78(r2)
	  fadds     f1, f1, f0

	.loc_0x2CC:
	  lwz       r3, 0x34(r31)
	  extsh     r0, r28
	  li        r4, 0x7A
	  sth       r0, 0xB8(r3)
	  extsh     r0, r27
	  sth       r0, 0xBA(r3)
	  bl        -0xCCA4
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x310
	  lwz       r3, 0x34(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x324

	.loc_0x310:
	  lwz       r3, 0x34(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x324:
	  lwz       r27, 0x20(r29)
	  addi      r3, r1, 0x64
	  lfs       f1, -0x4E54(r2)
	  li        r4, 0
	  lfs       f2, -0x4E50(r2)
	  lfs       f3, -0x4E4C(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CC7C
	  addi      r3, r1, 0x64
	  bl        0x1CD84
	  lwz       r3, 0x0(r27)
	  addi      r6, r1, 0x64
	  li        r4, 0
	  li        r5, 0
	  bl        0x1F9A4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x64(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x64(r1)
	  li        r4, 0
	  li        r5, 0
	  lwz       r3, 0x10(r29)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        0x1F974

	.loc_0x398:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x334(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x334(r1)
	  li        r3, 0x1

	.loc_0x3B4:
	  lmw       r27, 0x41C(r1)
	  lwz       r0, 0x434(r1)
	  addi      r1, r1, 0x430
	  mtlr      r0
	  blr
	*/
}
