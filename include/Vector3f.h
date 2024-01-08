#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"
#include "math.h"

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct Vector3f {
	Vector3f() { }
	Vector3f(const f32& x, const f32& y, const f32& z);

	void rotate(struct Matrix4f&);
	void rotateTo(Matrix4f&, Vector3f&);
	void multMatrix(Matrix4f&);
	void multMatrixTo(Matrix4f&, Vector3f&);

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

	inline void set(const f32& pX, const f32& pY, const f32& pZ)
	{
		x = pX;
		y = pY;
		z = pZ;
	}

	inline void set(const f32 val) { x = y = z = val; }

	void div(f32); // weak

	inline f32 squaredLength() const { return x * x + y * y + z * z; }
	inline f32 length() const { return sqrtf(squaredLength()); }

	const f32 getX() const { return x; }
	const f32 getY() const { return y; }
	const f32 getZ() const { return z; }

	f32 getX() { return x; }
	f32 getY() { return y; }
	f32 getZ() { return z; }

	f32 x, y, z; // _00, _04, _08
};

inline f32 Vector3f_diffX(Vector3f& a, Vector3f& b) { return a.getX() - b.getX(); }
inline f32 Vector3f_diffY(Vector3f& a, Vector3f& b) { return a.getY() - b.getY(); }
inline f32 Vector3f_diffZ(Vector3f& a, Vector3f& b) { return a.getZ() - b.getZ(); }

#endif
