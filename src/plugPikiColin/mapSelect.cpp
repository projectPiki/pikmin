#include "MapSelect.h"
#include "Delegate.h"
#include "sysNew.h"
#include "Graphics.h"
#include "jaudio/PikiScene.h"
#include "Menu.h"
#include "Demo.h"
#include "gameflow.h"
#include "FlowController.h"
#include "DebugLog.h"

zen::DrawWorldMap* mapWindow;
zen::DrawCMcourseSelect* selectWindow;

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
DEFINE_PRINT("MapSelect")

/**
 * @brief TODO
 */
struct MapSelectSetupSection : public Node {
	MapSelectSetupSection()
	{
		setName("MapSelect section");
		_30   = new Controller;
		_20   = 0;
		mFont = new Font;
		mFont->setTexture(gsys->loadTexture("consFont.bti", true), 16, 8);
		mBigFont = new Font;
		mBigFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
		makeMapsMenu();
		mMenu->addOption(0, nullptr, nullptr, true);
		Delegate1<MapSelectSetupSection, Menu&>* delegate;
		if (!gameflow.mIsChallengeMode) {
			delegate = new Delegate1<MapSelectSetupSection, Menu&>(this, openAllMaps);
		} else {
			delegate = new Delegate1<MapSelectSetupSection, Menu&>(this, openAllChMaps);
		}
		mMenu->addOption(0, "Open All Maps", delegate, true);
		_2C = nullptr;

		mapWindow    = nullptr;
		selectWindow = 0;
		if (!gameflow.mIsChallengeMode) {
			mapWindow = new zen::DrawWorldMap;

			bool old           = gsys->mTogglePrint != 0;
			gsys->mTogglePrint = true;
			// PRINT("opening map window with %d : %d\n");
			gsys->mTogglePrint = old;

			mapWindow->start(zen::DrawWorldMap::startModeFlag(gameflow.mLastUnlockedStageId == -1 ? 0 : gameflow.mLastUnlockedStageId),
			                 zen::DrawWorldMap::startPlaceFlag(gameflow._1CC == -1 ? 0 : gameflow._1CC));
		} else {
			gameflow.mWorldClock.mCurrentDay = 1;
			selectWindow                     = new zen::DrawCMcourseSelect;
			selectWindow->start();
		}
		gsys->setFade(1.0f, 3.0f);
		_24 = 0xb0000;
	}

	virtual void update();        // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	void openAllChMaps(Menu&);
	void openAllMaps(Menu&);
	void menuSelectOption(Menu&);
	void makeMapsMenu();

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20;         // _20
	u32 _24;         // _24
	Menu* mMenu;     // _28
	Menu* _2C;       // _2C
	Controller* _30; // _30
	Font* mFont;     // _34
	Font* mBigFont;  // _38
	Camera mCamera;  // _3C
};

/*
 * --INFO--
 * Address:	8005570C
 * Size:	000368
 */
