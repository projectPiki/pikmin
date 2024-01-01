#ifndef _TAICOLLECVISIBLEHEIGHTPELLETLOSTTIMERACTION_H
#define _TAICOLLECVISIBLEHEIGHTPELLETLOSTTIMERACTION_H

/**
 * .obj __vt__43TaiCollecVisibleHeightPelletLostTimerAction, global
 * .4byte __RTTI__43TaiCollecVisibleHeightPelletLostTimerAction
 * .4byte 0
 * .4byte start__14TaiTimerActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__43TaiCollecVisibleHeightPelletLostTimerActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
*/

struct TaiTimerAction {
	virtual void start(Teki &);  // _08
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TaiCollecVisibleHeightPelletLostTimerAction : public TaiTimerAction, public TaiAction {
	virtual void act(Teki &);  // _10

};

#endif
