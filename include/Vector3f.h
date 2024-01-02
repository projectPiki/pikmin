#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"
#include "math.h"

struct Vector3f {
	Vector3f() { }
	Vector3f(f32 const& x, f32 const& y, f32 const& z);

	inline f32 distance(Vector3f& to)
	{
		Vector3f result;
		result.sub2(to, *this);
		return result.length();
	}

	inline void sub2(Vector3f& a, Vector3f& b)
	{
		f32 newZ = a.getZ() - b.getZ();
		f32 newY = a.getY() - b.getY();
		f32 newX = a.getX() - b.getX();
		set(newX, newY, newZ);
	}

	inline void set(f32 const& pX, f32 const& pY, f32 const& pZ)
	{
		x = pX;
		y = pY;
		z = pZ;
	}

	inline f32 squaredLength() const { return x * x + y * y + z * z; }
	inline f32 length() const { return sqrtf(squaredLength()); }

	const f32 getX() const { return x; }
	const f32 getY() const { return y; }
	const f32 getZ() const { return z; }

	f32 getX() { return x; }
	f32 getY() { return y; }
	f32 getZ() { return z; }

	f32 x, y, z;
};

inline f32 Vector3f_diffX(Vector3f& a, Vector3f& b) { return a.getX() - b.getX(); }
inline f32 Vector3f_diffY(Vector3f& a, Vector3f& b) { return a.getY() - b.getY(); }
inline f32 Vector3f_diffZ(Vector3f& a, Vector3f& b) { return a.getZ() - b.getZ(); }

#endif
