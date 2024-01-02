#ifndef _TAIAFLYINGMOTIONKABEKUIC_H
#define _TAIAFLYINGMOTIONKABEKUIC_H

/**
 * .obj __vt__24TAIAflyingMotionKabekuiC, weak
 * .4byte __RTTI__24TAIAflyingMotionKabekuiC
 * .4byte 0
 * .4byte start__24TAIAflyingMotionKabekuiCFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TAIAreserveMotionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAreserveMotion {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

/**
 * @brief TODO
 */
struct TAIAflyingMotionKabekuiC : public TaiAction, public TAIAreserveMotion {
	virtual void start(Teki &);  // _08

};

#endif
