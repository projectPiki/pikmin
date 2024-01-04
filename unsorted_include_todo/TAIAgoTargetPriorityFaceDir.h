#ifndef _TAIAGOTARGETPRIORITYFACEDIR_H
#define _TAIAGOTARGETPRIORITYFACEDIR_H

/**
 * .obj __vt__27TAIAgoTargetPriorityFaceDir, global
 * .4byte __RTTI__27TAIAgoTargetPriorityFaceDir
 * .4byte 0
 * .4byte start__27TAIAgoTargetPriorityFaceDirFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__27TAIAgoTargetPriorityFaceDirFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte checkArrival__27TAIAgoTargetPriorityFaceDirFR4Teki
 * .4byte getWalkVelocity__27TAIAgoTargetPriorityFaceDirFR4Teki
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
struct TAIAgoTargetPriorityFaceDir : public TaiAction {
	virtual void start(Teki&);           // _08
	virtual void act(Teki&);             // _10
	virtual void checkArrival(Teki&);    // _1C
	virtual void getWalkVelocity(Teki&); // _20
};

#endif
