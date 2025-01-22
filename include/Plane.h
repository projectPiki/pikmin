#ifndef _PLANE_H
#define _PLANE_H

#include "types.h"
#include "Vector.h"

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct Plane {
	Plane() { }

	// unused/inlined:
	bool equal(Plane&);
	f32 calcRadScale();
	void reflect(Vector3f&);
	void reflectVector(Vector3f&);
	void bounceVector(Vector3f&, f32);
	void frictionVector(Vector3f&, f32);

	Vector3f mNormal; // _00
	f32 mOffset;      // _0C
};

#endif
