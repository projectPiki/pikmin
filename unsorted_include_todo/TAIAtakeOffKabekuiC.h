#ifndef _TAIATAKEOFFKABEKUIC_H
#define _TAIATAKEOFFKABEKUIC_H

/**
 * .obj __vt__19TAIAtakeOffKabekuiC, weak
 * .4byte __RTTI__19TAIAtakeOffKabekuiC
 * .4byte 0
 * .4byte start__19TAIAtakeOffKabekuiCFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__19TAIAtakeOffKabekuiCFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TAIAtakeOffKabekuiC : public TaiAction {
	virtual void start(Teki&); // _08
	virtual void act(Teki&);   // _10
};

#endif