void MapSelectSetupSection::openAllChMaps(Menu& parent)
{
	for (int i = 0; i < STAGE_COUNT; i++) {
		gameflow.mGamePrefs.openStage(i);
	}

	mMenu            = new Menu(_30, mFont, false);
	mMenu->_48.mMinX = glnWidth / 2;
	mMenu->_48.mMinY = glnHeight / 2 + 30;
	mMenu->addKeyEvent(0x10, 0x1001000, new Delegate1<MapSelectSetupSection, Menu&>(this, menuSelectOption));
	mMenu->addKeyEvent(0x20, 0x2000, new Delegate1<Menu, Menu&>(mMenu, Menu::menuCloseMenu));

	for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
		if (gameflow.mIsChallengeMode) {
			PRINT("checking map in challenge mode!\n");
			bool valid = gameflow.mGamePrefs.isStageOpen(inf->mChalStageID);
			if (inf->mIsVisible && valid) {
				mMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
			}
		} else {
			bool valid = gameflow.mPlayState.isStageOpen(inf->mStageID);
			if (inf->mIsVisible && valid && inf->mChalStageID == 7) {
				mMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
			}
		}
	}

	parent.mPreviousMenu = mMenu;

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  cmpwi     r0, 0
	  stwu      r1, -0x48(r1)
	  subi      r5, r5, 0x2848
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  li        r3, 0x1
	  stw       r28, 0x38(r1)
	  blt-      .loc_0x54
	  cmpwi     r0, 0x5
	  bgt-      .loc_0x54
	  lbz       r4, 0xB6(r5)
	  slw       r0, r3, r0
	  or        r0, r4, r0
	  stb       r0, 0xB6(r5)

	.loc_0x54:
	  li        r0, 0x1
	  cmpwi     r0, 0
	  blt-      .loc_0x78
	  cmpwi     r0, 0x5
	  bgt-      .loc_0x78
	  lbz       r4, 0xB6(r5)
	  slw       r0, r3, r0
	  or        r0, r4, r0
	  stb       r0, 0xB6(r5)

	.loc_0x78:
	  li        r0, 0x2
	  cmpwi     r0, 0
	  blt-      .loc_0x9C
	  cmpwi     r0, 0x5
	  bgt-      .loc_0x9C
	  lbz       r4, 0xB6(r5)
	  slw       r0, r3, r0
	  or        r0, r4, r0
	  stb       r0, 0xB6(r5)

	.loc_0x9C:
	  li        r0, 0x3
	  cmpwi     r0, 0
	  blt-      .loc_0xC0
	  cmpwi     r0, 0x5
	  bgt-      .loc_0xC0
	  lbz       r4, 0xB6(r5)
	  slw       r0, r3, r0
	  or        r0, r4, r0
	  stb       r0, 0xB6(r5)

	.loc_0xC0:
	  li        r0, 0x4
	  cmpwi     r0, 0
	  blt-      .loc_0xE4
	  cmpwi     r0, 0x5
	  bgt-      .loc_0xE4
	  lbz       r4, 0xB6(r5)
	  slw       r0, r3, r0
	  or        r0, r4, r0
	  stb       r0, 0xB6(r5)

	.loc_0xE4:
	  li        r3, 0xB4
	  bl        -0xE7F0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x108
	  lwz       r4, 0x30(r29)
	  li        r6, 0
	  lwz       r5, 0x34(r29)
	  bl        0x7EE8

	.loc_0x108:
	  stw       r28, 0x28(r29)
	  li        r3, 0x14
	  lwz       r0, -0x7848(r13)
	  lwz       r4, 0x28(r29)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stw       r0, 0x48(r4)
	  lwz       r0, -0x7844(r13)
	  lwz       r4, 0x28(r29)
	  srawi     r5, r0, 0x1
	  addze     r5, r5
	  addi      r0, r5, 0x1E
	  stw       r0, 0x4C(r4)
	  bl        -0xE844
	  mr.       r6, r3
	  beq-      .loc_0x19C
	  lis       r4, 0x802A
	  addi      r8, r4, 0x7854
	  lwz       r0, 0x0(r8)
	  lis       r5, 0x802A
	  lwz       r7, 0x4(r8)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x20(r1)
	  addi      r0, r4, 0x7AC4
	  stw       r7, 0x24(r1)
	  lwz       r4, 0x8(r8)
	  stw       r4, 0x28(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x10(r3)

	.loc_0x19C:
	  lis       r4, 0x100
	  lwz       r3, 0x28(r29)
	  addi      r5, r4, 0x1000
	  li        r4, 0x10
	  bl        0x809C
	  li        r3, 0x14
	  bl        -0xE8BC
	  mr.       r6, r3
	  beq-      .loc_0x218
	  lis       r4, 0x802A
	  addi      r8, r4, 0x7860
	  lwz       r0, 0x0(r8)
	  lis       r5, 0x802A
	  lwz       r7, 0x4(r8)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x2C(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x30(r1)
	  lwz       r4, 0x8(r8)
	  stw       r4, 0x34(r1)
	  lwz       r4, 0x28(r29)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x10(r3)

	.loc_0x218:
	  lwz       r3, 0x28(r29)
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        0x8024
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  lis       r3, 0x803A
	  lwz       r31, 0x10(r4)
	  subi      r28, r3, 0x2848
	  b         .loc_0x338

	.loc_0x240:
	  lwz       r0, 0x2B4(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0x2BC
	  lhz       r4, 0x28(r31)
	  cmpwi     r4, 0
	  blt-      .loc_0x280
	  cmpwi     r4, 0x5
	  bgt-      .loc_0x280
	  li        r0, 0x1
	  lbz       r3, 0xB6(r28)
	  slw       r0, r0, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x284

	.loc_0x280:
	  li        r3, 0

	.loc_0x284:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x334
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x334
	  lwz       r3, 0x14(r31)
	  bl        -0x15668
	  mr        r5, r3
	  lwz       r3, 0x28(r29)
	  addi      r4, r31, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x815C
	  b         .loc_0x334

	.loc_0x2BC:
	  lhz       r4, 0x26(r31)
	  cmpwi     r4, 0
	  blt-      .loc_0x2F0
	  cmpwi     r4, 0x5
	  bgt-      .loc_0x2F0
	  li        r0, 0x1
	  lwz       r3, 0x1C8(r28)
	  slw       r0, r0, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x2F4

	.loc_0x2F0:
	  li        r3, 0

	.loc_0x2F4:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x334
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x334
	  lhz       r0, 0x28(r31)
	  cmplwi    r0, 0x7
	  bne-      .loc_0x334
	  lwz       r3, 0x14(r31)
	  bl        -0x156E4
	  mr        r5, r3
	  lwz       r3, 0x28(r29)
	  addi      r4, r31, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x80E0

	.loc_0x334:
	  lwz       r31, 0xC(r31)

	.loc_0x338:
	  cmplwi    r31, 0
	  bne+      .loc_0x240
	  lwz       r0, 0x28(r29)
	  stw       r0, 0x24(r30)
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
 * Address:	80055A74
 * Size:	0002D0
 */
void MapSelectSetupSection::openAllMaps(Menu& parent)
{
	for (int i = 0; i < STAGE_COUNT + 1; i++) {
		gameflow.mPlayState.openStage(i);
	}

	mMenu            = new Menu(_30, mFont, false);
	mMenu->_48.mMinX = glnWidth / 2;
	mMenu->_48.mMinY = glnHeight / 2 + 30;
	mMenu->addKeyEvent(0x10, 0x1001000, new Delegate1<MapSelectSetupSection, Menu&>(this, menuSelectOption));
	mMenu->addKeyEvent(0x20, 0x2000, new Delegate1<Menu, Menu&>(mMenu, Menu::menuCloseMenu));

	for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
		if (gameflow.mIsChallengeMode) {
			bool valid = gameflow.mGamePrefs.isStageOpen(inf->mChalStageID);
			if (inf->mIsVisible && valid) {
				mMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
			}
		} else {
			bool valid = gameflow.mPlayState.isStageOpen(inf->mStageID);
			if (inf->mIsVisible && valid && inf->mChalStageID == 7) {
				mMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
			}
		}
	}

	parent.mPreviousMenu = mMenu;

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  li        r31, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x38(r1)
	  addi      r28, r5, 0x1A4

	.loc_0x34:
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x1E54
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x6
	  blt+      .loc_0x34
	  li        r3, 0xB4
	  bl        -0xEAC0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x70
	  lwz       r4, 0x30(r29)
	  li        r6, 0
	  lwz       r5, 0x34(r29)
	  bl        0x7C18

	.loc_0x70:
	  stw       r28, 0x28(r29)
	  li        r3, 0x14
	  lwz       r0, -0x7848(r13)
	  lwz       r4, 0x28(r29)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stw       r0, 0x48(r4)
	  lwz       r0, -0x7844(r13)
	  lwz       r4, 0x28(r29)
	  srawi     r5, r0, 0x1
	  addze     r5, r5
	  addi      r0, r5, 0x1E
	  stw       r0, 0x4C(r4)
	  bl        -0xEB14
	  mr.       r6, r3
	  beq-      .loc_0x104
	  lis       r4, 0x802A
	  addi      r8, r4, 0x7854
	  lwz       r0, 0x0(r8)
	  lis       r5, 0x802A
	  lwz       r7, 0x4(r8)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x20(r1)
	  addi      r0, r4, 0x7AC4
	  stw       r7, 0x24(r1)
	  lwz       r4, 0x8(r8)
	  stw       r4, 0x28(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x10(r3)

	.loc_0x104:
	  lis       r4, 0x100
	  lwz       r3, 0x28(r29)
	  addi      r5, r4, 0x1000
	  li        r4, 0x10
	  bl        0x7DCC
	  li        r3, 0x14
	  bl        -0xEB8C
	  mr.       r6, r3
	  beq-      .loc_0x180
	  lis       r4, 0x802A
	  addi      r8, r4, 0x7860
	  lwz       r0, 0x0(r8)
	  lis       r5, 0x802A
	  lwz       r7, 0x4(r8)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x2C(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x30(r1)
	  lwz       r4, 0x8(r8)
	  stw       r4, 0x34(r1)
	  lwz       r4, 0x28(r29)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x10(r3)

	.loc_0x180:
	  lwz       r3, 0x28(r29)
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        0x7D54
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  lis       r3, 0x803A
	  lwz       r31, 0x10(r4)
	  subi      r28, r3, 0x2848
	  b         .loc_0x2A0

	.loc_0x1A8:
	  lwz       r0, 0x2B4(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0x224
	  lhz       r4, 0x28(r31)
	  cmpwi     r4, 0
	  blt-      .loc_0x1E8
	  cmpwi     r4, 0x5
	  bgt-      .loc_0x1E8
	  li        r0, 0x1
	  lbz       r3, 0xB6(r28)
	  slw       r0, r0, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x1EC

	.loc_0x1E8:
	  li        r3, 0

	.loc_0x1EC:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x29C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x29C
	  lwz       r3, 0x14(r31)
	  bl        -0x15938
	  mr        r5, r3
	  lwz       r3, 0x28(r29)
	  addi      r4, r31, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x7E8C
	  b         .loc_0x29C

	.loc_0x224:
	  lhz       r4, 0x26(r31)
	  cmpwi     r4, 0
	  blt-      .loc_0x258
	  cmpwi     r4, 0x5
	  bgt-      .loc_0x258
	  li        r0, 0x1
	  lwz       r3, 0x1C8(r28)
	  slw       r0, r0, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x25C

	.loc_0x258:
	  li        r3, 0

	.loc_0x25C:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x29C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x29C
	  lhz       r0, 0x28(r31)
	  cmplwi    r0, 0x7
	  bne-      .loc_0x29C
	  lwz       r3, 0x14(r31)
	  bl        -0x159B4
	  mr        r5, r3
	  lwz       r3, 0x28(r29)
	  addi      r4, r31, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x7E10

	.loc_0x29C:
	  lwz       r31, 0xC(r31)

	.loc_0x2A0:
	  cmplwi    r31, 0
	  bne+      .loc_0x1A8
	  lwz       r0, 0x28(r29)
	  stw       r0, 0x24(r30)
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
 * Address:	80055D44
 * Size:	00010C
 */
void MapSelectSetupSection::menuSelectOption(Menu& parent)
{
	StageInfo* info = (StageInfo*)parent.mCurrentItem->mFilterIndex;

	flowCont.mCurrentStage = info;
	sprintf(flowCont.mStagePath1, "%s", info->mFileName);
	sprintf(flowCont.mStagePath2, "%s", info->mFileName);

	if (gameflow.mGamePrefs._22)
		gameflow.mGamePrefs.openStage(info->mStageID);

	_24 = 0x70000;
	parent.close();

	gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
	_20 = 1;
	gsys->setFade(0.0f, 3.0f);
}

/*
 * --INFO--
 * Address:	80055E50
 * Size:	00046C
 */
MapSelectSection::MapSelectSection()
{
	Node::init("<MapSelectSection>");
	gsys->mFrameRate = 1;
	flowCont._254    = 0;
	flowCont._258    = 0;
	flowCont._24C    = 0;
	flowCont._250    = 0;
	int size         = 0x19800;
	gsys->mHeaps[SYSHEAP_Message].init("message", 2, System::alloc(size), size);
	gsys->startLoading(nullptr, true, 60);

	add(new MapSelectSetupSection);
	gsys->endLoading();

	if (gameflow.mIsChallengeMode) {
		Jac_SceneSetup(10, 0);
	} else {
		Jac_SceneSetup(3, 0);
	}

	demoParms->initCore("");
	gameflow.addGenNode("DemoFlag Parms", demoParms);

	f32 badcompiler[14];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stmw      r27, 0x6C(r1)
	  addi      r31, r4, 0x7820
	  addi      r29, r3, 0
	  subi      r4, r13, 0x72F4
	  bl        -0x20EB8
	  lis       r3, 0x8023
	  subi      r28, r3, 0x71E0
	  stw       r28, 0x0(r29)
	  addi      r3, r29, 0
	  subi      r4, r13, 0x72F4
	  bl        -0x1574C
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x79E0
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  addi      r4, r31, 0x4C
	  bl        -0x15770
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  lis       r4, 0x803A
	  stw       r0, 0x14(r3)
	  lis       r3, 0x2
	  subi      r4, r4, 0x24E0
	  li        r0, 0
	  stw       r0, 0x254(r4)
	  subi      r27, r3, 0x6800
	  addi      r3, r27, 0
	  stw       r0, 0x258(r4)
	  stw       r0, 0x24C(r4)
	  stw       r0, 0x250(r4)
	  bl        -0xEEE0
	  lwz       r4, 0x2DEC(r13)
	  addi      r6, r3, 0
	  addi      r7, r27, 0
	  addi      r3, r4, 0x144
	  subi      r4, r13, 0x72EC
	  li        r5, 0x2
	  bl        -0x315F8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x384
	  bl        -0xEF24
	  mr.       r30, r3
	  beq-      .loc_0x3D4
	  addi      r3, r30, 0
	  subi      r4, r13, 0x72F4
	  bl        -0x20F84
	  stw       r28, 0x0(r30)
	  addi      r3, r30, 0
	  subi      r4, r13, 0x72F4
	  bl        -0x15810
	  lis       r3, 0x802A
	  addi      r0, r3, 0x795C
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0x3C
	  bl        -0x12D9C
	  addi      r0, r31, 0x60
	  stw       r0, 0x4(r30)
	  li        r3, 0x50
	  bl        -0xEF6C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x164
	  addi      r3, r27, 0
	  addi      r4, r31, 0x74
	  bl        -0x20FD0
	  stw       r28, 0x0(r27)
	  addi      r3, r27, 0
	  addi      r4, r31, 0x74
	  bl        -0x1585C
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r27)
	  addi      r3, r27, 0
	  li        r4, 0x1
	  bl        -0x15600

	.loc_0x164:
	  stw       r27, 0x30(r30)
	  li        r0, 0
	  li        r3, 0x10
	  stw       r0, 0x20(r30)
	  bl        -0xEFC0
	  stw       r3, 0x34(r30)
	  addi      r4, r31, 0x84
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x16ED0
	  mr        r4, r3
	  lwz       r3, 0x34(r30)
	  li        r5, 0x10
	  li        r6, 0x8
	  bl        -0x2E334
	  li        r3, 0x10
	  bl        -0xEFF0
	  stw       r3, 0x38(r30)
	  addi      r4, r31, 0x94
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x16F00
	  mr        r4, r3
	  lwz       r3, 0x38(r30)
	  li        r5, 0x15
	  li        r6, 0x2A
	  bl        -0x2E364
	  mr        r3, r30
	  bl        .loc_0x46C
	  lwz       r3, 0x28(r30)
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x7AE0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r28, r3, 0x2B4
	  lwz       r0, 0x2B4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x26C
	  li        r3, 0x14
	  bl        -0xF058
	  cmplwi    r3, 0
	  beq-      .loc_0x264
	  lwz       r0, 0x1C(r31)
	  lis       r5, 0x802A
	  lwz       r6, 0x20(r31)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x4C(r1)
	  addi      r0, r4, 0x7AC4
	  stw       r6, 0x50(r1)
	  lwz       r4, 0x24(r31)
	  stw       r4, 0x54(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x10(r3)

	.loc_0x264:
	  mr        r6, r3
	  b         .loc_0x2CC

	.loc_0x26C:
	  li        r3, 0x14
	  bl        -0xF0BC
	  cmplwi    r3, 0
	  beq-      .loc_0x2C8
	  lwz       r0, 0x28(r31)
	  lis       r5, 0x802A
	  lwz       r6, 0x2C(r31)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x58(r1)
	  addi      r0, r4, 0x7AC4
	  stw       r6, 0x5C(r1)
	  lwz       r4, 0x30(r31)
	  stw       r4, 0x60(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x10(r3)

	.loc_0x2C8:
	  mr        r6, r3

	.loc_0x2CC:
	  lwz       r3, 0x28(r30)
	  addi      r5, r31, 0xA0
	  li        r4, 0
	  li        r7, 0x1
	  bl        0x79F0
	  li        r0, 0
	  stw       r0, 0x2C(r30)
	  stw       r0, 0x2E54(r13)
	  stw       r0, 0x2E50(r13)
	  lwz       r0, 0x0(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x384
	  li        r3, 0x368
	  bl        -0xF14C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x314
	  bl        0x184FEC

	.loc_0x314:
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  stw       r27, 0x2E54(r13)
	  subi      r3, r3, 0x2848
	  addi      r5, r4, 0x1C
	  lwz       r4, 0x1C(r4)
	  li        r0, 0x1
	  addi      r6, r3, 0x1CC
	  stw       r0, 0x0(r5)
	  neg       r3, r4
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  lwz       r3, 0x2DEC(r13)
	  rlwinm    r0,r0,0,24,31
	  stw       r0, 0x1C(r3)
	  lwz       r5, 0x0(r6)
	  cmpwi     r5, -0x1
	  bne-      .loc_0x360
	  li        r5, 0

	.loc_0x360:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r4, 0x1D0(r3)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x378
	  li        r4, 0

	.loc_0x378:
	  lwz       r3, 0x2E54(r13)
	  bl        0x18ACA0
	  b         .loc_0x3B8

	.loc_0x384:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  stw       r0, 0x2FC(r3)
	  li        r3, 0x94
	  bl        -0xF1E4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x3AC
	  bl        0x1966E0

	.loc_0x3AC:
	  stw       r27, 0x2E50(r13)
	  lwz       r3, 0x2E50(r13)
	  bl        0x196B00

	.loc_0x3B8:
	  lwz       r3, 0x2DEC(r13)
	  lis       r0, 0xB
	  lfs       f0, -0x7A90(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7A94(r2)
	  stfs      f0, 0xC(r3)
	  stw       r0, 0x24(r30)

	.loc_0x3D4:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x15C54
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2B4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x418
	  li        r3, 0xA
	  li        r4, 0
	  bl        -0x3C9E0
	  b         .loc_0x424

	.loc_0x418:
	  li        r3, 0x3
	  li        r4, 0
	  bl        -0x3C9F0

	.loc_0x424:
	  lwz       r6, 0x2F70(r13)
	  li        r5, 0
	  lis       r3, 0x803A
	  stw       r5, 0x10(r6)
	  subi      r0, r13, 0x72E4
	  subi      r3, r3, 0x2848
	  stw       r5, 0xC(r6)
	  addi      r4, r31, 0xB0
	  stw       r5, 0x8(r6)
	  stw       r0, 0x4(r6)
	  lwz       r5, 0x2F70(r13)
	  bl        -0x3540
	  mr        r3, r29
	  lmw       r27, 0x6C(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr

	.loc_0x46C:
	*/
}

/*
 * --INFO--
 * Address:	800562BC
 * Size:	000294
 */
void MapSelectSetupSection::makeMapsMenu()
{
	mMenu            = new Menu(_30, mFont, false);
	mMenu->_48.mMinX = glnWidth / 2;
	mMenu->_48.mMinY = glnHeight / 2 + 30;
	mMenu->addKeyEvent(0x10, 0x1001000, new Delegate1<MapSelectSetupSection, Menu&>(this, menuSelectOption));
	mMenu->addKeyEvent(0x20, 0x2000, new Delegate1<Menu, Menu&>(mMenu, Menu::menuCloseMenu));

	for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
		if (gameflow.mIsChallengeMode) {
			bool valid = gameflow.mGamePrefs.isStageOpen(inf->mChalStageID);
			if (inf->mIsVisible && valid) {
				mMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
			}
		} else {
			bool valid = gameflow.mPlayState.isStageOpen(inf->mStageID);
			if (inf->mIsVisible && valid && inf->mChalStageID == 7) {
				mMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
			}
		}
	}

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  li        r3, 0xB4
	  stw       r29, 0x34(r1)
	  bl        -0xF2D8
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x40
	  lwz       r4, 0x30(r30)
	  li        r6, 0
	  lwz       r5, 0x34(r30)
	  bl        0x7400

	.loc_0x40:
	  stw       r29, 0x28(r30)
	  li        r3, 0x14
	  lwz       r0, -0x7848(r13)
	  lwz       r4, 0x28(r30)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stw       r0, 0x48(r4)
	  lwz       r0, -0x7844(r13)
	  lwz       r4, 0x28(r30)
	  srawi     r5, r0, 0x1
	  addze     r5, r5
	  addi      r0, r5, 0x1E
	  stw       r0, 0x4C(r4)
	  bl        -0xF32C
	  mr.       r6, r3
	  beq-      .loc_0xD4
	  lis       r4, 0x802A
	  addi      r8, r4, 0x7854
	  lwz       r0, 0x0(r8)
	  lis       r5, 0x802A
	  lwz       r7, 0x4(r8)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x18(r1)
	  addi      r0, r4, 0x7AC4
	  stw       r7, 0x1C(r1)
	  lwz       r4, 0x8(r8)
	  stw       r4, 0x20(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x20(r1)
	  stw       r0, 0x10(r3)

	.loc_0xD4:
	  lis       r4, 0x100
	  lwz       r3, 0x28(r30)
	  addi      r5, r4, 0x1000
	  li        r4, 0x10
	  bl        0x75B4
	  li        r3, 0x14
	  bl        -0xF3A4
	  mr.       r6, r3
	  beq-      .loc_0x150
	  lis       r4, 0x802A
	  addi      r8, r4, 0x7860
	  lwz       r0, 0x0(r8)
	  lis       r5, 0x802A
	  lwz       r7, 0x4(r8)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xC(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x10(r1)
	  lwz       r4, 0x8(r8)
	  stw       r4, 0x14(r1)
	  lwz       r4, 0x28(r30)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0xC(r1)
	  lwz       r0, 0x10(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x14(r1)
	  stw       r0, 0x10(r3)

	.loc_0x150:
	  lwz       r3, 0x28(r30)
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        0x753C
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  lis       r3, 0x803A
	  lwz       r31, 0x10(r4)
	  subi      r29, r3, 0x2848
	  b         .loc_0x270

	.loc_0x178:
	  lwz       r0, 0x2B4(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x1F4
	  lhz       r4, 0x28(r31)
	  cmpwi     r4, 0
	  blt-      .loc_0x1B8
	  cmpwi     r4, 0x5
	  bgt-      .loc_0x1B8
	  li        r0, 0x1
	  lbz       r3, 0xB6(r29)
	  slw       r0, r0, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x1BC

	.loc_0x1B8:
	  li        r3, 0

	.loc_0x1BC:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x26C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x26C
	  lwz       r3, 0x14(r31)
	  bl        -0x16150
	  mr        r5, r3
	  lwz       r3, 0x28(r30)
	  addi      r4, r31, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x7674
	  b         .loc_0x26C

	.loc_0x1F4:
	  lhz       r4, 0x26(r31)
	  cmpwi     r4, 0
	  blt-      .loc_0x228
	  cmpwi     r4, 0x5
	  bgt-      .loc_0x228
	  li        r0, 0x1
	  lwz       r3, 0x1C8(r29)
	  slw       r0, r0, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x22C

	.loc_0x228:
	  li        r3, 0

	.loc_0x22C:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x26C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x26C
	  lhz       r0, 0x28(r31)
	  cmplwi    r0, 0x7
	  bne-      .loc_0x26C
	  lwz       r3, 0x14(r31)
	  bl        -0x161CC
	  mr        r5, r3
	  lwz       r3, 0x28(r30)
	  addi      r4, r31, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x75F8

	.loc_0x26C:
	  lwz       r31, 0xC(r31)

	.loc_0x270:
	  cmplwi    r31, 0
	  bne+      .loc_0x178
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80056550
 * Size:	000328
 */
void MapSelectSetupSection::update()
{
	_30->update();

	if (_2C) {
		_2C = _2C->doUpdate(false);
	} else if (!_20) {

		if (selectWindow && selectWindow->update(_30)) {
			int status = selectWindow->getReturnStatusFlag();
			if (status == -2) {
				_20 = 1;
				gsys->setFade(0.0f, 3.0f);
			} else {
				for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
					if (inf->mChalStageID == status) {
						flowCont.mCurrentStage = inf;
						sprintf(flowCont.mStagePath1, "%s", inf->mFileName);
						sprintf(flowCont.mStagePath2, "%s", inf->mFileName);

						if (gameflow.mGamePrefs._22)
							gameflow.mGamePrefs.openStage(inf->mStageID);

						_24 = 0x70000;

						gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
						_20 = 1;
						gsys->setFade(0.0f, 3.0f);
						break;
					}
				}
			}
		}

		if (mapWindow && mapWindow->update(_30)) {
			int status = mapWindow->_08;
			if (status == 6) {
				_20 = 1;
				gsys->setFade(0.0f, 3.0f);
			} else {
				for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
					if (inf->mStageID == status) {
						flowCont.mCurrentStage = inf;
						sprintf(flowCont.mStagePath1, "%s", inf->mFileName);
						sprintf(flowCont.mStagePath2, "%s", inf->mFileName);

						if (gameflow.mGamePrefs._22)
							gameflow.mGamePrefs.openStage(inf->mStageID);

						_24 = 0x70000;

						gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
						_20 = 1;
						gsys->setFade(0.0f, 3.0f);
						break;
					}
				}
			}
		}
	}

	if (_20 == 1 && !_2C && gsys->getFade() == 0.0f) {
		_20                              = -1;
		gameflow.mNextOnePlayerSectionID = _24 >> 0x10;
		Jac_SceneExit(13, 0);
		gsys->softReset();
	}

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	80056878
 * Size:	000224
 */
void MapSelectSetupSection::draw(Graphics& gfx)
{
	gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setClearColour(Colour(0, 0, 0, 0));
	gfx.clearBuffer(3, false);
	Matrix4f mtx;
	gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setColour(Colour(0, 0, 0, 255), true);
	gfx.setAuxColour(Colour(0, 0, 64, 255));
	gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

	if (selectWindow) {
		selectWindow->draw(gfx);
	}
	if (mapWindow) {
		mapWindow->draw(gfx);
	}
	Matrix4f mtx2;
	gfx.setOrthogonal(mtx2.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

	if (_2C) {
		_2C->draw(gfx, 1.0f);
	}
}

/*
 * --INFO--
 * Address:	80056A9C
 * Size:	000004
 */
void MapSelectSection::init()
{
}
