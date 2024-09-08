#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include "types.h"

struct Graphics;

/**
 * @brief TODO
 */
struct ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C
	virtual void postUpdate();          // _10

	// _00 = VTBL?
	// TODO: members?
};

/**
 * @brief TODO
 */
struct DayOverModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C

	void makeTotalScoreWindow();
	void initialisePhaseOne();
	void initialisePhaseTwo();
	void initialisePhaseThree();
	void initialisePhaseFour();

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct IntroModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct IntroGameModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct MessageModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct QuittingModeState : public ModeState {
	virtual void update(u32&); // _08
	virtual void postUpdate(); // _10

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct QuittingGameModeState : public ModeState {
	virtual void update(u32&); // _08
	virtual void postUpdate(); // _10

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

/**
 * @brief TODO
 */
struct RunningModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C

	// _00     = VTBL?
	// _00-_04 = ModeState?
	// TODO: members
};

#endif
