#ifndef _PLANE_H
#define _PLANE_H

#include "types.h"

struct Vector3f;

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

	// TODO: members - it'll be 4 f32s, just not sure if it'll be a Vector3f and a f32 or 4 f32s.
};

#endif
