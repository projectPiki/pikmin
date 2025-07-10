#include "NewPikiGame.h"

#include "Controller.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "Font.h"
#include "GameCoreSection.h"
#include "GameStat.h"
#include "Graphics.h"
#include "Interface.h"
#include "KIO.h"
#include "MapMgr.h"
#include "MemStat.h"
#include "Menu.h"
#include "ModeState.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "PlayerState.h"
#include "Section.h"
#include "SoundMgr.h"
#include "VersionGroups.h"
#include "gameflow.h"
#include "jaudio/pikidemo.h"
#include "sysNew.h"
#include "timers.h"
#include "zen/DrawCM.h"
#include "zen/DrawCountDown.h"
#include "zen/DrawFinalResult.h"
#include "zen/DrawGameInfo.h"
#include "zen/DrawGameOver.h"
#include "zen/ogFileChkSel.h"
#include "zen/ogMemChk.h"
#include "zen/ogMenu.h"
#include "zen/ogPause.h"
#include "zen/ogResult.h"
#include "zen/ogTotalScore.h"
#include "zen/ogTutorial.h"

/// New piki game section instance
static NewPikiGameSetupSection* npgss;

/// Core gameplay section instance
static GameCoreSection* gamecore;

/// (UNUSED), but probably the currently selected movie index
static int movieIndex;

/// UI windows for various game states
static zen::DrawCMresult* challengeWindow;
static zen::DrawGameOver* gameoverWindow;
static zen::DrawCountDown* countWindow;
static zen::ogScrPauseMgr* pauseWindow;
static zen::ogScrResultMgr* resultWindow;
static zen::DrawFinalResult* totalWindow;
static zen::ogScrFileChkSelMgr* memcardWindow;

/// Whether menu overlay is active
static bool menuOn;

/// Whether game info HUD should be displayed
static bool gameInfoOn;

/// Whether game info HUD is currently visible
static bool gameInfoIn;

/// UI windows for the main menu & tutorial
static zen::ogScrMenuMgr* menuWindow;
static zen::ogScrTutorialMgr* tutorialWindow;

/// Whether or not the demo has sound enabled
static bool hasDemoSound;

/// Whether or not to suppress HUD frame display
static bool dontShowFrame;

/// Day end result documents table
static int resultTable[16];

/**
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(61)

/**
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("newPikiGame");

/**
 * @brief State for quitting the game and returning to menu.
 */
struct QuittingGameModeState : public ModeState {
	QuittingGameModeState(BaseGameSection* c)
	    : ModeState(c)
	{
	}

	virtual ModeState* update(u32& result) // _08
	{
		PRINT("quitter updating!\n");
		result = UPDATE_NONE;
		return this;
	}

	virtual void postUpdate() // _10
	{
		// Trigger soft reset when system operations are complete
		if (!gsys->mSysOpPending) {
			PRINT("sending softreset!\n");
			gamecore->exitStage();
			gameflow.mNextOnePlayerSectionID = mSection->mNextSectionId;
			gameflow.mLevelIndex             = 6;
			Jac_SceneExit(13, 0);
			gsys->softReset();
		}
	}

	///< 00     = VTBL
	///< 00-_04 = ModeState
};

/**
 * @brief State for displaying either of the game over states
 */
struct MessageModeState : public ModeState {
	MessageModeState(BaseGameSection* c, bool flag)
	    : ModeState(c)
	{
		mMessageTimer = flag ? 5.0f : 0.5f;
	}

	virtual ModeState* update(u32& result); // _08
	virtual void postRender(Graphics& gfx)  // _0C
	{
		Matrix4f mtx;
		if (gameoverWindow) {
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			gameoverWindow->draw(gfx);
		}
	}

	///< 00     = VTBL
	///< 00-_04 = ModeState
	f32 _UNUSED08;     ///< 08, unused
	int mMessagePhase; ///< _0C, current phase of message sequence
	f32 mMessageTimer; ///< _10, timer for message transitions
};

/**
 * @brief State for handling end of day sequence
 */
struct DayOverModeState : public ModeState {
	DayOverModeState(BaseGameSection* c, int flag)
	    : ModeState(c)
	{
		flowCont.mDayOverSeqStarted = true;
		gamecore->startContainerDemo();
		gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
		gamecore->mDrawGameInfo->upperFrameOut(0.5f, true);
		gamecore->mDrawGameInfo->lowerFrameOut(0.5f, true);

		if (flag == 0) {
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! CLEANUPDAYEND!!!!\n");
			OSReport("!!!!!!!!!!!!!! CLEANUPDAYEND!!!!\n");
			OSReport("!!!!!!!!!!!!!! CLEANUPDAYEND!!!!\n");
			OSReport("!!!!!!!!!!!!!! CLEANUPDAYEND!!!!\n");
			OSReport("!!!!!!!!!!!!!! CLEANUPDAYEND!!!!\n");
			OSReport("!!!!!!!!!!!!!! CLEANUPDAYEND!!!!\n");
#endif
			gamecore->cleanupDayEnd();

			// Play day end cutscene if not last day and haven't collected all parts
			if (gameflow.mWorldClock.mCurrentDay < MAX_DAYS && playerState->getCurrParts() != MAX_UFO_PARTS && !gameflow.mIsChallengeMode) {
				mSection->mCurrentFade = -0.1f;
				gameflow.mMoviePlayer->startMovie(DEMOID_DayEnd, 0, nullptr, nullptr, nullptr, -1, true);
			}

			mSection->mTargetFade = 1.0f;
			mSection->mFadeSpeed  = 0.5f;
		}

		mState = flag;
	}

