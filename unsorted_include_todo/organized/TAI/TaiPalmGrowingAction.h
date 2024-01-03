#ifndef _TAIPALMGROWINGACTION_H
#define _TAIPALMGROWINGACTION_H

/**
 * .obj __vt__20TaiPalmGrowingAction, global
 * .4byte __RTTI__20TaiPalmGrowingAction
 * .4byte 0
 * .4byte start__20TaiPalmGrowingActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__9TaiActionFR4Teki
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
struct TaiPalmGrowingAction : public TaiAction {
	virtual void start(Teki &);  // _08

};

#endif
