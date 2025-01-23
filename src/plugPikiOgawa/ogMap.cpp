#include "zen/ogMap.h"
#include "zen/ogSub.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "P2D/Graph.h"
#include "std/Math.h"
#include "sysNew.h"

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
 * Address:	80182DE0
 * Size:	0000D4
 */
void zen::ogScrMapMgr::start(s16 p1)
{
	u32 badCompiler[6];

	mMode  = p1;
	mState = MAP_Unk1;

	if (mMode == 1) {
		mCurrentScreen = mTest2Screen;
		mPic1          = mCurrentScreen->search('pic1', true);
		mPic1PositionX = mPic1->mRectTransform.mMin.x;
		mPic1PositionY = mPic1->mRectTransform.mMin.y;
		mTypingTextMgr->start();

	} else {
		mCurrentScreen = mTestScreen;
	}

	_2C = 0;
	_2E = 0;
}

/*
 * --INFO--
 * Address:	80182EB4
 * Size:	0001CC
 */
zen::ogScrMapMgr::ogScrMapMgr()
{
	mTestScreen = new P2DScreen();
	mTestScreen->set("screen/blo/test.blo", true, true, true);

	mTest2Screen = new P2DScreen();
	mTest2Screen->set("screen/blo/test2.blo", true, true, true);

	P2DTextBox* textBox = static_cast<P2DTextBox*>(mTest2Screen->search('tx00', true));
	mTypingTextMgr      = new TypingTextMgr(textBox);

	mCursorPane = mTest2Screen->search('curs', true);
	mFrameTimer = 0.0f;
	mState      = MAP_NULL;
}

/*
 * --INFO--
 * Address:	80183080
 * Size:	00029C
 */
zen::ogScrMapMgr::MapStatus zen::ogScrMapMgr::update(Controller* controller)
{
	if (mState == MAP_NULL) {
		return mState;
	}

	mFrameTimer += gsys->getFrameTime();
	mCurrentScreen->update();

	if (mState == MAP_Unk1) {
		mState = MAP_Unk0;
		return mState;
	}

	if (mState == MAP_Unk2) {
		mState = MAP_Unk4;
		return mState;
	}

	if (mState == MAP_Unk4) {
		mState = MAP_NULL;
		return mState;
	}

	if (controller->keyClick(KBBTN_B)) {
		mState = MAP_Unk2;
	}

	if (mMode == 1) {
		mTypingTextMgr->update();
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x80(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x284

	.loc_0x2C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  bl        0x2FA8C
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x64
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x284

	.loc_0x64:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x7C
	  li        r0, 0x4
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x284

	.loc_0x7C:
	  cmpwi     r0, 0x4
	  bne-      .loc_0x94
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x284

	.loc_0x94:
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0xA8
	  li        r0, 0x2
	  stw       r0, 0x0(r30)

	.loc_0xA8:
	  lha       r0, 0x14(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x204
	  lwz       r3, 0x10(r30)
	  bl        -0x279C
	  lwz       r4, 0x10(r30)
	  lwz       r3, 0x20(r30)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lfs       f1, 0x18(r30)
	  lfs       f2, -0x5074(r2)
	  bl        .loc_0x29C
	  lfs       f0, -0x5070(r2)
	  fmuls     f1, f0, f1
	  bl        0x98B60
	  lfs       f0, -0x5074(r2)
	  lwz       r6, 0x1C(r30)
	  fadds     f0, f0, f1
	  lha       r5, 0x18(r6)
	  lha       r3, 0x1C(r6)
	  lha       r4, 0x1A(r6)
	  lha       r0, 0x1E(r6)
	  sub       r3, r3, r5
	  srawi     r3, r3, 0x1
	  stfs      f0, 0xC0(r6)
	  addze     r3, r3
	  sub       r0, r0, r4
	  stfs      f0, 0xC4(r6)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stfs      f0, 0xC8(r6)
	  extsh     r3, r3
	  extsh     r0, r0
	  lwz       r4, 0x1C(r30)
	  sth       r3, 0xB8(r4)
	  sth       r0, 0xBA(r4)
	  lfs       f1, 0x24(r30)
	  lfs       f0, 0x28(r30)
	  lwz       r3, 0x1C(r30)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x78(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x70(r1)
	  mtlr      r12
	  lwz       r4, 0x7C(r1)
	  lwz       r5, 0x74(r1)
	  blrl
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x1B0
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x506C(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r30)

	.loc_0x1B0:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x1CC
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x506C(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r30)

	.loc_0x1CC:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x1E8
	  lfs       f1, 0x28(r30)
	  lfs       f0, -0x506C(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r30)

	.loc_0x1E8:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x204
	  lfs       f1, 0x28(r30)
	  lfs       f0, -0x506C(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r30)

	.loc_0x204:
	  lwz       r3, 0x4(r30)
	  lha       r4, 0x2C(r30)
	  lwz       r12, 0x0(r3)
	  lha       r5, 0x2E(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x238
	  lha       r3, 0x2C(r30)
	  subi      r0, r3, 0x4
	  sth       r0, 0x2C(r30)

	.loc_0x238:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x250
	  lha       r3, 0x2C(r30)
	  addi      r0, r3, 0x4
	  sth       r0, 0x2C(r30)

	.loc_0x250:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x268
	  lha       r3, 0x2E(r30)
	  subi      r0, r3, 0x4
	  sth       r0, 0x2E(r30)

	.loc_0x268:
	  lwz       r0, 0x20(r31)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x280
	  lha       r3, 0x2E(r30)
	  addi      r0, r3, 0x4
	  sth       r0, 0x2E(r30)

	.loc_0x280:
	  lwz       r3, 0x0(r30)

	.loc_0x284:
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr

	.loc_0x29C:
	*/
}

/*
 * --INFO--
 * Address:	8018331C
 * Size:	000060
 */
// f32 std::fmodf(f32, f32)
// {
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  fmr       f31, f2
  stfd      f30, 0x18(r1)
  fmr       f30, f1
  fabs      f1, f31
  fabs      f0, f30
  fcmpo     cr0, f1, f0
  ble-      .loc_0x34
  fmr       f1, f30
  b         .loc_0x48

.loc_0x34:
  fdivs     f1, f30, f31
  bl        0x920A0
  bl        0x91FE8
  fmuls     f0, f31, f1
  fsubs     f1, f30, f0

.loc_0x48:
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lfd       f30, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
// }

/*
 * --INFO--
 * Address:	8018337C
 * Size:	00008C
 */
void zen::ogScrMapMgr::draw(Graphics& gfx)
{
	if (mState == MAP_NULL) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mCurrentScreen->draw(0, 0, &perspGraph);
}
