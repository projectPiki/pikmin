#ifndef _TAIACHECKSATISFYMIURIN_H
#define _TAIACHECKSATISFYMIURIN_H

/**
 * .obj __vt__22TAIAcheckSatisfyMiurin, weak
 * .4byte __RTTI__22TAIAcheckSatisfyMiurin
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__22TAIAcheckSatisfyMiurinFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TAIAcheckSatisfyMiurin : public TaiAction {
	virtual void act(Teki&); // _10
};

#endif
