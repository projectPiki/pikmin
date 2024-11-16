#ifndef _SEEDITEM_H
#define _SEEDITEM_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"

struct Shape;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct SeedProp : public CreatureProp {
	inline SeedProp() { mCreatureProps.mFriction.mValue = 0.1f; }

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 *
 * @note Size: 0x2FC
 */
struct SeedItem : public Creature {
	SeedItem(CreatureProp*, Shape**);

	virtual void init(Vector3f&);         // _28
	virtual f32 getiMass();               // _38
	virtual f32 getSize();                // _3C
	virtual f32 getHeight();              // _40
	virtual bool isVisible();             // _74
	virtual bool isAtari();               // _84
	virtual bool stimulate(Interaction&); // _A0
	virtual void update();                // _E0
	virtual void refresh(Graphics&);      // _EC
	virtual void doAI();                  // _104
	virtual void doKill();                // _10C

	// unused/inlined:
	void startBirth();
	void startSown();

	// _00      = VTBL
	// _00-_2B8 = Creature
	u8 _2B8[0x2FC - 0x2B8]; // _2B8, unknown
};

#endif
