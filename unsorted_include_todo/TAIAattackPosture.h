#ifndef _TAIAATTACKPOSTURE_H
#define _TAIAATTACKPOSTURE_H

/**
 * .obj __vt__17TAIAattackPosture, weak
 * .4byte __RTTI__17TAIAattackPosture
 * .4byte 0
 * .4byte start__17TAIAreserveMotionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TAIAattackPostureFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TAIAreserveMotion {
	virtual void start(Teki&); // _08
};

struct TaiAction {
	virtual void _08() = 0;              // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAattackPosture : public TAIAreserveMotion, public TaiAction {
	virtual void act(Teki&); // _10
};

#endif
