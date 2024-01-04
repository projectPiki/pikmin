#ifndef _TAIAINSIDEOPTIONALRANGE_H
#define _TAIAINSIDEOPTIONALRANGE_H

/**
 * .obj __vt__23TAIAinsideOptionalRange, global
 * .4byte __RTTI__23TAIAinsideOptionalRange
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__22TAIAjudgeOptionalRangeFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte 0
 * .4byte 0
 * .4byte judgement__23TAIAinsideOptionalRangeFR4Teki
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

struct TAIAjudgeOptionalRange {
	virtual void _08() = 0;  // _08
	virtual void _0C() = 0;  // _0C
	virtual void act(Teki&); // _10
};

/**
 * @brief TODO
 */
struct TAIAinsideOptionalRange : public TaiAction, public TAIAjudgeOptionalRange {
	virtual void _1C() = 0;        // _1C
	virtual void _20() = 0;        // _20
	virtual void judgement(Teki&); // _24
};

#endif
