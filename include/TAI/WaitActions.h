#ifndef _TAI_WAITACTIONS_H
#define _TAI_WAITACTIONS_H

#include "TAI/MotionActions.h"
#include "types.h"

/**
 * @brief TODO
 */
struct TaiWaitTurningAction : public TaiMotionAction {
	TaiWaitTurningAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TaiMotionAction
};

#endif
