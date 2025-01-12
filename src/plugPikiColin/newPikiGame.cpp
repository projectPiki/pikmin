#include "types.h"
#include "Controller.h"
#include "Section.h"
#include "ModeState.h"
#include "Interface.h"
#include "NewPikiGame.h"
#include "sysNew.h"
#include "Controller.h"

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
 * Address:	........
 * Size:	0000E4
 */
void showFrame(bool, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80056B00
 * Size:	000118
 */
void createMenuWindow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  stw       r28, 0x20(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  li        r4, 0x5
	  addi      r5, r3, 0x2A4
	  lwz       r3, 0x2A4(r3)
	  stw       r0, 0x0(r5)
	  neg       r5, r3
	  subic     r0, r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r0, r0, r5
	  rlwinm    r31,r0,0,24,31
	  lwz       r28, 0x194(r3)
	  bl        -0x17B04
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x17B58
	  lwz       r30, 0x0(r3)
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  li        r3, 0x6C
	  bl        -0xFB88
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xA0
	  bl        0x13BA30

	.loc_0xA0:
	  stw       r29, 0x2E84(r13)
	  lwz       r3, 0x2E84(r13)
	  bl        0x13BE20
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x17B94
	  stw       r30, 0x0(r3)
	  mr        r4, r28
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x17B5C
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x2A0(r3)
	  lwz       r3, 0x2DEC(r13)
	  stw       r31, 0x2A4(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x17568
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
 * Address:	........
 * Size:	000040
 */
void deleteMenuWindow()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80056C18
 * Size:	0001B0
 */
void createTutorialWindow(int, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r30, r3
	  mr        r29, r4
	  addi      r28, r5, 0
	  li        r4, 0
	  li        r5, 0
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  li        r5, 0
	  lwzu      r0, 0x2A4(r3)
	  cmpwi     r29, 0
	  stw       r5, 0x0(r3)
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r0, r0, r4
	  rlwinm    r31,r0,0,24,31
	  lwz       r27, 0x194(r3)
	  blt-      .loc_0x78
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x78
	  li        r5, 0x1

	.loc_0x78:
	  rlwinm.   r0,r5,0,24,31
	  stb       r5, 0x2E8C(r13)
	  beq-      .loc_0x94
	  addi      r3, r29, 0x1
	  rlwinm    r4,r28,0,24,31
	  bl        -0x3BB84
	  b         .loc_0x9C

	.loc_0x94:
	  mr        r3, r30
	  bl        -0x3BA50

	.loc_0x9C:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x17C54
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x17CA8
	  lwz       r29, 0x0(r3)
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  li        r3, 0x8
	  bl        -0xFCD8
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xD8
	  bl        0x12BEA8

	.loc_0xD8:
	  stw       r28, 0x2E88(r13)
	  mr        r4, r30
	  lwz       r3, 0x2E88(r13)
	  bl        0x12C004
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x17CE8
	  stw       r29, 0x0(r3)
	  mr        r4, r27
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x17CB0
	  lbz       r0, 0x2E81(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x15C
	  lbz       r0, 0x2E82(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x15C
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2973C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x140
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x161DEC

	.loc_0x140:
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x161F08
	  li        r0, 0
	  stb       r0, 0x2E82(r13)

	.loc_0x15C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  stw       r0, 0x340(r3)
	  li        r0, 0
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x2A0(r3)
	  lwz       r3, 0x2DEC(r13)
	  stw       r31, 0x2A4(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x17724
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80056DC8
 * Size:	0000BC
 */
void deleteTutorialWindow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2E8C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  bl        -0x3BBE0
	  b         .loc_0x24

	.loc_0x20:
	  bl        -0x3BAE8

	.loc_0x24:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  stw       r0, 0x340(r3)
	  lbz       r0, 0x2E8D(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lbz       r0, 0x2E81(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  lbz       r0, 0x2E82(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lwz       r3, 0x2F6C(r13)
	  bl        0x29650
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x7C
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x161C84

	.loc_0x7C:
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x161D6C
	  li        r0, 0x1
	  stb       r0, 0x2E82(r13)

	.loc_0x98:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  stw       r0, 0x338(r3)
	  stw       r0, 0x2E88(r13)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void handleTutorialWindow(u32&, Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80056E84
 * Size:	000118
 */
BaseGameSection::BaseGameSection()
    : Node("")
{
	_40         = 6;
	_20         = 0;
	_34         = 0;
	_38         = 0;
	mController = new Controller;
	_3C         = 0;
	_28         = 0.0f;
	_2C         = 1.0f;
	_30         = 0.5f;
}

/*
 * --INFO--
 * Address:	80056F9C
 * Size:	000244
 */
void BaseGameSection::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  addi      r5, r1, 0x4C
	  stw       r31, 0xBC(r1)
	  mr        r31, r4
	  stw       r30, 0xB8(r1)
	  mr        r30, r3
	  mr        r3, r31
	  stw       r29, 0xB4(r1)
	  lwz       r7, 0x310(r4)
	  lwz       r6, 0x30C(r4)
	  addi      r4, r1, 0x5C
	  stw       r0, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  stw       r6, 0x54(r1)
	  stw       r7, 0x58(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x28(r30)
	  lfs       f0, 0x2C(r30)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x9C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x30(r30)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x28(r30)
	  lfs       f0, 0x28(r30)
	  lfs       f1, 0x2C(r30)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0xCC
	  stfs      f1, 0x28(r30)
	  b         .loc_0xCC

	.loc_0x9C:
	  ble-      .loc_0xCC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x30(r30)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x28(r30)
	  lfs       f0, 0x28(r30)
	  lfs       f1, 0x2C(r30)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0xCC
	  stfs      f1, 0x28(r30)

	.loc_0xCC:
	  lfs       f2, 0x28(r30)
	  lfs       f1, -0x7A80(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x1A8
	  lfs       f0, -0x7A84(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xF0
	  fmr       f2, f0
	  b         .loc_0xFC

	.loc_0xF0:
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0xFC
	  fmr       f2, f1

	.loc_0xFC:
	  lfs       f0, -0x7A80(r2)
	  li        r29, 0
	  stb       r29, 0x48(r1)
	  addi      r4, r1, 0x48
	  fsubs     f0, f0, f2
	  lfs       f1, -0x7A7C(r2)
	  mr        r3, r31
	  stb       r29, 0x49(r1)
	  li        r5, 0x1
	  fmuls     f0, f1, f0
	  stb       r29, 0x4A(r1)
	  fctiwz    f31, f0
	  stfd      f31, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stb       r0, 0x4B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x44(r1)
	  addi      r4, r1, 0x44
	  addi      r3, r31, 0
	  stfd      f31, 0xA0(r1)
	  stb       r29, 0x45(r1)
	  lwz       r0, 0xA4(r1)
	  stb       r29, 0x46(r1)
	  stb       r0, 0x47(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x34
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r29, 0x34(r1)
	  stw       r29, 0x38(r1)
	  stw       r0, 0x3C(r1)
	  stw       r5, 0x40(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl

	.loc_0x1A8:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r6, r3, 0x310
	  lwz       r0, 0x310(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x210
	  addi      r5, r3, 0x314
	  lfs       f2, -0x7A84(r2)
	  lfs       f1, 0x314(r3)
	  fcmpo     cr0, f1, f2
	  ble-      .loc_0x210
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r5)
	  lfs       f1, 0x0(r5)
	  fcmpo     cr0, f1, f2
	  bge-      .loc_0x200
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stfs      f2, 0x0(r5)
	  b         .loc_0x210

	.loc_0x200:
	  lwz       r6, 0x0(r6)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x5BE0

	.loc_0x210:
	  lwz       r3, 0x34(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800571E0
 * Size:	000004
 */
void ModeState::postUpdate()
{
}

/*
 * --INFO--
 * Address:	800571E4
 * Size:	000128
 */
void IntroGameModeState::update(u32&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2E88(r13)
	  lwz       r4, 0x0(r31)
	  cmplwi    r3, 0
	  lwz       r4, 0x24(r4)
	  beq-      .loc_0x60
	  bl        0x12BA00
	  cmpwi     r3, 0x4
	  bne-      .loc_0x60
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  li        r4, 0x2
	  bl        0x20A18

	.loc_0x5C:
	  bl        -0x478

	.loc_0x60:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x110
	  lbz       r0, 0x2E82(r13)
	  li        r3, 0x1
	  stb       r3, 0x2E81(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC
	  lwz       r3, 0x2F6C(r13)
	  bl        0x29200
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB0
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A78(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x161834

	.loc_0xB0:
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A78(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x16191C
	  li        r0, 0x1
	  stb       r0, 0x2E82(r13)

	.loc_0xCC:
	  li        r3, 0x10
	  bl        -0x102B0
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r4, r4, 0x7E80
	  stw       r5, 0x0(r3)
	  li        r0, 0
	  stw       r4, 0x4(r3)
	  stb       r0, 0x8(r3)
	  lwz       r0, 0x24(r5)
	  stw       r0, 0xC(r3)
	  b         .loc_0x114

	.loc_0x110:
	  mr        r3, r31

	.loc_0x114:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005730C
 * Size:	000640
 */
void RunningModeState::update(u32&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0x7
	  stwu      r1, -0x58(r1)
	  stmw      r25, 0x3C(r1)
	  subi      r30, r5, 0x2848
	  addi      r31, r3, 0
	  addi      r26, r4, 0
	  addi      r28, r30, 0x1DC
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x1DC(r30)
	  lbz       r5, 0x124(r3)
	  cmplwi    r5, 0
	  bne-      .loc_0x178
	  lwz       r0, 0x340(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x178
	  lha       r0, 0x1E4(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x178
	  lwz       r0, 0x0(r26)
	  li        r3, 0xC
	  rlwinm    r0,r0,0,0,30
	  stw       r0, 0x0(r26)
	  lwz       r0, 0x1FC(r30)
	  lwz       r4, 0x0(r31)
	  stw       r0, 0x40(r4)
	  bl        -0x10378
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x170
	  lis       r3, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r3, 0x7ECC
	  stw       r0, 0x4(r29)
	  lis       r4, 0x802A
	  lis       r3, 0x803A
	  stw       r5, 0x0(r29)
	  addi      r0, r4, 0x7E18
	  subi      r3, r3, 0x24E0
	  stw       r0, 0x4(r29)
	  li        r0, 0x1
	  stw       r0, 0x238(r3)
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB96E0
	  lwz       r4, 0x20(r30)
	  addi      r3, r30, 0x2D8
	  lfs       f1, 0x20(r4)
	  bl        -0x5BB4
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x16175C
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x161878
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB69C4
	  lwz       r0, 0x2FC(r30)
	  cmpwi     r0, 0x1E
	  bge-      .loc_0x150
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2985C
	  cmpwi     r3, 0x1E
	  beq-      .loc_0x150
	  lwz       r0, 0x2B4(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x150
	  lfs       f0, -0x7A74(r2)
	  li        r4, 0x1C
	  lwz       r3, 0x0(r29)
	  li        r5, 0
	  li        r6, 0
	  stfs      f0, 0x28(r3)
	  li        r7, 0
	  li        r8, 0
	  lwz       r3, 0x0(r28)
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1FD08

	.loc_0x150:
	  lfs       f0, -0x7A80(r2)
	  li        r0, 0
	  lwz       r3, 0x0(r29)
	  stfs      f0, 0x2C(r3)
	  lfs       f0, -0x7A88(r2)
	  lwz       r3, 0x0(r29)
	  stfs      f0, 0x30(r3)
	  stw       r0, 0x8(r29)

	.loc_0x170:
	  mr        r3, r29
	  b         .loc_0x62C

	.loc_0x178:
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  addi      r6, r4, 0x1E4
	  lha       r0, 0x1E4(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x1C0
	  cmplwi    r5, 0
	  bne-      .loc_0x1C0
	  lwz       r3, 0x20(r4)
	  lfs       f1, 0x2F0(r4)
	  lfs       f0, 0x20(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C0
	  li        r0, 0
	  stw       r0, 0x334(r4)
	  li        r0, 0x1
	  sth       r0, 0x1E6(r4)

	.loc_0x1C0:
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  addi      r29, r27, 0x1E6
	  lha       r0, 0x1E6(r27)
	  cmpwi     r0, 0
	  beq-      .loc_0x268
	  lwz       r0, 0x338(r27)
	  cmpwi     r0, 0
	  bne-      .loc_0x268
	  li        r25, 0x1
	  sth       r25, 0x0(r6)
	  li        r0, 0
	  sth       r0, 0x0(r29)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2976C
	  cmpwi     r3, 0x1E
	  beq-      .loc_0x268
	  lwz       r0, 0x2FC(r27)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x268
	  lwz       r3, 0x2F6C(r13)
	  bl        0x28664
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x24C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  stw       r25, 0x244(r3)
	  li        r4, 0
	  li        r5, 0x1C
	  lwz       r3, 0x1E8(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x268

	.loc_0x24C:
	  lwz       r3, 0x1E8(r27)
	  li        r4, 0
	  li        r5, 0x1C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x268:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r6, 0
	  lwz       r0, 0x10C(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x288
	  li        r6, 0x1

	.loc_0x288:
	  lis       r4, 0x803A
	  subi      r25, r4, 0x2848
	  addi      r27, r25, 0x334
	  lwz       r0, 0x334(r25)
	  cmpwi     r0, 0
	  beq-      .loc_0x3A4
	  addi      r30, r25, 0x338
	  lwz       r5, 0x338(r25)
	  cmpwi     r5, 0
	  bne-      .loc_0x3A4
	  lwz       r0, 0x33C(r25)
	  cmpwi     r0, 0
	  bne-      .loc_0x3A4
	  lwz       r4, 0x0(r28)
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x3A4
	  lwz       r4, 0xC(r31)
	  lwz       r4, 0x28(r4)
	  rlwinm.   r0,r4,0,7,7
	  beq-      .loc_0x330
	  cmpwi     r5, 0
	  bne-      .loc_0x3A4
	  rlwinm.   r0,r6,0,24,31
	  bne-      .loc_0x3A4
	  li        r3, 0x113
	  bl        0x4DD78
	  lwz       r0, 0x2B4(r25)
	  lwz       r3, 0x2E70(r13)
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r0, r0, r4
	  rlwinm    r4,r0,0,24,31
	  bl        0x12B024
	  lwz       r3, 0x0(r30)
	  li        r0, 0x1
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  subfe     r3, r3, r4
	  stb       r3, 0x8(r31)
	  stw       r0, 0x0(r30)
	  b         .loc_0x3A4

	.loc_0x330:
	  lwz       r0, 0x2B4(r25)
	  cmpwi     r0, 0
	  bne-      .loc_0x3A4
	  rlwinm.   r0,r4,0,16,16
	  beq-      .loc_0x3A4
	  lwz       r4, 0x20(r25)
	  lfs       f0, -0x7A70(r2)
	  lfs       f1, 0x20(r4)
	  lfs       f2, 0x2F0(r25)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x3A4
	  cmpwi     r5, 0
	  bne-      .loc_0x3A4
	  rlwinm.   r0,r6,0,24,31
	  bne-      .loc_0x3A4
	  lwz       r12, 0x0(r3)
	  li        r4, 0x11
	  li        r5, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  li        r0, 0x1
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  subfe     r3, r3, r4
	  stb       r3, 0x8(r31)
	  stw       r0, 0x0(r30)

	.loc_0x3A4:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r0, 0x234(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x458
	  cmpwi     r0, 0x2
	  bne-      .loc_0x408
	  lwz       r4, 0x0(r31)
	  li        r0, 0x7
	  li        r3, 0x14
	  stw       r0, 0x40(r4)
	  bl        -0x106D8
	  cmplwi    r3, 0
	  beq-      .loc_0x62C
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7E4C
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x7A88(r2)
	  stfs      f0, 0x10(r3)
	  b         .loc_0x62C

	.loc_0x408:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x458
	  lwz       r4, 0x0(r31)
	  li        r0, 0x7
	  li        r3, 0x14
	  stw       r0, 0x40(r4)
	  bl        -0x10728
	  cmplwi    r3, 0
	  beq-      .loc_0x62C
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7E4C
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x7A6C(r2)
	  stfs      f0, 0x10(r3)
	  b         .loc_0x62C

	.loc_0x458:
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x46C
	  lwz       r4, 0xC(r31)
	  bl        0x191874

	.loc_0x46C:
	  lwz       r3, 0x2E84(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C4
	  lwz       r4, 0xC(r31)
	  bl        0x13B4AC
	  cmpwi     r3, 0
	  bne-      .loc_0x498
	  lwz       r0, 0x0(r26)
	  rlwinm    r0,r0,0,0,30
	  stw       r0, 0x0(r26)
	  b         .loc_0x4C4

	.loc_0x498:
	  cmpwi     r3, 0x3
	  bne-      .loc_0x4C4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  li        r5, 0x1
	  bl        -0x18784
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  stw       r0, 0x338(r3)
	  stw       r0, 0x2E84(r13)

	.loc_0x4C4:
	  lwz       r3, 0x2E88(r13)
	  lwz       r4, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4FC
	  bl        0x12B434
	  cmpwi     r3, 0x4
	  bne-      .loc_0x4FC
	  lwz       r3, 0x0(r28)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x4F8
	  li        r4, 0x2
	  bl        0x20454

	.loc_0x4F8:
	  bl        -0xA3C

	.loc_0x4FC:
	  lwz       r3, 0x2E70(r13)
	  lwz       r4, 0xC(r31)
	  bl        0x12AEB8
	  cmpwi     r3, 0
	  bne-      .loc_0x520
	  lwz       r0, 0x0(r26)
	  rlwinm    r0,r0,0,0,30
	  stw       r0, 0x0(r26)
	  b         .loc_0x628

	.loc_0x520:
	  cmpwi     r3, 0x6
	  bne-      .loc_0x554
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB5F68
	  li        r0, 0
	  stw       r0, 0x0(r27)
	  li        r0, 0x1
	  lis       r3, 0x803A
	  sth       r0, 0x0(r29)
	  subi      r3, r3, 0x2848
	  lbz       r0, 0x8(r31)
	  stw       r0, 0x338(r3)
	  b         .loc_0x628

	.loc_0x554:
	  cmpwi     r3, 0x7
	  bne-      .loc_0x5B0
	  lwz       r4, 0x0(r31)
	  li        r0, 0x1
	  li        r3, 0x8
	  stw       r0, 0x40(r4)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0x10888
	  cmplwi    r3, 0
	  beq-      .loc_0x62C
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7EB8
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x62C

	.loc_0x5B0:
	  cmpwi     r3, 0x5
	  bne-      .loc_0x628
	  lbz       r0, 0x2E81(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x610
	  lbz       r0, 0x2E82(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x610
	  lwz       r3, 0x2F6C(r13)
	  bl        0x28B94
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5F4
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x1611C8

	.loc_0x5F4:
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x1612B0
	  li        r0, 0x1
	  stb       r0, 0x2E82(r13)

	.loc_0x610:
	  lis       r3, 0x803A
	  lbz       r0, 0x8(r31)
	  subi      r3, r3, 0x2848
	  stw       r0, 0x338(r3)
	  li        r3, 0x11F
	  bl        0x4DA44

	.loc_0x628:
	  mr        r3, r31

	.loc_0x62C:
	  lmw       r25, 0x3C(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005794C
 * Size:	000004
 */
void GameInterface::message(int, int)
{
}

/*
 * --INFO--
 * Address:	80057950
 * Size:	000078
 */
void IntroGameModeState::postRender(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  lwz       r0, 0x2E88(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x10
	  addi      r3, r31, 0
	  stw       r0, 0x10(r1)
	  addi      r4, r1, 0x20
	  stw       r0, 0x14(r1)
	  stw       r6, 0x18(r1)
	  stw       r7, 0x1C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E88(r13)
	  mr        r4, r31
	  bl        0x12B320

	.loc_0x64:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800579C8
 * Size:	000294
 */
void RunningModeState::postRender(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stw       r31, 0x12C(r1)
	  addi      r0, r1, 0x98
	  mr        r31, r4
	  stw       r30, 0x128(r1)
	  mr        r30, r3
	  addi      r6, r1, 0x80
	  lfs       f2, -0x724C(r13)
	  addi      r5, r1, 0x8C
	  lfs       f1, -0x7258(r13)
	  mr        r4, r0
	  lfs       f0, -0x7264(r13)
	  stfs      f2, 0x80(r1)
	  addi      r3, r1, 0xA4
	  lfs       f2, -0x7248(r13)
	  stfs      f1, 0x8C(r1)
	  lfs       f1, -0x7254(r13)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x7260(r13)
	  stfs      f2, 0x84(r1)
	  lfs       f2, -0x7244(r13)
	  stfs      f1, 0x90(r1)
	  lfs       f1, -0x7250(r13)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, -0x725C(r13)
	  stfs      f2, 0x88(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0xA0(r1)
	  bl        -0x1994C
	  lbz       r0, 0x2E80(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x70
	  addi      r3, r31, 0
	  stw       r0, 0x70(r1)
	  addi      r4, r1, 0xE4
	  stw       r0, 0x74(r1)
	  stw       r6, 0x78(r1)
	  stw       r7, 0x7C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E5C(r13)
	  mr        r4, r31
	  bl        0xB9B60

	.loc_0xCC:
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r0, 0x33C(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x14C
	  lwz       r3, 0x1DC(r4)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x14C
	  lwz       r3, 0x0(r30)
	  lwz       r0, 0x3C(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x14C
	  lwz       r3, 0x20(r4)
	  lfs       f2, 0x2F0(r4)
	  lfs       f3, 0xB0(r3)
	  lfs       f1, 0x90(r3)
	  fsubs     f2, f2, f3
	  lfs       f0, -0x7A84(r2)
	  fsubs     f1, f1, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x14C
	  lfs       f0, -0x7A80(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x14C
	  lwz       r3, 0x2E6C(r13)
	  bl        0x19035C
	  lwz       r3, 0x2E6C(r13)
	  mr        r4, r31
	  bl        0x190DC0

	.loc_0x14C:
	  lbz       r0, 0x2E80(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x27C
	  lwz       r0, 0x2E88(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A8
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x60
	  addi      r3, r31, 0
	  stw       r0, 0x60(r1)
	  addi      r4, r1, 0xE4
	  stw       r0, 0x64(r1)
	  stw       r6, 0x68(r1)
	  stw       r7, 0x6C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E88(r13)
	  mr        r4, r31
	  bl        0x12B164

	.loc_0x1A8:
	  lwz       r6, 0x310(r31)
	  li        r30, 0
	  lwz       r0, 0x30C(r31)
	  addi      r5, r1, 0x50
	  addi      r3, r31, 0
	  stw       r30, 0x50(r1)
	  addi      r4, r1, 0xE4
	  stw       r30, 0x54(r1)
	  stw       r0, 0x58(r1)
	  stw       r6, 0x5C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E5C(r13)
	  mr        r4, r31
	  bl        0xB9CA0
	  lwz       r0, 0x2E68(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x238
	  lwz       r6, 0x310(r31)
	  addi      r5, r1, 0x40
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r4, r1, 0xE4
	  stw       r30, 0x40(r1)
	  stw       r30, 0x44(r1)
	  stw       r0, 0x48(r1)
	  stw       r6, 0x4C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E68(r13)
	  mr        r4, r31
	  bl        0x191A18

	.loc_0x238:
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x30
	  addi      r3, r31, 0
	  stw       r0, 0x30(r1)
	  addi      r4, r1, 0xE4
	  stw       r0, 0x34(r1)
	  stw       r6, 0x38(r1)
	  stw       r7, 0x3C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E70(r13)
	  mr        r4, r31
	  bl        0x12AE48

	.loc_0x27C:
	  lwz       r0, 0x134(r1)
	  lwz       r31, 0x12C(r1)
	  lwz       r30, 0x128(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80057C5C
 * Size:	000360
 */
void MessageModeState::update(u32&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  subi      r29, r4, 0x24E0
	  stw       r28, 0x50(r1)
	  lwz       r0, 0x234(r29)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x274
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x120
	  bge-      .loc_0x54
	  cmpwi     r0, 0
	  beq-      .loc_0x60
	  bge-      .loc_0xDC
	  b         .loc_0x324

	.loc_0x54:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x324
	  b         .loc_0x158

	.loc_0x60:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x7A84(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x324
	  lfs       f0, -0x7A78(r2)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stfs      f0, 0x10(r31)
	  lfs       f0, -0x7A80(r2)
	  lwz       r4, 0x2F00(r13)
	  stfs      f0, 0x4C8(r4)
	  lwz       r0, 0x2B4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xB8
	  lwz       r0, 0x2FC(r3)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0xD0

	.loc_0xB8:
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  lfs       f1, -0x7A64(r2)
	  li        r4, 0
	  bl        0x1910A4

	.loc_0xD0:
	  li        r0, 0x1
	  stw       r0, 0xC(r31)
	  b         .loc_0x324

	.loc_0xDC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x7A84(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x324
	  lfs       f0, -0x7A68(r2)
	  li        r0, 0x2
	  stfs      f0, 0x10(r31)
	  lfs       f0, -0x7A80(r2)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0x4CC(r3)
	  stw       r0, 0xC(r31)
	  b         .loc_0x324

	.loc_0x120:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x7A84(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x324
	  lfs       f0, -0x7A78(r2)
	  li        r0, 0x3
	  stfs      f0, 0x10(r31)
	  stw       r0, 0xC(r31)
	  b         .loc_0x324

	.loc_0x158:
	  lfs       f0, -0x7A84(r2)
	  li        r3, 0xC
	  lwz       r4, 0x2F00(r13)
	  stfs      f0, 0x4CC(r4)
	  lwz       r4, 0x2F00(r13)
	  stfs      f0, 0x4C8(r4)
	  bl        -0x10DC8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1F4
	  lis       r3, 0x802A
	  lwz       r4, 0x0(r31)
	  addi      r0, r3, 0x7ECC
	  stw       r0, 0x4(r28)
	  lis       r3, 0x802A
	  addi      r0, r3, 0x7E18
	  stw       r4, 0x0(r28)
	  li        r30, 0x1
	  stw       r0, 0x4(r28)
	  stw       r30, 0x238(r29)
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB8C98
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r4, 0x20(r3)
	  addi      r3, r3, 0x2D8
	  lfs       f1, 0x20(r4)
	  bl        -0x6604
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x160D0C
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x160E28
	  stw       r30, 0x8(r28)

	.loc_0x1F4:
	  li        r30, 0
	  stw       r30, 0x8(r28)
	  lwz       r3, 0x0(r31)
	  stw       r28, 0x38(r3)
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB5F60
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2B4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x26C
	  lwz       r0, 0x2FC(r3)
	  cmpwi     r0, 0x1E
	  beq-      .loc_0x324
	  lwz       r3, 0x1DC(r3)
	  li        r4, 0x34
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1F2B8
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x324
	  lfs       f1, -0x7A64(r2)
	  li        r4, 0
	  bl        0x190F0C
	  b         .loc_0x324

	.loc_0x26C:
	  stw       r30, 0x2E68(r13)
	  b         .loc_0x324

	.loc_0x274:
	  cmpwi     r0, 0
	  bne-      .loc_0x324
	  li        r3, 0xC
	  bl        -0x10ED8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x304
	  lis       r3, 0x802A
	  lwz       r4, 0x0(r31)
	  addi      r0, r3, 0x7ECC
	  stw       r0, 0x4(r28)
	  lis       r3, 0x802A
	  addi      r0, r3, 0x7E18
	  stw       r4, 0x0(r28)
	  li        r30, 0x1
	  stw       r0, 0x4(r28)
	  stw       r30, 0x238(r29)
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB8B88
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r4, 0x20(r3)
	  addi      r3, r3, 0x2D8
	  lfs       f1, 0x20(r4)
	  bl        -0x6714
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x160BFC
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x160D18
	  stw       r30, 0x8(r28)

	.loc_0x304:
	  li        r0, 0
	  stw       r0, 0x2E68(r13)
	  stw       r0, 0x8(r28)
	  lwz       r3, 0x0(r31)
	  stw       r28, 0x38(r3)
	  lfs       f0, -0x7A80(r2)
	  lwz       r3, 0x0(r31)
	  stfs      f0, 0x2C(r3)

	.loc_0x324:
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x33C
	  lwz       r4, 0x0(r31)
	  lwz       r4, 0x24(r4)
	  bl        0x191054

	.loc_0x33C:
	  mr        r3, r31
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80057FBC
 * Size:	000474
 */
void DayOverModeState::update(u32&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2E88(r13)
	  lwz       r4, 0x0(r31)
	  cmplwi    r3, 0
	  lwz       r4, 0x24(r4)
	  beq-      .loc_0x68
	  bl        0x12AC20
	  cmpwi     r3, 0x4
	  bne-      .loc_0x68
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  li        r4, 0x2
	  bl        0x1FC38

	.loc_0x64:
	  bl        -0x1258

	.loc_0x68:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r30, r3, 0x1DC
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xEC
	  lwz       r0, 0x8(r31)
	  li        r3, 0
	  cmpwi     r0, 0x2
	  beq-      .loc_0xCC
	  bge-      .loc_0xA8
	  cmpwi     r0, 0
	  beq-      .loc_0xB4
	  bge-      .loc_0xC0
	  b         .loc_0xE0

	.loc_0xA8:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xE0
	  b         .loc_0xD8

	.loc_0xB4:
	  mr        r3, r31
	  bl        0x60C
	  b         .loc_0xE0

	.loc_0xC0:
	  mr        r3, r31
	  bl        0x968
	  b         .loc_0xE0

	.loc_0xCC:
	  mr        r3, r31
	  bl        0xD6C
	  b         .loc_0xE0

	.loc_0xD8:
	  mr        r3, r31
	  bl        0xFB8

	.loc_0xE0:
	  cmplwi    r3, 0
	  beq-      .loc_0xEC
	  b         .loc_0x458

	.loc_0xEC:
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  lwz       r4, 0x0(r31)
	  lwz       r4, 0x24(r4)
	  bl        0x190F2C

	.loc_0x104:
	  lwz       r3, 0x2E64(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x178
	  lwz       r4, 0x0(r31)
	  lwz       r4, 0x24(r4)
	  bl        0x1974E8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x178
	  lwz       r4, 0x0(r31)
	  li        r0, 0x6
	  li        r3, 0x8
	  stw       r0, 0x40(r4)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0x11100
	  cmplwi    r3, 0
	  beq-      .loc_0x458
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7EB8
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x458

	.loc_0x178:
	  lwz       r3, 0x2E74(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x2B0
	  lwz       r4, 0x0(r31)
	  lwz       r4, 0x24(r4)
	  bl        0x12CAD0
	  addi      r29, r3, 0
	  cmpwi     r29, 0x7
	  blt-      .loc_0x2B0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x78
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB54D4
	  lwz       r3, 0x0(r30)
	  bl        0x1EE4C
	  li        r3, 0x6
	  li        r4, 0
	  bl        -0x3E910
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  li        r5, 0x1
	  bl        -0x1916C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        -0x1917C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x1918C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x19164
	  mr        r0, r3
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r0
	  bl        -0x19174
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2E7C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x2B0
	  cmpwi     r29, 0x8
	  bne-      .loc_0x25C
	  lwz       r3, 0x0(r31)
	  li        r0, 0x1
	  stw       r0, 0x40(r3)
	  b         .loc_0x268

	.loc_0x25C:
	  lwz       r3, 0x0(r31)
	  li        r0, 0x6
	  stw       r0, 0x40(r3)

	.loc_0x268:
	  lwz       r4, 0x2DEC(r13)
	  li        r3, 0x8
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0x11238
	  cmplwi    r3, 0
	  beq-      .loc_0x458
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7EB8
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x458

	.loc_0x2B0:
	  lwz       r3, 0x2E78(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x350
	  lwz       r4, 0x0(r31)
	  lwz       r4, 0x24(r4)
	  bl        0x19CEB8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x350
	  lwz       r0, 0x8(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x2F4
	  lwz       r3, 0x0(r30)
	  li        r4, 0x2
	  bl        0x1F9B4
	  li        r0, 0
	  stw       r0, 0x2E78(r13)
	  b         .loc_0x350

	.loc_0x2F4:
	  li        r0, 0
	  stw       r0, 0x2E78(r13)
	  li        r0, 0xB
	  li        r3, 0x8
	  lwz       r4, 0x0(r31)
	  stw       r0, 0x40(r4)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0x112D8
	  cmplwi    r3, 0
	  beq-      .loc_0x458
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7EB8
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x458

	.loc_0x350:
	  lwz       r3, 0x2E7C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x454
	  li        r30, 0
	  stw       r30, 0x20(r1)
	  addi      r5, r1, 0x18
	  lwz       r4, 0x0(r31)
	  lwz       r4, 0x24(r4)
	  bl        0x13B41C
	  cmpwi     r3, 0x1
	  blt-      .loc_0x454
	  stw       r30, 0x2E7C(r13)
	  beq-      .loc_0x40C
	  cmpwi     r3, 0x5
	  beq-      .loc_0x40C
	  lis       r3, 0x803A
	  lwz       r0, 0x1C(r1)
	  subi      r5, r3, 0x2848
	  stb       r0, 0x1C7(r5)
	  addi      r3, r5, 0x24
	  li        r0, 0x1
	  lwz       r4, 0x18(r1)
	  addi      r4, r4, 0x1
	  stb       r4, 0xB5(r5)
	  lwz       r4, 0x2DEC(r13)
	  addi      r5, r4, 0x1C
	  lwz       r4, 0x1C(r4)
	  neg       r4, r4
	  stw       r0, 0x0(r5)
	  subic     r0, r4, 0x1
	  subfe     r29, r0, r4
	  bl        0x1C18C
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r0, 0x20(r3)
	  rlwinm.   r0,r0,0,15,15
	  beq-      .loc_0x400
	  lis       r4, 0x803B
	  lwz       r3, 0x2F88(r13)
	  subi      r5, r4, 0x7DA0
	  lis       r4, 0x2
	  addi      r6, r4, 0x6000
	  li        r4, 0
	  bl        0x2C168

	.loc_0x400:
	  lwz       r3, 0x2DEC(r13)
	  rlwinm    r0,r29,0,24,31
	  stw       r0, 0x1C(r3)

	.loc_0x40C:
	  lwz       r4, 0x2DEC(r13)
	  li        r3, 0x8
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0x113DC
	  cmplwi    r3, 0
	  beq-      .loc_0x458
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r31)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7EB8
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x458

	.loc_0x454:
	  mr        r3, r31

	.loc_0x458:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80058430
 * Size:	000250
 */
void DayOverModeState::makeTotalScoreWindow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  subi      r31, r3, 0x2848
	  stw       r30, 0x38(r1)
	  lwz       r0, 0x2FC(r31)
	  stw       r0, 0x1C(r1)
	  lwz       r3, 0x2F6C(r13)
	  lwz       r0, 0x1A8(r3)
	  stw       r0, 0x20(r1)
	  bl        0x285F8
	  stw       r3, 0x24(r1)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x28804
	  stw       r3, 0x18(r1)
	  addi      r3, r31, 0x94
	  addi      r4, r1, 0x18
	  bl        -0x43DC
	  li        r3, 0x44
	  bl        -0x11480
	  lwz       r0, 0x18(r1)
	  mr        r4, r3
	  addi      r30, r4, 0
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lwz       r3, 0x1C(r1)
	  stw       r3, 0x4(r4)
	  lwz       r3, 0x20(r1)
	  stw       r3, 0x8(r4)
	  lwz       r3, 0x24(r1)
	  stw       r3, 0xC(r4)
	  lwz       r3, 0xB8(r31)
	  stw       r3, 0x10(r4)
	  lwz       r3, 0xBC(r31)
	  extsh     r3, r3
	  sth       r3, 0x1A(r4)
	  lwz       r3, 0xC0(r31)
	  extsh     r3, r3
	  sth       r3, 0x24(r4)
	  lwz       r3, 0xE4(r31)
	  extsh     r3, r3
	  sth       r3, 0x2E(r4)
	  lwz       r3, 0xF8(r31)
	  extsh     r3, r3
	  sth       r3, 0x38(r4)
	  lha       r3, 0x38(r4)
	  cmpwi     r3, 0x270F
	  bne-      .loc_0xCC
	  sth       r0, 0x38(r4)

	.loc_0xCC:
	  addi      r5, r31, 0x8
	  lwz       r3, 0xC4(r31)
	  addi      r6, r4, 0x2
	  addi      r7, r31, 0x4
	  extsh     r3, r3
	  sth       r3, 0x1C(r4)
	  lwz       r3, 0xC8(r31)
	  extsh     r3, r3
	  sth       r3, 0x26(r4)
	  lwz       r3, 0xE8(r31)
	  extsh     r3, r3
	  sth       r3, 0x30(r4)
	  lwz       r3, 0xFC(r31)
	  extsh     r3, r3
	  sth       r3, 0x3A(r4)
	  lha       r3, 0x3A(r4)
	  cmpwi     r3, 0x270F
	  bne-      .loc_0x118
	  sth       r0, 0x38(r6)

	.loc_0x118:
	  lwz       r3, 0xC4(r5)
	  extsh     r3, r3
	  sth       r3, 0x1C(r6)
	  lwz       r3, 0xC8(r5)
	  addi      r5, r5, 0x8
	  extsh     r3, r3
	  sth       r3, 0x26(r6)
	  lwz       r3, 0xE8(r7)
	  extsh     r3, r3
	  sth       r3, 0x30(r6)
	  lwz       r3, 0xFC(r7)
	  addi      r7, r7, 0x4
	  extsh     r3, r3
	  sth       r3, 0x3A(r6)
	  lha       r3, 0x3A(r6)
	  addi      r6, r6, 0x2
	  cmpwi     r3, 0x270F
	  bne-      .loc_0x164
	  sth       r0, 0x38(r6)

	.loc_0x164:
	  lwz       r3, 0xC4(r5)
	  extsh     r3, r3
	  sth       r3, 0x1C(r6)
	  lwz       r3, 0xC8(r5)
	  addi      r5, r5, 0x8
	  extsh     r3, r3
	  sth       r3, 0x26(r6)
	  lwz       r3, 0xE8(r7)
	  extsh     r3, r3
	  sth       r3, 0x30(r6)
	  lwz       r3, 0xFC(r7)
	  addi      r7, r7, 0x4
	  extsh     r3, r3
	  sth       r3, 0x3A(r6)
	  lha       r3, 0x3A(r6)
	  addi      r6, r6, 0x2
	  cmpwi     r3, 0x270F
	  bne-      .loc_0x1B0
	  sth       r0, 0x38(r6)

	.loc_0x1B0:
	  lwz       r3, 0xC4(r5)
	  extsh     r3, r3
	  sth       r3, 0x1C(r6)
	  lwz       r3, 0xC8(r5)
	  extsh     r3, r3
	  sth       r3, 0x26(r6)
	  lwz       r3, 0xE8(r7)
	  extsh     r3, r3
	  sth       r3, 0x30(r6)
	  lwz       r3, 0xFC(r7)
	  extsh     r3, r3
	  sth       r3, 0x3A(r6)
	  lha       r3, 0x3A(r6)
	  addi      r6, r6, 0x2
	  cmpwi     r3, 0x270F
	  bne-      .loc_0x1F4
	  sth       r0, 0x38(r6)

	.loc_0x1F4:
	  lwz       r0, 0x28(r1)
	  li        r3, 0x1B4
	  extsh     r0, r0
	  sth       r0, 0x14(r4)
	  lwz       r0, 0x2C(r1)
	  extsh     r0, r0
	  sth       r0, 0x16(r4)
	  lwz       r0, 0x30(r1)
	  extsh     r0, r0
	  sth       r0, 0x18(r4)
	  bl        -0x11648
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x234
	  mr        r4, r30
	  bl        0x19CA68

	.loc_0x234:
	  stw       r31, 0x2E78(r13)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80058680
 * Size:	000368
 */
void DayOverModeState::initialisePhaseOne()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  stw       r28, 0x38(r1)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x285CC
	  cmpwi     r3, 0x1E
	  bne-      .loc_0x98
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB4F9C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x19690
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x19668
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  addi      r0, r3, 0
	  lwz       r3, 0x1DC(r4)
	  mr        r28, r0
	  li        r4, 0x4B
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1EA5C
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r28
	  bl        -0x196A8
	  b         .loc_0x33C

	.loc_0x98:
	  lis       r3, 0x803A
	  subi      r28, r3, 0x2848
	  lwz       r0, 0x2FC(r28)
	  cmpwi     r0, 0x1E
	  blt-      .loc_0x1DC
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB4F20
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x1970C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x196E4
	  lis       r4, 0x8022
	  lwz       r7, 0x2F6C(r13)
	  addi      r6, r4, 0x2378
	  lwz       r5, 0x0(r6)
	  li        r4, 0x1
	  lwz       r0, 0x4(r6)
	  addi      r31, r3, 0
	  li        r8, 0
	  stw       r5, 0x28(r1)
	  addi      r5, r1, 0x28
	  stw       r0, 0x2C(r1)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x30(r1)
	  lwz       r0, 0x28(r1)
	  lbz       r3, 0x184(r7)
	  slw       r0, r4, r0
	  and.      r0, r3, r0
	  beq-      .loc_0x124
	  li        r0, 0xC
	  slw       r0, r4, r0
	  mr        r8, r0

	.loc_0x124:
	  lwzu      r0, 0x4(r5)
	  lbz       r3, 0x184(r7)
	  slw       r0, r4, r0
	  and.      r0, r3, r0
	  beq-      .loc_0x144
	  li        r0, 0xD
	  slw       r0, r4, r0
	  or        r8, r8, r0

	.loc_0x144:
	  lwz       r0, 0x4(r5)
	  lbz       r3, 0x184(r7)
	  slw       r0, r4, r0
	  and.      r0, r3, r0
	  beq-      .loc_0x164
	  li        r0, 0xE
	  slw       r0, r4, r0
	  or        r8, r8, r0

	.loc_0x164:
	  rlwinm.   r0,r8,0,18,18
	  bne-      .loc_0x170
	  ori       r8, r8, 0x800

	.loc_0x170:
	  rlwinm.   r0,r8,0,17,17
	  bne-      .loc_0x17C
	  ori       r8, r8, 0x8000

	.loc_0x17C:
	  lfs       f0, -0x7A74(r2)
	  oris      r9, r8, 0xFFFF
	  lwz       r4, 0x0(r29)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stfs      f0, 0x28(r4)
	  ori       r9, r9, 0x7FF
	  li        r4, 0x45
	  lfs       f0, -0x7A80(r2)
	  li        r5, 0
	  lwz       r7, 0x0(r29)
	  li        r6, 0
	  li        r8, 0
	  stfs      f0, 0x2C(r7)
	  li        r7, 0
	  li        r10, 0x1
	  lwz       r3, 0x1DC(r3)
	  bl        0x1E920
	  li        r0, 0
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x2E68(r13)
	  mr        r4, r31
	  bl        -0x197EC
	  b         .loc_0x33C

	.loc_0x1DC:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x19834
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x1980C
	  li        r0, 0
	  lfs       f0, -0x7A74(r2)
	  stw       r0, 0x2E68(r13)
	  addi      r30, r3, 0
	  addi      r31, r28, 0x1DC
	  lwz       r5, 0x0(r29)
	  li        r4, 0x20
	  li        r6, 0
	  stfs      f0, 0x28(r5)
	  li        r5, 0
	  li        r7, 0
	  lwz       r3, 0x1DC(r28)
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E8AC
	  lwz       r3, 0x2F6C(r13)
	  bl        0x27BB8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x330
	  lwz       r0, 0x2B4(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x330
	  lis       r3, 0x8022
	  addi      r6, r3, 0x2384
	  lwz       r4, 0x0(r6)
	  lis       r3, 0x803D
	  lwz       r0, 0x4(r6)
	  addi      r5, r3, 0x1EB8
	  addi      r7, r1, 0x1C
	  stw       r4, 0x1C(r1)
	  li        r8, 0
	  li        r3, 0x1
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x24(r1)
	  lwz       r0, 0x1C(r1)
	  rlwinm    r6,r0,2,0,29
	  add       r4, r5, r6
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x2AC
	  li        r0, 0xC
	  slw       r0, r3, r0
	  mr        r8, r0

	.loc_0x2AC:
	  lwzu      r0, 0x4(r7)
	  rlwinm    r6,r0,2,0,29
	  add       r4, r5, r6
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x2D0
	  li        r0, 0xD
	  slw       r0, r3, r0
	  or        r8, r8, r0

	.loc_0x2D0:
	  lwz       r0, 0x4(r7)
	  rlwinm    r6,r0,2,0,29
	  add       r4, r5, r6
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x2F4
	  li        r0, 0xE
	  slw       r0, r3, r0
	  or        r8, r8, r0

	.loc_0x2F4:
	  cmplwi    r8, 0
	  bne-      .loc_0x304
	  ori       r8, r8, 0x8000
	  b         .loc_0x308

	.loc_0x304:
	  ori       r8, r8, 0x800

	.loc_0x308:
	  oris      r9, r8, 0xFFFF
	  lwz       r3, 0x0(r31)
	  ori       r9, r9, 0x7FF
	  li        r4, 0x38
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r10, 0x1
	  bl        0x1E7B4

	.loc_0x330:
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r30
	  bl        -0x19950

	.loc_0x33C:
	  li        r0, 0x1
	  stw       r0, 0x8(r29)
	  li        r3, 0
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800589E8
 * Size:	000410
 */
void DayOverModeState::initialisePhaseTwo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  li        r6, 0x78
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  mr        r27, r3
	  subi      r31, r4, 0x2280
	  li        r4, 0
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB4C28
	  lis       r3, 0x803A
	  subi      r29, r3, 0x2848
	  addi      r30, r29, 0x1DC
	  lwz       r3, 0x1DC(r29)
	  bl        0x1E594
	  li        r3, 0x6
	  li        r4, 0
	  bl        -0x3F1C8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  li        r5, 0x1
	  bl        -0x19A24
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        -0x19A34
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x19A44
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x19A1C
	  mr        r0, r3
	  lwz       r3, 0x2F6C(r13)
	  mr        r28, r0
	  bl        0x281DC
	  cmpwi     r3, 0x1E
	  bne-      .loc_0xE0
	  lwz       r3, 0x0(r30)
	  li        r4, 0x71
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E6A0
	  b         .loc_0x3A4

	.loc_0xE0:
	  lwzu      r0, 0x2FC(r29)
	  cmpwi     r0, 0x1E
	  bge-      .loc_0x330
	  lwz       r3, 0x0(r30)
	  li        r4, 0x24
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E66C
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x144
	  lwz       r3, 0x0(r30)
	  li        r4, 0x54
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E638

	.loc_0x144:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x178
	  lwz       r3, 0x0(r30)
	  li        r4, 0x55
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E604

	.loc_0x178:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x1AC
	  lwz       r3, 0x0(r30)
	  li        r4, 0x56
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E5D0

	.loc_0x1AC:
	  lwz       r4, 0x0(r29)
	  lis       r3, 0x803A
	  subi      r6, r3, 0x2848
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r29)
	  lwz       r0, 0x2B4(r6)
	  cmpwi     r0, 0
	  bne-      .loc_0x2C4
	  lwz       r3, 0x2F6C(r13)
	  li        r0, 0
	  stw       r0, 0x40(r1)
	  addi      r4, r1, 0x40
	  addi      r3, r3, 0x70
	  bl        0x2AF4C
	  lwz       r4, 0x40(r1)
	  li        r9, 0
	  cmpwi     r4, 0
	  ble-      .loc_0x28C
	  cmpwi     r4, 0x8
	  subi      r4, r4, 0x8
	  ble-      .loc_0x3EC
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  addi      r8, r31, 0
	  ble-      .loc_0x3EC

	.loc_0x218:
	  add       r7, r3, r9
	  stw       r7, 0x0(r8)
	  addi      r0, r7, 0x1
	  addi      r4, r7, 0x2
	  stw       r0, 0x4(r8)
	  addi      r0, r7, 0x3
	  addi      r6, r7, 0x4
	  stw       r4, 0x8(r8)
	  addi      r5, r7, 0x5
	  addi      r4, r7, 0x6
	  stw       r0, 0xC(r8)
	  addi      r0, r7, 0x7
	  addi      r9, r9, 0x8
	  stw       r6, 0x10(r8)
	  stw       r5, 0x14(r8)
	  stw       r4, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  addi      r8, r8, 0x20
	  bdnz+     .loc_0x218
	  b         .loc_0x3EC

	.loc_0x268:
	  sub       r0, r5, r9
	  cmpw      r9, r5
	  mtctr     r0
	  bge-      .loc_0x28C

	.loc_0x278:
	  add       r0, r3, r9
	  stw       r0, 0x0(r4)
	  addi      r4, r4, 0x4
	  addi      r9, r9, 0x1
	  bdnz+     .loc_0x278

	.loc_0x28C:
	  rlwinm    r0,r9,2,0,29
	  li        r3, 0
	  stwx      r3, r31, r0
	  li        r3, 0x55C
	  bl        -0x11C80
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x2B4
	  mr        r4, r31
	  bl        0x12B6CC

	.loc_0x2B4:
	  stw       r29, 0x2E74(r13)
	  lwz       r3, 0x2E74(r13)
	  bl        0x12B830
	  b         .loc_0x3A4

	.loc_0x2C4:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r4, 0xA8(r3)
	  lis       r3, 0x803D
	  addi      r5, r3, 0x1ED0
	  lhz       r0, 0x28(r4)
	  addi      r3, r6, 0x94
	  addi      r4, r1, 0x20
	  stw       r0, 0x20(r1)
	  lwz       r6, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  add       r0, r0, r6
	  add       r0, r5, r0
	  stw       r0, 0x24(r1)
	  bl        -0x4DBC
	  li        r3, 0xA0
	  bl        -0x11CEC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x31C
	  bl        0x195E68

	.loc_0x31C:
	  stw       r29, 0x2E64(r13)
	  addi      r4, r1, 0x20
	  lwz       r3, 0x2E64(r13)
	  bl        0x196A60
	  b         .loc_0x3A4

	.loc_0x330:
	  lwz       r3, 0x2F6C(r13)
	  bl        0x26E68
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x378
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  li        r0, 0x1
	  stw       r0, 0x244(r3)
	  li        r4, 0x72
	  li        r5, 0
	  lwz       r3, 0x0(r30)
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E408
	  b         .loc_0x3A4

	.loc_0x378:
	  lwz       r3, 0x0(r30)
	  li        r4, 0x49
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E3E0
	  mr        r3, r27
	  bl        -0x958

	.loc_0x3A4:
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r28
	  bl        -0x19D2C
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7A80(r2)
	  li        r0, 0x2
	  lwz       r4, 0x0(r27)
	  li        r3, 0
	  stfs      f0, 0x2C(r4)
	  lfs       f0, -0x7A88(r2)
	  lwz       r4, 0x0(r27)
	  stfs      f0, 0x30(r4)
	  stw       r0, 0x8(r27)
	  b         .loc_0x3FC

	.loc_0x3EC:
	  rlwinm    r0,r9,2,0,29
	  lwz       r5, 0x40(r1)
	  add       r4, r31, r0
	  b         .loc_0x268

	.loc_0x3FC:
	  lmw       r27, 0x4C(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80058DF8
 * Size:	000258
 */
void DayOverModeState::initialisePhaseThree()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  li        r6, 0x78
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  stw       r28, 0x28(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  subi      r28, r3, 0x2848
	  addi      r31, r28, 0x1DC
	  lwz       r3, 0x1DC(r28)
	  bl        0x1E188
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  li        r5, 0x1
	  bl        -0x19E24
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        -0x19E34
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x19E44
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x19E1C
	  mr        r0, r3
	  lwz       r3, 0x2F6C(r13)
	  mr        r30, r0
	  li        r4, 0
	  bl        0x27B2C
	  lwz       r3, 0x2F6C(r13)
	  bl        0x27DD0
	  cmpwi     r3, 0x1E
	  bne-      .loc_0xDC
	  lwz       r3, 0x0(r31)
	  li        r4, 0x4C
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E294
	  b         .loc_0x20C

	.loc_0xDC:
	  lwz       r0, 0x2FC(r28)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x20C
	  lwz       r3, 0x2F6C(r13)
	  bl        0x26CA0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x128
	  lwz       r3, 0x0(r31)
	  li        r4, 0x4D
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E250
	  mr        r3, r29
	  bl        -0xAE8
	  b         .loc_0x20C

	.loc_0x128:
	  lis       r3, 0x8022
	  lwz       r7, 0x2F6C(r13)
	  addi      r5, r3, 0x2390
	  lwz       r4, 0x0(r5)
	  li        r3, 0x1
	  lwz       r0, 0x4(r5)
	  addi      r6, r1, 0x1C
	  li        r8, 0
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x24(r1)
	  lwz       r0, 0x1C(r1)
	  lbz       r4, 0x184(r7)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  beq-      .loc_0x178
	  li        r0, 0xC
	  slw       r0, r3, r0
	  mr        r8, r0

	.loc_0x178:
	  lwzu      r0, 0x4(r6)
	  lbz       r4, 0x184(r7)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  beq-      .loc_0x198
	  li        r0, 0xD
	  slw       r0, r3, r0
	  or        r8, r8, r0

	.loc_0x198:
	  lwz       r0, 0x4(r6)
	  lbz       r4, 0x184(r7)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  beq-      .loc_0x1B8
	  li        r0, 0xE
	  slw       r0, r3, r0
	  or        r8, r8, r0

	.loc_0x1B8:
	  oris      r28, r8, 0xFFFF
	  lwz       r3, 0x2E5C(r13)
	  ori       r28, r28, 0x7FF
	  bl        0xB5B9C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r4, 0x20(r3)
	  addi      r3, r3, 0x2D8
	  lfs       f1, 0x10(r4)
	  bl        -0x77B8
	  lwz       r3, 0x0(r31)
	  addi      r9, r28, 0
	  li        r4, 0x4A
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r10, 0x1
	  bl        0x1E168
	  li        r0, 0
	  stw       r0, 0x2E68(r13)

	.loc_0x20C:
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r30
	  bl        -0x19FA4
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x3
	  stw       r0, 0x8(r29)
	  li        r3, 0
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80059050
 * Size:	00013C
 */
void DayOverModeState::initialisePhaseFour()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0x1DC
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lwz       r3, 0x1DC(r4)
	  bl        0x1DF54
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  li        r5, 0x1
	  bl        -0x1A058
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        -0x1A068
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  li        r5, 0x2
	  bl        -0x1A078
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0x1A050
	  mr        r0, r3
	  lwz       r3, 0x2F6C(r13)
	  mr        r30, r0
	  bl        0x27BA8
	  cmpwi     r3, 0x1E
	  bne-      .loc_0xB4
	  lwz       r3, 0x0(r31)
	  li        r4, 0x4D
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1E06C
	  mr        r3, r29
	  bl        -0xCCC
	  b         .loc_0x108

	.loc_0xB4:
	  lwz       r4, 0x0(r29)
	  li        r0, 0xB
	  li        r3, 0x8
	  stw       r0, 0x40(r4)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0x12124
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  lis       r4, 0x802A
	  lwz       r5, 0x0(r29)
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7EB8
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x120

	.loc_0x108:
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r30
	  bl        -0x1A0F8
	  li        r0, 0x4
	  stw       r0, 0x8(r29)
	  li        r3, 0

	.loc_0x120:
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
 * Address:	8005918C
 * Size:	0000C0
 */
void GameMovieInterface::parseMessages()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r0,r30,3,0,28
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  add       r31, r29, r0
	  b         .loc_0x4C

	.loc_0x2C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r31, 0xC
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x4C:
	  lwz       r0, 0x10C(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x2C
	  li        r30, 0
	  mulli     r0, r30, 0x2C
	  li        r3, 0
	  stw       r3, 0x10C(r29)
	  add       r31, r29, r0
	  b         .loc_0x90

	.loc_0x70:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r31, 0x110
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x2C
	  addi      r30, r30, 0x1

	.loc_0x90:
	  lwz       r0, 0x690(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x70
	  li        r0, 0
	  stw       r0, 0x690(r29)
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
 * Address:	8005924C
 * Size:	000428
 */
void GameMovieInterface::parse(GameMovieInterface::SimpleMessage&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  lwz       r0, 0x0(r4)
	  lwz       r7, 0x4(r4)
	  cmplwi    r0, 0x11
	  bgt-      .loc_0x414
	  lis       r4, 0x802A
	  addi      r4, r4, 0x7B0C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  cmpwi     r7, 0x11
	  li        r4, -0x1
	  li        r5, 0
	  bne-      .loc_0xFC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r6, 0x1E0(r3)
	  cmpwi     r6, -0x1
	  bne-      .loc_0x90
	  lha       r0, 0x1E2(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x78
	  lwz       r3, 0x1DC(r3)
	  li        r4, 0x2
	  bl        0x1E998
	  b         .loc_0x414

	.loc_0x78:
	  extsh.    r0, r0
	  bne-      .loc_0x88
	  li        r7, 0x1A
	  b         .loc_0xFC

	.loc_0x88:
	  li        r7, 0x18
	  b         .loc_0xFC

	.loc_0x90:
	  lha       r3, 0x1E2(r3)
	  extsh.    r0, r3
	  bne-      .loc_0xA4
	  addi      r7, r6, 0x5C
	  b         .loc_0xFC

	.loc_0xA4:
	  cmpwi     r3, 0x1
	  bne-      .loc_0xBC
	  addi      r4, r6, 0
	  addi      r7, r6, 0x3E
	  li        r5, 0
	  b         .loc_0xFC

	.loc_0xBC:
	  cmpwi     r3, 0x2
	  bne-      .loc_0xE8
	  cmpwi     r6, 0x1A
	  addi      r0, r6, 0x7A
	  bne-      .loc_0xE0
	  li        r0, 0x1
	  stb       r0, 0x2E8D(r13)
	  li        r7, 0x1B
	  b         .loc_0xFC

	.loc_0xE0:
	  mr        r7, r0
	  b         .loc_0xFC

	.loc_0xE8:
	  cmpwi     r3, 0x3
	  bne-      .loc_0xFC
	  addi      r4, r6, 0
	  addi      r7, r6, 0x20
	  li        r5, 0x1

	.loc_0xFC:
	  mr        r3, r7
	  bl        -0x2734
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  stw       r0, 0x338(r3)
	  b         .loc_0x414
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB4438
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  sth       r0, 0x1E6(r3)
	  b         .loc_0x414
	  lbz       r0, 0x2E81(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x414
	  lbz       r0, 0x2E82(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x414
	  lwz       r3, 0x2F6C(r13)
	  bl        0x270D8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x170
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x15F788

	.loc_0x170:
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x15F8A4
	  li        r0, 0
	  stb       r0, 0x2E82(r13)
	  b         .loc_0x414
	  lbz       r0, 0x2E81(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x414
	  lbz       r0, 0x2E82(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x414
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2707C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1CC
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x15F6B0

	.loc_0x1CC:
	  lwz       r3, 0x2E5C(r13)
	  li        r4, 0x1
	  lfs       f1, -0x7A88(r2)
	  lwz       r3, 0x344(r3)
	  bl        0x15F798
	  li        r0, 0x1
	  stb       r0, 0x2E82(r13)
	  b         .loc_0x414
	  cmpwi     r7, 0
	  bne-      .loc_0x308
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r4, r3, 0x234
	  lwz       r0, 0x234(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x294
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r0, 0x2B4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x288
	  lwz       r0, 0x2FC(r31)
	  cmpwi     r0, 0x1E
	  beq-      .loc_0x288
	  lwz       r3, 0x1DC(r31)
	  li        r4, 0x2F
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1DCC8
	  lwz       r4, 0x20(r31)
	  addi      r3, r31, 0x2D8
	  lfs       f1, 0x20(r4)
	  bl        -0x7C8C
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x278
	  lfs       f1, -0x7A64(r2)
	  li        r4, 0x1
	  bl        0x18F90C

	.loc_0x278:
	  lfs       f0, -0x7A84(r2)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0x4CC(r3)
	  b         .loc_0x414

	.loc_0x288:
	  li        r0, 0
	  stw       r0, 0x0(r4)
	  b         .loc_0x414

	.loc_0x294:
	  li        r0, 0x1
	  stw       r0, 0x0(r4)
	  li        r4, 0
	  lwz       r3, 0x3120(r13)
	  bl        0xBDF48
	  lis       r4, 0x803A
	  subi      r31, r4, 0x2848
	  addi      r6, r3, 0
	  lwz       r3, 0x1DC(r31)
	  addi      r7, r6, 0x94
	  addi      r8, r6, 0x88
	  li        r4, 0x2E
	  li        r5, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1DC44
	  lwz       r0, 0x2B4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x2EC
	  lwz       r0, 0x2FC(r31)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x414

	.loc_0x2EC:
	  lwz       r3, 0x2E68(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x414
	  lfs       f1, -0x7A64(r2)
	  li        r4, 0x1
	  bl        0x18F880
	  b         .loc_0x414

	.loc_0x308:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  li        r0, 0x2
	  stw       r0, 0x234(r3)
	  b         .loc_0x414
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  li        r0, 0
	  stw       r0, 0x234(r3)
	  b         .loc_0x414
	  rlwinm    r0,r7,0,0,0
	  lwz       r3, 0x2E5C(r13)
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r5, r0, r4
	  rlwinm    r4,r7,0,1,31
	  bl        0xB3A04
	  b         .loc_0x414
	  lwz       r3, 0x2E5C(r13)
	  mr        r4, r7
	  bl        0xB3E58
	  b         .loc_0x414
	  lfs       f0, -0x7A84(r2)
	  lwz       r4, 0x4(r3)
	  stfs      f0, 0x2C(r4)
	  lfs       f0, -0x7A60(r2)
	  lwz       r3, 0x4(r3)
	  stfs      f0, 0x30(r3)
	  b         .loc_0x414
	  lfs       f0, -0x7A84(r2)
	  lwz       r4, 0x4(r3)
	  stfs      f0, 0x28(r4)
	  lfs       f0, -0x7A80(r2)
	  lwz       r4, 0x4(r3)
	  stfs      f0, 0x2C(r4)
	  lfs       f0, -0x7A5C(r2)
	  lwz       r3, 0x4(r3)
	  stfs      f0, 0x30(r3)
	  b         .loc_0x414
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB47D0
	  b         .loc_0x414
	  lwz       r3, 0x2E78(r13)
	  bl        0x19BE14
	  li        r3, 0x6
	  li        r4, 0x1
	  bl        -0x3FD8C
	  b         .loc_0x414
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB4188
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  li        r0, 0x1
	  lis       r3, 0x803A
	  sth       r0, 0x1E6(r4)
	  subi      r3, r3, 0x24E0
	  li        r0, 0x2
	  stw       r0, 0x244(r3)
	  b         .loc_0x414
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stw       r7, 0x334(r3)
	  b         .loc_0x414
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB414C
	  b         .loc_0x414
	  bl        -0x2B5C

	.loc_0x414:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80059674
 * Size:	00004C
 */
void GameMovieInterface::parse(GameMovieInterface::ComplexMessage&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r10, r4, 0
	  stw       r0, 0x4(r1)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stwu      r1, -0x8(r1)
	  addi      r7, r10, 0xC
	  addi      r8, r10, 0x18
	  lwz       r4, 0x0(r4)
	  lwz       r3, 0x1DC(r3)
	  lwz       r5, 0x4(r10)
	  lwz       r6, 0x8(r10)
	  lwz       r9, 0x24(r10)
	  lbz       r10, 0x28(r10)
	  bl        0x1DAB4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800596C0
 * Size:	000724
 */
NewPikiGameSection::NewPikiGameSection()
{
	Node::init("<NewPikiGameSection>");
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stmw      r24, 0x38(r1)
	  addi      r30, r4, 0x7AE0
	  addi      r29, r3, 0
	  subi      r4, r13, 0x7204
	  bl        -0x24728
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  subi      r4, r13, 0x7204
	  bl        -0x18FBC
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x7D44
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0x74
	  bl        -0x18FE0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r27, r3, 0xA8
	  lwz       r4, 0xA8(r3)
	  lis       r3, 0x803A
	  subi      r25, r3, 0x2848
	  lhz       r3, 0x24(r4)
	  li        r0, -0x1
	  stw       r3, 0x1CC(r25)
	  stw       r0, 0x1D0(r25)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x26D28
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  addi      r3, r25, 0x2D8
	  lfs       f1, -0x7A58(r2)
	  bl        -0x7F44

	.loc_0xA4:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  li        r5, 0
	  stw       r5, 0x234(r3)
	  li        r0, 0x2
	  subi      r4, r13, 0x71FC
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x14(r3)
	  stw       r5, 0x2F00(r13)
	  lwz       r3, 0x2FE8(r13)
	  stw       r5, 0x2E58(r13)
	  bl        0x2CFA8
	  li        r3, 0x3E0
	  bl        -0x12794
	  mr.       r31, r3
	  beq-      .loc_0x6AC
	  mr        r3, r31
	  bl        -0x2924
	  lis       r3, 0x802A
	  addi      r0, r3, 0x7CBC
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x5C
	  bl        -0x165F8
	  lis       r3, 0x8003
	  subi      r25, r3, 0x3C8
	  addi      r4, r25, 0
	  addi      r3, r31, 0x3AC
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x2
	  bl        0x1BB294
	  addi      r4, r25, 0
	  addi      r3, r31, 0x3B4
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x2
	  bl        0x1BB27C
	  addi      r4, r25, 0
	  addi      r3, r31, 0x3BC
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x2
	  bl        0x1BB264
	  li        r3, 0xC
	  bl        -0x12810
	  cmplwi    r3, 0
	  beq-      .loc_0x184
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7F00
	  stw       r31, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x24(r31)
	  stw       r0, 0x8(r3)

	.loc_0x184:
	  stw       r3, 0x34(r31)
	  lis       r3, 0x803A
	  subi      r6, r3, 0x2848
	  lfs       f1, -0x7210(r13)
	  addi      r28, r6, 0x1DC
	  lfs       f0, -0x721C(r13)
	  li        r26, 0
	  stfs      f1, 0x24(r1)
	  lfs       f1, -0x720C(r13)
	  li        r0, 0x1
	  stfs      f0, 0x18(r1)
	  li        r3, 0x130
	  lfs       f0, -0x7218(r13)
	  stfs      f1, 0x28(r1)
	  lfs       f1, -0x7208(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x7214(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x20(r1)
	  lwz       r7, 0x1DC(r6)
	  stb       r26, 0x16C(r7)
	  lfs       f0, -0x7A54(r2)
	  stfs      f0, 0x160(r7)
	  lwz       r5, 0x18(r1)
	  lwz       r4, 0x1C(r1)
	  stw       r5, 0x148(r7)
	  stw       r4, 0x14C(r7)
	  lwz       r4, 0x20(r1)
	  stw       r4, 0x150(r7)
	  lwz       r5, 0x24(r1)
	  lwz       r4, 0x28(r1)
	  stw       r5, 0x154(r7)
	  stw       r4, 0x158(r7)
	  lwz       r4, 0x2C(r1)
	  stw       r4, 0x15C(r7)
	  stb       r26, 0x2E8D(r13)
	  stw       r26, 0x340(r6)
	  stb       r0, 0x3D4(r31)
	  bl        -0x128D8
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x290
	  addi      r3, r24, 0
	  subi      r4, r13, 0x7268
	  bl        -0x2493C
	  lis       r3, 0x802A
	  addi      r25, r3, 0x7C30
	  stw       r25, 0x0(r24)
	  addi      r3, r24, 0x48
	  subi      r4, r13, 0x7268
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x30(r24)
	  stfs      f0, 0x2C(r24)
	  stfs      f0, 0x28(r24)
	  stw       r26, 0x14(r24)
	  bl        -0x24968
	  stw       r25, 0x48(r24)
	  addi      r3, r24, 0x94
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x78(r24)
	  stfs      f0, 0x74(r24)
	  stfs      f0, 0x70(r24)
	  stw       r26, 0x5C(r24)
	  bl        -0x29CF8
	  addi      r3, r24, 0
	  li        r4, 0x42
	  bl        0x2404

	.loc_0x290:
	  li        r0, 0
	  stw       r24, 0x2EAC(r13)
	  lis       r3, 0x803A
	  stw       r0, 0x2E60(r13)
	  subi      r4, r3, 0x2848
	  li        r3, 0x50
	  sth       r0, 0x1E4(r4)
	  sth       r0, 0x1E6(r4)
	  stw       r0, 0x44(r31)
	  bl        -0x12970
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x300
	  addi      r3, r24, 0
	  addi      r4, r30, 0x1C
	  bl        -0x249D4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r24)
	  addi      r3, r24, 0
	  addi      r4, r30, 0x1C
	  bl        -0x19268
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r24)
	  addi      r3, r24, 0
	  li        r4, 0x2
	  bl        -0x1900C

	.loc_0x300:
	  stw       r24, 0x54(r31)
	  li        r26, 0
	  li        r3, 0x694
	  stw       r26, 0x38(r31)
	  stb       r26, 0x2E82(r13)
	  stb       r26, 0x2E81(r13)
	  bl        -0x129D4
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x36C
	  lis       r3, 0x802A
	  addi      r0, r3, 0x7BE0
	  lis       r3, 0x802A
	  stw       r0, 0x0(r24)
	  addi      r0, r3, 0x7DCC
	  lis       r3, 0x8006
	  stw       r0, 0x0(r24)
	  subi      r4, r3, 0x5F08
	  addi      r3, r24, 0x110
	  li        r5, 0
	  li        r6, 0x2C
	  li        r7, 0x20
	  bl        0x1BB058
	  li        r0, 0x20
	  stw       r0, 0x8(r24)
	  stw       r26, 0x10C(r24)
	  stw       r31, 0x4(r24)

	.loc_0x36C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stw       r24, 0x1E8(r3)
	  addi      r4, r30, 0x8C
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2CCF8
	  li        r3, 0x18
	  bl        -0x12A44
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x3A0
	  li        r4, 0x1388
	  bl        -0x24964

	.loc_0x3A0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stw       r24, 0x308(r3)
	  addi      r4, r30, 0x8C
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2CDD4
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  li        r0, 0
	  stw       r0, 0x240(r4)
	  lis       r25, 0x28
	  mr        r3, r25
	  stw       r0, 0x23C(r4)
	  stw       r0, 0x238(r4)
	  bl        -0x12A94
	  lwz       r4, 0x2DEC(r13)
	  addi      r6, r3, 0
	  addi      r7, r25, 0
	  addi      r3, r4, 0xF4
	  subi      r4, r13, 0x71F8
	  li        r5, 0x2
	  bl        -0x351AC
	  lis       r25, 0x4
	  addi      r3, r25, 0
	  bl        -0x12ABC
	  lwz       r4, 0x2DEC(r13)
	  addi      r6, r3, 0
	  addi      r7, r25, 0
	  addi      r3, r4, 0x11C
	  subi      r4, r13, 0x71F0
	  li        r5, 0x2
	  bl        -0x351D4
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71E8
	  bl        0x2CC50
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x98
	  bl        0x2CC44
	  li        r3, 0x4D4
	  bl        -0x12AF8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x454
	  lwz       r4, 0x24(r31)
	  bl        0xB2DC

	.loc_0x454:
	  stw       r24, 0x2F00(r13)
	  addi      r4, r30, 0x98
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2CD28
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71E0
	  bl        0x2CC0C
	  mr        r3, r31
	  lwz       r4, 0x2F00(r13)
	  bl        0x40C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71E0
	  bl        0x2CD04
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71E8
	  bl        0x2CCF8
	  lwz       r3, 0x0(r27)
	  lhz       r4, 0x26(r3)
	  cmplwi    r4, 0x5
	  bge-      .loc_0x4A8
	  b         .loc_0x4AC

	.loc_0x4A8:
	  li        r4, 0

	.loc_0x4AC:
	  li        r3, 0x5
	  bl        -0x402F0
	  mr        r3, r31
	  bl        .loc_0x724
	  li        r3, 0x348
	  bl        -0x12B7C
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x4E0
	  lwz       r4, 0x24(r31)
	  addi      r6, r31, 0x5C
	  lwz       r5, 0x2F00(r13)
	  bl        0xB62B0

	.loc_0x4E0:
	  stw       r24, 0x2E5C(r13)
	  mr        r3, r31
	  lwz       r4, 0x2E5C(r13)
	  bl        -0x195D4
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  li        r30, 0
	  stw       r30, 0x254(r4)
	  li        r3, 0x60
	  li        r0, 0x80
	  stw       r30, 0x258(r4)
	  li        r26, 0xFF
	  subi      r4, r13, 0x71D8
	  stb       r3, 0x3A8(r31)
	  stb       r0, 0x3A9(r31)
	  stb       r26, 0x3AA(r31)
	  stb       r30, 0x3AB(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2CB50
	  lwz       r3, 0x2F00(r13)
	  bl        0xB8C4
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71D8
	  bl        0x2CC4C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71E8
	  bl        0x2CB30
	  lwz       r3, 0x2F00(r13)
	  bl        0xBCB8
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71E8
	  bl        0x2CC2C
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB50F4
	  stb       r30, 0x3AC(r31)
	  li        r6, 0x30
	  li        r5, 0x40
	  stb       r30, 0x3AD(r31)
	  li        r3, 0xC0
	  li        r0, 0x1
	  stb       r6, 0x3AE(r31)
	  li        r4, 0x4
	  stb       r26, 0x3AF(r31)
	  stb       r6, 0x3B0(r31)
	  stb       r6, 0x3B1(r31)
	  stb       r6, 0x3B2(r31)
	  stb       r26, 0x3B3(r31)
	  stb       r30, 0x3B4(r31)
	  stb       r30, 0x3B5(r31)
	  stb       r30, 0x3B6(r31)
	  stb       r30, 0x3B7(r31)
	  stb       r5, 0x3B8(r31)
	  stb       r5, 0x3B9(r31)
	  stb       r3, 0x3BA(r31)
	  stb       r26, 0x3BB(r31)
	  stb       r30, 0x3BC(r31)
	  stb       r30, 0x3BD(r31)
	  stb       r30, 0x3BE(r31)
	  stb       r30, 0x3BF(r31)
	  stb       r3, 0x3C0(r31)
	  stb       r5, 0x3C1(r31)
	  stb       r30, 0x3C2(r31)
	  stb       r26, 0x3C3(r31)
	  lfs       f0, -0x7A50(r2)
	  stfs      f0, 0x3C4(r31)
	  lfs       f0, -0x7A4C(r2)
	  stfs      f0, 0x3C8(r31)
	  lfs       f0, -0x7A48(r2)
	  stfs      f0, 0x3CC(r31)
	  lfs       f0, -0x7A44(r2)
	  stfs      f0, 0x3D0(r31)
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r3, 0x1C
	  lwz       r3, 0x1C(r3)
	  stw       r0, 0x0(r5)
	  neg       r5, r3
	  subic     r0, r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r25, r0, r5
	  bl        -0x1ACBC
	  lwz       r3, 0x2DEC(r13)
	  rlwinm    r0,r25,0,24,31
	  stw       r0, 0x1C(r3)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x26784
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x664
	  lwz       r3, 0x0(r28)
	  li        r4, 0x3
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1D444
	  b         .loc_0x698

	.loc_0x664:
	  lwz       r3, 0x0(r27)
	  lhz       r0, 0x26(r3)
	  cmplwi    r0, 0x5
	  bge-      .loc_0x698
	  lwz       r3, 0x0(r28)
	  li        r4, 0x28
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1D40C

	.loc_0x698:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7A80(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7A68(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x6AC:
	  addi      r4, r31, 0
	  addi      r3, r29, 0
	  bl        -0x1979C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71FC
	  bl        0x2CAC8
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  addi      r4, r3, 0x1C
	  lwz       r3, 0x1C(r3)
	  stw       r0, 0x0(r4)
	  neg       r3, r3
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  lwz       r3, 0x2FE8(r13)
	  rlwinm    r26,r0,0,24,31
	  bl        0x2CB14
	  lwz       r3, 0x2DEC(r13)
	  stw       r26, 0x1C(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lmw       r24, 0x38(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x724:
	*/
}

/*
 * --INFO--
 * Address:	80059DE4
 * Size:	000160
 */
void NewPikiGameSetupSection::init2Ddata()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0x7AE0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  li        r3, 0x10
	  bl        -0x12E04
	  stw       r3, 0x58(r30)
	  addi      r4, r31, 0xA4
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1AD14
	  mr        r4, r3
	  lwz       r3, 0x58(r30)
	  li        r5, 0x15
	  li        r6, 0x2A
	  bl        -0x32178
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71D0
	  bl        0x2C8FC
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71CC
	  bl        0x2C8F0
	  li        r3, 0x58
	  bl        -0x12E4C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x80
	  bl        0x1284B8

	.loc_0x80:
	  stw       r30, 0x2E70(r13)
	  subi      r4, r13, 0x71CC
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2C9D8
	  li        r0, 0
	  lwz       r3, 0x2FE8(r13)
	  stw       r0, 0x2E74(r13)
	  addi      r4, r31, 0xB0
	  stw       r0, 0x2E78(r13)
	  stw       r0, 0x2E64(r13)
	  stw       r0, 0x2E7C(r13)
	  stw       r0, 0x2E88(r13)
	  stw       r0, 0x2E84(r13)
	  bl        0x2C8A0
	  li        r3, 0x1C
	  bl        -0x12E9C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xD0
	  bl        0x18EA50

	.loc_0xD0:
	  stw       r30, 0x2E68(r13)
	  addi      r4, r31, 0xB0
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2C988
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r31, 0xBC
	  bl        0x2C86C
	  li        r3, 0x38
	  bl        -0x12ED0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x104
	  bl        0x18DBCC

	.loc_0x104:
	  stw       r30, 0x2E6C(r13)
	  addi      r4, r31, 0xBC
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2C954
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x71D0
	  bl        0x2C948
	  lis       r3, 0x803A
	  lfs       f0, -0x7A40(r2)
	  subi      r4, r3, 0x2848
	  lwz       r3, 0x2E6C(r13)
	  lwz       r6, 0x20(r4)
	  li        r4, 0
	  lfs       f2, 0x90(r6)
	  lfs       f1, 0xB0(r6)
	  fsubs     f2, f2, f0
	  bl        0x18DD90
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
 * Address:	80059F44
 * Size:	0001B4
 */
void NewPikiGameSetupSection::createMapObjects(MapMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  mr        r28, r4
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x1AF40
	  lis       r3, 0x803A
	  lfs       f0, -0x7A80(r2)
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x304
	  stfs      f0, 0x304(r3)
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r4, 0x130
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x198
	  li        r3, 0x11C
	  bl        -0x12FA8
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x80
	  mr        r4, r30
	  bl        -0x19444

	.loc_0x80:
	  lis       r3, 0x803A
	  subi      r5, r3, 0x24E0
	  lis       r3, 0x802A
	  lis       r4, 0x802A
	  addi      r29, r26, 0
	  addi      r25, r5, 0xB0
	  addi      r27, r3, 0x7BB4
	  addi      r26, r4, 0x7BA8
	  b         .loc_0x148

	.loc_0xA4:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x18F40
	  addi      r3, r29, 0
	  addi      r4, r26, 0
	  bl        -0x18C28
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x18F60
	  addi      r5, r3, 0
	  crclr     6, 0x6
	  addi      r3, r25, 0
	  subi      r4, r13, 0x71C4
	  bl        0x1BC574
	  b         .loc_0x148

	.loc_0xE8:
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  bl        -0x18C60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x11C
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x18F98
	  crclr     6, 0x6
	  addi      r5, r31, 0
	  subi      r4, r13, 0x71C0
	  bl        0x1BE03C
	  b         .loc_0x148

	.loc_0x11C:
	  addi      r3, r29, 0
	  subi      r4, r13, 0x71BC
	  bl        -0x18C94
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x148
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x18FCC
	  lwz       r3, 0x4(r28)
	  mr        r4, r29
	  bl        0x14FE4

	.loc_0x148:
	  mr        r3, r29
	  bl        -0x19338
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x168
	  mr        r3, r29
	  bl        -0x18C18
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xA4

	.loc_0x168:
	  mr        r3, r29
	  bl        -0x19358
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x184
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x19014

	.loc_0x184:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x198:
	  mr        r3, r28
	  bl        0xB404
	  lmw       r25, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005A0F8
 * Size:	000020
 */
GameMovieInterface::ComplexMessage::ComplexMessage()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7A84(r2)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005A118
 * Size:	000004
 */
void GameInterface::movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool)
{
}

/*
 * --INFO--
 * Address:	8005A11C
 * Size:	000004
 */
void GameInterface::parseMessages()
{
}

/*
 * --INFO--
 * Address:	8005A120
 * Size:	000004
 */
void GameInterface::parse(int, int)
{
}

/*
 * --INFO--
 * Address:	8005A124
 * Size:	000054
 */
void NewPikiGameSetupSection::openMenu()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x50(r3)
	  stw       r0, 0x20(r3)
	  lwz       r3, 0x20(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r31)
	  li        r0, 0x1
	  stb       r0, 0x98(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005A178
 * Size:	000138
 */
void NewPikiGameSetupSection::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  lwz       r4, 0x3D8(r3)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  subi      r0, r4, 0x1
	  stw       r0, 0x3D8(r31)
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x1B19C
	  lwz       r4, 0x18(r3)
	  lwz       r0, 0x10(r3)
	  sub.      r0, r0, r4
	  beq-      .loc_0x94
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  li        r4, 0x5
	  addi      r6, r3, 0x1C
	  lwz       r3, 0x1C(r3)
	  li        r5, 0x1
	  stw       r0, 0x0(r6)
	  neg       r6, r3
	  subic     r0, r6, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r30, r0, r6
	  bl        -0x1B1C8
	  lwz       r3, 0x2DEC(r13)
	  rlwinm    r0,r30,0,24,31
	  stw       r0, 0x1C(r3)

	.loc_0x94:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x54(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x3D4(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xFC
	  lwz       r0, 0x38(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xE0
	  stw       r0, 0x34(r31)
	  li        r0, 0
	  stw       r0, 0x38(r31)

	.loc_0xE0:
	  lwz       r3, 0x34(r31)
	  addi      r4, r31, 0x3C
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r31)

	.loc_0xFC:
	  lwz       r3, 0x20(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r31)

	.loc_0x120:
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
 * Address:	8005A2B0
 * Size:	00000C
 */
void ModeState::update(u32&)
{
	/*
	.loc_0x0:
	  li        r0, 0x3
	  stw       r0, 0x0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005A2BC
 * Size:	00083C
 */
void NewPikiGameSetupSection::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x2A8(r1)
	  stmw      r25, 0x28C(r1)
	  addi      r27, r5, 0x338
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  lwz       r0, 0x338(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x3C
	  lwz       r0, 0x340(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x4C

	.loc_0x3C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  bl        0x1D584

	.loc_0x4C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r29, r3, 0x1DC
	  lwz       r3, 0x1DC(r3)
	  mr        r4, r31
	  bl        0x1DA00
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1A0
	  lwz       r6, 0x0(r29)
	  lfs       f2, -0x7A84(r2)
	  addi      r4, r6, 0x168
	  lfs       f3, 0x168(r6)
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0xEC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7A3C(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fsubs     f0, f3, f0
	  stfs      f0, 0x0(r4)
	  lwz       r3, 0x0(r29)
	  lfsu      f0, 0x168(r3)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0xB0
	  stfs      f2, 0x0(r3)

	.loc_0xB0:
	  lwz       r3, 0x30D8(r13)
	  lwz       r4, 0x0(r29)
	  lwz       r3, 0x20(r3)
	  lfs       f3, 0x144(r4)
	  lwz       r3, 0x4(r3)
	  lfs       f2, -0x7A80(r2)
	  lfs       f0, 0x1CC(r3)
	  lfs       f1, 0x168(r4)
	  fsubs     f0, f0, f3
	  lwz       r3, 0x2E4(r31)
	  fsubs     f1, f2, f1
	  fmuls     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x1CC(r3)
	  b         .loc_0x138

	.loc_0xEC:
	  lwz       r3, 0x30D8(r13)
	  li        r0, 0x1
	  lwz       r5, 0x20(r3)
	  lwz       r3, 0x4(r5)
	  lfs       f0, 0x1CC(r3)
	  stb       r0, 0x16C(r6)
	  stfs      f0, 0x160(r6)
	  lwz       r3, 0x8(r5)
	  lwz       r0, 0xC(r5)
	  stw       r3, 0x148(r6)
	  stw       r0, 0x14C(r6)
	  lwz       r0, 0x10(r5)
	  stw       r0, 0x150(r6)
	  lwz       r3, 0x14(r5)
	  lwz       r0, 0x18(r5)
	  stw       r3, 0x154(r6)
	  stw       r0, 0x158(r6)
	  lwz       r0, 0x1C(r5)
	  stw       r0, 0x15C(r6)

	.loc_0x138:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x5C
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x30C(r31)
	  lis       r4, 0x4330
	  lwz       r0, 0x310(r31)
	  addi      r3, r30, 0x5C
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x284(r1)
	  lfd       f5, -0x7A28(r2)
	  stw       r0, 0x27C(r1)
	  lfs       f2, 0x228(r30)
	  stw       r4, 0x280(r1)
	  lfs       f3, -0x7A38(r2)
	  stw       r4, 0x278(r1)
	  lfd       f1, 0x280(r1)
	  lfd       f0, 0x278(r1)
	  fsubs     f1, f1, f5
	  lfs       f4, 0x3A4(r30)
	  fsubs     f0, f0, f5
	  fdivs     f1, f1, f0
	  bl        -0x17804

	.loc_0x1A0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  addi      r28, r3, 0x1D8
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x1C8
	  lwz       r3, 0x2E5C(r13)
	  mr        r4, r31
	  lwz       r3, 0x64(r3)
	  bl        0xB724

	.loc_0x1C8:
	  lwz       r5, 0x310(r31)
	  li        r26, 0
	  lwz       r0, 0x30C(r31)
	  addi      r4, r1, 0x138
	  addi      r3, r31, 0
	  stw       r26, 0x138(r1)
	  stw       r26, 0x13C(r1)
	  stw       r0, 0x140(r1)
	  stw       r5, 0x144(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x148
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r26, 0x148(r1)
	  stw       r26, 0x14C(r1)
	  stw       r0, 0x150(r1)
	  stw       r5, 0x154(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r26, 0x158(r1)
	  addi      r4, r1, 0x158
	  addi      r3, r31, 0
	  stb       r26, 0x159(r1)
	  stb       r26, 0x15A(r1)
	  stb       r26, 0x15B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r5, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  lfs       f1, 0x1CC(r5)
	  addi      r4, r5, 0x260
	  lwz       r12, 0x3C(r12)
	  lfs       f2, 0x1C4(r5)
	  mtlr      r12
	  lfs       f3, 0x1D0(r5)
	  lfs       f4, 0x1D4(r5)
	  lfs       f5, -0x7A80(r2)
	  blrl
	  lwz       r0, 0x2E7C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x32C
	  lwz       r0, 0x0(r28)
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x32C
	  li        r25, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        0x25EF8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2E4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x1E4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x2E4
	  mr        r25, r26

	.loc_0x2E4:
	  rlwinm.   r0,r25,0,24,31
	  beq-      .loc_0x2FC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lfs       f1, 0x2F0(r3)
	  b         .loc_0x300

	.loc_0x2FC:
	  lfs       f1, -0x7A58(r2)

	.loc_0x300:
	  lwz       r3, 0x2F00(r13)
	  mr        r4, r31
	  li        r5, 0x8
	  lwz       r3, 0x4(r3)
	  bl        0x13F90
	  lfs       f0, -0x7A34(r2)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  stfs      f0, 0x3A4(r30)
	  bl        -0x19E10
	  b         .loc_0x390

	.loc_0x32C:
	  lwz       r3, 0x2F00(r13)
	  mr        r4, r31
	  lfs       f1, -0x7A30(r2)
	  li        r5, 0x8
	  lwz       r3, 0x4(r3)
	  bl        0x13F60
	  lwz       r3, 0x0(r29)
	  mr        r4, r31
	  bl        0x1D814
	  mr        r3, r31
	  lfs       f1, -0x7A80(r2)
	  bl        -0x30E38
	  lwz       r3, 0x0(r29)
	  mr        r4, r31
	  bl        0x1D85C
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x31F7C

	.loc_0x390:
	  lwz       r3, 0x3180(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x400
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x33C(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x3BC
	  lwz       r0, 0x0(r27)
	  cmpwi     r0, 0
	  beq-      .loc_0x3D0

	.loc_0x3BC:
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x340(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x3F4

	.loc_0x3D0:
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0x1
	  lwz       r0, 0x258(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x3E8
	  li        r5, 0

	.loc_0x3E8:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x3F4
	  bl        0x14228C

	.loc_0x3F4:
	  lwz       r3, 0x3180(r13)
	  mr        r4, r31
	  bl        0x1422FC

	.loc_0x400:
	  lwz       r0, 0x0(r28)
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x54C
	  li        r26, 0
	  stb       r26, 0x2E80(r13)
	  addi      r5, r1, 0x1E4
	  addi      r3, r31, 0
	  lwz       r6, 0x310(r31)
	  addi      r4, r1, 0x234
	  lwz       r0, 0x30C(r31)
	  stw       r26, 0x1E4(r1)
	  stw       r26, 0x1E8(r1)
	  stw       r0, 0x1EC(r1)
	  stw       r6, 0x1F0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r5, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  lfs       f3, -0x7A80(r2)
	  addi      r4, r5, 0x260
	  lwz       r12, 0x3C(r12)
	  fmr       f5, f3
	  lfs       f1, -0x7A54(r2)
	  mtlr      r12
	  lfs       f2, 0x1C4(r5)
	  lfs       f4, 0x1D4(r5)
	  blrl
	  lfs       f2, -0x7228(r13)
	  addi      r6, r1, 0x11C
	  lfs       f1, -0x7234(r13)
	  addi      r5, r1, 0x110
	  lfs       f0, -0x7240(r13)
	  stfs      f2, 0x11C(r1)
	  addi      r4, r1, 0x104
	  lfs       f2, -0x7224(r13)
	  addi      r3, r1, 0x84
	  stfs      f1, 0x110(r1)
	  lfs       f1, -0x7230(r13)
	  stfs      f0, 0x104(r1)
	  lfs       f0, -0x723C(r13)
	  stfs      f2, 0x120(r1)
	  lfs       f2, -0x7220(r13)
	  stfs      f1, 0x114(r1)
	  lfs       f1, -0x722C(r13)
	  stfs      f0, 0x108(r1)
	  lfs       f0, -0x7238(r13)
	  stfs      f2, 0x124(r1)
	  stfs      f1, 0x118(r1)
	  stfs      f0, 0x10C(r1)
	  bl        -0x1C698
	  li        r0, 0x700
	  stw       r0, 0x4(r31)
	  mr        r4, r31
	  lwz       r3, 0x34(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r31)
	  addi      r5, r1, 0x128
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r4, r1, 0xC4
	  stw       r26, 0x128(r1)
	  stw       r26, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  stw       r6, 0x134(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x20(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x54C
	  lwz       r3, 0x2E84(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x54C
	  mr        r4, r31
	  bl        0x1389CC
	  stb       r3, 0x2E80(r13)

	.loc_0x54C:
	  lwz       r6, 0x310(r31)
	  li        r26, 0
	  lwz       r0, 0x30C(r31)
	  addi      r5, r1, 0x1D4
	  addi      r3, r31, 0
	  stw       r26, 0x1D4(r1)
	  addi      r4, r1, 0x234
	  stw       r26, 0x1D8(r1)
	  stw       r0, 0x1DC(r1)
	  stw       r6, 0x1E0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r31)
	  addi      r5, r1, 0x1C4
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r4, r1, 0x234
	  stw       r26, 0x1C4(r1)
	  stw       r26, 0x1C8(r1)
	  stw       r0, 0x1CC(r1)
	  stw       r6, 0x1D0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5D0
	  lfs       f1, -0x7A80(r2)
	  mr        r4, r31
	  bl        0x3B88

	.loc_0x5D0:
	  lwz       r0, 0x20(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x5EC
	  lwz       r3, 0x0(r29)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x72C

	.loc_0x5EC:
	  lwz       r0, 0x2E64(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x63C
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x1B4
	  addi      r3, r31, 0
	  stw       r0, 0x1B4(r1)
	  addi      r4, r1, 0x234
	  stw       r0, 0x1B8(r1)
	  stw       r6, 0x1BC(r1)
	  stw       r7, 0x1C0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E64(r13)
	  mr        r4, r31
	  bl        0x194DE4

	.loc_0x63C:
	  lwz       r0, 0x2E74(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x68C
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x1A4
	  addi      r3, r31, 0
	  stw       r0, 0x1A4(r1)
	  addi      r4, r1, 0x234
	  stw       r0, 0x1A8(r1)
	  stw       r6, 0x1AC(r1)
	  stw       r7, 0x1B0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E74(r13)
	  mr        r4, r31
	  bl        0x12A658

	.loc_0x68C:
	  lwz       r0, 0x2E78(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x6DC
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x194
	  addi      r3, r31, 0
	  stw       r0, 0x194(r1)
	  addi      r4, r1, 0x234
	  stw       r0, 0x198(r1)
	  stw       r6, 0x19C(r1)
	  stw       r7, 0x1A0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E78(r13)
	  mr        r4, r31
	  bl        0x19A948

	.loc_0x6DC:
	  lwz       r0, 0x2E7C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x72C
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x184
	  addi      r3, r31, 0
	  stw       r0, 0x184(r1)
	  addi      r4, r1, 0x234
	  stw       r0, 0x188(r1)
	  stw       r6, 0x18C(r1)
	  stw       r7, 0x190(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E7C(r13)
	  mr        r4, r31
	  bl        0x138EFC

	.loc_0x72C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x3A54
	  lbz       r0, 0x3D4(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x800
	  lwz       r3, 0x2DEC(r13)
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x810
	  lwz       r0, 0x20(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x770
	  lwz       r3, 0x0(r29)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x810

	.loc_0x770:
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r0, 0x33C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x7D0
	  lwz       r0, 0x0(r27)
	  cmpwi     r0, 0
	  bne-      .loc_0x7D0
	  lwz       r3, 0x0(r29)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x7C8
	  lwz       r0, 0x3C(r30)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x7C8
	  lwz       r3, 0x2F6C(r13)
	  bl        0x25A08
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x7C8
	  addi      r3, r31, 0x2D8
	  lfs       f1, -0x7A80(r2)
	  bl        -0x91BC

	.loc_0x7C8:
	  mr        r3, r30
	  bl        -0x1A324

	.loc_0x7D0:
	  lwz       r3, 0x2E5C(r13)
	  lwz       r3, 0x344(r3)
	  bl        0x15DAEC
	  lwz       r0, 0x3C(r30)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x810
	  lwz       r0, 0x0(r28)
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x810
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB6030
	  b         .loc_0x810

	.loc_0x800:
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB4F2C
	  li        r0, 0
	  stb       r0, 0x3D4(r30)

	.loc_0x810:
	  lwz       r0, 0x38(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x828
	  stw       r0, 0x34(r30)
	  li        r0, 0
	  stw       r0, 0x38(r30)

	.loc_0x828:
	  lmw       r25, 0x28C(r1)
	  lwz       r0, 0x2AC(r1)
	  addi      r1, r1, 0x2A8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005AAF8
 * Size:	000004
 */
void ModeState::postRender(Graphics&)
{
}

/*
 * --INFO--
 * Address:	8005AAFC
 * Size:	000004
 */
void NewPikiGameSection::init()
{
}

/*
 * --INFO--
 * Address:	8005AB00
 * Size:	00003C
 */
void GameMovieInterface::message(int, int)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x10C(r3)
	  lwz       r0, 0x8(r3)
	  cmpw      r6, r0
	  bgelr-
	  rlwinm    r0,r6,3,0,28
	  add       r6, r3, r0
	  stw       r4, 0xC(r6)
	  lwz       r0, 0x10C(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r3, r0
	  stw       r5, 0x10(r4)
	  lwz       r4, 0x10C(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x10C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005AB3C
 * Size:	00011C
 */
void GameMovieInterface::movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool)
{
	/*
	.loc_0x0:
	  lwz       r11, 0x690(r3)
	  lwz       r0, 0x8(r3)
	  cmpw      r11, r0
	  bgelr-
	  mulli     r0, r11, 0x2C
	  add       r11, r3, r0
	  stw       r4, 0x110(r11)
	  cmplwi    r7, 0
	  lwz       r0, 0x690(r3)
	  mulli     r0, r0, 0x2C
	  add       r4, r3, r0
	  stw       r5, 0x114(r4)
	  lwz       r0, 0x690(r3)
	  mulli     r0, r0, 0x2C
	  add       r4, r3, r0
	  stw       r6, 0x118(r4)
	  bne-      .loc_0x70
	  lwz       r0, 0x690(r3)
	  lfs       f0, -0x7280(r13)
	  mulli     r4, r0, 0x2C
	  addi      r4, r4, 0x11C
	  add       r4, r3, r4
	  stfs      f0, 0x0(r4)
	  lfs       f0, -0x727C(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x7278(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x94

	.loc_0x70:
	  lwz       r0, 0x690(r3)
	  lwz       r4, 0x0(r7)
	  mulli     r5, r0, 0x2C
	  lwz       r0, 0x4(r7)
	  add       r5, r3, r5
	  stw       r4, 0x11C(r5)
	  stw       r0, 0x120(r5)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x124(r5)

	.loc_0x94:
	  cmplwi    r8, 0
	  bne-      .loc_0xC8
	  lwz       r0, 0x690(r3)
	  lfs       f0, -0x7274(r13)
	  mulli     r4, r0, 0x2C
	  addi      r4, r4, 0x128
	  add       r4, r3, r4
	  stfs      f0, 0x0(r4)
	  lfs       f0, -0x7270(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x726C(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0xEC

	.loc_0xC8:
	  lwz       r0, 0x690(r3)
	  lwz       r4, 0x0(r8)
	  mulli     r5, r0, 0x2C
	  lwz       r0, 0x4(r8)
	  add       r5, r3, r5
	  stw       r4, 0x128(r5)
	  stw       r0, 0x12C(r5)
	  lwz       r0, 0x8(r8)
	  stw       r0, 0x130(r5)

	.loc_0xEC:
	  lwz       r0, 0x690(r3)
	  mulli     r0, r0, 0x2C
	  add       r4, r3, r0
	  stw       r9, 0x134(r4)
	  lwz       r0, 0x690(r3)
	  mulli     r0, r0, 0x2C
	  add       r4, r3, r0
	  stb       r10, 0x138(r4)
	  lwz       r4, 0x690(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x690(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005AC58
 * Size:	0000C8
 */
void DayOverModeState::postRender(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  addi      r31, r4, 0
	  lwz       r0, 0x2E88(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x20
	  addi      r3, r31, 0
	  stw       r0, 0x20(r1)
	  addi      r4, r1, 0x30
	  stw       r0, 0x24(r1)
	  stw       r6, 0x28(r1)
	  stw       r7, 0x2C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E88(r13)
	  mr        r4, r31
	  bl        0x128018

	.loc_0x64:
	  lwz       r0, 0x2E68(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x10
	  addi      r3, r31, 0
	  stw       r0, 0x10(r1)
	  addi      r4, r1, 0x30
	  stw       r0, 0x14(r1)
	  stw       r6, 0x18(r1)
	  stw       r7, 0x1C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E68(r13)
	  mr        r4, r31
	  bl        0x18E90C

	.loc_0xB4:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005AD20
 * Size:	000078
 */
void MessageModeState::postRender(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  lwz       r0, 0x2E68(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x10
	  addi      r3, r31, 0
	  stw       r0, 0x10(r1)
	  addi      r4, r1, 0x20
	  stw       r0, 0x14(r1)
	  stw       r6, 0x18(r1)
	  stw       r7, 0x1C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E68(r13)
	  mr        r4, r31
	  bl        0x18E894

	.loc_0x64:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005AD98
 * Size:	00000C
 */
void QuittingGameModeState::update(u32&)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005ADA4
 * Size:	000074
 */
void QuittingGameModeState::postUpdate()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x2DEC(r13)
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x60
	  lwz       r3, 0x2E5C(r13)
	  bl        0xB3EBC
	  lwz       r4, 0x0(r31)
	  lis       r3, 0x803A
	  subi      r5, r3, 0x2848
	  lwz       r4, 0x40(r4)
	  li        r0, 0x6
	  li        r3, 0xD
	  stw       r4, 0x1F4(r5)
	  li        r4, 0
	  stw       r0, 0x1FC(r5)
	  bl        -0x41114
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  stb       r0, 0x0(r3)

	.loc_0x60:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005AE18
 * Size:	000004
 */
void BaseGameSection::openMenu()
{
}
