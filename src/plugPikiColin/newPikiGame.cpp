#include "NewPikiGame.h"

#include "Controller.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "FlowController.h"
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

//////////////////////////////////////////////////////
//////////////// FORWARD DECLARATIONS ////////////////
//////////////////////////////////////////////////////

struct NewPikiGameSetupSection;

//////////////////////////////////////////////////////
///////////////// MACROS AND DEFINES /////////////////
//////////////////////////////////////////////////////

/// Maximum number of pages a daily diary entry can have.
#define MAX_DIARY_ENTRY_PAGES (15)

/// Maximum number of each type of message for `GameMovieMessage` to shuttle.
#define GAME_MESSAGE_LIMIT (32)

/// In-game time before sunset (in hours) where you can't open the map/controls (Y) menu.
/// (This is about 8s of real-world time, or 7.5 in-game minutes.)
#define MAP_MENU_SUNSET_LOCKOUT (0.125f)

#if defined(WIN32)
/// Size of the "teki" heap to use for gameplay (and some cutscenes) - bigger in the DLL.
#define TEKI_HEAP_SIZE (0xA00000)
#else
/// Size of the "teki" heap to use for gameplay (and some cutscenes).
#define TEKI_HEAP_SIZE (0x280000)
#endif

/// Size of the "movie" heap to use for gameplay, cutscenes, and some menus/windows.
#define MOVIE_HEAP_SIZE (0x40000)

//////////////////////////////////////////////////////
////////////////// STATIC INSTANCES //////////////////
//////////////////////////////////////////////////////

/// Gameplay setup instance.
static NewPikiGameSetupSection* npgss;

/// Core gameplay handler instance.
static GameCoreSection* gamecore;

/// Current index of the Movie Player debug menu. (See `CinDemoIDs` enum)
static int movieIndex;

/// Challenge mode results screen.
static zen::DrawCMresult* challengeWindow;

/// Game over text overlay (Olimar down! or Pikmin extinction).
static zen::DrawGameOver* gameoverWindow;

/// End of day count down number overlay.
static zen::DrawCountDown* countWindow;

/// Pause menu screen (opened with START).
static zen::ogScrPauseMgr* pauseWindow;

/// End of day results screen.
static zen::ogScrResultMgr* resultWindow;

/// Story mode final results screen.
static zen::DrawFinalResult* totalWindow;

#if defined(VERSION_G98E01_PIKIDEMO)
#else
/// Memory card screen (mostly for errors) - not present in the demo (no need to save).
static zen::ogScrFileChkSelMgr* memcardWindow;
#endif

/// Whether Y menu (map etc) is active.
static bool menuOn;

/// Whether game info HUD is initialised and toggleable.
static bool gameInfoOn;

/// Whether game info HUD is currently visible.
static bool gameInfoIn;

/// Radar map/Pikmin counts/controls menu (opened with Y).
static zen::ogScrMenuMgr* menuWindow;

/// Text ("tutorial") pop-ups/overlays.
static zen::ogScrTutorialMgr* tutorialWindow;

/// Whether or not to play the parts discovery jingle (when walking close to them for the first time).
static bool hasDemoSound;

/// Whether or not to force the HUD frame to hide, even after a text box finishes (just for final part collection).
static bool dontShowFrame;

#if defined(VERSION_G98E01_PIKIDEMO)
#else
/// Table to hold indices of today's diary entry pages - gets overwritten + reused each day end. Not present in demo (no results screen).
static zen::EnumResult resultTable[MAX_DIARY_ENTRY_PAGES + 1];
#endif

//////////////////////////////////////////////////////
//////////////// PRINT/ERROR DEFINES /////////////////
//////////////////////////////////////////////////////

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(61)

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("newPikiGame");

//////////////////////////////////////////////////////
/////////////////// MOVIE MESSAGES ///////////////////
//////////////////////////////////////////////////////

/**
 * @brief Gameplay-specific message shuttle. Primarily used for shuttling messages into and out of cutscenes and text windows.
 *
 * @note Size: 0x694.
 */
struct GameMovieInterface : public GameInterface {

	/**
	 * @brief Construct a game message shuttle.
	 * @param section Parent setup section to attach to.
	 */
	GameMovieInterface(NewPikiGameSetupSection* section)
	{
		mMessageLimit       = GAME_MESSAGE_LIMIT;
		mSimpleMessageCount = 0;
		mSetupSection       = section;
	}

	/**
	 * @brief Holds simple commands and small data to pass between cutscenes and gameplay.
	 *
	 * @note Size: 0x8.
	 */
	struct SimpleMessage {
		int mCommand; ///< _00, command to action - see `GameMovieCommand` enum.
		int mData;    ///< _04, any data to pass, which differs by command - documented in `GameMovieCommand` enum also.
	};

	/**
	 * @brief Holds sufficient information to start a cutscene, including the movie ID, target actor, position/rotation, and flags.
	 *
	 * @note Size: 0x2C.
	 */
	struct ComplexMessage {

		/// Constructs a blank message.
		ComplexMessage() { }

		int mMovieIdx;      ///< _00, index of movie to play - see `CinDemoIDs` enum.
		int _04;            ///< _04, unknown/unused.
		Creature* mTarget;  ///< _08, target actor for cutscene.
		Vector3f mPosition; ///< _0C, position of world (focus) during cutscene.
		Vector3f mRotation; ///< _18, rotation of world matrix during cutscene.
		int mActorVisMask;  ///< _24, actor visibility mask, used for day end actors and bad ending - see `CineActorFlags` enum.
		bool mIsPlaying;    ///< _28, whether cutscene should play on start - always `true` in practice.
	};

	/**
	 * @brief Adds a simple (command) message to the command queue for async action.
	 * @param cmd Command to action (see `GameMovieCommand` enum).
	 * @param data Data to send with command (also documented in `GameMovieCommand` enum with each command).
	 */
	virtual void message(int cmd, int data) // _08
	{
		// don't add to queue if queue is full
		if (mSimpleMessageCount >= mMessageLimit) {
			return;
		}

		// add to queue
		mSimpMesg[mSimpleMessageCount].mCommand = cmd;
		mSimpMesg[mSimpleMessageCount].mData    = data;

		mSimpleMessageCount++;
	}

	/**
	 * @brief Adds a cutscene to the queue to play.
	 *
	 * @param movieIdx Index of movie to play - see `CinDemoIDs` enum.
	 * @param unused Stored and passed but never used.
	 * @param target Target actor for cutscene.
	 * @param pos Position of world (focus) during cutscene.
	 * @param rot Rotation of world matrix during cutscene.
	 * @param actorVisMask Actor visibility mask (day end, bad ending) - see `CineActorFlags` enum.
	 * @param isPlaying Whether cutscene should play when started (in reality this is always true).
	 */
	virtual void movie(int movieIdx, int unused, Creature* target, immut Vector3f* pos, immut Vector3f* rot, u32 actorVisMask,
	                   bool isPlaying) // _0C
	{
		// don't add to the queue if we're full
		if (mComplexMesgCount >= mMessageLimit) {
			return;
		}

		// store movie info
		mCompMesg[mComplexMesgCount].mMovieIdx = movieIdx;
		mCompMesg[mComplexMesgCount]._04       = unused; // passed around but never used.
		mCompMesg[mComplexMesgCount].mTarget   = target;
		if (!pos) {
			// no position, make a dummy one at the map origin
			mCompMesg[mComplexMesgCount].mPosition.set(0.0f, 0.0f, 0.0f);
		} else {
			mCompMesg[mComplexMesgCount].mPosition = *pos;
		}
		if (!rot) {
			// no rotation, use default world rotation
			mCompMesg[mComplexMesgCount].mRotation.set(0.0f, 0.0f, 0.0f);
		} else {
			mCompMesg[mComplexMesgCount].mRotation = *rot;
		}
		mCompMesg[mComplexMesgCount].mActorVisMask = actorVisMask;
		mCompMesg[mComplexMesgCount].mIsPlaying    = isPlaying; // this is always true. why would you start a movie paused?

		mComplexMesgCount++;
	}

	virtual void parseMessages();            // _10
	virtual void parse(SimpleMessage& msg);  // _18
	virtual void parse(ComplexMessage& msg); // _1C

	// _00 = VTBL
	NewPikiGameSetupSection* mSetupSection;       ///< _004, parent setup/controlling section.
	int mMessageLimit;                            ///< _008, max amount of messages to hold in each queue.
	SimpleMessage mSimpMesg[GAME_MESSAGE_LIMIT];  ///< _00C, simple message queue, for commands and small data.
	int mSimpleMessageCount;                      ///< _10C, number of messages in simple message (command) queue.
	ComplexMessage mCompMesg[GAME_MESSAGE_LIMIT]; ///< _110, complex message queue, for queued cutscenes.
	int mComplexMesgCount;                        ///< _690, number of messages in commplex message (cutscene) queue.
};

//////////////////////////////////////////////////////
//////////////// GAMEPLAY MODE STATES ////////////////
//////////////////////////////////////////////////////

/**
 * @brief State for handling the transition between the area entry (or crash landing) cutscene, and entering gameplay.
 *
 * @note Size: 0xC.
 */
struct IntroGameModeState : public ModeState {

	/**
	 * @brief Constructs a basic intro state.
	 * @param parent Parent setup/control section (`NewPikiGameSetupSection` in this case).
	 */
	IntroGameModeState(BaseGameSection* parent)
	    : ModeState(parent)
	{
		mController = parent->mController;
	}

	virtual ModeState* update(u32& result); // _08
	virtual void postRender(Graphics&);     // _0C

	// _00     = VTBL
	// _00-_08 = ModeState
	Controller* mController; ///< _08, pointer to parent's active controller.
};

/**
 * @brief State for handling general gameplay.
 *
 * @note Size: 0x10.
 */
struct RunningModeState : public ModeState {

	/**
	 * @brief Constructs a basic running state.
	 * @param parent Parent setup/control section (`NewPikiGameSetupSection` in this case).
	 */
	RunningModeState(BaseGameSection* parent)
	    : ModeState(parent)
	{
		mIsOverlayCached = false;
		mController      = parent->mController;
	}

	virtual void postRender(Graphics&);     // _0C
	virtual ModeState* update(u32& result); // _08

	// _00     = VTBL
	// _00-_08 = ModeState
	bool mIsOverlayCached;   ///< _08, stores current overlay state when we open the pause or map/controls menu, so we can restore it.
	Controller* mController; ///< _0C, pointer to parent's active controller.
};

/**
 * @brief State for handling quitting out of gameplay, either to map screen, card select, or title.
 *
 * @note Size: 0x8.
 */
struct QuittingGameModeState : public ModeState {

	/**
	 * @brief Constructs a quitter state.
	 * @param parent Parent setup/control section (`NewPikiGameSetupSection` in this case).
	 */
	QuittingGameModeState(BaseGameSection* parent)
	    : ModeState(parent)
	{
	}

	/**
	 * @brief Updates quitter - keeps update flag at none, no transits out.
	 * @details Actual transit out of this state is handled by `postUpdate`.
	 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
	 * @return Pointer to active state for next frame - always `this`.
	 */
	virtual ModeState* update(u32& result) // _08
	{
		PRINT("quitter updating!\n");
		// don't let anything update if we're quitting
		result = UPDATE_NONE;
		return this;
	}

	/**
	 * @brief Force transits to a new game section, based on what we have queued up.
	 */
	virtual void postUpdate() // _10
	{
		// force transit to next section (if we're not already)
		if (!gsys->mSoftResetPending) {
			PRINT("sending softreset!\n");
			gamecore->exitStage();
			gameflow.mNextOnePlayerSectionID       = mParentSection->mPendingOnePlayerSectionID;
			gameflow.mNextOnePlayerSectionOnDayEnd = ONEPLAYER_MapSelect;
			Jac_SceneExit(SCENE_Exit, 0);
			gsys->softReset();
		}
	}

	// _00     = VTBL
	// _00-_08 = ModeState
};

