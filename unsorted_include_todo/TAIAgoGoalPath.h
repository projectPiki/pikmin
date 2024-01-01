#ifndef _TAIAGOGOALPATH_H
#define _TAIAGOGOALPATH_H

/**
 * .obj __vt__14TAIAgoGoalPath, global
 * .4byte __RTTI__14TAIAgoGoalPath
 * .4byte 0
 * .4byte start__14TAIAgoGoalPathFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAgoGoalPathFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte checkArrival__14TAIAgoGoalPathFR4Teki
 * .4byte getWalkVelocity__27TAIAgoTargetPriorityFaceDirFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAgoTargetPriorityFaceDir {
	virtual void start(Teki &);            // _08
	virtual void _0C() = 0;                // _0C
	virtual void act(Teki &);              // _10
	virtual void _14() = 0;                // _14
	virtual void _18() = 0;                // _18
	virtual void checkArrival(Teki &);     // _1C
	virtual void getWalkVelocity(Teki &);  // _20
};

/**
 * @brief TODO
 */
struct TAIAgoGoalPath : public TaiAction, public TAIAgoTargetPriorityFaceDir {
	virtual void start(Teki &);         // _08
	virtual void act(Teki &);           // _10
	virtual void checkArrival(Teki &);  // _1C

};

#endif
