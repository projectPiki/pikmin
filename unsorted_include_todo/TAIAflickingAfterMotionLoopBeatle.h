#ifndef _TAIAFLICKINGAFTERMOTIONLOOPBEATLE_H
#define _TAIAFLICKINGAFTERMOTIONLOOPBEATLE_H

/**
 * .obj __vt__33TAIAflickingAfterMotionLoopBeatle, weak
 * .4byte __RTTI__33TAIAflickingAfterMotionLoopBeatle
 * .4byte 0
 * .4byte start__33TAIAflickingAfterMotionLoopBeatleFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__33TAIAflickingAfterMotionLoopBeatleFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getFrameMax__33TAIAflickingAfterMotionLoopBeatleFR4Teki
 * .4byte permitFlick__33TAIAflickingAfterMotionLoopBeatleFR4Teki
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
struct TAIAflickingAfterMotionLoopBeatle : public TaiAction {
	virtual void start(Teki&);       // _08
	virtual void act(Teki&);         // _10
	virtual void getFrameMax(Teki&); // _1C
	virtual void permitFlick(Teki&); // _20
};

#endif
