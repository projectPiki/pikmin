#ifndef _KEYITEM_H
#define _KEYITEM_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"

struct Shape;

/**
 * @brief TODO
 */
struct KeyProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 */
struct KeyItem : public Creature {
	KeyItem(CreatureProp*, Shape*);

	virtual void init(Vector3f&);               // _28
	virtual void startAI(int);                  // _34
	virtual f32 getiMass();                     // _38
	virtual f32 getSize();                      // _3C
	virtual f32 getHeight();                    // _40
	virtual bool isVisible();                   // _74
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void doKill();                      // _10C

	// _00      = VTBL
	// _00-_2B8 = Creature
	// TODO: members
};

#endif
