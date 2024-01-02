#ifndef _TAIAAPPROACHTARGETPRIORITYFACEDIR_H
#define _TAIAAPPROACHTARGETPRIORITYFACEDIR_H

/**
 * .obj __vt__33TAIAapproachTargetPriorityFaceDir, global
 * .4byte __RTTI__33TAIAapproachTargetPriorityFaceDir
 * .4byte 0
 * .4byte start__33TAIAapproachTargetPriorityFaceDirFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__33TAIAapproachTargetPriorityFaceDirFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getVelocity__33TAIAapproachTargetPriorityFaceDirFR4Teki
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
struct TAIAapproachTargetPriorityFaceDir : public TaiAction {
	virtual void start(Teki &);        // _08
	virtual void act(Teki &);          // _10
	virtual void getVelocity(Teki &);  // _1C

};

#endif
