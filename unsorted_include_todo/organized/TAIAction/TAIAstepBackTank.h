#ifndef _TAIASTEPBACKTANK_H
#define _TAIASTEPBACKTANK_H

/**
 * .obj __vt__16TAIAstepBackTank, weak
 * .4byte __RTTI__16TAIAstepBackTank
 * .4byte 0
 * .4byte start__12TAIAstepBackFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAstepBackTankFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getVelocity__16TAIAstepBackTankFR4Teki
*/

struct TAIAstepBack {
	virtual void start(Teki &);  // _08
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAstepBackTank : public TAIAstepBack, public TaiAction {
	virtual void act(Teki &);          // _10
	virtual void getVelocity(Teki &);  // _1C

};

#endif
