#ifndef _TAIADIVEKABEKUIA_H
#define _TAIADIVEKABEKUIA_H

/**
 * .obj __vt__16TAIAdiveKabekuiA, weak
 * .4byte __RTTI__16TAIAdiveKabekuiA
 * .4byte 0
 * .4byte start__17TAIAtimerReactionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__17TAIAtimerReactionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFrameMax__16TAIAdiveKabekuiAFR4Teki
*/

struct TAIAtimerReaction {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiA : public TAIAtimerReaction, public TaiAction {
	virtual void getFrameMax(Teki &);  // _1C

};

#endif
