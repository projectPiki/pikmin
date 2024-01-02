#ifndef _RECEIVER_H
#define _RECEIVER_H

#include "types.h"
#include "Msg.h"

/**
 * @brief TODO
 */
template <typename T>
struct Receiver {

	virtual void procMsg(T*, Msg*);               // _08 (weak)
	virtual void procBounceMsg(T*, MsgBounce*);   // _0C (weak)
	virtual void procStickMsg(T*, MsgStick*);     // _10 (weak)
	virtual void procHangMsg(T*, MsgHang*);       // _14 (weak)
	virtual void procTargetMsg(T*, MsgTarget*);   // _18 (weak)
	virtual void procCollideMsg(T*, MsgCollide*); // _1C (weak)
	virtual void procAnimMsg(T*, MsgAnim*);       // _20 (weak)
	virtual void procDamageMsg(T*, MsgDamage*);   // _24 (weak)
	virtual void procWallMsg(T*, MsgWall*);       // _28 (weak)
	virtual void procOffWallMsg(T*, MsgOffWall*); // _2C (weak)
	virtual void procUserMsg(T*, MsgUser*);       // _30 (weak)
	virtual void procGroundMsg(T*, MsgGround*);   // _34 (weak)

	// _00 = VTBL
	// TODO: members
};

#endif
