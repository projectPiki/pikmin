#ifndef _TAIAWATCHNAVIMIURIN_H
#define _TAIAWATCHNAVIMIURIN_H

/**
 * .obj __vt__19TAIAwatchNaviMiurin, weak
 * .4byte __RTTI__19TAIAwatchNaviMiurin
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__19TAIAwatchNaviMiurinFR4Teki
 * .4byte actByEvent__19TAIAwatchNaviMiurinFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TAIAwatchNaviMiurin : public TaiAction {
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
