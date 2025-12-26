#include "MapSelect.h"
#include "Camera.h"
#include "Controller.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "Demo.h"
#include "FlowController.h"
#include "Font.h"
#include "Graphics.h"
#include "Menu.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "sysNew.h"
#include "system.h"
#include "zen/DrawCM.h"
#include "zen/DrawWorldMap.h"

static zen::DrawCMcourseSelect* selectWindow;
static zen::DrawWorldMap* mapWindow;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("MapSelect")

/**
 * @brief TODO
 */
struct MapSelectSetupSection : public Node {
	// fun fact: these need to be ahead of the ctor for function pointer nonsense
	void openAllMaps(Menu& parent)
	{
		PRINT("opening all maps !!\n");
		for (int i = 0; i < STAGE_COUNT + 1; i++) {
			gameflow.mPlayState.openStage(i);
		}

		makeMapsMenu();

		parent.mPreviousMenu = mMapListMenu;
		STACK_PAD_TERNARY(parent.mPreviousMenu, 1);
	}
	void openAllChMaps(Menu& parent)
	{
		PRINT("opening all challenge maps !!\n");
		for (int i = 0; i < STAGE_COUNT; i++) {
			gameflow.mGamePrefs.openStage(i);
		}

		makeMapsMenu();

		parent.mPreviousMenu = mMapListMenu;
		STACK_PAD_TERNARY(parent.mPreviousMenu, 1);
	}

	void makeMapsMenu()
	{
		mMapListMenu                     = new Menu(mController, mConsFont, false);
		mMapListMenu->mAnchorPoint.mMinX = glnWidth / 2;
		mMapListMenu->mAnchorPoint.mMinY = glnHeight / 2 + 30;
		mMapListMenu->addKeyEvent(Menu::KeyEventType::Navigate, KBBTN_START | KBBTN_A,
		                          new Delegate1<MapSelectSetupSection, Menu&>(this, &menuSelectOption));
		mMapListMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B,
		                          new Delegate1<Menu, Menu&>(mMapListMenu, &Menu::menuCloseMenu));