/**
 * @brief State for displaying either of the game over states.
 *
 * In reality, this is only really used for navi down, because Olimar is dramatic
 * - pikmin extinction gets mostly handled by the simple message system and cutscenes.
 *
 * @note Size: 0x14.
 */
struct MessageModeState : public ModeState {

	/**
	 * @brief Phases of message mode progress.
	 */
	enum State {
		STATE_Starting    = 0, ///< 0, starting up - for Pikmin extinction, this is the whole state.
		STATE_Desaturate  = 1, ///< 1, desaturates the map to greyscale (for navi down).
		STATE_FadeOut     = 2, ///< 2, fades to black - Olimar blacked out!
		STATE_ForceDayEnd = 3, ///< 3, force (sad) day end to begin.
	};

	/**
	 * @brief Construct a new game over message state.
	 *
	 * @param parent Parent setup/control section (`NewPikiGameSetupSection` in this case).
	 * @param isPikminZero Whether we should use the pikmin extinction timing (true) or navi down (false).
	 */
	MessageModeState(BaseGameSection* parent, bool isPikminZero)
	    : ModeState(parent)
	{
		// pikmin extinction doesn't progress through states, it just lasts 5 seconds
		// navi down DOES progress through states, so first state should only be short
		mStateTimer = isPikminZero ? 5.0f : 0.5f;
	}

	virtual ModeState* update(u32& result); // _08

	/**
	 * @brief Renders the relevant game over text overlay.
	 *
	 * This is in postRender so it comes after other renders, and is therefore on top.
	 *
	 * @param gfx Graphics context for rendering.
	 */
	virtual void postRender(Graphics& gfx) // _0C
	{
		Matrix4f orthoMtx;
		if (gameoverWindow) {
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
			gameoverWindow->draw(gfx);
		}
	}

	// _00     = VTBL
	// _00-_08 = ModeState
	u32 _08;         ///< _08, unknown/unused.
	int mState;      ///< _0C, current state of message sequence - see `State` enum.
	f32 mStateTimer; ///< _10, timer for message state transitions.
};

/**
 * @brief State for handling the end of day sequence, including for the various game endings.
 *
 * @note Size: 0xC.
 */
struct DayOverModeState : public ModeState {

	/**
	 * @brief Phases that end-of-day progresses through.
	 *
	 * Regular day end + challenge mode only use the first 2; neutral/bad endings use the first 3; happy uses all 4.
	 * (Last one is just for wrapping things up.)
	 * Code calls them phases, but they're states everywhere else.
	 */
	enum State {
		STATE_PhaseZero  = 0, ///< 0, initial prep and starting the pikmin marching cutscene/take off/first ending cutscene.
		STATE_PhaseOne   = 1, ///< 1, end of day/challenge results or next ending cutscene (happy:takeoff, neutral:leaving, bad:failescape).
		STATE_PhaseTwo   = 2, ///< 2, either quick transit to quitter, or next ending cutscene (happy:onyons, neutral:space, bad:olimin).
		STATE_PhaseThree = 3, ///< 3, only endings - neutral/bad: quick transit to quitter; happy: space cutscene/final results.
		STATE_PhaseFour  = 4, ///< 4, done in every situation! finish processing any logic and quit out of gameplay mode state.
	};

	/**
	 * @brief Construct a new end of day state, optionally starting the pikmin marching back into their onions cutscene.
	 *
	 * @param parent Parent setup/control section (`NewPikiGameSetupSection` in this case).
	 * @param startState State to start in - see `State` enum. STATE_PhaseZero will play the pikmin marching cutscene,
	 * STATE_EndOfDayResults won't.
	 */
	DayOverModeState(BaseGameSection* parent, int startState)
	    : ModeState(parent)
	{
		flowCont.mIsDayEndSeqStarted = TRUE;

		// this actually does nothing
		gamecore->startContainerDemo();

		// force clock to end of day time
		gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());

		// hide the HUD
		gamecore->mDrawGameInfo->upperFrameOut(0.5f, true);
		gamecore->mDrawGameInfo->lowerFrameOut(0.5f, true);

		if (startState == STATE_PhaseZero) {
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

			// you heard the man, clean up day end!
			gamecore->cleanupDayEnd();

			// if we aren't playing an ending (last day or all parts), play pikmin marching back into their onions cutscene
			if (gameflow.mWorldClock.mCurrentDay < MAX_DAYS && playerState->getCurrParts() != MAX_UFO_PARTS && !gameflow.mIsChallengeMode) {
				mParentSection->mCurrentFade = -0.1f;
				gameflow.mMoviePlayer->startMovie(DEMOID_DayEnd, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
			}

			// start fade out ahead of take-off cutscene
			mParentSection->mTargetFade = 1.0f;
			mParentSection->mFadeSpeed  = 0.5f;
		}

		mState = startState;
	}

	virtual ModeState* update(u32& result); // _08

	/**
	 * @brief Renders the relevant text screen or game over text overlay.
	 *
	 * This is in postRender so it comes after other renders, and is therefore on top.
	 *
	 * @param gfx Graphics context for rendering.
	 */
	virtual void postRender(Graphics& gfx) // _0C
	{
		Matrix4f orthoMtx;
		// if we have text open, handle that
		if (tutorialWindow) {
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
			tutorialWindow->draw(gfx);
		}

		// if we have a game over text overlay, handle that
		if (gameoverWindow) {
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
			gameoverWindow->draw(gfx);
		}
	}

	void makeTotalScoreWindow();
	ModeState* initialisePhaseOne();
	ModeState* initialisePhaseTwo();
	ModeState* initialisePhaseThree();
	ModeState* initialisePhaseFour();

	// _00     = VTBL
	// _00-_08 = ModeState
	int mState; ///< _08, current state of the day end sequence - see `State` enum.
};

//////////////////////////////////////////////////////
////////////// STATIC HELPER FUNCTIONS ///////////////
//////////////////////////////////////////////////////

/**
 * @brief Controls visibility of game HUD frames, both top and bottom.
 * @param set Whether to show (true) or hide (false) the HUD.
 * @param fadeTime Fade (in or out) duration in seconds.
 *
 * @note UNUSED Size: 0000E4
 */
static void showFrame(bool set, f32 fadeTime)
{
	if (set) {
		// HUD needs to be active but hidden to re-show it
		if (gameInfoOn && !gameInfoIn) {
			if (!playerState->isTutorial()) {
				// don't show the sun meter and day number on day 1
				gamecore->mDrawGameInfo->upperFrameIn(fadeTime, true);
			}
			// always show the captain health and pikmin counts etc regardless of day
			gamecore->mDrawGameInfo->lowerFrameIn(fadeTime, true);
			gameInfoIn = true;
		}
	} else {
		// HUD needs to be active and shown to hide it
		if (gameInfoOn && gameInfoIn) {
			if (!playerState->isTutorial()) {
				// top HUD isn't visible on day 1, nothing to hide
				gamecore->mDrawGameInfo->upperFrameOut(fadeTime, true);
			}
			// hide bottom HUD
			gamecore->mDrawGameInfo->lowerFrameOut(fadeTime, true);
			gameInfoIn = false;
		}
	}
}

/**
 * @brief Creates and initializes the map and controls menu (Y menu).
 */
static void createMenuWindow()
{
	// load menu assets without a loading screen
	gsys->startLoading(nullptr, false, 0);
	bool oldAlloc        = gsys->mPrevAllocType;
	gsys->mPrevAllocType = 0;
	int oldHeap          = gsys->getHeapNum();

	// use movie heap for the map menu
	PRINT("using movie heap!\n");
	gsys->setHeap(SYSHEAP_Movie);
	int oldMovieAlloc = gsys->getHeap(SYSHEAP_Movie)->setAllocType(AYU_STACK_GROW_DOWN);

	menuWindow = new zen::ogScrMenuMgr;
	menuWindow->start();

	// restore movie heap settings
	gsys->getHeap(SYSHEAP_Movie)->setAllocType(oldMovieAlloc);

	// restore previous heap
	gsys->setHeap(oldHeap);
	gsys->mRetraceCount  = 0;
	gsys->mPrevAllocType = oldAlloc;

	// attach the menu so it gets drawn properly
	gsys->endLoading();
	PRINT("menu window attach\n");
	gsys->attachObjs();
}

/**
 * @brief Destroys the map and controls menu (Y menu) window and frees resources.
 * @note UNUSED Size: 000040
 */
static void deleteMenuWindow()
{
	// clear movie heap to free resources
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	PRINT("menu window detach\n");
	gameflow.mIsUIOverlayActive = FALSE;
	menuWindow                  = nullptr;
}

/**
 * @brief Creates and displays a text window.
 *
 * @param textID Text ID to display - see `zen::ogScrTutorialMgr::EnumTutorial` enum.
 * @param ufoPartID Ufo part ID for audio (-1 if no part associated with the text).
 * @param hasAudio Whether text has audio - this is just for the discovering (going near) a part jingle.
 */
static void createTutorialWindow(int textID, int ufoPartID, bool hasAudio)
{
	// load assets without a loading screen
	gsys->startLoading(nullptr, false, 0);

	bool oldAlloc        = gsys->mPrevAllocType;
	gsys->mPrevAllocType = FALSE;
	int oldHeap          = gsys->getHeapNum();
	PRINT("using movie heap!\n");

	hasDemoSound = (ufoPartID >= 0 && hasAudio);

	if (hasDemoSound) {
		// plays the part discovery (going near ship part) jingle
		Jac_StartPartsFindDemo(ufoPartID + 1, hasAudio);
	} else {
		// regular text printing sound effects
		Jac_StartTextDemo(textID);
	}

	// use movie heap for text screen
	gsys->setHeap(SYSHEAP_Movie);
	int oldMovieAlloc = gsys->getHeap(SYSHEAP_Movie)->setAllocType(AYU_STACK_GROW_DOWN);

	tutorialWindow = new zen::ogScrTutorialMgr;
	tutorialWindow->start((zen::ogScrTutorialMgr::EnumTutorial)textID);

	// restore movie heap settings
	gsys->getHeap(SYSHEAP_Movie)->setAllocType(oldMovieAlloc);

	// restore previous heap
	gsys->setHeap(oldHeap);

	// hide the HUD while we're in a text screen
	showFrame(false, 0.5f);
	gameflow.mIsTutorialTextActive = TRUE;
	gsys->mRetraceCount            = 0;
	gsys->mPrevAllocType           = oldAlloc;

	// attach screen so it gets drawn properly
	gsys->endLoading();
	PRINT("tutorial window attach\n");
	gsys->attachObjs();
}

/**
 * @brief Destroys the current text window and restores the game state.
 *
 * This doesn't actually reset the movie heap used for text assets, unlike the menu screen - bug?
 */
static void deleteTutorialWindow()
{
	if (hasDemoSound) {
		// finish any part discovery jingles
		Jac_FinishPartsFindDemo();
	} else {
		// finish any text printing sound effects
		Jac_FinishTextDemo();
	}

	gameflow.mIsTutorialTextActive = FALSE;
	if (!dontShowFrame && gameInfoOn && !gameInfoIn) {
		// un-hide the HUD
		if (!playerState->isTutorial()) {
			gamecore->mDrawGameInfo->upperFrameIn(0.5f, true);
		}
		gamecore->mDrawGameInfo->lowerFrameIn(0.5f, true);
		gameInfoIn = true;
	}

	gameflow.mIsUIOverlayActive = FALSE;
	tutorialWindow              = nullptr;
}

/**
 * @brief Handles the text window update logic.
 *
 * @param result Unused output for any update logic flags to use or adjust.
 * @param controller Player input controller.
 * @note UNUSED Size: 0000A8
 */
static void handleTutorialWindow(u32& result, Controller* controller)
{
	if (tutorialWindow && tutorialWindow->update(controller) == zen::ogScrTutorialMgr::STATUS_Exiting) {
		// text window is closing, skip any associated cutscene going on alongside this text
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
		}

		// get rid of the text window
		deleteTutorialWindow();
	}
}

//////////////////////////////////////////////////////
///// BASE GAME SECTION AND MODE STATE FUNCTIONS /////
//////////////////////////////////////////////////////

