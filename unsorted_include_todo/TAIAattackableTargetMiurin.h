#ifndef _TAIAATTACKABLETARGETMIURIN_H
#define _TAIAATTACKABLETARGETMIURIN_H

/**
 * .obj __vt__26TAIAattackableTargetMiurin, weak
 * .4byte __RTTI__26TAIAattackableTargetMiurin
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__26TAIAattackableTargetMiurinFR4Teki
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

struct TAIAattackableTarget {
	virtual void _08() = 0;    // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
	virtual void _14() = 0;    // _14
	virtual void _18() = 0;    // _18
	virtual void judge(Teki&); // _1C
};

/**
 * @brief TODO
 */
struct TAIAattackableTargetMiurin : public TaiAction, public TAIAattackableTarget {
	virtual void act(Teki&); // _10
};

#endif
