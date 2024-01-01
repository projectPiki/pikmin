#ifndef _PELLETUFOLOADSTATE_H
#define _PELLETUFOLOADSTATE_H

/**
 * .obj __vt__18PelletUfoLoadState, global
 * .4byte __RTTI__18PelletUfoLoadState
 * .4byte 0
 * .4byte "procMsg__17Receiver<6Pellet>FP6PelletP3Msg"
 * .4byte "procBounceMsg__17Receiver<6Pellet>FP6PelletP9MsgBounce"
 * .4byte "procStickMsg__17Receiver<6Pellet>FP6PelletP8MsgStick"
 * .4byte "procHangMsg__17Receiver<6Pellet>FP6PelletP7MsgHang"
 * .4byte "procTargetMsg__17Receiver<6Pellet>FP6PelletP9MsgTarget"
 * .4byte "procCollideMsg__17Receiver<6Pellet>FP6PelletP10MsgCollide"
 * .4byte "procAnimMsg__17Receiver<6Pellet>FP6PelletP7MsgAnim"
 * .4byte "procDamageMsg__17Receiver<6Pellet>FP6PelletP9MsgDamage"
 * .4byte "procWallMsg__17Receiver<6Pellet>FP6PelletP7MsgWall"
 * .4byte "procOffWallMsg__17Receiver<6Pellet>FP6PelletP10MsgOffWall"
 * .4byte "procUserMsg__17Receiver<6Pellet>FP6PelletP7MsgUser"
 * .4byte "procGroundMsg__17Receiver<6Pellet>FP6PelletP9MsgGround"
 * .4byte init__18PelletUfoLoadStateFP6Pellet
 * .4byte exec__18PelletUfoLoadStateFP6Pellet
 * .4byte cleanup__18PelletUfoLoadStateFP6Pellet
 * .4byte "resume__15AState<6Pellet>FP6Pellet"
 * .4byte "restart__15AState<6Pellet>FP6Pellet"
 * .4byte "transit__15AState<6Pellet>FP6Pelleti"
*/

struct Receiver<Pellet> {
	virtual void procMsg(Pellet *, Msg *);                // _08 (weak)
	virtual void procBounceMsg(Pellet *, MsgBounce *);    // _0C (weak)
	virtual void procStickMsg(Pellet *, MsgStick *);      // _10 (weak)
	virtual void procHangMsg(Pellet *, MsgHang *);        // _14 (weak)
	virtual void procTargetMsg(Pellet *, MsgTarget *);    // _18 (weak)
	virtual void procCollideMsg(Pellet *, MsgCollide *);  // _1C (weak)
	virtual void procAnimMsg(Pellet *, MsgAnim *);        // _20 (weak)
	virtual void procDamageMsg(Pellet *, MsgDamage *);    // _24 (weak)
	virtual void procWallMsg(Pellet *, MsgWall *);        // _28 (weak)
	virtual void procOffWallMsg(Pellet *, MsgOffWall *);  // _2C (weak)
	virtual void procUserMsg(Pellet *, MsgUser *);        // _30 (weak)
	virtual void procGroundMsg(Pellet *, MsgGround *);    // _34 (weak)
};

struct AState<Pellet> {
	virtual void _08() = 0;               // _08
	virtual void _0C() = 0;               // _0C
	virtual void _10() = 0;               // _10
	virtual void _14() = 0;               // _14
	virtual void _18() = 0;               // _18
	virtual void _1C() = 0;               // _1C
	virtual void _20() = 0;               // _20
	virtual void _24() = 0;               // _24
	virtual void _28() = 0;               // _28
	virtual void _2C() = 0;               // _2C
	virtual void _30() = 0;               // _30
	virtual void _34() = 0;               // _34
	virtual void init(Pellet *);          // _38
	virtual void exec(Pellet *);          // _3C
	virtual void cleanup(Pellet *);       // _40
	virtual void resume(Pellet *);        // _44 (weak)
	virtual void restart(Pellet *);       // _48 (weak)
	virtual void transit(Pellet *, int);  // _4C (weak)
};

/**
 * @brief TODO
 */
struct PelletUfoLoadState : public Receiver<Pellet>, public AState<Pellet> {
	virtual void init(Pellet *);     // _38
	virtual void exec(Pellet *);     // _3C
	virtual void cleanup(Pellet *);  // _40

};

#endif
