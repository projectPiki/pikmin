#include "types.h"
#include "Controller.h"
#include "Section.h"
#include "ModeState.h"
#include "Interface.h"
#include "NewPikiGame.h"
#include "sysNew.h"
#include "timers.h"
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
#include "zen/ogPause.h"
#include "zen/ogResult.h"
#include "zen/DrawGameOver.h"
#include "zen/ogTotalScore.h"
#include "zen/DrawFinalResult.h"
#include "zen/ogMemChk.h"
#include "zen/ogFileChkSel.h"
#include "zen/DrawCM.h"
#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"
#include "MoviePlayer.h"
#include "Graphics.h"
#include "Font.h"
#include "DebugLog.h"

static NewPikiGameSetupSection* npgss;
static GameCoreSection* gamecore;
static int movieIndex;
static zen::DrawCMresult* challengeWindow;
static zen::DrawGameOver* gameoverWindow;
static zen::DrawCountDown* countWindow;
static zen::ogScrPauseMgr* pauseWindow;
static zen::ogScrResultMgr* resultWindow;
static zen::DrawFinalResult* totalWindow;
static zen::ogScrFileChkSelMgr* memcardWindow;
static bool menuOn;
static bool gameInfoOn;
static bool gameInfoIn;
static zen::ogScrMenuMgr* menuWindow;
static zen::ogScrTutorialMgr* tutorialWindow;
static bool hasDemoSound;
static bool dontShowFrame;

static int resultTable[16];

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

/**
 * @brief TODO
 */
struct QuittingGameModeState : public ModeState {
	QuittingGameModeState(BaseGameSection* c)
	    : ModeState(c)
	{
	}

	virtual ModeState* update(u32& a) // _08
	{
		PRINT("quitter updating!\n");
		a = 0;
		return this;
	}
	virtual void postUpdate() // _10
	{
		if (!gsys->mPending) {
			PRINT("sending softreset!\n");
			gamecore->exitStage();
			gameflow.mNextOnePlayerSectionID = mSection->_40;
			gameflow.mLevelIndex             = 6;
			Jac_SceneExit(13, 0);
			gsys->softReset();
		}
	}

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct MessageModeState : public ModeState {
	MessageModeState(BaseGameSection* c, bool flag)
	    : ModeState(c)
	{
		_10 = flag ? 5.0f : 0.5f;
	}

	virtual ModeState* update(u32&);       // _08
	virtual void postRender(Graphics& gfx) // _0C
	{
		Matrix4f mtx;
		if (gameoverWindow) {
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			gameoverWindow->draw(gfx);
		}
	}

	// _00     = VTBL?
	// _00-_04 = ModeState?
	f32 _08; // _08
	int _0C; // _0C
	f32 _10; // _10
};

/**
 * @brief TODO
 */
struct DayOverModeState : public ModeState {
	DayOverModeState(BaseGameSection* c, int flag)
	    : ModeState(c)
	{
		flowCont._238 = true;
		gamecore->startContainerDemo();
		gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
		gamecore->mDrawGameInfo->upperFrameOut(0.5f, true);
		gamecore->mDrawGameInfo->lowerFrameOut(0.5f, true);
		if (flag == 0) {
			gamecore->cleanupDayEnd();

			if (gameflow.mWorldClock.mCurrentDay < 30 && playerState->getCurrParts() != 30 && !gameflow.mIsChallengeMode) {
				mSection->mCurrentFade = -0.1f;
				gameflow.mMoviePlayer->startMovie(28, 0, nullptr, nullptr, nullptr, -1, true);
			}

			mSection->mTargetFade = 1.0f;
			mSection->mFadeSpeed  = 0.5f;
		}
		_08 = flag;
	}

	virtual ModeState* update(u32&);       // _08
	virtual void postRender(Graphics& gfx) // _0C
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

	void makeTotalScoreWindow();
	ModeState* initialisePhaseOne();
	ModeState* initialisePhaseTwo();
	ModeState* initialisePhaseThree();
	ModeState* initialisePhaseFour();

