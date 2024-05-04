#ifndef _TAICONTINUOUSMOTIONACTION_H
#define _TAICONTINUOUSMOTIONACTION_H

#include "TaiAction.h"

/**
 * .obj __vt__25TaiContinuousMotionAction, global
 * .4byte __RTTI__25TaiContinuousMotionAction
 * .4byte 0
 * .4byte start__25TaiContinuousMotionActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__25TaiContinuousMotionActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte motionStarted__25TaiContinuousMotionActionFR4Teki
 */

/**
 * @brief TODO
 */
struct TaiContinuousMotionAction : public TaiAction {
	virtual void start(Teki&);         // _08
	virtual int act(Teki&);           // _10
	virtual void motionStarted(Teki&); // _1C
};

#endif
