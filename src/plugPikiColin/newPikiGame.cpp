#include "types.h"
#include "Controller.h"
#include "Section.h"
#include "ModeState.h"
#include "Interface.h"
#include "NewPikiGame.h"
#include "sysNew.h"
#include "jaudio/PikiDemo.h"
#include "KIO.h"
#include "DayMgr.h"
#include "GameStat.h"
#include "Controller.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "MapMgr.h"
#include "NaviMgr.h"
#include "zen/DrawGameInfo.h"
#include "MemStat.h"
#include "Menu.h"
#include "GameCoreSection.h"
#include "PlayerState.h"
#include "zen/ogTutorial.h"
#include "zen/ogMenu.h"
#include "zen/DrawCountDown.h"
#include "jaudio/PikiScene.h"
#include "zen/ogPause.h"
#include "zen/ogResult.h"
#include "zen/DrawGameOver.h"
#include "zen/ogTotalScore.h"
#include "zen/DrawFinalResult.h"
#include "zen/ogMemChk.h"
#include "zen/ogFileChkSel.h"
#include "zen/DrawCM.h"
#include "MoviePlayer.h"
#include "Graphics.h"
#include "Font.h"
#include "DebugLog.h"

bool HasDemoSound;
bool dontShowFrame;
bool gameInfoOn;
bool gameInfoIn;
bool menuOn;
int resultTable[16];
zen::DrawCMresult* challengeWindow;
zen::ogScrTutorialMgr* tutorialWindow;
zen::ogScrMenuMgr* menuWindow;
zen::ogScrPauseMgr* pauseWindow;
zen::ogScrFileChkSelMgr* memcardWindow;
zen::DrawCountDown* countWindow;
zen::DrawGameOver* gameoverWindow;
zen::ogScrResultMgr* resultWindow;
zen::DrawFinalResult* totalWindow;
GameCoreSection* gamecore;
NewPikiGameSetupSection* npgss;

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
DEFINE_PRINT("newPikiGame")

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void showFrame(bool set, f32 time)
{
	if (!set) {
		if (gameInfoOn && !gameInfoIn) {
			if (!playerState->isTutorial()) {
				gamecore->mDrawGameInfo->upperFrameIn(time, true);
			}
			gamecore->mDrawGameInfo->lowerFrameIn(time, true);
			gameInfoIn = true;
		}
		return;
	}

	if (gameInfoOn && gameInfoIn) {
		if (!playerState->isTutorial()) {
			gamecore->mDrawGameInfo->upperFrameOut(time, true);
		}
		gamecore->mDrawGameInfo->lowerFrameOut(time, true);
		gameInfoIn = false;
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80056B00
 * Size:	000118
 */
void createMenuWindow()
{
	gsys->startLoading(nullptr, false, 0);
	int heapold = gsys->_2A4 != 0;
	gsys->_2A4  = 0;
	int heapid  = gsys->mActiveHeapIdx;
	PRINT("using movie heap!\n");

	gsys->setHeap(5);
	AyuHeap* heap    = gsys->getHeap(5);
	int oldtype      = heap->mAllocType;
	heap->mAllocType = 1;

	menuWindow = new zen::ogScrMenuMgr;
	menuWindow->start();

	gsys->getHeap(5)->mAllocType = oldtype;
	gsys->setHeap(heapid);
	gsys->_2A0 = 0;
	gsys->_2A4 = heapold;
	gsys->endLoading();
	PRINT("menu window attach\n");
	gsys->attachObjs();
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
void createTutorialWindow(int a1, int a2, bool flag)
{
	gsys->startLoading(nullptr, false, 0);
	int heapold = gsys->_2A4 != 0;
	gsys->_2A4  = 0;
	int heapid  = gsys->mActiveHeapIdx;
	PRINT("using movie heap!\n");

	HasDemoSound = (a2 >= 0 && flag);

	if (HasDemoSound) {
		Jac_StartPartsFindDemo(a2 + 1, flag);
	} else {
		Jac_StartTextDemo(a1);
	}
	gsys->setHeap(5);

	AyuHeap* heap    = gsys->getHeap(5);
	int oldtype      = heap->mAllocType;
	heap->mAllocType = 1;
	tutorialWindow   = new zen::ogScrTutorialMgr;
	tutorialWindow->start((zen::ogScrTutorialMgr::EnumTutorial)a1);

	gsys->getHeap(5)->mAllocType = oldtype;
	gsys->setHeap(heapid);
	showFrame(false, 0.5f);
	gameflow._340 = 1;
	gsys->_2A0    = 0;
	gsys->_2A4    = heapold;
	gsys->endLoading();
	PRINT("tutorial window attach\n");
	gsys->attachObjs();

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
	if (HasDemoSound) {
		Jac_FinishPartsFindDemo();
	} else {
		Jac_FinishTextDemo();
	}
	gameflow._340 = 0;
	if (!dontShowFrame && gameInfoOn && !gameInfoIn) {
		if (!playerState->isTutorial()) {
			gamecore->mDrawGameInfo->upperFrameIn(0.5f, true);
		}
		gamecore->mDrawGameInfo->lowerFrameIn(0.5f, true);
		gameInfoIn = true;
	}

	gameflow._338  = 0;
	tutorialWindow = 0;

	FORCE_DONT_INLINE;
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
	_40          = 6;
	_20          = 0;
	_34          = 0;
	_38          = 0;
	mController  = new Controller;
	_3C          = 0;
	mCurrentFade = 0.0f;
	mTargetFade  = 1.0f;
	mFadeSpeed   = 0.5f;
}

/*
 * --INFO--
 * Address:	80056F9C
 * Size:	000244
 */
void BaseGameSection::draw(Graphics& gfx)
{
	Matrix4f mtx;
	gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

	if (mCurrentFade < mTargetFade) {
		mCurrentFade += mFadeSpeed * gsys->getFrameTime();
		if (mCurrentFade > mTargetFade) {
			mCurrentFade = mTargetFade;
		}
	} else if (mCurrentFade > mTargetFade) {
		mCurrentFade -= mFadeSpeed * gsys->getFrameTime();
		if (mCurrentFade < mTargetFade) {
			mCurrentFade = mTargetFade;
		}
	}

	if (mCurrentFade < 1.0f) {
		f32 test = mCurrentFade > 1.0f ? 1.0f : mCurrentFade < 0.0f ? 0.0f : mCurrentFade;
		test     = (1.0f - test) * 255.0f;
		gfx.setColour(Colour(0, 0, 0, test), true);
		gfx.setAuxColour(Colour(0, 0, 0, test));
		gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	}

	if (gameflow.mLevelBannerTexture && gameflow.mLevelBannerFadeValue > 0.0f) {
		gameflow.mLevelBannerFadeValue -= gsys->getFrameTime();
		if (gameflow.mLevelBannerFadeValue < 0.0f) {
			gameflow.mLevelBannerTexture   = nullptr;
			gameflow.mLevelBannerFadeValue = 0.0f;
		} else {
			gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTexture, gameflow.mLevelBannerFadeValue);
		}
	}
	_34->postUpdate();
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
ModeState* IntroGameModeState::update(u32& a)
{
	a = 1;

	if (tutorialWindow && tutorialWindow->update(mSection->mController) == (zen::ogScrTutorialMgr::TutorialStatus)4) {
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(2);
		}
		deleteTutorialWindow();
	}

	if (!gameflow.mMoviePlayer->mIsActive) {
		gameInfoOn = true;
		if (!gameInfoIn) {
			if (!playerState->isTutorial()) {
				gamecore->mDrawGameInfo->upperFrameIn(0.5f, true);
			}
			gamecore->mDrawGameInfo->lowerFrameIn(0.5f, true);
			gameInfoIn = true;
		}

		new RunningModeState(mSection);
	}
	return this;
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
ModeState* RunningModeState::update(u32& a)
{
	a = 7;
	if (!gameflow.mMoviePlayer->mIsActive && !gameflow._340 && gameflow._1E4) {
		a &= ~1;
		PRINT("*-------------------------------- DAY END !!!!!!!!!!!!!!  --------------------------------*\n");
		mSection->_40 = gameflow.mLevelIndex;
		return new DayOverModeState(mSection, 0);
	}

	if (!gameflow._1E4 && !gameflow.mMoviePlayer->mIsActive && gameflow.mParameters->mEndHour() >= gameflow.mWorldClock.mTimeOfDay) {
		gameflow._334 = 0;
		gameflow._1E6 = 1;
	}

	if (gameflow._1E6 && !gameflow._338) {
		gameflow._1E4 = 1;
		gameflow._1E6 = 0;
		if (playerState->getCurrParts() != 30 && gameflow.mWorldClock.mCurrentDay == 30) {
			if (playerState->happyEndable()) {
				flowCont._244 = 1;
				gameflow.mGameInterface->message(0, 28);
			} else {
				gameflow.mGameInterface->message(0, 28);
			}
		}
	}

	if (gameflow._334 && !gameflow._338 && !gameflow._33C && !gameflow.mMoviePlayer->mIsActive) {

		if (mController->keyClick(KBBTN_START) && !gameflow.mGameInterface->mMesgCount) {
			seSystem->playSysSe(SYSSE_PAUSE);
			pauseWindow->start(gameflow.mIsChallengeMode != 0);
			_08           = 1 - (gameflow._338 == 0);
			gameflow._338 = 1;
		} else if (mController->keyClick(KBBTN_Y) && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - 0.125f
		           && !gameflow.mGameInterface->mMesgCount) {
			gameflow.mGameInterface->message(17, 0);
			_08           = 1 - (gameflow._338 == 0);
			gameflow._338 = 1;
		}
	}

	if (flowCont._234) {
		if (flowCont._234 == 2) {
			mSection->_40 = 7;
			return new MessageModeState(mSection, false);
		}
		if (flowCont._234 == 1) {
			mSection->_40 = 7;
			return new MessageModeState(mSection, true);
		}
	}

	if (gameoverWindow) {
		gameoverWindow->update(mController);
	}

	if (menuWindow) {
		int state = menuWindow->update(mController);
		if (state == 0) {
			a &= ~1;
		} else if (state == 3) {
			gsys->resetHeap(5, 1);
			gameflow._338 = 0;
			menuWindow    = nullptr;
		}
	}

	if (tutorialWindow && tutorialWindow->update(mController) == (zen::ogScrTutorialMgr::TutorialStatus)4) {

		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(2);
		}
		deleteTutorialWindow();
	}

	int state = pauseWindow->update(mController);
	if (state == 0) {
		a &= ~1;
	} else if (state == 6) {
		gamecore->forceDayEnd();
		gameflow._334 = 0;
		gameflow._1E6 = 1;
		gameflow._338 = _08;

	} else if (state == 7) {
		mSection->_40 = 1;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection);
	} else if (state == 5) {
		if (gameInfoOn && !gameInfoIn) {
			if (!playerState->isTutorial()) {
				gamecore->mDrawGameInfo->upperFrameIn(0.5f, true);
			}
			gamecore->mDrawGameInfo->lowerFrameIn(0.5f, true);
			gameInfoIn    = true;
			gameflow._338 = _08;
			seSystem->playSysSe(SYSSE_PAUSE);
		}
	}
	return this;
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
void IntroGameModeState::postRender(Graphics& gfx)
{
	Matrix4f mtx;
	if (tutorialWindow) {
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		tutorialWindow->draw(gfx);
	}
}

/*
 * --INFO--
 * Address:	800579C8
 * Size:	000294
 */
void RunningModeState::postRender(Graphics& gfx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx2.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));

	if (!menuOn) {
		gfx.setOrthogonal(mtx1.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gamecore->draw1D(gfx);
	}

	if (gameflow._33C == 0 && !gameflow.mMoviePlayer->mIsActive && mSection->_3C & 4) {
		f32 time = (gameflow.mWorldClock.mTimeOfDay - gameflow.mParameters->mNightCountdown())
		         / (gameflow.mParameters->mNightEnd() - gameflow.mParameters->mNightCountdown());
		if (time >= 0.0f && time < 1.0f) {
			countWindow->update();
			countWindow->draw(gfx);
		}
	}

	if (menuOn) {
		return;
	}

	if (tutorialWindow) {
		gfx.setOrthogonal(mtx1.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		tutorialWindow->draw(gfx);
	}

	gfx.setOrthogonal(mtx1.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gamecore->draw2D(gfx);

	if (gameoverWindow) {
		gfx.setOrthogonal(mtx1.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gameoverWindow->draw(gfx);
	}

	gfx.setOrthogonal(mtx1.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	pauseWindow->draw(gfx);
}

/*
 * --INFO--
 * Address:	80057C5C
 * Size:	000360
 */
ModeState* MessageModeState::update(u32& a)
{
	if (flowCont._234 == 2) {
		switch (_0C) {
		case 0:
			_10 -= gsys->getFrameTime();
			if (_10 < 0.0f) {
				_10          = 2.0f;
				mapMgr->_4C8 = 1.0f;
				if ((gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == 30) && gameoverWindow) {
					gameoverWindow->start((zen::DrawGameOver::modeFlag)0, 40.0f);
				}
				_0C = 1;
			}
			break;
		case 1:
			_10 -= gsys->getFrameTime();
			if (_10 < 0.0f) {
				_10          = 3.0f;
				mapMgr->_4CC = 1.0f;
				_0C          = 2;
			}
			break;
		case 2:
			_10 -= gsys->getFrameTime();
			if (_10 < 0.0f) {
				_10 = 2.0f;
				_0C = 3;
			}
			break;
		case 3:
			mapMgr->_4CC = 0.0f;
			mapMgr->_4C8 = 0.0f;
			PRINT("DOING FORCE RESULTS SCREEN !!!\n");
			DayOverModeState* state = new DayOverModeState(mSection, 1);
			state->_08              = 0;
			mSection->_38           = state;
			gamecore->cleanupDayEnd();
			if (!gameflow.mIsChallengeMode) {
				if (gameflow.mWorldClock.mCurrentDay != 30) {
					gameflow.mMoviePlayer->startMovie(52, 0, nullptr, nullptr, nullptr, -1, true);
					if (gameoverWindow) {
						gameoverWindow->start((zen::DrawGameOver::modeFlag)0, 40.0f);
					}
				}
			} else {
				gameoverWindow = nullptr;
			}
			break;
		}
	} else if (flowCont._234 == 0) {
		DayOverModeState* state = new DayOverModeState(mSection, 1);
		gameoverWindow          = nullptr;
		state->_08              = 0;
		mSection->_38           = state;
		mSection->mTargetFade   = 1.0f;
	}

	if (gameoverWindow) {
		gameoverWindow->update(mSection->mController);
	}
	return this;
}

/*
 * --INFO--
 * Address:	80057FBC
 * Size:	000474
 */
ModeState* DayOverModeState::update(u32& a)
{
	a = 1;

	if (tutorialWindow && tutorialWindow->update(mSection->mController) == (zen::ogScrTutorialMgr::TutorialStatus)4) {
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(2);
		}
		deleteTutorialWindow();
	}

	if (!gameflow.mMoviePlayer->mIsActive) {
		ModeState* state = nullptr;
		switch (_08) {
		case 0:
			state = initialisePhaseOne();
			break;
		case 1:
			state = initialisePhaseTwo();
			break;
		case 2:
			state = initialisePhaseThree();
			break;
		case 3:
			state = initialisePhaseFour();
			break;
		}
		if (state) {
			return state;
		}
	}

	if (gameoverWindow) {
		gameoverWindow->update(mSection->mController);
	}

	if (challengeWindow && challengeWindow->update(mSection->mController)) {
		mSection->_40 = 6;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection);
	}

	if (resultWindow) {
		zen::ogScrResultMgr::returnStatusFlag stat = resultWindow->update(mSection->mController);
		if (stat >= 7) {
			gsys->startLoading(nullptr, 1, 120);
			gamecore->exitDayEnd();
			gameflow.mMoviePlayer->fixMovieList();
			Jac_SceneSetup(6, 0);
			gsys->resetHeap(5, 1);
			gsys->resetHeap(4, 1);
			gsys->resetHeap(4, 2);
			gsys->setHeap(gsys->setHeap(4));
			gsys->endLoading();

			if (!memcardWindow) {
				if (stat == 8) {
					mSection->_40 = 1;
				} else {
					mSection->_40 = 6;
				}
				gsys->setFade(0.0f, 3.0f);
				return new QuittingGameModeState(mSection);
			}
		}
	}

	if (totalWindow && totalWindow->update(mSection->mController)) {
		if (_08 == 2) {
			gameflow.mMoviePlayer->skipScene(2);
			totalWindow = nullptr;
		} else {
			totalWindow   = nullptr;
			mSection->_40 = 11;
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
		}
	}

	if (memcardWindow) {
		CardQuickInfo info;
		int state = memcardWindow->update(mSection->mController, info);
		if (state >= 1) {
			memcardWindow = nullptr;
			if (state != 1 && state != 5) {
				gameflow.mPlayState._23             = info.mCurrentDay;
				gameflow.mGamePrefs.mSpareSaveGames = info.mIndex + 1;
				PRINT("using save game file %d with %d as the spare\n", gameflow.mGamePrefs.mSaveGameIndex,
				      gameflow.mGamePrefs.mSpareSaveGames);

				bool sysbackup     = gsys->mTogglePrint != 0;
				gsys->mTogglePrint = 1;
				PRINT("doing save now!!\n");
				gameflow.mMemoryCard.saveCurrentGame();
				if (mSection->mController->keyDown(KBBTN_Z)) {
					kio->startWrite(0, cardData, 0x26000);
				}
				gsys->mTogglePrint = sysbackup;
			}
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
		}
	}

	return this;
	f32 badcompiler[2];
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
	GameQuickInfo info;
	info.mDay       = gameflow.mWorldClock.mCurrentDay;
	info.mPikis     = playerState->getLastPikmins();
	info.mDeadPikis = playerState->getFinalDeadPikis();
	info.mParts     = playerState->getCurrParts();
	gameflow.mGamePrefs.checkIsHiscore(info);

	zen::TotalScoreRecord* record = new zen::TotalScoreRecord;
	record->mParts                = info.mParts;
	record->mDay                  = info.mDay;
	record->mPikis                = info.mPikis;
	record->mDeadPikis            = info.mDeadPikis;
	record->_10                   = gameflow.mGamePrefs.mHiscores._00;

	for (int i = 0; i < 5; i++) {
		record->_1A[i] = gameflow.mGamePrefs.mHiscores.mMinDayRecords[i]._00;
		record->_24[i] = gameflow.mGamePrefs.mHiscores.mMinDayRecords[i]._04;
		record->_2E[i] = gameflow.mGamePrefs.mHiscores.mBornPikminRecords[i]._00;
		record->_38[i] = gameflow.mGamePrefs.mHiscores.mDeadPikminRecords[i]._00;
		if (record->_38[i] == 9999) {
			record->_38[i] = -1;
		}
	}

	record->_14 = info._10;
	record->_16 = info._14;
	record->_18 = info._18;

	totalWindow = new zen::DrawFinalResult(record);

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
ModeState* DayOverModeState::initialisePhaseOne()
{
	if (playerState->getCurrParts() == 30) {
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();
		gsys->resetHeap(4, 2);
		int old = gsys->setHeap(4);
		gameflow.mMoviePlayer->startMovie(75, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setHeap(old);
	} else if (gameflow.mWorldClock.mCurrentDay >= 30) {
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();
		gsys->resetHeap(4, 2);
		int old    = gsys->setHeap(4);
		u32 flags  = 0;
		u32 ids[3] = { 1, 2, 0 };
		for (int i = 0; i < 3; i++) {
			if (playerState->hasContainer(ids[i])) {
				flags |= 1 << (i + 12);
			}
		}
		if (!(flags & 0x2000)) {
			flags |= 0x800;
		}
		if (!(flags & 0x4000)) {
			flags |= 0x8000;
		}
		mSection->mCurrentFade = -0.1f;
		mSection->mTargetFade  = 1.0f;
		gameflow.mMoviePlayer->startMovie(69, 0, nullptr, nullptr, nullptr, flags | 0xffff07ff, true);
		gameoverWindow = nullptr;
		gsys->setHeap(old);
	} else {
		gsys->resetHeap(4, 2);
		int old                = gsys->setHeap(4);
		gameoverWindow         = nullptr;
		mSection->mCurrentFade = -0.1f;
		gameflow.mMoviePlayer->startMovie(32, 0, nullptr, nullptr, nullptr, -1, true);
		if (!playerState->isTutorial() && !gameflow.mIsChallengeMode) {
			u32 flags  = 0;
			u32 ids[3] = { 1, 2, 0 };
			for (int i = 0; i < 3; i++) {
				if (GameStat::victimPikis[ids[i]]) {
					PRINT("got (%d) %d victims\n", i, GameStat::victimPikis[ids[i]]);
					flags |= 1 << (i + 12);
				}
			}
			if (flags == 0) {
				flags |= 0x8000;
			} else {
				flags |= 0x800;
			}
			gameflow.mMoviePlayer->startMovie(56, 0, nullptr, nullptr, nullptr, flags | 0xffff07ff, true);
		}
		gsys->setHeap(old);
	}

	_08 = 1;
	return nullptr;
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
ModeState* DayOverModeState::initialisePhaseTwo()
{
	gsys->startLoading(nullptr, true, 120);
	PRINT("EXITDAYEND!!!!\n");
	gamecore->exitDayEnd();
	gameflow.mMoviePlayer->fixMovieList();
	Jac_SceneSetup(6, 0);
	gsys->resetHeap(5, 1);
	gsys->resetHeap(4, 1);
	gsys->resetHeap(4, 2);
	int old = gsys->setHeap(4);

	if (playerState->getCurrParts() == 30) {
		gameflow.mMoviePlayer->startMovie(113, 0, nullptr, nullptr, nullptr, -1, true);
	} else if (gameflow.mWorldClock.mCurrentDay < 30) {
		PRINT("LOADING YOZURA MOVIE!!\n");
		gameflow.mMoviePlayer->startMovie(36, 0, nullptr, nullptr, nullptr, -1, true);

		if (playerState->hasContainer(1)) {
			gameflow.mMoviePlayer->startMovie(84, 0, nullptr, nullptr, nullptr, -1, true);
		}
		if (playerState->hasContainer(2)) {
			gameflow.mMoviePlayer->startMovie(85, 0, nullptr, nullptr, nullptr, -1, true);
		}
		if (playerState->hasContainer(0)) {
			gameflow.mMoviePlayer->startMovie(86, 0, nullptr, nullptr, nullptr, -1, true);
		}

		gameflow.mWorldClock.mCurrentDay++;
		if (!gameflow.mIsChallengeMode) {
			int pages = 0;
			int doc   = playerState->mResultFlags.getDocument(pages);
			if (pages == 0) {
				ERROR("zero pages!\n");
			}
			int i = 0;
			for (; i < pages; i++) {
				resultTable[i] = doc + i;
			}
			resultTable[i] = 0;
			resultWindow   = new zen::ogScrResultMgr((zen::EnumResult*)resultTable);
			resultWindow->start();
		} else {
			GameChalQuickInfo info;
			PRINT("starting challenge mode window %d : %d!\n", GameStat::allPikis);
			info.mCourseID = flowCont.mCurrentStage->mChalStageID;
			info.mPikis    = GameStat::allPikis;
			gameflow.mGamePrefs.checkIsHiscore(info);
			challengeWindow = new zen::DrawCMresult;
			challengeWindow->start(info);
		}
	} else {
		if (playerState->happyEndable()) {
			flowCont._244 = 1;
			gameflow.mMoviePlayer->startMovie(114, 0, nullptr, nullptr, nullptr, -1, true);
		} else {
			gameflow.mMoviePlayer->startMovie(73, 0, nullptr, nullptr, nullptr, -1, true);
			makeTotalScoreWindow();
		}
	}

	gsys->setHeap(old);
	gsys->endLoading();
	mSection->mTargetFade = 1.0f;
	mSection->mFadeSpeed  = 0.5f;
	_08                   = 2;
	return nullptr;
}

/*
 * --INFO--
 * Address:	80058DF8
 * Size:	000258
 */
ModeState* DayOverModeState::initialisePhaseThree()
{
	gsys->startLoading(nullptr, true, 120);
	gameflow.mMoviePlayer->fixMovieList();
	gsys->resetHeap(5, 1);
	gsys->resetHeap(4, 1);
	gsys->resetHeap(4, 2);
	int old = gsys->setHeap(4);
	playerState->setNavi(false);

	if (playerState->getCurrParts() == 30) {
		gameflow.mMoviePlayer->startMovie(76, 0, nullptr, nullptr, nullptr, -1, true);
	} else if (gameflow.mWorldClock.mCurrentDay == 30) {
		if (playerState->happyEndable()) {
			gameflow.mMoviePlayer->startMovie(77, 0, nullptr, nullptr, nullptr, -1, true);
			makeTotalScoreWindow();
		} else {
			u32 flags  = 0;
			u32 ids[3] = { 1, 2, 0 };
			for (int i = 0; i < 3; i++) {
				if (playerState->hasContainer(ids[i])) {
					flags |= 1 << (i + 12);
				}
			}
			flags |= 0xffff07ff;
			gamecore->prepareBadEnd();
			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mMoviePlayer->startMovie(74, 0, nullptr, nullptr, nullptr, flags, true);
			gameoverWindow = nullptr;
		}
	}

	gsys->setHeap(old);
	gsys->endLoading();
	_08 = 3;
	return nullptr;
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
ModeState* DayOverModeState::initialisePhaseFour()
{
	gameflow.mMoviePlayer->fixMovieList();
	gsys->resetHeap(5, 1);
	gsys->resetHeap(4, 1);
	gsys->resetHeap(4, 2);
	int old = gsys->setHeap(4);

	if (playerState->getCurrParts() == 30) {
		gameflow.mMoviePlayer->startMovie(77, 0, nullptr, nullptr, nullptr, -1, true);
		makeTotalScoreWindow();
	} else {
		mSection->_40 = 11;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection); // When this happens, the heap isnt restored, potential bug?
	}

	gsys->setHeap(old);
	_08 = 4;
	return nullptr;
}

/*
 * --INFO--
 * Address:	8005918C
 * Size:	0000C0
 */
void GameMovieInterface::parseMessages()
{
	for (int i = 0; i < mMesgCount; i++) {
		parse(mMesg[i]);
	}
	mMesgCount = 0;

	for (int i = 0; i < mComplexMesgCount; i++) {
		parse(mCompMesg[i]);
	}

	mComplexMesgCount = 0;
}

/*
 * --INFO--
 * Address:	8005924C
 * Size:	000428
 */
void GameMovieInterface::parse(GameMovieInterface::SimpleMessage& msg)
{
	int index = msg._04;
	switch (msg._00) {
	case 0:
		PRINT("***** START TUTORIAL WINDOW\n");
		int a  = -1;
		bool b = false;
		if (index == 17) {
			if (gameflow.mMovieInfoNum == -1) {
				if (gameflow.mMovieType == -1) {
					gameflow.mMoviePlayer->skipScene(2);
					return;
				} else if (gameflow.mMovieType == 0) {
					index = 26;
				} else {
					index = 24;
				}
			} else if (gameflow.mMovieType == 0) {
				index = gameflow.mMovieInfoNum + 92;
			} else if (gameflow.mMovieType == 1) {
				index = gameflow.mMovieInfoNum + 62;
				b     = 0;
				a     = gameflow.mMovieInfoNum;
			} else if (gameflow.mMovieType == 2) {
				int id = gameflow.mMovieInfoNum + 122;
				if (gameflow.mMovieInfoNum == 26) {
					dontShowFrame = true;
					index         = 27;
				} else {
					index = id;
				}
			} else if (gameflow.mMovieType == 3) {
				index = gameflow.mMovieInfoNum + 32;
				b     = true;
				a     = gameflow.mMovieInfoNum;
			}
		}
		createTutorialWindow(index, a, b);
		gameflow._338 = 1;
		break;
	case 1:
		ERROR("SHOULD NOT GET THIS COMMAND!!!\n");
		break;
	case 2:
		gamecore->forceDayEnd();
		gameflow._1E6 = 1;
		break;
	case 3:
		showFrame(true, 0.5f);
		break;
	case 4:
		showFrame(false, 0.5f);
		break;
	case 5:
		if (index == 0) {
			if (flowCont._234 == 1) {
				if (!gameflow.mIsChallengeMode && gameflow.mWorldClock.mCurrentDay != 30) {
					gameflow.mMoviePlayer->startMovie(47, 0, nullptr, nullptr, nullptr, -1, true);
					gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::modeFlag(1), 40.0f);
					}
					mapMgr->_4CC = 0.0f;
				} else {
					flowCont._234 = 0;
				}
			} else {
				flowCont._234 = 1;
				PRINT("got zero pikis flag!!\n");
				Navi* navi = naviMgr->getNavi(0);
				gameflow.mMoviePlayer->startMovie(46, 0, navi, &navi->mPosition, &navi->mRotation, -1, true);
				if (gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == 30) {
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::modeFlag(1), 40.0f);
					}
				}
			}
		} else {
			flowCont._234 = 2;
		}
		break;
	case 6:
		flowCont._234 = 0;
		break;
	case 7:
		gamecore->startMovie(index & 0x7fffffff, index);
		break;
	case 8:
		gamecore->endMovie(index);
		break;
	case 9:
		mSection->mTargetFade = 0.0f;
		mSection->mFadeSpeed  = 4.5f;
		break;
	case 10:
		mSection->mCurrentFade = 0.0f;
		mSection->mTargetFade  = 1.0f;
		mSection->mFadeSpeed   = 2.5f;
		break;
	case 11:
		gamecore->cleanupDayEnd();
		break;
	case 12:
		totalWindow->start();
		Jac_SceneSetup(6, 1);
		break;
	case 13:
		gamecore->forceDayEnd();
		gameflow._1E6 = 1;
		flowCont._244 = 2;
		break;
	case 14:
		gameflow._334 = index;
		break;
	case 16:
		gamecore->forceDayEnd();
		break;
	case 17:
		createMenuWindow();
		break;
	}
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
void GameMovieInterface::parse(GameMovieInterface::ComplexMessage& msg)
{
	gameflow.mMoviePlayer->startMovie(msg._00, msg._04, msg._08, &msg._0C, &msg._18, msg._24, msg._28);
}

/*
 * --INFO--
 * Address:	800596C0
 * Size:	000724
 */
NewPikiGameSection::NewPikiGameSection()
{
	Node::init("<NewPikiGameSection>");

	gameflow._1CC                 = flowCont.mCurrentStage->mStageIndex;
	gameflow.mLastUnlockedStageId = -1;

	if (playerState->isTutorial()) {
		gameflow.mWorldClock.setTime(14.8f);
	}
	flowCont._234    = 0;
	gsys->mFrameRate = 2;
	mapMgr           = nullptr;
	npgss            = nullptr;

	memStat->start("all");
	NewPikiGameSetupSection* setup = new NewPikiGameSetupSection;
	add(setup);
	memStat->end("all");

	bool print         = gsys->mTogglePrint != 0;
	gsys->mTogglePrint = 1;
	memStat->print();
	gsys->mTogglePrint = print;

	gsys->endLoading();

	PRINT("FINISHED INIT!\n");
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
	_58 = new Font;
	_58->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
	memStat->start("gui");

	memStat->start("pause");
	pauseWindow = new zen::ogScrPauseMgr;
	memStat->end("pause");

	resultWindow    = nullptr;
	totalWindow     = nullptr;
	challengeWindow = nullptr;
	memcardWindow   = nullptr;
	tutorialWindow  = nullptr;
	menuWindow      = nullptr;

	memStat->start("gameover");
	gameoverWindow = new zen::DrawGameOver;
	memStat->end("gameover");

	memStat->start("countdown");
	countWindow = new zen::DrawCountDown;
	memStat->end("countdown");

	memStat->end("gui");

	countWindow->init(gameflow.mParameters->mNightCountdown(), gameflow.mParameters->mNightEnd() - 0.01f, nullptr);
}

/*
 * --INFO--
 * Address:	80059F44
 * Size:	0001B4
 */
void NewPikiGameSetupSection::createMapObjects(MapMgr* map)
{
	gsys->getHeap(gsys->mActiveHeapIdx);
	gameflow.mTimeMultiplier = 1.0f;
	RandomAccessStream* data = gsys->openFile(flowCont.mStagePath1, true, true);
	if (data) {
		CmdStream* stream = new CmdStream(data);
		while (!stream->endOfCmds() && !stream->endOfSection()) {
			stream->getToken(true);
			if (stream->isToken("map_file")) {
				sprintf(flowCont.mAnimationTestPath, "%s", stream->getToken(true));
			} else if (stream->isToken("day_multiply")) {
				sscanf(stream->getToken(true), "%f", &gameflow.mTimeMultiplier);
			} else if (stream->isToken("dayMgr")) {
				stream->getToken(true);
				map->mDayMgr->init(stream);
			}
		}

		if (!stream->endOfCmds()) {
			stream->getToken(true);
		}
		data->close();
	}
	map->initShape();

	f32 badcompiler[6];
}

/*
 * --INFO--
 * Address:	8005A0F8
 * Size:	000020
 */
GameMovieInterface::ComplexMessage::ComplexMessage()
{
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
	_20 = _50;
	_20->open(false);
	_20->mIsMenuChanging = true;
}

/*
 * --INFO--
 * Address:	8005A178
 * Size:	000138
 */
void NewPikiGameSetupSection::update()
{
	_3D8--;
	if (!gameflow.mMoviePlayer->mIsActive) {
		if (gsys->getHeap(5)->getTopUsed()) {
			bool old           = gsys->mTogglePrint != 0;
			gsys->mTogglePrint = 1;
			gsys->resetHeap(5, true);
			gsys->mTogglePrint = old;
		}
	}
	mController->update();
	_54->update();

	if (!_3D4) {
		if (_38) {
			_34 = _38;
			_38 = nullptr;
		}
		_34 = _34->update(_3C);
	}

	if (_20) {
		_20 = _20->doUpdate(false);
	}
}

/*
 * --INFO--
 * Address:	8005A2B0
 * Size:	00000C
 */
ModeState* ModeState::update(u32& a)
{
	a = 3;
}

/*
 * --INFO--
 * Address:	8005A2BC
 * Size:	00083C
 */
void NewPikiGameSetupSection::draw(Graphics& gfx)
{
	Matrix4f mtx;

	if (gameflow._338 == 0 || gameflow._340) {
		gameflow.mMoviePlayer->update();
	}

	if (!gameflow.mMoviePlayer->setCamera(gfx)) {
		gameflow.mMoviePlayer->_168 -= gsys->getFrameTime() * 0.6f;
		if (gameflow.mMoviePlayer->_168 < 0.0f) {
			gameflow.mMoviePlayer->_168 = 0.0f;
		}
	} else {
		// gameflow.mMoviePlayer->setGameCamInfo(true,);
	}

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
void GameMovieInterface::message(int a1, int a2)
{
	if (mMesgCount >= _08) {
		return;
	}
	mMesg[mMesgCount]._00 = a1;
	mMesg[mMesgCount]._04 = a2;

	mMesgCount++;
}

/*
 * --INFO--
 * Address:	8005AB3C
 * Size:	00011C
 */
void GameMovieInterface::movie(int id, int a1, Creature* obj, Vector3f* pos, Vector3f* dir, u32 flags, bool a2)
{
	if (mComplexMesgCount >= _08) {
		return;
	}
	mCompMesg[mComplexMesgCount]._00 = id;
	mCompMesg[mComplexMesgCount]._04 = a1;
	mCompMesg[mComplexMesgCount]._08 = obj;
	if (!pos) {
		mCompMesg[mComplexMesgCount]._0C.set(0.0f, 0.0f, 0.0f);
	} else {
		mCompMesg[mComplexMesgCount]._0C = *pos;
	}
	if (!dir) {
		mCompMesg[mComplexMesgCount]._18.set(0.0f, 0.0f, 0.0f);
	} else {
		mCompMesg[mComplexMesgCount]._18 = *dir;
	}
	mCompMesg[mComplexMesgCount]._24 = flags;
	mCompMesg[mComplexMesgCount]._28 = a2;

	mComplexMesgCount++;
}

/*
 * --INFO--
 * Address:	8005AC58
 * Size:	0000C8
 */
void DayOverModeState::postRender(Graphics& gfx)
{
	Matrix4f mtx;
	if (tutorialWindow) {
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		tutorialWindow->draw(gfx);
	}

	if (gameoverWindow) {
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gameoverWindow->draw(gfx);
	}
}

/*
 * --INFO--
 * Address:	8005AD20
 * Size:	000078
 */
void MessageModeState::postRender(Graphics& gfx)
{
	Matrix4f mtx;
	if (gameoverWindow) {
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gameoverWindow->draw(gfx);
	}
}

/*
 * --INFO--
 * Address:	8005AD98
 * Size:	00000C
 */
ModeState* QuittingGameModeState::update(u32& a)
{
	a = 0;
}

/*
 * --INFO--
 * Address:	8005ADA4
 * Size:	000074
 */
void QuittingGameModeState::postUpdate()
{
	if (!gsys->getPending()) {
		gamecore->exitStage();
		gameflow.mNextOnePlayerSectionID = mSection->_40;
		gameflow.mLevelIndex             = 6;
		Jac_SceneExit(13, 0);
		gsys->softReset();
	}
}

/*
 * --INFO--
 * Address:	8005AE18
 * Size:	000004
 */
void BaseGameSection::openMenu()
{
}
