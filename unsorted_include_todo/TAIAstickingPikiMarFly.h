#ifndef _TAIASTICKINGPIKIMARFLY_H
#define _TAIASTICKINGPIKIMARFLY_H

/**
 * .obj __vt__22TAIAstickingPikiMarFly, weak
 * .4byte __RTTI__22TAIAstickingPikiMarFly
 * .4byte 0
 * .4byte start__16TAIAstickingPikiFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAstickingPikiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPikiNum__22TAIAstickingPikiMarFlyFR4Teki
*/

struct TAIAstickingPiki {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAstickingPikiMarFly : public TAIAstickingPiki, public TaiAction {
	virtual void getPikiNum(Teki &);  // _1C

};

#endif
