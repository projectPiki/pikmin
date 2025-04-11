#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include "Section.h"
#include "GameCoreSection.h"
#include "gameflow.h"
#include "PlayerState.h"
#include "MoviePlayer.h"
#include "FlowController.h"
#include "zen/DrawGameInfo.h"
#include "types.h"

struct Graphics;
struct Controller;

extern GameCoreSection* gamecore;

/**
 * @brief TODO
 */
struct ModeState {
	ModeState(BaseGameSection* game)
	    : mSection(game)
	{
	}

	BaseGameSection* mSection; // _00

	virtual ModeState* update(u32&);    // _08
	virtual void postRender(Graphics&); // _0C
	virtual void postUpdate();          // _10

	// _04 = VTBL
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

	virtual ModeState* update(u32&);    // _08
	virtual void postRender(Graphics&); // _0C

	void makeTotalScoreWindow();
	ModeState* initialisePhaseOne();
	ModeState* initialisePhaseTwo();
	ModeState* initialisePhaseThree();
	ModeState* initialisePhaseFour();

	// _00     = VTBL?
	// _00-_04 = ModeState?
	int _08; // _08
};

/**
 * @brief TODO
 */
struct IntroModeState : public ModeState {
	IntroModeState(BaseGameSection* c)
	    : ModeState(c)
	{
		mController = c->mController;
	}

	virtual ModeState* update(u32&);    // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL
	// _00-_04 = ModeState
	Controller* mController; // _08
};

/**
 * @brief TODO
 */
struct IntroGameModeState : public ModeState {
	IntroGameModeState(BaseGameSection* c)
	    : ModeState(c)
	{
		_08 = c->mController;
	}

	virtual ModeState* update(u32&);    // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
	Controller* _08;
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

	virtual ModeState* update(u32&);    // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	f32 _08; // _08
	int _0C; // _0C
	f32 _10; // _10
};

/**
 * @brief TODO
 */
struct QuittingModeState : public ModeState {
	QuittingModeState(BaseGameSection* c)
	    : ModeState(c)
	{
	}

	virtual ModeState* update(u32&); // _08
	virtual void postUpdate();       // _10

	// _00     = VTBL?
	// _00-_04 = ModeState?
};

/**
 * @brief TODO
 */
struct QuittingGameModeState : public ModeState {
	QuittingGameModeState(BaseGameSection* c)
	    : ModeState(c)
	{
	}

	virtual ModeState* update(u32&); // _08
	virtual void postUpdate();       // _10

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct RunningModeState : public ModeState {
	RunningModeState(BaseGameSection* c)
	    : ModeState(c)
	{
	}

	virtual ModeState* update(u32&);    // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: member
	u8 _08;                  // _08
	Controller* mController; // _0C
};

#endif