	virtual ModeState* update(u32& result); // _08
	virtual void postRender(Graphics& gfx)  // _0C
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

	///< 00     = VTBL
	///< 00-_04 = ModeState
	int mState; ///< _08, current state of the day end sequence
};

/**
 * --INFO--
 * Address:	........
 * Size:	0000E4
 *
 * @brief Controls visibility of game HUD frames.
 * @param set Whether to show (true) or hide (false) the frames
 * @param time Fade duration in seconds
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

/**
 * --INFO--
 * Address:	80056B00
 * Size:	000118
 *
 * @brief Creates and initializes the debug menu window.
 */
static void createMenuWindow()
{
	gsys->startLoading(nullptr, false, 0);
	bool heapold         = gsys->mPrevAllocType;
	gsys->mPrevAllocType = 0;
	int heapid           = gsys->getHeapNum();
	PRINT("using movie heap!\n");

	gsys->setHeap(SYSHEAP_Movie);
	int oldtype = gsys->getHeap(SYSHEAP_Movie)->setAllocType(1);

	menuWindow = new zen::ogScrMenuMgr;
	menuWindow->start();

	gsys->getHeap(SYSHEAP_Movie)->setAllocType(oldtype);
	gsys->setHeap(heapid);
	gsys->mRetraceCount  = 0;
	gsys->mPrevAllocType = heapold;
	gsys->endLoading();
	PRINT("menu window attach\n");
	gsys->attachObjs();
}

/**
 * --INFO--
 * Address:	........
 * Size:	000040
 *
 * @brief Destroys the debug menu window and frees resources.
 */
static void deleteMenuWindow()
{
	gsys->resetHeap(5, 1);
	gameflow.mIsUiOverlayActive = FALSE;
	menuWindow                  = nullptr;
}

/**
 * --INFO--
 * Address:	80056C18
 * Size:	0001B0
 *
 * @brief Creates and displays a tutorial window.
 * @param tutorialId Tutorial message ID to display
 * @param partId Part collection ID for audio (if applicable)
 * @param hasAudio Whether tutorial has associated audio
 */
static void createTutorialWindow(int tutorialId, int partId, bool hasAudio)
{
	gsys->startLoading(nullptr, false, 0);
	bool heapold         = gsys->mPrevAllocType;
	gsys->mPrevAllocType = FALSE;
	int heapid           = gsys->getHeapNum();
	PRINT("using movie heap!\n");

	hasDemoSound = (partId >= 0 && hasAudio);

	if (hasDemoSound) {
		Jac_StartPartsFindDemo(partId + 1, hasAudio);
	} else {
		Jac_StartTextDemo(tutorialId);
	}
	gsys->setHeap(5);

	int oldtype    = gsys->getHeap(SYSHEAP_Movie)->setAllocType(1);
	tutorialWindow = new zen::ogScrTutorialMgr;
	tutorialWindow->start((zen::ogScrTutorialMgr::EnumTutorial)tutorialId);

	gsys->getHeap(SYSHEAP_Movie)->setAllocType(oldtype);
	gsys->setHeap(heapid);
	showFrame(false, 0.5f);
	gameflow.mIsTutorialActive = TRUE;
	gsys->mRetraceCount        = 0;
	gsys->mPrevAllocType       = heapold;
	gsys->endLoading();
	PRINT("tutorial window attach\n");
	gsys->attachObjs();
}

/**
 * --INFO--
 * Address:	80056DC8
 * Size:	0000BC
 *
 * @brief Destroys the tutorial window and restores game state.
 */
static void deleteTutorialWindow()
{
	if (hasDemoSound) {
		Jac_FinishPartsFindDemo();
	} else {
		Jac_FinishTextDemo();
	}

	gameflow.mIsTutorialActive = FALSE;
	if (!dontShowFrame && gameInfoOn && !gameInfoIn) {
		if (!playerState->isTutorial()) {
			gamecore->mDrawGameInfo->upperFrameIn(0.5f, true);
		}
		gamecore->mDrawGameInfo->lowerFrameIn(0.5f, true);
		gameInfoIn = true;
	}

	gameflow.mIsUiOverlayActive = FALSE;
	tutorialWindow              = 0;
}

/**
 * --INFO--
 * Address:	........
 * Size:	0000A8
 *
 * @brief Handles the tutorial window update logic.
 * @param unused
 * @param controller Player input controller
 */
