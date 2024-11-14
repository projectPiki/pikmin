#ifndef _MIZUITEM_H
#define _MIZUITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"

struct SimpleAI;

/**
 * @brief TODO
 */
struct MizuItemProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 */
struct MizuItem : public ItemCreature {
	MizuItem(int, CreatureProp*, ItemShapeObject*, SimpleAI*);

	virtual void startAI(int);         // _34
	virtual bool isAlive();            // _88
	virtual bool needFlick(Creature*); // _94
	virtual void update();             // _E0

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	// TODO: members
};

#endif
