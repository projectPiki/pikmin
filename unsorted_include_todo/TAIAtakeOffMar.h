#ifndef _TAIATAKEOFFMAR_H
#define _TAIATAKEOFFMAR_H

/**
 * .obj __vt__14TAIAtakeOffMar, weak
 * .4byte __RTTI__14TAIAtakeOffMar
 * .4byte 0
 * .4byte start__11TAIAtakeOffFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAtakeOffFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte startFlying__14TAIAtakeOffMarFR4Teki
 */

struct TAIAtakeOff {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

struct TaiAction {
	virtual void _08() = 0;              // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAtakeOffMar : public TAIAtakeOff, public TaiAction {
	virtual void startFlying(Teki&); // _1C
};

#endif