static void handleTutorialWindow(u32& unused, Controller* controller)
{
	if (tutorialWindow && tutorialWindow->update(controller) == zen::ogScrTutorialMgr::Status_4) {
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
		}

		deleteTutorialWindow();
	}
}

/**
 * --INFO--
 * Address:	80056E84
 * Size:	000118
 */
BaseGameSection::BaseGameSection()
    : Node("")
{
	mNextSectionId    = ONEPLAYER_MapSelect;
	mActiveMenu       = nullptr;
	mCurrentModeState = nullptr;
	mNextModeState    = nullptr;
	mController       = new Controller;
	mUpdateFlags      = UPDATE_NONE;
	mCurrentFade      = 0.0f;
	mTargetFade       = 1.0f;
	mFadeSpeed        = 0.5f;
}

/**
 * --INFO--
 * Address:	80056F9C
 * Size:	000244
 */
void BaseGameSection::draw(Graphics& gfx)
{
	Matrix4f mtx;
	gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

	// Update fade transition
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

	// Draw fade overlay
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

	// Draw level banner if active
	if (gameflow.mLevelBannerTexture && gameflow.mLevelBannerFadeValue > 0.0f) {
		gameflow.mLevelBannerFadeValue -= gsys->getFrameTime();
		if (gameflow.mLevelBannerFadeValue < 0.0f) {
			gameflow.mLevelBannerTexture   = nullptr;
			gameflow.mLevelBannerFadeValue = 0.0f;
		} else {
			gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTexture, gameflow.mLevelBannerFadeValue);
		}
	}

	mCurrentModeState->postUpdate();
}

/**
 * --INFO--
 * Address:	800571E4
 * Size:	000128
 */
ModeState* IntroGameModeState::update(u32& result)
{
	result = UPDATE_AI;

	handleTutorialWindow(result, mSection->mController);

	if (!gameflow.mMoviePlayer->mIsActive) {
		gameInfoOn = true;
		showFrame(true, 2.0f);

		return new RunningModeState(mSection);
	}

	return this;
}

/**
 * --INFO--
 * Address:	8005730C
 * Size:	000640
 */
ModeState* RunningModeState::update(u32& result)
{
	result = UPDATE_ALL; // Enable all update types

	// Check for day end during movie playback
	if (!gameflow.mMoviePlayer->mIsActive && !gameflow.mIsTutorialActive && gameflow.mIsDayEndActive) {
		result &= ~UPDATE_AI; // Disable AI updates during day end
		PRINT("*-------------------------------- DAY END !!!!!!!!!!!!!!  --------------------------------*\n");
		mSection->mNextSectionId = gameflow.mLevelIndex;
		return new DayOverModeState(mSection, 0);
	}

	// Trigger day end when time expires
	if (!gameflow.mIsDayEndActive && !gameflow.mMoviePlayer->mIsActive
	    && gameflow.mWorldClock.mTimeOfDay >= gameflow.mParameters->mEndHour()) {
		gameflow.mIsGameplayInputEnabled = FALSE;
		gameflow.mIsDayEndTriggered      = TRUE;
	}

	// Process day end trigger
	if (gameflow.mIsDayEndTriggered && !gameflow.mIsUiOverlayActive) {
		gameflow.mIsDayEndActive    = TRUE;
		gameflow.mIsDayEndTriggered = FALSE;

		// Special handling for final day
		if (playerState->getCurrParts() != MAX_UFO_PARTS && gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
			if (playerState->happyEndable()) {
				flowCont._244 = 1;
				gameflow.mGameInterface->message(MOVIECMD_StartTutorial, 28);
			} else {
				gameflow.mGameInterface->message(MOVIECMD_StartTutorial, 28);
			}
		}
	}

	bool mesgsPending = false;
	if (static_cast<GameMovieInterface*>(gameflow.mGameInterface)->mMessageCount) {
		mesgsPending = true;
	}

	// Handle pause menu
	if (gameflow.mIsGameplayInputEnabled && !gameflow.mIsUiOverlayActive && !gameflow._33C && !gameflow.mMoviePlayer->mIsActive) {

		if (mController->keyClick(KBBTN_START)) {
			if (!gameflow.mIsUiOverlayActive && !mesgsPending) {
				PRINT("starting pause menu!\n");
				seSystem->playSysSe(SYSSE_PAUSE);
				pauseWindow->start(gameflow.mIsChallengeMode);
				mCachedPauseFlag            = gameflow.mIsUiOverlayActive;
				gameflow.mIsUiOverlayActive = TRUE;
			}
		} else if (!gameflow.mIsChallengeMode && mController->keyClick(KBBTN_Y)
		           && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - 0.125f && !gameflow.mIsUiOverlayActive
		           && !mesgsPending) {
			gameflow.mGameInterface->message(MOVIECMD_CreateSettingsMenu, 0);
			mCachedPauseFlag            = gameflow.mIsUiOverlayActive;
			gameflow.mIsUiOverlayActive = TRUE;
		}
	}

	if (flowCont.mGameEndCondition) {
		if (flowCont.mGameEndCondition == 2) {
#if defined(VERSION_GPIP01_00)
			flowCont._238PAL = 0;
#endif
			mSection->mNextSectionId = ONEPLAYER_NewPikiGame;
			return new MessageModeState(mSection, false);
		}
		if (flowCont.mGameEndCondition == 1) {
#if defined(VERSION_GPIP01_00)
			flowCont._238PAL = 0;
#endif
			mSection->mNextSectionId = ONEPLAYER_NewPikiGame;
			return new MessageModeState(mSection, true);
		}
	}

	if (gameoverWindow) {
		gameoverWindow->update(mController);
	}

	if (menuWindow) {
		int state = menuWindow->update(mController);
		if (state == zen::ogScrMenuMgr::STATE_ActiveDisplay) {
			result &= ~UPDATE_AI; // Disable AI updates when menu is active
		} else if (state == zen::ogScrMenuMgr::STATE_TransitionToInactive) {
			deleteMenuWindow();
		}
	}

	handleTutorialWindow(result, mController);

	int state = pauseWindow->update(mController);
	if (state == zen::ogScrPauseMgr::PAUSE_Unk0) {
		result &= ~UPDATE_AI; // Disable AI updates when pause menu is active
	} else if (state == zen::ogScrPauseMgr::PAUSE_Unk6) {
		gamecore->forceDayEnd();
		gameflow.mIsGameplayInputEnabled = FALSE;
		gameflow.mIsDayEndTriggered      = TRUE;
		gameflow.mIsUiOverlayActive      = mCachedPauseFlag;

	} else if (state == zen::ogScrPauseMgr::PAUSE_Unk7) {
		mSection->mNextSectionId = ONEPLAYER_CardSelect;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection);
	} else if (state == zen::ogScrPauseMgr::PAUSE_Unk5) {
		showFrame(true, 0.5f);
		gameflow.mIsUiOverlayActive = mCachedPauseFlag;
		seSystem->playSysSe(SYSSE_UNPAUSE);
	}

	return this;
}

