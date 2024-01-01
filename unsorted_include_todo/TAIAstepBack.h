#ifndef _TAIASTEPBACK_H
#define _TAIASTEPBACK_H

/**
 * .obj __vt__12TAIAstepBack, global
 * .4byte __RTTI__12TAIAstepBack
 * .4byte 0
 * .4byte start__12TAIAstepBackFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAstepBackFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getVelocity__12TAIAstepBackFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAstepBack : public TaiAction {
	virtual void start(Teki &);        // _08
	virtual void act(Teki &);          // _10
	virtual void getVelocity(Teki &);  // _1C

};

#endif
