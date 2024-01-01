#ifndef _TAIASTICKINGPIKI_H
#define _TAIASTICKINGPIKI_H

/**
 * .obj __vt__16TAIAstickingPiki, global
 * .4byte __RTTI__16TAIAstickingPiki
 * .4byte 0
 * .4byte start__16TAIAstickingPikiFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAstickingPikiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPikiNum__16TAIAstickingPikiFR4Teki
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
struct TAIAstickingPiki : public TaiAction {
	virtual void start(Teki &);       // _08
	virtual void act(Teki &);         // _10
	virtual void getPikiNum(Teki &);  // _1C

};

#endif
