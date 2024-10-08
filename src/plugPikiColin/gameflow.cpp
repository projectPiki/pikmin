#include "gameflow.h"
#include "LoadIdler.h"
#include "WorldClock.h"
#include "Delegate.h"

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
 * Address:	80051478
 * Size:	000150
 */
void GameLoadIdler::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x30
	  stw       r0, 0x4(r1)
	  li        r0, 0xFF
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  li        r31, 0
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  addi      r29, r4, 0
	  stb       r3, 0x368(r4)
	  lis       r4, 0x803A
	  subi      r30, r4, 0x2848
	  stb       r3, 0x369(r29)
	  addi      r4, r1, 0x24
	  stb       r3, 0x36A(r29)
	  addi      r3, r29, 0
	  stb       r0, 0x36B(r29)
	  lwz       r5, 0x310(r29)
	  lwz       r0, 0x30C(r29)
	  stw       r31, 0x24(r1)
	  stw       r31, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  stw       r5, 0x30(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r29)
	  addi      r4, r1, 0x14
	  lwz       r0, 0x30C(r29)
	  mr        r3, r29
	  stw       r31, 0x14(r1)
	  stw       r31, 0x18(r1)
	  stw       r0, 0x1C(r1)
	  stw       r5, 0x20(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r29, 0
	  stb       r31, 0x11(r1)
	  stb       r31, 0x12(r1)
	  stb       r31, 0x13(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x310
	  lwz       r0, 0x310(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x134
	  addi      r4, r30, 0x314
	  lfs       f0, -0x7B08(r2)
	  lfs       f1, 0x314(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x314(r30)
	  lfs       f1, 0x314(r30)
	  lfs       f0, -0x7B04(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x11C
	  stfs      f0, 0x0(r4)

	.loc_0x11C:
	  lwz       r6, 0x0(r3)
	  mr        r3, r30
	  lfs       f1, 0x0(r4)
	  addi      r4, r29, 0
	  li        r5, 0x1
	  bl        .loc_0x150

	.loc_0x134:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x150:
	*/
}

/*
 * --INFO--
 * Address:	800515C8
 * Size:	000254
 */
void GameFlow::drawLoadLogo(Graphics&, bool, Texture*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  fmr       f31, f1
	  stmw      r27, 0xCC(r1)
	  mr.       r31, r6
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  beq-      .loc_0x23C
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x38
	  lfs       f1, -0x7B00(r2)
	  b         .loc_0x40

	.loc_0x38:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x28C(r3)

	.loc_0x40:
	  lfs       f0, 0x2E44(r13)
	  li        r27, 0
	  addi      r5, r1, 0x60
	  fadds     f0, f0, f1
	  addi      r3, r30, 0
	  addi      r4, r1, 0x74
	  stfs      f0, 0x2E44(r13)
	  lwz       r6, 0x310(r30)
	  lwz       r0, 0x30C(r30)
	  stw       r27, 0x60(r1)
	  stw       r27, 0x64(r1)
	  stw       r0, 0x68(r1)
	  stw       r6, 0x6C(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2D4(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x108
	  lfs       f0, -0x7AFC(r2)
	  li        r28, 0xDC
	  stb       r28, 0x5C(r1)
	  addi      r4, r1, 0x5C
	  fmuls     f0, f0, f31
	  stb       r27, 0x5D(r1)
	  mr        r3, r30
	  li        r5, 0x1
	  fctiwz    f31, f0
	  stb       r27, 0x5E(r1)
	  stfd      f31, 0xC0(r1)
	  lwz       r0, 0xC4(r1)
	  stb       r0, 0x5F(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x58(r1)
	  addi      r4, r1, 0x58
	  addi      r3, r30, 0
	  stb       r27, 0x59(r1)
	  stfd      f31, 0xB8(r1)
	  stb       r27, 0x5A(r1)
	  lwz       r0, 0xBC(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x184

	.loc_0x108:
	  lfs       f0, -0x7AFC(r2)
	  li        r28, 0xC0
	  stb       r28, 0x54(r1)
	  li        r0, 0x40
	  fmuls     f0, f0, f31
	  stb       r0, 0x55(r1)
	  addi      r4, r1, 0x54
	  mr        r3, r30
	  fctiwz    f31, f0
	  stb       r27, 0x56(r1)
	  li        r5, 0x1
	  stfd      f31, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stb       r0, 0x57(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stfd      f31, 0xC0(r1)
	  addi      r4, r1, 0x50
	  stb       r0, 0x50(r1)
	  mr        r3, r30
	  lwz       r0, 0xC4(r1)
	  stb       r28, 0x51(r1)
	  stb       r27, 0x52(r1)
	  stb       r0, 0x53(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl

	.loc_0x184:
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lhz       r8, 0x8(r31)
	  lwz       r0, 0x2D4(r29)
	  srawi     r6, r8, 0x1
	  lwz       r3, 0x30C(r30)
	  addze     r6, r6
	  lhz       r7, 0xA(r31)
	  srawi     r5, r3, 0x1
	  lwz       r3, 0x310(r30)
	  addze     r5, r5
	  srawi     r4, r7, 0x1
	  addze     r4, r4
	  srawi     r3, r3, 0x1
	  addze     r3, r3
	  cmpwi     r0, 0
	  sub       r9, r5, r6
	  sub       r10, r3, r4
	  beq-      .loc_0x1E8
	  subi      r10, r10, 0x28

	.loc_0x1E8:
	  li        r0, 0
	  stw       r0, 0x30(r1)
	  addi      r5, r1, 0x30
	  addi      r4, r1, 0x40
	  stw       r0, 0x34(r1)
	  mr        r3, r30
	  li        r6, 0
	  stw       r8, 0x38(r1)
	  stw       r7, 0x3C(r1)
	  lhz       r7, 0xA(r31)
	  lhz       r0, 0x8(r31)
	  add       r7, r10, r7
	  stw       r9, 0x40(r1)
	  add       r0, r9, r0
	  stw       r10, 0x44(r1)
	  stw       r0, 0x48(r1)
	  stw       r7, 0x4C(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl

	.loc_0x23C:
	  lmw       r27, 0xCC(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void WorldClock::setClockSpd(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005181C
 * Size:	0000A8
 */
void WorldClock::setTime(f32)
{
	/*
	.loc_0x0:
	  fctiwz    f0, f1
	  stwu      r1, -0x38(r1)
	  lis       r4, 0x4330
	  stfd      f0, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stfd      f0, 0x30(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x24(r1)
	  lwz       r0, 0x34(r1)
	  stw       r4, 0x20(r1)
	  stw       r0, 0x20(r3)
	  lfd       f0, 0x20(r1)
	  lfd       f3, -0x7AF0(r2)
	  lfs       f2, 0x0(r3)
	  fsubs     f0, f0, f3
	  fsubs     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x14(r3)
	  lfs       f2, -0x7AF8(r2)
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x14(r3)
	  fdivs     f1, f2, f1
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x28(r3)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x0(r3)
	  lwz       r0, 0x20(r3)
	  fdivs     f0, f1, f0
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x14(r1)
	  stw       r4, 0x10(r1)
	  lfd       f1, 0x10(r1)
	  fsubs     f1, f1, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x10(r3)
	  addi      r1, r1, 0x38
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void WorldClock::reset(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void WorldClock::age(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800518C4
 * Size:	0000F8
 */
void WorldClock::update(f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f2, 0x14(r3)
	  lfs       f0, 0x28C(r4)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x14(r3)
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x64
	  fsubs     f0, f0, f1
	  stfs      f0, 0x14(r3)
	  lwz       r4, 0x20(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x20(r3)
	  lwz       r4, 0x20(r3)
	  cmpwi     r4, 0x18
	  blt-      .loc_0x64
	  subi      r0, r4, 0x18
	  stw       r0, 0x20(r3)
	  lwz       r4, 0x24(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x24(r3)

	.loc_0x64:
	  lfs       f2, -0x7AF8(r2)
	  lis       r0, 0x4330
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x14(r3)
	  fdivs     f1, f2, f1
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r4, 0x2C(r1)
	  stw       r4, 0x28(r3)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x0(r3)
	  lwz       r4, 0x20(r3)
	  fdivs     f0, f1, f0
	  lfd       f2, -0x7AF0(r2)
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x24(r1)
	  stw       r0, 0x20(r1)
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  lfs       f1, 0x18(r3)
	  lfs       f0, 0x10(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r3)
	  lfs       f1, 0x1C(r3)
	  lfs       f0, -0x7AE8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xE8
	  lfs       f0, -0x7AE4(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r3)

	.loc_0xE8:
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x10(r3)
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800519BC
 * Size:	000090
 */
void GameFlow::menuToggleTimers(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0xAAAB
	  stw       r0, 0x4(r1)
	  subi      r0, r3, 0x5555
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  lwz       r5, 0x2DEC(r13)
	  lwzu      r3, 0x18(r5)
	  addi      r3, r3, 0x1
	  mulhwu    r0, r0, r3
	  rlwinm    r0,r0,31,1,31
	  mulli     r0, r0, 0x3
	  sub       r0, r3, r0
	  stw       r0, 0x0(r5)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x34(r3)
	  bl        -0x1107C
	  lwz       r3, 0x2DEC(r13)
	  lis       r4, 0x802A
	  lwz       r6, 0x30(r31)
	  lis       r5, 0x802A
	  lwz       r0, 0x18(r3)
	  lwz       r3, 0x18(r6)
	  addi      r4, r4, 0x6150
	  rlwinm    r6,r0,2,0,29
	  crclr     6, 0x6
	  addi      r0, r5, 0x6144
	  add       r5, r0, r6
	  lwz       r5, 0x0(r5)
	  bl        0x1C4B64
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051A4C
 * Size:	000060
 */
void GameFlow::menuTogglePrint(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x1C(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0x1C(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  subi      r5, r13, 0x7598
	  b         .loc_0x38

	.loc_0x34:
	  subi      r5, r13, 0x7590

	.loc_0x38:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x6164
	  crclr     6, 0x6
	  lwz       r3, 0x18(r6)
	  bl        0x1C4B00
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051AAC
 * Size:	000060
 */
void GameFlow::menuToggleDInfo(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x20(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0x20(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  subi      r5, r13, 0x7598
	  b         .loc_0x38

	.loc_0x34:
	  subi      r5, r13, 0x7590

	.loc_0x38:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x6174
	  crclr     6, 0x6
	  lwz       r3, 0x18(r6)
	  bl        0x1C4AA0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051B0C
 * Size:	000060
 */
void GameFlow::menuToggleDExtra(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x24(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0x24(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x24(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  subi      r5, r13, 0x7598
	  b         .loc_0x38

	.loc_0x34:
	  subi      r5, r13, 0x7590

	.loc_0x38:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x6184
	  crclr     6, 0x6
	  lwz       r3, 0x18(r6)
	  bl        0x1C4A40
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051B6C
 * Size:	000060
 */
void GameFlow::menuToggleBlur(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x28(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0x28(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  subi      r5, r13, 0x7598
	  b         .loc_0x38

	.loc_0x34:
	  subi      r5, r13, 0x7590

	.loc_0x38:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x6198
	  crclr     6, 0x6
	  lwz       r3, 0x18(r6)
	  bl        0x1C49E0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051BCC
 * Size:	000060
 */
void GameFlow::menuToggleInfo(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x2C(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x2C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  subi      r5, r13, 0x7598
	  b         .loc_0x38

	.loc_0x34:
	  subi      r5, r13, 0x7590

	.loc_0x38:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x61A8
	  crclr     6, 0x6
	  lwz       r3, 0x18(r6)
	  bl        0x1C4980
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051C2C
 * Size:	000060
 */
void GameFlow::menuToggleColls(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x30(r3)
	  xori      r0, r0, 0x1
	  stw       r0, 0x30(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  subi      r5, r13, 0x7598
	  b         .loc_0x38

	.loc_0x34:
	  subi      r5, r13, 0x7590

	.loc_0x38:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x61BC
	  crclr     6, 0x6
	  lwz       r3, 0x18(r6)
	  bl        0x1C4920
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0004DC
 */
void GameFlow::addOptionsMenu(Menu*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80051C8C
 * Size:	0000A0
 */
void GameFlow::menuChangeFilter(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x7578
	  stw       r0, 0x4(r1)
	  crclr     6, 0x6
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x350(r3)
	  lis       r3, 0x802A
	  addi      r3, r3, 0x6220
	  xori      r0, r0, 0x1
	  stw       r0, 0x350(r31)
	  lwz       r0, 0x350(r31)
	  lwz       r6, 0x30(r4)
	  addi      r4, r3, 0
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x18(r6)
	  lwzx      r5, r5, r0
	  bl        0x1C48C4
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x350(r31)
	  lwz       r3, 0x24C(r3)
	  rlwinm    r4,r0,3,0,28
	  lwz       r12, 0x3B4(r3)
	  addi      r4, r4, 0x354
	  add       r4, r31, r4
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x24C(r3)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	80051D2C
 * Size:	0000AC
 */
void GameFlow::menuIncreaseFilter(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r5, 0x30(r4)
	  lwz       r0, 0x1C(r5)
	  add       r5, r31, r0
	  lbzu      r3, 0x354(r5)
	  cmplwi    r3, 0x80
	  bge-      .loc_0x34
	  addi      r0, r3, 0x1
	  stb       r0, 0x0(r5)

	.loc_0x34:
	  lwz       r5, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x622C
	  crclr     6, 0x6
	  lwz       r0, 0x1C(r5)
	  lwz       r3, 0x18(r5)
	  add       r5, r31, r0
	  lbz       r5, 0x354(r5)
	  bl        0x1C4818
	  lwz       r0, 0x350(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x98
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r31, 0x354
	  lwz       r3, 0x24C(r3)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x24C(r3)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051DD8
 * Size:	0000AC
 */
void GameFlow::menuDecreaseFilter(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r5, 0x30(r4)
	  lwz       r0, 0x1C(r5)
	  add       r5, r31, r0
	  lbzu      r3, 0x354(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  subi      r0, r3, 0x1
	  stb       r0, 0x0(r5)

	.loc_0x34:
	  lwz       r5, 0x30(r4)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x622C
	  crclr     6, 0x6
	  lwz       r0, 0x1C(r5)
	  lwz       r3, 0x18(r5)
	  add       r5, r31, r0
	  lbz       r5, 0x354(r5)
	  bl        0x1C476C
	  lwz       r0, 0x350(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x98
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r31, 0x354
	  lwz       r3, 0x24C(r3)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x24C(r3)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000214
 */
void GameFlow::addFilterMenu(Menu*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80051E84
 * Size:	000024
 */
void GameFlow::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x20(r3)
	  bl        0xCD04
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051EA8
 * Size:	000144
 */
void preloadLanguage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  subi      r31, r4, 0x2848
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x38(r3)
	  bl        -0x11AF0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x7
	  lwz       r28, 0x194(r3)
	  bl        -0x12E7C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x7
	  li        r5, 0x2
	  bl        -0x12EC0
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x12EE0
	  lwz       r5, 0x2DEC(r13)
	  li        r4, 0
	  subi      r0, r13, 0x7570
	  addi      r7, r5, 0x31C
	  lwz       r3, 0x0(r7)
	  addi      r29, r31, 0x2A8
	  stw       r3, 0x4(r7)
	  lwz       r3, 0x2DEC(r13)
	  addi      r3, r3, 0x200
	  stw       r4, 0x10(r3)
	  stw       r4, 0xC(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x2DEC(r13)
	  addi      r0, r3, 0x200
	  stw       r0, 0x228(r3)
	  lwz       r3, 0x2DEC(r13)
	  addi      r0, r3, 0x31C
	  stw       r0, 0x328(r3)
	  lwz       r0, 0x2A8(r31)
	  lwz       r3, 0x2DEC(r13)
	  mulli     r0, r0, 0x14
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x24(r12)
	  add       r5, r31, r0
	  lwz       r4, 0x208(r5)
	  mtlr      r12
	  lwz       r5, 0x20C(r5)
	  blrl
	  lwz       r0, 0x0(r29)
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  mulli     r0, r0, 0x14
	  add       r4, r31, r0
	  lwz       r4, 0x210(r4)
	  bl        -0x121BC
	  lwz       r0, 0x0(r29)
	  lwz       r5, 0x2DEC(r13)
	  mulli     r0, r0, 0x14
	  add       r3, r31, r0
	  lwz       r4, 0x218(r3)
	  lwz       r0, 0x214(r3)
	  stw       r0, 0x44(r5)
	  stw       r4, 0x48(r5)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x12F9C
	  mr        r4, r28
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x12F60
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
 * Address:	80051FEC
 * Size:	00009C
 */
void GameFlow::setLoadBanner(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0x3
	  stw       r30, 0x10(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r30, 0x194(r3)
	  bl        -0x12FE0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x3
	  bl        -0x12FB8
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  bl        -0x12F28
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  addi      r31, r4, 0x318
	  stw       r3, 0x318(r4)
	  lwz       r3, 0x318(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r30
	  bl        -0x13000
	  lwz       r3, 0x0(r31)
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
 * Address:	80052088
 * Size:	00060C
 */
void GameFlow::hardReset(BaseApp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r10, -0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x16
	  stwu      r1, -0x148(r1)
	  stmw      r27, 0x134(r1)
	  li        r29, 0
	  addi      r31, r3, 0
	  stw       r4, 0x2E40(r13)
	  stw       r29, 0x1D4(r3)
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6128
	  stw       r29, 0x350(r31)
	  li        r3, 0x15
	  addi      r9, r30, 0x13C
	  stb       r29, 0x35C(r31)
	  addi      r8, r30, 0x154
	  addi      r7, r30, 0x174
	  stb       r29, 0x35D(r31)
	  addi      r6, r30, 0x190
	  addi      r5, r30, 0x1A0
	  stb       r3, 0x35E(r31)
	  addi      r4, r30, 0x1B0
	  stb       r0, 0x35F(r31)
	  addi      r0, r30, 0x1C0
	  stb       r3, 0x360(r31)
	  li        r3, 0xD8
	  stb       r29, 0x361(r31)
	  stb       r29, 0x362(r31)
	  stw       r10, 0x1EC(r31)
	  stw       r29, 0x1F0(r31)
	  stw       r29, 0x1F4(r31)
	  stw       r29, 0x200(r31)
	  stw       r29, 0x2AC(r31)
	  stw       r29, 0x2A8(r31)
	  stw       r9, 0x208(r31)
	  stw       r8, 0x20C(r31)
	  stw       r7, 0x210(r31)
	  stw       r6, 0x214(r31)
	  stw       r5, 0x218(r31)
	  stw       r9, 0x21C(r31)
	  stw       r8, 0x220(r31)
	  stw       r7, 0x224(r31)
	  stw       r6, 0x228(r31)
	  stw       r5, 0x22C(r31)
	  lwz       r5, 0x2DEC(r13)
	  stw       r4, 0x44(r5)
	  stw       r0, 0x48(r5)
	  bl        -0xB144
	  mr.       r28, r3
	  beq-      .loc_0x34C
	  stw       r29, 0x0(r28)
	  addi      r5, r1, 0x8C
	  addi      r4, r28, 0
	  lwz       r0, -0x756C(r13)
	  addi      r3, r28, 0x4
	  stw       r0, 0x98(r1)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x8C(r1)
	  bl        0xC90C
	  lis       r3, 0x802A
	  addi      r27, r3, 0x6098
	  stw       r27, 0xC(r28)
	  addi      r5, r1, 0x88
	  addi      r4, r28, 0
	  lfs       f0, -0x7AE0(r2)
	  addi      r3, r28, 0x14
	  stfs      f0, 0x10(r28)
	  lwz       r0, -0x7568(r13)
	  stw       r0, 0xA0(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r0, 0x88(r1)
	  bl        0xC8D8
	  stw       r27, 0x1C(r28)
	  addi      r5, r1, 0x84
	  addi      r4, r28, 0
	  lfs       f0, -0x7ADC(r2)
	  addi      r3, r28, 0x24
	  stfs      f0, 0x20(r28)
	  lwz       r0, -0x7564(r13)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x84(r1)
	  bl        0xC8AC
	  stw       r27, 0x2C(r28)
	  addi      r5, r1, 0x80
	  addi      r4, r28, 0
	  lfs       f0, -0x7AD8(r2)
	  addi      r3, r28, 0x34
	  stfs      f0, 0x30(r28)
	  lwz       r0, -0x7560(r13)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x80(r1)
	  bl        0xC880
	  stw       r27, 0x3C(r28)
	  addi      r5, r1, 0x7C
	  addi      r4, r28, 0
	  lfs       f0, -0x7AE0(r2)
	  addi      r3, r28, 0x44
	  stfs      f0, 0x40(r28)
	  lwz       r0, -0x755C(r13)
	  stw       r0, 0xB8(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x7C(r1)
	  bl        0xC854
	  stw       r27, 0x4C(r28)
	  addi      r5, r1, 0x78
	  addi      r4, r28, 0
	  lfs       f0, -0x7AD4(r2)
	  addi      r3, r28, 0x54
	  stfs      f0, 0x50(r28)
	  lwz       r0, -0x7558(r13)
	  stw       r0, 0xC0(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x78(r1)
	  bl        0xC828
	  stw       r27, 0x5C(r28)
	  addi      r5, r1, 0x74
	  addi      r4, r28, 0
	  lfs       f0, -0x7AD0(r2)
	  addi      r3, r28, 0x64
	  stfs      f0, 0x60(r28)
	  lwz       r0, -0x7554(r13)
	  stw       r0, 0xC8(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0x74(r1)
	  bl        0xC7FC
	  stw       r27, 0x6C(r28)
	  addi      r5, r1, 0x70
	  addi      r4, r28, 0
	  lfs       f0, -0x7ACC(r2)
	  addi      r3, r28, 0x74
	  stfs      f0, 0x70(r28)
	  lwz       r0, -0x7550(r13)
	  stw       r0, 0xD0(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x70(r1)
	  bl        0xC7D0
	  stw       r27, 0x7C(r28)
	  addi      r5, r1, 0x6C
	  addi      r4, r28, 0
	  lfs       f0, -0x7AC8(r2)
	  addi      r3, r28, 0x84
	  stfs      f0, 0x80(r28)
	  lwz       r0, -0x754C(r13)
	  stw       r0, 0xD8(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r0, 0x6C(r1)
	  bl        0xC7A4
	  stw       r27, 0x8C(r28)
	  addi      r5, r1, 0x68
	  addi      r4, r28, 0
	  lfs       f0, -0x7AC4(r2)
	  addi      r3, r28, 0x94
	  stfs      f0, 0x90(r28)
	  lwz       r0, -0x7548(r13)
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0x68(r1)
	  bl        0xC778
	  stw       r27, 0x9C(r28)
	  addi      r5, r1, 0x64
	  addi      r4, r28, 0
	  lfs       f0, -0x7AC0(r2)
	  addi      r3, r28, 0xA4
	  stfs      f0, 0xA0(r28)
	  lwz       r0, -0x7544(r13)
	  stw       r0, 0xE8(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r0, 0x64(r1)
	  bl        0xC74C
	  stw       r27, 0xAC(r28)
	  addi      r5, r1, 0x60
	  addi      r4, r28, 0
	  lfs       f0, -0x7AC8(r2)
	  addi      r3, r28, 0xB4
	  stfs      f0, 0xB0(r28)
	  lwz       r0, -0x7540(r13)
	  stw       r0, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0x60(r1)
	  bl        0xC720
	  lis       r3, 0x802A
	  addi      r0, r3, 0x60C4
	  stw       r0, 0xBC(r28)
	  li        r0, 0x1
	  addi      r5, r1, 0x5C
	  stw       r0, 0xC0(r28)
	  subi      r0, r13, 0x7538
	  addi      r4, r28, 0
	  lwz       r6, -0x753C(r13)
	  addi      r3, r28, 0xC4
	  stw       r0, 0x100(r1)
	  stw       r6, 0x128(r1)
	  lwz       r0, 0x128(r1)
	  stw       r29, 0xFC(r1)
	  stw       r0, 0x5C(r1)
	  bl        0xC6E0
	  lis       r3, 0x802A
	  addi      r0, r3, 0x606C
	  stw       r0, 0xCC(r28)
	  li        r3, 0x41
	  bl        -0x18D0
	  stw       r3, 0xD4(r28)
	  li        r0, 0x40
	  stw       r0, 0xD0(r28)
	  lwz       r3, 0xFC(r1)
	  lwz       r0, 0x100(r1)
	  stw       r3, 0xD0(r28)
	  stw       r0, 0xD4(r28)

	.loc_0x34C:
	  stw       r28, 0x20(r31)
	  lis       r3, 0x1
	  li        r27, 0
	  lwz       r4, 0x20(r31)
	  subi      r28, r3, 0x8000
	  lfs       f0, -0x7AE8(r2)
	  addi      r3, r31, 0x24
	  lfs       f1, 0x30(r4)
	  stfs      f0, 0x2EC(r31)
	  stfs      f0, 0x2E8(r31)
	  stw       r27, 0x2FC(r31)
	  stw       r27, 0x2F8(r31)
	  stw       r27, 0x300(r31)
	  lfs       f0, -0x7AE4(r2)
	  stfs      f0, 0x2DC(r31)
	  lfs       f0, -0x7AF8(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2E0(r31)
	  lfs       f1, 0x2E0(r31)
	  lfs       f0, 0x2DC(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  lfs       f0, -0x7B04(r2)
	  stfs      f0, 0x304(r31)
	  stw       r27, 0x2BC(r31)
	  bl        0x249C8
	  mr        r3, r28
	  bl        -0xB43C
	  lwz       r4, 0x2DEC(r13)
	  addi      r6, r3, 0
	  addi      r7, r28, 0
	  addi      r3, r4, 0xCC
	  subi      r4, r13, 0x7530
	  li        r5, 0x2
	  bl        -0x2DB54
	  stw       r27, 0x318(r31)
	  li        r4, 0x3
	  li        r5, 0x2
	  lwz       r3, 0x2DEC(r13)
	  lwz       r27, 0x194(r3)
	  bl        -0x13440
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x3
	  bl        -0x13418
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r30, 0x1D4
	  li        r5, 0x1
	  bl        -0x13388
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  addi      r28, r4, 0x318
	  stw       r3, 0x318(r4)
	  lwz       r3, 0x318(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x438
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x438:
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r27
	  bl        -0x13460
	  lwz       r0, 0x0(r28)
	  li        r3, 0
	  li        r4, 0
	  stw       r0, 0x310(r31)
	  lfs       f0, -0x7B04(r2)
	  stfs      f0, 0x314(r31)
	  bl        -0x38C64
	  li        r0, 0x1
	  stw       r0, 0x2D4(r31)
	  addi      r4, r31, 0x31C
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  li        r6, 0
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7AE8(r2)
	  li        r0, 0x2
	  addi      r3, r31, 0
	  stfs      f0, 0x2CC(r31)
	  addi      r5, r30, 0x1E8
	  subi      r4, r13, 0x7528
	  stfs      f0, 0x2C8(r31)
	  li        r6, 0x1
	  stfs      f0, 0x2C4(r31)
	  stw       r0, 0x2D0(r31)
	  bl        -0x11E98
	  li        r0, 0
	  stw       r0, 0x1D8(r31)
	  li        r3, 0x174
	  bl        -0xB544
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4D4
	  bl        0x248DC

	.loc_0x4D4:
	  stw       r27, 0x1DC(r31)
	  li        r3, 0x30
	  bl        -0xB560
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x500
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A504

	.loc_0x500:
	  stw       r27, 0x3178(r13)
	  lwz       r3, 0x3178(r13)
	  bl        0x12A618
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  bl        0x12ADC8
	  li        r0, 0x3
	  stw       r0, 0xAC(r31)
	  li        r0, 0x8
	  li        r27, 0
	  stb       r0, 0xB0(r31)
	  addi      r3, r31, 0xB8
	  stb       r0, 0xB1(r31)
	  stw       r27, 0x19C(r31)
	  stb       r27, 0xB2(r31)
	  stb       r27, 0xB4(r31)
	  stb       r27, 0xB5(r31)
	  stb       r27, 0xB3(r31)
	  stb       r27, 0xB6(r31)
	  stb       r27, 0xA8(r31)
	  bl        .loc_0x60C
	  li        r3, 0x30
	  bl        -0xB5DC
	  mr.       r28, r3
	  beq-      .loc_0x5D4
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r30, 0x1F8
	  stw       r27, 0x10(r28)
	  stw       r27, 0xC(r28)
	  stw       r27, 0x8(r28)
	  bl        -0x2D744
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r30, 0x1F8
	  bl        -0x11EF4
	  lis       r3, 0x802A
	  addi      r0, r3, 0x647C
	  stw       r0, 0x0(r28)
	  li        r0, 0x14C
	  li        r3, 0x20
	  stw       r0, 0x24(r28)
	  li        r0, 0x1
	  stw       r3, 0x20(r28)
	  stw       r0, 0x28(r28)
	  stw       r27, 0x2C(r28)

	.loc_0x5D4:
	  stw       r28, 0x30C(r31)
	  addi      r4, r30, 0x204
	  li        r5, 0
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x12898
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r30, 0x21C
	  li        r5, 0
	  bl        -0x128A8
	  lmw       r27, 0x134(r1)
	  lwz       r0, 0x14C(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr

	.loc_0x60C:
	*/
}

/*
 * --INFO--
 * Address:	80052694
 * Size:	0000C8
 */
void GameHiscores::Initialise()
{
	/*
	.loc_0x0:
	  li        r5, 0
	  stw       r5, 0x0(r3)
	  li        r4, 0x1E
	  li        r0, 0x270F
	  stw       r5, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r5, 0x2C(r3)
	  stw       r0, 0x40(r3)
	  stw       r5, 0x68(r3)
	  stw       r5, 0x68(r3)
	  stw       r5, 0x68(r3)
	  stw       r5, 0x68(r3)
	  stw       r5, 0x68(r3)
	  stw       r5, 0xC(r3)
	  stw       r4, 0x10(r3)
	  stw       r5, 0x30(r3)
	  stw       r0, 0x44(r3)
	  stw       r5, 0x7C(r3)
	  stw       r5, 0x7C(r3)
	  stw       r5, 0x7C(r3)
	  stw       r5, 0x7C(r3)
	  stw       r5, 0x7C(r3)
	  stw       r5, 0x14(r3)
	  stw       r4, 0x18(r3)
	  stw       r5, 0x34(r3)
	  stw       r0, 0x48(r3)
	  stw       r5, 0x90(r3)
	  stw       r5, 0x90(r3)
	  stw       r5, 0x90(r3)
	  stw       r5, 0x90(r3)
	  stw       r5, 0x90(r3)
	  stw       r5, 0x1C(r3)
	  stw       r4, 0x20(r3)
	  stw       r5, 0x38(r3)
	  stw       r0, 0x4C(r3)
	  stw       r5, 0xA4(r3)
	  stw       r5, 0xA4(r3)
	  stw       r5, 0xA4(r3)
	  stw       r5, 0xA4(r3)
	  stw       r5, 0xA4(r3)
	  stw       r5, 0x24(r3)
	  stw       r4, 0x28(r3)
	  stw       r5, 0x3C(r3)
	  stw       r0, 0x50(r3)
	  stw       r5, 0xB8(r3)
	  stw       r5, 0xB8(r3)
	  stw       r5, 0xB8(r3)
	  stw       r5, 0xB8(r3)
	  stw       r5, 0xB8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005275C
 * Size:	000548
 */
void GameFlow::softReset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stmw      r27, 0x7C(r1)
	  li        r29, 0
	  addi      r31, r3, 0
	  lwz       r4, 0x2DEC(r13)
	  lwz       r30, 0x1C(r4)
	  stw       r29, 0x1C(r4)
	  lwz       r3, 0x1F0(r31)
	  lwz       r0, 0x1EC(r31)
	  cmpw      r3, r0
	  beq-      .loc_0x2B0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  li        r5, 0x2
	  bl        -0x1376C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  bl        -0x1378C
	  li        r0, 0x2
	  stw       r0, 0x0(r3)
	  li        r4, 0x1
	  lwz       r3, 0x2E40(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  bl        -0x137B8
	  mr        r28, r3
	  lwz       r3, 0x8(r3)
	  lwz       r0, 0x4(r28)
	  sub       r0, r0, r3
	  subic.    r3, r0, 0x8
	  ble-      .loc_0x9C
	  b         .loc_0xA0

	.loc_0x9C:
	  mr        r3, r29

	.loc_0xA0:
	  lwz       r29, 0x0(r28)
	  li        r0, 0x2
	  addi      r27, r3, 0
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x8(r28)
	  lwz       r0, 0x4(r28)
	  sub       r0, r0, r3
	  subic.    r3, r0, 0x8
	  ble-      .loc_0xC8
	  b         .loc_0xCC

	.loc_0xC8:
	  li        r3, 0

	.loc_0xCC:
	  bl        -0xB824
	  stw       r29, 0x0(r28)
	  addi      r6, r3, 0
	  addi      r7, r27, 0
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0x2
	  addi      r3, r4, 0xA4
	  subi      r4, r13, 0x7520
	  bl        -0x2DF40
	  lwz       r3, 0x2E40(r13)
	  li        r4, 0x2
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x1384C
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x1F0(r31)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x244
	  bge-      .loc_0x144
	  cmpwi     r0, 0x1
	  beq-      .loc_0x190
	  bge-      .loc_0x1CC
	  cmpwi     r0, 0
	  bge-      .loc_0x154
	  b         .loc_0x29C

	.loc_0x144:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x280
	  bge-      .loc_0x29C
	  b         .loc_0x208

	.loc_0x154:
	  li        r3, 0x20
	  bl        -0xB8B0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x188
	  subi      r4, r13, 0x751C
	  bl        .loc_0x548
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x72D0
	  stw       r0, 0x0(r28)

	.loc_0x188:
	  stw       r28, 0x204(r31)
	  b         .loc_0x29C

	.loc_0x190:
	  li        r3, 0x20
	  bl        -0xB8EC
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x1C4
	  subi      r4, r13, 0x751C
	  bl        .loc_0x548
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x7478
	  stw       r0, 0x0(r28)

	.loc_0x1C4:
	  stw       r28, 0x204(r31)
	  b         .loc_0x29C

	.loc_0x1CC:
	  li        r3, 0x20
	  bl        -0xB928
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x200
	  subi      r4, r13, 0x751C
	  bl        .loc_0x548
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x352C
	  stw       r0, 0x0(r28)

	.loc_0x200:
	  stw       r28, 0x204(r31)
	  b         .loc_0x29C

	.loc_0x208:
	  li        r3, 0x20
	  bl        -0xB964
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x23C
	  subi      r4, r13, 0x751C
	  bl        .loc_0x548
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x6868
	  stw       r0, 0x0(r28)

	.loc_0x23C:
	  stw       r28, 0x204(r31)
	  b         .loc_0x29C

	.loc_0x244:
	  li        r3, 0x20
	  bl        -0xB9A0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x278
	  subi      r4, r13, 0x751C
	  bl        .loc_0x548
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x4FA0
	  stw       r0, 0x0(r28)

	.loc_0x278:
	  stw       r28, 0x204(r31)
	  b         .loc_0x29C

	.loc_0x280:
	  li        r3, 0x20
	  bl        -0xB9DC
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x298
	  bl        0x12BD4C

	.loc_0x298:
	  stw       r28, 0x204(r31)

	.loc_0x29C:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x139E0
	  li        r0, 0x2
	  stw       r0, 0x0(r3)

	.loc_0x2B0:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  li        r5, 0x2
	  bl        -0x139E4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        -0x13A04
	  li        r0, 0x2
	  stw       r0, 0x0(r3)
	  li        r4, 0x2
	  lwz       r3, 0x2E40(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        -0x13A30
	  lwz       r5, 0x8(r3)
	  lis       r4, 0x802A
	  lwz       r3, 0x4(r3)
	  lis       r0, 0x4330
	  addi      r4, r4, 0x6138
	  sub       r3, r3, r5
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x74(r1)
	  lwz       r3, 0x30C(r31)
	  stw       r0, 0x70(r1)
	  bl        -0x12340
	  lwz       r3, 0x2E40(r13)
	  lwz       r4, 0x30C(r31)
	  bl        -0x124B0
	  li        r28, 0
	  stw       r28, 0x308(r31)
	  li        r3, 0x28
	  bl        -0xBA94
	  cmplwi    r3, 0
	  beq-      .loc_0x394
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r3)
	  lis       r4, 0x8023
	  subi      r5, r13, 0x7514
	  stw       r28, 0x10(r3)
	  subi      r4, r4, 0x736C
	  li        r0, 0x1
	  stw       r28, 0xC(r3)
	  stw       r28, 0x8(r3)
	  stw       r5, 0x4(r3)
	  stw       r4, 0x0(r3)
	  stw       r28, 0x18(r3)
	  stw       r28, 0x1C(r3)
	  stw       r28, 0x20(r3)
	  stw       r0, 0x24(r3)

	.loc_0x394:
	  lwz       r5, 0x2DEC(r13)
	  li        r4, 0x100
	  stw       r3, 0x238(r5)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1311C
	  lwz       r3, 0x1DC(r31)
	  bl        0x243E8
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xDEFC
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  fmr       f31, f1
	  stw       r0, 0x23C(r3)
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x240(r3)
	  lwz       r0, 0x1F0(r31)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x40C
	  cmpwi     r0, 0x1
	  beq-      .loc_0x40C
	  cmpwi     r0, 0
	  beq-      .loc_0x40C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl

	.loc_0x40C:
	  lwz       r3, 0x2DEC(r13)
	  li        r28, 0
	  li        r4, 0x6
	  stw       r28, 0x250(r3)
	  stw       r28, 0x1E8(r31)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x13B60
	  stb       r28, 0x1D(r3)
	  lwz       r3, 0x204(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1F0(r31)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x468
	  cmpwi     r0, 0x1
	  beq-      .loc_0x468
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x468:
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xDFB4
	  lwz       r0, 0x2D0(r31)
	  fsubs     f2, f1, f31
	  cmpwi     r0, 0x1
	  bgt-      .loc_0x498
	  lfs       f1, -0x7ABC(r2)
	  lfs       f0, -0x7AB8(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4A4

	.loc_0x498:
	  lfs       f0, -0x7ABC(r2)
	  fdivs     f0, f2, f0
	  stfs      f0, 0x2C0(r31)

	.loc_0x4A4:
	  lfs       f0, -0x7AB4(r2)
	  li        r28, 0
	  li        r29, 0x1
	  stfs      f0, 0x2CC(r31)
	  li        r4, 0x2
	  lfs       f0, -0x7AFC(r2)
	  stfs      f0, 0x2C8(r31)
	  stw       r28, 0x2D0(r31)
	  lwz       r3, 0x2DEC(r13)
	  stw       r29, 0x1C(r3)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x13C0C
	  lwz       r5, 0x2DEC(r13)
	  lis       r0, 0x4330
	  lwz       r4, 0x8(r3)
	  lwz       r6, 0x240(r5)
	  lwz       r3, 0x4(r3)
	  stw       r6, 0x64(r1)
	  sub       r3, r3, r4
	  stw       r6, 0x6C(r1)
	  stw       r3, 0x74(r1)
	  stw       r30, 0x1C(r5)
	  stw       r0, 0x60(r1)
	  lwz       r3, 0x30C(r31)
	  stw       r0, 0x70(r1)
	  lwz       r4, 0x204(r31)
	  stw       r0, 0x68(r1)
	  bl        -0x12694
	  stw       r28, 0x33C(r31)
	  stw       r28, 0x338(r31)
	  stw       r28, 0x348(r31)
	  stw       r28, 0x34C(r31)
	  stw       r29, 0x334(r31)
	  lwz       r0, 0x1F0(r31)
	  stw       r0, 0x1EC(r31)
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lmw       r27, 0x7C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr

	.loc_0x548:
	*/
}

// /*
//  * --INFO--
//  * Address:	80052CA4
//  * Size:	00006C
//  */
// Node::Node(char* name)
// 	: CoreNode(name)
// {
// 	init(name);
// 	/*
// 	.loc_0x0:
// 	  mflr      r0
// 	  lis       r5, 0x8022
// 	  stw       r0, 0x4(r1)
// 	  addi      r0, r5, 0x738C
// 	  li        r5, 0
// 	  stwu      r1, -0x18(r1)
// 	  stw       r31, 0x14(r1)
// 	  addi      r31, r3, 0
// 	  lis       r3, 0x8022
// 	  stw       r0, 0x0(r31)
// 	  addi      r0, r3, 0x737C
// 	  lis       r3, 0x8023
// 	  stw       r0, 0x0(r31)
// 	  subi      r0, r3, 0x71E0
// 	  mr        r3, r31
// 	  stw       r5, 0x10(r31)
// 	  stw       r5, 0xC(r31)
// 	  stw       r5, 0x8(r31)
// 	  stw       r4, 0x4(r31)
// 	  stw       r0, 0x0(r31)
// 	  bl        -0x125B8
// 	  mr        r3, r31
// 	  lwz       r0, 0x1C(r1)
// 	  lwz       r31, 0x14(r1)
// 	  addi      r1, r1, 0x18
// 	  mtlr      r0
// 	  blr
// 	*/
// }

/*
 * --INFO--
 * Address:	80052D10
 * Size:	000024
 */
void* GameFlow::loadShape(char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x13B1C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80052D34
 * Size:	00002C
 */
void GameFlow::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3178(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C
	  bl        0x12A4AC

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80052D60
 * Size:	0000D0
 */
void GameFlow::addGenNode(char*, CoreNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r5, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  li        r3, 0x24
	  bl        -0xBD88
	  mr.       r31, r3
	  beq-      .loc_0xA4
	  cmplwi    r30, 0
	  beq-      .loc_0x44
	  b         .loc_0x48

	.loc_0x44:
	  lwz       r30, 0x4(r29)

	.loc_0x48:
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x10(r31)
	  addi      r4, r30, 0
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)
	  bl        -0x2DF04
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0x126B4
	  lis       r3, 0x802A
	  addi      r0, r3, 0x63B0
	  stw       r0, 0x0(r31)
	  stw       r29, 0x20(r31)

	.loc_0xA4:
	  lwz       r3, 0x30C(r28)
	  mr        r4, r31
	  bl        -0x12834
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80052E30
 * Size:	000060
 */
void GameGenFlow::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r4, 0x2848
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x2BC(r5)
	  addi      r0, r4, 0x1
	  stw       r0, 0x2BC(r5)
	  lwz       r4, 0x20(r5)
	  lfs       f1, 0x304(r5)
	  lfs       f0, 0x30(r4)
	  lfs       f2, -0x7AF8(r2)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x2E0(r5)
	  lfs       f1, 0x2E0(r5)
	  lfs       f0, 0x2DC(r5)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x2D8(r5)
	  bl        -0x12718
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80052E90
 * Size:	000004
 */
void GameLoadIdler::init() { }

/*
 * --INFO--
 * Address:	80052E94
 * Size:	000030
 */
void Delegate1<GameFlow, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1C1E84
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80052EC4
 * Size:	0001CC
 */
void __sinit_gameflow_cpp(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  lis       r4, 0x802A
	  stwu      r1, -0x20(r1)
	  stmw      r26, 0x8(r1)
	  subi      r27, r3, 0x2848
	  addi      r28, r4, 0x6128
	  addi      r3, r27, 0
	  subi      r4, r13, 0x751C
	  bl        -0x1DF34
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r27)
	  addi      r3, r27, 0
	  subi      r4, r13, 0x751C
	  bl        -0x127C8
	  addi      r0, r28, 0x450
	  lis       r3, 0x8022
	  stw       r0, 0x0(r27)
	  addi      r26, r27, 0x24
	  addi      r29, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r29, 0x24(r27)
	  addi      r30, r3, 0x737C
	  stw       r30, 0x24(r27)
	  li        r31, 0
	  addi      r3, r26, 0
	  stw       r31, 0x34(r27)
	  addi      r4, r28, 0x538
	  stw       r31, 0x30(r27)
	  stw       r31, 0x2C(r27)
	  bl        -0x2E070
	  lis       r3, 0x802A
	  addi      r0, r3, 0x66BC
	  stw       r0, 0x0(r26)
	  li        r5, -0x1
	  lis       r3, 0x2
	  stw       r5, 0x60(r27)
	  addi      r26, r27, 0x94
	  addi      r0, r3, 0x6000
	  stw       r5, 0x58(r27)
	  addi      r3, r26, 0
	  addi      r4, r28, 0x544
	  stw       r5, 0x5C(r27)
	  stw       r0, 0x64(r27)
	  stw       r31, 0x68(r27)
	  stw       r29, 0x94(r27)
	  stw       r30, 0x94(r27)
	  stw       r31, 0xA4(r27)
	  stw       r31, 0xA0(r27)
	  stw       r31, 0x9C(r27)
	  bl        -0x2E0C0
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6994
	  lis       r3, 0x8005
	  stw       r0, 0x0(r26)
	  addi      r4, r3, 0x3148
	  addi      r3, r27, 0xBC
	  li        r5, 0
	  li        r6, 0x8
	  li        r7, 0x5
	  bl        0x1C1AB4
	  lis       r3, 0x8005
	  addi      r4, r3, 0x313C
	  addi      r3, r27, 0xE4
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x5
	  bl        0x1C1A98
	  lis       r3, 0x8005
	  addi      r4, r3, 0x3130
	  addi      r3, r27, 0xF8
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x5
	  bl        0x1C1A7C
	  lis       r3, 0x8005
	  addi      r4, r3, 0x3114
	  addi      r3, r27, 0x10C
	  li        r5, 0
	  li        r6, 0x14
	  li        r7, 0x5
	  bl        0x1C1A60
	  mr        r3, r26
	  bl        .loc_0x1CC
	  addi      r26, r27, 0x1A4
	  stw       r29, 0x1A4(r27)
	  addi      r3, r26, 0
	  addi      r4, r28, 0x550
	  stw       r30, 0x1A4(r27)
	  stw       r31, 0x1B4(r27)
	  stw       r31, 0x1B0(r27)
	  stw       r31, 0x1AC(r27)
	  bl        -0x2E168
	  lis       r3, 0x802A
	  addi      r0, r3, 0x696C
	  stw       r0, 0x0(r26)
	  addi      r26, r27, 0x31C
	  li        r0, 0x1
	  stb       r31, 0x1C7(r27)
	  addi      r3, r26, 0
	  subi      r4, r13, 0x7570
	  stb       r0, 0x1C4(r27)
	  bl        -0x1E0AC
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6684
	  stw       r0, 0x0(r26)
	  addi      r0, r28, 0x520
	  stw       r0, 0x0(r26)
	  lwz       r0, 0x24(r1)
	  lmw       r26, 0x8(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x1CC:
	*/
}

/*
 * --INFO--
 * Address:	80053090
 * Size:	000084
 */
void GamePrefs::Initialise()
{
	/*
	.loc_0x0:
	  li        r0, 0x3
	  stw       r0, 0x18(r3)
	  li        r4, 0x8
	  li        r0, 0x5
	  stb       r4, 0x1C(r3)
	  addi      r9, r3, 0x24
	  mtctr     r0
	  li        r5, 0
	  stb       r4, 0x1D(r3)
	  mr        r8, r9
	  stw       r5, 0x108(r3)
	  li        r4, 0x1E
	  li        r0, 0x270F
	  stb       r5, 0x1E(r3)
	  stb       r5, 0x20(r3)
	  stb       r5, 0x21(r3)
	  stb       r5, 0x1F(r3)
	  stb       r5, 0x22(r3)
	  stb       r5, 0x14(r3)
	  stw       r5, 0x24(r3)

	.loc_0x50:
	  stw       r5, 0x4(r9)
	  stwu      r4, 0x8(r9)
	  stw       r5, 0x50(r3)
	  stw       r0, 0x64(r3)
	  addi      r3, r3, 0x4
	  stw       r5, 0x68(r8)
	  stw       r5, 0x68(r8)
	  stw       r5, 0x68(r8)
	  stw       r5, 0x68(r8)
	  stw       r5, 0x68(r8)
	  addi      r8, r8, 0x14
	  bdnz+     .loc_0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053114
 * Size:	00001C
 */
GameRecChalCourse::GameRecChalCourse()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x14(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053130
 * Size:	00000C
 */
GameRecDeadPikmin::GameRecDeadPikmin()
{
	/*
	.loc_0x0:
	  li        r0, 0x270F
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005313C
 * Size:	00000C
 */
GameRecBornPikmin::GameRecBornPikmin()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053148
 * Size:	000014
 */
GameRecMinDay::GameRecMinDay()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  li        r0, 0x1E
	  stw       r0, 0x4(r3)
	  blr
	*/
}
