#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"

struct Vector3f {
	f32 x, y, z;
	Vector3f() {};
	Vector3f(float const& x, float const& y, float const& z);
	f32 getX() { return this->x; } // inline function call
	f32 getY() { return this->y; } // inline function call
	f32 getZ() { return this->z; } // inline function call
};

inline float vecdiffX(Vector3f& argA, Vector3f& argB) { return argA.getX() - argB.getX(); }

inline float vecdiffY(Vector3f& argA, Vector3f& argB) { return argA.getY() - argB.getY(); }

inline float vecdiffZ(Vector3f& argA, Vector3f& argB) { return argA.getZ() - argB.getZ(); }

#endif
