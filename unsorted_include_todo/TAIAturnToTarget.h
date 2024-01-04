#ifndef _TAIATURNTOTARGET_H
#define _TAIATURNTOTARGET_H

/**
 * .obj __vt__16TAIAturnToTarget, global
 * .4byte __RTTI__16TAIAturnToTarget
 * .4byte 0
 * .4byte start__16TAIAturnToTargetFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAturnToTargetFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getTurnVelocity__16TAIAturnToTargetFR4Teki
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
struct TAIAturnToTarget : public TaiAction {
	virtual void start(Teki&);           // _08
	virtual void act(Teki&);             // _10
	virtual void getTurnVelocity(Teki&); // _1C
};

#endif
