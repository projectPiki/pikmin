#ifndef _ITEMOBJECT_H
#define _ITEMOBJECT_H

#include "types.h"
#include "ItemMgr.h"

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
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct ItemObject : public ItemCreature {
	ItemObject(int, Shape*); // unused/inlined

	virtual bool isAtari();            // _84
	virtual bool needShadow();         // _90
	virtual void update();             // _E0
	virtual void postUpdate(int, f32); // _E4

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct Fulcrum : public ItemObject {
	Fulcrum();

	// _00      = VTBL
	// _00-_304 = ItemObject?
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct BombGenItem : public ItemObject {
	BombGenItem(Shape*);

	virtual bool isVisible();          // _74
	virtual bool isAtari();            // _84
	virtual bool isAlive();            // _88
	virtual bool needFlick(Creature*); // _94

	void pickable();
	void pick();

	// _00      = VTBL
	// _00-_304 = ItemObject?
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct NaviDemoSunsetStart : public ItemObject {
	NaviDemoSunsetStart();

	// _00      = VTBL
	// _00-_304 = ItemObject?
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct NaviDemoSunsetGoal : public ItemObject {
	NaviDemoSunsetGoal();

	// _00      = VTBL
	// _00-_304 = ItemObject?
	// TOD0: members
};

#endif
