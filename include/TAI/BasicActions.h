#ifndef _TAI_BASICACTIONS_H
#define _TAI_BASICACTIONS_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiActionStateAction : public TaiAction {
	inline TaiActionStateAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mStateID; // _08
};

/**
 * @brief TODO
 */
struct TaiSetOptionAction : public TaiAction {
	TaiSetOptionAction(int option, bool doSet)
	    : TaiAction(-1)
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
	inline TaiPlaySoundAction() // TODO: this is a guess
	    : TaiAction(0)
	{
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
	inline TaiStopSoundAction() // TODO: this is a guess
	    : TaiAction(0)
	{
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
	inline TaiTypeNaviWatchResultOnAction() // TODO: this is a guess
	    : TaiAction(-1)
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
