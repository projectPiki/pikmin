#ifndef _BUILDINGITEM_H
#define _BUILDINGITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"

struct ItemShapeObject;
struct SimpleAI;

/**
 * @brief TODO
 */
struct BuildingItemProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO.
 */
struct BuildingItem : public ItemCreature {
	BuildingItem(int, CreatureProp*, ItemShapeObject*, SimpleAI*);

	virtual bool insideSafeArea(Vector3f&);   // _10
	virtual void startAI(int);                // _34
	virtual f32 getiMass();                   // _38 (weak)
	virtual void doStore(CreatureInf*);       // _48
	virtual void doRestore(CreatureInf*);     // _4C
	virtual void doSave(RandomAccessStream&); // _50
	virtual void doLoad(RandomAccessStream&); // _54
	virtual f32 getBoundingSphereRadius();    // _64
	virtual bool isAlive();                   // _88
	virtual bool needShadow();                // _90 (weak)
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC
	virtual void refresh2d(Graphics&);        // _F0
	virtual void doKill();                    // _10C
	virtual void playEffect(int);             // _12C
	virtual void isCompleted();               // _15C

	void startBreakEffect();
	void stopBreakEffect();

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

#endif
