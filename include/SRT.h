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

	Vector3f s; // _00, scale
	Vector3f r; // _0C, rotation
	Vector3f t; // _18, translation (aka position)
};

#endif
