#ifndef _TAIATIMERREACTIONTAMAGO_H
#define _TAIATIMERREACTIONTAMAGO_H

/**
 * .obj __vt__23TAIAtimerReactionTamago, weak
 * .4byte __RTTI__23TAIAtimerReactionTamago
 * .4byte 0
 * .4byte start__23TAIAtimerReactionTamagoFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__23TAIAtimerReactionTamagoFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFrameMax__23TAIAtimerReactionTamagoFR4Teki
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
struct TAIAtimerReactionTamago : public TaiAction {
	virtual void start(Teki &);        // _08
	virtual void act(Teki &);          // _10
	virtual void getFrameMax(Teki &);  // _1C

};

#endif
