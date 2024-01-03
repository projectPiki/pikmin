#ifndef _TAIADAMAGE_H
#define _TAIADAMAGE_H

/**
 * .obj __vt__10TAIAdamage, global
 * .4byte __RTTI__10TAIAdamage
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__10TAIAdamageFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte judgeDamage__10TAIAdamageFR4Teki
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
struct TAIAdamage : public TaiAction {
	virtual void act(Teki &);          // _10
	virtual void judgeDamage(Teki &);  // _1C

};

#endif
