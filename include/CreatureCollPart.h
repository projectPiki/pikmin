#ifndef _CREATURECOLLPART_H
#define _CREATURECOLLPART_H

#include "types.h"
#include "DynColl.h"

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
	}

	virtual void update() { }                                 // _10 (weak)
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&) { }                       // _44 (weak)

	// _00      = VTBL
	// _00-_140 = DynCollShape
	u8 _140[0x4]; // _140, unknown
	int _144;     // _144, anim matrix ID?
};

/*
 * @brief TODO
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
