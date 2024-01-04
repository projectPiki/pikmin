#ifndef _TAIAFIREBREATHMAR_H
#define _TAIAFIREBREATHMAR_H

/**
 * .obj __vt__17TAIAfireBreathMar, weak
 * .4byte __RTTI__17TAIAfireBreathMar
 * .4byte 0
 * .4byte start__17TAIAfireBreathMarFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TAIAfireBreathMarFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPreviousAnimSpeed__17TAIAfireBreathMarFR4Teki
 * .4byte getAttackAnimSpeed__17TAIAfireBreathMarFR4Teki
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
struct TAIAfireBreathMar : public TaiAction {
	virtual void start(Teki&);                // _08
	virtual void act(Teki&);                  // _10
	virtual void getPreviousAnimSpeed(Teki&); // _1C
	virtual void getAttackAnimSpeed(Teki&);   // _20
};

#endif
