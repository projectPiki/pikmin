#ifndef _TAIAFIREBREATHTANK_H
#define _TAIAFIREBREATHTANK_H

/**
 * .obj __vt__18TAIAfireBreathTank, weak
 * .4byte __RTTI__18TAIAfireBreathTank
 * .4byte 0
 * .4byte start__18TAIAfireBreathTankFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAfireBreathFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPreviousAnimSpeed__18TAIAfireBreathTankFR4Teki
 * .4byte getAttackAnimSpeed__18TAIAfireBreathTankFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAfireBreath {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

/**
 * @brief TODO
 */
struct TAIAfireBreathTank : public TaiAction, public TAIAfireBreath {
	virtual void start(Teki &);                 // _08
	virtual void getPreviousAnimSpeed(Teki &);  // _1C
	virtual void getAttackAnimSpeed(Teki &);    // _20

};

#endif
