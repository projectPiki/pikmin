#ifndef _TAIAFLICKING_H
#define _TAIAFLICKING_H

/**
 * .obj __vt__12TAIAflicking, global
 * .4byte __RTTI__12TAIAflicking
 * .4byte 0
 * .4byte start__12TAIAflickingFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAflickingFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte flick__12TAIAflickingFR4Teki
 * .4byte getFlickDirection__12TAIAflickingFR4Teki
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
struct TAIAflicking : public TaiAction {
	virtual void start(Teki&);             // _08
	virtual void act(Teki&);               // _10
	virtual void flick(Teki&);             // _1C
	virtual void getFlickDirection(Teki&); // _20
};

#endif
