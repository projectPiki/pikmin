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
#include "LifeGauge.h"
#include "MapMgr.h"
#include "MemStat.h"
#include "Menu.h"
#include "ModeState.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "Pellet.h"
#include "PlayerState.h"
#include "Section.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
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

struct NewPikiGameSetupSection;

/// New piki game section instance
static NewPikiGameSetupSection* npgss;

/// Core gameplay section instance
static GameCoreSection* gamecore;

/// Current index of the Movie Player debug menu. (See `CinDemoIDs` enum)
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
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(61)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("newPikiGame");

/**
 * @brief TODO
 */
struct GameMovieInterface : public GameInterface {
	GameMovieInterface(NewPikiGameSetupSection* section)
	{
		mMessageLimit = 32;
		mMessageCount = 0;
		mSection      = section;
	}

	/**
	 * @brief TODO
	 */
	struct SimpleMessage {
		int mMessageId; // _00
		int mData;      // _04
	};

	/**
	 * @brief TODO
	 */
	struct ComplexMessage {
		ComplexMessage() { }

		int mMovieIdx;      // _00
		int _UNUSED04;      // _04
		Creature* mTarget;  // _08
		Vector3f mPosition; // _0C
		Vector3f mRotation; // _18
		int mFlags;         // _24
		bool mIsPlaying;    // _28
	};

	virtual void message(int msgId, int data) // _08
	{
		if (mMessageCount >= mMessageLimit) {
			return;
		}

		mMesg[mMessageCount].mMessageId = msgId;
		mMesg[mMessageCount].mData      = data;

		mMessageCount++;
	}
	virtual void movie(int id, int a1, Creature* obj, immut Vector3f* pos, immut Vector3f* dir, u32 flags, bool a2) // _0C
	{
		if (mComplexMesgCount >= mMessageLimit) {
			return;
		}
		mCompMesg[mComplexMesgCount].mMovieIdx = id;
		mCompMesg[mComplexMesgCount]._UNUSED04 = a1;
		mCompMesg[mComplexMesgCount].mTarget   = obj;
		if (!pos) {
			mCompMesg[mComplexMesgCount].mPosition.set(0.0f, 0.0f, 0.0f);
		} else {
			mCompMesg[mComplexMesgCount].mPosition = *pos;
		}
		if (!dir) {
			mCompMesg[mComplexMesgCount].mRotation.set(0.0f, 0.0f, 0.0f);
		} else {
			mCompMesg[mComplexMesgCount].mRotation = *dir;
		}
		mCompMesg[mComplexMesgCount].mFlags     = flags;
		mCompMesg[mComplexMesgCount].mIsPlaying = a2;

		mComplexMesgCount++;
	}
	virtual void parseMessages();        // _10
	virtual void parse(SimpleMessage&);  // _18
	virtual void parse(ComplexMessage&); // _1C

	// _00 = VTBL
	NewPikiGameSetupSection* mSection; // _04
	int mMessageLimit;                 // _08
	SimpleMessage mMesg[32];           // _0C
	int mMessageCount;                 // _10C
	ComplexMessage mCompMesg[32];      // _110
	int mComplexMesgCount;             // _690
};

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
			gameflow.mNextOnePlayerSectionID       = mSection->mPendingOnePlayerSectionID;
			gameflow.mNextOnePlayerSectionOnDayEnd = ONEPLAYER_MapSelect;
			Jac_SceneExit(SCENE_Unk13, 0);
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
			gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
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
		flowCont.mIsDayEndSeqStarted = TRUE;
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
#else
			PRINT("CLEANUPDAYEND!!!!\n");
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
			gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
			tutorialWindow->draw(gfx);
		}

		if (gameoverWindow) {
			gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
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
 * @brief Controls visibility of game HUD frames.
 * @param set Whether to show (true) or hide (false) the frames
 * @param time Fade duration in seconds
 *
 * @note UNUSED Size: 0000E4
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
	int oldtype = gsys->getHeap(SYSHEAP_Movie)->setAllocType(AYU_STACK_GROW_DOWN);

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
 * @brief Destroys the debug menu window and frees resources.
 * @note UNUSED Size: 000040
 */
static void deleteMenuWindow()
{
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	PRINT("menu window detach\n");
	gameflow.mIsUIOverlayActive = FALSE;
	menuWindow                  = nullptr;
}

/**
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
	gsys->setHeap(SYSHEAP_Movie);

	int oldtype    = gsys->getHeap(SYSHEAP_Movie)->setAllocType(AYU_STACK_GROW_DOWN);
	tutorialWindow = new zen::ogScrTutorialMgr;
	tutorialWindow->start((zen::ogScrTutorialMgr::EnumTutorial)tutorialId);

	gsys->getHeap(SYSHEAP_Movie)->setAllocType(oldtype);
	gsys->setHeap(heapid);
	showFrame(false, 0.5f);
	gameflow.mIsTutorialTextActive = TRUE;
	gsys->mRetraceCount            = 0;
	gsys->mPrevAllocType           = heapold;
	gsys->endLoading();
	PRINT("tutorial window attach\n");
	gsys->attachObjs();
}

/**
 * @brief Destroys the tutorial window and restores game state.
 */
static void deleteTutorialWindow()
{
	if (hasDemoSound) {
		Jac_FinishPartsFindDemo();
	} else {
		Jac_FinishTextDemo();
	}

	gameflow.mIsTutorialTextActive = FALSE;
	if (!dontShowFrame && gameInfoOn && !gameInfoIn) {
		if (!playerState->isTutorial()) {
			gamecore->mDrawGameInfo->upperFrameIn(0.5f, true);
		}
		gamecore->mDrawGameInfo->lowerFrameIn(0.5f, true);
		gameInfoIn = true;
	}

	gameflow.mIsUIOverlayActive = FALSE;
	tutorialWindow              = 0;
}

/**
 * @brief Handles the tutorial window update logic.
 * @param unused
 * @param controller Player input controller
 *
 * @note UNUSED Size: 0000A8
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
 * @todo: Documentation
 */
BaseGameSection::BaseGameSection()
    : Node("")
{
	mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
	mActiveMenu                = nullptr;
	mCurrentModeState          = nullptr;
	mNextModeState             = nullptr;
	mController                = new Controller(1);
	mUpdateFlags               = UPDATE_NONE;
	mCurrentFade               = 0.0f;
	mTargetFade                = 1.0f;
	mFadeSpeed                 = 0.5f;
}

/**
 * @todo: Documentation
 */
void BaseGameSection::draw(Graphics& gfx)
{
	Matrix4f mtx;
	gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));

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
		gfx.fillRectangle(AREA_FULL_SCREEN(gfx));
	}

	// Draw level banner if active
	if (gameflow.mLevelBannerTex && gameflow.mLevelBannerFadeValue > 0.0f) {
		gameflow.mLevelBannerFadeValue -= gsys->getFrameTime();
		if (gameflow.mLevelBannerFadeValue < 0.0f) {
			gameflow.mLevelBannerTex       = nullptr;
			gameflow.mLevelBannerFadeValue = 0.0f;
		} else {
			gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTex, gameflow.mLevelBannerFadeValue);
		}
	}

	mCurrentModeState->postUpdate();
}