/**
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

/**
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

	if (!gameflow._33C && !gameflow.mMoviePlayer->mIsActive && mSection->mUpdateFlags & UPDATE_COUNTDOWN) {
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

/**
 * --INFO--
 * Address:	80057C5C
 * Size:	000360
 */
ModeState* MessageModeState::update(u32& result)
{
	if (flowCont.mGameEndCondition == 2) {
		switch (mMessagePhase) {
		case 0:
			mMessageTimer -= gsys->getFrameTime();
			if (mMessageTimer < 0.0f) {
				mMessageTimer               = 2.0f;
				mapMgr->mTargetDesaturation = 1.0f;
				if ((gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == MAX_DAYS) && gameoverWindow) {
					gameoverWindow->start((zen::DrawGameOver::modeFlag)0, 40.0f);
				}
				mMessagePhase = 1;
			}
			break;
		case 1:
			mMessageTimer -= gsys->getFrameTime();
			if (mMessageTimer < 0.0f) {
				mMessageTimer            = 3.0f;
				mapMgr->mTargetFadeLevel = 1.0f;
				mMessagePhase            = 2;
			}
			break;
		case 2:
			mMessageTimer -= gsys->getFrameTime();
			if (mMessageTimer < 0.0f) {
				mMessageTimer = 2.0f;
				mMessagePhase = 3;
			}
			break;
		case 3:
			mapMgr->mTargetFadeLevel    = 0.0f;
			mapMgr->mTargetDesaturation = 0.0f;
			PRINT("DOING FORCE RESULTS SCREEN !!!\n");
			DayOverModeState* state  = new DayOverModeState(mSection, 1);
			state->mState            = 0;
			mSection->mNextModeState = state;
			gamecore->cleanupDayEnd();
			if (!gameflow.mIsChallengeMode) {
				if (gameflow.mWorldClock.mCurrentDay != MAX_DAYS) {
					gameflow.mMoviePlayer->startMovie(DEMOID_OliDownDayEnd, 0, nullptr, nullptr, nullptr, -1, true);
					if (gameoverWindow) {
						gameoverWindow->start((zen::DrawGameOver::modeFlag)0, 40.0f);
					}
				}
			} else {
				gameoverWindow = nullptr;
			}
			break;
		}
	} else if (flowCont.mGameEndCondition == 0) {
		DayOverModeState* state  = new DayOverModeState(mSection, 1);
		gameoverWindow           = nullptr;
		state->mState            = 0;
		mSection->mNextModeState = state;
		mSection->mTargetFade    = 1.0f;
	}

	if (gameoverWindow) {
		gameoverWindow->update(mSection->mController);
	}
	return this;
}

/**
 * --INFO--
 * Address:	80057FBC
 * Size:	000474
 */
