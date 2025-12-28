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

/// Macros for packing and unpacking the section compression flag.
#define PACK_NEXT_ONEPLAYER(onePlayerID) (onePlayerID) << 16
#define UNPACK_NEXT_ONEPLAYER(flag)      (flag) >> 16

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
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

	/// Constructor.
	CardSelectSetupSection()
	{
		setName("CardSelect section");

		// This section uses `SeSystem` without constructing it.
#if defined(BUGFIX)
		seSystem = new SeSystem();
#endif

		mJacSetupCountdown = 5;
		mController        = new Controller();
		mFadeState         = 0;

		// reset the window pointer
		memcardWindow = nullptr;
		memcardWindow = new zen::ogScrFileChkSelMgr();
		memcardWindow->start(gameflow.mIsChallengeMode);

		gsys->setFade(1.0f, 3.0f);
		mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
	}

	/// Updates the screen each frame and alters the state.
	virtual void update() // _10 (weak)
	{
		mController->update();
		if (!memcardWindow && mFadeState == 0) {
			// no window, fade in
			mFadeState = 1;
			gsys->setFade(0.0f, 3.0f);
		}

		if (memcardWindow && gameflow.mIsChallengeMode && mJacSetupCountdown != 0) {
			mJacSetupCountdown--;

			if (mJacSetupCountdown == 0) {
#ifndef WIN32
				Jac_SceneSetup(SCENE_Unk2, 0);
#endif
			}
		}

		if (mFadeState == 1 && gsys->getFade() == 0.0f) {
			// fade in is done
			mFadeState = -1;
			if (mNextSectionsFlag) {
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

						// put us in the map select screen
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;

					} else {
						PRINT("NO SAVE GAMES!\n");
						gameflow.mPlayState.Initialise();

						// start the intro cutscene
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
					gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;
				}

				gameflow.mCurrentStageID       = -1;
				gameflow.mPendingStageUnlockID = -1;
			}

#ifdef __MWERKS__
			Jac_SceneExit(SCENE_Unk13, 0);
#endif
			gsys->softReset();
		}
	}

	/// Renders the screen and adjusts the render based on screen status.
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
		if (returnCode >= zen::ogScrFileChkSelMgr::FILECHKSEL_Exit) {
			PRINT("got return code .... %d\n", returnCode);

			memcardWindow = nullptr;
			if (returnCode == zen::ogScrFileChkSelMgr::ErrorOrCompleted) {
				mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameExit);
				mFadeState        = 1;
				gsys->setFade(0.0f, 3.0f);
			} else if (returnCode == zen::ogScrFileChkSelMgr::FILECHKSEL_Unk5) {
				mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
				mFadeState        = 1;
				gsys->setFade(0.0f, 3.0f);
			} else {
				// 2/3/4 = we selected a a save file (A, B, or C)
				gameflow.mGamePrefs.mHasSaveGame        = true;
				gameflow.mSaveGameCrc                   = card.mCrc;
				gameflow.mGamePrefs.mMostRecentFileSlot = returnCode - 2;
				PRINT("got index = %d\n", card.mMemCardSaveIndex);
				gameflow.mGamePrefs.mMemCardSaveIndex = card.mMemCardSaveIndex + 1;
				PRINT("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				PRINT("using save game file %d (crc = %08x) with %d as the spare\n", gameflow.mGamePrefs.mMemCardSaveIndex,
				      gameflow.mSaveGameCrc, gameflow.mGamePrefs.mSpareMemCardSaveIndex);
				gameflow.mWorldClock.mCurrentDay = card.mCurrentDay;
				mFadeState                       = 1;
				gsys->setFade(0.0f, 3.0f);
			}
		}

		if (memcardWindow) {
			// render the screen
			memcardWindow->draw(gfx);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 mFadeState;          ///< _20, whether screen is fading in, static or off.
	u32 mNextSectionsFlag;   ///< _24, flag that stores the next OnePlayerSection and Section - see defines in Section.h.
	u8 _28[0x30 - 0x28];     ///< _28, unused/unknown region.
	Controller* mController; ///< _30, active controller.
	int mJacSetupCountdown;  ///< _34, frame countdown before setting up audio scene (CM only).
};

/**
 * @todo: Documentation
 */
CardSelectSection::CardSelectSection()
{
	Node::init("<CardSelectSection>");
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
		Jac_SceneSetup(SCENE_Unk2, 0);
	}

	gsys->startLoading(nullptr, true, 60);

	// this does the actual hard work of setting things up.
	add(new CardSelectSetupSection());
	gsys->endLoading();
}
