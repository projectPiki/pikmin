#ifndef _TAIAANGRYMIURIN_H
#define _TAIAANGRYMIURIN_H

/**
 * .obj __vt__15TAIAangryMiurin, weak
 * .4byte __RTTI__15TAIAangryMiurin
 * .4byte 0
 * .4byte start__15TAIAangryMiurinFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__15TAIAangryMiurinFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFlickDirection__15TAIAangryMiurinFR4Teki
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
struct TAIAangryMiurin : public TaiAction {
	virtual void start(Teki&);             // _08
	virtual void act(Teki&);               // _10
	virtual void getFlickDirection(Teki&); // _1C
};

#endif
