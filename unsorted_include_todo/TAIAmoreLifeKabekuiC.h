#ifndef _TAIAMORELIFEKABEKUIC_H
#define _TAIAMORELIFEKABEKUIC_H

/**
 * .obj __vt__20TAIAmoreLifeKabekuiC, weak
 * .4byte __RTTI__20TAIAmoreLifeKabekuiC
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAmoreLifeFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getLifePercentThreshold__20TAIAmoreLifeKabekuiCFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAmoreLife {
	virtual void _08() = 0;    // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki &);  // _10
};

/**
 * @brief TODO
 */
struct TAIAmoreLifeKabekuiC : public TaiAction, public TAIAmoreLife {
	virtual void getLifePercentThreshold(Teki &);  // _1C

};

#endif
