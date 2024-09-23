#ifndef _TAI_WAITACTIONS_H
#define _TAI_WAITACTIONS_H

#include "types.h"
#include "TAI/MotionActions.h"

/**
 * @brief TODO
 */
struct TaiWaitTurningAction : public TaiMotionAction {
	inline TaiWaitTurningAction() // TODO: this is a guess
	    : TaiMotionAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

#endif
