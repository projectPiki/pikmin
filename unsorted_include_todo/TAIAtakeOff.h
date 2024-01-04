#ifndef _TAIATAKEOFF_H
#define _TAIATAKEOFF_H

/**
 * .obj __vt__11TAIAtakeOff, global
 * .4byte __RTTI__11TAIAtakeOff
 * .4byte 0
 * .4byte start__11TAIAtakeOffFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAtakeOffFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte startFlying__11TAIAtakeOffFR4Teki
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
struct TAIAtakeOff : public TaiAction {
	virtual void start(Teki&);       // _08
	virtual void act(Teki&);         // _10
	virtual void startFlying(Teki&); // _1C
};

#endif