	// _00     = VTBL?
	// _00-_04 = ModeState?
	int _08; // _08
};

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
static void showFrame(bool set, f32 time)
{
	if (set) {
		if (gameInfoOn && !gameInfoIn) {
			if (!playerState->isTutorial()) {
				gamecore->mDrawGameInfo->upperFrameIn(time, true);
			}
			gamecore->mDrawGameInfo->lowerFrameIn(time, true);
			gameInfoIn = true;
		}
	} else {
		if (gameInfoOn && gameInfoIn) {
			if (!playerState->isTutorial()) {
				gamecore->mDrawGameInfo->upperFrameOut(time, true);
			}
			gamecore->mDrawGameInfo->lowerFrameOut(time, true);
			gameInfoIn = false;
		}
	}
}

/*
 * --INFO--
 * Address:	80056B00
 * Size:	000118
 */
static void createMenuWindow()
{
	gsys->startLoading(nullptr, false, 0);
	int heapold = !!gsys->_2A4;
	gsys->_2A4  = 0;
	int heapid  = gsys->getHeapNum();
	PRINT("using movie heap!\n");

	gsys->setHeap(SYSHEAP_Movie);
	int oldtype = gsys->getHeap(SYSHEAP_Movie)->setAllocType(1);

	menuWindow = new zen::ogScrMenuMgr;
	menuWindow->start();

	gsys->getHeap(SYSHEAP_Movie)->setAllocType(oldtype);
	gsys->setHeap(heapid);
	gsys->_2A0 = 0;
	gsys->_2A4 = heapold;
	gsys->endLoading();
	PRINT("menu window attach\n");
	gsys->attachObjs();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
static void deleteMenuWindow()
{
	gsys->resetHeap(5, 1);
	gameflow._338 = 0;
	menuWindow    = nullptr;
}

/*
 * --INFO--
 * Address:	80056C18
 * Size:	0001B0
 */
static void createTutorialWindow(int a1, int a2, bool flag)
{
	gsys->startLoading(nullptr, false, 0);
	int heapold = gsys->_2A4 != 0;
	gsys->_2A4  = 0;
	int heapid  = gsys->getHeapNum();
	PRINT("using movie heap!\n");

	hasDemoSound = (a2 >= 0 && flag);

	if (hasDemoSound) {
		Jac_StartPartsFindDemo(a2 + 1, flag);
	} else {
		Jac_StartTextDemo(a1);
	}
	gsys->setHeap(5);

	int oldtype    = gsys->getHeap(SYSHEAP_Movie)->setAllocType(1);
	tutorialWindow = new zen::ogScrTutorialMgr;
	tutorialWindow->start((zen::ogScrTutorialMgr::EnumTutorial)a1);

	gsys->getHeap(5)->setAllocType(oldtype);
	gsys->setHeap(heapid);
	showFrame(false, 0.5f);
	gameflow._340 = 1;
	gsys->_2A0    = 0;
	gsys->_2A4    = heapold;
	gsys->endLoading();
	PRINT("tutorial window attach\n");
	gsys->attachObjs();
}

/*
 * --INFO--
 * Address:	80056DC8
 * Size:	0000BC
 */
static void deleteTutorialWindow()
{
	if (hasDemoSound) {
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
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
static void handleTutorialWindow(u32&, Controller* controller)
{
	if (tutorialWindow && tutorialWindow->update(controller) == zen::ogScrTutorialMgr::Status_4) {
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(2);
		}
		deleteTutorialWindow();
	}
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
		f32 fade = mCurrentFade;
		if (fade < 0.0f) {
			fade = 0.0f;
		} else if (fade > 1.0f) {
			fade = 1.0f;
		}

		gfx.setColour(Colour(0, 0, 0, (int)((1.0f - fade) * 255.0f)), true);
		gfx.setAuxColour(Colour(0, 0, 0, (int)((1.0f - fade) * 255.0f)));
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
}

/*
 * --INFO--
 * Address:	800571E4
 * Size:	000128
 */
ModeState* IntroGameModeState::update(u32& a)
{
	a = 1;

	handleTutorialWindow(a, mSection->mController);

	if (!gameflow.mMoviePlayer->mIsActive) {
		gameInfoOn = true;
		showFrame(true, 2.0f);

		return new RunningModeState(mSection);
	}
	return this;
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

	if (!gameflow._1E4 && !gameflow.mMoviePlayer->mIsActive && gameflow.mWorldClock.mTimeOfDay >= gameflow.mParameters->mEndHour()) {
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

	bool mesgsPending = false;
	if (static_cast<GameMovieInterface*>(gameflow.mGameInterface)->mMesgCount) {
		mesgsPending = true;
	}
	if (gameflow._334 && !gameflow._338 && !gameflow._33C && !gameflow.mMoviePlayer->mIsActive) {

		if (mController->keyClick(KBBTN_START)) {
			if (!gameflow._338 && !mesgsPending) {
				PRINT("starting pause menu!\n");
				seSystem->playSysSe(SYSSE_PAUSE);
				pauseWindow->start(!!gameflow.mIsChallengeMode);
				_08           = !!gameflow._338;
				gameflow._338 = 1;
			}
		} else if (!gameflow.mIsChallengeMode && mController->keyClick(KBBTN_Y)
		           && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - 0.125f && !gameflow._338 && !mesgsPending) {
			gameflow.mGameInterface->message(17, 0);
			_08           = !!gameflow._338;
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
			deleteMenuWindow();
		}
	}

	handleTutorialWindow(a, mController);

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
		showFrame(true, 0.5f);
		gameflow._338 = _08;
		seSystem->playSysSe(SYSSE_UNPAUSE);
	}
	return this;
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
				_10                                       = 2.0f;
				mapMgr->mTargetGreyscaleDesaturationLevel = 1.0f;
				if ((gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == 30) && gameoverWindow) {
					gameoverWindow->start((zen::DrawGameOver::modeFlag)0, 40.0f);
				}
				_0C = 1;
			}
			break;
		case 1:
			_10 -= gsys->getFrameTime();
			if (_10 < 0.0f) {
				_10                             = 3.0f;
				mapMgr->mTargetFadeToBlackLevel = 1.0f;
				_0C                             = 2;
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
			mapMgr->mTargetFadeToBlackLevel           = 0.0f;
			mapMgr->mTargetGreyscaleDesaturationLevel = 0.0f;
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
	u32 badCompiler;
	a = 1;

	handleTutorialWindow(a, mSection->mController);

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
			PRINT("EXITDAYEND!!!!\n");
			gamecore->exitDayEnd();
			gameflow.mMoviePlayer->fixMovieList();
			Jac_SceneSetup(6, 0);
			gsys->resetHeap(5, 1);
			gsys->resetHeap(4, 1);
			gsys->resetHeap(4, 2);
			int heapIdx = gsys->setHeap(SYSHEAP_Teki);
			gsys->setHeap(heapIdx);
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
				gameflow.mPlayState._23             = info._04;
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
				u32 badCompiler2;
			}
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
		}
	}

