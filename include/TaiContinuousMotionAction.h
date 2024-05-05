#ifndef _TAICONTINUOUSMOTIONACTION_H
#define _TAICONTINUOUSMOTIONACTION_H

#include "TaiAction.h"

/**
 * @brief TODO
 */
struct TaiContinuousMotionAction : public TaiAction {
	virtual void start(Teki&);         // _08
	virtual bool act(Teki&);           // _10
	virtual void motionStarted(Teki&); // _1C

	// _04 = VTBL
	// _00-_08 = TaiAction
};

#endif
