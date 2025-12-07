#ifndef BOUNDBOX_H
#define BOUNDBOX_H

#include "Vector.h"

struct Graphics;

struct BoundBox {
	BoundBox(immut Vector3f& min, immut Vector3f& max)
	{
		mMin = min;
		mMax = max;
	}

	BoundBox() { resetBound(); }

	void resetBound()
	{
		mMin.set(32768.0f, 32768.0f, 32768.0f);
		mMax.set(-32768.0f, -32768.0f, -32768.0f);
	}

	void expandBound(immut BoundBox& other)
	{
		if (other.mMin.x < mMin.x) {
			mMin.x = other.mMin.x;
		}
		if (other.mMin.y < mMin.y) {
			mMin.y = other.mMin.y;
		}
		if (other.mMin.z < mMin.z) {
			mMin.z = other.mMin.z;
		}

		if (other.mMax.x > mMax.x) {
			mMax.x = other.mMax.x;
		}
		if (other.mMax.y > mMax.y) {
			mMax.y = other.mMax.y;
		}
		if (other.mMax.z > mMax.z) {
			mMax.z = other.mMax.z;
		}
	}

	void expandBound(immut Vector3f& other)
	{
		if (other.x < mMin.x) {
			mMin.x = other.x;
		}
		if (other.y < mMin.y) {
			mMin.y = other.y;
		}
		if (other.z < mMin.z) {
			mMin.z = other.z;
		}

		if (other.x > mMax.x) {
			mMax.x = other.x;
		}
		if (other.y > mMax.y) {
			mMax.y = other.y;
		}
		if (other.z > mMax.z) {
			mMax.z = other.z;
		}
	}

	bool intersects(immut BoundBox& other) immut
	{
		if (other.mMin.x <= mMax.x && other.mMax.x >= mMin.x && other.mMin.y <= mMax.y && other.mMax.y >= mMin.y && other.mMin.z <= mMax.z
		    && other.mMax.z >= mMin.z) {
			return true;
		}
		return false;
	}

	// void resetBound()
	// {
	// 	mMax.set(32768.0f, 32768.0f, 32768.0f);
	// 	mMin.set(-32768.0f, -32768.0f, -32768.0f);
	// }

	// void setBoundZero()
	// {
	// 	mMax.set(0.0f, 0.0f, 0.0f);
	// 	mMin.set(0.0f, 0.0f, 0.0f);
	// }

	void draw(Graphics&);

	void read(RandomAccessStream& input)
	{
		mMin.read(input);
		mMax.read(input);
	}

	Vector3f mMin; // _00
	Vector3f mMax; // _0C
};

#endif // BOUNDBOX_H
