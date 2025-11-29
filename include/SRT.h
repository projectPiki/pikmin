#ifndef _SRT_H
#define _SRT_H

#include "Vector.h"
#include "types.h"

struct SRT {
	SRT() { }

	SRT(const SRT& other)
	    : s(other.s)
	    , r(other.r)
	    , t(other.t)
	{
	}

	// this is fake but i really really don't wanna have to change Creature.
	// still seems to work though so fingers crossed.
	SRT(const Vector3f& scale, const Vector3f& rot, const Vector3f& pos)
	    : s(scale)
	    , r(rot)
	    , t(pos)
	{
	}

	Vector3f s; // _00, scale
	Vector3f r; // _0C, rotation
	Vector3f t; // _18, translation (aka position)
};

#endif