/**
 * @brief Constructs a base class game section, for controlling gameplay and pre-gameplay sections.
 *
 * Defaults to no updating, no active states, fade-in of 2 seconds and map select as the next section.
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
 * @brief Renders a single frame, handling just fade-ins and level banners.
 *
 * Also triggers the current mode state's postUpdate method, if it has one.
 */
void BaseGameSection::draw(Graphics& gfx)
{
	Matrix4f orthoMtx;
	gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));

	// Update fade transition - fade of 1 = black screen, fade of 0 = no fade
	if (mCurrentFade < mTargetFade) {
		// fade out
		mCurrentFade += mFadeSpeed * gsys->getFrameTime();
		if (mCurrentFade > mTargetFade) {
			mCurrentFade = mTargetFade;
		}
	} else if (mCurrentFade > mTargetFade) {
		// fade in
		mCurrentFade -= mFadeSpeed * gsys->getFrameTime();
		if (mCurrentFade < mTargetFade) {
			mCurrentFade = mTargetFade;
		}
	}

	// draw fade overlay, if active
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

	// draw level banner, if active
	if (gameflow.mLevelBannerTex && gameflow.mLevelBannerFadeValue > 0.0f) {
		// fade out level banner
		gameflow.mLevelBannerFadeValue -= gsys->getFrameTime();
		if (gameflow.mLevelBannerFadeValue < 0.0f) {
			gameflow.mLevelBannerTex       = nullptr;
			gameflow.mLevelBannerFadeValue = 0.0f;
		} else {
			gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTex, gameflow.mLevelBannerFadeValue);
		}
	}

	// perform any post-draw mode state updates
	mCurrentModeState->postUpdate();
}

/**
 * @brief Updates the intro state, to decide when to enter active gameplay.
 *
 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
 * @return Pointer to active state for next frame, either `this` or a new gameplay state.
 */
ModeState* IntroGameModeState::update(u32& result)
{
	// don't advance the clock or count down until we're in gameplay!
	result = UPDATE_AI;

	// for Day 1, deal with the "My name is Captain Olimar..." text windows while they're open.
	handleTutorialWindow(result, mParentSection->mController);

	if (!gameflow.mMoviePlayer->mIsActive) {
		// intro cutscene is finished, get us into gameplay!
		PRINT("switching to running!\n");
		// enable the HUD and make it visible
		gameInfoOn = true;
		showFrame(true, 2.0f);

		// transit to gameplay (`RunningModeState`)
		return new RunningModeState(mParentSection);
	}

	// cutscene is still playing, stay in this state
	return this;
}

/**
 * @brief Updates general gameplay, and controls transits to day end, game over, or "quitting" to another game subsection.
 *
 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
 * @return Pointer to active state for next frame, either `this` or a new state.
 */
ModeState* RunningModeState::update(u32& result)
{
	result = UPDATE_ALL; // enable all update types to start, then disable any we don't want.

	// if we've entered the end of day cutscene, transit to the day over state to handle the day end phases
	if (!gameflow.mMoviePlayer->mIsActive && !gameflow.mIsTutorialTextActive && gameflow.mIsDayEndActive) {
		result &= ~UPDATE_AI; // Disable AI updates during day end, but keep clock going
		PRINT("*-------------------------------- DAY END !!!!!!!!!!!!!!  --------------------------------*\n");

		// queue up the next subsection - in reality this is usually map select
		mParentSection->mPendingOnePlayerSectionID = gameflow.mNextOnePlayerSectionOnDayEnd;
		return new DayOverModeState(mParentSection, 0);
	}

	// trigger day end when time expires
	if (!gameflow.mIsDayEndActive && !gameflow.mMoviePlayer->mIsActive
	    && gameflow.mWorldClock.mTimeOfDay >= gameflow.mParameters->mEndHour()) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
		gameflow.mIsPauseAllowed = FALSE;
#endif
		gameflow.mIsDayEndTriggered = TRUE;
	}

	// process day end trigger (can't start cutscene while a window is open!)
	if (gameflow.mIsDayEndTriggered && !gameflow.mIsUIOverlayActive) {
		gameflow.mIsDayEndActive    = TRUE;
		gameflow.mIsDayEndTriggered = FALSE;

		// Special handling for neutral and bad endings on the final day
		if (playerState->getCurrParts() != MAX_UFO_PARTS && gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
			if (playerState->happyEndable()) {
				// we got at least 25 parts!
				flowCont.mEndingType = ENDING_Neutral;
				gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_BadEnding);
			} else {
				// uh oh - olimin time
				gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_BadEnding);
			}
		}
	}

	// check our voicemail - do we have any simple movie-related commands pending?
	bool mesgsPending = false;
	if (static_cast<GameMovieInterface*>(gameflow.mGameInterface)->mSimpleMessageCount) {
		mesgsPending = true;
	}

	// handle pause and map/control menus
	// can't open a pause menu if a) we're not allowed, b) a window is open, c) we're already paused, or d) if a cutscene is playing
	if (gameflow.mIsPauseAllowed && !gameflow.mIsUIOverlayActive && !gameflow.mPauseAll && !gameflow.mMoviePlayer->mIsActive) {

		// pause menu (Continue, Go To Sunset, Continue From Last Save)
		if (mController->keyClick(KBBTN_START)) {
			if (!gameflow.mIsUIOverlayActive && !mesgsPending) {
				PRINT("starting pause menu!\n");
				seSystem->playSysSe(SYSSE_PAUSE);
				pauseWindow->start(gameflow.mIsChallengeMode);
				mIsOverlayCached            = gameflow.mIsUIOverlayActive;
				gameflow.mIsUIOverlayActive = TRUE;
			}
		}
		// I added a bugfix to prevent the OgRader screen from opening in the background when the debug menu is active.  Many
		// debug menus also use the Y button, and both being open at the same time can even cause crashes in the Movie Player.
#if defined(VERSION_G98E01_PIKIDEMO)
		else if (mController->keyClick(KBBTN_Y)
		         && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - MAP_MENU_SUNSET_LOCKOUT
		         && !gameflow.mIsUIOverlayActive && !mesgsPending && TERNARY_BUGFIX(!mParentSection->mActiveMenu, true))
		// in the demo, you can open the map/controls menu in challenge mode...
#else
		else if (!gameflow.mIsChallengeMode && mController->keyClick(KBBTN_Y)
		         && gameflow.mWorldClock.mTimeOfDay < gameflow.mParameters->mEndHour() - MAP_MENU_SUNSET_LOCKOUT
		         && !gameflow.mIsUIOverlayActive && !mesgsPending && TERNARY_BUGFIX(!mParentSection->mActiveMenu, true))
#endif
		{
			// also can't open the map/controls menu in the very last ~8s of gameplay before sunset
			gameflow.mGameInterface->message(MOVIECMD_CreateMenuWindow, 0);
			mIsOverlayCached            = gameflow.mIsUIOverlayActive;
			gameflow.mIsUIOverlayActive = TRUE;
		}
#if defined(DEVELOP) || defined(WIN32)
		// Mapping this to d-pad down was genuinely an atrocious choice, so I'm assigning it to d-pad up.
		else if (mController->keyUnClick(TERNARY_BUILD_MATCHING(KBBTN_DPAD_DOWN, KBBTN_DPAD_UP))) {
			mParentSection->openMenu();
		}
#endif
	}

	// check if we have an unhandled forced game end pending
	if (flowCont.mGameEndFlag != GAMEEND_None) {
		if (flowCont.mGameEndFlag == GAMEEND_NaviDown) {
			// you killed your captain!
#if defined(VERSION_GPIP01_00)
			// can't skip the end of day cutscene in PAL if you kill your captain - shame! shame! shame!
			flowCont.mIsDayEndSkippable = FALSE;
#endif
			mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			// start OLIMAR DOWN ! state
			return new MessageModeState(mParentSection, false);
		}

		if (flowCont.mGameEndFlag == GAMEEND_PikminExtinction) {
			// you killed all your pikmin!
#if defined(VERSION_GPIP01_00)
			// can't skip the end of day cutscene in PAL if you kill all your pikmin - shame! shame! shame!
			flowCont.mIsDayEndSkippable = FALSE;
#endif
			mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			// start PIKMIN EXTINCTION state
			return new MessageModeState(mParentSection, true);
		}
	}

	// update the game over window - this is really pedantic, since it should never be active in this state
	if (gameoverWindow) {
		gameoverWindow->update(mController);
	}

	// handle the Y menu, if it's open
	if (menuWindow) {
		zen::ogScrMenuMgr::returnStatusFlag state = menuWindow->update(mController);
		if (state == zen::ogScrMenuMgr::STATE_ActiveDisplay) {
			// disable AI updates when menu is active
			result &= ~UPDATE_AI;
		} else if (state == zen::ogScrMenuMgr::STATE_TransitionToInactive) {
			// we closed it, get rid of it
			deleteMenuWindow();
		}
	}

	// handle any text windows that are open
	handleTutorialWindow(result, mController);

	// handle the pause menu, if it's open
	zen::ogScrPauseMgr::PauseStatus state = pauseWindow->update(mController);
	if (state == zen::ogScrPauseMgr::PAUSE_Active) {
		// disable AI updates when pause menu is active
		result &= ~UPDATE_AI;

	} else if (state == zen::ogScrPauseMgr::PAUSE_ExitToSunset) {
		// go to sunset selected - end the day
		gamecore->forceDayEnd();
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
		gameflow.mIsPauseAllowed = FALSE;
#endif
		gameflow.mIsDayEndTriggered = TRUE;
		gameflow.mIsUIOverlayActive = mIsOverlayCached;

	} else if (state == zen::ogScrPauseMgr::PAUSE_ExitToTitle) {
		// continue from last save/quit challenge mode selected
#if defined(VERSION_G98E01_PIKIDEMO)
		// demo creates a fresh bootup, very dramatic
		gsys->forceHardReset();
#else
		// take us back to card select
		// (this ends up as file select for story mode, or a quick transit to map select for challenge mode)
		mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_CardSelect;
		gsys->setFade(0.0f);
		// transit to quitter
		return new QuittingGameModeState(mParentSection);

#endif
	} else if (state == zen::ogScrPauseMgr::PAUSE_ExitToGameplay) {
		// close the menu - re-enable the HUD and restore any overlays
		showFrame(true, 0.5f);
		gameflow.mIsUIOverlayActive = mIsOverlayCached;
		seSystem->playSysSe(SYSSE_UNPAUSE);
	}

	return this;
}

/**
 * @brief Renders any text overlays during an area intro cutscene.
 *
 * In reality, only the end of the crash landing cutscene has text.
 * This is in postRender so it comes after other renders, and is therefore on top.
 *
 * @param gfx Graphics context for rendering.
 */
void IntroGameModeState::postRender(Graphics& gfx)
{
	Matrix4f orthoMtx;
	if (tutorialWindow) {
		// render the text window over the top
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		tutorialWindow->draw(gfx);
	}
}

/**
 * @brief Renders any overlays (menus, text windows, game over text) during gameplay.
 *
 * This is in postRender so it comes after other renders, and is therefore on top.
 *
 * @param gfx Graphics context for rendering.
 */
void RunningModeState::postRender(Graphics& gfx)
{
	Matrix4f orthoMtx;

	// unused - idk what the point of this would've even been.
	Matrix4f unusedMtx;
	unusedMtx.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));

	if (!menuOn) {
		// no map menu open, draw any other 2D screen objects (enemy health gauges, debug text, etc)
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gamecore->draw1D(gfx);
	}

	// handle sunset approaching/countdown text overlay
	if (!gameflow.mPauseAll && !gameflow.mMoviePlayer->mIsActive && mParentSection->mUpdateFlags & UPDATE_COUNTDOWN) {

		// calc how "far" we are until the end of day - negative = not at countdown yet; 0 = countdown just started; 1 = end of day
		f32 countDownProgress = (gameflow.mWorldClock.mTimeOfDay - gameflow.mParameters->mNightCountdown())
		                      / (gameflow.mParameters->mNightEnd() - gameflow.mParameters->mNightCountdown());
		if (countDownProgress >= 0.0f && countDownProgress < 1.0f) {
			// we're in the countdown window! draw the overlay
			countWindow->update();
			countWindow->draw(gfx);
		}
	}

	// don't bother with text screens, game over text, etc if map menu is open
	if (menuOn) {
		return;
	}

	// draw text screens if any are active
	if (tutorialWindow) {
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		tutorialWindow->draw(gfx);
	}

	// draw the HUD, onion menus, results screens, etc
	gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
	gamecore->draw2D(gfx);

	// draw any game over text if required
	if (gameoverWindow) {
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gameoverWindow->draw(gfx);
	}

	// draw the pause menu if active
	gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
	pauseWindow->draw(gfx);
}

