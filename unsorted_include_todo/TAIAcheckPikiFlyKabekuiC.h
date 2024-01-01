#ifndef _TAIACHECKPIKIFLYKABEKUIC_H
#define _TAIACHECKPIKIFLYKABEKUIC_H

/**
 * .obj __vt__24TAIAcheckPikiFlyKabekuiC, weak
 * .4byte __RTTI__24TAIAcheckPikiFlyKabekuiC
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TAIAcheckPikiFlyKabekuiCFR4Teki
 * .4byte actByEvent__22TAIAhitCheckFlyingPikiFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
*/

struct TaiAction {
	virtual void start(Teki &);  // _08
	virtual void finish(Teki &); // _0C
	virtual void act(Teki &);    // _10
	virtual void _14() = 0;      // _14
	virtual void hasNextState(); // _18
};

struct TAIAhitCheckFlyingPiki {
	virtual void _08() = 0;                // _08
	virtual void _0C() = 0;                // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
};

/**
 * @brief TODO
 */
struct TAIAcheckPikiFlyKabekuiC : public TaiAction, public TAIAhitCheckFlyingPiki {
	virtual void act(Teki &);  // _10

};

#endif