ModeState* DayOverModeState::update(u32& result)
{
	STACK_PAD_VAR(1);
	result = 1;

	handleTutorialWindow(result, mSection->mController);

#if defined(VERSION_GPIP01_00)
	bool skipped = false;
	if (flowCont._238PAL && playerState->getCurrParts() != 30 && gameflow.mWorldClock.mCurrentDay < 30) {
		if (mState == 0 && mSection->mController->keyClick(KBBTN_B | KBBTN_A)) {
			OSReport("!!!!!!!!!!!!!! SKIPPING !!!!\n");
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
			skipped          = true;
			flowCont._23CPAL = 1;
		}

		if (mState == 1 && (flowCont._23CPAL || mSection->mController->keyClick(KBBTN_B | KBBTN_A))) {
			skipped = true;
		}
	}
	if (!gameflow.mMoviePlayer->mIsActive || skipped) {
#else
	if (!gameflow.mMoviePlayer->mIsActive) {
#endif
		ModeState* state = nullptr;
		switch (mState) {
		case 0:
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE ONE!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE ONE!!!!\n");
#endif
			state = initialisePhaseOne();
			break;
		case 1:
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE TWO!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE TWO!!!!\n");
#endif
			state = initialisePhaseTwo();
			break;
		case 2:
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE THREE!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE THREE!!!!\n");
#endif
			state = initialisePhaseThree();
			break;
		case 3:
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE FOUR!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE FOUR!!!!\n");
#endif
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
		mSection->mNextSectionId = ONEPLAYER_MapSelect;
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
					mSection->mNextSectionId = ONEPLAYER_CardSelect;
				} else {
					mSection->mNextSectionId = ONEPLAYER_MapSelect;
				}
				gsys->setFade(0.0f, 3.0f);
				return new QuittingGameModeState(mSection);
			}
		}
	}

	if (totalWindow && totalWindow->update(mSection->mController)) {
		if (mState == 2) {
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
			totalWindow = nullptr;
		} else {
			totalWindow              = nullptr;
			mSection->mNextSectionId = ONEPLAYER_GameExit;
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
				gameflow.mPlayState.mSaveFlags          = info.mFlags;
				gameflow.mGamePrefs.mSpareSaveGameIndex = info.mIndex + 1;
				PRINT("using save game file %d with %d as the spare\n", gameflow.mGamePrefs.mSaveGameIndex,
				      gameflow.mGamePrefs.mSpareSaveGameIndex);

				bool sysbackup     = gsys->mTogglePrint != FALSE;
				gsys->mTogglePrint = TRUE;
				PRINT("doing save now!!\n");
				gameflow.mMemoryCard.saveCurrentGame();
				if (mSection->mController->keyDown(KBBTN_Z)) {
					kio->startWrite(0, (u8*)cardData, 0x26000);
				}
				gsys->mTogglePrint = sysbackup;
				STACK_PAD_VAR(1);
			}
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
		}
	}

	return this;
}

/**
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

/**
 * --INFO--
 * Address:	80058680
 * Size:	000368
 */
ModeState* DayOverModeState::initialisePhaseOne()
{
	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();
		gsys->resetHeap(SYSHEAP_Teki, 2);
		int old = gsys->setHeap(SYSHEAP_Teki);
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingWave, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setHeap(old);

	} else if (gameflow.mWorldClock.mCurrentDay >= MAX_DAYS) {
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

	mState = 1;
	return nullptr;
}

/**
 * --INFO--
 * Address:	800589E8
 * Size:	000410
 */
ModeState* DayOverModeState::initialisePhaseTwo()
{
	gsys->startLoading(nullptr, true, 120);
	PRINT("EXITDAYEND!!!!\n");
	gamecore->exitDayEnd();
#if defined(VERSION_PIKIDEMO)
	gsys->forceHardReset();
	while (true) { }
#endif
	gameflow.mMoviePlayer->fixMovieList();
	Jac_SceneSetup(6, 0);
	gsys->resetHeap(SYSHEAP_Movie, 1);
	gsys->resetHeap(SYSHEAP_Teki, 1);
	gsys->resetHeap(SYSHEAP_Teki, 2);
	int old = gsys->setHeap(SYSHEAP_Teki);

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingTakeOff, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);

	} else if (gameflow.mWorldClock.mCurrentDay < MAX_DAYS) {
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
			gameflow.mMoviePlayer->startMovie(DEMOID_NeutralEndingLeaveOK, 0, nullptr, nullptr, nullptr, -1, true);
		} else {
			gameflow.mMoviePlayer->startMovie(DEMOID_BadEndingFailEscape, 0, nullptr, nullptr, nullptr, -1, true);
			makeTotalScoreWindow();
		}
	}

	gsys->setHeap(old);
	gsys->endLoading();
	mSection->mTargetFade = 1.0f;
	mSection->mFadeSpeed  = 0.5f;
	mState                = 2;
	return nullptr;
}

