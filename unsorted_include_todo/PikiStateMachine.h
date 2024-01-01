#ifndef _PIKISTATEMACHINE_H
#define _PIKISTATEMACHINE_H

/**
 * .obj __vt__16PikiStateMachine, global
 * .4byte __RTTI__16PikiStateMachine
 * .4byte 0
 * .4byte init__16PikiStateMachineFP4Piki
 * .4byte "exec__19StateMachine<4Piki>FP4Piki"
 * .4byte "procMsg__19StateMachine<4Piki>FP4PikiP3Msg"
 * .4byte transit__16PikiStateMachineFP4Pikii
*/

struct StateMachine<Piki> {
	virtual void init(Piki *);            // _08
	virtual void exec(Piki *);            // _0C
	virtual void procMsg(Piki *, Msg *);  // _10
};

/**
 * @brief TODO
 */
struct PikiStateMachine : public StateMachine<Piki> {
	virtual void init(Piki *);          // _08
	virtual void transit(Piki *, int);  // _14

};

#endif
