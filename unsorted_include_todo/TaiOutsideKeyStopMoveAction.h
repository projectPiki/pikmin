#ifndef _TAIOUTSIDEKEYSTOPMOVEACTION_H
#define _TAIOUTSIDEKEYSTOPMOVEACTION_H

/**
 * .obj __vt__27TaiOutsideKeyStopMoveAction, global
 * .4byte __RTTI__27TaiOutsideKeyStopMoveAction
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__27TaiOutsideKeyStopMoveActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
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
struct TaiOutsideKeyStopMoveAction : public TaiAction {
	virtual void act(Teki &);  // _10

};

#endif
