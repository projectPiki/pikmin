#ifndef _TAIAFLYINGTOGOAL_H
#define _TAIAFLYINGTOGOAL_H

/**
 * .obj __vt__16TAIAflyingToGoal, global
 * .4byte __RTTI__16TAIAflyingToGoal
 * .4byte 0
 * .4byte start__16TAIAflyingToGoalFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAflyingToGoalFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte goal__16TAIAflyingToGoalFR4Teki
 * .4byte getVelocity__16TAIAflyingToGoalFR4Teki
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
struct TAIAflyingToGoal : public TaiAction {
	virtual void start(Teki &);        // _08
	virtual void act(Teki &);          // _10
	virtual void goal(Teki &);         // _1C
	virtual void getVelocity(Teki &);  // _20

};

#endif
