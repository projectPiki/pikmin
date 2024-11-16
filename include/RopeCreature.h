#ifndef _ROPECREATURE_H
#define _ROPECREATURE_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"

struct Shape;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct RopeProp : public CreatureProp {
	inline RopeProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 */
struct RopeCreature : public Creature {
	RopeCreature(CreatureProp*);

	virtual bool needShadow();       // _90 (weak)
	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC
	virtual void doKill() = 0;       // _10C

	void setRope(Creature*);
	void getRopePos(f32);

	// _00      = VTBL
	// _00-_2B8 = Creature
	Creature* _2B8;     // _2B8, probably
	RopeCreature* _2BC; // _2BC, probably
	f32 _2C0;           // _2C0
	Vector3f _2C4;      // _2C4
};

/**
 * @brief TODO
 *
 * @note Size: 0x300.
 */
struct RopeItem : public RopeCreature {
	RopeItem(CreatureProp*, Shape*);

	virtual void init(Vector3f&); // _28
	virtual void startAI(int);    // _34
	virtual f32 getiMass();       // _38
	virtual f32 getSize();        // _3C
	virtual bool isVisible();     // _74
	virtual bool isAtari();       // _84
	virtual bool isAlive();       // _88
	virtual bool needShadow();    // _90
	virtual void doKill();        // _10C

	void autoInit();

	// _00      = VTBL
	// _00-_2D0 = RopeCreature
	u8 _2D0[0x300 - 0x2D0]; // _2D0
};

#endif