/**
 * @brief Updates game over cutscene state progress, and controls transit to day end.
 *
 * In reality, this only really does anything for navi down, pikmin extinction is separate/not as involved.
 *
 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
 * @return Pointer to active state for next frame, always `this` in practice, since `DayOverModeState` is queued to the parent section.
 */
ModeState* MessageModeState::update(u32& result)
{
	if (flowCont.mGameEndFlag == GAMEEND_NaviDown) {
		// you killed your captain!
		switch (mState) {
		case STATE_Starting:
		{
			// start the timer.
			mStateTimer -= gsys->getFrameTime();
			if (mStateTimer < 0.0f) {
				mStateTimer                 = 2.0f;
				mapMgr->mTargetDesaturation = 1.0f;
				if ((gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == MAX_DAYS) && gameoverWindow) {
					gameoverWindow->start(zen::DrawGameOver::MODE_NaviDown, 40.0f);
				}
				mState = STATE_Desaturate;
			}
			break;
		}
		case STATE_Desaturate:
		{
			mStateTimer -= gsys->getFrameTime();
			if (mStateTimer < 0.0f) {
				mStateTimer              = 3.0f;
				mapMgr->mTargetFadeLevel = 1.0f;
				mState                   = STATE_FadeOut;
			}
			break;
		}
		case STATE_FadeOut:
		{
			mStateTimer -= gsys->getFrameTime();
			if (mStateTimer < 0.0f) {
				mStateTimer = 2.0f;
				mState      = STATE_ForceDayEnd;
			}
			break;
		}
		case STATE_ForceDayEnd:
		{
			mapMgr->mTargetFadeLevel    = 0.0f;
			mapMgr->mTargetDesaturation = 0.0f;
			PRINT("DOING FORCE RESULTS SCREEN !!!\n");
			// set up day end state
			DayOverModeState* state = new DayOverModeState(mParentSection, DayOverModeState::STATE_PhaseOne);
			// (we want to avoid the automatic day end cutscene that constructing in phase 0 would do, and replace it with our own)
			state->mState                  = DayOverModeState::STATE_PhaseZero;
			mParentSection->mNextModeState = state;

			PRINT("CLEANUPDAYEND!!!!\n");

			gamecore->cleanupDayEnd();
			if (!gameflow.mIsChallengeMode) {
				if (gameflow.mWorldClock.mCurrentDay != MAX_DAYS) {
					gameflow.mMoviePlayer->startMovie(DEMOID_OliDownDayEnd, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::MODE_NaviDown, 40.0f);
					}
				}
			} else {
				gameoverWindow = nullptr;
			}
			break;
		}
		}

	} else if (flowCont.mGameEndFlag == GAMEEND_None) {
		// you really shouldn't be here, but there's nothing to handle. go straight to results
		PRINT("DOING FORCE RESULTS SCREEN !!!\n");
		DayOverModeState* state = new DayOverModeState(mParentSection, DayOverModeState::STATE_PhaseOne);
		gameoverWindow          = nullptr;
		// do this to avoid the day end cutscene playing
		state->mState                  = DayOverModeState::STATE_PhaseZero;
		mParentSection->mNextModeState = state;
		mParentSection->mTargetFade    = 1.0f;
	}

	if (gameoverWindow) {
		gameoverWindow->update(mParentSection->mController);
	}
	return this;
}

/**
 * @brief Updates the end of day sequence, and controls transits to quit out of gameplay.
 *
 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
 * @return Pointer to active state for next frame, either `this` or a new state (`QuittingGameModeState`).
 */
ModeState* DayOverModeState::update(u32& result)
{
	STACK_PAD_VAR(1);

	result = UPDATE_AI; // we need animations to play, but we don't need in-game time to pass

	// handle any text windows we might have open, such as during endings
	handleTutorialWindow(result, mParentSection->mController);

#if defined(VERSION_GPIP01_00)

	// PAL-exclusive day end cutscene skipping code!
	bool skipped = false;
	// if the end of day is skippable (not from navi down or something) and we're not at a literal game ending, we can skip
	if (flowCont.mIsDayEndSkippable && playerState->getCurrParts() != MAX_UFO_PARTS && gameflow.mWorldClock.mCurrentDay < MAX_DAYS) {
		// if we're in the pikmin marching cutscene, we can skip with A or B
		if (mState == STATE_PhaseZero && mParentSection->mController->keyClick(KBBTN_A | KBBTN_B)) {
			OSReport("!!!!!!!!!!!!!! SKIPPING !!!!\n");
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
			skipped                   = true;
			flowCont.mIsDayEndSkipped = TRUE;
		}

		// if we're in the takeoff cutscene and we either already skipped the previous one, or we press A or B, skip it too
		if (mState == STATE_PhaseOne && (flowCont.mIsDayEndSkipped || mParentSection->mController->keyClick(KBBTN_A | KBBTN_B))) {
			skipped = true;
		}
	}

	if (!gameflow.mMoviePlayer->mIsActive || skipped)
#else
	if (!gameflow.mMoviePlayer->mIsActive)
#endif
	{
		// once the current cutscene is finished, handle transition to the next phase
		ModeState* nextState = nullptr;
		switch (mState) {
		case STATE_PhaseZero:
		{
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE ONE!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE ONE!!!!\n");
#endif
			nextState = initialisePhaseOne();
			break;
		}
		case STATE_PhaseOne:
		{
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE TWO!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE TWO!!!!\n");
#endif
			nextState = initialisePhaseTwo();
			break;
		}
		case STATE_PhaseTwo:
		{
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE THREE!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE THREE!!!!\n");
#endif
			// in reality, we only end up here if none of the below checks transit us to a QuittingGameModeState
			nextState = initialisePhaseThree();
			break;
		}
		case STATE_PhaseThree:
		{
#if defined(VERSION_GPIP01_00)
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE FOUR!!!!\n");
			OSReport("!!!!!!!!!!!!!! INITIALISE PHASE FOUR!!!!\n");
#endif
			nextState = initialisePhaseFour();
			break;
		}
		}

		if (nextState) {
			return nextState;
		}
	}

	if (gameoverWindow) {
		gameoverWindow->update(mParentSection->mController);
	}

	// if the challenge mode results window is open and finished (we've saved or couldn't save for some reason), transit to quitter
	if (challengeWindow && challengeWindow->update(mParentSection->mController)) {
		// we want to go back to map select after exiting
		mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
		gsys->setFade(0.0f);
		return new QuittingGameModeState(mParentSection);
	}

	// if we're in the day end results screen, process that logic
	if (resultWindow) {
		zen::ogScrResultMgr::returnStatusFlag stat = resultWindow->update(mParentSection->mController);
		if (stat >= 7) {
			// 2-second loading screen
			gsys->startLoading(nullptr, true, 120);
			PRINT("EXITDAYEND!!!!\n");
			// double quadruple check we've cleaned everything up (pikmin counts, cutscenes, heaps)
			gamecore->exitDayEnd();
			gameflow.mMoviePlayer->fixMovieList();
			Jac_SceneSetup(SCENE_Results, JACRES_EndOfDay);
			gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
			gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
			gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
			int heapIdx = gsys->setHeap(SYSHEAP_Teki);
			gsys->setHeap(heapIdx);
			gsys->endLoading();

#if defined(VERSION_G98E01_PIKIDEMO)
			// demo doesn't interact with the memory card
#else
			if (!memcardWindow) {
#endif
			// if we don't have a memory card window open, check if we went back to last save, or continued
			if (stat == 8) {
				// return to last save
				mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_CardSelect;
			} else {
				// map select for a new day
				mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
			}
			// transit to quitter to handle changing subsection
			gsys->setFade(0.0f);
			return new QuittingGameModeState(mParentSection);
#if defined(VERSION_G98E01_PIKIDEMO)
#else
			}
#endif
		}
	}

	// the final result screen is open and done, process what comes next
	if (totalWindow && totalWindow->update(mParentSection->mController)) {
		if (mState == STATE_PhaseTwo) {
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
			totalWindow = nullptr;
		} else {
			// we're done with final results, transit to quitter
			totalWindow = nullptr;
			// next section will be title screen, but queue up exit section first to clean up
			mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_GameExit;
			gsys->setFade(0.0f);
			return new QuittingGameModeState(mParentSection);
		}
	}

#if defined(VERSION_G98E01_PIKIDEMO)
	// no memory card screens in demo
#else

	// handle what happens if we have a memory card-related screen open
	if (memcardWindow) {
		CardQuickInfo info;
		zen::ogScrFileChkSelMgr::returnStatusFlag state = memcardWindow->update(mParentSection->mController, info);
		if (state >= 1) {
			memcardWindow = nullptr;
			if (state != 1 && state != 5) {
				gameflow.mPlayState.mSaveSlot              = info.mGameSaveSlot;
				gameflow.mGamePrefs.mSpareMemCardSaveIndex = info.mMemCardSaveIndex + 1;
				PRINT("using save game file %d with %d as the spare\n", gameflow.mGamePrefs.mMemCardSaveIndex,
				      gameflow.mGamePrefs.mSpareMemCardSaveIndex);

				bool printSetting  = gsys->mTogglePrint != FALSE;
				gsys->mTogglePrint = TRUE;
				PRINT("doing save now!!\n");
				gameflow.mMemoryCard.saveCurrentGame();
				if (mParentSection->mController->keyDown(KBBTN_Z)) {
					kio->startWrite(KIOWRITE_MemoryCard, cardData, CARD_DATA_SIZE);
				}
				gsys->mTogglePrint = printSetting;
				STACK_PAD_VAR(1);
			}
			gsys->setFade(0.0f);
			return new QuittingGameModeState(mParentSection);
		}
	}
#endif

	return this;
}

/**
 * @brief Opens the final results window by getting the relevant trackables and their hiscore ranks.
 */
void DayOverModeState::makeTotalScoreWindow()
{
	// get our final scores!
	GameQuickInfo info;
	info.mDay       = gameflow.mWorldClock.mCurrentDay;
	info.mBornPikis = playerState->getLastPikmins();
	info.mDeadPikis = playerState->getFinalDeadPikis();
	info.mParts     = playerState->getCurrParts();
	// check if any of these set new records, and update the ranks if so
	gameflow.mGamePrefs.checkIsHiscore(info);

	// copy info to something DrawFinalResult can read
	zen::TotalScoreRecord* record = new zen::TotalScoreRecord;
	record->mParts                = info.mParts;
	record->mDay                  = info.mDay;
	record->mPikis                = info.mBornPikis;
	record->mDeadPikis            = info.mDeadPikis;
	record->mTotalPikis           = gameflow.mGamePrefs.mHiscores.mTotalPikis;

	// get all the hiscores to display alongside our new score
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		record->mRecordNumParts[i] = gameflow.mGamePrefs.mHiscores.mMinDayRecords[i].mNumParts;
		record->mRecordNumDays[i]  = gameflow.mGamePrefs.mHiscores.mMinDayRecords[i].mNumDays;
		record->mRecordNumBorn[i]  = gameflow.mGamePrefs.mHiscores.mBornPikminRecords[i].mNumBorn;
		record->mRecordNumDead[i]  = gameflow.mGamePrefs.mHiscores.mDeadPikminRecords[i].mNumDead;
		if (record->mRecordNumDead[i] == 9999) {
			record->mRecordNumDead[i] = -1;
		}
	}

	// get our new score's ranks
	record->mPartsDaysRank = info.mPartsDaysRank;
	record->mBornPikisRank = info.mBornPikisRank;
	record->mDeadPikisRank = info.mDeadPikisRank;

	// make final results window
	totalWindow = new zen::DrawFinalResult(record);
}

