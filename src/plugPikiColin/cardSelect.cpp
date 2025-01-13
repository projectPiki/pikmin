#include "CardSelectSection.h"
#include "zen/ogFileChkSel.h"
#include "jaudio/PikiScene.h"
#include "FlowController.h"
#include "PlayerState.h"
#include "MemoryCard.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "gameflow.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "BaseInf.h"
#include "Section.h"
#include "sysNew.h"
#include "types.h"

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
DEFINE_PRINT("CardSelect")

// WARNING: DO NOT INCLUDE THIS IN ANY FILES ASIDE FROM CARDSELECT.CPP
static zen::ogScrFileChkSelMgr* memcardWindow;

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct CardSelectSetupSection : public Node {
	inline CardSelectSetupSection()
	{
		setName("CardSelect section");
		mJacSetupCountdown = 5;
		mController        = new Controller();
		mFadeState         = 0;

		memcardWindow = nullptr;
		memcardWindow = new zen::ogScrFileChkSelMgr();
		memcardWindow->start(gameflow.mIsChallengeMode);

		gsys->setFade(1.0f, 3.0f);
		mNextSectionID = 0;
	}

	virtual void update() // _10 (weak)
	{
		mController->update();
		if (!memcardWindow && mFadeState == 0) {
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
			mFadeState = -1;
			if (mNextSectionID) {
				gameflow.mNextOnePlayerSectionID = mNextSectionID >> 16;
			} else {
				if (!gameflow.mIsChallengeMode) {
					PRINT("NORMAL MODE!!!\n");

					gameflow.mWorldClock.mCurrentDay = 1;
					if (gameflow.mGamePrefs.mHasSaveGame) {
						gameflow.mMemoryCard.loadCurrentGame();
						if (gameflow.mPlayState._20 == 1) {
							gameflow.mPlayState.reset();
							gameflow.mPlayState._20 = 2;
						}

						gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;

					} else {
						PRINT("NO SAVE GAMES!\n");
						gameflow.mPlayState.reset();
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_IntroGame;
					}

					if (playerState->isTutorial()) {
						StageInfo* stage       = flowCont.mRootInfo.getChild();
						flowCont.mCurrentStage = stage;
						sprintf(flowCont.mStagePath1, "%s", stage->mFileName);
						sprintf(flowCont.mStagePath2, "%s", stage->mFileName);
						gameflow.mWorldClock.setTime(14.8f);
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_IntroGame;
					}
				} else {
					PRINT("CHALLENGE MODE!!!\n");
					gameflow.mPlayState.reset();
					if (gameflow.mIsChallengeMode) {
						playerState->setChallengeMode();
					}
					gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;
				}

				gameflow._1CC                 = -1;
				gameflow.mLastUnlockedStageId = -1;
			}

#ifdef __MWERKS__
			Jac_SceneExit(13, 0);
#endif
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

		if (!memcardWindow) {
			return;
		}

		CardQuickInfo card;
		int returnCode = memcardWindow->update(mController, card);
		if (returnCode >= 1) {
			PRINT("got return code .... %d\n", returnCode);

			memcardWindow = nullptr;
			if (returnCode == 1) {
				mNextSectionID = ONEPLAYER_GameExit << 16;
				mFadeState     = 1;
				gsys->setFade(0.0f, 3.0f);
			} else if (returnCode == 5) {
				mNextSectionID = ONEPLAYER_GameSetup;
				mFadeState     = 1;
				gsys->setFade(0.0f, 3.0f);
			} else {
				gameflow.mGamePrefs.mHasSaveGame = 1;
				gameflow.mSaveGameCrc            = card.mCrc;
				gameflow.mGamePrefs._108         = returnCode - 2;
				PRINT("got index = %d\n", card.mIndex);
				gameflow.mGamePrefs.mSaveGameIndex = card.mIndex + 1;
				PRINT("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				PRINT("using save game file %d (crc = %08x) with %d as the spare\n", gameflow.mGamePrefs.mSaveGameIndex,
				      gameflow.mSaveGameCrc, gameflow.mGamePrefs.mSpareSaveGames);
				gameflow.mWorldClock.mCurrentDay = card._0C;
				mFadeState                       = 1;
				gsys->setFade(0.0f, 3.0f);
			}
		}

		if (memcardWindow) {
			memcardWindow->draw(gfx);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 mFadeState;          // _20, unknown
	u32 mNextSectionID;      // _24, unknown
	u8 _28[0x30 - 0x28];     // _28, unknown
	Controller* mController; // _30
	int mJacSetupCountdown;  // _34
};

/*
 * --INFO--
 * Address:	8005503C
 * Size:	00023C
 */
CardSelectSection::CardSelectSection()
{
	Node::init("<CardSelectSection>");
	gsys->setFrameClamp(1);
	flowCont.mCurrentStage = nullptr;
	playerState->initGame();
	generatorCache->initGame();
	pikiInfMgr.initGame();
	FOREACH_NODE(StageInfo, flowCont.mRootInfo.mChild, stage)
	{
		stage->_20 = 0;
		stage->mStageInf.initGame();
	}

	gameflow.mGamePrefs.mSaveGameIndex = 0;
	gameflow.mGamePrefs.mHasSaveGame   = 0;

	if (gameflow.mIsChallengeMode == 0) {
		Jac_SceneSetup(2, 0);
	}

	gsys->startLoading(nullptr, true, 60);
	add(new CardSelectSetupSection());
	gsys->endLoading();
}
