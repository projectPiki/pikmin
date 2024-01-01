#ifndef _TAIOTIMOTIATTACKINGACTION_H
#define _TAIOTIMOTIATTACKINGACTION_H

/**
 * .obj __vt__25TaiOtimotiAttackingAction, global
 * .4byte __RTTI__25TaiOtimotiAttackingAction
 * .4byte 0
 * .4byte start__25TaiOtimotiAttackingActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__25TaiOtimotiAttackingActionFR4Teki
 * .4byte actByEvent__25TaiOtimotiAttackingActionFR9TekiEvent
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
struct TaiOtimotiAttackingAction : public TaiAction {
	virtual void start(Teki &);            // _08
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
