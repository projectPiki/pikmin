#ifndef _KUSAITEM_H
#define _KUSAITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"

struct InteractBuild;

/////////// Climbing Stick Item ///////////

/*
 * @brief TODO
 */
struct KusaItemProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/*
 * @brief TODO
 */
struct KusaItem : public ItemCreature {
	KusaItem(CreatureProp*, Shape*);

	virtual void startAI(int);                // _34
	virtual f32 getiMass();                   // _38
	virtual f32 getSize();                    // _3C
	virtual void doSave(RandomAccessStream&); // _50
	virtual void doLoad(RandomAccessStream&); // _54
	virtual bool isVisible();                 // _74
	virtual bool isAlive();                   // _88
	virtual bool ignoreAtari(Creature*);      // _98
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	// TODO: members
};

/////////// Stick Base Item (CUT/CRASHES) ///////////

/*
 * @brief TODO
 */
struct BoBaseItem : public ItemCreature {
	BoBaseItem(CreatureProp*, Shape*);

	virtual void startAI(int);           // _34
	virtual f32 getiMass();              // _38
	virtual f32 getSize();               // _3C
	virtual bool isVisible();            // _74
	virtual bool isAlive();              // _88
	virtual bool ignoreAtari(Creature*); // _98
	virtual void update();               // _E0
	virtual void refresh(Graphics&);     // _EC

	void interactBuild(InteractBuild&);

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	// TODO: members
};

#endif
