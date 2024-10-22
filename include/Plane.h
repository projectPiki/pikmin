#ifndef _PLANE_H
#define _PLANE_H

#include "types.h"
#include "Vector.h"

/**
 * @brief TODO
 */
struct Plane {
	Plane();

	// unused/inlined:
	bool equal(Plane&);
	void calcRadScale();
	void reflect(Vector3f&);
	void reflectVector(Vector3f&);
	void bounceVector(Vector3f&, f32);
	void frictionVector(Vector3f&, f32);

	Vector3f mNormal; // _00
	f32 mOffset;      // _10
};

#endif
