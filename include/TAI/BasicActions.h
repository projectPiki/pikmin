#ifndef _TAI_BASICACTIONS_H
#define _TAI_BASICACTIONS_H

#include "TAI/Action.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TaiActionStateAction : public TaiAction {
	TaiActionStateAction(int nextState, int actionState)
	    : TaiAction(nextState)
	{
		mActionState = actionState;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mActionState; // _08
};

/**
 * @brief TODO
 */
struct TaiSetOptionAction : public TaiAction {
	TaiSetOptionAction(int option, bool doSet)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mOpt   = option;
		mDoSet = doSet;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mOpt;    // _08
	bool mDoSet; // _0C, true=set opt, false=clear opt
};

/**
 * @brief TODO
 */
struct TaiPlaySoundAction : public TaiAction {
	TaiPlaySoundAction(int soundID)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mSoundID = soundID;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mSoundID; // _08
};

/**
 * @brief TODO
 */
struct TaiStopSoundAction : public TaiAction {
	TaiStopSoundAction(int soundID)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mSoundID = soundID;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mSoundID; // _08
};

/**
 * @brief TODO
 */
struct TaiTypeNaviWatchResultOnAction : public TaiAction {
	TaiTypeNaviWatchResultOnAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiNaviWatchResultOnAction : public TaiAction {
	inline TaiNaviWatchResultOnAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mResultFlag; // _08
};

#endif
