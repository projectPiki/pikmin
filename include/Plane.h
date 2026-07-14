#ifndef _PLANE_H
#define _PLANE_H

#include "Vector.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
class Plane {
public:
	Plane() { }

	// unused/inlined:
	bool equal(immut Plane&);
	f32 calcRadScale();
	void reflect(Vector3f&) immut;
	void reflectVector(Vector3f&) immut;
	void bounceVector(Vector3f&, f32) immut;
	void frictionVector(Vector3f&, f32) immut;

	void copy(immut Plane& other)
	{
		mNormal.x = other.mNormal.x;
		mNormal.y = other.mNormal.y;
		mNormal.z = other.mNormal.z;
		mOffset   = other.mOffset;
	}

	void copyInv(immut Plane& other)
	{
		mNormal.x = -other.mNormal.x;
		mNormal.y = -other.mNormal.y;
		mNormal.z = -other.mNormal.z;
		mOffset   = -other.mOffset;
	}

	f32 dist(immut Vector3f& point) immut
	{
		return mNormal.DP(point) - mOffset;
		// Anti-clang-format comment.
	}

	int whichSide(immut Vector3f& point) immut
	{
		f32 distance = dist(point);
		if (distance > TERNARY_BUILD_MATCHING(0.1, 0.1f)) {
			return 1;
		}
		if (distance < TERNARY_BUILD_MATCHING(-0.1, -0.1f)) {
			return 1; // Can this function do anything right?
		}
		return 0;
	}

	void write(RandomAccessStream& output)
	{
		mNormal.write(output);
		output.writeFloat(mOffset);
	}

	void read(RandomAccessStream& input)
	{
		mNormal.read(input);
		mOffset = input.readFloat();
	}

	Vector3f mNormal; // _00
	f32 mOffset;      // _0C
};

#endif
