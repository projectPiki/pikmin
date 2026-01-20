#include "CardSelectSection.h"

#include "BaseInf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
#include "Generator.h"
#include "Graphics.h"
#include "MemoryCard.h"
#include "PlayerState.h"
#include "Section.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "sysNew.h"
#include "zen/ogFileChkSel.h"

// Macros for packing and unpacking the section compression flag.
// (this packing is a holdover from TitlesSection where there's also section transitions, not just OnePlayerSection).

/// Packs next OnePlayerSection subsection ID to transit to, to be stored in a flag.
#define PACK_NEXT_ONEPLAYER(onePlayerID) (onePlayerID) << 16

/// Unpacks next OnePlayerSection subsection ID from flag.
#define UNPACK_NEXT_ONEPLAYER(flag) (flag) >> 16

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("CardSelect")

/// Screen/window for memory card selection.
static zen::ogScrFileChkSelMgr* memcardWindow;

/**
 * @brief Initialising object for the Memory Card selection section.
 *
 * Localised to just the source file, so effectively private.
 * (Lives in the source file because it has file-specific PRINT statements.)
 *
 * @note Size: 0x38.
 */
struct CardSelectSetupSection : public Node {

	/**
	 * @brief States that the section can be in, to control transitions and actions.
	 */
	enum State {
		Inactive = -1, ///< no longer active.
		Active   = 0,  ///< normal/active state.
		Exit     = 1,  ///< fading out/exiting.
	};

	/// Constructs a card select helper object; also sets up a new memory card selection screen.
	CardSelectSetupSection()
	{
		setName("CardSelect section");

		// This section uses `SeSystem` without constructing it.
#if defined(BUGFIX)
		seSystem = new SeSystem();
#endif

		mJacSetupCountdown = 5;
		mController        = new Controller(1);
		mState             = Active;

		// reset the window pointer
		memcardWindow = nullptr;
		memcardWindow = new zen::ogScrFileChkSelMgr();
		memcardWindow->start(gameflow.mIsChallengeMode); // challenge mode skips file select

		gsys->setFade(1.0f);
		mNextSectionsFlag = 0; // indicates we haven't set a destination yet (we're past setup)
	}

	/// Updates the screen each frame and alters the state.
	virtual void update() // _10 (weak)
	{
		mController->update();
		if (!memcardWindow && mState == Active) {
			// fade out
			mState = Exit;
			gsys->setFade(0.0f);
		}

		if (memcardWindow && gameflow.mIsChallengeMode && mJacSetupCountdown != 0) {
			mJacSetupCountdown--;

			if (mJacSetupCountdown == 0) {
#ifndef WIN32
				Jac_SceneSetup(SCENE_FileSelect, 0);
#endif
			}
		}

		if (mState == Exit && gsys->getFade() == 0.0f) {
			// fading out is done
			mState = Inactive;
			if (mNextSectionsFlag) {
				// we picked a destination!
				gameflow.mNextOnePlayerSectionID = UNPACK_NEXT_ONEPLAYER(mNextSectionsFlag);
			} else {
				if (!gameflow.mIsChallengeMode) {
					PRINT("NORMAL MODE!!!\n");

					gameflow.mWorldClock.mCurrentDay = 1;
					if (gameflow.mGamePrefs.mHasSaveGame) {
						// save game exists, load it
						gameflow.mMemoryCard.loadCurrentGame();
						if (gameflow.mPlayState.mSaveStatus == PlayState::Fresh) {
							gameflow.mPlayState.Initialise();
							gameflow.mPlayState.mSaveStatus = PlayState::ReadyToSave;
						}

						// next subsection will be map select
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;

					} else {
						PRINT("NO SAVE GAMES!\n");
						gameflow.mPlayState.Initialise();

						// next subsection will be the new game intro cutscene
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_IntroGame;
					}

					if (playerState->isTutorial()) {
						// we're in day 1, do things a bit differently
						StageInfo* stage       = (StageInfo*)flowCont.mStageList.mChild;
						flowCont.mCurrentStage = stage;
						sprintf(flowCont.mCurrStageFilePath, "%s", stage->mFileName);
						sprintf(flowCont.mDoorStageFilePath, "%s", stage->mFileName);
						// day one is locked at 2:48pm
						gameflow.mWorldClock.setTime(TUTORIAL_TIME_OF_DAY);
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_IntroGame;
					}
				} else {
					PRINT("CHALLENGE MODE!!!\n");
					gameflow.mPlayState.Initialise();
					if (gameflow.mIsChallengeMode) {
						playerState->setChallengeMode();
					}

					// next subsection will be (challenge mode) map select
					gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;
				}

				// don't show any preference for ship position or any unlock animations on map screen
				gameflow.mCurrentStageID       = -1;
				gameflow.mPendingStageUnlockID = -1;
			}

#ifndef WIN32
			Jac_SceneExit(SCENE_Exit, 0);
#endif

			// force transit to next section
			gsys->softReset();
		}
	}

