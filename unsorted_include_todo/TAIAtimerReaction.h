#ifndef _TAIATIMERREACTION_H
#define _TAIATIMERREACTION_H

/**
 * .obj __vt__17TAIAtimerReaction, weak
 * .4byte __RTTI__17TAIAtimerReaction
 * .4byte 0
 * .4byte start__17TAIAtimerReactionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TAIAtimerReactionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFrameMax__17TAIAtimerReactionFR4Teki
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
struct TAIAtimerReaction : public TaiAction {
	virtual void start(Teki&);       // _08
	virtual void act(Teki&);         // _10
	virtual void getFrameMax(Teki&); // _1C
};

#endif
