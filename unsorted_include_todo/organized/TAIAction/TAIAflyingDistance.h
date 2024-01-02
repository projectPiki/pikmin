#ifndef _TAIAFLYINGDISTANCE_H
#define _TAIAFLYINGDISTANCE_H

/**
 * .obj __vt__18TAIAflyingDistance, global
 * .4byte __RTTI__18TAIAflyingDistance
 * .4byte 0
 * .4byte start__18TAIAflyingDistanceFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__18TAIAflyingDistanceFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte __RTTI__18TAIAflyingDistance
 * .4byte 0xfffffff8
 * .4byte getOffset__14FlyingDistanceFR4Teki
 * .4byte getGoalAreaRange__18TAIAflyingDistanceFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct FlyingDistance {
	virtual void start(Teki &);      // _08
	virtual void _0C() = 0;          // _0C
	virtual void act(Teki &);        // _10
	virtual void _14() = 0;          // _14
	virtual void _18() = 0;          // _18
	virtual void _1C() = 0;          // _1C
	virtual void _20() = 0;          // _20
	virtual void getOffset(Teki &);  // _24
};

/**
 * @brief TODO
 */
struct TAIAflyingDistance : public TaiAction, public FlyingDistance {
	virtual void start(Teki &);             // _08
	virtual void act(Teki &);               // _10
	virtual void getGoalAreaRange(Teki &);  // _28

};

#endif
