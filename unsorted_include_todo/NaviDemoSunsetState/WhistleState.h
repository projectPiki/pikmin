#ifndef _NAVIDEMOSUNSETSTATE_WHISTLESTATE_H
#define _NAVIDEMOSUNSETSTATE_WHISTLESTATE_H

/**
 * .obj __vt__Q219NaviDemoSunsetState12WhistleState, global
 * .4byte __RTTI__Q219NaviDemoSunsetState12WhistleState
 * .4byte 0
 * .4byte "procMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP3Msg"
 * .4byte "procBounceMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP9MsgBounce"
 * .4byte "procStickMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP8MsgStick"
 * .4byte "procHangMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP7MsgHang"
 * .4byte "procTargetMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP9MsgTarget"
 * .4byte "procCollideMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP10MsgCollide"
 * .4byte procAnimMsg__Q219NaviDemoSunsetState12WhistleStateFP19NaviDemoSunsetStateP7MsgAnim
 * .4byte "procDamageMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP9MsgDamage"
 * .4byte "procWallMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP7MsgWall"
 * .4byte "procOffWallMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP10MsgOffWall"
 * .4byte "procUserMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP7MsgUser"
 * .4byte "procGroundMsg__31Receiver<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP9MsgGround"
 * .4byte init__Q219NaviDemoSunsetState12WhistleStateFP19NaviDemoSunsetState
 * .4byte exec__Q219NaviDemoSunsetState12WhistleStateFP19NaviDemoSunsetState
 * .4byte cleanup__Q219NaviDemoSunsetState12WhistleStateFP19NaviDemoSunsetState
 * .4byte "resume__29AState<19NaviDemoSunsetState>FP19NaviDemoSunsetState"
 * .4byte "restart__29AState<19NaviDemoSunsetState>FP19NaviDemoSunsetState"
 * .4byte "transit__29AState<19NaviDemoSunsetState>FP19NaviDemoSunsetStatei"
 */

struct Receiver<NaviDemoSunsetState> {
	virtual void procMsg(NaviDemoSunsetState*, Msg*);               // _08 (weak)
	virtual void procBounceMsg(NaviDemoSunsetState*, MsgBounce*);   // _0C (weak)
	virtual void procStickMsg(NaviDemoSunsetState*, MsgStick*);     // _10 (weak)
	virtual void procHangMsg(NaviDemoSunsetState*, MsgHang*);       // _14 (weak)
	virtual void procTargetMsg(NaviDemoSunsetState*, MsgTarget*);   // _18 (weak)
	virtual void procCollideMsg(NaviDemoSunsetState*, MsgCollide*); // _1C (weak)
	virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*);       // _20
	virtual void procDamageMsg(NaviDemoSunsetState*, MsgDamage*);   // _24 (weak)
	virtual void procWallMsg(NaviDemoSunsetState*, MsgWall*);       // _28 (weak)
	virtual void procOffWallMsg(NaviDemoSunsetState*, MsgOffWall*); // _2C (weak)
	virtual void procUserMsg(NaviDemoSunsetState*, MsgUser*);       // _30 (weak)
	virtual void procGroundMsg(NaviDemoSunsetState*, MsgGround*);   // _34 (weak)
};

struct AState<NaviDemoSunsetState> {
	virtual void _08() = 0;                                   // _08
	virtual void _0C() = 0;                                   // _0C
	virtual void _10() = 0;                                   // _10
	virtual void _14() = 0;                                   // _14
	virtual void _18() = 0;                                   // _18
	virtual void _1C() = 0;                                   // _1C
	virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*); // _20
	virtual void _24() = 0;                                   // _24
	virtual void _28() = 0;                                   // _28
	virtual void _2C() = 0;                                   // _2C
	virtual void _30() = 0;                                   // _30
	virtual void _34() = 0;                                   // _34
	virtual void init(NaviDemoSunsetState*);                  // _38
	virtual void exec(NaviDemoSunsetState*);                  // _3C
	virtual void cleanup(NaviDemoSunsetState*);               // _40
	virtual void resume(NaviDemoSunsetState*);                // _44 (weak)
	virtual void restart(NaviDemoSunsetState*);               // _48 (weak)
	virtual void transit(NaviDemoSunsetState*, int);          // _4C (weak)
};

namespace NaviDemoSunsetState {
/**
 * @brief TODO
 */
struct WhistleState : public Receiver<NaviDemoSunsetState>, public AState<NaviDemoSunsetState> {
	virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*); // _20
	virtual void init(NaviDemoSunsetState*);                  // _38
	virtual void exec(NaviDemoSunsetState*);                  // _3C
	virtual void cleanup(NaviDemoSunsetState*);               // _40

	void enterAllPikis(NaviDemoSunsetState*);
};
} // namespace NaviDemoSunsetState

#endif
