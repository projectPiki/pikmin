#ifndef _TAIAEATPIKI_H
#define _TAIAEATPIKI_H

/**
 * .obj __vt__11TAIAeatPiki, global
 * .4byte __RTTI__11TAIAeatPiki
 * .4byte 0
 * .4byte start__11TAIAeatPikiFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAeatPikiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte eatEffect__11TAIAeatPikiFR4Teki
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
struct TAIAeatPiki : public TaiAction {
	virtual void start(Teki &);      // _08
	virtual void act(Teki &);        // _10
	virtual void eatEffect(Teki &);  // _1C

};

#endif
