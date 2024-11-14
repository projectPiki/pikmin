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
	Sphere(Vector3f& centre, f32 radius)
	    : mCentre(centre)
	    , mRadius(radius)
	{
	}

	Vector3f mCentre; // _04
	f32 mRadius;      // _00
};

/**
 * @brief TODO
 */
struct Tube {
	void getYRatio(f32);
	bool collide(const Sphere&, Vector3f&, f32&);
	void getPosRatio(const Vector3f&);
	void getPosGradient(Vector3f&, f32, Vector3f&, Vector3f&);
	void setPos(f32);

	// unused/inlined:
	void getRatioRadius(f32);

	// TODO: members
	Vector3f _00; // _00
	Vector3f _0C; // _0C
	f32 _18;      // _18
	f32 _1C;      // _1C
};

#endif
