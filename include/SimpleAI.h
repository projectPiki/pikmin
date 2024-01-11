#ifndef _SIMPLEAI_H
#define _SIMPLEAI_H

#include "types.h"
#include "AICreature.h"
#include "StateMachine.h"

/**
 * @brief TODO
 */
struct SAIAction {
	virtual void act(AICreature*) = 0; // _08

	// _00 = VTBL?
	// TODO: members
};

/**
 * @brief TODO
 */
struct SAIArrow : public CoreNode {
	inline SAIArrow()
	    : CoreNode("SAIArrowRoot")
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct SAICondition : public CoreNode {
	inline SAICondition()
	    : CoreNode()
	{
	}

	virtual bool satisfy(AICreature*); // _10 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct SAIEvent : public Receiver<AICreature> {
	// _00 = VTBL?
	// TODO: members
};

/**
 * @brief TODO
 */
struct SAIState : public AState<AICreature> {
	SAIState(int);

	virtual void procMsg(AICreature*, Msg*); // _08
	virtual void init(AICreature*);          // _38
	virtual void exec(AICreature*);          // _3C
	virtual void cleanup(AICreature*);       // _40

	// _00     = VTBL
	// _00-_0C = AState
	char* mName;             // _0C, probably
	SAIArrow mArrow;         // _0C
	int _24;                 // _24
	u32 _28;                 // _28, unknown
	u32 _2C;                 // _2C, unknown
	SAICondition mCondition; // _30
};

/**
 * @brief TODO
 */
struct SimpleAI : public StateMachine<AICreature> {
	SimpleAI();

	virtual void exec(AICreature*);          // _0C
	virtual void procMsg(AICreature*, Msg*); // _10

	void addState(int, int, SAIAction*, SAIAction*, SAIAction*);
	void addArrow(int, SAIEvent*, int);
	void start(AICreature*, int);
	void checkEvent(AICreature*);

	// _00     = VTBL
	// _00-_1C = StateMachine
	// TODO: members
};

#endif