/**
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

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingOnyons, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
	} else if (gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
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
	mState = 3;
	return nullptr;
}

/**
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

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		gameflow.mMoviePlayer->startMovie(DEMOID_EndingSpace, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
		makeTotalScoreWindow();
	} else {
		mSection->mNextSectionId = ONEPLAYER_GameExit;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection); // When this happens, the heap isnt restored, potential bug?
	}

	gsys->setHeap(old);
	mState = 4;
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
		mCurrentModeState = new IntroGameModeState(this);

		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

		dontShowFrame              = false;
		gameflow.mIsTutorialActive = FALSE;
		mIsInitialSetup            = true;

		lgMgr                       = new LifeGaugeMgr;
		movieIndex                  = 0;
		gameflow.mIsDayEndActive    = FALSE;
		gameflow.mIsDayEndTriggered = FALSE;
		_44                         = 0;
		mSecondController           = new Controller(2);
		mNextModeState              = nullptr;
		gameInfoIn                  = false;
		gameInfoOn                  = false;
		gameflow.mGameInterface     = new GameMovieInterface(this);

		memStat->start("animCacher");
		gameflow.mFrameCacher = new AnimFrameCacher(5000);
		memStat->end("animCacher");

		flowCont._240               = 0;
		flowCont._23C               = 0;
		flowCont.mDayOverSeqStarted = 0;

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
		gamecore = new GameCoreSection(mController, mapMgr, mGameCamera);
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

		bool old           = gsys->mTogglePrint != FALSE;
		gsys->mTogglePrint = TRUE;
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
		mActiveMenu = mSectionMenu;
		mActiveMenu->open(false);
		mActiveMenu->mIsMenuChanging = true;
	}
	virtual void update() // _10
	{
		mUpdateCountdown--;
		if (!gameflow.mMoviePlayer->mIsActive) {
			if (gsys->getHeap(SYSHEAP_Movie)->getTopUsed()) {
				bool old           = gsys->mTogglePrint != FALSE;
				gsys->mTogglePrint = TRUE;
				gsys->resetHeap(SYSHEAP_Movie, true);
				gsys->mTogglePrint = old;
			}
		}
		mController->update();
		mSecondController->update();

		if (!mIsInitialSetup) {
			if (mNextModeState) {
				mCurrentModeState = mNextModeState;
				mNextModeState    = nullptr;
			}
			mCurrentModeState = mCurrentModeState->update(mUpdateFlags);
		}

		// Three things.  1: This code snippet is imitating a development feature that exists in the DLLs, but this might not be where the
		// equivalent code from the DLL exists.  TODO: Figure that out.  2: The original code used D-Pad Down, but that's really obnoxious
		// so I chose D-Pad Up instead.  3: mSectionMenu was actually a top-level menu which could access many other menus, but that code
		// was stripped from the retail game.  TODO: Completely restore that functionality from the DLL.  For now, it's better than nothing.
#ifdef DEVELOP
		if (mController->keyClick(KBBTN_DPAD_UP)) {
			mSectionMenu = gamecore->mAiPerfDebugMenu;
			openMenu();
		}
#endif

		if (mActiveMenu) {
			mActiveMenu = mActiveMenu->doUpdate(false);
		}
	}
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f mtx;

		if (!gameflow.mIsUiOverlayActive || gameflow.mIsTutorialActive) {
			gameflow.mMoviePlayer->update();
		}

		if (!gameflow.mMoviePlayer->setCamera(gfx)) {
			// false = no scene currently active, so no preset camera information to go off
			if (gameflow.mMoviePlayer->mCamTransitionFactor > 0.0f) {
				// we're in an active transition, so follow it
				gameflow.mMoviePlayer->mCamTransitionFactor -= gsys->getFrameTime() * 0.6f;
				if (gameflow.mMoviePlayer->mCamTransitionFactor < 0.0f) {
					gameflow.mMoviePlayer->mCamTransitionFactor = 0.0f;
				}

				f32 tComp = 1.0f - gameflow.mMoviePlayer->mCamTransitionFactor;
				f32 fov   = cameraMgr->mCamera->getFov();
				f32 a     = gameflow.mMoviePlayer->mTargetFov;

				// huh.
				Vector3f unused1(cameraMgr->mCamera->getViewpoint());
				Vector3f unused2(gameflow.mMoviePlayer->mTargetViewpoint);
				Vector3f unused3(cameraMgr->mCamera->getWatchpoint());
				Vector3f unused4(gameflow.mMoviePlayer->mLookAtPos);

				gfx.mCamera->mFov = (fov - a) * tComp + a;
			} else {
				// no scene or active transition, so set to player cam
				gameflow.mMoviePlayer->setGameCamInfo(true, cameraMgr->mCamera->getFov(), cameraMgr->mCamera->getViewpoint(),
				                                      cameraMgr->mCamera->getWatchpoint());
			}

			gfx.setCamera(&mGameCamera);
			mGameCamera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), mGameCamera.mFov, 100.0f, mCameraFarClip);
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
			if (!gameflow._33C && !gameflow.mIsUiOverlayActive || gameflow.mIsTutorialActive) {
				bool check = true;
				if (gsys->mDvdErrorCode >= DvdError::ReadingDisc) {
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
			if (!mActiveMenu && menuWindow) {
				menuOn = menuWindow->draw(gfx);
			}
		}

		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		// whole section in DLL here about printing some debug text to screen

		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		if (mActiveMenu) {
			mActiveMenu->draw(gfx, 1.0f);
		}

		if (!mActiveMenu || gameflow.mMoviePlayer->mIsActive) {
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
		if (!mIsInitialSetup) {
			if (!gsys->resetPending() && (!mActiveMenu || gameflow.mMoviePlayer->mIsActive)) {
				if (!gameflow._33C && !gameflow.mIsUiOverlayActive) {
					if (!gameflow.mMoviePlayer->mIsActive && mUpdateFlags & UPDATE_WORLD_CLOCK && !playerState->isTutorial()) {
						f32 tod = gameflow.mWorldClock.mTimeOfDay;
						gameflow.mWorldClock.update(1.0f);
						f32 tod2 = gameflow.mWorldClock.mTimeOfDay;
					}
					Node::update();
				}
				gamecore->mDrawGameInfo->update();
				if (mUpdateFlags & UPDATE_AI && !(gameflow.mDemoFlags & 0x80)) {
					gamecore->updateAI();
				}
			}
		} else {
			PRINT("final setup!\n");
			gamecore->finalSetup();
			mIsInitialSetup = false;
		}
		if (mNextModeState) {
			PRINT("FORCING MODE !!!!\n");
			mCurrentModeState = mNextModeState;
			mNextModeState    = nullptr;
		}
	}

	void init2Ddata()
	{
		mGameFont = new Font;
		mGameFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
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

		STACK_PAD_VAR(6);
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
			if (playerState->isTutorial() && !gameflow.mIsDayEndActive) {
				check = false;
			}
			mapMgr->mDayMgr->refresh(gfx, check ? gameflow.mWorldClock.mTimeOfDay : 14.8f, 8);
			mCameraFarClip = 10000.0f;
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
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		mCurrentModeState->postRender(gfx);
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

	///< 00     = VTBL
	///< 00-_44 = BaseGameSection
	int _44;                       ///< 44
	u8 _48[8];                     ///< 48
	Menu* mSectionMenu;            ///< 50
	Controller* mSecondController; ///< 54
	Font* mGameFont;               ///< 58
	Camera mGameCamera;            ///< 5C
	f32 mCameraFarClip;            ///< 3A4
	Colour _3A8;                   ///< 3a8, unused
	Colour _3AC[2];                ///< 3AC, unused
	Colour _3B4[2];                ///< 3B4, unused
	Colour _3BC[2];                ///< 3BC, unused
	f32 _3C4[4];                   ///< 3C4, unused
	bool mIsInitialSetup;          ///< 3D4
	int mUpdateCountdown;          ///< 3D8
	int _3DC;                      ///< 3DC
};

/**
 * --INFO--
 * Address:	8005918C
 * Size:	0000C0
 */
