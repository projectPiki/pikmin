#ifndef _TAIAFLICKINGAFTERMOTIONLOOP_H
#define _TAIAFLICKINGAFTERMOTIONLOOP_H

/**
 * .obj __vt__27TAIAflickingAfterMotionLoop, global
 * .4byte __RTTI__27TAIAflickingAfterMotionLoop
 * .4byte 0
 * .4byte start__27TAIAflickingAfterMotionLoopFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__27TAIAflickingAfterMotionLoopFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFrameMax__27TAIAflickingAfterMotionLoopFR4Teki
 * .4byte permitFlick__27TAIAflickingAfterMotionLoopFR4Teki
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
struct TAIAflickingAfterMotionLoop : public TaiAction {
	virtual void start(Teki &);        // _08
	virtual void act(Teki &);          // _10
	virtual void getFrameMax(Teki &);  // _1C
	virtual void permitFlick(Teki &);  // _20

};

#endif
