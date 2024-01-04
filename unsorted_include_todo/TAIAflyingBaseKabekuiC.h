#ifndef _TAIAFLYINGBASEKABEKUIC_H
#define _TAIAFLYINGBASEKABEKUIC_H

/**
 * .obj __vt__22TAIAflyingBaseKabekuiC, weak
 * .4byte __RTTI__22TAIAflyingBaseKabekuiC
 * .4byte 0
 * .4byte start__14TAIAflyingBaseFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAflyingBaseFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFlyingStayVelocity__22TAIAflyingBaseKabekuiCFR4Teki
 */

struct TAIAflyingBase {
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
struct TAIAflyingBaseKabekuiC : public TAIAflyingBase, public TaiAction {
	virtual void getFlyingStayVelocity(Teki&); // _1C
};

#endif
