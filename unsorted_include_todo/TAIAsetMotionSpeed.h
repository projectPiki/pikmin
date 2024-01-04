#ifndef _TAIASETMOTIONSPEED_H
#define _TAIASETMOTIONSPEED_H

/**
 * .obj __vt__18TAIAsetMotionSpeed, weak
 * .4byte __RTTI__18TAIAsetMotionSpeed
 * .4byte 0
 * .4byte start__18TAIAsetMotionSpeedFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__10TAIAmotionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void _10() = 0;              // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

struct TAIAmotion {
	virtual void start(Teki&); // _08
	virtual void _0C() = 0;    // _0C
	virtual void act(Teki&);   // _10
};

/**
 * @brief TODO
 */
struct TAIAsetMotionSpeed : public TaiAction, public TAIAmotion {
	virtual void start(Teki&); // _08
};

#endif
