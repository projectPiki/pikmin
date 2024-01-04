#ifndef _TAIAGOGOALPATHDORORO_H
#define _TAIAGOGOALPATHDORORO_H

/**
 * .obj __vt__20TAIAgoGoalPathDororo, weak
 * .4byte __RTTI__20TAIAgoGoalPathDororo
 * .4byte 0
 * .4byte start__14TAIAgoGoalPathFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAgoGoalPathFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte checkArrival__14TAIAgoGoalPathFR4Teki
 * .4byte getWalkVelocity__20TAIAgoGoalPathDororoFR4Teki
 */

struct TAIAgoGoalPath {
	virtual void start(Teki&);        // _08
	virtual void _0C() = 0;           // _0C
	virtual void act(Teki&);          // _10
	virtual void _14() = 0;           // _14
	virtual void _18() = 0;           // _18
	virtual void checkArrival(Teki&); // _1C
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
struct TAIAgoGoalPathDororo : public TAIAgoGoalPath, public TaiAction {
	virtual void getWalkVelocity(Teki&); // _20
};

#endif
