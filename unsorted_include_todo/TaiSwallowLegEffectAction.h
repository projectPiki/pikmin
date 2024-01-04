#ifndef _TAISWALLOWLEGEFFECTACTION_H
#define _TAISWALLOWLEGEFFECTACTION_H

/**
 * .obj __vt__25TaiSwallowLegEffectAction, global
 * .4byte __RTTI__25TaiSwallowLegEffectAction
 * .4byte 0
 * .4byte start__18TAIAeffCloudOfDustFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__18TAIAeffCloudOfDustFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte setType__25TaiSwallowLegEffectActionFR8Vector3fii
 */

struct TAIAeffCloudOfDust {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

struct TaiAction {
	virtual void _08() = 0;              // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TaiSwallowLegEffectAction : public TAIAeffCloudOfDust, public TaiAction {
	virtual void setType(Vector3f&, int, int); // _1C
};

#endif
