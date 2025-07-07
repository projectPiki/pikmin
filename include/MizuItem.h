#ifndef _MIZUITEM_H
#define _MIZUITEM_H

#include "CreatureProp.h"
#include "ItemMgr.h"
#include "types.h"

struct SimpleAI;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct MizuItemProp : public CreatureProp {
	inline MizuItemProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C8.
 */
struct MizuItem : public ItemCreature {
	MizuItem(int, CreatureProp*, ItemShapeObject*, SimpleAI*);

	virtual void startAI(int);         // _34
	virtual bool isAlive();            // _88
	virtual bool needFlick(Creature*); // _94
	virtual void update();             // _E0

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
};

#endif
