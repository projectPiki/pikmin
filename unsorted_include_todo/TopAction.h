#ifndef _TOPACTION_H
#define _TOPACTION_H

/**
 * .obj __vt__9TopAction, global
 * .4byte __RTTI__9TopAction
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
 * .4byte defaultInitialiser__6ActionFv
 * .4byte dump__6ActionFv
 * .4byte draw__9TopActionFR8Graphics
 * .4byte __dt__9TopActionFv
 * .4byte init__9TopActionFP8Creature
 * .4byte exec__9TopActionFv
 * .4byte cleanup__6ActionFv
 * .4byte resume__9TopActionFv
 * .4byte restart__9TopActionFv
 * .4byte resumable__9TopActionFv
 * .4byte getInfo__9TopActionFPc
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

struct Action {
	virtual void _08() = 0;            // _08
	virtual void _0C() = 0;            // _0C
	virtual void _10() = 0;            // _10
	virtual void _14() = 0;            // _14
	virtual void _18() = 0;            // _18
	virtual void _1C() = 0;            // _1C
	virtual void _20() = 0;            // _20
	virtual void _24() = 0;            // _24
	virtual void _28() = 0;            // _28
	virtual void _2C() = 0;            // _2C
	virtual void _30() = 0;            // _30
	virtual void _34() = 0;            // _34
	virtual void defaultInitialiser(); // _38
	virtual void dump();               // _3C
	virtual void draw(Graphics&);      // _40
	virtual ~Action();                 // _44
	virtual void init(Creature*);      // _48
	virtual void exec();               // _4C
	virtual void cleanup();            // _50
};

/**
 * @brief TODO
 */
struct TopAction : public Receiver<Piki>, public Action {
	virtual void draw(Graphics&); // _40
	virtual ~TopAction();         // _44
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void resume();        // _54
	virtual void restart();       // _58
	virtual void resumable();     // _5C
	virtual void getInfo(char*);  // _60
};

#endif
