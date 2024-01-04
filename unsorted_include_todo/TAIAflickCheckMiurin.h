#ifndef _TAIAFLICKCHECKMIURIN_H
#define _TAIAFLICKCHECKMIURIN_H

/**
 * .obj __vt__20TAIAflickCheckMiurin, weak
 * .4byte __RTTI__20TAIAflickCheckMiurin
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__20TAIAflickCheckMiurinFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getDamageCountLimit__20TAIAflickCheckMiurinFR4Teki
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
struct TAIAflickCheckMiurin : public TaiAction {
	virtual void act(Teki&);                 // _10
	virtual void getDamageCountLimit(Teki&); // _1C
};

#endif
