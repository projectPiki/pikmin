#ifndef _TAICONTINUOUSMOTIONACTION_H
#define _TAICONTINUOUSMOTIONACTION_H

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

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TaiContinuousMotionAction : public TaiAction {
	virtual void start(Teki&);         // _08
	virtual void act(Teki&);           // _10
	virtual void motionStarted(Teki&); // _1C
};

#endif
