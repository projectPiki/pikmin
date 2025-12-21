#ifndef _CREATURECOLLPART_H
#define _CREATURECOLLPART_H

#include "DynColl.h"
#include "types.h"

struct CollPart;

/**
 * @brief TODO
 *
 * @note Size: 0x148.
 */
struct CreatureCollPart : public DynCollShape {
	CreatureCollPart() // TODO: fix this, it's implicit but required/this is just a guess
	    : DynCollShape(nullptr)
	{
		mAnimMatrixID = 0;
		mOwner        = nullptr;
	}

	CreatureCollPart(Shape* shape)
	    : DynCollShape(shape)
	{
		mAnimMatrixID = 0;
		mOwner        = nullptr;
	}

	virtual void update() { }                                             // _10 (weak)
	virtual void touchCallback(Plane&, immut Vector3f&, immut Vector3f&); // _38
	virtual void refresh(Graphics&) { }                                   // _44 (weak)

	// _00      = VTBL
	// _00-_140 = DynCollShape
	Creature* mOwner;  // _140
	int mAnimMatrixID; // _144, anim matrix ID?
};

/**
 * @brief TODO
 *
 * @note Size: 0x48.
 */
struct CreaturePlatMgr {
	CreaturePlatMgr()
	    : mPartCount(0)
	{
	}

	void init(Creature*, MapMgr*, Shape*);
	void release();
	void update(Graphics&);

	Shape* mPlatShape;                // _00
	CreatureCollPart* mPlatParts[16]; // _04
	int mPartCount;                   // _44
};

#endif