/**
 * @todo: Documentation
 */
ModeState* IntroGameModeState::update(u32& result)
{
	result = UPDATE_AI;

	handleTutorialWindow(result, mSection->mController);

	if (!gameflow.mMoviePlayer->mIsActive) {
		PRINT("switching to running!\n");
		gameInfoOn = true;
		showFrame(true, 2.0f);

		return new RunningModeState(mSection);
	}

	return this;
}

/**
 * @todo: Documentation
 */
ModeState* RunningModeState::update(u32& result)
{
	result = UPDATE_ALL; // Enable all update types

	// Check for day end during movie playback
	if (!gameflow.mMoviePlayer->mIsActive && !gameflow.mIsTutorialTextActive && gameflow.mIsDayEndActive) {
		result &= ~UPDATE_AI; // Disable AI updates during day end
		PRINT("*-------------------------------- DAY END !!!!!!!!!!!!!!  --------------------------------*\n");
		mSection->mPendingOnePlayerSectionID = gameflow.mNextOnePlayerSectionOnDayEnd;
		return new DayOverModeState(mSection, 0);
	}

	// Trigger day end when time expires
	if (!gameflow.mIsDayEndActive && !gameflow.mMoviePlayer->mIsActive
	    && gameflow.mWorldClock.mTimeOfDay >= gameflow.mParameters->mEndHour()) {
#if defined(VERSION_G98E01_PIKIDEMO)
#else
		gameflow.mIsPauseAllowed = FALSE;
#endif
		gameflow.mIsDayEndTriggered = TRUE;
	}

	// Process day end trigger
	if (gameflow.mIsDayEndTriggered && !gameflow.mIsUIOverlayActive) {
		gameflow.mIsDayEndActive    = TRUE;
		gameflow.mIsDayEndTriggered = FALSE;

		// Special handling for final day
		if (playerState->getCurrParts() != MAX_UFO_PARTS && gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
			if (playerState->happyEndable()) {
				flowCont.mEndingType = ENDING_Neutral;
				gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_BadEnding);
			} else {
				gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_BadEnding);
			}
		}
	}

	bool mesgsPending = false;
	if (static_cast<GameMovieInterface*>(gameflow.mGameInterface)->mMessageCount) {
		mesgsPending = true;
	}

	// Handle pause menu
	if (gameflow.mIsPauseAllowed && !gameflow.mIsUIOverlayActive && !gameflow.mPauseAll && !gameflow.mMoviePlayer->mIsActive) {

		if (mController->keyClick(KBBTN_START)) {
			if (!gameflow.mIsUIOverlayActive && !mesgsPending) {
				PRINT("starting pause menu!\n");
				seSystem->playSysSe(SYSSE_PAUSE);
				pauseWindow->start(gameflow.mIsChallengeMode);
				mCachedPauseFlag            = gameflow.mIsUIOverlayActive;
				gameflow.mIsUIOverlayActive = TRUE;
			}
		}
		// I added a bugfix to prevent the OgRader screen from opening in the background when the debug menu is active.  Many
		// debug menus also use the Y button, and both being open at the same time can even cause crashes in the Movie Player.
#if defined(VERSION_G98E01_PIKIDEMO)
		else if (mController->keyClick(KBBTN_Y) && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - 0.125f
		         && !gameflow.mIsUIOverlayActive && !mesgsPending && TERNARY_BUGFIX(!mSection->mActiveMenu, true))
#else
		else if (!gameflow.mIsChallengeMode && mController->keyClick(KBBTN_Y)
		         && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - 0.125f && !gameflow.mIsUIOverlayActive
		         && !mesgsPending && TERNARY_BUGFIX(!mSection->mActiveMenu, true))
#endif
		{
			gameflow.mGameInterface->message(MOVIECMD_CreateMenuWindow, 0);
			mCachedPauseFlag            = gameflow.mIsUIOverlayActive;
			gameflow.mIsUIOverlayActive = TRUE;
		}
#if defined(DEVELOP) || defined(WIN32)
		// Mapping this to d-pad down was genuinely an atrocious choice, so I'm assigning it to d-pad up.
		else if (mController->keyUnClick(TERNARY_BUILD_MATCHING(KBBTN_DPAD_DOWN, KBBTN_DPAD_UP))) {
			mSection->openMenu();
		}
#endif
	}

	// check if we have an unhandled forced game end pending
	if (flowCont.mGameEndFlag != GAMEEND_None) {
		if (flowCont.mGameEndFlag == GAMEEND_NaviDown) {
			// you killed your captain!
#if defined(VERSION_GPIP01_00)
			flowCont.mIsDayEndSkippable = FALSE;
#endif
			mSection->mPendingOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			return new MessageModeState(mSection, false);
		}

		if (flowCont.mGameEndFlag == GAMEEND_PikminExtinction) {
			// you killed all your pikmin!
#if defined(VERSION_GPIP01_00)
			flowCont.mIsDayEndSkippable = FALSE;
#endif
			mSection->mPendingOnePlayerSectionID = ONEPLAYER_NewPikiGame;
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
#if defined(VERSION_G98E01_PIKIDEMO)
#else
		gameflow.mIsPauseAllowed = FALSE;
#endif
		gameflow.mIsDayEndTriggered = TRUE;
		gameflow.mIsUIOverlayActive = mCachedPauseFlag;

	} else if (state == zen::ogScrPauseMgr::PAUSE_Unk7) {
#if defined(VERSION_G98E01_PIKIDEMO)
		gsys->forceHardReset();
#else
		mSection->mPendingOnePlayerSectionID = ONEPLAYER_CardSelect;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection);
#endif
	} else if (state == zen::ogScrPauseMgr::PAUSE_Unk5) {
		showFrame(true, 0.5f);
		gameflow.mIsUIOverlayActive = mCachedPauseFlag;
		seSystem->playSysSe(SYSSE_UNPAUSE);
	}

	return this;
}

