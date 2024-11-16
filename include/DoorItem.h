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

	virtual void init(Vector3f&);    // _28
	virtual void startAI(int);       // _34
	virtual f32 getiMass();          // _38
	virtual f32 getSize();           // _3C
	virtual f32 getHeight();         // _40
	virtual bool isVisible();        // _74
	virtual bool isAtari();          // _84
	virtual bool isAlive();          // _88
	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC

	void disappear();

	// unused/inlined:
	void becomeGate();

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	u8 _3C8[0x3D8 - 0x3C8]; // _3C8, unknown
};

#endif
