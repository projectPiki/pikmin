#ifndef _NAVIDEMOSUNSETSTATE_DEMOSTATEMACHINE_H
#define _NAVIDEMOSUNSETSTATE_DEMOSTATEMACHINE_H

/**
 * .obj __vt__Q219NaviDemoSunsetState16DemoStateMachine, global
 * .4byte __RTTI__Q219NaviDemoSunsetState16DemoStateMachine
 * .4byte 0
 * .4byte init__Q219NaviDemoSunsetState16DemoStateMachineFP19NaviDemoSunsetState
 * .4byte "exec__35StateMachine<19NaviDemoSunsetState>FP19NaviDemoSunsetState"
 * .4byte "procMsg__35StateMachine<19NaviDemoSunsetState>FP19NaviDemoSunsetStateP3Msg"
 * .4byte "transit__35StateMachine<19NaviDemoSunsetState>FP19NaviDemoSunsetStatei"
 */

struct StateMachine<NaviDemoSunsetState> {
	virtual void init(NaviDemoSunsetState*);          // _08
	virtual void exec(NaviDemoSunsetState*);          // _0C (weak)
	virtual void procMsg(NaviDemoSunsetState*, Msg*); // _10 (weak)
	virtual void transit(NaviDemoSunsetState*, int);  // _14 (weak)
};

namespace NaviDemoSunsetState {
/**
 * @brief TODO
 */
struct DemoStateMachine : public StateMachine<NaviDemoSunsetState> {
	virtual void init(NaviDemoSunsetState*); // _08
};
} // namespace NaviDemoSunsetState

#endif