/**
 * @todo: Documentation
 */
void IntroGameModeState::postRender(Graphics& gfx)
{
	Matrix4f mtx;
	if (tutorialWindow) {
		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
		tutorialWindow->draw(gfx);
	}
}

/**
 * @todo: Documentation
 */
void RunningModeState::postRender(Graphics& gfx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx2.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));

	if (!menuOn) {
		gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
		gamecore->draw1D(gfx);
	}

	if (!gameflow.mPauseAll && !gameflow.mMoviePlayer->mIsActive && mSection->mUpdateFlags & UPDATE_COUNTDOWN) {
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
		gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
		tutorialWindow->draw(gfx);
	}

	gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
	gamecore->draw2D(gfx);

	if (gameoverWindow) {
		gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
		gameoverWindow->draw(gfx);
	}

	gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
	pauseWindow->draw(gfx);
}

/**
 * @todo: Documentation
 */
ModeState* MessageModeState::update(u32& result)
{
	if (flowCont.mGameEndFlag == GAMEEND_NaviDown) {
		// you killed your captain!
		switch (mMessagePhase) {
		case 0:
			mMessageTimer -= gsys->getFrameTime();
			if (mMessageTimer < 0.0f) {
				mMessageTimer               = 2.0f;
				mapMgr->mTargetDesaturation = 1.0f;
				if ((gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == MAX_DAYS) && gameoverWindow) {
					gameoverWindow->start(zen::DrawGameOver::MODE_NaviDown, 40.0f);
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
			PRINT("CLEANUPDAYEND!!!!\n");
			gamecore->cleanupDayEnd();
			if (!gameflow.mIsChallengeMode) {
				if (gameflow.mWorldClock.mCurrentDay != MAX_DAYS) {
					gameflow.mMoviePlayer->startMovie(DEMOID_OliDownDayEnd, 0, nullptr, nullptr, nullptr, -1, true);
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::MODE_NaviDown, 40.0f);
					}
				}
			} else {
				gameoverWindow = nullptr;
			}
			break;
		}
	} else if (flowCont.mGameEndFlag == GAMEEND_None) {
		// you really shouldn't be here, but there's nothing to handle. go straight to results
		PRINT("DOING FORCE RESULTS SCREEN !!!\n");
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
 * @todo: Documentation
 */
ModeState* DayOverModeState::update(u32& result)
{
	STACK_PAD_VAR(1);
	result = 1;

	handleTutorialWindow(result, mSection->mController);

#if defined(VERSION_GPIP01_00)
	bool skipped = false;
	if (flowCont.mIsDayEndSkippable && playerState->getCurrParts() != 30 && gameflow.mWorldClock.mCurrentDay < 30) {
		if (mState == 0 && mSection->mController->keyClick(KBBTN_B | KBBTN_A)) {
			OSReport("!!!!!!!!!!!!!! SKIPPING !!!!\n");
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
			skipped                   = true;
			flowCont.mIsDayEndSkipped = TRUE;
		}

		if (mState == 1 && (flowCont.mIsDayEndSkipped || mSection->mController->keyClick(KBBTN_B | KBBTN_A))) {
			skipped = true;
		}
	}
	if (!gameflow.mMoviePlayer->mIsActive || skipped)
#else
	if (!gameflow.mMoviePlayer->mIsActive)
#endif
	{
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
		mSection->mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
		gsys->setFade(0.0f, 3.0f);
		return new QuittingGameModeState(mSection);
	}

	if (resultWindow) {
		zen::ogScrResultMgr::returnStatusFlag stat = resultWindow->update(mSection->mController);
		if (stat >= 7) {
			gsys->startLoading(nullptr, true, 120);
			PRINT("EXITDAYEND!!!!\n");
			gamecore->exitDayEnd();
			gameflow.mMoviePlayer->fixMovieList();
			Jac_SceneSetup(SCENE_Unk6, 0);
			gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
			gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
			gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
			int heapIdx = gsys->setHeap(SYSHEAP_Teki);
			gsys->setHeap(heapIdx);
			gsys->endLoading();

#if defined(VERSION_G98E01_PIKIDEMO)
#else
			if (!memcardWindow) {
#endif
			if (stat == 8) {
				mSection->mPendingOnePlayerSectionID = ONEPLAYER_CardSelect;
			} else {
				mSection->mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
			}
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
#if defined(VERSION_G98E01_PIKIDEMO)
#else
			}
#endif
		}
	}

	if (totalWindow && totalWindow->update(mSection->mController)) {
		if (mState == 2) {
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
			totalWindow = nullptr;
		} else {
			totalWindow                          = nullptr;
			mSection->mPendingOnePlayerSectionID = ONEPLAYER_GameExit;
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
		}
	}

#if defined(VERSION_G98E01_PIKIDEMO)
#else
	if (memcardWindow) {
		CardQuickInfo info;
		int state = memcardWindow->update(mSection->mController, info);
		if (state >= 1) {
			memcardWindow = nullptr;
			if (state != 1 && state != 5) {
				gameflow.mPlayState.mSaveSlot              = info.mGameSaveSlot;
				gameflow.mGamePrefs.mSpareMemCardSaveIndex = info.mMemCardSaveIndex + 1;
				PRINT("using save game file %d with %d as the spare\n", gameflow.mGamePrefs.mMemCardSaveIndex,
				      gameflow.mGamePrefs.mSpareMemCardSaveIndex);

				bool sysbackup     = gsys->mTogglePrint != FALSE;
				gsys->mTogglePrint = TRUE;
				PRINT("doing save now!!\n");
				gameflow.mMemoryCard.saveCurrentGame();
				if (mSection->mController->keyDown(KBBTN_Z)) {
					kio->startWrite(KIOWRITE_MemoryCard, cardData, CARD_DATA_SIZE);
				}
				gsys->mTogglePrint = sysbackup;
				STACK_PAD_VAR(1);
			}
			gsys->setFade(0.0f, 3.0f);
			return new QuittingGameModeState(mSection);
		}
	}
#endif

	return this;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
ModeState* DayOverModeState::initialisePhaseOne()
{
	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();
		gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
		int old = gsys->setHeap(SYSHEAP_Teki);
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingWave, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setHeap(old);

	} else if (gameflow.mWorldClock.mCurrentDay >= MAX_DAYS) {
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();
		gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
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
		gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
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
 * @todo: Documentation
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
	Jac_SceneSetup(SCENE_Unk6, 0);
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
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
			info.mStageID = flowCont.mCurrentStage->mChalStageID;
			info.mScore   = GameStat::allPikis;
			gameflow.mGamePrefs.checkIsHiscore(info);
			challengeWindow = new zen::DrawCMresult;
			challengeWindow->start(info);
		}
	} else {
		// we've hit max days, and haven't collected 30 parts :(
		if (playerState->happyEndable()) {
			flowCont.mEndingType = ENDING_Neutral;
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
 * @todo: Documentation
 */
ModeState* DayOverModeState::initialisePhaseThree()
{
	gsys->startLoading(nullptr, true, 120);
	gameflow.mMoviePlayer->fixMovieList();
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
	int old = gsys->setHeap(SYSHEAP_Teki);
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
 * @todo: Documentation
 */
ModeState* DayOverModeState::initialisePhaseFour()
{
	gameflow.mMoviePlayer->fixMovieList();
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
	int old = gsys->setHeap(SYSHEAP_Teki);

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		gameflow.mMoviePlayer->startMovie(DEMOID_EndingSpace, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, true);
		makeTotalScoreWindow();
	} else {
		mSection->mPendingOnePlayerSectionID = ONEPLAYER_GameExit;
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

		dontShowFrame                  = false;
		gameflow.mIsTutorialTextActive = FALSE;
		mIsInitialSetup                = true;

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

		flowCont.mIsSunsetStateForceEnded = FALSE;
		flowCont.mIsSunsetWhistleActive   = FALSE;
		flowCont.mIsDayEndSeqStarted      = FALSE;

		int size1 = 0x280000; // = 0xa00000 in the DLL
		gsys->mHeaps[SYSHEAP_Teki].init("teki", AYU_STACK_GROW_UP, new u8[size1], size1);
		int size2 = 0x40000;
		gsys->mHeaps[SYSHEAP_Movie].init("movie", AYU_STACK_GROW_UP, new u8[size2], size2);

		PRINT("now doing map!\n");
		memStat->start("mapMgr");
		memStat->start("constructor");
		mapMgr = new MapMgr(mController);
		memStat->end("constructor");

		memStat->start("shape");
		createMapObjects(mapMgr);
		memStat->end("shape");
		memStat->end("mapMgr");

		Jac_SceneSetup(SCENE_Unk5, flowCont.mCurrentStage->mStageID < STAGE_COUNT ? flowCont.mCurrentStage->mStageID : 0);
		init2Ddata();
		gamecore = new GameCoreSection(mController, mapMgr, mGameCamera);
		add(gamecore);

#if defined(DEVELOP) || defined(WIN32)
		typedef Delegate1<NewPikiGameSetupSection, Menu&> NPGSSDelegate1; // This is an insanely long typename to spell.

		Menu* optionsMenu               = new Menu(mController, gsys->mConsFont);
		optionsMenu->mAnchorPoint.mMinX = glnWidth / 2;
		optionsMenu->mAnchorPoint.mMinY = glnHeight / 2;
		optionsMenu->mDiffuseColour.set(128, 32, 32, 255);
		optionsMenu->mHighlightColour.set(32, 32, 32, 128);
		optionsMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B,
		                         new Delegate1<Menu, Menu&>(optionsMenu, &Menu::menuCloseMenu));

		gameflow.addOptionsMenu(optionsMenu);

		Menu* movieMenu               = new Menu(mController, gsys->mConsFont);
		movieMenu->mAnchorPoint.mMinX = glnWidth - 110;
		movieMenu->mAnchorPoint.mMinY = glnHeight - 88;
		movieMenu->mDiffuseColour.set(128, 32, 32, 255);
		movieMenu->mHighlightColour.set(32, 32, 32, 128);
		movieMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B, new Delegate1<Menu, Menu&>(movieMenu, Menu::menuCloseMenu));

		char* movieBuf = new char[0x40];
		sprintf(movieBuf, "Movie #%d", movieIndex);
		movieMenu->addOption(0, movieBuf, nullptr);
		movieMenu->addKeyEvent(Menu::KeyEventType::Input, KBBTN_Y, new NPGSSDelegate1(this, &menuDecreaseMovie));
		movieMenu->addKeyEvent(Menu::KeyEventType::Input, KBBTN_X, new NPGSSDelegate1(this, &menuIncreaseMovie));
		movieMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		movieMenu->addOption(0, "Play / Stop", new NPGSSDelegate1(this, &menuPlayMovie));
		movieMenu->addOption(0, "Pause / Frame Step", nullptr);
		movieMenu->addKeyEvent(Menu::KeyEventType::Release, KBBTN_A, new NPGSSDelegate1(this, &menuPauseMovie));
		movieMenu->addKeyEvent(Menu::KeyEventType::Input, KBBTN_X, new NPGSSDelegate1(this, &menuIncreaseFrame));
		movieMenu->addKeyEvent(Menu::KeyEventType::Input, KBBTN_Y, new NPGSSDelegate1(this, &menuDecreaseFrame));

		Menu* filterMenu               = new Menu(mController, gsys->mConsFont);
		filterMenu->mAnchorPoint.mMinX = glnWidth / 2;
		filterMenu->mAnchorPoint.mMinY = glnHeight / 2;
		filterMenu->mDiffuseColour.set(128, 32, 32, 255);
		filterMenu->mHighlightColour.set(32, 32, 32, 128);
		filterMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B, new Delegate1<Menu, Menu&>(filterMenu, Menu::menuCloseMenu));

		gameflow.addFilterMenu(filterMenu);

		mSectionMenu                     = new Menu(mController, gsys->mConsFont);
		mSectionMenu->mAnchorPoint.mMinX = glnWidth / 2;
		mSectionMenu->mAnchorPoint.mMinY = glnHeight / 2;
		mSectionMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B,
		                          new Delegate1<Menu, Menu&>(mSectionMenu, &Menu::menuCloseMenu));

		mSectionMenu->addOption(0, "Change Course", new NPGSSDelegate1(this, &menuChangeCourse));
		mSectionMenu->addOption(0, "Day End", new NPGSSDelegate1(this, &menuDayEnd));
		mSectionMenu->addMenu(optionsMenu, 0, "Options");
		mSectionMenu->addMenu(gamecore->mAiPerfDebugMenu, 0, "Kando Options");
		if (mapMgr->mDayMgr) {
			mSectionMenu->addMenu(mapMgr->mDayMgr->mMenu, 0, "Lighting");
		}
		mSectionMenu->addMenu(movieMenu, 0, "Movie Player");
		mSectionMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mSectionMenu->addOption(0, "Quit", new NPGSSDelegate1(this, &menuQuitGame));
#endif

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
				gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
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

		if (mActiveMenu) {
			mActiveMenu = mActiveMenu->doUpdate(false);
		}
	}
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f mtx;

		if (!gameflow.mIsUIOverlayActive || gameflow.mIsTutorialTextActive) {
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

				// In the final game, these leftovers from demo got left on the stack.
				Vector3f unused1(cameraMgr->mCamera->getViewpoint());
				Vector3f unused2(gameflow.mMoviePlayer->mTargetViewpoint);
				Vector3f unused3(cameraMgr->mCamera->getWatchpoint());
				Vector3f unused4(gameflow.mMoviePlayer->mLookAtPos);

#if defined(VERSION_G98E01_PIKIDEMO)
				f32 fov2 = sinf(HALF_PI * tComp);
				fov2     = sinf(HALF_PI * fov2);
				fov2     = sinf(HALF_PI * fov2);
				fov2     = sinf(HALF_PI * fov2);

				gfx.mCamera->mFov = (fov - a) * fov2 + a;

				unused1.set(unused1 - unused2);
				unused1.set(unused1 * tComp);
				gfx.mCamera->mPosition.set(unused1 + unused2);

				unused3.set(unused3 - unused4);
				unused3.set(unused3 * tComp);
				gfx.mCamera->mFocus.set(unused3 + unused4);

				gfx.mCamera->calcLookAt(gfx.mCamera->mPosition, gfx.mCamera->mFocus, nullptr);
#else
				gfx.mCamera->mFov = (fov - a) * tComp + a;
#endif
			} else {
				// no scene or active transition, so set to player cam
				gameflow.mMoviePlayer->setGameCamInfo(true, cameraMgr->mCamera->getFov(), cameraMgr->mCamera->getViewpoint(),
				                                      cameraMgr->mCamera->getWatchpoint());
			}

			gfx.setCamera(&mGameCamera);
			mGameCamera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), mGameCamera.mFov, 100.0f, mCameraFarClip);
		}

		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
			gsys->mTimer->start("preRender", true);
			preRender(gfx);
			gsys->mTimer->stop("preRender");
		}

