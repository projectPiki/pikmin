#ifndef _NAVISTATEMACHINE_H
#define _NAVISTATEMACHINE_H

/**
 * .obj __vt__16NaviStateMachine, global
 * .4byte __RTTI__16NaviStateMachine
 * .4byte 0
 * .4byte init__16NaviStateMachineFP4Navi
 * .4byte "exec__19StateMachine<4Navi>FP4Navi"
 * .4byte "procMsg__19StateMachine<4Navi>FP4NaviP3Msg"
 * .4byte "transit__19StateMachine<4Navi>FP4Navii"
 */

struct StateMachine<Navi> {
	virtual void init(Navi*);          // _08
	virtual void exec(Navi*);          // _0C (weak)
	virtual void procMsg(Navi*, Msg*); // _10 (weak)
	virtual void transit(Navi*, int);  // _14 (weak)
};

/**
 * @brief TODO
 */
struct NaviStateMachine : public StateMachine<Navi> {
	virtual void init(Navi*); // _08
};

#endif
