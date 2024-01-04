#ifndef _TAIRANDOMWANDERINGROUTEACTION_H
#define _TAIRANDOMWANDERINGROUTEACTION_H

/**
 * .obj __vt__29TaiRandomWanderingRouteAction, global
 * .4byte __RTTI__29TaiRandomWanderingRouteAction
 * .4byte 0
 * .4byte start__29TaiRandomWanderingRouteActionFR4Teki
 * .4byte finish__29TaiRandomWanderingRouteActionFR4Teki
 * .4byte act__29TaiRandomWanderingRouteActionFR4Teki
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

struct TaiContinuousMotionAction {
	virtual void start(Teki&);         // _08
	virtual void finish(Teki&);        // _0C
	virtual void act(Teki&);           // _10
	virtual void _14() = 0;            // _14
	virtual void _18() = 0;            // _18
	virtual void motionStarted(Teki&); // _1C
};

/**
 * @brief TODO
 */
struct TaiRandomWanderingRouteAction : public TaiAction, public TaiContinuousMotionAction {
	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual void act(Teki&);    // _10
};

#endif
