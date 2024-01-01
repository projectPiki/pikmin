#ifndef _SAISTATE_H
#define _SAISTATE_H

/**
 * .obj __vt__8SAIState, global
 * .4byte __RTTI__8SAIState
 * .4byte 0
 * .4byte procMsg__8SAIStateFP10AICreatureP3Msg
 * .4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
 * .4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
 * .4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
 * .4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
 * .4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
 * .4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
 * .4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
 * .4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
 * .4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
 * .4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
 * .4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
 * .4byte init__8SAIStateFP10AICreature
 * .4byte exec__8SAIStateFP10AICreature
 * .4byte cleanup__8SAIStateFP10AICreature
 * .4byte "resume__20AState<10AICreature>FP10AICreature"
 * .4byte "restart__20AState<10AICreature>FP10AICreature"
 * .4byte "transit__20AState<10AICreature>FP10AICreaturei"
*/

struct Receiver<AICreature> {
	virtual void procMsg(AICreature *, Msg *);                // _08
	virtual void procBounceMsg(AICreature *, MsgBounce *);    // _0C (weak)
	virtual void procStickMsg(AICreature *, MsgStick *);      // _10 (weak)
	virtual void procHangMsg(AICreature *, MsgHang *);        // _14 (weak)
	virtual void procTargetMsg(AICreature *, MsgTarget *);    // _18 (weak)
	virtual void procCollideMsg(AICreature *, MsgCollide *);  // _1C (weak)
	virtual void procAnimMsg(AICreature *, MsgAnim *);        // _20 (weak)
	virtual void procDamageMsg(AICreature *, MsgDamage *);    // _24 (weak)
	virtual void procWallMsg(AICreature *, MsgWall *);        // _28 (weak)
	virtual void procOffWallMsg(AICreature *, MsgOffWall *);  // _2C (weak)
	virtual void procUserMsg(AICreature *, MsgUser *);        // _30 (weak)
	virtual void procGroundMsg(AICreature *, MsgGround *);    // _34 (weak)
};

struct AState<AICreature> {
	virtual void procMsg(AICreature *, Msg *);  // _08
	virtual void _0C() = 0;                     // _0C
	virtual void _10() = 0;                     // _10
	virtual void _14() = 0;                     // _14
	virtual void _18() = 0;                     // _18
	virtual void _1C() = 0;                     // _1C
	virtual void _20() = 0;                     // _20
	virtual void _24() = 0;                     // _24
	virtual void _28() = 0;                     // _28
	virtual void _2C() = 0;                     // _2C
	virtual void _30() = 0;                     // _30
	virtual void _34() = 0;                     // _34
	virtual void init(AICreature *);            // _38
	virtual void exec(AICreature *);            // _3C
	virtual void cleanup(AICreature *);         // _40
	virtual void resume(AICreature *);          // _44 (weak)
	virtual void restart(AICreature *);         // _48 (weak)
	virtual void transit(AICreature *, int);    // _4C (weak)
};

/**
 * @brief TODO
 */
struct SAIState : public Receiver<AICreature>, public AState<AICreature> {
	virtual void procMsg(AICreature *, Msg *);  // _08
	virtual void init(AICreature *);            // _38
	virtual void exec(AICreature *);            // _3C
	virtual void cleanup(AICreature *);         // _40

};

#endif
