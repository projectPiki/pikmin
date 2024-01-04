#ifndef _TAIAJUDGEOPTIONALRANGE_H
#define _TAIAJUDGEOPTIONALRANGE_H

/**
 * .obj __vt__22TAIAjudgeOptionalRange, global
 * .4byte __RTTI__22TAIAjudgeOptionalRange
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__22TAIAjudgeOptionalRangeFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte 0
 * .4byte 0
 * .4byte 0
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
struct TAIAjudgeOptionalRange : public TaiAction {
	virtual void act(Teki&); // _10
	virtual void _1C() = 0;  // _1C
	virtual void _20() = 0;  // _20
	virtual void _24() = 0;  // _24
};

#endif