void GameMovieInterface::parseMessages()
{
	for (int i = 0; i < mMessageCount; i++) {
		parse(mMesg[i]);
	}
	mMessageCount = 0;

	for (int i = 0; i < mComplexMesgCount; i++) {
		parse(mCompMesg[i]);
	}

	mComplexMesgCount = 0;
}

/**
 * --INFO--
 * Address:	8005924C
 * Size:	000428
 */
void GameMovieInterface::parse(GameMovieInterface::SimpleMessage& msg)
{
#if defined(VERSION_GPIP01_00)
	int id   = msg.mMessageId;
	int data = msg.mData;
	OSReport("!!!!!!!!!!! Got message %d : %d\n", id, data);
	switch (id) {
#else
	int data = msg.mData;
	switch (msg.mMessageId) {
#endif
	case MOVIECMD_StartTutorial:
		// Data from here uses the DEMOID_* define (cutscene ID)
		PRINT("***** START TUTORIAL WINDOW\n");
		int partId    = -1;
		bool hasAudio = false;
		if (data == DEMOID_ShipUpgrade) {
			if (gameflow.mMovieInfoNum == -1) {
				if (gameflow.mMovieType == -1) {
					gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
					return;
				} else if (gameflow.mMovieType == 0) {
					data = DEMOID_ShipUpgradeLast;
				} else {
					data = DEMOID_Unk24;
				}

			} else if (gameflow.mMovieType == 0) {
				data = gameflow.mMovieInfoNum + 92;
			} else if (gameflow.mMovieType == 1) {
				data     = gameflow.mMovieInfoNum + 62;
				hasAudio = false;
				partId   = gameflow.mMovieInfoNum;
			} else if (gameflow.mMovieType == 2) {
				PRINT("showing power up message (%d)!!\n", gameflow.mMovieInfoNum + 122);
				int id = gameflow.mMovieInfoNum + 122;
				if (gameflow.mMovieInfoNum == DEMOID_ShipUpgradeLast) {
					dontShowFrame = true;
					data          = 27;
				} else {
					data = id;
				}
			} else if (gameflow.mMovieType == 3) {
				partId   = gameflow.mMovieInfoNum;
				hasAudio = true;
				data     = gameflow.mMovieInfoNum + 32;
			}
		}

		createTutorialWindow(data, partId, hasAudio);
		gameflow.mIsUiOverlayActive = TRUE;
		break;
	case MOVIECMD_Unused:
		ERROR("SHOULD NOT GET THIS COMMAND!!!\n");
		break;
	case MOVIECMD_ForceDayEnd:
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
		break;
	case MOVIECMD_HideHUD:
		showFrame(false, 0.5f);
		break;
	case MOVIECMD_ShowHUD:
		showFrame(true, 0.5f);
		break;
	case MOVIECMD_GameEndCondition:
		if (data == 0) {
			if (flowCont.mGameEndCondition == 1) {
				if (!gameflow.mIsChallengeMode && gameflow.mWorldClock.mCurrentDay != MAX_DAYS) {
					gameflow.mMoviePlayer->startMovie(DEMOID_ExtDayEnd, 0, nullptr, nullptr, nullptr, -1, true);
					gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::modeFlag(1), 40.0f);
					}
					mapMgr->mTargetFadeLevel = 0.0f;
				} else {
					flowCont.mGameEndCondition = 0;
				}
			} else {
				flowCont.mGameEndCondition = 1;
				PRINT("got zero pikis flag!!\n");
				Navi* navi = naviMgr->getNavi(0);
				gameflow.mMoviePlayer->startMovie(DEMOID_Extinction, 0, navi, &navi->mPosition, &navi->mRotation, -1, true);
				if (gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::modeFlag(1), 40.0f);
					}
				}
			}
		} else {
			flowCont.mGameEndCondition = 2;
			PRINT("got navi dead flag!!\n");
		}
		break;
	case MOVIECMD_ForceResults:
		PRINT("got FORCE RESULTS SCREEN !!!\n");
		flowCont.mGameEndCondition = 0;
		break;
	case MOVIECMD_StartMovie:
		bool check = (data & 0x80000000) != 0;
		gamecore->startMovie(data & 0x7FFFFFFF, check);
		PRINT("%s\n", check ? "HIDING NAVI!!!" : "not hiding!");
		break;
	case MOVIECMD_EndMovie:
