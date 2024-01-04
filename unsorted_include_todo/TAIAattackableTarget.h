#ifndef _TAIAATTACKABLETARGET_H
#define _TAIAATTACKABLETARGET_H

/**
 * .obj __vt__20TAIAattackableTarget, global
 * .4byte __RTTI__20TAIAattackableTarget
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__20TAIAattackableTargetFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte judge__20TAIAattackableTargetFR4Teki
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
struct TAIAattackableTarget : public TaiAction {
	virtual void act(Teki&);   // _10
	virtual void judge(Teki&); // _1C
};

#endif
