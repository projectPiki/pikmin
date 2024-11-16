#ifndef _FISHITEM_H
#define _FISHITEM_H

#include "types.h"
#include "ItemMgr.h"

/**
 * @brief
 *
 * @note Size: 0x1C.
 */
struct Fish {
	Fish() { }

	Vector3f mPosition; // _00
	Vector3f _0C;       // _0C
	f32 mDirection;     // _18
};

/**
 * @brief TODO
 */
struct FishGenerator : public ItemCreature {
	FishGenerator();

	virtual void startAI(int);       // _34
	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC

	void moveFish(Fish*);

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	int mFishCount;         // _3C8
	int mMaxFish;           // _3CC
	Fish* mFish;            // _3D0
	Vector3f mSchoolCentre; // _3D4
	Vector3f _3E0;          // _3E0
};

#endif
