#ifndef _TAIAMORELIFE_H
#define _TAIAMORELIFE_H

/**
 * .obj __vt__12TAIAmoreLife, global
 * .4byte __RTTI__12TAIAmoreLife
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAmoreLifeFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte 0
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
struct TAIAmoreLife : public TaiAction {
	virtual void act(Teki&); // _10
	virtual void _1C() = 0;  // _1C
};

#endif
