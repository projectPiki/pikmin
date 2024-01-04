#ifndef _TAIAFLICKINGMIURIN_H
#define _TAIAFLICKINGMIURIN_H

/**
 * .obj __vt__18TAIAflickingMiurin, weak
 * .4byte __RTTI__18TAIAflickingMiurin
 * .4byte 0
 * .4byte start__25TAIAflickingReserveMotionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__25TAIAflickingReserveMotionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte flick__25TAIAflickingReserveMotionFR4Teki
 * .4byte getFlickDirection__18TAIAflickingMiurinFR4Teki
 */

struct TAIAflickingReserveMotion {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
	virtual void _14() = 0;    // _14
	virtual void _18() = 0;    // _18
	virtual void flick(Teki&); // _1C
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
struct TAIAflickingMiurin : public TAIAflickingReserveMotion, public TaiAction {
	virtual void getFlickDirection(Teki&); // _20
};

#endif
