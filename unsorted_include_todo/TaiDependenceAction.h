#ifndef _TAIDEPENDENCEACTION_H
#define _TAIDEPENDENCEACTION_H

/**
 * .obj __vt__19TaiDependenceAction, weak
 * .4byte __RTTI__19TaiDependenceAction
 * .4byte 0
 * .4byte start__19TaiDependenceActionFR4Teki
 * .4byte finish__19TaiDependenceActionFR4Teki
 * .4byte act__19TaiDependenceActionFR4Teki
 * .4byte actByEvent__19TaiDependenceActionFR9TekiEvent
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
struct TaiDependenceAction : public TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
};

#endif
