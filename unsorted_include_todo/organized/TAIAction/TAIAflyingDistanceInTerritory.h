#ifndef _TAIAFLYINGDISTANCEINTERRITORY_H
#define _TAIAFLYINGDISTANCEINTERRITORY_H

/**
 * .obj __vt__29TAIAflyingDistanceInTerritory, global
 * .4byte __RTTI__29TAIAflyingDistanceInTerritory
 * .4byte 0
 * .4byte start__29TAIAflyingDistanceInTerritoryFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__29TAIAflyingDistanceInTerritoryFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte goal__29TAIAflyingDistanceInTerritoryFR4Teki
 * .4byte getVelocity__16TAIAflyingToGoalFR4Teki
 * .4byte __RTTI__29TAIAflyingDistanceInTerritory
 * .4byte 0xfffffff4
 * .4byte getOffset__14FlyingDistanceFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAflyingToGoal {
	virtual void start(Teki &);        // _08
	virtual void _0C() = 0;            // _0C
	virtual void act(Teki &);          // _10
	virtual void _14() = 0;            // _14
	virtual void _18() = 0;            // _18
	virtual void goal(Teki &);         // _1C
	virtual void getVelocity(Teki &);  // _20
};

struct FlyingDistance {
	virtual void start(Teki &);      // _08
	virtual void _0C() = 0;          // _0C
	virtual void act(Teki &);        // _10
	virtual void _14() = 0;          // _14
	virtual void _18() = 0;          // _18
	virtual void goal(Teki &);       // _1C
	virtual void _20() = 0;          // _20
	virtual void _24() = 0;          // _24
	virtual void _28() = 0;          // _28
	virtual void getOffset(Teki &);  // _2C
};

/**
 * @brief TODO
 */
struct TAIAflyingDistanceInTerritory : public TaiAction, public TAIAflyingToGoal, public FlyingDistance {
	virtual void start(Teki &);  // _08
	virtual void act(Teki &);    // _10
	virtual void goal(Teki &);   // _1C

};

#endif
