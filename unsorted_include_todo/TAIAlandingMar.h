#ifndef _TAIALANDINGMAR_H
#define _TAIALANDINGMAR_H

/**
 * .obj __vt__14TAIAlandingMar, weak
 * .4byte __RTTI__14TAIAlandingMar
 * .4byte 0
 * .4byte start__11TAIAlandingFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAlandingFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte landingEffect__14TAIAlandingMarFR4Teki
 */

struct TAIAlanding {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

struct TaiAction {
	virtual void _08() = 0;              // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAlandingMar : public TAIAlanding, public TaiAction {
	virtual void landingEffect(Teki&); // _1C
};

#endif
