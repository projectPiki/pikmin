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
	TaiResetTimerAction(int timerIdx, f32 length, f32 randomRate)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mTimerIdx    = timerIdx;
		mTimerLength = length;
		mRandomRate  = randomRate;
	}

	virtual void start(Teki&); // _08

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
struct TaiTimerElapsedAction : public TaiAction {
	TaiTimerElapsedAction(int nextState, int timerIdx)
	    : TaiAction(nextState)
	{
		mTimerIdx = timerIdx;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx; // _08
};

/**
 * @brief TODO
 */
struct TaiStartingTimerAction : public TaiTimerAction {
	TaiStartingTimerAction(int nextState, int timerIdx, f32 length, f32 randomRate, f32 chance)
	    : TaiTimerAction(nextState, timerIdx, length, randomRate)
	{
		mChance = chance;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_14 = TaiTimerAction
	f32 mChance; // _14
};

#endif
