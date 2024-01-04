#ifndef _TAIFLICKINGACTION_H
#define _TAIFLICKINGACTION_H

/**
 * .obj __vt__17TaiFlickingAction, global
 * .4byte __RTTI__17TaiFlickingAction
 * .4byte 0
 * .4byte start__17TaiFlickingActionFR4Teki
 * .4byte finish__17TaiFlickingActionFR4Teki
 * .4byte act__17TaiFlickingActionFR4Teki
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
struct TaiFlickingAction : public TaiAction {
	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual void act(Teki&);    // _10
};

#endif
