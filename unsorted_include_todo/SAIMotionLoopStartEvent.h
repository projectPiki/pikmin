#ifndef _SAIMOTIONLOOPSTARTEVENT_H
#define _SAIMOTIONLOOPSTARTEVENT_H

/**
 * .obj __vt__23SAIMotionLoopStartEvent, global
 * .4byte __RTTI__23SAIMotionLoopStartEvent
 * .4byte 0
 * .4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
 * .4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
 * .4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
 * .4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
 * .4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
 * .4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
 * .4byte procAnimMsg__23SAIMotionLoopStartEventFP10AICreatureP7MsgAnim
 * .4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
 * .4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
 * .4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
 * .4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
 * .4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
 */

struct Receiver<AICreature> {
	virtual void procMsg(AICreature*, Msg*);               // _08 (weak)
	virtual void procBounceMsg(AICreature*, MsgBounce*);   // _0C (weak)
	virtual void procStickMsg(AICreature*, MsgStick*);     // _10 (weak)
	virtual void procHangMsg(AICreature*, MsgHang*);       // _14 (weak)
	virtual void procTargetMsg(AICreature*, MsgTarget*);   // _18 (weak)
	virtual void procCollideMsg(AICreature*, MsgCollide*); // _1C (weak)
	virtual void procAnimMsg(AICreature*, MsgAnim*);       // _20
	virtual void procDamageMsg(AICreature*, MsgDamage*);   // _24 (weak)
	virtual void procWallMsg(AICreature*, MsgWall*);       // _28 (weak)
	virtual void procOffWallMsg(AICreature*, MsgOffWall*); // _2C (weak)
	virtual void procUserMsg(AICreature*, MsgUser*);       // _30 (weak)
	virtual void procGroundMsg(AICreature*, MsgGround*);   // _34 (weak)
};

/**
 * @brief TODO
 */
struct SAIMotionLoopStartEvent : public Receiver<AICreature> {
	virtual void procAnimMsg(AICreature*, MsgAnim*); // _20
};

#endif
