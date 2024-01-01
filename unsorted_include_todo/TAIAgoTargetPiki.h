#ifndef _TAIAGOTARGETPIKI_H
#define _TAIAGOTARGETPIKI_H

/**
 * .obj __vt__16TAIAgoTargetPiki, weak
 * .4byte __RTTI__16TAIAgoTargetPiki
 * .4byte 0
 * .4byte start__27TAIAgoTargetPriorityFaceDirFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAgoTargetPikiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte checkArrival__16TAIAgoTargetPikiFR4Teki
 * .4byte getWalkVelocity__27TAIAgoTargetPriorityFaceDirFR4Teki
*/

struct TAIAgoTargetPriorityFaceDir {
	virtual void start(Teki &);            // _08
	virtual void _0C() = 0;                // _0C
	virtual void act(Teki &);              // _10
	virtual void _14() = 0;                // _14
	virtual void _18() = 0;                // _18
	virtual void checkArrival(Teki &);     // _1C
	virtual void getWalkVelocity(Teki &);  // _20
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAgoTargetPiki : public TAIAgoTargetPriorityFaceDir, public TaiAction {
	virtual void act(Teki &);           // _10
	virtual void checkArrival(Teki &);  // _1C

};

#endif
