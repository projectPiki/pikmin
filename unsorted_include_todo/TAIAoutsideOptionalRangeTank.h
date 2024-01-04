#ifndef _TAIAOUTSIDEOPTIONALRANGETANK_H
#define _TAIAOUTSIDEOPTIONALRANGETANK_H

/**
 * .obj __vt__28TAIAoutsideOptionalRangeTank, weak
 * .4byte __RTTI__28TAIAoutsideOptionalRangeTank
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__22TAIAjudgeOptionalRangeFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte setTargetPosition__28TAIAoutsideOptionalRangeTankFR4Teki
 * .4byte getOptionalRange__28TAIAoutsideOptionalRangeTankFR4Teki
 * .4byte judgement__24TAIAoutsideOptionalRangeFR4Teki
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

struct TAIAoutsideOptionalRange {
	virtual void _08() = 0;                // _08
	virtual void _0C() = 0;                // _0C
	virtual void _10() = 0;                // _10
	virtual void _14() = 0;                // _14
	virtual void _18() = 0;                // _18
	virtual void setTargetPosition(Teki&); // _1C
	virtual void getOptionalRange(Teki&);  // _20
	virtual void judgement(Teki&);         // _24
};

/**
 * @brief TODO
 */
struct TAIAoutsideOptionalRangeTank : public TaiAction, public TAIAjudgeOptionalRange, public TAIAoutsideOptionalRange {
	virtual void setTargetPosition(Teki&); // _1C
	virtual void getOptionalRange(Teki&);  // _20
};

#endif
