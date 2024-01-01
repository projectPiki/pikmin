#ifndef _PELLETSTATEMACHINE_H
#define _PELLETSTATEMACHINE_H

/**
 * .obj __vt__18PelletStateMachine, global
 * .4byte __RTTI__18PelletStateMachine
 * .4byte 0
 * .4byte init__18PelletStateMachineFP6Pellet
 * .4byte "exec__21StateMachine<6Pellet>FP6Pellet"
 * .4byte "procMsg__21StateMachine<6Pellet>FP6PelletP3Msg"
 * .4byte "transit__21StateMachine<6Pellet>FP6Pelleti"
*/

struct StateMachine<Pellet> {
	virtual void init(Pellet *);            // _08
	virtual void exec(Pellet *);            // _0C (weak)
	virtual void procMsg(Pellet *, Msg *);  // _10 (weak)
	virtual void transit(Pellet *, int);    // _14 (weak)
};

/**
 * @brief TODO
 */
struct PelletStateMachine : public StateMachine<Pellet> {
	virtual void init(Pellet *);  // _08

};

#endif
