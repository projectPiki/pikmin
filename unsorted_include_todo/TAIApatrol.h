#ifndef _TAIAPATROL_H
#define _TAIAPATROL_H

/**
 * .obj __vt__10TAIApatrol, global
 * .4byte __RTTI__10TAIApatrol
 * .4byte 0
 * .4byte start__10TAIApatrolFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__10TAIApatrolFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getTurnVelocity__16TAIAturnToTargetFR4Teki
 * .4byte getTimeout__10TAIApatrolFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAturnToTarget {
	virtual void start(Teki &);            // _08
	virtual void _0C() = 0;                // _0C
	virtual void act(Teki &);              // _10
	virtual void _14() = 0;                // _14
	virtual void _18() = 0;                // _18
	virtual void getTurnVelocity(Teki &);  // _1C
};

/**
 * @brief TODO
 */
struct TAIApatrol : public TaiAction, public TAIAturnToTarget {
	virtual void start(Teki &);       // _08
	virtual void act(Teki &);         // _10
	virtual void getTimeout(Teki &);  // _20

};

#endif
