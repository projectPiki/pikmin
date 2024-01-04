#ifndef _TAIAINWATERDAMAGE_H
#define _TAIAINWATERDAMAGE_H

/**
 * .obj __vt__17TAIAinWaterDamage, global
 * .4byte __RTTI__17TAIAinWaterDamage
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TAIAinWaterDamageFR4Teki
 * .4byte actByEvent__17TAIAinWaterDamageFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAinWaterDamage : public TaiAction {
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
};

#endif
