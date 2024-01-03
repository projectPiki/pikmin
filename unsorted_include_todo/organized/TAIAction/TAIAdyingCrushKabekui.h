#ifndef _TAIADYINGCRUSHKABEKUI_H
#define _TAIADYINGCRUSHKABEKUI_H

/**
 * .obj __vt__21TAIAdyingCrushKabekui, global
 * .4byte __RTTI__21TAIAdyingCrushKabekui
 * .4byte 0
 * .4byte start__21TAIAdyingCrushKabekuiFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAdyingKabekuiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAdyingKabekui {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

/**
 * @brief TODO
 */
struct TAIAdyingCrushKabekui : public TaiAction, public TAIAdyingKabekui {
	virtual void start(Teki &);  // _08

};

#endif
