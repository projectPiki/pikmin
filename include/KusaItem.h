#ifndef _KUSAITEM_H
#define _KUSAITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"
#include "Collision.h"

namespace zen {
struct particleGenerator;
} // namespace zen

struct InteractBuild;
struct BoBaseItem;

/////////// Climbing Stick Item ///////////

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct KusaItemProp : public CreatureProp {
	inline KusaItemProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
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
	virtual bool isVisible() { return true; } // _74
	virtual bool isAlive() { return true; }   // _88
	virtual bool ignoreAtari(Creature*);      // _98
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	CollInfo mKusaCollision; // _3C8
	CollPart mKusaParts[10]; // _3DC
	u32 mPartIDs[10];        // _7EC
	Vector3f _814;           // _814
	BoBaseItem* mBaseItem;   // _820
};

/////////// Stick Base Item (CUT/CRASHES) ///////////

/*
 * @brief TODO
 */
struct BoBaseItem : public ItemCreature {
	BoBaseItem(CreatureProp*, Shape*);

	virtual void startAI(int);                // _34
	virtual f32 getiMass();                   // _38
	virtual f32 getSize();                    // _3C
	virtual bool isVisible() { return true; } // _74
	virtual bool isAlive();                   // _88
	virtual bool ignoreAtari(Creature*);      // _98
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC

	bool interactBuild(InteractBuild&);

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	CollInfo mBaseCollision;          // _3C8
	CollPart mBaseParts[10];          // _3DC
	u32 mPartIDs[10];                 // _7EC
	Vector3f _814;                    // _814
	KusaItem* mStickItem;             // _820
	bool _824;                        // _824
	s8 _825;                          // _825
	zen::particleGenerator* mPtclGen; // _828
};

#endif
