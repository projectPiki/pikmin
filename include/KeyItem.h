#ifndef _KEYITEM_H
#define _KEYITEM_H

#include "Creature.h"
#include "CreatureProp.h"
#include "types.h"

struct Shape;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct KeyProp : public CreatureProp {
	inline KeyProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

BEGIN_ENUM_TYPE(KeyState)
enum {
	Active,    // Key is interactive
	Collected, // Key has been collected
	Inactive,  // Key is initialized but not started
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x2E4.
 */
struct KeyItem : public Creature {
	KeyItem(CreatureProp*, Shape*);

	virtual void init(Vector3f&);               // _28
	virtual void startAI(int);                  // _34
	virtual f32 getiMass();                     // _38
	virtual f32 getSize();                      // _3C
	virtual f32 getHeight() { return 0.0f; }    // _40
	virtual bool isVisible();                   // _74
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC

protected:
	virtual void doKill(); // _10C

	// _00      = VTBL
	// _00-_2B8 = Creature
	KeyState::Type mState; // _2B8
	SearchData mSearch[3]; // _2BC
	Shape* mModel;         // _2E0
};

#endif