// need these to be commented out, otherwise gsys does weird things in the next if block.
#if defined(VERSION_G98E01_PIKIDEMO)
		gsys->mTimer->start("mainRender", true);
#else
		MATCHING_START_TIMER("mainRender", true);
#endif
		mainRender(gfx);
#if defined(VERSION_G98E01_PIKIDEMO)
		gsys->mTimer->stop("mainRender");
#else
		MATCHING_STOP_TIMER("mainRender");
#endif

		if (effectMgr) {
			if (!gameflow.mPauseAll && !gameflow.mIsUIOverlayActive || gameflow.mIsTutorialTextActive) {

#if defined(VERSION_G98E01_PIKIDEMO)
				gsys->mTimer->start("effect", true);
#endif
				bool check = true;
				if (gsys->mDvdErrorCode >= DvdError::ReadingDisc) {
					check = false;
				}

				if (check) {
					effectMgr->update();
				}
#if defined(VERSION_G98E01_PIKIDEMO)
				gsys->mTimer->stop("effect");
#endif
			}

#if defined(VERSION_G98E01_PIKIDEMO)
			gsys->mTimer->start("eff draw", true);
#endif
			effectMgr->draw(gfx);
#if defined(VERSION_G98E01_PIKIDEMO)
			gsys->mTimer->stop("eff draw");
#endif
		}

		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
