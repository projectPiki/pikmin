#ifndef _TAIALESSLIFE_H
#define _TAIALESSLIFE_H

/**
 * .obj __vt__12TAIAlessLife, global
 * .4byte __RTTI__12TAIAlessLife
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAlessLifeFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte 0
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
struct TAIAlessLife : public TaiAction {
	virtual void act(Teki &);  // _10
	virtual void _1C() = 0;    // _1C

};

#endif
