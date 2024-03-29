#ifndef _TAISWITCHMOTIONACTION_H
#define _TAISWITCHMOTIONACTION_H

/**
 * .obj __vt__21TaiSwitchMotionAction, global
 * .4byte __RTTI__21TaiSwitchMotionAction
 * .4byte 0
 * .4byte start__21TaiSwitchMotionActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__15TaiMotionActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

struct TaiMotionAction {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

/**
 * @brief TODO
 */
struct TaiSwitchMotionAction : public TaiAction, public TaiMotionAction {
	virtual void start(Teki&); // _08
};

#endif
