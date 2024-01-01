#ifndef _TAIADESCENT_H
#define _TAIADESCENT_H

/**
 * .obj __vt__11TAIAdescent, global
 * .4byte __RTTI__11TAIAdescent
 * .4byte 0
 * .4byte start__11TAIAdescentFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAdescentFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFlyingVelocity__11TAIAdescentFR4Teki
 * .4byte getForceDescentFrame__11TAIAdescentFR4Teki
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
struct TAIAdescent : public TaiAction {
	virtual void start(Teki &);                 // _08
	virtual void act(Teki &);                   // _10
	virtual void getFlyingVelocity(Teki &);     // _1C
	virtual void getForceDescentFrame(Teki &);  // _20

};

#endif
