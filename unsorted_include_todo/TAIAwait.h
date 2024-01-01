#ifndef _TAIAWAIT_H
#define _TAIAWAIT_H

/**
 * .obj __vt__8TAIAwait, global
 * .4byte __RTTI__8TAIAwait
 * .4byte 0
 * .4byte start__8TAIAwaitFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__8TAIAwaitFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getWaitCounterMax__8TAIAwaitFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAwait : public TaiAction {
	virtual void start(Teki &);              // _08
	virtual void act(Teki &);                // _10
	virtual void getWaitCounterMax(Teki &);  // _1C

};

#endif
