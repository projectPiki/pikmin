#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include "FlowController.h"
#include "GameCoreSection.h"
#include "MoviePlayer.h"
#include "PlayerState.h"
#include "Section.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "types.h"
#include "zen/DrawGameInfo.h"

struct Graphics;
struct Controller;

extern GameCoreSection* gamecore;

/**
 * @brief Flags controlling which game components are updated in a given frame.
 * @details This enum is used for the 'result' parameter in ModeState::update
 * and for the mUpdateFlags member in BaseGameSection.
 */
enum ModeUpdateFlags {
	UPDATE_NONE        = 0,                                                 // 0, No updates
	UPDATE_AI          = 1 << 0,                                            // 1, Update AI logic
	UPDATE_WORLD_CLOCK = 1 << 1,                                            // 2, Update the world clock and time-of-day
	UPDATE_COUNTDOWN   = 1 << 2,                                            // 4, Update the end-of-day countdown
	UPDATE_ALL         = UPDATE_AI | UPDATE_WORLD_CLOCK | UPDATE_COUNTDOWN, // 7, Update all components
};

/**
 * @brief TODO
 */
struct ModeState {
	ModeState(BaseGameSection* game)
	    : mSection(game)
	{
	}

	BaseGameSection* mSection; // _00

	virtual ModeState* update(u32& result) { result = UPDATE_AI | UPDATE_WORLD_CLOCK; } // _08
	virtual void postRender(Graphics&) { }                                              // _0C
	virtual void postUpdate() { }                                                       // _10

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

	virtual ModeState* update(u32& result); // _08
	virtual void postRender(Graphics&);     // _0C

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

	virtual void postRender(Graphics&);     // _0C
	virtual ModeState* update(u32& result); // _08

	// _00     = VTBL?
	// _00-_04 = ModeState?
	u8 mCachedPauseFlag;     // _08
	Controller* mController; // _0C
};

#endif
