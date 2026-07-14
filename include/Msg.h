#ifndef _MSG_H
#define _MSG_H

#include "Collision.h"
#include "Vector.h"
#include "types.h"

class Creature;
class PaniAnimKeyEvent;

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
class Msg {
public:
	inline Msg(int type)
	    : mMsgType(type)
	{
	}

	int mMsgType; // _00, see `MsgType` enum.
};

/**
 * @brief TODO
 *
 * @note will need to fix saiEvents.cpp when this gets worked out
 */
class MsgAnim : public Msg {
public:
	inline MsgAnim(immut PaniAnimKeyEvent* event) // adjust when type of _04 is known
	    : Msg(MSG_Anim)
	    , mKeyEvent(event)
	{
	}

	// _00-_04 = Msg
	immut PaniAnimKeyEvent* mKeyEvent; // _04, probably a pointer to a struct with a u32 or int at _00
};

/**
 * @brief TODO
 */
class MsgBounce : public Msg {
public:
	inline MsgBounce(immut Vector3f& normal)
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
class MsgCollide : public Msg {
public:
	inline MsgCollide(immut CollEvent& event)
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
class MsgDamage : public Msg {
public:
	inline MsgDamage() // this never gets called, funnily enough
	    : Msg(MSG_Damage)
	{
	}

	// _00-_04 = Msg
};

/**
 * @brief TODO
 */
class MsgGround : public Msg {
public:
	inline MsgGround()
	    : Msg(MSG_Ground)
	{
	}

	// _00-_04 = Msg
};

/**
 * @brief TODO
 */
class MsgHang : public Msg {
public:
	inline MsgHang() // this also never gets called
	    : Msg(MSG_Hang)
	{
	}

	// _00-_04 = Msg
};

/**
 * @brief TODO
 */
class MsgOffWall : public Msg {
public:
	inline MsgOffWall(DynCollObject* object)
	    : Msg(MSG_OffWall)
	    , mObject(object)
	{
	}

	// _00-_04 = Msg
	DynCollObject* mObject; // _04
};

/**
 * @brief TODO
 */
class MsgStick : public Msg {
public:
	inline MsgStick()
	    : Msg(MSG_Stick)
	{
	}

	// _00-_04 = Msg
};

/**
 * @brief TODO
 */
class MsgTarget : public Msg {
public:
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
class MsgUser : public Msg {
public:
	inline MsgUser(int val)
	    : Msg(MSG_User)
	{
		mUserID = val;
	}

	// _00-_04 = Msg
	int mUserID; // _04
};

/**
 * @brief TODO
 */
class MsgWall : public Msg {
public:
	inline MsgWall(immut Plane& plane, DynCollObject* wall)
	    : Msg(MSG_Wall)
	{
		mWallPlane      = &plane;
		mWallCollObject = wall;
	}

	// _00-_04 = Msg
	immut Plane* mWallPlane;        // _04
	DynCollObject* mWallCollObject; // _08
};

#endif