#if defined(VERSION_G98E01_PIKIDEMO)
			gsys->mTimer->start("postRender", true);
#endif
			menuOn = false;
			gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
			postRender(gfx);
			if (!mActiveMenu && menuWindow) {
				menuOn = menuWindow->draw(gfx);
			}
#if defined(VERSION_G98E01_PIKIDEMO)
			gsys->mTimer->stop("postRender");
#endif
		}

		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));

		// whole section in DLL here about printing some debug text to screen

		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));

		if (mActiveMenu) {
			mActiveMenu->draw(gfx, 1.0f);
		}

		if (!mActiveMenu || gameflow.mMoviePlayer->mIsActive) {
			if (challengeWindow) {
				gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
				challengeWindow->draw(gfx);
			}
			if (resultWindow) {
				gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
				resultWindow->draw(gfx);
			}
			if (totalWindow) {
				gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
				totalWindow->draw(gfx);
			}
#if defined(VERSION_G98E01_PIKIDEMO)
#else
			if (memcardWindow) {
				gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
				memcardWindow->draw(gfx);
			}
#endif
		}

		BaseGameSection::draw(gfx);
		if (!mIsInitialSetup) {
			if (!gsys->resetPending() && (!mActiveMenu || gameflow.mMoviePlayer->mIsActive)) {
				if (!gameflow.mPauseAll && !gameflow.mIsUIOverlayActive) {
					if (!gameflow.mMoviePlayer->mIsActive && mUpdateFlags & UPDATE_WORLD_CLOCK && !playerState->isTutorial()) {
						f32 tod = gameflow.mWorldClock.mTimeOfDay;
						gameflow.mWorldClock.update(1.0f);
						f32 tod2 = gameflow.mWorldClock.mTimeOfDay;
					}
					Node::update();
				}
				gamecore->mDrawGameInfo->update();
				if (mUpdateFlags & UPDATE_AI && !(gameflow.mDemoFlags & GFDEMO_InMenu)) {
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
#if defined(VERSION_G98E01_PIKIDEMO)
#else
		menuWindow = nullptr;
#endif
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
		RandomAccessStream* data = gsys->openFile(flowCont.mCurrStageFilePath, true, true);
		if (data) {
			CmdStream* stream = new CmdStream(data);
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
				if (stream->isToken("map_file")) {
					sprintf(flowCont.mMapModelFilePath, "%s", stream->getToken(true));
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
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
#if defined(VERSION_G98E01_PIKIDEMO)
		if (!(gameflow.mDemoFlags & GFDEMO_InMenu))
#else
		if (!memcardWindow && !(gameflow.mDemoFlags & GFDEMO_InMenu))
#endif
		{
			bool isTimeMoving = true;
			if (playerState->isTutorial() && !gameflow.mIsDayEndActive) {
				isTimeMoving = false;
			}
			mapMgr->mDayMgr->refresh(gfx, isTimeMoving ? gameflow.mWorldClock.mTimeOfDay : TUTORIAL_TIME_OF_DAY, 8);
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
		gfx.setOrthogonal(mtx2.mMtx, AREA_FULL_SCREEN(gfx));
	}

	void menuQuitGame(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		parent.close();
		mPendingOnePlayerSectionID = ONEPLAYER_GameExit;
		gsys->setFade(0.0f, 3.0f);
		mNextModeState = new QuittingGameModeState(this);
	}

	void menuChangeCourse(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		parent.close();
		mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
		gsys->setFade(0.0f, 3.0f);
		mNextModeState = new QuittingGameModeState(this);
	}

	void menuDayEnd(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		parent.close();
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
	}

	void menuDecreaseFrame(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->mIsPaused = true;
			if (mUpdateCountdown < -1) {
				_3DC             = 4;
				mUpdateCountdown = 0;
			}
			if (mUpdateCountdown < 0) {
				mUpdateCountdown = _3DC;
				if (_3DC > 0) {
					--_3DC;
				}
				gameflow.mMoviePlayer->backFrame();
			}
		}
	}

	void menuIncreaseFrame(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->mIsPaused = true;
			if (mUpdateCountdown < -1) {
				_3DC             = 4;
				mUpdateCountdown = 0;
			}
			if (mUpdateCountdown < 0) {
				mUpdateCountdown = _3DC;
				if (_3DC > 0) {
					--_3DC;
				}
				gameflow.mMoviePlayer->nextFrame();
			}
		}
	}

	void menuIncreaseMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (mUpdateCountdown < -1) {
			_3DC             = 4;
			mUpdateCountdown = 0;
		}
		if (mUpdateCountdown < 0) {
			mUpdateCountdown = _3DC;
			if (_3DC > 0) {
				--_3DC;
			}
			++movieIndex;
		}
		if (movieIndex > TERNARY_BUGFIX(DEMOID_COUNT - 1, DEMOID_EndOfDayRedOnyon)) {
			movieIndex = TERNARY_BUGFIX(DEMOID_COUNT - 1, DEMOID_EndOfDayRedOnyon);
		}
		sprintf(parent.mCurrentItem->mName, "Movie #%d", movieIndex);
	}

	void menuDecreaseMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (mUpdateCountdown < -1) {
			_3DC             = 4;
			mUpdateCountdown = 0;
		}
		if (mUpdateCountdown < 0) {
			mUpdateCountdown = _3DC;
			if (_3DC > 0) {
				--_3DC;
			}
			--movieIndex;
		}
		if (movieIndex < 0) {
			movieIndex = 0;
		}
		sprintf(parent.mCurrentItem->mName, "Movie #%d", movieIndex);
	}

	void menuPlayMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(2);
		} else {
			gameflow.mMoviePlayer->mIsPaused = false;
			gameflow.mMoviePlayer->startMovie(movieIndex, 0, nullptr, nullptr, nullptr, 0xFFFFFFFF, false);
		}
	}

	void menuPauseMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->mIsPaused ^= true;
			PRINT("movie pause = %s\n", gameflow.mMoviePlayer->mIsPaused ? "On" : "Off");
		}
	}

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
 * @todo: Documentation
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
 * @todo: Documentation
 */
