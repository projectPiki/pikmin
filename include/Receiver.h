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
		switch (msg->mMsgType) {
		case MSG_Bounce:
			procBounceMsg(target, static_cast<MsgBounce*>(msg));
			break;
		case MSG_Stick:
			procStickMsg(target, static_cast<MsgStick*>(msg));
			break;
		case MSG_Hang:
			procHangMsg(target, static_cast<MsgHang*>(msg));
			break;
		case MSG_Target:
			procTargetMsg(target, static_cast<MsgTarget*>(msg));
			break;
		case MSG_Collide:
			procCollideMsg(target, static_cast<MsgCollide*>(msg));
			break;
		case MSG_Anim:
			procAnimMsg(target, static_cast<MsgAnim*>(msg));
			break;
		case MSG_Damage:
			procDamageMsg(target, static_cast<MsgDamage*>(msg));
			break;
		case MSG_Wall:
			procWallMsg(target, static_cast<MsgWall*>(msg));
			break;
		case MSG_OffWall:
			procOffWallMsg(target, static_cast<MsgOffWall*>(msg));
			break;
		case MSG_User:
			procUserMsg(target, static_cast<MsgUser*>(msg));
			break;
		case MSG_Ground:
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
