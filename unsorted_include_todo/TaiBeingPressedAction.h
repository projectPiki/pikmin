#ifndef _TAIBEINGPRESSEDACTION_H
#define _TAIBEINGPRESSEDACTION_H

/**
 * .obj __vt__21TaiBeingPressedAction, global
 * .4byte __RTTI__21TaiBeingPressedAction
 * .4byte 0
 * .4byte start__21TaiBeingPressedActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__9TaiActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TaiBeingPressedAction : public TaiAction {
	virtual void start(Teki&); // _08
};

#endif