	return this;
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
	info.mBornPikis = playerState->getLastPikmins();
	info.mDeadPikis = playerState->getFinalDeadPikis();
	info.mParts     = playerState->getCurrParts();
	gameflow.mGamePrefs.checkIsHiscore(info);

	zen::TotalScoreRecord* record = new zen::TotalScoreRecord;
	record->mParts                = info.mParts;
	record->mDay                  = info.mDay;
	record->mPikis                = info.mBornPikis;
	record->mDeadPikis            = info.mDeadPikis;
	record->mTotalPikis           = gameflow.mGamePrefs.mHiscores.mTotalPikis;

	for (int i = 0; i < 5; i++) {
		record->mRecordNumParts[i] = gameflow.mGamePrefs.mHiscores.mMinDayRecords[i].mNumParts;
		record->mRecordNumDays[i]  = gameflow.mGamePrefs.mHiscores.mMinDayRecords[i].mNumDays;
		record->mRecordNumBorn[i]  = gameflow.mGamePrefs.mHiscores.mBornPikminRecords[i].mNumBorn;
		record->mRecordNumDead[i]  = gameflow.mGamePrefs.mHiscores.mDeadPikminRecords[i].mNumDead;
		if (record->mRecordNumDead[i] == 9999) {
			record->mRecordNumDead[i] = -1;
		}
	}

	record->mPartsDaysRank = info.mPartsDaysRank;
	record->mBornPikisRank = info.mBornPikisRank;
	record->mDeadPikisRank = info.mDeadPikisRank;

