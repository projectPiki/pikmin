#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include "Section.h"
#include "GameCoreSection.h"
#include "gameflow.h"
#include "PlayerState.h"
#include "MoviePlayer.h"
#include "FlowController.h"
#include "jaudio/PikiScene.h"
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

	virtual ModeState* update(u32& p1) { p1 = 3; } // _08
	virtual void postRender(Graphics&) { }         // _0C
	virtual void postUpdate() { }                  // _10

	// _04 = VTBL
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

	// _00     = VTBL
	// _00-_04 = ModeState
	Controller* _08; // _08
};

/**
 * @brief TODO
 */
struct RunningModeState : public ModeState {
	RunningModeState(BaseGameSection* c)
	    : ModeState(c)
	{
		mCachedPauseFlag = 0;
		mController      = c->mController;
	}

	virtual void postRender(Graphics&); // _0C
	virtual ModeState* update(u32&);    // _08

	// _00     = VTBL?
	// _00-_04 = ModeState?
	u8 mCachedPauseFlag;     // _08
	Controller* mController; // _0C
};

#endif
