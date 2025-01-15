#include "App.h"
#include "timers.h"
#include "Graphics.h"
#include "gameflow.h"
#include "AtxStream.h"

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
 * Address:	8005EDF0
 * Size:	000160
 */
void PlugPikiApp::hardReset()
{
	useHeap(0);
	gsys->mTimer = new Timers;
	gameflow.hardReset(this);
	AyuHeap* heap = gsys->getHeap(0);

	heap = gsys->getHeap(1);
	heap->init("ovl", 2, 0, 0);

	gsys->resetHeap(1, 1);
	gsys->getHeap(1)->mAllocType = 1;
	useHeap(1);
	gsys->softReset();

	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  stw       r28, 0x30(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0xC
	  bl        -0x17E24
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  li        r4, 0
	  stw       r4, 0x0(r3)
	  li        r0, -0x1
	  stw       r4, 0x8(r3)
	  stw       r0, 0x4(r3)

	.loc_0x58:
	  lwz       r5, 0x2DEC(r13)
	  lis       r4, 0x803A
	  subi      r0, r4, 0x2848
	  stw       r3, 0x34(r5)
	  mr        r3, r0
	  addi      r4, r31, 0
	  bl        -0xCDD8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  bl        -0x1FE4C
	  mr        r30, r3
	  lwz       r3, 0x8(r3)
	  lwz       r0, 0x4(r30)
	  sub       r0, r0, r3
	  subic.    r3, r0, 0x8
	  ble-      .loc_0x9C
	  b         .loc_0xA0

	.loc_0x9C:
	  li        r3, 0

	.loc_0xA0:
	  lwz       r29, 0x0(r30)
	  li        r0, 0x2
	  addi      r28, r3, 0
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x8(r30)
	  lwz       r0, 0x4(r30)
	  sub       r0, r0, r3
	  subic.    r3, r0, 0x8
	  ble-      .loc_0xC8
	  b         .loc_0xCC

	.loc_0xC8:
	  li        r3, 0

	.loc_0xCC:
	  bl        -0x17EB8
	  stw       r29, 0x0(r30)
	  mr        r0, r3
	  mr        r29, r0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  bl        -0x1FEB4
	  addi      r6, r29, 0
	  addi      r7, r28, 0
	  subi      r4, r13, 0x6EE8
	  li        r5, 0x2
	  bl        -0x3A5E0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        -0x1FEC4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  bl        -0x1FEE4
	  li        r30, 0x1
	  stw       r30, 0x0(r3)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  stb       r30, 0x0(r3)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EF50
 * Size:	000040
 */
void PlugPikiApp::softReset()
{
	BaseApp::softReset();
	gameflow.softReset();
	_2C = 1;
}

/*
 * --INFO--
 * Address:	8005EF90
 * Size:	00004C
 */
void PlugPikiApp::update()
{
	gameflow._2D0++;
	gameflow.update();
	Node::update();
}

/*
 * --INFO--
 * Address:	8005EFDC
 * Size:	0004BC
 */
void PlugPikiApp::draw(Graphics& gfx)
{
	if (!_2C) {
		return;
	}

	gsys->mDispCount     = 0;
	gsys->mMaterialCount = 0;
	gsys->_1A4           = 0;
	gsys->_1B4           = 0;
	gsys->mLightCount    = 0;
	gsys->mLoadedPolys   = 0;
	gsys->mLightingSkips = 0;
	gsys->mLightingSets  = 0;
	gsys->mSystemState   = 0;
	Node::draw(gfx);

	Mtx mtx;
	RectArea area(0, 0, gfx.mScreenWidth, gfx.mScreenHeight);
	gfx.setOrthogonal(mtx, area);
	gfx.useTexture(nullptr, 0);

	if (gsys->mTimerState) {
		Colour color(255, 255, 255, 255);
		gfx.setColour(color, true);
		gfx.texturePrintf(gsys->mConsFont, 32, 32, "%d polys = %d pps", gsys->_1A4, gsys->_1A4 * gsys->_290);
		gfx.texturePrintf(gsys->mConsFont, 32, 44, "%d anims", gsys->mLoadedPolys);
		gfx.texturePrintf(gsys->mConsFont, 32, 56, "%d mats", gsys->mMaterialCount);
		gfx.texturePrintf(gsys->mConsFont, 32, 68, "%d disps", gsys->mDispCount);
		gfx.texturePrintf(gsys->mConsFont, 32, 80, "%d mtxs", gsys->mGfx->mMatrixBuffer);
		gfx.texturePrintf(gsys->mConsFont, 32, 92, "%d / %d lighting skips / sets", gsys->mLightingSkips, gsys->mLightingSets);
		gfx.texturePrintf(gsys->mConsFont, 32, 104, "%d light sets", gsys->mSystemState);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1D8(r1)
	  stmw      r27, 0x1C4(r1)
	  addi      r29, r4, 0
	  subi      r31, r5, 0x7950
	  lwz       r0, 0x2C(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x4A8
	  lwz       r4, 0x2DEC(r13)
	  li        r27, 0
	  stw       r27, 0x1AC(r4)
	  mr        r4, r29
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1A8(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1A4(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1B4(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1B0(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1B8(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1BC(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1C0(r5)
	  lwz       r5, 0x2DEC(r13)
	  stw       r27, 0x1C4(r5)
	  bl        -0x1E884
	  lwz       r6, 0x310(r29)
	  addi      r5, r1, 0x60
	  lwz       r0, 0x30C(r29)
	  mr        r3, r29
	  addi      r4, r1, 0x170
	  stw       r27, 0x60(r1)
	  stw       r27, 0x64(r1)
	  stw       r0, 0x68(r1)
	  stw       r6, 0x6C(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x294
	  li        r0, 0xFF
	  stb       r0, 0x5C(r1)
	  addi      r4, r1, 0x5C
	  addi      r3, r29, 0
	  stb       r0, 0x5D(r1)
	  li        r5, 0x1
	  stb       r0, 0x5E(r1)
	  stb       r0, 0x5F(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x2DEC(r13)
	  lis       r0, 0x4330
	  lwz       r12, 0x3B4(r29)
	  mr        r3, r29
	  lwz       r8, 0x1A4(r5)
	  lwz       r12, 0xEC(r12)
	  addi      r7, r31, 0x1C
	  xoris     r4, r8, 0x8000
	  lfd       f1, -0x7938(r2)
	  stw       r4, 0x1BC(r1)
	  lfs       f2, 0x290(r5)
	  mtlr      r12
	  stw       r0, 0x1B8(r1)
	  li        r6, 0x20
	  lwz       r4, 0x10(r5)
	  lfd       f0, 0x1B8(r1)
	  crclr     6, 0x6
	  li        r5, 0x20
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x1B0(r1)
	  lwz       r9, 0x1B4(r1)
	  blrl
	  mr        r3, r29
	  lwz       r5, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r29)
	  addi      r7, r31, 0x30
	  lwz       r4, 0x10(r5)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  lwz       r8, 0x1B8(r5)
	  li        r5, 0x20
	  mtlr      r12
	  li        r6, 0x2C
	  blrl
	  mr        r3, r29
	  lwz       r6, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r29)
	  crclr     6, 0x6
	  lwz       r4, 0x10(r6)
	  li        r5, 0x20
	  lwz       r12, 0xEC(r12)
	  lwz       r8, 0x1A8(r6)
	  li        r6, 0x38
	  mtlr      r12
	  subi      r7, r13, 0x6EE4
	  blrl
	  mr        r3, r29
	  lwz       r5, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r29)
	  addi      r7, r31, 0x3C
	  lwz       r4, 0x10(r5)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  lwz       r8, 0x1AC(r5)
	  li        r5, 0x20
	  mtlr      r12
	  li        r6, 0x44
	  blrl
	  mr        r3, r29
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r29)
	  crclr     6, 0x6
	  lwz       r7, 0x24C(r4)
	  li        r5, 0x20
	  lwz       r12, 0xEC(r12)
	  lwz       r4, 0x10(r4)
	  li        r6, 0x50
	  mtlr      r12
	  lwz       r8, 0x38C(r7)
	  subi      r7, r13, 0x6EDC
	  blrl
	  mr        r3, r29
	  lwz       r6, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r29)
	  addi      r7, r31, 0x48
	  lwz       r4, 0x10(r6)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  lwz       r8, 0x1BC(r6)
	  li        r5, 0x20
	  mtlr      r12
	  lwz       r9, 0x1C0(r6)
	  li        r6, 0x5C
	  blrl
	  mr        r3, r29
	  lwz       r5, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r29)
	  addi      r7, r31, 0x68
	  lwz       r4, 0x10(r5)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  lwz       r8, 0x1C4(r5)
	  li        r5, 0x20
	  mtlr      r12
	  li        r6, 0x68
	  blrl

	.loc_0x294:
	  lis       r3, 0x803A
	  lfs       f1, -0x7940(r2)
	  subi      r3, r3, 0x2848
	  addi      r30, r3, 0x2C4
	  lfs       f0, 0x2C4(r3)
	  fcmpo     cr0, f0, f1
	  bgt-      .loc_0x2BC
	  lfs       f0, 0x2C8(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x3E0

	.loc_0x2BC:
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lfs       f1, 0x28C(r4)
	  addi      r5, r4, 0x28C
	  lfs       f0, 0x2CC(r3)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x2CC(r3)
	  lfs       f1, 0x2CC(r3)
	  lfs       f0, -0x7940(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2F0
	  stfs      f0, 0x2C8(r3)

	.loc_0x2F0:
	  lis       r3, 0x803A
	  lfs       f2, 0x0(r30)
	  subi      r3, r3, 0x2848
	  lfsu      f1, 0x2C8(r3)
	  lfs       f0, 0x0(r5)
	  fsubs     f1, f1, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r30)
	  lfs       f2, 0x0(r30)
	  lfs       f1, 0x0(r3)
	  lfs       f0, -0x793C(r2)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x44(r1)
	  lwz       r0, 0x44(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x44(r1)
	  lfs       f1, 0x44(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x348
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x0(r30)

	.loc_0x348:
	  li        r27, 0xC0
	  stb       r27, 0x58(r1)
	  li        r28, 0xFF
	  addi      r4, r1, 0x58
	  stb       r28, 0x59(r1)
	  mr        r3, r29
	  li        r5, 0x1
	  stb       r28, 0x5A(r1)
	  lfs       f0, 0x0(r30)
	  fctiwz    f0, f0
	  stfd      f0, 0x1B0(r1)
	  lwz       r0, 0x1B4(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r27, 0x54(r1)
	  addi      r4, r1, 0x54
	  addi      r3, r29, 0
	  stb       r27, 0x55(r1)
	  stb       r28, 0x56(r1)
	  lfs       f0, 0x0(r30)
	  fctiwz    f0, f0
	  stfd      f0, 0x1B8(r1)
	  lwz       r0, 0x1BC(r1)
	  stb       r0, 0x57(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  crset     6, 0x6
	  subi      r3, r3, 0x2848
	  lfs       f1, 0x2C0(r3)
	  addi      r3, r1, 0x70
	  addi      r4, r31, 0x78
	  bl        0x1B71E0

	.loc_0x3E0:
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r3, 0x4
	  lfs       f0, 0x8(r3)
	  lfs       f2, 0x4(r3)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x448
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r4)
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r3, 0x4
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x4(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x488
	  stfs      f1, 0x0(r4)
	  b         .loc_0x488

	.loc_0x448:
	  ble-      .loc_0x488
	  stfs      f0, 0x0(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x28C(r3)
	  lfs       f0, 0xC(r3)
	  lfs       f1, 0x4(r3)
	  fmuls     f0, f0, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r3, 0x4
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x488
	  stfs      f1, 0x0(r4)

	.loc_0x488:
	  lwz       r5, 0x2DEC(r13)
	  lwz       r0, 0x18(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x4A8
	  lwz       r3, 0x34(r5)
	  mr        r4, r29
	  lwz       r5, 0x10(r5)
	  bl        -0x1EAD4

	.loc_0x4A8:
	  lmw       r27, 0x1C4(r1)
	  lwz       r0, 0x1DC(r1)
	  addi      r1, r1, 0x1D8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005F498
 * Size:	000144
 */
int PlugPikiApp::idle()
{
	gsys->setHeap(mHeapIndex);
	gsys->mTimer->newFrame();
	gsys->mTimer->_start("all", false);

	if (gsys->getPending()) {
		gsys->detachObjs();
		gsys->mTimer->reset();
		gsys->clearPending();
		softReset();
		gsys->attachObjs();
	} else {
		update();
		gsys->beginRender();
		renderall();
		// something here
		gsys->doneRender();
		// something here
		gsys->mTimer->_stop("all");
		gsys->waitRetrace();
		gsys->setHeap(-1);
	}
	return 1;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x50(r31)
	  bl        -0x2044C
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x34(r3)
	  bl        -0x1EB2C
	  lwz       r3, 0x2DEC(r13)
	  subi      r4, r13, 0x6ED4
	  li        r5, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x1EB30
	  lwz       r3, 0x2DEC(r13)
	  lbz       r0, 0x0(r3)
	  lwz       r4, 0x26C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x94
	  bl        -0x1FDC4
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x34(r3)
	  bl        -0x1EB74
	  lwz       r4, 0x2DEC(r13)
	  li        r0, 0
	  addi      r3, r31, 0
	  stb       r0, 0x0(r4)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1FE94
	  li        r3, 0x1
	  b         .loc_0x130

	.loc_0x94:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1AACC
	  mr        r3, r31
	  bl        -0x12C44
	  lwz       r4, 0x2DEC(r13)
	  lwz       r3, 0x254(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0xDC
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x24C(r4)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xDC:
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1AA0C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x108:
	  lwz       r3, 0x2DEC(r13)
	  subi      r4, r13, 0x6ED4
	  lwz       r3, 0x34(r3)
	  bl        -0x1EC04
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1AA24
	  lwz       r3, 0x2DEC(r13)
	  li        r4, -0x1
	  bl        -0x20558
	  li        r3, 0x1

	.loc_0x130:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005F5DC
 * Size:	000148
 */
PlugPikiApp::PlugPikiApp()
{
	mName = "Piki the Game";
	gsys->setHeap(0);
	hardReset();
	mCommandStream = new AtxCommandStream(this);
	if (mCommandStream->open("app", 3)) {
		mCommandStream->mPath = 0;
	} else {
		mCommandStream->mPath = mName;
	}
	gsys->mTimerState = 1;
	gsys->hardReset();
	gsys->getHeap(gsys->mActiveHeapIdx);
	gsys->getHeap(gsys->mActiveHeapIdx);
	gsys->_198 = 0;
	gsys->setHeap(-1);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  mr        r3, r31
	  bl        -0x3A7FC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x77B0
	  lis       r3, 0x802B
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x772C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x78C4
	  stw       r0, 0x4(r31)
	  li        r4, 0
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x205C0
	  mr        r3, r31
	  bl        -0x840
	  li        r3, 0x14
	  bl        -0x18634
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8023
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x703C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0xC(r3)
	  subi      r0, r4, 0x7874
	  stw       r0, 0x4(r3)
	  stw       r31, 0x10(r3)

	.loc_0x98:
	  lwz       r31, 0x8(r1)
	  subi      r4, r13, 0x6ED0
	  li        r5, 0x3
	  stw       r3, 0x20(r31)
	  lwz       r3, 0x20(r31)
	  bl        -0x1BD64
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC8
	  lwz       r0, 0x4(r31)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x0(r3)
	  b         .loc_0xD0

	.loc_0xC8:
	  li        r0, 0
	  stw       r0, 0x20(r31)

	.loc_0xD0:
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  stw       r0, 0x18(r3)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x19E9C
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x206A8
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x206B4
	  lwz       r4, 0x8(r3)
	  li        r0, 0
	  lwz       r3, 0x4(r3)
	  lis       r5, 0x4330
	  sub       r3, r3, r4
	  xoris     r4, r3, 0x8000
	  lwz       r3, 0x2DEC(r13)
	  stw       r4, 0x1C(r1)
	  li        r4, -0x1
	  stw       r0, 0x198(r3)
	  stw       r5, 0x18(r1)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x206A0
	  lwz       r3, 0x8(r1)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005F724
 * Size:	000064
 */
GameApp::~GameApp()
{
}

/*
 * --INFO--
 * Address:	8005F788
 * Size:	000008
 */
int GameApp::idle()
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	8005F790
 * Size:	000074
 */
PlugPikiApp::~PlugPikiApp()
{
}
