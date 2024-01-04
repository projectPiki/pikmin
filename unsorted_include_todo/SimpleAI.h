#ifndef _SIMPLEAI_H
#define _SIMPLEAI_H

/**
 * .obj __vt__8SimpleAI, global
 * .4byte __RTTI__8SimpleAI
 * .4byte 0
 * .4byte "init__26StateMachine<10AICreature>FP10AICreature"
 * .4byte exec__8SimpleAIFP10AICreature
 * .4byte procMsg__8SimpleAIFP10AICreatureP3Msg
 * .4byte "transit__26StateMachine<10AICreature>FP10AICreaturei"
 */

struct StateMachine<AICreature> {
	virtual void init(AICreature*);          // _08 (weak)
	virtual void exec(AICreature*);          // _0C
	virtual void procMsg(AICreature*, Msg*); // _10
	virtual void transit(AICreature*, int);  // _14 (weak)
};

/**
 * @brief TODO
 */
struct SimpleAI : public StateMachine<AICreature> {
	virtual void exec(AICreature*);          // _0C
	virtual void procMsg(AICreature*, Msg*); // _10

	SimpleAI();
	void addState(int, int, SAIAction*, SAIAction*, SAIAction*);
	void addArrow(int, SAIEvent*, int);
	void start(AICreature*, int);
	void checkEvent(AICreature*);
};

#endif