/**
 * @brief Finishes processing of phase zero day end state (cutscenes), and sets up for phase one (results or more cutscenes).
 *
 * @return Next mode state to transit to, if any - `nullptr` if we should stay in the current day end state. Always `nullptr` here, since we
 * always need to do phase one processing.
 */
ModeState* DayOverModeState::initialisePhaseOne()
{
	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		// START HAPPY ENDING!
		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();

		// use teki heap for the good ending/pikmin wave cutscene
		gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
		int old = gsys->setHeap(SYSHEAP_Teki);
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingWave, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);

		// restore the heap
		gsys->setHeap(old);

	} else if (gameflow.mWorldClock.mCurrentDay >= MAX_DAYS) {
		// NEUTRAL OR BAD ENDING

		PRINT("EXITDAYEND!!!!\n");
		gamecore->exitDayEnd();

		// use the teki heap for the bad/neutral ending
		gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
		int old = gsys->setHeap(SYSHEAP_Teki);

		// work out what pikmin to use for bad/neutral ending cutscene
		u32 badEndingObjFlags   = 0;
		u32 ids[PikiColorCount] = { Red, Yellow, Blue };
		for (int i = 0; i < PikiColorCount; i++) {
			if (playerState->hasContainer(ids[i])) {
				ADD_ACTOR_PIKMIN_TYPE(badEndingObjFlags, i);
			}
		}
		// we never unlocked yellows, add another red instead
		if (!(badEndingObjFlags & CAF_BadEndingYellowPikmin)) {
			badEndingObjFlags |= CAF_BadEndingExtraRed1;
		}
		// we never unlocked blues, add another red instead
		if (!(badEndingObjFlags & CAF_BadEndingBluePikmin)) {
			badEndingObjFlags |= CAF_BadEndingExtraRed2;
		}

		u32 actorVisFlags            = badEndingObjFlags | ~CAF_AllObjMasks;
		mParentSection->mCurrentFade = -0.1f;
		mParentSection->mTargetFade  = 1.0f;
		gameflow.mMoviePlayer->startMovie(DEMOID_BadEnding, 0, nullptr, nullptr, nullptr, actorVisFlags, true);
		gameoverWindow = nullptr;

		// restore the heap
		gsys->setHeap(old);

	} else {
		// regular day end

		// use teki heap for day end
		gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
		int old                      = gsys->setHeap(SYSHEAP_Teki);
		gameoverWindow               = nullptr;
		mParentSection->mCurrentFade = -0.1f;

		// start no-enemy day end cutscene
		// NB: this will immediately get overridden by take off cutscene if we're not in challenge mode or on Day 1
		gameflow.mMoviePlayer->startMovie(DEMOID_ChalDayEnd, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		if (!playerState->isTutorial() && !gameflow.mIsChallengeMode) {

			// play take off cutscene where we kill any pikmin left behind
			u32 dayEndObjFlags      = 0;
			u32 ids[PikiColorCount] = { Red, Yellow, Blue };
			for (int i = 0; i < PikiColorCount; i++) {
				if (GameStat::victimPikis[ids[i]]) {
					// we had at least one of this color die, add the color to the end of day
					PRINT("got (%d) %d victims\n", i, GameStat::victimPikis[ids[i]]);
					ADD_ACTOR_PIKMIN_TYPE(dayEndObjFlags, i);
				}
			}
			if (dayEndObjFlags == 0) {
				// no dead pikmin! use correct (frustrated/neutral) animation
				dayEndObjFlags |= CAF_DayEndEnemyNoDeaths;
			} else {
				// dead pikmin :( use killing animation
				dayEndObjFlags |= CAF_DayEndEnemyAttack;
			}
			gameflow.mMoviePlayer->startMovie(DEMOID_TakeOff, 0, nullptr, nullptr, nullptr, dayEndObjFlags | ~CAF_AllObjMasks, true);
		}

		// restore heap
		gsys->setHeap(old);
	}

	// move to next phase while take off cutscene is playing
	mState = STATE_PhaseOne;
	return nullptr;
}

/**
 * @brief Finishes processing of phase one day end state (results or cutscenes), and sets up for phase two (ending-only cutscenes).
 *
 * @return Next mode state to transit to, if any - `nullptr` if we should stay in the current day end state. Always `nullptr` here, since we
 * always need to do some post-phase one checks in `update`, even if we don't get to start initialising phase three.
 */
ModeState* DayOverModeState::initialisePhaseTwo()
{
	// take off (or first ending) cutscene has ended - handle what comes next

	// 2 second loading screen to be safe
	gsys->startLoading(nullptr, true, 120);
	PRINT("EXITDAYEND!!!!\n");

	// calc our final pikmin totals
	gamecore->exitDayEnd();

#if defined(VERSION_PIKIDEMO)
	// demo ends when the day ends. *hard* exit.
	gsys->forceHardReset();
	while (true) { }

	return nullptr;
#else

	// clean up all our lingering cutscenes
	gameflow.mMoviePlayer->fixMovieList();

	// get results music ready
	Jac_SceneSetup(SCENE_Results, JACRES_EndOfDay);

	// clean up heaps
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);

	// use teki heap for end of day results
	int old = gsys->setHeap(SYSHEAP_Teki);

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		// we collected all the parts! play the good ending take off :)
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingTakeOff, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);

	} else if (gameflow.mWorldClock.mCurrentDay < MAX_DAYS) {
		PRINT("LOADING YOZURA MOVIE!!\n"); // 'loading night sky movie'
		gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayResults, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);

		if (playerState->hasContainer(Red)) {
			// add red onion flying cutscene
			gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayRedOnyon, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		}
		if (playerState->hasContainer(Yellow)) {
			// add yellow onion flying cutscene
			gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayYellowOnyon, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		}
		if (playerState->hasContainer(Blue)) {
			// add blue onion flying cutscene
			gameflow.mMoviePlayer->startMovie(DEMOID_EndOfDayBlueOnyon, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		}

		// advance the day and handle the end-of-day results entries
		gameflow.mWorldClock.mCurrentDay++;
		if (!gameflow.mIsChallengeMode) {
			// story mode - get a diary entry to show at the end of the day, along with how many pages/screens it has
			int pageCount              = 0;
			zen::EnumResult diaryEntry = (zen::EnumResult)playerState->mResultFlags.getDocument(pageCount);
			if (pageCount == 0) {
				// bad!
				ERROR("zero pages!\n");
			}

			// add all diary entry pages to the table for display.
			int i = 0;
			for (; i < pageCount; i++) {
				// entries can have up to 15 pages technically, but in practice they have a max of 2.
				resultTable[i] = (zen::EnumResult)(diaryEntry + i);
			}
			// signal diary entry end
			resultTable[i] = zen::RESFLAG_DOC_END;

			// start the results window with our chosen diary entry
			resultWindow = new zen::ogScrResultMgr((zen::EnumResult*)resultTable);
			resultWindow->start();

		} else {
			// challenge mode - start the challenge mode results window
			GameChalQuickInfo info;
			PRINT("starting challenge mode window %d : %d!\n", GameStat::formationPikis, GameStat::containerPikis);
			info.mStageID = flowCont.mCurrentStage->mChalStageID;
			info.mScore   = GameStat::allPikis;
			// check if we got a new hiscore for this course, and update the info if so
			gameflow.mGamePrefs.checkIsHiscore(info);

			challengeWindow = new zen::DrawCMresult;
			challengeWindow->start(info);
		}
	} else {
		// we've hit max days, and haven't collected 30 parts :(
		if (playerState->happyEndable()) {
			// we have at least 25 parts, we can take off at least
			flowCont.mEndingType = ENDING_Neutral;
			gameflow.mMoviePlayer->startMovie(DEMOID_NeutralEndingLeaveOK, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		} else {
			// uh oh. play ship crashing back down cutscene and start final results
			gameflow.mMoviePlayer->startMovie(DEMOID_BadEndingFailEscape, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
			makeTotalScoreWindow();
		}
	}

	// restore heap
	gsys->setHeap(old);

	// fade out
	gsys->endLoading();
	mParentSection->mTargetFade = 1.0f;
	mParentSection->mFadeSpeed  = 0.5f;
	// move to next phase
	mState = STATE_PhaseTwo;
	return nullptr;
#endif
}

/**
 * @brief Finishes processing of phase two day end state (ending cutscenes), and sets up for phase three (more ending cutscenes and some
 * final results).
 *
 * @return Next mode state to transit to, if any - `nullptr` if we should stay in the current day end state. Always `nullptr` here, since if
 * we've made it to this phase of processing without transiting (we're in an ending), we'll need to do some post-phase two checks in
 * `update`.
 */
ModeState* DayOverModeState::initialisePhaseThree()
{
	// 2-second loading screen
	gsys->startLoading(nullptr, true, 120);

	// double-quadruple check our cutscene list and heaps are right before we move forward
	gameflow.mMoviePlayer->fixMovieList();
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);

	// use teki heap for these cutscenes
	int old = gsys->setHeap(SYSHEAP_Teki);

	// confirm navi isn't a pilot for the bad ending cutscene, since we crashed again
	// (space cutscenes will re-set this to true, so it's fine)
	playerState->setNavi(false);

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		// happy ending!
		// cute onions floating near the planet cutscene
		gameflow.mMoviePlayer->startMovie(DEMOID_GoodEndingOnyons, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);

	} else if (gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
		// neutral or bad ending
		if (playerState->happyEndable()) {
			// neutral! we made it to space
			gameflow.mMoviePlayer->startMovie(DEMOID_EndingSpace, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
			makeTotalScoreWindow();
		} else {
			// decide what pikmin should be present for the olimin cutscene
			// if we've unlocked a type, make it present (there are a bunch of pikmin of each color)
			u32 oliminObjFlags      = 0;
			u32 ids[PikiColorCount] = { Red, Yellow, Blue };
			for (int i = 0; i < PikiColorCount; i++) {
				if (playerState->hasContainer(ids[i])) {
					ADD_ACTOR_PIKMIN_TYPE(oliminObjFlags, i);
				}
			}
			u32 actorVisFlags = oliminObjFlags | ~CAF_AllObjMasks;
			PRINT("playing movie with mask = %08x\n", actorVisFlags);

			// kill any sprouts, since we need to be near the red onyon (and the focus should be solely on the olimin sprout)
			gamecore->prepareBadEnd();

			// make lighting morning
			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());

			// OLIMIN
			gameflow.mMoviePlayer->startMovie(DEMOID_BadEndingOlimin, 0, nullptr, nullptr, nullptr, actorVisFlags, true);
			gameoverWindow = nullptr;
		}
	}

	// restore heap
	gsys->setHeap(old);
	gsys->endLoading();
	// go to next phase
	mState = STATE_PhaseThree;
	return nullptr;
}

/**
 * @brief Finishes processing of phase three day end state (ending cutscenes), and sets up for phase four (everything being resolved).
 *
 * @return Next mode state to transit to, if any - `nullptr` if we should stay in the current day end state. For neutral and bad endings,
 * this returns a pointer to a new `QuittingGameModeState`, to transit toward the title screen. Happy ending returns `nullptr` here, since
 * if we've made it to this phase of processing without transiting, we'll need to do some post-phase three checks in `update` to clean up
 * the final results screen.
 */
