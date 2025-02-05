#ifndef _TAI_TIMERACTIONS_H
#define _TAI_TIMERACTIONS_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiTimerAction : public TaiAction {
	TaiTimerAction(int nextState, int p2, f32 p3, f32 p4)
	    : TaiAction(nextState)
	    , _08(p2)
	    , _0C(p3)
	    , _10(p4)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetTimer(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
	f32 _0C; // _0C
	f32 _10; // _10
};

/**
 * @brief TODO
 */
struct TaiResetTimerAction : public TaiAction {
	inline TaiResetTimerAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	void resetTimer(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiTimerElapsedAction : public TaiAction {
	inline TaiTimerElapsedAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiStartingTimerAction : public TaiTimerAction {
	inline TaiStartingTimerAction() // TODO: this is a guess
	    : TaiTimerAction(0, 0, 0.0f, 0.0f)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiTimerAction?
	// TODO: members
};

#endif
