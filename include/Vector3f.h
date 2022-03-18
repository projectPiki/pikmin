#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"

struct Vector3f {
	f32 x, y, z;
	Vector3f() {};
	Vector3f(float const& x, float const& y, float const& z);
};

inline float getX(Vector3f& vec) { return vec.x; }

inline float getY(Vector3f& vec) { return vec.y; }

inline float getZ(Vector3f& vec) { return vec.z; }

inline float vecdiffX(Vector3f& argA, Vector3f& argB) { return (getX(argA) - getX(argB)); }

inline float vecdiffY(Vector3f& argA, Vector3f& argB) { return (getY(argA) - getY(argB)); }

inline float vecdiffZ(Vector3f& argA, Vector3f& argB) { return (getZ(argA) - getZ(argB)); }

#endif
