#ifndef _BOMBAI_H
#define _BOMBAI_H

/**
 * .obj __vt__6BombAI, weak
 * .4byte __RTTI__6BombAI
 * .4byte 0
 * .4byte "init__26StateMachine<10AICreature>FP10AICreature"
 * .4byte exec__8SimpleAIFP10AICreature
 * .4byte procMsg__8SimpleAIFP10AICreatureP3Msg
 * .4byte "transit__26StateMachine<10AICreature>FP10AICreaturei"
 */

struct StateMachine<AICreature> {
	virtual void init(AICreature*);         // _08 (weak)
	virtual void _0C() = 0;                 // _0C
	virtual void _10() = 0;                 // _10
	virtual void transit(AICreature*, int); // _14 (weak)
};

struct SimpleAI {
	virtual void _08() = 0;                  // _08
	virtual void exec(AICreature*);          // _0C
	virtual void procMsg(AICreature*, Msg*); // _10
};

/**
 * @brief TODO
 */
struct BombAI : public StateMachine<AICreature>, public SimpleAI {

	BombAI();
};

#endif