ModeState* DayOverModeState::initialisePhaseFour()
{
	// double-quadruple check we're all good with cutscenes and heaps
	gameflow.mMoviePlayer->fixMovieList();
	gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_DOWN);
	gsys->resetHeap(SYSHEAP_Teki, AYU_STACK_GROW_UP);
	// use teki heap for the space cutscene
	int old = gsys->setHeap(SYSHEAP_Teki);

	if (playerState->getCurrParts() == MAX_UFO_PARTS) {
		// happy ending, do final cutscene flying back to Hocotate
		gameflow.mMoviePlayer->startMovie(DEMOID_EndingSpace, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);

		// final results!
		makeTotalScoreWindow();

	} else {
		// we're done with all other endings, start the quitter to go back to title
		mParentSection->mPendingOnePlayerSectionID = ONEPLAYER_GameExit;
		gsys->setFade(0.0f);
		return new QuittingGameModeState(mParentSection); // When this happens, the heap isnt restored, potential bug?
	}

	// restore heap
	gsys->setHeap(old);
	// move to next (final cleanup) phase
	mState = STATE_PhaseFour;
	return nullptr;
}

//////////////////////////////////////////////////////
//////////////////// SETUP SECTION ///////////////////
//////////////////////////////////////////////////////

/**
 * @brief Inner control section for gameplay, which does a lot more of the labour than its parent `NewPikiGameSection`.
 *
 * This also sets up our `GameCoreSection` instance, which handles even more fine-grain game flow decisions.
 *
 * @note Size: 0x3E0.
 * @note This is required to be this far down in the .cpp file due to .sdata nonsense.
 */
struct NewPikiGameSetupSection : public BaseGameSection {

	/// Constructs a new control section for gameplay, also setting up a lot of other important gameplay controllers in the process.
	NewPikiGameSetupSection()
	{
		// start off in intro mode, to handle any area entry cutscenes
		mCurrentModeState = new IntroGameModeState(this);

		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

		dontShowFrame                  = false;
		gameflow.mIsTutorialTextActive = FALSE;
		mIsInitialSetup                = true;

		// set up life gauge manager
		lgMgr = new LifeGaugeMgr;

		movieIndex                  = 0;
		gameflow.mIsDayEndActive    = FALSE;
		gameflow.mIsDayEndTriggered = FALSE;
		_44                         = 0; // unused

		// set up unused player 2 controller (!!)
		mPlayer2Controller = new Controller(2);

		mNextModeState = nullptr;

		gameInfoIn = false;
		gameInfoOn = false;

		// set up our interface for this section - will always be upcasted to `GameMovieInterface*` here.
		gameflow.mGameInterface = new GameMovieInterface(this);

		// set up frame cacher for pikmin animations
		memStat->start("animCacher");
		gameflow.mFrameCacher = new AnimFrameCacher(5000);
		memStat->end("animCacher");

		flowCont.mIsSunsetStateForceEnded = FALSE;
		flowCont.mIsSunsetWhistleActive   = FALSE;
		flowCont.mIsDayEndSeqStarted      = FALSE;

		// set up teki and movie heaps
		int tekiHeapSize = TEKI_HEAP_SIZE; // = 0xa00000 in the DLL
		gsys->mHeaps[SYSHEAP_Teki].init("teki", AYU_STACK_GROW_UP, new u8[tekiHeapSize], tekiHeapSize);
		int movieHeapSize = MOVIE_HEAP_SIZE;
		gsys->mHeaps[SYSHEAP_Movie].init("movie", AYU_STACK_GROW_UP, new u8[movieHeapSize], movieHeapSize);

		// set up the map!
		PRINT("now doing map!\n");
		memStat->start("mapMgr");
		memStat->start("constructor");
		mapMgr = new MapMgr(mController);
		memStat->end("constructor");

		memStat->start("shape");
		createMapObjects(mapMgr);
		memStat->end("shape");
		memStat->end("mapMgr");

		// set up course-specific music and any relevant windows we'll need urgently
		// our fall-back music is the impact site track
		Jac_SceneSetup(SCENE_Course, (flowCont.mCurrentStage->mStageID < STAGE_COUNT) ? flowCont.mCurrentStage->mStageID : STAGE_Practice);
		init2Ddata();

		// set up our workhorse gameplay handler
		gamecore = new GameCoreSection(mController, mapMgr, mGameCamera);
		add(gamecore);

		// debug menus!
#if defined(DEVELOP) || defined(WIN32)
		typedef Delegate1<NewPikiGameSetupSection, Menu&> NPGSSDelegate1; // This is an insanely long typename to spell.

		// set up options debug menu
		Menu* optionsMenu               = new Menu(mController, gsys->mConsFont);
		optionsMenu->mCenterPoint.mMinX = glnWidth / 2;
		optionsMenu->mCenterPoint.mMinY = glnHeight / 2;
		optionsMenu->mGradBGTopColour.set(MENU_COLOUR_DARK_RED);
		optionsMenu->mGradBGBottomColour.set(MENU_COLOUR_MEDIUM_GREY);
		optionsMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(optionsMenu, &Menu::menuCloseMenu));

		gameflow.addOptionsMenu(optionsMenu);

		// set up movie player debug menu
		Menu* movieMenu               = new Menu(mController, gsys->mConsFont);
		movieMenu->mCenterPoint.mMinX = glnWidth - 110;
		movieMenu->mCenterPoint.mMinY = glnHeight - 88;
		movieMenu->mGradBGTopColour.set(MENU_COLOUR_DARK_RED);
		movieMenu->mGradBGBottomColour.set(MENU_COLOUR_MEDIUM_GREY);
		movieMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(movieMenu, Menu::menuCloseMenu));

		char* movieBuf = new char[0x40];
		sprintf(movieBuf, "Movie #%d", movieIndex);
		movieMenu->addOption(0, movieBuf, nullptr);
		movieMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_Y, new NPGSSDelegate1(this, &menuDecreaseMovie));
		movieMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_X, new NPGSSDelegate1(this, &menuIncreaseMovie));
		movieMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		movieMenu->addOption(0, "Play / Stop", new NPGSSDelegate1(this, &menuPlayMovie));
		movieMenu->addOption(0, "Pause / Frame Step", nullptr);
		movieMenu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_A, new NPGSSDelegate1(this, &menuPauseMovie));
		movieMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_X, new NPGSSDelegate1(this, &menuIncreaseFrame));
		movieMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_Y, new NPGSSDelegate1(this, &menuDecreaseFrame));

		// set up vertical filter menu
		Menu* filterMenu               = new Menu(mController, gsys->mConsFont);
		filterMenu->mCenterPoint.mMinX = glnWidth / 2;
		filterMenu->mCenterPoint.mMinY = glnHeight / 2;
		filterMenu->mGradBGTopColour.set(MENU_COLOUR_DARK_RED);
		filterMenu->mGradBGBottomColour.set(MENU_COLOUR_MEDIUM_GREY);
		filterMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(filterMenu, Menu::menuCloseMenu));

		gameflow.addFilterMenu(filterMenu);

		// set up overall debug menu
		mDebugMenu                     = new Menu(mController, gsys->mConsFont);
		mDebugMenu->mCenterPoint.mMinX = glnWidth / 2;
		mDebugMenu->mCenterPoint.mMinY = glnHeight / 2;
		mDebugMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(mDebugMenu, &Menu::menuCloseMenu));

		mDebugMenu->addOption(0, "Change Course", new NPGSSDelegate1(this, &menuChangeCourse));
		mDebugMenu->addOption(0, "Day End", new NPGSSDelegate1(this, &menuDayEnd));
		mDebugMenu->addMenu(optionsMenu, 0, "Options");
		mDebugMenu->addMenu(gamecore->mAiPerfDebugMenu, 0, "Kando Options");
		if (mapMgr->mDayMgr) {
			mDebugMenu->addMenu(mapMgr->mDayMgr->mMenu, 0, "Lighting");
		}
		mDebugMenu->addMenu(movieMenu, 0, "Movie Player");
		mDebugMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mDebugMenu->addOption(0, "Quit", new NPGSSDelegate1(this, &menuQuitGame));