void GameMovieInterface::parse(GameMovieInterface::SimpleMessage& msg)
{
	int id   = msg.mMessageId;
	int data = msg.mData;
#if defined(VERSION_GPIP01_00)
	OSReport("!!!!!!!!!!! Got message %d : %d\n", id, data);
#endif
	switch (id) {
	case MOVIECMD_TextDemo:
		// data here should use the zen::ogScrTutorialMgr::EnumTutorial enum (text ID)
		PRINT("***** START TUTORIAL WINDOW\n");
		int partId    = -1;
		bool hasAudio = false;
		if (data == zen::ogScrTutorialMgr::TUT_GetParts) {
			if (gameflow.mShipTextPartID == -1) {
				if (gameflow.mShipTextType == SHIPTEXT_CollectEngine) {
					gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
					return;

				} else if (gameflow.mShipTextType == SHIPTEXT_PartCollect) {
					data = zen::ogScrTutorialMgr::TUT_HitUFO;
				} else {
					data = zen::ogScrTutorialMgr::TUT_APunchUFO;
				}

			} else if (gameflow.mShipTextType == SHIPTEXT_PartCollect) {
				data = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsGetOffset;

			} else if (gameflow.mShipTextType == SHIPTEXT_PartsAccess) {
				data     = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsInfoOffset;
				hasAudio = false;
				partId   = gameflow.mShipTextPartID;

			} else if (gameflow.mShipTextType == SHIPTEXT_PowerUp) {
				PRINT("showing power up message (%d)!!\n", gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsPower);
				int id = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsPower;
				if (gameflow.mShipTextPartID == UFO_SecretSafe) {
					dontShowFrame = true;
					data          = zen::ogScrTutorialMgr::TUT_FinishUFO;
				} else {
					data = id;
				}

			} else if (gameflow.mShipTextType == SHIPTEXT_PartDiscovery) {
				partId   = gameflow.mShipTextPartID;
				hasAudio = true;
				data     = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsGetOnlyOffset;
			}
		}

		createTutorialWindow(data, partId, hasAudio);
		gameflow.mIsUIOverlayActive = TRUE;
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
		// data here is 0 or 1:
		// - 0 = caused by pikmin zero
		// - 1 = caused by navi dead
		if (data == 0) {
			// data = 0 => pikmin zero!
			if (flowCont.mGameEndFlag == GAMEEND_PikminExtinction) {
				// we already have the pikmin extinction flag set somehow, go straight to day end if we're not on day 30
				if (!gameflow.mIsChallengeMode && gameflow.mWorldClock.mCurrentDay != MAX_DAYS) {
					gameflow.mMoviePlayer->startMovie(DEMOID_ExtDayEnd, 0, nullptr, nullptr, nullptr, -1, true);
					gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::MODE_Extinction, 40.0f);
					}
					mapMgr->mTargetFadeLevel = 0.0f;
				} else {
					// if we're in challenge mode or on the final day, reset the end flag
					flowCont.mGameEndFlag = GAMEEND_None;
				}
			} else {
				// flag isn't set yet, set it and handle the extinction cutscene
				flowCont.mGameEndFlag = GAMEEND_PikminExtinction;
				PRINT("got zero pikis flag!!\n");
				Navi* navi = naviMgr->getNavi(0);
				gameflow.mMoviePlayer->startMovie(DEMOID_Extinction, 0, navi, &navi->mSRT.t, &navi->mSRT.r, -1, true);
				if (gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
					// if we're in challenge mode or on the final day, game over!
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::MODE_Extinction, 40.0f);
					}
				}
			}
		} else {
			// data = 1 => navi dead!
			flowCont.mGameEndFlag = GAMEEND_NaviDown;
			PRINT("got navi dead flag!!\n");
		}
		break;

	case MOVIECMD_ForceResults:
		PRINT("got FORCE RESULTS SCREEN !!!\n");
		flowCont.mGameEndFlag = GAMEEND_None;
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
		Jac_SceneSetup(SCENE_Unk6, 1);
		break;

	case MOVIECMD_SpecialDayEnd:
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
		flowCont.mEndingType        = ENDING_Happy;
		break;

	case MOVIECMD_SetPauseAllowed:
		gameflow.mIsPauseAllowed = data;
		break;

	case MOVIECMD_CountDownLastSecond:
		break;

	case MOVIECMD_StageFinish:
		PRINT("GOT STAGE FINISH MESSAGE!!!\n");
		gamecore->forceDayEnd();
		break;

	case MOVIECMD_CreateMenuWindow:
		createMenuWindow();
		break;

