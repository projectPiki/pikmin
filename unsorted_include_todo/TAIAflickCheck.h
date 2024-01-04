#ifndef _TAIAFLICKCHECK_H
#define _TAIAFLICKCHECK_H

/**
 * .obj __vt__14TAIAflickCheck, global
 * .4byte __RTTI__14TAIAflickCheck
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAflickCheckFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getDamageCountLimit__14TAIAflickCheckFR4Teki
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
struct TAIAflickCheck : public TaiAction {
	virtual void act(Teki&);                 // _10
	virtual void getDamageCountLimit(Teki&); // _1C
};

#endif