#endif

		// reset more unused values
		flowCont._254 = 0;
		flowCont._258 = 0;

		_3A8.set(96, 128, 255, 0); // unused color

		// initialise lights and effects
		memStat->start("effects");
		mapMgr->initEffects();
		memStat->end("effects");

		memStat->start("mapMgr");
		mapMgr->createLights();
		memStat->end("mapMgr");

		// REALLY set up the course
		gamecore->initStage();

		// set up more unused colors and floats - maybe something blending-related?
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
			// start our wake-up post-crash-landing cutscene for Day 1
			gameflow.mMoviePlayer->startMovie(DEMOID_OlimarWakeUp, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		} else if (flowCont.mCurrentStage->mStageID < STAGE_COUNT) {
			// landing cutscene if we have a valid stage!
			gameflow.mMoviePlayer->startMovie(DEMOID_Landing, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		}
		gsys->setFade(1.0f);
	}

	/// Opens the debug menu.
	virtual void openMenu() // _30
	{
		mActiveMenu = mDebugMenu;
		mActiveMenu->open(false);
		mActiveMenu->mIsMenuChanging = true;
	}

	/// Updates for this frame - farms a lot of the work out to the active mode state.
	virtual void update() // _10
	{
		mMenuRepeatTimer--;
		if (!gameflow.mMoviePlayer->mIsActive) {
			// if we have no active cutscene (or text screen), reset our movie heap to make sure we're not leaking memory
			if (gsys->getHeap(SYSHEAP_Movie)->getTopUsed()) {
				bool old           = gsys->mTogglePrint != FALSE;
				gsys->mTogglePrint = TRUE;
				gsys->resetHeap(SYSHEAP_Movie, AYU_STACK_GROW_DOWN);
				gsys->mTogglePrint = old;
			}
		}

		// update both player 1 and player 2 (!) controllers
		mController->update();
		mPlayer2Controller->update();

		if (!mIsInitialSetup) {
			// handle any pending mode state transitions
			if (mNextModeState) {
				mCurrentModeState = mNextModeState;
				mNextModeState    = nullptr;
			}
			// update the current/new mode state
			mCurrentModeState = mCurrentModeState->update(mUpdateFlags);
		}

		// update any debug menus we have active
		if (mActiveMenu) {
			mActiveMenu = mActiveMenu->doUpdate(false);
		}
	}

	/**
	 * @brief Renders any section-related objects this frame. A lot of the main work is farmed out to inlines.
	 *
	 * @param gfx Graphics context for rendering.
	 */
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f orthoMtx;

		if (!gameflow.mIsUIOverlayActive || gameflow.mIsTutorialTextActive) {
			// update any cutscenes or text demos
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

				// flip so lerp factor goes from 0 to 1
				f32 tComp = 1.0f - gameflow.mMoviePlayer->mCamTransitionFactor;

				f32 camFov   = cameraMgr->mCamera->getFov();
				f32 movieFov = gameflow.mMoviePlayer->mTargetFov;

#if defined(VERSION_G98E01_PIKIDEMO)
				Vector3f camViewPt(cameraMgr->mCamera->getViewpoint());
				Vector3f movieViewPt(gameflow.mMoviePlayer->mTargetViewpoint);
				Vector3f camWatchPt(cameraMgr->mCamera->getWatchpoint());
				Vector3f movieWatchPt(gameflow.mMoviePlayer->mLookAtPos);

				// unsure why you'd do this vs just a straight lerp factor but okay
				f32 tCompFov = sinf(HALF_PI * tComp);
				tCompFov     = sinf(HALF_PI * tCompFov);
				tCompFov     = sinf(HALF_PI * tCompFov);
				tCompFov     = sinf(HALF_PI * tCompFov);

				// lerp the field of view from movie to gameplay camera
				gfx.mCamera->mFov = movieFov + (camFov - movieFov) * tCompFov;

				// lerp the camera's position from movie to gameplay camera
				gfx.mCamera->mPosition.x = movieViewPt.x + (camViewPt.x - movieViewPt.x) * tComp;
				gfx.mCamera->mPosition.y = movieViewPt.y + (camViewPt.y - movieViewPt.y) * tComp;
				gfx.mCamera->mPosition.z = movieViewPt.z + (camViewPt.z - movieViewPt.z) * tComp;

				// lerp the camera's focus from movie to gameplay camera
				gfx.mCamera->mFocus.x = movieWatchPt.x + (camWatchPt.x - movieWatchPt.x) * tComp;
				gfx.mCamera->mFocus.y = movieWatchPt.y + (camWatchPt.y - movieWatchPt.y) * tComp;
				gfx.mCamera->mFocus.z = movieWatchPt.z + (camWatchPt.z - movieWatchPt.z) * tComp;

				// recalculate camera matrix after changing vectors
				gfx.mCamera->calcLookAt(gfx.mCamera->mPosition, gfx.mCamera->mFocus, nullptr);
#else

				// in the demo, we'd also lerp the camera view (pos) and watch (focus) points from movie to gameplay camera
				// but it seems this was removed in retail - someone forgot to remove these though!
				Vector3f camViewPt(cameraMgr->mCamera->getViewpoint());
				Vector3f movieViewPt(gameflow.mMoviePlayer->mTargetViewpoint);
				Vector3f camWatchPt(cameraMgr->mCamera->getWatchpoint());
				Vector3f targetWatchPt(gameflow.mMoviePlayer->mLookAtPos);

				// just lerp the field of view from movie to gameplay camera (but preserve the eye and target points!)
				gfx.mCamera->mFov = (camFov - movieFov) * tComp + movieFov;
#endif
			} else {
				// no scene or active transition, so set to player cam
				gameflow.mMoviePlayer->setGameCamInfo(true, cameraMgr->mCamera->getFov(), cameraMgr->mCamera->getViewpoint(),
				                                      cameraMgr->mCamera->getWatchpoint());
			}

			gfx.setCamera(&mGameCamera);
			mGameCamera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), mGameCamera.mFov, 100.0f, mCameraFarClip);
		}

		// do any pre-rendering, assuming we're not in a menu
		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
			gsys->mTimer->start("preRender", true);
			preRender(gfx);
			gsys->mTimer->stop("preRender");
		}

		// do the main frame render

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

		// try and update and draw effects
		if (effectMgr) {
			if (!gameflow.mPauseAll && !gameflow.mIsUIOverlayActive || gameflow.mIsTutorialTextActive) {

#if defined(VERSION_G98E01_PIKIDEMO)
				gsys->mTimer->start("effect", true);
#endif
				bool isDVDNormal = true;
				if (gsys->mDvdErrorCode >= DvdError::ReadingDisc) {
					isDVDNormal = false;
				}

				if (isDVDNormal) {
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

		// do any 2D post-rendering (for overlays and windows)
		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
#if defined(VERSION_G98E01_PIKIDEMO)
			gsys->mTimer->start("postRender", true);
#endif
			menuOn = false;
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
			postRender(gfx);
			if (!mActiveMenu && menuWindow) {
				menuOn = menuWindow->draw(gfx);
			}
#if defined(VERSION_G98E01_PIKIDEMO)
			gsys->mTimer->stop("postRender");
#endif
		}

		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));

		// whole section in DLL here about printing some debug text to screen

		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));

		// draw the debug menu if it's open
		if (mActiveMenu) {
			mActiveMenu->draw(gfx, 1.0f);
		}

		if (!mActiveMenu || gameflow.mMoviePlayer->mIsActive) {
			// draw any other main windows we might have open
			if (challengeWindow) {
				gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
				challengeWindow->draw(gfx);
			}
			if (resultWindow) {
				gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
				resultWindow->draw(gfx);
			}
			if (totalWindow) {
				gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
				totalWindow->draw(gfx);
			}
#if defined(VERSION_G98E01_PIKIDEMO)
#else
			if (memcardWindow) {
				gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
				memcardWindow->draw(gfx);
			}
#endif
		}

		BaseGameSection::draw(gfx);
		if (!mIsInitialSetup) {
			// check if we should advance the time of day
			if (!gsys->resetPending() && (!mActiveMenu || gameflow.mMoviePlayer->mIsActive)) {
				if (!gameflow.mPauseAll && !gameflow.mIsUIOverlayActive) {
					if (!gameflow.mMoviePlayer->mIsActive && (mUpdateFlags & UPDATE_WORLD_CLOCK) && !playerState->isTutorial()) {
						f32 tod = gameflow.mWorldClock.mTimeOfDay;
						gameflow.mWorldClock.update(1.0f);
						f32 tod2 = gameflow.mWorldClock.mTimeOfDay;
					}
					// update any children in our list (this will make gamecore update)
					Node::update();
				}
				// update the HUD
				gamecore->mDrawGameInfo->update();
				if (mUpdateFlags & UPDATE_AI && !(gameflow.mDemoFlags & GFDEMO_InMenu)) {
					// update enemy/boss/pikmin/etc AI
					gamecore->updateAI();
				}
			}
		} else {
			// we're still in initial set up - finalise things so we can start properly
			PRINT("final setup!\n");
			gamecore->finalSetup();
			mIsInitialSetup = false;
		}
		if (mNextModeState) {
			// force a mode transition if we have one pending
			PRINT("FORCING MODE !!!!\n");
			mCurrentModeState = mNextModeState;
			mNextModeState    = nullptr;
		}
	}

	/// Sets up our Pikmin font and sets up any relevant windows we might need suddenly (game over, count down, pause screen).
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
#if defined(VERSION_G98E01_PIKIDEMO)
#else
		memcardWindow = nullptr;
#endif
		tutorialWindow = nullptr;
		menuWindow     = nullptr;
		memStat->start("gameover");
		gameoverWindow = new zen::DrawGameOver;
		memStat->end("gameover");

		memStat->start("countdown");
		countWindow = new zen::DrawCountDown;
		memStat->end("countdown");

		memStat->end("gui");

		countWindow->init(gameflow.mParameters->mNightCountdown(), gameflow.mParameters->mNightEnd() - 0.01f, nullptr);
	}

	/**
	 * @brief Sets up the map model and day manager, using information from the stage file.
	 * @param map Active map manager to set up model and day manager for.
	 */
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

	/**
	 * @brief Performs any pre-rendering steps, including handling shadows, etc.
	 * @param gfx Graphics context for rendering.
	 */
	void preRender(Graphics& gfx) { gamecore->mMapMgr->preRender(gfx); }

	/**
	 * @brief Performs the main rendering for a single frame, including getting `gamecore` to also render.
	 * @param gfx Graphics context for rendering.
	 */
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
			mapMgr->mDayMgr->refresh(gfx, isTimeMoving ? gameflow.mWorldClock.mTimeOfDay : TUTORIAL_TIME_OF_DAY, 8); // use 8 lights
			mCameraFarClip = 10000.0f; // anything further than 10000 units isn't rendered

			// force gamecore to also render
			Node::draw(gfx);

		} else {
			// we're in a menu or memory card error screen, act like it.
			mapMgr->mDayMgr->refresh(gfx, MOVIE_TIME, 8);
			gameflow.mMoviePlayer->addLights(gfx);
			gfx.calcLighting(1.0f);
			gameflow.mMoviePlayer->refresh(gfx);
			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.flushCachedShapes();
		}
	}

	/**
	 * @brief Performs any post-rendering, primarily for overlays and things to be drawn on top of regular frame drawing.
	 * @param gfx Graphics context for rendering.
	 */
	void postRender(Graphics& gfx)
	{
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, 60.0f, gfx.mCamera->mAspectRatio, 1.0f, gfx.mCamera->mFar, 1.0f);

		Matrix4f unused;
		unused.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));

		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		mCurrentModeState->postRender(gfx);
		Matrix4f orthoMtx;
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
	}

	/**
	 * @brief Debug menu callback to quit game to title. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuQuitGame(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		parent.close();
		mPendingOnePlayerSectionID = ONEPLAYER_GameExit;
		gsys->setFade(0.0f);
		mNextModeState = new QuittingGameModeState(this);
	}

	/**
	 * @brief Debug menu callback to go straight to map select. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuChangeCourse(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		parent.close();
		mPendingOnePlayerSectionID = ONEPLAYER_MapSelect;
		gsys->setFade(0.0f);
		mNextModeState = new QuittingGameModeState(this);
	}

	/**
	 * @brief Debug menu callback to end the day. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuDayEnd(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		parent.close();
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
	}

	/**
	 * @brief Debug menu callback to step current cutscene backward by one frame. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuDecreaseFrame(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			// pause the current cutscene so we step through frame-by-frame
			gameflow.mMoviePlayer->mIsPaused = true;

			// we just had an input, set a delay for the next one to be detected
			if (mMenuRepeatTimer < -1) {
				mMenuRepeatDelay = 4;
				mMenuRepeatTimer = 0;
			}

			// timer expired => we're holding the button, lock out input but decrease the delay
			if (mMenuRepeatTimer < 0) {
				mMenuRepeatTimer = mMenuRepeatDelay;
				if (mMenuRepeatDelay > 0) {
					// accelerate our input rate (holding the button speeds up our inputs)
					// this will eventually just run the cutscene at -30 fps if held down
					--mMenuRepeatDelay;
				}
				gameflow.mMoviePlayer->backFrame();
			}
		}
	}

	/**
	 * @brief Debug menu callback to step current cutscene forward by one frame. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuIncreaseFrame(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			// pause the current cutscene so we step through frame-by-frame
			gameflow.mMoviePlayer->mIsPaused = true;

			// we just had an input, set a delay for the next one to be detected
			if (mMenuRepeatTimer < -1) {
				mMenuRepeatDelay = 4;
				mMenuRepeatTimer = 0;
			}
			// timer expired => we're holding the button, lock out input but decrease the delay
			if (mMenuRepeatTimer < 0) {
				mMenuRepeatTimer = mMenuRepeatDelay;
				if (mMenuRepeatDelay > 0) {
					// accelerate our input rate (holding the button speeds up our inputs)
					// this will eventually just run the cutscene at 30 fps if held down
					--mMenuRepeatDelay;
				}
				gameflow.mMoviePlayer->nextFrame();
			}
		}
	}

	/**
	 * @brief Debug menu callback to increase selected cutscene index. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuIncreaseMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		// we just had an input, set a delay for the next one to be detected
		if (mMenuRepeatTimer < -1) {
			mMenuRepeatDelay = 4;
			mMenuRepeatTimer = 0;
		}
		// timer expired => we're holding the button, lock out input but decrease the delay
		if (mMenuRepeatTimer < 0) {
			mMenuRepeatTimer = mMenuRepeatDelay;
			if (mMenuRepeatDelay > 0) {
				// accelerate our input rate (holding the button speeds up our inputs)
				--mMenuRepeatDelay;
			}
			++movieIndex;
		}
		// set correct movie ID bounds
		if (movieIndex > TERNARY_BUGFIX(DEMOID_COUNT - 1, DEMOID_EndOfDayRedOnyon)) {
			movieIndex = TERNARY_BUGFIX(DEMOID_COUNT - 1, DEMOID_EndOfDayRedOnyon);
		}
		sprintf(parent.mCurrentItem->mLabel, "Movie #%d", movieIndex);
	}

	/**
	 * @brief Debug menu callback to decrease selected cutscene index. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuDecreaseMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		// we just had an input, set a delay for the next one to be detected
		if (mMenuRepeatTimer < -1) {
			mMenuRepeatDelay = 4;
			mMenuRepeatTimer = 0;
		}
		// timer expired => we're holding the button, lock out input but decrease the delay
		if (mMenuRepeatTimer < 0) {
			mMenuRepeatTimer = mMenuRepeatDelay;
			if (mMenuRepeatDelay > 0) {
				// accelerate our input rate (holding the button speeds up our inputs)
				--mMenuRepeatDelay;
			}
			--movieIndex;
		}
		// set correct movie ID bounds
		if (movieIndex < 0) {
			movieIndex = 0;
		}
		sprintf(parent.mCurrentItem->mLabel, "Movie #%d", movieIndex);
	}

	/**
	 * @brief Debug menu callback to start the chosen cutscene. DLL-only.
	 * @param parent Parent debug menu.
	 */
	void menuPlayMovie(Menu& parent)
	{
		// UNUSED FUNCTION (DLL inline)
		if (gameflow.mMoviePlayer->mIsActive) {
			gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
		} else {
			gameflow.mMoviePlayer->mIsPaused = false;
			gameflow.mMoviePlayer->startMovie(movieIndex, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, false);
		}
	}

	/**
	 * @brief Debug menu callback to pause/unpause the currently playing cutscene. DLL-only.
	 * @param parent Parent debug menu.
	 */
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
	u32 _44;                        ///< _044, unused/unknown.
	u8 _48[0x50 - 0x48];            ///< _048, unused/unknown.
	Menu* mDebugMenu;               ///< _050, debug menu, only enabled in DEVELOP builds.
	Controller* mPlayer2Controller; ///< _054, controller for player 2 - never used, but set up and updated.
	Font* mGameFont;                ///< _058, "big" font, seemingly for screens - set up, but never used.
	Camera mGameCamera;             ///< _05C, camera following captain.
	f32 mCameraFarClip;             ///< _3A4, max render distance from the camera.
	Colour _3A8;                    ///< _3A8, unused/unknown.
	Colour _3AC[2];                 ///< _3AC, unused/unknown.
	Colour _3B4[2];                 ///< _3B4, unused/unknown.
	Colour _3BC[2];                 ///< _3BC, unused/unknown.
	f32 _3C4[4];                    ///< _3C4, unused/unknown.
	bool mIsInitialSetup;           ///< _3D4, are we still in the initial setup phase? Cannot do certain actions til we're done.
	int mMenuRepeatTimer;           ///< _3D8, timer for detecting repeat inputs in the movie debug menu so we don't scroll too fast.
	int mMenuRepeatDelay;           ///< _3DC, decreasing lockout for repeat inputs in the movie debug menu, for variable scroll speed.
};

