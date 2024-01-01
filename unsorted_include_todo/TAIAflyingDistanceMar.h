#ifndef _TAIAFLYINGDISTANCEMAR_H
#define _TAIAFLYINGDISTANCEMAR_H

/**
 * .obj __vt__21TAIAflyingDistanceMar, weak
 * .4byte __RTTI__21TAIAflyingDistanceMar
 * .4byte 0
 * .4byte start__18TAIAflyingDistanceFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__21TAIAflyingDistanceMarFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte __RTTI__21TAIAflyingDistanceMar
 * .4byte 0xfffffff8
 * .4byte "@8@getOffset__21TAIAflyingDistanceMarFR4Teki"
 * .4byte getGoalAreaRange__21TAIAflyingDistanceMarFR4Teki
 * .4byte getOffset__21TAIAflyingDistanceMarFR4Teki
*/

struct TAIAflyingDistance {
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
struct TAIAflyingDistanceMar : public TAIAflyingDistance, public TaiAction {
	virtual void act(Teki &);               // _10
	virtual void getGoalAreaRange(Teki &);  // _28
	virtual void getOffset(Teki &);         // _2C

};

#endif
