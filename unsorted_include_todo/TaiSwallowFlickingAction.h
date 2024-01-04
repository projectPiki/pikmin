#ifndef _TAISWALLOWFLICKINGACTION_H
#define _TAISWALLOWFLICKINGACTION_H

/**
 * .obj __vt__24TaiSwallowFlickingAction, global
 * .4byte __RTTI__24TaiSwallowFlickingAction
 * .4byte 0
 * .4byte start__24TaiSwallowFlickingActionFR4Teki
 * .4byte finish__24TaiSwallowFlickingActionFR4Teki
 * .4byte act__24TaiSwallowFlickingActionFR4Teki
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
struct TaiSwallowFlickingAction : public TaiAction {
	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual void act(Teki&);    // _10
};

#endif
