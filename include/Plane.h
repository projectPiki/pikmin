#ifndef _PLANE_H
#define _PLANE_H

#include "Vector.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct Plane {
	Plane() { }

	// unused/inlined:
	bool equal(immut Plane&);
	f32 calcRadScale();
	void reflect(Vector3f&);
	void reflectVector(Vector3f&);
	void bounceVector(Vector3f&, f32);
	void frictionVector(Vector3f&, f32);

	f32 dist(immut Vector3f& point) immut { return mNormal.DP(point) - mOffset; }

	void read(RandomAccessStream& input)
	{
		mNormal.read(input);
		mOffset = input.readFloat();
	}

	Vector3f mNormal; // _00
	f32 mOffset;      // _0C
};

#endif