#if defined(VERSION_G98E01_PIKIDEMO)
	case MOVIECMD_DemoFinish:
		createTutorialWindow(DEMOID_DayEndForest, -1, 0);
		gameflow.mIsUIOverlayActive = TRUE;
		break;
#else
#endif
	}
}

/**
 * @todo: Documentation
 */
void GameMovieInterface::parse(GameMovieInterface::ComplexMessage& msg)
{
	gameflow.mMoviePlayer->startMovie(msg.mMovieIdx, msg._UNUSED04, msg.mTarget, &msg.mPosition, &msg.mRotation, msg.mFlags,
	                                  msg.mIsPlaying);
}

/**
 * @todo: Documentation
 */
NewPikiGameSection::NewPikiGameSection()
{
	Node::init("<NewPikiGameSection>");

	gameflow.mCurrentStageID       = flowCont.mCurrentStage->mStageIndex;
	gameflow.mPendingStageUnlockID = -1;

	if (playerState->isTutorial()) {
		// day one is locked at 2:48pm
		gameflow.mWorldClock.setTime(TUTORIAL_TIME_OF_DAY);
	}
	flowCont.mGameEndFlag = 0;
#if defined(VERSION_GPIP01_00)
	flowCont.mIsDayEndSkippable = TRUE;
	flowCont.mIsDayEndSkipped   = FALSE;
#endif
	gsys->setFrameClamp(2);
#ifdef WIN32
	_nPrint = FALSE;
	_kPrint = FALSE;
#endif
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
