#ifndef _DOORITEM_H
#define _DOORITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct DoorProp : public CreatureProp {
	inline DoorProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 *
 * @note Size: 0x3D8.
 */
struct DoorItem : public ItemCreature {
	DoorItem(int p1, CreatureProp* props, Shape* shape);

	virtual void init(Vector3f&);            // _28
	virtual void startAI(int);               // _34
	virtual f32 getiMass();                  // _38
	virtual f32 getSize();                   // _3C
	virtual bool isVisible();                // _74
	virtual bool isAtari();                  // _84
	virtual void update();                   // _E0
	virtual void refresh(Graphics&);         // _EC
	virtual bool isAlive() { return true; }  // _88
	virtual f32 getHeight() { return 0.0f; } // _40

	void disappear();

	// unused/inlined:
	void becomeGate();

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	f32 _3C8;     // _3C8
	int mStateId; // _3CC
	char* _3D0;   // _3D0
	char* _3D4;   // _3D4
};

#endif
