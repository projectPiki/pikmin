#ifndef _TAIADAMAGEBEATLE_H
#define _TAIADAMAGEBEATLE_H

/**
 * .obj __vt__16TAIAdamageBeatle, weak
 * .4byte __RTTI__16TAIAdamageBeatle
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__10TAIAdamageFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte judgeDamage__16TAIAdamageBeatleFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAdamage {
	virtual void _08() = 0;    // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki &);  // _10
};

/**
 * @brief TODO
 */
struct TAIAdamageBeatle : public TaiAction, public TAIAdamage {
	virtual void judgeDamage(Teki &);  // _1C

};

#endif