//////////////////////////////////////////////////////
/////////////////// MOVIE FUNCTIONS //////////////////
//////////////////////////////////////////////////////

/**
 * @brief Processes the current command and movie queues until they're empty.
 */
void GameMovieInterface::parseMessages()
{
	// process all queued commands
	for (int i = 0; i < mSimpleMessageCount; i++) {
		parse(mSimpMesg[i]);
	}
	mSimpleMessageCount = 0;

	// process all queued movies
	for (int i = 0; i < mComplexMesgCount; i++) {
		parse(mCompMesg[i]);
	}

	mComplexMesgCount = 0;
}

/**
 * @brief Actions the given movie command and any associated data.
 *
 * @param msg Simple message containing command and possible data to process.
 */
void GameMovieInterface::parse(GameMovieInterface::SimpleMessage& msg)
{
	int cmd  = msg.mCommand;
	int data = msg.mData;

#if defined(VERSION_GPIP01_00)
	OSReport("!!!!!!!!!!! Got message %d : %d\n", cmd, data);
#endif

	switch (cmd) {
	case MOVIECMD_TextDemo:
	{
		// open a text window - data here should use the zen::ogScrTutorialMgr::EnumTutorial enum (text ID)
		PRINT("***** START TUTORIAL WINDOW\n");
		int ufoPartID = -1;
		bool hasAudio = false;
		if (data == zen::ogScrTutorialMgr::TUT_GetParts) {
			// we want a ship part-related text box - either interacting with ship or actual part

			// we have no target part - we're either interacting with the ship
			// or have just collected the engine (since the power-up animation needs to happen before any text)
			if (gameflow.mShipTextPartID == UFO_NOPART) {
				if (gameflow.mShipTextType == SHIPTEXT_CollectEngine) {
					gameflow.mMoviePlayer->skipScene(SCENESKIP_Skip);
					return;

				} else if (gameflow.mShipTextType == SHIPTEXT_PartCollect) {
					// interacting with the Dolphin by pressing A at the ship body itself
					data = zen::ogScrTutorialMgr::TUT_HitUFO;
				} else {
					// this is the damage critical text box, but never gets called like this - this is a fallback
					data = zen::ogScrTutorialMgr::TUT_APunchUFO;
				}

			} else if (gameflow.mShipTextType == SHIPTEXT_PartCollect) {
				// collecting a ship part!
				data = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsGetOffset;

			} else if (gameflow.mShipTextType == SHIPTEXT_PartsAccess) {
				// interacting with a part directly before collection (little info box)
				data      = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsInfoOffset;
				hasAudio  = false;
				ufoPartID = gameflow.mShipTextPartID;

			} else if (gameflow.mShipTextType == SHIPTEXT_PowerUp) {
				// upgrading the Dolphin
				PRINT("showing power up message (%d)!!\n", gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsPower);
				int id = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsPower;
				// handle final part differently, since we'll need to go straight to the good ending
				if (gameflow.mShipTextPartID == UFO_SecretSafe) {
					dontShowFrame = true;
					data          = zen::ogScrTutorialMgr::TUT_FinishUFO;
				} else {
					data = id;
				}

			} else if (gameflow.mShipTextType == SHIPTEXT_PartDiscovery) {
				// we walked close to a part for the first time
				ufoPartID = gameflow.mShipTextPartID;
				hasAudio  = true;
				data      = gameflow.mShipTextPartID + zen::ogScrTutorialMgr::TUT_PartsGetOnlyOffset;
			}
		}

		createTutorialWindow(data, ufoPartID, hasAudio);
		gameflow.mIsUIOverlayActive = TRUE;
		break;
	}
	case MOVIECMD_Unused:
	{
		// bad!
		ERROR("SHOULD NOT GET THIS COMMAND!!!\n");
		break;
	}
	case MOVIECMD_ForceDayEnd:
	{
		// force day to end
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
		break;
	}
	case MOVIECMD_HideHUD:
	{
		// hide the game HUD with a 0.5s fade-out
		showFrame(false, 0.5f);
		break;
	}
	case MOVIECMD_ShowHUD:
	{
		// show the game HUD with a 0.5s fade-in
		showFrame(true, 0.5f);
		break;
	}
	case MOVIECMD_GameEndCondition:
	{
		// cause the day to end. data here should use `GameEndCause` enum.
		if (data == ENDCAUSE_PikminZero) {
			// pikmin zero!
			if (flowCont.mGameEndFlag == GAMEEND_PikminExtinction) {
				// we already have the pikmin extinction flag set, go straight to day end if we're not on day 30
				if (!gameflow.mIsChallengeMode && gameflow.mWorldClock.mCurrentDay != MAX_DAYS) {
					gameflow.mMoviePlayer->startMovie(DEMOID_ExtDayEnd, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
					gameflow.mWorldClock.setTime(gameflow.mParameters->mEndHour());
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::MODE_Extinction, 40.0f);
					}
					// fade to black
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
				gameflow.mMoviePlayer->startMovie(DEMOID_Extinction, 0, navi, &navi->mSRT.t, &navi->mSRT.r, CAF_AllVisibleMask, true);
				if (gameflow.mIsChallengeMode || gameflow.mWorldClock.mCurrentDay == MAX_DAYS) {
					// if we're in challenge mode or on the final day, display Pikmin Extinction text now, since we don't end the day
					if (gameoverWindow) {
						gameoverWindow->start(zen::DrawGameOver::MODE_Extinction, 40.0f);
					}
				}
			}
		} else {
			// data = ENDCAUSE_NaviDown
			flowCont.mGameEndFlag = GAMEEND_NaviDown;
			PRINT("got navi dead flag!!\n");
		}
		break;
	}
	case MOVIECMD_ForceResults:
	{
		// force going to results screen - in practice, this does nothing.
		PRINT("got FORCE RESULTS SCREEN !!!\n");
		flowCont.mGameEndFlag = GAMEEND_None;
		break;
	}
	case MOVIECMD_StartMovie:
	{
		// start playing a cutscene
		bool useNaviView = (data & CinePlayerFlags::UseNaviView) != 0;
		gamecore->startMovie(data & ~CinePlayerFlags::UseNaviView, useNaviView);
		PRINT("%s\n", useNaviView ? "HIDING NAVI!!!" : "not hiding!");
		break;
	}
	case MOVIECMD_EndMovie:
	{
		// stop playing a cutscene
#if defined(VERSION_PIKIDEMO)
		// demo version takes no parameter because it has no cutscene-specific behaviour
		gamecore->endMovie();
#else
		// after demo, devs added some angle changes for finding each onyon, and for the main engine cutscene, so need the ID.
		gamecore->endMovie(data);
#endif
		break;
	}
	case MOVIECMD_FadeOut:
	{
		// start a fade-out from gameplay
		mSetupSection->mTargetFade = 0.0f;
		mSetupSection->mFadeSpeed  = 4.5f;
		break;
	}
	case MOVIECMD_FadeIn:
	{
		// start a fade-in to gameplay
		mSetupSection->mCurrentFade = 0.0f;
		mSetupSection->mTargetFade  = 1.0f;
		mSetupSection->mFadeSpeed   = 2.5f;
		break;
	}
	case MOVIECMD_CleanupDayEnd:
	{
		// cleanup day end! we clearly should not get this message.
		PRINT("MESSAGE CLEANUPDAYEND!!!!\n");
		PRINT("wwwwwhhhhyyyyyy??????|!!!\n");
		gamecore->cleanupDayEnd();
		break;
	}
	case MOVIECMD_StartTotalResults:
	{
		// start the final results for story mode
		PRINT("starting total results!!\n");
		totalWindow->start();
		Jac_SceneSetup(SCENE_Results, JACRES_FinalResult);
		break;
	}
	case MOVIECMD_SpecialDayEnd:
	{
		// we collected all the parts! end the day and show the happy ending.
		gamecore->forceDayEnd();
		gameflow.mIsDayEndTriggered = TRUE;
		flowCont.mEndingType        = ENDING_Happy;
		break;
	}
	case MOVIECMD_SetPauseAllowed:
	{
		// allow/disallow pausing. data here is a BOOL for whether to allow pausing.
		gameflow.mIsPauseAllowed = data;
		break;
	}
	case MOVIECMD_CountDownLastSecond:
	{
		// this does nothing - maybe commented out code, or some flexibility for handling things last-second?
		break;
	}
	case MOVIECMD_StageFinish:
	{
		// game over! pikmin extinction or navi dead, end the day.
		PRINT("GOT STAGE FINISH MESSAGE!!!\n");
		gamecore->forceDayEnd();
		break;
	}
	case MOVIECMD_CreateMenuWindow:
	{
		// open the Y menu (map and controls etc)
		createMenuWindow();
		break;
	}
#if defined(VERSION_G98E01_PIKIDEMO)
	case MOVIECMD_DemoFinish:
	{
		// show the happy ending text at the end of the demo :)
		createTutorialWindow(zen::ogScrTutorialMgr::TUT_HappyEnding, -1, false);
		gameflow.mIsUIOverlayActive = TRUE;
		break;
	}
#else
#endif
	}
}

/**
 * @brief Starts a cutscene with the given cutscene information (in the form of a ComplexMessage).
 *
 * @param msg Message containing all information needed to start the cutscene.
 */
void GameMovieInterface::parse(GameMovieInterface::ComplexMessage& msg)
{
	gameflow.mMoviePlayer->startMovie(msg.mMovieIdx, msg._04, msg.mTarget, &msg.mPosition, &msg.mRotation, msg.mActorVisMask,
	                                  msg.mIsPlaying);
}

//////////////////////////////////////////////////////
//////////////////// GAME SECTION ////////////////////
//////////////////////////////////////////////////////

/**
 * @brief Constructs gameplay subsection - either challenge mode or story mode.
 *
 * Most of the hard work gets farmed out to `NewPikiGameSetupSection` above and any mode states, including transiting to a new subsection.
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

	flowCont.mGameEndFlag = GAMEEND_None;
#if defined(VERSION_GPIP01_00)
	// in PAL, day end is skippable unless it's a special day end
	flowCont.mIsDayEndSkippable = TRUE;
	flowCont.mIsDayEndSkipped   = FALSE;
#endif

	// run gameplay at 30 fps
	gsys->setFrameClamp(2);

#ifdef WIN32
	_nPrint = FALSE;
	_kPrint = FALSE;
#endif

	// these will get set up by NewPikiGameSetupSection or GameCoreSection
	mapMgr = nullptr;
	npgss  = nullptr;

	memStat->start("all");
	// the actual workhorse for gameplay
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

//////////////////////////////////////////////////////
