#ifndef _TAIAFLYINGDISTANCEINTERRITORYMAR_H
#define _TAIAFLYINGDISTANCEINTERRITORYMAR_H

/**
 * .obj __vt__32TAIAflyingDistanceInTerritoryMar, weak
 * .4byte __RTTI__32TAIAflyingDistanceInTerritoryMar
 * .4byte 0
 * .4byte start__29TAIAflyingDistanceInTerritoryFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__29TAIAflyingDistanceInTerritoryFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte goal__29TAIAflyingDistanceInTerritoryFR4Teki
 * .4byte getVelocity__32TAIAflyingDistanceInTerritoryMarFR4Teki
 * .4byte __RTTI__32TAIAflyingDistanceInTerritoryMar
 * .4byte 0xfffffff4
 * .4byte "@12@getOffset__32TAIAflyingDistanceInTerritoryMarFR4Teki"
 * .4byte getOffset__32TAIAflyingDistanceInTerritoryMarFR4Teki
 */

struct TAIAflyingDistanceInTerritory {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
	virtual void _14() = 0;    // _14
	virtual void _18() = 0;    // _18
	virtual void goal(Teki&);  // _1C
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
struct TAIAflyingDistanceInTerritoryMar : public TAIAflyingDistanceInTerritory, public TaiAction {
	virtual void getVelocity(Teki&); // _20
	virtual void getOffset(Teki&);   // _30
};

#endif
