#ifndef _ITEMOBJECT_H
#define _ITEMOBJECT_H

#include "Collision.h"
#include "ItemMgr.h"
#include "types.h"

/**
 * @brief TODO.
 */
struct ItemBall : public ItemCreature {
	ItemBall(Shape*, CreatureProp*);

	virtual void startAI(int); // _34
	virtual bool isVisible();  // _74
	virtual bool isAlive();    // _88

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	CollInfo mBallCollision; // _3C8
	CollPart mBallParts[10]; // _3DC
	u32 mPartIDs[10];        // _7EC
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C8.
 */
struct ItemObject : public ItemCreature {
	ItemObject(int, Shape*); // unused/inlined

	virtual bool needShadow() { return false; }            // _90
	virtual void update();                                 // _E0
	virtual void postUpdate(int unused, f32 deltaTime) { } // _E4
	virtual bool isAtari() { return false; }               // _84

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3C8.
 */
struct Fulcrum : public ItemObject {
	Fulcrum();

	// _00      = VTBL
	// _00-_3C8 = ItemObject
};

/**
 * @brief TODO
 *
 * @note Size: 0x3CC.
 */
struct BombGenItem : public ItemObject {
	BombGenItem(Shape*);

	virtual bool isAtari() // _84
	{
		return isValid();
	}
	virtual bool needFlick(Creature*) // _94
	{
		return false;
	}
	virtual bool isVisible() // _74
	{
		return isValid();
	}
	virtual bool isAlive() // _88
	{
		return isValid();
	}

	bool pickable();
	bool pick();

	inline bool isValid()
	{
		if (_3C8 == -1) {
			return true;
		}

		if (_3CA > 0) {
			return true;
		}

		return false;
	}

	// _00      = VTBL
	// _00-_3C8 = ItemObject
	s16 _3C8; // _3C8
	s16 _3CA; // _3CA
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C8.
 */
struct NaviDemoSunsetStart : public ItemObject {
	NaviDemoSunsetStart();

	// _00      = VTBL
	// _00-_3C8 = ItemObject
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct NaviDemoSunsetGoal : public ItemObject {
	NaviDemoSunsetGoal();

	// _00      = VTBL
	// _00-_3C8 = ItemObject
	// TOD0: members
};

#endif
