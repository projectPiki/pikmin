#ifndef _TAISTOPPINGMOVEACTION_H
#define _TAISTOPPINGMOVEACTION_H

/**
 * .obj __vt__21TaiStoppingMoveAction, global
 * .4byte __RTTI__21TaiStoppingMoveAction
 * .4byte 0
 * .4byte start__21TaiStoppingMoveActionFR4Teki
 * .4byte finish__21TaiStoppingMoveActionFR4Teki
 * .4byte act__21TaiStoppingMoveActionFR4Teki
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
struct TaiStoppingMoveAction : public TaiAction {
	virtual void start(Teki &);  // _08
	virtual void finish(Teki &); // _0C
	virtual void act(Teki &);    // _10

};

#endif
