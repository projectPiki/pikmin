#ifndef _TAIAFLYUSUBA_H
#define _TAIAFLYUSUBA_H

/**
 * .obj __vt__12TAIAflyUsuba, weak
 * .4byte __RTTI__12TAIAflyUsuba
 * .4byte 0
 * .4byte start__12TAIAflyUsubaFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAflyUsubaFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiAction {
	virtual void start(Teki&);           // _08 (weak)
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10 (weak)
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAflyUsuba : public TaiAction {
	virtual void start(Teki&); // _08 (weak)
	virtual void act(Teki&);   // _10 (weak)
};

#endif
