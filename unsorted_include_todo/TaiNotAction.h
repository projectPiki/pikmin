#ifndef _TAINOTACTION_H
#define _TAINOTACTION_H

/**
 * .obj __vt__12TaiNotAction, weak
 * .4byte __RTTI__12TaiNotAction
 * .4byte 0
 * .4byte start__12TaiNotActionFR4Teki
 * .4byte finish__12TaiNotActionFR4Teki
 * .4byte act__12TaiNotActionFR4Teki
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
struct TaiNotAction : public TaiAction {
	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual void act(Teki&);    // _10
};

#endif
