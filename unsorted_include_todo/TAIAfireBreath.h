#ifndef _TAIAFIREBREATH_H
#define _TAIAFIREBREATH_H

/**
 * .obj __vt__14TAIAfireBreath, global
 * .4byte __RTTI__14TAIAfireBreath
 * .4byte 0
 * .4byte start__14TAIAfireBreathFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAfireBreathFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPreviousAnimSpeed__14TAIAfireBreathFR4Teki
 * .4byte getAttackAnimSpeed__14TAIAfireBreathFR4Teki
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
struct TAIAfireBreath : public TaiAction {
	virtual void start(Teki&);                // _08
	virtual void act(Teki&);                  // _10
	virtual void getPreviousAnimSpeed(Teki&); // _1C
	virtual void getAttackAnimSpeed(Teki&);   // _20
};

#endif
