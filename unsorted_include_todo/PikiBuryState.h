#ifndef _PIKIBURYSTATE_H
#define _PIKIBURYSTATE_H

/**
 * .obj __vt__13PikiBuryState, global
 * .4byte __RTTI__13PikiBuryState
 * .4byte 0
 * .4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
 * .4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
 * .4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
 * .4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
 * .4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
 * .4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
 * .4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
 * .4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
 * .4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
 * .4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
 * .4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
 * .4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
 * .4byte init__13PikiBuryStateFP4Piki
 * .4byte exec__13PikiBuryStateFP4Piki
 * .4byte cleanup__13PikiBuryStateFP4Piki
 * .4byte "resume__13AState<4Piki>FP4Piki"
 * .4byte "restart__13AState<4Piki>FP4Piki"
 * .4byte transit__9PikiStateFP4Pikii
 * .4byte stopEffect__9PikiStateFv
 * .4byte restartEffect__9PikiStateFv
 * .4byte dump__9PikiStateFv
 * .4byte doDump__9PikiStateFv
 * .4byte useLookUpdate__9PikiStateFv
 * .4byte collideAI__9PikiStateFv
 * .4byte freeAI__9PikiStateFv
 */

struct Receiver<Piki> {
	virtual void procMsg(Piki*, Msg*);               // _08
	virtual void procBounceMsg(Piki*, MsgBounce*);   // _0C
	virtual void procStickMsg(Piki*, MsgStick*);     // _10
	virtual void procHangMsg(Piki*, MsgHang*);       // _14
	virtual void procTargetMsg(Piki*, MsgTarget*);   // _18
	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procDamageMsg(Piki*, MsgDamage*);   // _24
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual void procOffWallMsg(Piki*, MsgOffWall*); // _2C
	virtual void procUserMsg(Piki*, MsgUser*);       // _30
	virtual void procGroundMsg(Piki*, MsgGround*);   // _34
};

struct AState<Piki> {
	virtual void _08() = 0;      // _08
	virtual void _0C() = 0;      // _0C
	virtual void _10() = 0;      // _10
	virtual void _14() = 0;      // _14
	virtual void _18() = 0;      // _18
	virtual void _1C() = 0;      // _1C
	virtual void _20() = 0;      // _20
	virtual void _24() = 0;      // _24
	virtual void _28() = 0;      // _28
	virtual void _2C() = 0;      // _2C
	virtual void _30() = 0;      // _30
	virtual void _34() = 0;      // _34
	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40
	virtual void resume(Piki*);  // _44
	virtual void restart(Piki*); // _48
};

struct PikiState {
	virtual void _08() = 0;           // _08
	virtual void _0C() = 0;           // _0C
	virtual void _10() = 0;           // _10
	virtual void _14() = 0;           // _14
	virtual void _18() = 0;           // _18
	virtual void _1C() = 0;           // _1C
	virtual void _20() = 0;           // _20
	virtual void _24() = 0;           // _24
	virtual void _28() = 0;           // _28
	virtual void _2C() = 0;           // _2C
	virtual void _30() = 0;           // _30
	virtual void _34() = 0;           // _34
	virtual void init(Piki*);         // _38
	virtual void exec(Piki*);         // _3C
	virtual void cleanup(Piki*);      // _40
	virtual void _44() = 0;           // _44
	virtual void _48() = 0;           // _48
	virtual void transit(Piki*, int); // _4C
	virtual void stopEffect();        // _50
	virtual void restartEffect();     // _54
	virtual void dump();              // _58
	virtual void doDump();            // _5C
	virtual void useLookUpdate();     // _60
	virtual void collideAI();         // _64
	virtual void freeAI();            // _68
};

/**
 * @brief TODO
 */
struct PikiBuryState : public Receiver<Piki>, public AState<Piki>, public PikiState {
	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40
};

#endif
