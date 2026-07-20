#ifndef _SIMPLEAI_H
#define _SIMPLEAI_H

#include "StateMachine.h"
#include "types.h"

// NB: do not combine this file with SAIEvent.h, they have to stay separate for weak function ordering
// in simpleAI.cpp (lol and also lmao)

#define C_SAI(obj) static_cast<SimpleAI*>(obj->mSAICtx.mStateMachine)

class AICreature;
class SAIEvent;
class SAIAction;
class SAIArrow;

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
class SimpleAI : public StateMachine<AICreature> {
public:
	SimpleAI();

	virtual void procMsg(AICreature*, Msg*); // _10
	virtual void exec(AICreature*);          // _0C

	void addState(int, int, SAIAction* = nullptr, SAIAction* = nullptr, SAIAction* = nullptr);
	SAIArrow* addArrow(int, SAIEvent*, int);
	void start(AICreature*, int);
	void checkEvent(AICreature*);

	// _00     = VTBL
	// _00-_1C = StateMachine
};

#endif
