#ifndef _TAIAINWATER_H
#define _TAIAINWATER_H

/**
 * .obj __vt__11TAIAinWater, global
 * .4byte __RTTI__11TAIAinWater
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAinWaterFR4Teki
 * .4byte actByEvent__11TAIAinWaterFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TAIAinWater : public TaiAction {
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
