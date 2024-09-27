#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "types.h"
#include "Vector.h"

struct Sphere;

/**
 * @brief TODO
 */
struct Cylinder {

	void get2dDist(Vector3f&);
	void collide(const Sphere&, Vector3f&, f32&);
	void getPosRatio(const Vector3f&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct RectArea {

	// TODO: members
};

/**
 * @brief TODO
 */
struct Sphere {
	f32 mRadius;      // _00
	Vector3f mCentre; // _04
};

/**
 * @brief TODO
 */
struct Tube {

	void getYRatio(f32);
	void collide(const Sphere&, Vector3f&, f32&);
	void getPosRatio(const Vector3f&);
	void getPosGradient(Vector3f&, f32, Vector3f&, Vector3f&);
	void setPos(f32);

	// unused/inlined:
	void getRatioRadius(f32);

	// TODO: members
};

#endif
