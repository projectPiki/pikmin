#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"

struct Vector3f {
	f32 x, y, z;

	Vector3f(float const& x, float const& y, float const& z);
};

#endif