		for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
			if (gameflow.mIsChallengeMode) {
				PRINT("checking map in challenge mode!\n");
				bool valid = gameflow.mGamePrefs.isStageOpen(inf->mChalStageID);
				if (inf->mIsVisible && valid) {
					mMapListMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
				}
			} else {
				bool valid = gameflow.mPlayState.isStageOpen(inf->mStageID);
				if (inf->mIsVisible && valid && inf->mChalStageID == 7) {
					mMapListMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
				}
			}
		}

		STACK_PAD_VAR(2);
	}
	void menuSelectOption(Menu& parent)
	{
		StageInfo* info = (StageInfo*)parent.mCurrentItem->mFilterIndex;

		enterCourse(info);
		mNextSectionId = ONEPLAYER_NewPikiGame << 16;
		parent.close();

		gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
		mSectionState = 1;
		gsys->setFade(0.0f, 3.0f);
	}

	MapSelectSetupSection()
	{
		setName("MapSelect section");

		// This section uses `SeSystem` without constructing it.
#if defined(BUGFIX)
		seSystem = new SeSystem();
#endif

		mController   = new Controller;
		mSectionState = 0;
		mConsFont     = new Font;
		mConsFont->setTexture(gsys->loadTexture("consFont.bti", true), 16, 8);
		mBigFont = new Font;
		mBigFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
		makeMapsMenu();
		mMapListMenu->addOption(0, nullptr, nullptr, true);
		mMapListMenu->addOption(0, "Open All Maps",
		                        !gameflow.mIsChallengeMode ? new Delegate1<MapSelectSetupSection, Menu&>(this, &openAllMaps)
		                                                   : new Delegate1<MapSelectSetupSection, Menu&>(this, &openAllChMaps),
		                        true);
		mActiveOverlayMenu = nullptr;

		mapWindow    = nullptr;
		selectWindow = nullptr;
		if (!gameflow.mIsChallengeMode) {
			mapWindow = new zen::DrawWorldMap;

			bool old           = gsys->mTogglePrint != FALSE;
			gsys->mTogglePrint = TRUE;
#if defined(VERSION_PIKIDEMO)
			_Print("opening map window with %d : %d\n", gameflow.mLastUnlockedStageId, gameflow.mCurrentStageId);
#else
			(gameflow.mCurrentStageId != 0); // huh?
			PRINT("opening map window with %d : %d\n", gameflow.mLastUnlockedStageId, gameflow.mCurrentStageId);
#endif
			gsys->mTogglePrint = old;

			mapWindow->start(zen::DrawWorldMap::startModeFlag(gameflow.mLastUnlockedStageId == -1 ? 0 : gameflow.mLastUnlockedStageId),
			                 zen::DrawWorldMap::startPlaceFlag(gameflow.mCurrentStageId == -1 ? 0 : gameflow.mCurrentStageId));
		} else {
			gameflow.mWorldClock.mCurrentDay = 1;
			selectWindow                     = new zen::DrawCMcourseSelect;
			selectWindow->start();
		}
		gsys->setFade(1.0f, 3.0f);
		mNextSectionId = ONEPLAYER_GameExit << 16;
	}

	virtual void update() // _10 (weak)
	{
		mController->update();

		// This code snippet is imitating a development feature that exists in the DLLs, but this
		// might not be where the equivalent code from the DLL exists.  TODO: Figure that out.
#ifdef DEVELOP
		if (mController->keyClick(KBBTN_Z)) {
			// The gist of this code is copied from `NewPikiGameSetupSection::openMenu`.
			mActiveOverlayMenu = mMapListMenu;
			mActiveOverlayMenu->open(false);
			mActiveOverlayMenu->mIsMenuChanging = true;
		}
		if (mController->keyClick(KBBTN_L) && gameflow.mWorldClock.mCurrentDay > 1) {
			--gameflow.mWorldClock.mCurrentDay;
		}
		if (mController->keyClick(KBBTN_R) && gameflow.mWorldClock.mCurrentDay < MAX_DAYS) {
			++gameflow.mWorldClock.mCurrentDay;
		}
#endif

		if (mActiveOverlayMenu) {
			mActiveOverlayMenu = mActiveOverlayMenu->doUpdate(false);
		} else if (!mSectionState) {

			if (selectWindow && selectWindow->update(mController)) {
				int status = selectWindow->getReturnStatusFlag();
				if (status == -2) {
					mSectionState = 1;
					gsys->setFade(0.0f, 3.0f);
				} else {
					for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
						if (inf->mChalStageID == status) {
							enterCourse(inf);
							mNextSectionId = ONEPLAYER_NewPikiGame << 16;

							gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
							mSectionState = 1;
							gsys->setFade(0.0f, 3.0f);
							break;
						}
					}
				}
			}

			if (mapWindow && mapWindow->update(mController)) {
				zen::DrawWorldMap::returnStatusFlag returnStatus = mapWindow->getReturnStatusFlag();
				if (returnStatus == zen::DrawWorldMap::RETURNSTATUS_WorldMapPaused) {
					mSectionState = 1;
					gsys->setFade(0.0f, 3.0f);
				} else {
					for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
						if (inf->mStageID == returnStatus) {
							enterCourse(inf);
							mNextSectionId = ONEPLAYER_NewPikiGame << 16;

							gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
							mSectionState = 1;
							gsys->setFade(0.0f, 3.0f);
							break;
						}
					}
				}
			}
		}

		if (mSectionState == 1 && !mActiveOverlayMenu && gsys->getFade() == 0.0f) {
			mSectionState                    = -1;
			gameflow.mNextOnePlayerSectionID = mNextSectionId >> 16;
			Jac_SceneExit(13, 0);
			gsys->softReset();
		}
	}
	virtual void draw(Graphics& gfx) // _14 (weak)
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, false);
		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setColour(COLOUR_BLACK, true);
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

		if (mActiveOverlayMenu) {
			mActiveOverlayMenu->draw(gfx, 1.0f);
		}
	}

	// weak:

	// DLL inlines
	void enterCourse(StageInfo* info)
	{
		flowCont.mCurrentStage = info;
		sprintf(flowCont.mStagePath1, "%s", info->mFileName);
		sprintf(flowCont.mStagePath2, "%s", info->mFileName);
		if (gameflow.mGamePrefs.isChallengeOpen()) {
			gameflow.mGamePrefs.openStage(info->mStageID);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 mSectionState;        // _20
	u32 mNextSectionId;       // _24
	Menu* mMapListMenu;       // _28
	Menu* mActiveOverlayMenu; // _2C
	Controller* mController;  // _30
	Font* mConsFont;          // _34
	Font* mBigFont;           // _38
	Camera mCamera;           // _3C
};

/**
 * @todo: Documentation
 */
MapSelectSection::MapSelectSection()
{
	Node::init("<MapSelectSection>");
	gsys->setFrameClamp(1);
	flowCont._254 = 0;
	flowCont._258 = 0;
	flowCont._24C = 0;
	flowCont._250 = 0;
	int size      = 0x19800;
	gsys->mHeaps[SYSHEAP_Message].init("message", AYU_STACK_GROW_UP, System::alloc(size), size);
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
}
