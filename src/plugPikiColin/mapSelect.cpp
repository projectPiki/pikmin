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

zen::DrawCMcourseSelect* selectWindow;
zen::DrawWorldMap* mapWindow;

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
	// fun fact: these need to be ahead of the ctor for function pointer nonsense
	void openAllMaps(Menu& parent)
	{
		PRINT("opening all maps !!\n");
		for (int i = 0; i < STAGE_COUNT + 1; i++) {
			gameflow.mPlayState.openStage(i);
		}

		makeMapsMenu();

		parent.mPreviousMenu = _28;
		parent.mPreviousMenu ? "fake" : "fake";
	}
	void openAllChMaps(Menu& parent)
	{
		PRINT("opening all challenge maps !!\n");
		for (int i = 0; i < STAGE_COUNT; i++) {
			gameflow.mGamePrefs.openStage(i);
		}

		makeMapsMenu();

		parent.mPreviousMenu = _28;
		parent.mPreviousMenu ? "fake" : "fake";
	}

	void makeMapsMenu()
	{
		_28            = new Menu(mController, mConsFont, false);
		_28->_48.mMinX = glnWidth / 2;
		_28->_48.mMinY = glnHeight / 2 + 30;
		_28->addKeyEvent(0x10, KBBTN_START | KBBTN_A, new Delegate1<MapSelectSetupSection, Menu&>(this, &menuSelectOption));
		_28->addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(_28, &Menu::menuCloseMenu));

		for (StageInfo* inf = (StageInfo*)flowCont.mRootInfo.mChild; inf; inf = (StageInfo*)inf->mNext) {
			if (gameflow.mIsChallengeMode) {
				PRINT("checking map in challenge mode!\n");
				bool valid = gameflow.mGamePrefs.isStageOpen(inf->mChalStageID);
				if (inf->mIsVisible && valid) {
					_28->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
				}
			} else {
				bool valid = gameflow.mPlayState.isStageOpen(inf->mStageID);
				if (inf->mIsVisible && valid && inf->mChalStageID == 7) {
					_28->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr, true);
				}
			}
		}

		f32 badcompiler[2];
	}
	void menuSelectOption(Menu& parent)
	{
		StageInfo* info = (StageInfo*)parent.mCurrentItem->mFilterIndex;

		enterCourse(info);
		_24 = 0x70000;
		parent.close();

		gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
		_20 = 1;
		gsys->setFade(0.0f, 3.0f);
	}

	MapSelectSetupSection()
	{
		setName("MapSelect section");
		mController = new Controller;
		_20         = 0;
		mConsFont   = new Font;
		mConsFont->setTexture(gsys->loadTexture("consFont.bti", true), 16, 8);
		mBigFont = new Font;
		mBigFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
		makeMapsMenu();
		_28->addOption(0, nullptr, nullptr, true);
		_28->addOption(0, "Open All Maps",
		               !gameflow.mIsChallengeMode ? new Delegate1<MapSelectSetupSection, Menu&>(this, &openAllMaps)
		                                          : new Delegate1<MapSelectSetupSection, Menu&>(this, &openAllChMaps),
		               true);
		_2C = nullptr;

		mapWindow    = nullptr;
		selectWindow = nullptr;
		if (!gameflow.mIsChallengeMode) {
			mapWindow = new zen::DrawWorldMap;

			bool old           = gsys->mTogglePrint != 0;
			gsys->mTogglePrint = 1;
			PRINT("opening map window with %d : %d\n", gameflow.mLastUnlockedStageId, gameflow._1CC != 0);
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

	virtual void update() // _10 (weak)
	{
		mController->update();

		if (_2C) {
			_2C = _2C->doUpdate(false);
		} else if (!_20) {

			if (selectWindow && selectWindow->update(mController)) {
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

			if (mapWindow && mapWindow->update(mController)) {
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
	virtual void draw(Graphics& gfx) // _14 (weak)
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
	u32 _20;                 // _20
	u32 _24;                 // _24
	Menu* _28;               // _28
	Menu* _2C;               // _2C
	Controller* mController; // _30
	Font* mConsFont;         // _34
	Font* mBigFont;          // _38
	Camera mCamera;          // _3C
};

/*
 * --INFO--
 * Address:	80055E50
 * Size:	00046C
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
}
