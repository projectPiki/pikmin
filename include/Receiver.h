#ifndef _RECEIVER_H
#define _RECEIVER_H

#include "types.h"
#include "Msg.h"

/**
 * @brief TODO
 */
template <typename T>
struct Receiver {

	virtual void procMsg(T* target, Msg* msg) // _08 (weak)
	{
		switch (msg->_00) {
		case 0:
			procBounceMsg(target, static_cast<MsgBounce*>(msg));
			break;
		case 8:
			procStickMsg(target, static_cast<MsgStick*>(msg));
			break;
		case 1:
			procHangMsg(target, static_cast<MsgHang*>(msg));
			break;
		case 2:
			procTargetMsg(target, static_cast<MsgTarget*>(msg));
			break;
		case 3:
			procCollideMsg(target, static_cast<MsgCollide*>(msg));
			break;
		case 4:
			procAnimMsg(target, static_cast<MsgAnim*>(msg));
			break;
		case 5:
			procDamageMsg(target, static_cast<MsgDamage*>(msg));
			break;
		case 6:
			procWallMsg(target, static_cast<MsgWall*>(msg));
			break;
		case 7:
			procOffWallMsg(target, static_cast<MsgOffWall*>(msg));
			break;
		case 10:
			procUserMsg(target, static_cast<MsgUser*>(msg));
			break;
		case 9:
			procGroundMsg(target, static_cast<MsgGround*>(msg));
			break;
		}
	}
	virtual void procBounceMsg(T*, MsgBounce*) { }   // _0C (weak)
	virtual void procStickMsg(T*, MsgStick*) { }     // _10 (weak)
	virtual void procHangMsg(T*, MsgHang*) { }       // _14 (weak)
	virtual void procTargetMsg(T*, MsgTarget*) { }   // _18 (weak)
	virtual void procCollideMsg(T*, MsgCollide*) { } // _1C (weak)
	virtual void procAnimMsg(T*, MsgAnim*) { }       // _20 (weak)
	virtual void procDamageMsg(T*, MsgDamage*) { }   // _24 (weak)
	virtual void procWallMsg(T*, MsgWall*) { }       // _28 (weak)
	virtual void procOffWallMsg(T*, MsgOffWall*) { } // _2C (weak)
	virtual void procUserMsg(T*, MsgUser*) { }       // _30 (weak)
	virtual void procGroundMsg(T*, MsgGround*) { }   // _34 (weak)

	// _00 = VTBL
};

#endif
