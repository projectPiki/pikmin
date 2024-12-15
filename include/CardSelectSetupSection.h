#ifndef _CARDSELECTSETUPSECTION_H
#define _CARDSELECTSETUPSECTION_H

#include "types.h"
#include "Section.h"
#include "zen/ogFileChkSel.h"
#include "FlowController.h"
#include "sysNew.h"
#include "gameflow.h"
#include "jaudio/PikiScene.h"
#include "MemoryCard.h"
#include "PlayerState.h"
#include "Graphics.h"

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
		_34         = 5;
		mController = new Controller();
		_20         = 0;

		memcardWindow = nullptr;
		memcardWindow = new zen::ogScrFileChkSelMgr();

		memcardWindow->start(gameflow._2B4);

		gsys->setFade(1.0f, 3.0f);
		_24 = 0;
	}

	virtual void update() // _10 (weak)
	{
		u32 badCompiler[4]; // i tried, there are still more inlines somewhere

		mController->update();
		if (!memcardWindow && _20 == 0) {
			_20 = 1;
			gsys->setFade(0.0f, 3.0f);
		}

		if (memcardWindow && gameflow._2B4 && _34 != 0) {
			_34--;
			if (_34 == 0) {
				Jac_SceneSetup(2, 0);
			}
		}

		if (_20 == 1 && gsys->mCurrentFade == 0.0f) {
			_20 = -1;
			if (_24) {
				gameflow.mNextOnePlayerSectionID = _24 >> 16;
			} else {
				if (gameflow._2B4 == 0) {
					gameflow.mWorldClock._24 = 1;
					if (gameflow.mGamePrefs._1E) {
						gameflow.mMemoryCard.loadCurrentGame();
						if (gameflow.mPlayState._20 == 1) {
							gameflow.mPlayState.reset();
							gameflow.mPlayState._20 = 2;
						}
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;

					} else {
						gameflow.mPlayState.reset();
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_IntroGame;
					}

					if (playerState->isTutorial()) {
						StageInfo* stage = flowCont.mRootInfo.getChild();
						flowCont._A8     = stage;
						sprintf(flowCont._130, "%s", stage->mFileName);
						sprintf(flowCont._1B0, "%s", stage->mFileName);
						gameflow.mWorldClock.setTime(14.8f);
						gameflow.mNextOnePlayerSectionID = ONEPLAYER_IntroGame;
					}
				} else {
					gameflow.mPlayState.reset();
					if (gameflow._2B4) {
						playerState->setChallengeMode();
					}
					gameflow.mNextOnePlayerSectionID = ONEPLAYER_MapSelect;
				}

				gameflow._1CC = -1;
				gameflow._1D0 = -1;
			}
			Jac_SceneExit(13, 0);
			gsys->mPending = true;
		}
	}
	virtual void draw(Graphics& gfx) // _14 (weak)
	{
		gfx.setViewport(RectArea(0, 0, gfx._30C, gfx._310));
		gfx.setScissor(RectArea(0, 0, gfx._30C, gfx._310));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, false);

		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx._30C, gfx._310));

		if (!memcardWindow) {
			return;
		}

		CardQuickInfo card;
		int windowStatus = memcardWindow->update(mController, card);
		if (windowStatus >= 1) {
			memcardWindow = nullptr;
			if (windowStatus == 1) {
				_24 = 0xB0000;
				_20 = 1;
				gsys->setFade(0.0f, 3.0f);

			} else if (windowStatus == 5) {
				_24 = 0;
				_20 = 1;
				gsys->setFade(0.0f, 3.0f);
			} else {
				gameflow.mGamePrefs._1E  = 1;
				gameflow._1A0            = card._24;
				gameflow.mGamePrefs._108 = windowStatus - 2;
				gameflow.mGamePrefs._20  = card._00 + 1;
				gameflow.mWorldClock._24 = card._0C;
				_20                      = 1;
				gsys->setFade(0.0f, 3.0f);
			}
		}

		if (memcardWindow) {
			memcardWindow->draw(gfx);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20;                 // _20, unknown
	u32 _24;                 // _24, unknown
	u8 _28[0x30 - 0x28];     // _28, unknown
	Controller* mController; // _30
	int _34;                 // _34
};

#endif