#if defined(VERSION_PIKIDEMO)
		gamecore->endMovie();
#else
		gamecore->endMovie(data);
#endif
		break;
	case MOVIECMD_FadeOut:
		mSection->mTargetFade = 0.0f;
		mSection->mFadeSpeed  = 4.5f;
		break;
	case MOVIECMD_FadeIn:
		mSection->mCurrentFade = 0.0f;
		mSection->mTargetFade  = 1.0f;
		mSection->mFadeSpeed   = 2.5f;
		break;
	case MOVIECMD_CleanupDayEnd:
		PRINT("MESSAGE CLEANUPDAYEND!!!!\n");
		PRINT("wwwwwhhhhyyyyyy??????|!!!\n");
		gamecore->cleanupDayEnd();
		break;
	case MOVIECMD_StartTotalResults:
		PRINT("starting total results!!\n");
		totalWindow->start();
		Jac_SceneSetup(6, 1);
		break;
	case MOVIECMD_SpecialDayEnd:
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
		flowCont._244               = 2;
		break;
	case MOVIECMD_SetInputEnabled:
		gameflow.mIsGameplayInputEnabled = data;
		break;
	case MOVIECMD_StageFinish:
		PRINT("GOT STAGE FINISH MESSAGE!!!\n");
		gamecore->forceDayEnd();
		break;
	case MOVIECMD_CreateSettingsMenu:
		createMenuWindow();
		break;
	}
}

/**
 * --INFO--
 * Address:	80059674
 * Size:	00004C
 */
void GameMovieInterface::parse(GameMovieInterface::ComplexMessage& msg)
{
	gameflow.mMoviePlayer->startMovie(msg.mMovieIdx, msg._UNUSED04, msg.mTarget, &msg.mPosition, &msg.mRotation, msg.mFlags,
	                                  msg.mIsPlaying);
}

/**
 * --INFO--
 * Address:	800596C0
 * Size:	000724
 */
NewPikiGameSection::NewPikiGameSection()
{
	Node::init("<NewPikiGameSection>");

	gameflow.mCurrentStageId      = flowCont.mCurrentStage->mStageIndex;
	gameflow.mLastUnlockedStageId = -1;

	if (playerState->isTutorial()) {
		gameflow.mWorldClock.setTime(14.8f);
	}
	flowCont.mGameEndCondition = 0;
#if defined(VERSION_GPIP01_00)
	flowCont._238PAL = 1;
	flowCont._23CPAL = 0;
#endif
	gsys->setFrameClamp(2);
	mapMgr = nullptr;
	npgss  = nullptr;

	memStat->start("all");
	NewPikiGameSetupSection* setup = new NewPikiGameSetupSection;
	add(setup);
	memStat->end("all");

	bool print         = gsys->mTogglePrint;
	gsys->mTogglePrint = TRUE;
	memStat->print();
	gsys->mTogglePrint = print;

	gsys->endLoading();

	PRINT("FINISHED INIT!\n");

	STACK_PAD_TERNARY(print, 2);
}
