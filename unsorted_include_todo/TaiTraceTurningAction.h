#ifndef _TAITRACETURNINGACTION_H
#define _TAITRACETURNINGACTION_H

/**
 * .obj __vt__21TaiTraceTurningAction, global
 * .4byte __RTTI__21TaiTraceTurningAction
 * .4byte 0
 * .4byte start__25TaiContinuousMotionActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__21TaiTraceTurningActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte motionStarted__25TaiContinuousMotionActionFR4Teki
 */

struct TaiContinuousMotionAction {
	virtual void start(Teki&);         // _08
	virtual void _0C() = 0;            // _0C
	virtual void act(Teki&);           // _10
	virtual void _14() = 0;            // _14
	virtual void _18() = 0;            // _18
	virtual void motionStarted(Teki&); // _1C
};

struct TaiAction {
	virtual void _08() = 0;              // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TaiTraceTurningAction : public TaiContinuousMotionAction, public TaiAction {
	virtual void act(Teki&); // _10
};

#endif
