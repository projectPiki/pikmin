#ifndef _SRT_H
#define _SRT_H

#include "Vector.h"
#include "types.h"

struct SRT {
	SRT() { }

	SRT(const SRT& other)
	    : mScale(other.mScale)
	    , mRotation(other.mRotation)
	    , mTranslation(other.mTranslation)
	{
	}

	// this is fake but i really really don't wanna have to change Creature.
	// still seems to work though so fingers crossed.
	SRT(const Vector3f& scale, const Vector3f& rot, const Vector3f& pos)
	    : mScale(scale)
	    , mRotation(rot)
	    , mTranslation(pos)
	{
	}

	Vector3f mScale;       // _00
	Vector3f mRotation;    // _0C
	Vector3f mTranslation; // _18, aka position
};

#endif
