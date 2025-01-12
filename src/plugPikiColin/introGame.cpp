#include "ModeState.h"
#include "IntroGameSection.h"
#include "system.h"
#include "MoviePlayer.h"
#include "MemStat.h"
#include "MapMgr.h"
#include "gameflow.h"
#include "Graphics.h"
#include "jaudio/PikiScene.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("introGame");

static IntroGameSetupSection* igss;

/*
 * --INFO--
 * Address:	8005AE1C
 * Size:	000298
 */
IntroGameSection::IntroGameSection()
{
	Node::init("<IntroGameSection>");
	gsys->setFrameClamp(2);

	mapMgr = nullptr;
	igss   = nullptr;

	gsys->startLoading(0, true, 60);
	igss = new IntroGameSetupSection();
	add(igss);

	/*
	.loc_0x0:
	  mflr      r0
	  subi      r4, r13, 0x70DC
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r27, 0x3C(r1)
	  addi      r29, r3, 0
	  bl        -0x25E7C
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  subi      r4, r13, 0x70DC
	  bl        -0x1A710
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x7EAC
	  lis       r3, 0x802A
	  stw       r0, 0x0(r29)
	  addi      r4, r3, 0x7F84
	  addi      r3, r29, 0
	  bl        -0x1A738
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  li        r0, 0
	  stw       r4, 0x14(r3)
	  li        r4, 0
	  li        r5, 0x1
	  stw       r0, 0x2F00(r13)
	  li        r6, 0x3C
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x2E90(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x3A8
	  bl        -0x13EB0
	  mr.       r31, r3
	  beq-      .loc_0x260
	  mr        r3, r31
	  bl        -0x4040
	  lis       r3, 0x802B
	  subi      r0, r3, 0x7F34
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x50
	  bl        -0x17D14
	  li        r3, 0xC
	  bl        -0x13EDC
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7ECC
	  stw       r0, 0x4(r3)
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7FF4
	  stw       r31, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x24(r31)
	  stw       r0, 0x8(r3)

	.loc_0xF4:
	  stw       r3, 0x34(r31)
	  lis       r3, 0x803A
	  subi      r8, r3, 0x2848
	  lfs       f1, -0x70E8(r13)
	  addi      r30, r8, 0x1DC
	  lfs       f0, -0x70F4(r13)
	  li        r7, 0
	  stfs      f1, 0x28(r1)
	  lfs       f1, -0x70E4(r13)
	  li        r0, 0x1
	  stfs      f0, 0x1C(r1)
	  li        r3, 0xB
	  lfs       f0, -0x70F0(r13)
	  stfs      f1, 0x2C(r1)
	  li        r4, 0
	  lfs       f1, -0x70E0(r13)
	  stfs      f0, 0x20(r1)
	  lfs       f0, -0x70EC(r13)
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r9, 0x1DC(r8)
	  stb       r7, 0x16C(r9)
	  lfs       f0, -0x7A20(r2)
	  stfs      f0, 0x160(r9)
	  lwz       r6, 0x1C(r1)
	  lwz       r5, 0x20(r1)
	  stw       r6, 0x148(r9)
	  stw       r5, 0x14C(r9)
	  lwz       r5, 0x24(r1)
	  stw       r5, 0x150(r9)
	  lwz       r6, 0x28(r1)
	  lwz       r5, 0x2C(r1)
	  stw       r6, 0x154(r9)
	  stw       r5, 0x158(r9)
	  lwz       r5, 0x30(r1)
	  stw       r5, 0x15C(r9)
	  stb       r0, 0x3A4(r31)
	  sth       r7, 0x1E4(r8)
	  stw       r7, 0x44(r31)
	  stw       r7, 0x38(r31)
	  bl        -0x41730
	  li        r3, 0x6B4
	  bl        -0x13FB4
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x1B0
	  bl        0x1411E4

	.loc_0x1B0:
	  li        r0, 0
	  stb       r0, 0x6B0(r28)
	  li        r3, 0x1418
	  bl        -0x13FD4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1D8
	  lwz       r5, 0x24(r31)
	  li        r4, 0
	  bl        0x104C4

	.loc_0x1D8:
	  lis       r28, 0x50
	  stw       r27, 0x39C(r31)
	  mr        r3, r28
	  bl        -0x13FFC
	  lwz       r4, 0x2DEC(r13)
	  addi      r6, r3, 0
	  addi      r7, r28, 0
	  addi      r3, r4, 0x11C
	  subi      r4, r13, 0x70D4
	  li        r5, 0x2
	  bl        -0x36714
	  lwz       r3, 0x0(r30)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1C120
	  lwz       r3, 0x0(r30)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  bl        0x1C0FC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7A1C(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7A18(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x260:
	  addi      r4, r31, 0
	  addi      r3, r29, 0
	  bl        -0x1AAAC
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lmw       r27, 0x3C(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005B0B4
 * Size:	000080
 */
void IntroModeState::update(u32& a2)
{
	a2 = 1;
	if (!gameflow.mMoviePlayer->_124) {
		PRINT("quitting!\n");
		// TODO: this has regswap issues.
		// return new QuittingModeState(_04);
	}
	// return this;
}

/*
 * --INFO--
 * Address:	8005B134
 * Size:	000004
 */
void IntroModeState::postRender(Graphics&)
{
}

/*
 * --INFO--
 * Address:	8005B138
 * Size:	00000C
 */
void QuittingModeState::update(u32& a)
{
	PRINT("quitter updating!\n");
	a = 0;
}

/*
 * --INFO--
 * Address:	8005B144
 * Size:	00005C
 */
void QuittingModeState::postUpdate()
{
	if (!gsys->getPending()) {
		PRINT("sending softreset!\n");

		memStat->reset();
		gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
#ifdef __MWERKS__
		Jac_SceneExit(13, 0);
#endif
		gsys->softReset();
	}
}

/*
 * --INFO--
 * Address:	8005B1A0
 * Size:	000030
 */
void IntroGameSetupSection::update()
{
	mController->update();
}

/*
 * --INFO--
 * Address:	8005B1D0
 * Size:	0004BC
 */
void IntroGameSetupSection::draw(Graphics& gfx)
{
	gameflow.mMoviePlayer->update();
	if (!gameflow.mMoviePlayer->setCamera(gfx)) {
		gfx.setCamera(&_50);
		_50.update(gfx.mScreenWidth / gfx.mScreenHeight, gfx.mScreenHeight, 100.0f, _398);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x180(r1)
	  stw       r31, 0x17C(r1)
	  addi      r31, r5, 0x1DC
	  stw       r30, 0x178(r1)
	  mr        r30, r4
	  stw       r29, 0x174(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x170(r1)
	  lwz       r3, 0x1DC(r5)
	  bl        0x1C684
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  bl        0x1CB0C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB4
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0x50
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x30C(r30)
	  lis       r4, 0x4330
	  lwz       r0, 0x310(r30)
	  addi      r3, r29, 0x50
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x16C(r1)
	  lfd       f5, -0x7A08(r2)
	  stw       r0, 0x164(r1)
	  lfs       f2, 0x21C(r29)
	  stw       r4, 0x168(r1)
	  lfs       f3, -0x7A14(r2)
	  stw       r4, 0x160(r1)
	  lfd       f1, 0x168(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f5
	  lfs       f4, 0x398(r29)
	  fsubs     f0, f0, f5
	  fdivs     f1, f1, f0
	  bl        -0x1862C

	.loc_0xB4:
	  lwz       r5, 0x310(r30)
	  li        r28, 0
	  lwz       r0, 0x30C(r30)
	  addi      r4, r1, 0xC8
	  addi      r3, r30, 0
	  stw       r28, 0xC8(r1)
	  stw       r28, 0xCC(r1)
	  stw       r0, 0xD0(r1)
	  stw       r5, 0xD4(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r30)
	  addi      r4, r1, 0xD8
	  lwz       r0, 0x30C(r30)
	  mr        r3, r30
	  stw       r28, 0xD8(r1)
	  stw       r28, 0xDC(r1)
	  stw       r0, 0xE0(r1)
	  stw       r5, 0xE4(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0xE8(r1)
	  addi      r4, r1, 0xE8
	  addi      r3, r30, 0
	  stb       r28, 0xE9(r1)
	  stb       r28, 0xEA(r1)
	  stb       r28, 0xEB(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r5, 0x2E4(r30)
	  lwz       r12, 0x3B4(r30)
	  lfs       f1, 0x1CC(r5)
	  addi      r4, r5, 0x260
	  lwz       r12, 0x3C(r12)
	  lfs       f2, 0x1C4(r5)
	  mtlr      r12
	  lfs       f3, 0x1D0(r5)
	  lfs       f4, 0x1D4(r5)
	  lfs       f5, -0x7A1C(r2)
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  subi      r28, r4, 0x77C0
	  lwz       r12, 0x74(r12)
	  addi      r4, r28, 0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x39C(r29)
	  mr        r4, r30
	  lfs       f1, -0x7A10(r2)
	  li        r5, 0x8
	  bl        0x131CC
	  lwz       r3, 0x39C(r29)
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        0x13BF4
	  mr        r3, r30
	  lfs       f1, -0x7A1C(r2)
	  bl        -0x31BD0
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  bl        0x1CAC4
	  lwz       r12, 0x3B4(r30)
	  mr        r3, r30
	  mr        r4, r28
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  bl        -0x32D10
	  lwz       r3, 0x3180(r13)
	  lwz       r5, 0x2DEC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x26C
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x33C(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x260
	  lwz       r0, 0x338(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x260
	  lwz       r0, 0x258(r5)
	  li        r4, 0x1
	  cmpwi     r0, 0
	  blt-      .loc_0x254
	  li        r4, 0

	.loc_0x254:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x260
	  bl        0x14150C

	.loc_0x260:
	  mr        r4, r30
	  lwz       r3, 0x3180(r13)
	  bl        0x14157C

	.loc_0x26C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x398
	  lwz       r6, 0x310(r30)
	  li        r28, 0
	  lwz       r0, 0x30C(r30)
	  addi      r5, r1, 0x10C
	  addi      r3, r30, 0
	  stw       r28, 0x10C(r1)
	  addi      r4, r1, 0x11C
	  stw       r28, 0x110(r1)
	  stw       r0, 0x114(r1)
	  stw       r6, 0x118(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r5, 0x2E4(r30)
	  lwz       r12, 0x3B4(r30)
	  lfs       f3, -0x7A1C(r2)
	  addi      r4, r5, 0x260
	  lwz       r12, 0x3C(r12)
	  fmr       f5, f3
	  lfs       f1, -0x7A20(r2)
	  mtlr      r12
	  lfs       f2, 0x1C4(r5)
	  lfs       f4, 0x1D4(r5)
	  blrl
	  lfs       f2, -0x7100(r13)
	  addi      r6, r1, 0xAC
	  lfs       f1, -0x710C(r13)
	  addi      r5, r1, 0xA0
	  lfs       f0, -0x7118(r13)
	  stfs      f2, 0xAC(r1)
	  addi      r4, r1, 0x94
	  lfs       f2, -0x70FC(r13)
	  addi      r3, r1, 0x14
	  stfs      f1, 0xA0(r1)
	  lfs       f1, -0x7108(r13)
	  stfs      f0, 0x94(r1)
	  lfs       f0, -0x7114(r13)
	  stfs      f2, 0xB0(r1)
	  lfs       f2, -0x70F8(r13)
	  stfs      f1, 0xA4(r1)
	  lfs       f1, -0x7104(r13)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x7110(r13)
	  stfs      f2, 0xB4(r1)
	  stfs      f1, 0xA8(r1)
	  stfs      f0, 0x9C(r1)
	  bl        -0x1D41C
	  li        r0, 0x700
	  stw       r0, 0x4(r30)
	  mr        r4, r30
	  lwz       r3, 0x34(r29)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r30)
	  addi      r5, r1, 0xB8
	  lwz       r0, 0x30C(r30)
	  mr        r3, r30
	  addi      r4, r1, 0x54
	  stw       r28, 0xB8(r1)
	  stw       r28, 0xBC(r1)
	  stw       r0, 0xC0(r1)
	  stw       r6, 0xC4(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x398:
	  lwz       r6, 0x310(r30)
	  li        r28, 0
	  lwz       r0, 0x30C(r30)
	  addi      r5, r1, 0xFC
	  addi      r3, r30, 0
	  stw       r28, 0xFC(r1)
	  addi      r4, r1, 0x11C
	  stw       r28, 0x100(r1)
	  stw       r0, 0x104(r1)
	  stw       r6, 0x108(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r30)
	  addi      r5, r1, 0xEC
	  lwz       r0, 0x30C(r30)
	  mr        r3, r30
	  addi      r4, r1, 0x11C
	  stw       r28, 0xEC(r1)
	  stw       r28, 0xF0(r1)
	  stw       r0, 0xF4(r1)
	  stw       r6, 0xF8(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x4640
	  lbz       r0, 0x3A4(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x480
	  lwz       r3, 0x2DEC(r13)
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x484
	  lwz       r0, 0x20(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x448
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x484

	.loc_0x448:
	  lwz       r0, 0x38(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  stw       r0, 0x34(r29)
	  li        r0, 0
	  stw       r0, 0x38(r29)

	.loc_0x460:
	  lwz       r3, 0x34(r29)
	  addi      r4, r29, 0x3C
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r29)
	  b         .loc_0x484

	.loc_0x480:
	  stb       r28, 0x3A4(r29)

	.loc_0x484:
	  lwz       r0, 0x38(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x49C
	  stw       r0, 0x34(r29)
	  li        r0, 0
	  stw       r0, 0x38(r29)

	.loc_0x49C:
	  lwz       r0, 0x184(r1)
	  lwz       r31, 0x17C(r1)
	  lwz       r30, 0x178(r1)
	  lwz       r29, 0x174(r1)
	  lwz       r28, 0x170(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005B68C
 * Size:	000004
 */
void IntroGameSection::init()
{
}
