#ifndef _TAIMIZINKOCRYTIMERACTION_H
#define _TAIMIZINKOCRYTIMERACTION_H

/**
 * .obj __vt__24TaiMizinkoCryTimerAction, global
 * .4byte __RTTI__24TaiMizinkoCryTimerAction
 * .4byte 0
 * .4byte start__14TaiTimerActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TaiMizinkoCryTimerActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiTimerAction {
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
struct TaiMizinkoCryTimerAction : public TaiTimerAction, public TaiAction {
	virtual void act(Teki&); // _10
};

#endif
