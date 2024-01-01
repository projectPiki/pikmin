#ifndef _TAIABARKDORORO_H
#define _TAIABARKDORORO_H

/**
 * .obj __vt__14TAIAbarkDororo, weak
 * .4byte __RTTI__14TAIAbarkDororo
 * .4byte 0
 * .4byte start__14TAIAbarkDororoFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__14TAIAbarkDororoFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFrameMax__14TAIAmotionLoopFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

struct TAIAmotionLoop {
	virtual void start(Teki &);        // _08
	virtual void _0C() = 0;            // _0C
	virtual void act(Teki &);          // _10
	virtual void _14() = 0;            // _14
	virtual void _18() = 0;            // _18
	virtual void getFrameMax(Teki &);  // _1C (weak)
};

/**
 * @brief TODO
 */
struct TAIAbarkDororo : public TaiAction, public TAIAmotionLoop {
	virtual void start(Teki &);  // _08
	virtual void act(Teki &);    // _10

};

#endif