	/**
	 * @brief Renders the screen and adjusts the render based on screen status.
	 * @param gfx Graphics context for rendering.
	 */
	virtual void draw(Graphics& gfx) // _14 (weak)
	{
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);

		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));

		if (!memcardWindow) {
			// nothing to draw
			return;
		}

		// if screen indicates an exit or error, process that before drawing
		CardQuickInfo card;
		zen::ogScrFileChkSelMgr::returnStatusFlag returnCode = memcardWindow->update(mController, card);

		// process any error or exit codes
		if (returnCode >= zen::ogScrFileChkSelMgr::FILECHKSEL_Exit) {
			PRINT("got return code .... %d\n", returnCode);

			// close the memory card window and decide what to do next
			memcardWindow = nullptr;
			if (returnCode == zen::ogScrFileChkSelMgr::ErrorOrCompleted) {
				// back out to title screen
				mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameExit);
				mState            = Exit;
				gsys->setFade(0.0f);

			} else if (returnCode == zen::ogScrFileChkSelMgr::ForceExit) {
				// force close and let update sort out where we go
				mNextSectionsFlag = 0;
				mState            = Exit;
				gsys->setFade(0.0f);

			} else {
				// we selected a a save file (A, B, or C)
				gameflow.mGamePrefs.mHasSaveGame        = true;
				gameflow.mSaveGameCrc                   = card.mCrc;
				gameflow.mGamePrefs.mMostRecentFileSlot = returnCode - zen::ogScrFileChkSelMgr::FILECHKSEL_SlotOffset;
				PRINT("got index = %d\n", card.mMemCardSaveIndex);
				gameflow.mGamePrefs.mMemCardSaveIndex = card.mMemCardSaveIndex + 1;
				PRINT("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				PRINT("using save game file %d (crc = %08x) with %d as the spare\n", gameflow.mGamePrefs.mMemCardSaveIndex,
				      gameflow.mSaveGameCrc, gameflow.mGamePrefs.mSpareMemCardSaveIndex);
				gameflow.mWorldClock.mCurrentDay = card.mCurrentDay;
				mState                           = Exit;
				gsys->setFade(0.0f);
			}
		}

		if (memcardWindow) {
			// render the screen
			memcardWindow->draw(gfx);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 mState;              ///< _20, whether screen is inactive, active, or exiting - see `State` enum.
	u32 mNextSectionsFlag;   ///< _24, flag that stores the next OnePlayerSection - see `ONEPLAYER` macros.
	u8 _28[0x30 - 0x28];     ///< _28, unused/unknown.
	Controller* mController; ///< _30, active controller.
	int mJacSetupCountdown;  ///< _34, frame countdown before setting up audio scene (CM only).
};

/**
 * @brief Constructs card access/file select subsection.
 *
 * Most of the hard work gets farmed out to `CardSelectSetupSection` above, including transiting to a new subsection.
 */
CardSelectSection::CardSelectSection()
{
	Node::init("<CardSelectSection>");
	// run card select at 60 fps
	gsys->setFrameClamp(1);

	// reset everything game-related
	flowCont.mCurrentStage = nullptr;
	playerState->initGame();
	generatorCache->initGame();
	pikiInfMgr.initGame();
	FOREACH_NODE(StageInfo, flowCont.mStageList.mChild, stage)
	{
		stage->mHasInitialised = FALSE;
		stage->mStageInf.initGame();
	}

	gameflow.mGamePrefs.mMemCardSaveIndex = 0;
	gameflow.mGamePrefs.mHasSaveGame      = false;

	if (gameflow.mIsChallengeMode == FALSE) {
		Jac_SceneSetup(SCENE_FileSelect, 0);
	}

	gsys->startLoading(nullptr, true, 60);

	// this does the actual hard work of setting things up.
	add(new CardSelectSetupSection());
	gsys->endLoading();
}
