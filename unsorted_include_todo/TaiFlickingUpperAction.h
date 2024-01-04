#ifndef _TAIFLICKINGUPPERACTION_H
#define _TAIFLICKINGUPPERACTION_H

/**
 * .obj __vt__22TaiFlickingUpperAction, global
 * .4byte __RTTI__22TaiFlickingUpperAction
 * .4byte 0
 * .4byte start__15TaiMotionActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__22TaiFlickingUpperActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiMotionAction {
	virtual void start(Teki&); // _08
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
struct TaiFlickingUpperAction : public TaiMotionAction, public TaiAction {
	virtual void act(Teki&); // _10
};

#endif
