#ifndef _TAIPALMDAMAGINGACTION_H
#define _TAIPALMDAMAGINGACTION_H

/**
 * .obj __vt__21TaiPalmDamagingAction, global
 * .4byte __RTTI__21TaiPalmDamagingAction
 * .4byte 0
 * .4byte start__21TaiPalmDamagingActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TaiDamagingActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TaiDamagingAction {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

/**
 * @brief TODO
 */
struct TaiPalmDamagingAction : public TaiAction, public TaiDamagingAction {
	virtual void start(Teki &);  // _08

};

#endif
