#ifndef _TAI_MESSAGEACTIONS_H
#define _TAI_MESSAGEACTIONS_H

#include "TAI/Action.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TaiKeySendMessageAction : public TaiAction {
	TaiKeySendMessageAction(int msg, int animKeyOpt)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mMessage    = msg;
		mAnimKeyOpt = animKeyOpt;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMessage;    // _08
	int mAnimKeyOpt; // _0C
};

/**
 * @brief TODO
 */
struct TaiSendMessageAction : public TaiAction {
	inline TaiSendMessageAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMessage; // _08
};

#endif
