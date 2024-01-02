#ifndef _TAITARGETNEARESTCOLLISIONACTION_H
#define _TAITARGETNEARESTCOLLISIONACTION_H

/**
 * .obj __vt__31TaiTargetNearestCollisionAction, global
 * .4byte __RTTI__31TaiTargetNearestCollisionAction
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__9TaiActionFR4Teki
 * .4byte actByEvent__31TaiTargetNearestCollisionActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TaiTargetNearestCollisionAction : public TaiAction {
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
