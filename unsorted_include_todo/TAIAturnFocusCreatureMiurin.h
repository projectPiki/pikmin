#ifndef _TAIATURNFOCUSCREATUREMIURIN_H
#define _TAIATURNFOCUSCREATUREMIURIN_H

/**
 * .obj __vt__27TAIAturnFocusCreatureMiurin, weak
 * .4byte __RTTI__27TAIAturnFocusCreatureMiurin
 * .4byte 0
 * .4byte start__27TAIAturnFocusCreatureMiurinFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__21TAIAturnFocusCreatureFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getTurnVelocity__27TAIAturnFocusCreatureMiurinFR4Teki
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

struct TAIAturnFocusCreature {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

/**
 * @brief TODO
 */
struct TAIAturnFocusCreatureMiurin : public TaiAction, public TAIAturnFocusCreature {
	virtual void start(Teki&);           // _08
	virtual void getTurnVelocity(Teki&); // _1C
};

#endif
