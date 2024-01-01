#ifndef _TAIOTIMOTIPRESSINGACTION_H
#define _TAIOTIMOTIPRESSINGACTION_H

/**
 * .obj __vt__24TaiOtimotiPressingAction, global
 * .4byte __RTTI__24TaiOtimotiPressingAction
 * .4byte 0
 * .4byte start__24TaiOtimotiPressingActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TaiOtimotiPressingActionFR4Teki
 * .4byte actByEvent__24TaiOtimotiPressingActionFR9TekiEvent
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
struct TaiOtimotiPressingAction : public TaiAction {
	virtual void start(Teki &);            // _08
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
