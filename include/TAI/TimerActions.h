#ifndef _TAI_TIMERACTIONS_H
#define _TAI_TIMERACTIONS_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiTimerAction : public TaiAction {
	TaiTimerAction(int nextState, int timerIdx, f32 length, f32 randomRate)
	    : TaiAction(nextState)
	    , mTimerIdx(timerIdx)
	    , mTimerLength(length)
	    , mRandomRate(randomRate)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetTimer(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx;    // _08
	f32 mTimerLength; // _0C
	f32 mRandomRate;  // _10
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
	TaiTimerElapsedAction(int nextState, int p2)
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
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