	totalWindow = new zen::DrawFinalResult(record);
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
		gsys->resetHeap(SYSHEAP_Teki, 2);
		int old = gsys->setHeap(SYSHEAP_Teki);
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingWave, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setHeap(old);

	} else if (gameflow.mWorldClock.mCurrentDay >= 30) {
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();
		gsys->resetHeap(SYSHEAP_Teki, 2);
		int old    = gsys->setHeap(SYSHEAP_Teki);
		u32 flags  = 0;
		u32 ids[3] = { Red, Yellow, Blue };
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
		u32 flags2             = flags | 0xFFFF07FF;
		mSection->mCurrentFade = -0.1f;
		mSection->mTargetFade  = 1.0f;
		gameflow.mMoviePlayer->startMovie(DEMOID_BadEnding, 0, nullptr, nullptr, nullptr, flags2, true);
		gameoverWindow = nullptr;
		gsys->setHeap(old);
	} else {
		gsys->resetHeap(SYSHEAP_Teki, 2);
		int old                = gsys->setHeap(SYSHEAP_Teki);
		gameoverWindow         = nullptr;
		mSection->mCurrentFade = -0.1f;
		gameflow.mMoviePlayer->startMovie(DEMOID_ChalDayEnd, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
		if (!playerState->isTutorial() && !gameflow.mIsChallengeMode) {
			u32 flags  = 0;
			u32 ids[3] = { Red, Yellow, Blue };
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
			gameflow.mMoviePlayer->startMovie(DEMOID_TakeOff, 0, nullptr, nullptr, nullptr, flags | 0xFFFF07FF, true);
		}
		gsys->setHeap(old);
	}

	_08 = 1;
	return nullptr;
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
	gsys->resetHeap(SYSHEAP_Movie, 1);
	gsys->resetHeap(SYSHEAP_Teki, 1);
	gsys->resetHeap(SYSHEAP_Teki, 2);
	int old = gsys->setHeap(SYSHEAP_Teki);

	if (playerState->getCurrParts() == 30) {
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingTakeOff, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);

	} else if (gameflow.mWorldClock.mCurrentDay < 30) {
		PRINT("LOADING YOZURA MOVIE!!\n");
		gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayResults, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);

		if (playerState->hasContainer(Red)) {
			gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayRedOnyon, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
		}
		if (playerState->hasContainer(Yellow)) {
			gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayYellowOnyon, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
		}
		if (playerState->hasContainer(Blue)) {
			gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayBlueOnyon, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
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
			PRINT("starting challenge mode window %d : %d!\n", GameStat::formationPikis, GameStat::containerPikis);
			info.mCourseID = flowCont.mCurrentStage->mChalStageID;
			info.mScore    = GameStat::allPikis;
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
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingOnyons, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
	} else if (gameflow.mWorldClock.mCurrentDay == 30) {
		if (playerState->happyEndable()) {
			gameflow.mMoviePlayer->startMovie(DEMOID_EndingSpace, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
			makeTotalScoreWindow();
		} else {
			u32 flags  = 0;
			u32 ids[3] = { Red, Yellow, Blue };
			for (int i = 0; i < 3; i++) {
				if (playerState->hasContainer(ids[i])) {
					flags |= 1 << (i + 12);
				}
			}
			u32 mask = flags | 0xFFFF07FF;
			PRINT("playing movie with mask = %08x\n", mask);
			gamecore->prepareBadEnd();
			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mMoviePlayer->startMovie(DEMOID_BadEndingOlimin, 0, nullptr, nullptr, nullptr, mask, true);
			gameoverWindow = nullptr;
		}
	}

	gsys->setHeap(old);
	gsys->endLoading();
	_08 = 3;
	return nullptr;
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
		gameflow.mMoviePlayer->startMovie(DEMOID_EndingSpace, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
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

/**
 * @brief TODO
 *
 * @note Yes I know this sucks to be so far down the file.
 * @note UNFORTUNATELY IT'S REQUIRED BECAUSE SDATA SUCKS.
 */
struct NewPikiGameSetupSection : public BaseGameSection {
	NewPikiGameSetupSection()
	{
		_34 = new IntroGameModeState(this);

		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

		dontShowFrame = false;
		gameflow._340 = 0;
		_3D4          = true;

		lgMgr                   = new LifeGaugeMgr;
		movieIndex              = 0;
		gameflow._1E4           = 0;
		gameflow._1E6           = 0;
		_44                     = 0;
		_54                     = new Controller(2);
		_38                     = nullptr;
		gameInfoIn              = false;
		gameInfoOn              = false;
		gameflow.mGameInterface = new GameMovieInterface(this);

		memStat->start("animCacher");
		gameflow.mFrameCacher = new AnimFrameCacher(5000);
		memStat->end("animCacher");

		flowCont._240 = 0;
		flowCont._23C = 0;
		flowCont._238 = 0;

		int size1 = 0x280000;
		gsys->mHeaps[4].init("teki", 2, new u8[size1], size1); // size 0xa00000 in the DLL
		int size2 = 0x40000;
		gsys->mHeaps[5].init("movie", 2, new u8[size2], size2);

		PRINT("now doing map!\n");
		memStat->start("mapMgr");
		memStat->start("constructor");
		mapMgr = new MapMgr(mController);
		memStat->end("constructor");

		memStat->start("shape");
		createMapObjects(mapMgr);
		memStat->end("shape");
		memStat->end("mapMgr");

		Jac_SceneSetup(5, flowCont.mCurrentStage->mStageID < 5 ? flowCont.mCurrentStage->mStageID : 0);
		init2Ddata();
		gamecore = new GameCoreSection(mController, mapMgr, _5C);
		add(gamecore);

		// a bunch of menu stuff here in the DLL

		flowCont._254 = 0;
		flowCont._258 = 0;
		_3A8.set(96, 128, 255, 0);

		memStat->start("effects");
		mapMgr->initEffects();
		memStat->end("effects");

		memStat->start("mapMgr");
		mapMgr->createLights();
		memStat->end("mapMgr");

		gamecore->initStage();
		_3AC[0].set(0, 0, 48, 255);
		_3AC[1].set(48, 48, 48, 255);
		_3B4[0].set(0, 0, 0, 0);
		_3B4[1].set(64, 64, 192, 255);
		_3BC[0].set(0, 0, 0, 0);
		_3BC[1].set(192, 64, 0, 255);

		_3C4[0] = 150.0f;
		_3C4[1] = 750.0f;
		_3C4[2] = 1000.0f;
		_3C4[3] = 3000.0f;

		bool old           = gsys->mTogglePrint != 0;
		gsys->mTogglePrint = 1;
		PRINT("tekiHeap has %d bytes free\n", gsys->getHeap(SYSHEAP_Teki)->getFree());
		gsys->mTogglePrint = old;

		if (playerState->isTutorial()) {
			gameflow.mMoviePlayer->startMovie(DEMOID_OlimarWakeUp, 0, nullptr, nullptr, nullptr, -1, true);
		} else if (flowCont.mCurrentStage->mStageID < 5) {
			gameflow.mMoviePlayer->startMovie(DEMOID_Landing, 0, nullptr, nullptr, nullptr, -1, true);
		}
		gsys->setFade(1.0f, 3.0f);
	}

	virtual void openMenu() // _30
	{
		_20 = _50;
		_20->open(false);
		_20->mIsMenuChanging = true;
	}
	virtual void update() // _10
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
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f mtx;

		if (gameflow._338 == 0 || gameflow._340) {
			gameflow.mMoviePlayer->update();
		}

		if (!gameflow.mMoviePlayer->setCamera(gfx)) {
			if (gameflow.mMoviePlayer->_168 > 0.0f) {
				gameflow.mMoviePlayer->_168 -= gsys->getFrameTime() * 0.6f;
				if (gameflow.mMoviePlayer->_168 < 0.0f) {
					gameflow.mMoviePlayer->_168 = 0.0f;
				}

				f32 tComp = 1.0f - gameflow.mMoviePlayer->_168;
				f32 fov   = cameraMgr->mCamera->getFov();
				f32 a     = gameflow.mMoviePlayer->_144;

				// huh.
				Vector3f unused1(cameraMgr->mCamera->getViewpoint());
				Vector3f unused2(gameflow.mMoviePlayer->_12C);
				Vector3f unused3(cameraMgr->mCamera->getWatchpoint());
				Vector3f unused4(gameflow.mMoviePlayer->mLookAtPos);

				gfx.mCamera->mFov = (fov - a) * tComp + a;
			} else {
				gameflow.mMoviePlayer->setGameCamInfo(true, cameraMgr->mCamera->getFov(), cameraMgr->mCamera->getViewpoint(),
				                                      cameraMgr->mCamera->getWatchpoint());
			}

			gfx.setCamera(&_5C);
			_5C.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), _5C.mFov, 100.0f, _3A4);
		}

		if (!(gameflow.mDemoFlags & 0x80)) {
			gsys->mTimer->start("preRender", true);
			preRender(gfx);
			gsys->mTimer->stop("preRender");
		}

		// need these to be commented out, otherwise gsys does weird things in the next if block.
		// gsys->mTimer->start("mainRender", true);
		mainRender(gfx);
		// gsys->mTimer->stop("mainRender");

		if (effectMgr) {
			if (gameflow._33C == 0 && gameflow._338 == 0 || gameflow._340) {
				bool check = true;
				if (gsys->_258 >= 0) {
					check = false;
				}
				if (check) {
					effectMgr->update();
				}
			}
			effectMgr->draw(gfx);
		}

		if (!(gameflow.mDemoFlags & 0x80)) {
			menuOn = false;
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			postRender(gfx);
			if (!_20 && menuWindow) {
				menuOn = menuWindow->draw(gfx);
			}
		}

		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		// whole section in DLL here about printing some debug text to screen

		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		if (_20) {
			_20->draw(gfx, 1.0f);
		}

		if (!_20 || gameflow.mMoviePlayer->mIsActive) {
			if (challengeWindow) {
				gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
				challengeWindow->draw(gfx);
			}
			if (resultWindow) {
				gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
				resultWindow->draw(gfx);
			}
			if (totalWindow) {
				gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
				totalWindow->draw(gfx);
			}
			if (memcardWindow) {
				gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
				memcardWindow->draw(gfx);
			}
		}

		BaseGameSection::draw(gfx);
		if (!_3D4) {
			if (!gsys->resetPending() && (!_20 || gameflow.mMoviePlayer->mIsActive)) {
				if (!gameflow._33C && !gameflow._338) {
					if (!gameflow.mMoviePlayer->mIsActive && _3C & 0x2 && !playerState->isTutorial()) {
						f32 tod = gameflow.mWorldClock.mTimeOfDay;
						gameflow.mWorldClock.update(1.0f);
						f32 tod2 = gameflow.mWorldClock.mTimeOfDay;
					}
					Node::update();
				}
				gamecore->mDrawGameInfo->update();
				if (_3C & 1 && !(gameflow.mDemoFlags & 0x80)) {
					gamecore->updateAI();
				}
			}
		} else {
			PRINT("final setup!\n");
			gamecore->finalSetup();
			_3D4 = false;
		}
		if (_38) {
			PRINT("FORCING MODE !!!!\n");
			_34 = _38;
			_38 = nullptr;
		}
	}

	void init2Ddata()
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
	void createMapObjects(MapMgr* map)
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

	void preRender(Graphics& gfx) { gamecore->mMapMgr->preRender(gfx); }
	void mainRender(Graphics& gfx)
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, false);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
		if (!memcardWindow && !(gameflow.mDemoFlags & 0x80)) {
			bool check = true;
			if (playerState->isTutorial() && !gameflow._1E4) {
				check = false;
			}
			mapMgr->mDayMgr->refresh(gfx, check ? gameflow.mWorldClock.mTimeOfDay : 14.8f, 8);
			_3A4 = 10000.0f;
			Node::draw(gfx);
		} else {
			mapMgr->mDayMgr->refresh(gfx, 25.0f, 8);
			gameflow.mMoviePlayer->addLights(gfx);
			gfx.calcLighting(1.0f);
			gameflow.mMoviePlayer->refresh(gfx);
			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.flushCachedShapes();
		}
	}
	void postRender(Graphics& gfx)
	{
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, 60.0f, gfx.mCamera->mAspectRatio, 1.0f, gfx.mCamera->mFar, 1.0f);
		Matrix4f mtx;
		mtx.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));
		gfx.mRenderState = 0x700;
		_34->postRender(gfx);
		Matrix4f mtx2;
		gfx.setOrthogonal(mtx2.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	}

	// unused DLL inlines:
	void menuQuitGame(Menu&);
	void menuChangeCourse(Menu&);
	void menuDayEnd(Menu&);
	void menuIncreaseFrame(Menu&);
	void menuDecreaseFrame(Menu&);
	void menuIncreaseMovie(Menu&);
	void menuDecreaseMovie(Menu&);
	void menuPlayMovie(Menu&);
	void menuPauseMovie(Menu&);

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	int _44;         // _44
	u8 _48[8];       // _48
	Menu* _50;       // _50
	Controller* _54; // _54
	Font* _58;       // _58
	Camera _5C;      // _5C
	f32 _3A4;        // _3A4
	Colour _3A8;     // _3a8
	Colour _3AC[2];  // _3AC
	Colour _3B4[2];  // _3B4
	Colour _3BC[2];  // _3BC
	f32 _3C4[4];     // _3C4
	bool _3D4;       // _3D4
	int _3D8;        // _3D8
	int _3DC;        // _3DC
};

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
	switch (msg.mCommand) {
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
				b     = false;
				a     = gameflow.mMovieInfoNum;
			} else if (gameflow.mMovieType == 2) {
				PRINT("showing power up message (%d)!!\n", gameflow.mMovieInfoNum + 122);
				int id = gameflow.mMovieInfoNum + 122;
				if (gameflow.mMovieInfoNum == DEMOID_ShipUpgradeLast) {
					dontShowFrame = true;
					index         = 27;
				} else {
					index = id;
				}
			} else if (gameflow.mMovieType == 3) {
				a     = gameflow.mMovieInfoNum;
				b     = true;
				index = gameflow.mMovieInfoNum + 32;
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
		showFrame(false, 0.5f);
		break;
	case 4:
		showFrame(true, 0.5f);
		break;
	case 5:
		if (index == 0) {
			if (flowCont._234 == 1) {
				if (!gameflow.mIsChallengeMode && gameflow.mWorldClock.mCurrentDay != 30) {
					gameflow.mMoviePlayer->startMovie(DEMOID_ExtDayEnd, 0, nullptr, nullptr, nullptr, -1, true);
					gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::modeFlag(1), 40.0f);
					}
					mapMgr->mTargetFadeToBlackLevel = 0.0f;
				} else {
					flowCont._234 = 0;
				}
			} else {
				flowCont._234 = 1;
				PRINT("got zero pikis flag!!\n");
				Navi* navi = naviMgr->getNavi(0);
				gameflow.mMoviePlayer->startMovie(DEMOID_Extinction, 0, navi, &navi->mPosition, &navi->mRotation, -1, true);
				if (gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == 30) {
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::modeFlag(1), 40.0f);
					}
				}
			}
		} else {
			flowCont._234 = 2;
			PRINT("got navi dead flag!!\n");
		}
		break;
	case 6:
		PRINT("got FORCE RESULTS SCREEN !!!\n");
		flowCont._234 = 0;
		break;
	case 7:
		bool check = (index & 0x80000000) != 0;
		gamecore->startMovie(index & 0x7FFFFFFF, check);
		PRINT("%s\n", check ? "HIDING NAVI!!!" : "not hiding!");
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
		PRINT("MESSAGE CLEANUPDAYEND!!!!\n");
		PRINT("wwwwwhhhhyyyyyy??????|!!!\n");
		gamecore->cleanupDayEnd();
		break;
	case 12:
		PRINT("starting total results!!\n");
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
		PRINT("GOT STAGE FINISH MESSAGE!!!\n");
		gamecore->forceDayEnd();
		break;
	case 17:
		createMenuWindow();
		break;
	}
}

/*
 * --INFO--
 * Address:	80059674
 * Size:	00004C
 */
void GameMovieInterface::parse(GameMovieInterface::ComplexMessage& msg)
{
	gameflow.mMoviePlayer->startMovie(msg.mMovieIdx, msg._04, msg.mTarget, &msg.mPosition, &msg.mRotation, msg.mFlags, msg.mIsPlaying);
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
	flowCont._234 = 0;
	gsys->setFrameClamp(2);
	mapMgr = nullptr;
	npgss  = nullptr;

	memStat->start("all");
	NewPikiGameSetupSection* setup = new NewPikiGameSetupSection;
	add(setup);
	memStat->end("all");

	u32 print          = !!gsys->mTogglePrint;
	gsys->mTogglePrint = 1;
	memStat->print();
	gsys->mTogglePrint = print;

	gsys->endLoading();

	PRINT("FINISHED INIT!\n");

	print ? "fake" : "fake";
	print ? "fake" : "fake";
}
