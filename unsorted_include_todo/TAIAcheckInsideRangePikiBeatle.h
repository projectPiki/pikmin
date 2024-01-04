#ifndef _TAIACHECKINSIDERANGEPIKIBEATLE_H
#define _TAIACHECKINSIDERANGEPIKIBEATLE_H

/**
 * .obj __vt__30TAIAcheckInsideRangePikiBeatle, weak
 * .4byte __RTTI__30TAIAcheckInsideRangePikiBeatle
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TAIAcheckInsideRangePikiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPikiMax__24TAIAcheckInsideRangePikiFR4Teki
 * .4byte getRange__30TAIAcheckInsideRangePikiBeatleFR4Teki
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

struct TAIAcheckInsideRangePiki {
	virtual void _08() = 0;         // _08
	virtual void _0C() = 0;         // _0C
	virtual void act(Teki&);        // _10
	virtual void _14() = 0;         // _14
	virtual void _18() = 0;         // _18
	virtual void getPikiMax(Teki&); // _1C
};

/**
 * @brief TODO
 */
struct TAIAcheckInsideRangePikiBeatle : public TaiAction, public TAIAcheckInsideRangePiki {
	virtual void getRange(Teki&); // _20
};

#endif
