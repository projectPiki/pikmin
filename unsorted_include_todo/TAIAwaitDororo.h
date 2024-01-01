#ifndef _TAIAWAITDORORO_H
#define _TAIAWAITDORORO_H

/**
 * .obj __vt__14TAIAwaitDororo, weak
 * .4byte __RTTI__14TAIAwaitDororo
 * .4byte 0
 * .4byte start__14TAIAwaitDororoFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__8TAIAwaitFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getWaitCounterMax__14TAIAwaitDororoFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAwait {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

/**
 * @brief TODO
 */
struct TAIAwaitDororo : public TaiAction, public TAIAwait {
	virtual void start(Teki &);              // _08
	virtual void getWaitCounterMax(Teki &);  // _1C

};

#endif
