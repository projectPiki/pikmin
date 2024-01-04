#ifndef _TAIAJUDGELIFE_H
#define _TAIAJUDGELIFE_H

/**
 * .obj __vt__13TAIAjudgeLife, weak
 * .4byte __RTTI__13TAIAjudgeLife
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__9TaiActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TAIAjudgeLife : public TaiAction {
	virtual void _1C() = 0; // _1C
};

#endif
