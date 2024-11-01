#ifndef _MSG_H
#define _MSG_H

#include "types.h"
#include "Collision.h"
#include "Vector.h"

struct Creature;
struct PaniAnimKeyEvent;

/**
 * @brief TODO
 */
enum MsgType {
	MSG_Bounce  = 0,
	MSG_Hang    = 1,
	MSG_Target  = 2,
	MSG_Collide = 3,
	MSG_Anim    = 4,
	MSG_Damage  = 5,
	MSG_Wall    = 6,
	MSG_OffWall = 7,
	MSG_Stick   = 8,
	MSG_Ground  = 9,
	MSG_User    = 10,
};

/**
 * @brief TODO
 */
struct Msg {
	inline Msg(int type)
	    : mMsgType(type)
	{
	}

	int mMsgType; // _00
};

/**
 * @brief TODO
 *
 * @note will need to fix saiEvents.cpp when this gets worked out
 */
struct MsgAnim : public Msg {
	inline MsgAnim(PaniAnimKeyEvent* event) // adjust when type of _04 is known
	    : Msg(MSG_Anim)
	    , mKeyEvent(event)
	{
	}

	// _00-_04 = Msg
	PaniAnimKeyEvent* mKeyEvent; // _04, probably a pointer to a struct with a u32 or int at _00
};

/**
 * @brief TODO
 */
struct MsgBounce : public Msg {
	inline MsgBounce(Vector3f& normal)
	    : Msg(MSG_Bounce)
	    , mNormal(normal)
	{
	}

	// _00-_04 = Msg
	Vector3f mNormal; // _04
};

/**
 * @brief TODO
 */
struct MsgCollide : public Msg {
	inline MsgCollide(CollEvent& event)
	    : Msg(MSG_Collide)
	    , mEvent(event)
	{
	}

	// _00-_04 = Msg
	CollEvent mEvent; // _04
};

/**
 * @brief TODO
 */
struct MsgDamage : public Msg {
	inline MsgDamage()
	    : Msg(MSG_Damage)
	{
	}

	// _00-_04 = Msg
	// TODO: members
};

/**
 * @brief TODO
 */
struct MsgGround : public Msg {
	inline MsgGround()
	    : Msg(MSG_Ground)
	{
	}

	// _00-_04 = Msg
	// TODO: members
};

/**
 * @brief TODO
 */
struct MsgHang : public Msg {
	inline MsgHang()
	    : Msg(MSG_Hang)
	{
	}

	// _00-_04 = Msg
	// TODO: members
};

/**
 * @brief TODO
 */
struct MsgOffWall : public Msg {
	inline MsgOffWall()
	    : Msg(MSG_OffWall)
	{
	}

	// _00-_04 = Msg
	// TODO: members
};

/**
 * @brief TODO
 */
struct MsgStick : public Msg {
	inline MsgStick()
	    : Msg(MSG_Stick)
	{
	}

	// _00-_04 = Msg
	// TODO: members
};

/**
 * @brief TODO
 */
struct MsgTarget : public Msg {
	MsgTarget(Creature* target)
	    : Msg(MSG_Target)
	{
		mTarget = target;
	}

	// _00-_04 = Msg
	Creature* mTarget; // _04
};

/**
 * @brief TODO
 */
struct MsgUser : public Msg {
	inline MsgUser(u32 val)
	    : Msg(MSG_User)
	{
		_04 = val;
	}

	// _00-_04 = Msg
	u32 _04; // _04, could be int
};

/**
 * @brief TODO
 */
struct MsgWall : public Msg {
	inline MsgWall()
	    : Msg(MSG_Wall)
	{
	}

	// _00-_04 = Msg
	// TODO: members
};

#endif
