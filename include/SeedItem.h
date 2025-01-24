#ifndef _SEEDITEM_H
#define _SEEDITEM_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"
#include "Interactions.h"

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

	virtual void init(Vector3f&);            // _28
	virtual f32 getSize();                   // _3C
	virtual bool isVisible();                // _74
	virtual bool isAtari();                  // _84
	virtual void update();                   // _E0
	virtual void refresh(Graphics&);         // _EC
	virtual void doAI();                     // _104
	virtual void doKill();                   // _10C
	virtual bool stimulate(Interaction& act) // _A0
	{
		act.actCommon(this);
		return true;
	}
	virtual f32 getHeight() { return 0.0f; }  // _40
	virtual f32 getiMass() { return 100.0f; } // _38

	// unused/inlined:
	void startBirth();
	void startSown();

	// _00      = VTBL
	// _00-_2B8 = Creature
	int mStateId;          // _2B8
	SearchData mSearch[3]; // _2BC
	f32 _2E0;              // _2E0
	Shape* mCurrentShape;  // _2E4
	Shape* mShape;         // _2E8
	Shape* mShape2;        // _2EC
	Vector3f _2F0;         // _2F0
};

#endif
