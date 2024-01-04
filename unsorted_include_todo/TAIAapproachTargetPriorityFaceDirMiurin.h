#ifndef _TAIAAPPROACHTARGETPRIORITYFACEDIRMIURIN_H
#define _TAIAAPPROACHTARGETPRIORITYFACEDIRMIURIN_H

/**
 * .obj __vt__39TAIAapproachTargetPriorityFaceDirMiurin, weak
 * .4byte __RTTI__39TAIAapproachTargetPriorityFaceDirMiurin
 * .4byte 0
 * .4byte start__39TAIAapproachTargetPriorityFaceDirMiurinFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__33TAIAapproachTargetPriorityFaceDirFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getVelocity__39TAIAapproachTargetPriorityFaceDirMiurinFR4Teki
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

struct TAIAapproachTargetPriorityFaceDir {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

/**
 * @brief TODO
 */
struct TAIAapproachTargetPriorityFaceDirMiurin : public TaiAction, public TAIAapproachTargetPriorityFaceDir {
	virtual void start(Teki&);       // _08
	virtual void getVelocity(Teki&); // _1C
};

#endif
