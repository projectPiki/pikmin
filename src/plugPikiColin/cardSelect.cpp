#include "CardSelectSection.h"

#include "BaseInf.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "gameflow.h"
#include "Generator.h"
#include "Graphics.h"
#include "MemoryCard.h"
#include "PlayerState.h"
#include "Section.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "jaudio/piki_scene.h"
#include "zen/ogFileChkSel.h"

/**
 * @brief Error function for cardSelect.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/**
 * @brief Print function for cardSelect.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	0000F4
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
		mJacSetupCountdown = 5;
		mController        = new Controller();
		mFadeState         = 0;

		// reset the window pointer
		memcardWindow = nullptr;
		memcardWindow = new zen::ogScrFileChkSelMgr();
		memcardWindow->start(gameflow.mIsChallengeMode);

		gsys->setFade(1.0f, 3.0f);
		mNextSectionID = 0;
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
#ifdef __MWERKS__
				Jac_SceneSetup(2, 0);
#endif
			}
		}

		if (mFadeState == 1 && gsys->getFade() == 0.0f) {
			// fade in is done
			mFadeState = -1;
			if (mNextSectionID) {
				gameflow.mNextOnePlayerSectionID = mNextSectionID >> 16;
			} else {
				if (!gameflow.mIsChallengeMode) {
					PRINT("NORMAL MODE!!!\n");

					gameflow.mWorldClock.mCurrentDay = 1;
					if (gameflow.mGamePrefs.mHasSaveGame) {
						// save game exists, load it
						gameflow.mMemoryCard.loadCurrentGame();
						if (gameflow.mPlayState.mSaveStatus == 1) {
							gameflow.mPlayState.Initialise();
							gameflow.mPlayState.mSaveStatus = 2;
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
						StageInfo* stage       = flowCont.mRootInfo.getChild();
						flowCont.mCurrentStage = stage;
						sprintf(flowCont.mStagePath1, "%s", stage->mFileName);
						sprintf(flowCont.mStagePath2, "%s", stage->mFileName);
						// day one is locked at 2:48pm
						gameflow.mWorldClock.setTime(14.8f);
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

				gameflow.mCurrentStageId      = -1;
				gameflow.mLastUnlockedStageId = -1;
			}

#ifdef __MWERKS__
			Jac_SceneExit(13, 0);
#endif
			gsys->softReset();
		}
	}

	/// Renders the screen and adjusts the render based on screen status.
	virtual void draw(Graphics& gfx) // _14 (weak)
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, false);

		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

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
				mNextSectionID = ONEPLAYER_GameExit << 16;
				mFadeState     = 1;
				gsys->setFade(0.0f, 3.0f);
			} else if (returnCode == zen::ogScrFileChkSelMgr::FILECHKSEL_Unk5) {
				mNextSectionID = ONEPLAYER_GameSetup;
				mFadeState     = 1;
				gsys->setFade(0.0f, 3.0f);
			} else {
				// 2/3/4 = we selected a a save file (A, B, or C)
				gameflow.mGamePrefs.mHasSaveGame = true;
				gameflow.mSaveGameCrc            = card.mCrc;
				gameflow.mGamePrefs.mFileNum     = returnCode - 2;
				PRINT("got index = %d\n", card.mIndex);
				gameflow.mGamePrefs.mSaveGameIndex = card.mIndex + 1;
				PRINT("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				PRINT("using save game file %d (crc = %08x) with %d as the spare\n", gameflow.mGamePrefs.mSaveGameIndex,
				      gameflow.mSaveGameCrc, gameflow.mGamePrefs.mSpareSaveGameIndex);
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
	u32 mNextSectionID;      ///< _24, flag that stores the next OnePlayerSection section.
	u8 _28[0x30 - 0x28];     ///< _28, unused/unknown region.
	Controller* mController; ///< _30, active controller.
	int mJacSetupCountdown;  ///< _34, frame countdown before setting up audio scene (CM only).
};

/**
 * --INFO--
 * Address:	8005503C
 * Size:	00023C
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
	FOREACH_NODE(StageInfo, flowCont.mRootInfo.mChild, stage)
	{
		stage->mHasInitialised = FALSE;
		stage->mStageInf.initGame();
	}

	gameflow.mGamePrefs.mSaveGameIndex = 0;
	gameflow.mGamePrefs.mHasSaveGame   = false;

	if (gameflow.mIsChallengeMode == FALSE) {
		Jac_SceneSetup(2, 0);
	}

	gsys->startLoading(nullptr, true, 60);

	// this does the actual hard work of setting things up.
	add(new CardSelectSetupSection());
	gsys->endLoading();
}
