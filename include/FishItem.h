#ifndef _FISHITEM_H
#define _FISHITEM_H

#include "types.h"
#include "ItemMgr.h"

/*
 * @brief TODO
 */
struct Fish {
	Fish();

	// TODO: members
};

/*
 * @brief TODO
 */
struct FishGenerator : public ItemCreature {
	FishGenerator();

	virtual void startAI(int);       // _34
	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC

	void moveFish(Fish*);

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

#endif
